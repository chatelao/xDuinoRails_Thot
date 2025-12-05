# Contributing to xDuinoRails_Thot

Thank you for your interest in contributing!

## Development Setup
1. Install [PlatformIO](https://platformio.org/).
2. Clone the repository.
3. Install Python dependencies: `pip install -r requirements.txt`.

## Running Tests
This project uses PlatformIO's unit testing framework.

### Native Tests
To run unit tests on your local machine (without hardware), use the `native` environment:
```bash
python -m platformio test -d firmware -e native
```
These tests verify core logic like RCN-227 Function Mapping.

### Signal Verification
Before submitting signal changes, ensure you generate the SVGs and verify XMLs:
```bash
# In firmware/ directory
python scripts/generate_svgs.py
python scripts/validate_xml.py
```

## Code Style
- Use snake_case for filenames.
- Use Doxygen style comments.
