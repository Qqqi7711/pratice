#include "Circle.h"


	void Circle::setR(double r) {
		m_radius = r;
	}
	//��ȡ�뾶
	double Circle::getR() {
		return m_radius;
	}
	//����Բ��
	void Circle::setCenter(Point center) {
		m_center = center;
	}
	Point Circle::getCenter() {
		return m_center;
	}
