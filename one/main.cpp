#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.

    float rad = rotation_angle * MY_PI / 180.0;//将旋转角度变为弧度制
    model << cos(rad), -sin(rad), 0, 0,
             sin(rad),  cos(rad), 0, 0,
              0,          0,      1, 0,
              0,          0,      0, 1;//绕Z轴旋转的齐次变换矩阵

    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    //eye_fov 垂直视野高度 fov:field of view
    // aspect_ratio 宽高比  width/height
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    //先将透视投影转换为正交投影
    Eigen::Matrix4f proj_ortho;
    proj_ortho << zNear, 0,     0,            0,
                  0,     zNear, 0,            0,
                  0,     0,     zNear + zFar, -zNear * zFar,
                  0,     0,     1,            0;
    //再求出正交投影变换矩阵
    // 计算参数
    float yTop = fabs(zNear) * tan(eye_fov / 2.0 * MY_PI / 180.0);//上边界 top
    float xRight = yTop * aspect_ratio;//右边界 right
    float yBotton = -yTop;//下边界 botton
    float xLeft = -xRight;//左边界 left
    //把中心移到原点
    Eigen::Matrix4f translate;
    translate << 1, 0, 0,   -(xRight + xLeft)/2.0,
                 0, 1, 0, -(yTop + yBotton) / 2.0,
                 0, 0, 1,   -(zNear + zFar) / 2.0,
                 0, 0, 0,                       1;
    //将结果缩放为[-1，1]范围内
    Eigen::Matrix4f scale;
    scale << 2/(xRight-xLeft), 0,                0,              0,
             0,                2/(yTop-yBotton), 0,              0,
             0,                0,                2/(zNear-zFar), 0,
             0,                0,                0,              1;

    projection = scale * translate * proj_ortho;
    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.

    return projection;
}

int main(int argc, const char** argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
