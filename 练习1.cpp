//#include<iostream>
//using namespace std;
//
//#define PI 3.14
//class Circle {
//public:
//	//����
//	double radius;
//	//��Ϊ
//	double getZC() {
//		return 2 * PI * radius;
//	}
//};
//
//class Student {
//public:
//	//����
//	string name;
//	int ID;
//};
//
//int main()
//{
//	Circle c1;
//	c1.radius = 10;
//	cout << "Բ���ܳ�Ϊ��" << c1.getZC() << endl;
//
//	Student s1;
//	s1.name = "����";
//	s1.ID = 1002;
//	cout << "ѧ��������" << s1.name << endl;
//	cout << "ѧ��ѧ�ţ�" << s1.ID << endl;
//	system("pause");
//	return 0;
//}

//���Բ�Ĺ�ϵ����

#include<iostream>
using namespace std;

#include <math.h>

#include "Point.h"
#include "Circle.h"

////����
//class Point {
//public:
//	//���ú�����
//	void setX(double x) {
//		m_x = x;
//	}
//	//��ȡ������
//	double getX() {
//		return m_x;
//	}
//	void setY(double y) {
//		m_y = y;
//	}
//	double getY() {
//		return m_y;
//	}
//private:
//	//��������
//	double m_x;
//	double m_y;
//};

//Բ��
//class Circle {
//public:
//	//���ð뾶
//	void setR(double r) {
//		m_radius = r;
//	}
//	//��ȡ�뾶
//	double getR() {
//		return m_radius;
//	}
//	//����Բ��
//	void setCenter(Point center) {
//		m_center = center;
//	}
//	Point getCenter() {
//		return m_center;
//	}
//private:
//	double m_radius;//�뾶
//	//Բ������
//	Point m_center;
//};

//�жϵ���Բ�Ĺ�ϵ����
void judgePC(Point &p, Circle &c) {
	double distance = pow((p.getX() - c.getCenter().getX()), 2) + pow((p.getY() - c.getCenter().getY()), 2);
	double rDistance = pow(c.getR(), 2);
	if (distance == 0) {
		cout << "����Բ����" << endl;
	}
	else {
		if (distance < rDistance) {
			cout << "����Բ��" << endl;
		}
		else if (distance == rDistance) {
			cout << "����Բ��" << endl;
		}
		else if (distance > rDistance) {
			cout << "����Բ��" << endl;
		}
	}
}

int main() {
	//����Բ����
	Point center;
	center.setX(0);
	center.setY(0);
	Circle c1;
	c1.setCenter(center);
	c1.setR(2);
	//����Ŀ������
	Point p1;
	p1.setX(0);
	p1.setY(0);
	judgePC(p1, c1);
	system("pause");
	return 0;
}