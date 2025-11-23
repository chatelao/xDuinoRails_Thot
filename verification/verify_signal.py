from playwright.sync_api import Page, expect, sync_playwright
import time
import re

def verify_signal_aspects(page: Page):
    # 1. Arrange: Go to the web tool
    page.goto("http://localhost:8000/webtool/index.html")

    # 2. Act: Select Country "ch"
    page.select_option("#country", "ch")

    # Wait for the custom signal select to be enabled (class 'disabled' removed)
    # The class list is initially "custom-select disabled", becomes "custom-select"
    custom_select = page.locator("#custom-signal-select")
    expect(custom_select).not_to_have_class(re.compile(r"disabled"))

    # Open the custom dropdown
    custom_select.locator(".select-selected").click()

    # Wait for the signal item and click it
    signal_item_locator = page.locator(".select-item span", has_text="CH-Rangierhaltsignal-V2")
    expect(signal_item_locator).to_be_visible()
    signal_item_locator.click()

    # 3. Assert: Check the Aspect Table
    # Wait for the table to appear and update
    table_container = page.locator("#aspect-table-container")
    expect(table_container).to_be_visible()

    # Check aspect names in the first column
    rows = page.locator("table.aspect-table tbody tr")
    expect(rows.first).to_be_visible()

    aspect_names = rows.locator("td:first-child").all_inner_texts()
    print("Aspect Names:", aspect_names)

    if "Halt" in aspect_names:
        raise Exception("Aspect 'Halt' found but should be removed")

    if "Rangieren verboten" in aspect_names:
        raise Exception("Aspect 'Rangieren verboten' found but should be removed")

    # Verify expected aspects are present
    expected = ["Zustimmung", "Rangieren erlaubt"]
    for exp in expected:
        if exp not in aspect_names:
            raise Exception(f"Expected aspect '{exp}' not found")

    # 4. Screenshot
    page.screenshot(path="/home/jules/verification/signal_verification.png", full_page=True)

if __name__ == "__main__":
    with sync_playwright() as p:
        browser = p.chromium.launch(headless=True)
        page = browser.new_page()
        try:
            verify_signal_aspects(page)
            print("Verification passed!")
        except Exception as e:
            print(f"Verification failed: {e}")
            page.screenshot(path="/home/jules/verification/failure.png")
            exit(1)
        finally:
            browser.close()
