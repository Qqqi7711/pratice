#include "Circle.h"


	void Circle::setR(double r) {
		m_radius = r;
	}
	//获取半径
	double Circle::getR() {
		return m_radius;
	}
	//设置圆心
	void Circle::setCenter(Point center) {
		m_center = center;
	}
	Point Circle::getCenter() {
		return m_center;
	}
