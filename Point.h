#pragma once
#include<iostream>
using namespace std;

class Point {
public:
	//设置横坐标
	void setX(double x);
	//获取横坐标
	double getX();
	void setY(double y);
	double getY();
private:
	//横纵坐标
	double m_x;
	double m_y;
};
