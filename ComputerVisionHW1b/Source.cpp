#include <opencv2/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;

int main()
{
	// Video capture source
	VideoCapture cap;

	// Try open video from camera
	if (!cap.open(0)) {
		puts("Error: Could not initialize camera video...\n");
		return 1;
	}

	// Create MOG2 Background subtractor objects
	Ptr<BackgroundSubtractor> pMOG2;
	pMOG2 = createBackgroundSubtractorMOG2();

	Mat frame, image, foreground;
	// frame = current frame from video.
	// image = clone of frame, to avoid override by the next frame
	// foreground = Result of pMOG2->apply.

	// Create wondows
	namedWindow("Original video", CV_WINDOW_AUTOSIZE);
	namedWindow("Foreground ", CV_WINDOW_AUTOSIZE);

	int fps = cap.get(CV_CAP_PROP_FPS);
	if (fps <= 0)
		fps = 30;

	int imageDuration = 1000 / fps;

	while (true)
	{
		// Get current frame from video
		cap >> frame;

		if (frame.empty())
			break;

		image = frame.clone();

		// -1 = Automatic chosen learning rate
		pMOG2->apply(image, foreground, -1); 

		// Make the forground black & white image.
		threshold(foreground, foreground, 1, 255, THRESH_BINARY);
		
		// Smoothes an image using the median filter.
		medianBlur(foreground, foreground, 9);

		// Erodes an image by using a specific structuring element.
		erode(foreground, foreground, Mat());

		// Dilates an image by using a specific structuring element.
		dilate(foreground, foreground, Mat());

		imshow("Original video ", frame);
		imshow("Foreground ", foreground);

		char c = (char)waitKey(imageDuration);
		if (c == 27)   // ESC button.
			break;
	}

	return 0;
} // End main
