#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<iostream>

#define M_PI 3.14

using namespace std;
using namespace Eigen;

int main(){
    Vector3f p(1.0f, 2.0f, 1.0f);//��������µ�p��
    Matrix3f R;
    float angle = M_PI / 4;

    R << cos(angle), -sin(angle), 1,
         sin(angle),  cos(angle), 2,
		     0,          0,       1;  //����ʱ����ת45�ȣ���ƽ��(1,2)�ı任����R
    Vector3f p_transformed = R*p;

    cout << "�任ǰ��" << p.transpose()<< endl;
    cout << "�任��" << p_transformed.transpose()<< endl;


    return 0;
}