/************************************************************************
 MIT License

 Copyright (c) 2018 Harsh Kakashaniya,Rohitkrishna Nambiar

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 *************************************************************************/

/**
 *  @file    LaneDetectionModule.cpp
 *  @author  Harsh Kakashaniya and Rohitkrishna Nambiar
 *  @date    10/12/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 5,Midterm Project.
 *
 *  @Description DESCRIPTION
 *
 *  Class member functions for LaneDetectionModule.h
 *
 */

#ifndef LANEDETECTIONMODULE_H_
#define LANEDETECTIONMODULE_H_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include "Lane.hpp"

class LaneDetectionModule {
public:

  /**
   *   @brief Default constructor for LaneDetectionModule
   *
   *
   *   @param nothing
   *   @return nothing
   */
  LaneDetectionModule();

  /**
   *   @brief Default destructor for LaneDetectionModule
   *
   *
   *   @param nothing
   *   @return nothing
   */
  ~LaneDetectionModule();

  /**
	   *   @brief Method Undistortedimage for LaneDetectionModule
	   *
	   *
	   *   @param src is a Matrix of source of image
	   *   @param dst is a Matrix of destination of image
	   *   @return nothing
	   */
	void undistortImage(const cv::Mat& src,cv::Mat& dst);

  /**
	   *   @brief Method thresholdImageY to set
	   *   		  yellow threshold image for LaneDetectionModule
	   *
	   *
	   *   @param src is a Matrix of source of image
	   *   @param dst is a Matrix of destination of image
	   *   @return nothing
	   */
	void thresholdImageY(const cv::Mat& src,cv::Mat& dst);

  /**
	   *   @brief Method thresholdImageW to set
	   *   		white threshold image for LaneDetectionModule
	   *
	   *
	   *   @param src is a Matrix of source of image
	   *   @param dst is a Matrix of destination of image
	   *   @return nothing
	   */
	void thresholdImageW(const cv::Mat& src,cv::Mat& dst);

  /**
	   *   @brief Method extractROI to set
	   *   		  region of interest for LaneDetectionModule
	   *
	   *
	   *   @param src is a Matrix of source of image
	   *   @param dst is a Matrix of destination of image
	   *   @return nothing
	   */
	void extractROI(const cv::Mat& src,cv::Mat& dst);
	  /**
	   *   @brief Method extractLanes to calculate
	   *   		  parameters of lines and its characteristics
	   *   		  for LaneDetectionModule.
	   *
	   *   @param src is a Matrix of source of image
	   *   @param dst is a Matrix of destination of image
	   *   @param lane1 object of class lane to store line characteristic.
	   *   @param lane2 object of class lane to store line characteristic
	   *   @param curveFlag to set degree of curve
	   *   @return nothing
	   */
	void extractLanes(const cv::Mat& src,Lane& lane1,Lane& lane2,int curveFlag);

  /**
	   *   @brief Method getDriveHeading to calculate
	   *   		  drive heading to be given to actuator for further action
	   *   		  in LaneDetectionModule.
	   *
	   *   @param lane1 object of class lane to store line characteristic.
	   *   @param lane2 object of class lane to store line characteristic.
	   *   @return double value of drive head.
	   */
	double getDriveHeading(Lane& lane1,Lane& lane2);

  /**
	   *   @brief Method displayOutput to calculate
	   *   		  to display of the system
	   *   		  for LaneDetectionModule.
	   *
	   *   @param src is a Matrix of source of image
	   *   @param lane1 object of class lane to store line characteristic.
	   *   @param lane2 object of class lane to store line characteristic
	   *   @param heading to get Drive heading for output
	   *   @return nothing
	   */
	void displayOutput(const cv::Mat& src,Lane& lane1,Lane& lane2,double heading);

  /**
	   *   @brief Method detectLane check if program is successfully running
	   *   		  gives bool output for LaneDetectionModule
	   *
	   *   @param videoName is video of source
	   *   @return bool for code working.
	   */
	bool detectLane(std::string videoName);

  /**
	   *   @brief Method getYellowMax is to use get max value of yellow
	   *   for LaneDetectionModule
	   *
	   *   @param nothing
	   *   @return Scalar of RGB set values.
	   */
	cv::Scalar getYellowMax();

  /**
	   *   @brief Method getYellowMin is to use get min value of yellow
	   *   for LaneDetectionModule
	   *
	   *   @param nothing
	   *   @return Scalar of RGB set values.
	   */
	cv::Scalar getYellowMin();

  /**
	   *   @brief Method setYellowMax is to use set max value of yellow
	   *   for LaneDetectionModule
	   *
	   *   @param  Scalar of RGB values
	   *   @return nothing.
	   */
  void setYellowMax(cv::Scalar value);

  /**
	   *   @brief Method setYellowMin is to use set min value of yellow
	   *   for LaneDetectionModule
	   *
	   *   @param  Scalar of RGB values
	   *   @return nothing.
	   */
  void setYellowMin(cv::Scalar value);

  /**
	   *   @brief Method setGrayScaleMax is to use set max value of Gray scale
	   *   value for LaneDetectionModule
	   *
	   *   @param  int of GrayScale values
	   *   @return nothing.
	   */
	void setGrayScaleMax(int value);

  /**
	   *   @brief Method setGrayScaleMin is to use set min value of Gray scale
	   *   value for LaneDetectionModule
	   *
	   *   @param  int of GrayScale values
	   *   @return nothing.
	   */
	void setGrayScaleMin(int value);

  /**
	   *   @brief Method getGrayScaleMin is to use get min value of GrayScale
	   *   for LaneDetectionModule
	   *
	   *   @param nothing
	   *   @return int of GrayScale values
	   */
	int getGrayScaleMin();

  /**
	   *   @brief Method getGrayScaleMax is to use get max value of GrayScale
	   *   for LaneDetectionModule
	   *
	   *   @param nothing
	   *   @return int of GrayScale values
	   */
	int getGrayScaleMax();

private:
	cv::Scalar yellowMin;  // max possible RGB values of yellow
	cv::Scalar yellowMax;  // min possible RGB values of yellow
	int grayscaleMin;  // min possible grayscale value for white in our video
	int grayscaleMax;  // max possible grayscale value for white in our video
	std::string videoName;  // specify video name
};

#endif /* LANEDETECTIONMODULE_H_ */
