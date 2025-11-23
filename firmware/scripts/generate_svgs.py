import os
import glob
import re
import xml.etree.ElementTree as ET
import cairosvg

def generate_svg(xml_file, output_dir):
    try:
        tree = ET.parse(xml_file)
        root = tree.getroot()

        # Iterate signals
        for signal in root.findall('signal'):
            name = signal.get('name')
            if not name:
                continue

            filename = signal.get('svg', f"{name}.svg")
            outline = signal.get('outline')
            outline_color = signal.get('outlineColor', '#000000')

            bulbs = []
            lightbulbs_el = signal.find('lightbulbs')
            if lightbulbs_el is not None:
                for lb in lightbulbs_el.findall('lightbulb'):
                    x = float(lb.get('x', 0))
                    y = float(lb.get('y', 0))
                    color = lb.get('color', 'white')
                    d = lb.get('d', '')
                    bulbs.append({'x': x, 'y': y, 'color': color, 'd': d})

            # Calculate BBox
            min_x, max_x, min_y, max_y = float('inf'), float('-inf'), float('inf'), float('-inf')

            # From Outline (Simple parsing of coordinates)
            if outline:
                nums = [float(n) for n in re.findall(r'-?\d+\.?\d*', outline)]
                # Heuristic: alternating X, Y pairs
                if len(nums) >= 2:
                    xs = nums[0::2]
                    ys = nums[1::2]
                    if xs:
                        min_x = min(min_x, *xs)
                        max_x = max(max_x, *xs)
                    if ys:
                        min_y = min(min_y, *ys)
                        max_y = max(max_y, *ys)

            # From Bulbs
            r_default = 100 # mm default radius
            for b in bulbs:
                x, y = b['x'], b['y']
                min_x = min(min_x, x - r_default)
                max_x = max(max_x, x + r_default)
                min_y = min(min_y, y - r_default)
                max_y = max(max_y, y + r_default)

            if min_x == float('inf'):
                min_x, max_x, min_y, max_y = -100, 100, -100, 100

            # Padding
            padding = 50
            min_x -= padding
            max_x += padding
            min_y -= padding
            max_y += padding

            width = max_x - min_x
            height = max_y - min_y

            # ViewBox Calculation (Flipping Y)
            # XML Y-up vs SVG Y-down.
            # We flip with transform="scale(1, -1)".
            # XML coords mapped to SVG: (x, -y).
            # BBox Y range in flipped space: [-max_y, -min_y].
            # viewBox origin (top-left) should be (min_x, -max_y).
            viewbox = f"{min_x} {-max_y} {width} {height}"

            svg_lines = []
            svg_lines.append(f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="{viewbox}">')
            svg_lines.append(f'  <g transform="scale(1, -1)">')

            if outline:
                svg_lines.append(f'    <path d="{outline}" fill="{outline_color}" stroke="none" />')

            for b in bulbs:
                # Ensure color is valid or mapped if needed. SVG supports names.
                d_attr = b['d'] if b['d'] else f"m -{r_default}, 0 a {r_default},{r_default} 0 1,0 {2*r_default},0 a {r_default},{r_default} 0 1,0 -{2*r_default},0"
                svg_lines.append(f'    <path d="{d_attr}" transform="translate({b["x"]}, {b["y"]})" fill="{b["color"]}" />')

            svg_lines.append('  </g>')
            svg_lines.append('</svg>')

            svg_path = os.path.join(output_dir, filename)
            with open(svg_path, 'w') as f:
                f.write('\n'.join(svg_lines))

            # Generate PNG
            png_filename = filename.replace('.svg', '.png')
            png_path = os.path.join(output_dir, png_filename)
            try:
                cairosvg.svg2png(url=svg_path, write_to=png_path)
            except Exception as e:
                print(f"Error generating PNG for {filename}: {e}")

    except Exception as e:
        print(f"Error processing {xml_file}: {e}")

if __name__ == "__main__":
    output_dir = "firmware/definitions/generated_svgs"
    os.makedirs(output_dir, exist_ok=True)

    # Find XMLs
    base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__))) # firmware
    def_dir = os.path.join(base_dir, "definitions")

    for xml_file in glob.glob(os.path.join(def_dir, "*.xml")):
        print(f"Generating SVGs for {xml_file}")
        generate_svg(xml_file, output_dir)
