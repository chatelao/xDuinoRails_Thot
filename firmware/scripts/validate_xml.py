from lxml import etree
import os

Import("env")

def validate_xml(source, target, env):
    print("Validating XML files...")
    definitions_dir = os.path.join(env.get("PROJECT_DIR"), "definitions")
    xsd_path = os.path.join(definitions_dir, "signals.xsd")

    if not os.path.exists(xsd_path):
        print(f"XSD file not found at {xsd_path}")
        return

    xml_schema_doc = etree.parse(xsd_path)
    xml_schema = etree.XMLSchema(xml_schema_doc)

    for filename in os.listdir(definitions_dir):
        if filename.endswith(".xml"):
            xml_path = os.path.join(definitions_dir, filename)
            try:
                xml_doc = etree.parse(xml_path)
                xml_schema.assertValid(xml_doc)
                print(f"Validation successful for {filename}")
            except etree.DocumentInvalid as e:
                print(f"Validation error in {filename}:")
                print(e)
                env.Exit(1)
            except Exception as e:
                print(f"An error occurred while validating {filename}: {e}")
                env.Exit(1)

env.AddPreAction("buildprog", validate_xml)
