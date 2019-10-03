#include <iostream>
using namespace std;

#include "../include/Eigen/Core"
#include "../include/Eigen/Dense"

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
}