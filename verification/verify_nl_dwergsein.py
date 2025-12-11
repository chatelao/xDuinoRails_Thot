from playwright.sync_api import sync_playwright

def run(playwright):
    browser = playwright.chromium.launch()
    page = browser.new_page()
    page.goto("http://localhost:8000/webtool/index.html")

    # Wait for the XML to be loaded and processed
    page.wait_for_selector("#country")

    # Select Country: NL
    # The loadCountry function is global
    page.evaluate("loadCountry('nl')")
    # Wait for the signal selector to populate or the fetch to complete
    page.wait_for_timeout(1000)

    # Select Signal: NL-Dwergsein
    page.evaluate("updateSignalSelection('NL-Dwergsein')")
    # Wait for SVG update
    page.wait_for_timeout(1000)

    # Select Aspect: Groen (or just check default)
    # Let's select 'Groen' explicitly to be sure
    page.evaluate("updateAspectSelection('Groen')")
    page.wait_for_timeout(500)

    # Take screenshot of the display area
    element = page.locator("#display")
    element.screenshot(path="verification/nl_dwergsein_groen.png")

    # Select Aspect: Red
    page.evaluate("updateAspectSelection('Rood')")
    page.wait_for_timeout(500)
    element.screenshot(path="verification/nl_dwergsein_rood.png")

    browser.close()

with sync_playwright() as playwright:
    run(playwright)
