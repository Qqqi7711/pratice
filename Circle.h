#pragma once
#include <iostream>
using namespace std;

#include "Point.h"

class Circle {
public:
	//���ð뾶
	void setR(double r);
	//��ȡ�뾶
	double getR();
	//����Բ��
	void setCenter(Point center);
	Point getCenter();
private:
	double m_radius;//�뾶
	//Բ������
	Point m_center;
};
