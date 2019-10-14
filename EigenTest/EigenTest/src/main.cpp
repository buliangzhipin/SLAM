#include <iostream>
#include <cmath>
using namespace std;

#include "../include/Eigen/Core"
#include "../include/Eigen/Dense"
#include "../include/Eigen/Geometry"

#define MAX_SIZE 60

int main()
{
	Eigen::Matrix<float, 2, 3> matrix_23;
	Eigen::Vector3d v_3d;
	Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
	Eigen::MatrixXd matrix_x;

	matrix_23 << 1, 2, 3, 4, 5, 6;
	cout << matrix_23 << endl;
	for (int i = 0; i < 1; i++)
		for (int j = 0; j < 2; j++)
			cout << matrix_23(i, j) << endl;

	v_3d << 3, 2, 1;

	Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
	cout << result << endl;
	
	matrix_33 = Eigen::Matrix3d::Random();
	cout << matrix_33 << endl << endl;


	Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
	Eigen::AngleAxisd rotation_vector(EIGEN_PI / 4, Eigen::Vector3d(0, 0, 1));
	cout.precision(3);
	cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;
	rotation_matrix = rotation_vector.toRotationMatrix();
	Eigen::Vector3d v(1, 0, 0);
	Eigen::Vector3d v_rotated = rotation_vector * v;
	cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
	v_rotated = rotation_matrix * v;
	cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;

	Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); //ZYX order, it means yaw pitch roll
	cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

	Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
	cout << "quaternion = \n" << q.coeffs() << endl;//coeffs is (x,y,z,w)

	//Or using Roatation Matrix
	q = Eigen::Quaterniond(rotation_matrix);
	cout << "quaternion = \n" << q.coeffs() << endl;
	v_rotated = q * v;
	cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
	int a;
	cin >> a;

	return 0;

}