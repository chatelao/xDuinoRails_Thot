from playwright.sync_api import sync_playwright, expect

def verify(page):
    print("Navigating...")
    page.goto("http://localhost:8000/webtool/index.html")

    print("Selecting Country...")
    page.select_option("#country", "ch")

    print("Waiting for signal selector...")
    page.wait_for_selector("#custom-signal-select:not(.disabled)", timeout=10000)

    print("Opening signal dropdown...")
    page.click("#custom-signal-select .select-selected")

    print("Selecting signal...")
    page.click(".select-item[data-value='CH-L-Hauptsignal-7L']")

    print("Waiting for SVG...")
    page.wait_for_selector("#display svg")

    print("Selecting Aspect Halt...")
    page.select_option("#aspect", "Halt")

    print("Waiting for render...")
    page.wait_for_timeout(1000)

    print("Taking screenshot...")
    page.screenshot(path="verification/verification.png")
    print("Done.")

if __name__ == "__main__":
    with sync_playwright() as p:
        browser = p.chromium.launch(headless=True)
        page = browser.new_page()
        try:
            verify(page)
        except Exception as e:
            print(f"Error: {e}")
            page.screenshot(path="verification/error.png")
        finally:
            browser.close()
