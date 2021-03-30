function startChipM8() {
    // Fetch the file
    var fileInput = document.getElementById("RomUploadInput");
    var file = fileInput.files[0];
    if (file == undefined) {
        console.log("No file selected");
        return;
    }

    // Disable file input
    fileInput.setAttribute("disabled", "");

    // Save the file to the virtual hard drive
    // https://stackoverflow.com/questions/47313403/passing-client-files-to-webassembly-from-the-front-end
    var fr = new FileReader();
    fr.onload = function () {
        var data = new Uint8Array(fr.result);
        Module["FS_createDataFile"]('/', 'rom.ch8', data, true, true, true);

        // Tell ChipM8 to load and run the rom
        Module.ccall("startChip8", null, [], null);
    };
    fr.readAsArrayBuffer(file);
}

function applySettings() {
    clockRate = parseInt(document.getElementById("ClockInput").value);
    bgColor = colorToSigned24Bit(document.getElementById("BackgroundColorInput").value);
    fgColor = colorToSigned24Bit(document.getElementById("ForegroundColorInput").value);
   
    // Call the update settings function
    Module.ccall("updateSettings", null, ['number', 'number', 'number'], [fgColor, bgColor, clockRate]);
}

// Taken from https://stackoverflow.com/questions/49686254/convert-hexadecimal-color-string-to-integer-in-javascript
function colorToSigned24Bit(s) {
    return (parseInt(s.substr(1), 16) << 8) / 256;
}