import os
import glob
import xml.etree.ElementTree as ET
from collections import defaultdict
import json

def split_definitions():
    definitions_dir = 'definitions'
    all_xml_files = glob.glob(os.path.join(definitions_dir, '*.xml'))

    # Exclude the schema file
    xml_files_to_process = [f for f in all_xml_files if os.path.basename(f) != 'signals.xsd']

    for filepath in xml_files_to_process:
        try:
            tree = ET.parse(filepath)
            root = tree.getroot()

            families = defaultdict(list)

            # Group signals by family
            for signal in root.findall('signal'):
                name = signal.get('name')
                if not name:
                    continue

                parts = name.split('-')
                if len(parts) > 1:
                    family_name = parts[1]
                    families[family_name].append(signal)

            # Write new files for each family
            country_code = os.path.basename(filepath).split('.')[0]
            for family, signals in families.items():
                new_filename = f"{country_code}-{family}.xml"
                new_filepath = os.path.join(definitions_dir, new_filename)

                new_root = ET.Element('signalDefinitions')
                new_root.set('xmlns:xsi', "http://www.w3.org/2001/XMLSchema-instance")
                new_root.set('xsi:noNamespaceSchemaLocation', 'signals.xsd')
                new_root.extend(signals)

                new_tree = ET.ElementTree(new_root)
                # Pretty print
                ET.indent(new_tree, space="  ")

                # Write to a string first to add newline
                import io
                f = io.StringIO()
                new_tree.write(f, encoding='unicode', xml_declaration=True)
                xml_content = f.getvalue()

                with open(new_filepath, 'w', encoding='utf-8') as outfile:
                    outfile.write(xml_content)
                    outfile.write('\n') # Add trailing newline

                print(f"Created {new_filepath}")

            # Remove original file
            os.remove(filepath)
            print(f"Removed original file: {filepath}")

        except ET.ParseError as e:
            print(f"Error parsing {filepath}: {e}")
        except Exception as e:
            print(f"An error occurred with {filepath}: {e}")

    # Generate manifest.json
    generate_manifest()

def generate_manifest():
    definitions_dir = 'definitions'
    manifest = defaultdict(list)

    all_xml_files = glob.glob(os.path.join(definitions_dir, '*.xml'))
    xml_files = [f for f in all_xml_files if os.path.basename(f) != 'signals.xsd']

    for filepath in xml_files:
        filename = os.path.basename(filepath)
        country_code = filename.split('-')[0]
        # Store relative path for web use
        manifest[country_code].append(f"../{definitions_dir}/{filename}")

    # Sort the file lists for consistency
    for country in manifest:
        manifest[country].sort()

    manifest_path = os.path.join(definitions_dir, 'manifest.json')
    with open(manifest_path, 'w') as f:
        json.dump(manifest, f, indent=2)
    print(f"Generated {manifest_path}")

if __name__ == "__main__":
    split_definitions()
