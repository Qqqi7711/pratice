#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<iostream>

#define M_PI 3.14

using namespace std;
using namespace Eigen;

int main(){
    Vector3f p(1.0f, 2.0f, 1.0f);//齐次坐标下的p点
    Matrix3f R;
    float angle = M_PI / 4;

    R << cos(angle), -sin(angle), 1,
         sin(angle),  cos(angle), 2,
		     0,          0,       1;  //先逆时针旋转45度，再平移(1,2)的变换矩阵R
    Vector3f p_transformed = R*p;

    cout << "变换前：" << p.transpose()<< endl;
    cout << "变换后：" << p_transformed.transpose()<< endl;


    return 0;
}