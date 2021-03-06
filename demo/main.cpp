#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "SpecularHighlightRemoval.hpp"

int main(int argc, char **argv) 
{

	if(argc != 2) 
	{
		printf("Usage: SpecularHighlightRemoval imagefile.extension\n");
		return 0;
	}

	cv::Mat inputImage = cv::imread(argv[1]);
	cv::Mat outputImage;

	SpecularHighlightRemoval specularHighlightRemoval;
	specularHighlightRemoval.initialize(inputImage.rows, inputImage.cols);
	outputImage = specularHighlightRemoval.run(inputImage);

	while(cv::waitKey(33) != 13) 
	{
		cv::imshow("Input Image", inputImage);
		cv::imshow("Output Image", outputImage);
	}

	return 0;
	
}
