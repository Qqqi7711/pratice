#pragma once
#include<iostream>
using namespace std;

class Point {
public:
	//���ú�����
	void setX(double x);
	//��ȡ������
	double getX();
	void setY(double y);
	double getY();
private:
	//��������
	double m_x;
	double m_y;
};
