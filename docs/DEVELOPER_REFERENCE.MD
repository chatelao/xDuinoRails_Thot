# Developer Reference

## GitHub Pages Deployment

The documentation and the Signal Viewer webtool are automatically deployed to GitHub Pages using a GitHub Actions workflow defined in `.github/workflows/deploy_pages.yml`.

This workflow performs the following steps:
1.  Checks out the repository.
2.  Installs Python dependencies.
3.  Generates the latest Signal SVGs using `firmware/scripts/generate_svgs.py`.
4.  Uploads the entire repository as a pages artifact.
5.  Deploys the artifact to GitHub Pages.

This ensures that the [Signal Viewer](https://chatelao.github.io/xDuinoRails_Thot/webtool/) always uses the latest definitions and SVGs from the `main` branch.
