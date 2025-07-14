//#include<iostream>
//using namespace std;
//
//#define PI 3.14
//class Circle {
//public:
//	//属性
//	double radius;
//	//行为
//	double getZC() {
//		return 2 * PI * radius;
//	}
//};
//
//class Student {
//public:
//	//属性
//	string name;
//	int ID;
//};
//
//int main()
//{
//	Circle c1;
//	c1.radius = 10;
//	cout << "圆的周长为：" << c1.getZC() << endl;
//
//	Student s1;
//	s1.name = "张四";
//	s1.ID = 1002;
//	cout << "学生姓名：" << s1.name << endl;
//	cout << "学生学号：" << s1.ID << endl;
//	system("pause");
//	return 0;
//}

//点和圆的关系案例

#include<iostream>
using namespace std;

#include <math.h>

#include "Point.h"
#include "Circle.h"

////点类
//class Point {
//public:
//	//设置横坐标
//	void setX(double x) {
//		m_x = x;
//	}
//	//获取横坐标
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
//	//横纵坐标
//	double m_x;
//	double m_y;
//};

//圆类
//class Circle {
//public:
//	//设置半径
//	void setR(double r) {
//		m_radius = r;
//	}
//	//获取半径
//	double getR() {
//		return m_radius;
//	}
//	//设置圆心
//	void setCenter(Point center) {
//		m_center = center;
//	}
//	Point getCenter() {
//		return m_center;
//	}
//private:
//	double m_radius;//半径
//	//圆心坐标
//	Point m_center;
//};

//判断点与圆的关系函数
void judgePC(Point &p, Circle &c) {
	double distance = pow((p.getX() - c.getCenter().getX()), 2) + pow((p.getY() - c.getCenter().getY()), 2);
	double rDistance = pow(c.getR(), 2);
	if (distance == 0) {
		cout << "点在圆心上" << endl;
	}
	else {
		if (distance < rDistance) {
			cout << "点在圆内" << endl;
		}
		else if (distance == rDistance) {
			cout << "点在圆上" << endl;
		}
		else if (distance > rDistance) {
			cout << "点在圆外" << endl;
		}
	}
}

int main() {
	//创建圆对象
	Point center;
	center.setX(0);
	center.setY(0);
	Circle c1;
	c1.setCenter(center);
	c1.setR(2);
	//创建目标点对象
	Point p1;
	p1.setX(0);
	p1.setY(0);
	judgePC(p1, c1);
	system("pause");
	return 0;
}