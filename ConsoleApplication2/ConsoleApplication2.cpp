// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
using namespace cv;
using namespace std;
    	

int main()
{
	import cv2
	import sys
	img = cv2.imread('C:\\Users\\fjw\\Desktop\\1.jpg')
	face_haar = cv2.CascadeClassifier("data/haarcascades/haarcascade_frontalface_default.xml")
	eye_haar = cv2.CascadeClassifier("data/haarcascades/haarcascade_eye.xml")
	gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	faces = face_haar.detectMultiScale(gray_img, 1.3, 5)
	print(faces)
	for face_x, face_y, face_w, face_h in faces :
	    cv2.rectangle(img, (face_x, face_y), (face_x + face_w, face_y + face_h), (0, 255, 0), 2)
		roi_gray_img = gray_img[face_y:face_y + face_h, face_x : face_x + face_w]
		roi_img = img[face_y:face_y + face_h, face_x : face_x + face_w]
		eyes = eye_haar.detectMultiScale(roi_gray_img, 1.3, 5)
        for eye_x, eye_y, eye_w, eye_h in eyes :
			 cv2.rectangle(roi_img, (eye_x, eye_y), (eye_x + eye_w, eye_y + eye_h), (255, 0, 0), 2)
	cv2.imshow('img', img)
	cv2.waitKey(0)
	cv2.destroyAllWindows()

}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
