# chest-CT-analysis

## Sample Instructions:

This program uses C++ and ITK to invert the pixel intensities of an image.

### Requirements
- Visual Studio with C++ support
- CMake
- ITK (installed and built)
- ImageJ (to view images)

### Setup

1. Clone this repository:
   ```powershell
   git clone <repository-url>
   ```
2. Open CMake GUI.
3. Set **Source** to the cloned repository folder.
4. Set **Build** to a new `build` folder inside the repository.
5. Click **Configure** and select your Visual Studio version (`x64`).
6. Set `ITK_DIR` to your ITK build directory (e.g. `C:/ITK/build`).
7. Click **Configure**, then **Generate**.
8. Open the generated `.sln` or `.slnx` file in Visual Studio.
9. Select **Release | x64** and build the solution.

### Running the Demo

1. Save a grayscale image as `test_image.tif` in the repository folder.
2. Open PowerShell in the repository folder.
3. Run:
   ```powershell
   .\build\Release\ITKtesting.exe ".\test_image.tif" ".\inverted.tif"
   ```
4. Open `inverted.tif` in ImageJ to view the result.

### Notes
- Use a 2D grayscale image (preferably 16-bit TIFF).
- Rebuild in Visual Studio after changing the C++ code.
- Keep the `build` folder out of GitHub using `.gitignore`.

