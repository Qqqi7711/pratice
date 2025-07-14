#pragma once
#include <iostream>
using namespace std;

#include "Point.h"

class Circle {
public:
	//设置半径
	void setR(double r);
	//获取半径
	double getR();
	//设置圆心
	void setCenter(Point center);
	Point getCenter();
private:
	double m_radius;//半径
	//圆心坐标
	Point m_center;
};
