import os
import time
from playwright.sync_api import sync_playwright

def verify_signals():
    with sync_playwright() as p:
        # Launch browser
        browser = p.chromium.launch()
        page = browser.new_page()

        # Go to webtool via localhost
        url = "http://localhost:8000/webtool/index.html"
        print(f"Loading {url}")
        page.goto(url)

        # Check title
        print("Page title:", page.title())

        # Select Country CH
        print("Selecting country 'ch'...")
        page.select_option("#country", "ch")

        # Wait for signal select to be enabled (XML loaded)
        print("Waiting for signal dropdown...")
        page.wait_for_function("document.getElementById('signal').disabled === false", timeout=10000)

        signals_to_test = [
            "CH-Rangierhaltsignal",
            "CH-Raeumungssignal",
            "CH-Rangierhaltsignal-V2"
        ]

        os.makedirs("verification/screenshots", exist_ok=True)

        for signal_name in signals_to_test:
            print(f"Testing {signal_name}...")
            page.select_option("#signal", signal_name)

            # Wait for aspect select to be enabled (Signal loaded)
            page.wait_for_function("document.getElementById('aspect').disabled === false", timeout=5000)
            page.wait_for_timeout(200) # Visual debounce

            # Screenshot base (all lights)
            page.screenshot(path=f"verification/screenshots/{signal_name}_base.png")

            # Loop aspects
            aspect_options = page.locator("#aspect option").all_text_contents()
            # Remove "Select Aspect" and "Dark"
            valid_aspects = [opt for opt in aspect_options if opt not in ["Select Aspect", "Dark"]]

            for aspect in valid_aspects:
                print(f"  Aspect: {aspect}")
                page.select_option("#aspect", aspect)
                page.wait_for_timeout(200)
                safe_aspect_name = aspect.replace(" ", "_")
                page.screenshot(path=f"verification/screenshots/{signal_name}_{safe_aspect_name}.png")

        browser.close()

if __name__ == "__main__":
    verify_signals()
