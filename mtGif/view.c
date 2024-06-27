#include "view.h"

void play(FrameNode* head)
{
	cvNamedWindow("Display window", CV_WINDOW_AUTOSIZE); //create a window
	FrameNode* tmp = head;
	int imgNum = 1, playCount = 0;
	IplImage* image;
	while (playCount < GIF_REPEAT)
	{
		while (tmp)
		{
			image = cvLoadImage(tmp->frame->path, 1);
			IplImage* pGrayImg = 0;
			pGrayImg = cvCreateImage(cvSize(image->width, image->height), image->depth, 1);
			if (!image) { //The image is empty - shouldn't happen since we checked already.
				printf("Could not open or find image number %d", imgNum);
			}
			else{
				cvShowImage("Display window", image); //display the image
				cvWaitKey(tmp->frame->duration); //wait
				tmp = tmp->next;
				cvReleaseImage(&image);
			}
			imgNum++;
		}
		playCount++;
	}
	cvDestroyWindow("Display window");
	return;
}