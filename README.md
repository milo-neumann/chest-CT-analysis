# CSC 621 Biomedical Image Analysis Research Project
## Objectives:
- Measure & visualize the change in (measured) covid affected lung tissue between 2 scans of the same patient at different times
- Compare 2 segmentation methods for accuracy of correctly segmenting affected tissue

## Our pipeline:
1. Registration (IN: 2 scans of the same patient OUT: 2 scans aligned)
2. Validate registration
3. Segmentation method 1 (combination of in-class techniques and algorithms
4. Segmentation method 2 (different combination)
5. Validate & compare (quantify) segmentations of same image against a ‘target’
6. Compare (quantify) change in affected tissue between 2 scans of same patient (Re-use segmentation validation, but changing ‘target’ to first scan of patient)


# ITK Image Processing Demo
This program is a mini demo that inverts the pixel intensities in a 2D .dicom image

### Requirements
- Visual Studio with C++ support
- CMake
- ITK (installed and built)
- ImageJ (to view images)

### Setup

1. Clone this repository:
   ```powershell
   git clone <https://github.com/milo-neumann/chest-CT-analysis.git>
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
