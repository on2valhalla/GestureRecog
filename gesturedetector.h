#ifndef GESTUREDETECTION_H
#define GESTUREDETECTION_H

#include <QDialog>
#include <QTimer>

//sys
#include <iostream>
#include <string>
#include <cmath>

//OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>

//color detector, controller, histogram
#include "colorhistogram.h"
#include "skindetectcontroller.h"

static std::string FACEFILE = "/opt/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt_tree.xml";

namespace Ui {
	class GestureDetector;
}

class GestureDetector : public QDialog
{
	Q_OBJECT
	
public:
	explicit GestureDetector(QWidget *parent = 0);
	~GestureDetector();

	void start();
	void setCap(cv::VideoCapture &cap);
	void beginPicSequence();

	
private:
	Ui::GestureDetector *ui;
	QTimer *timer;
	cv::VideoCapture cap;
	cv::CascadeClassifier cascadeFace; //HAAR Cascade for detecting faces

	static const int DELAY = 1000; //Timer delay, determines how fast video plays
	static const int PASSINT = 1000; //Interval between gesture captures
	int timeCount;

	//display an image in the dialog
	void displayMat(const cv::Mat &image);

	// Detect and Identify the hand gesture present in the image
	std::vector<Hand> detect(cv::Mat &image, cv::Mat &filtered);


private slots:
	void updateTimer();
	void reject();
	void pause();
};


#endif // GESTUREDETECTION_H
