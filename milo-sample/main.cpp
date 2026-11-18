/*
    DESCRIPTION: A simple executable that reads a 2D image, inverts the intesity values
	    of all pixels, and outputs a new 2D image (result)

    PURPOSE: getting familiar with ITK, general understanding of CSC 621 project pipeline

	ARGUMENTS:
		input: path to the input image
		output: path to the output image
*/

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkInvertIntensityImageFilter.h"
#include <iostream>

int main(int argc, char* argv[])
{
	// check for input image and file name to write to
    if (argc != 3)
    {
        std::cout << "Provide path to input image & path to desired output\n";
        return 1;
    }

	// test image is 2D, with pixel type short
    using ImageType = itk::Image<short, 2>;

    // define the ITK tools
    using ReaderType = itk::ImageFileReader<ImageType>;
    using FilterType = itk::InvertIntensityImageFilter<ImageType>;  // this is the filter applied!
    using WriterType = itk::ImageFileWriter<ImageType>;

    auto reader = ReaderType::New();
    auto filter = FilterType::New();
    auto writer = WriterType::New();

    // tells ITK which file to read (1st arg)
    reader->SetFileName(argv[1]);

    // connect the image to the filter
    filter->SetInput(reader->GetOutput());

    // invert around 0: output = -input.
    filter->SetMaximum(0);

    // connects the filtered image to the writer
    writer->SetInput(filter->GetOutput());
    writer->SetFileName(argv[2]);

    try
    {
        writer->Update();
        std::cout << "SUCCESS | Image saved at: " << argv[2] << "\n";
    }
    catch (const itk::ExceptionObject& error)
    {
        std::cerr << error << "\n";
        return 1;
    }

    return 0;
}
