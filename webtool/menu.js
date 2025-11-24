document.addEventListener("DOMContentLoaded", function() {
    // Inject Menu HTML
    const navHtml = `
        <div class="topnav" id="myTopnav">
            <a href="index.html" id="link-viewer">Viewer</a>
            <a href="gallery.html" id="link-gallery">Gallerie</a>
            <a href="editor.html" id="link-editor">Editor</a>
            <a href="javascript:void(0);" class="icon" onclick="toggleMenu()">
                <svg viewBox="0 0 100 80" width="20" height="20" fill="white">
                    <rect width="100" height="20"></rect>
                    <rect y="30" width="100" height="20"></rect>
                    <rect y="60" width="100" height="20"></rect>
                </svg>
            </a>
        </div>
    `;

    // Prepend to body
    document.body.insertAdjacentHTML('afterbegin', navHtml);

    // Set Active Link
    const path = window.location.pathname;
    const page = path.split("/").pop();

    if (page === "gallery.html") {
        document.getElementById("link-gallery").classList.add("active");
    } else if (page === "editor.html") {
        document.getElementById("link-editor").classList.add("active");
    } else {
        // Default to index.html or empty (root)
        document.getElementById("link-viewer").classList.add("active");
    }
});

function toggleMenu() {
    var x = document.getElementById("myTopnav");
    if (x.className === "topnav") {
        x.className += " responsive";
    } else {
        x.className = "topnav";
    }
}
