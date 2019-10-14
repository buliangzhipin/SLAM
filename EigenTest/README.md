Add Eigen library

There are four ways to express rotation in Eigen.
* rotation matrix
* Angle Axis
* Euler Angle
* Quaternion

### Rotation Matrix

![](https://latex.codecogs.com/gif.latex?R=\begin{pmatrix}&space;a&b&c\\\\&space;d&e&f\\\\&space;g&h&i&space;\end{pmatrix})

Assuming that we have a coordinate system and its basis is ![](https://latex.codecogs.com/gif.latex?\left&space;(&space;{\bf&space;e}_1,{\bf&space;e}_2,{\bf&space;e}_3&space;\right&space;)) and then the coordinate of vector a in this basis is 

![](https://latex.codecogs.com/gif.latex?a&space;=&space;\left&space;[&space;{\bf&space;e}_1,{\bf&space;e}_2,{\bf&space;e}_3&space;\right&space;]\begin{bmatrix}&space;a_1\\\\&space;a_2\\\\&space;a_3&space;\end{bmatrix}&space;=&space;a_1{\bf&space;e}_1&plus;a_2{\bf&space;e}_2&plus;a_3{\bf&space;e}_3)

And if the basis is rotated and it becomes ![](https://latex.codecogs.com/gif.latex?\left&space;(&space;{\bf&space;e'}_1,{\bf&space;e'}_2,{\bf&space;e'}_3&space;\right&space;)), and then a will become something like below

![](https://latex.codecogs.com/gif.latex?\left&space;[&space;{\bf&space;e}_1,{\bf&space;e}_2,{\bf&space;e}_3&space;\right&space;]\begin{bmatrix}&space;a_1\\\\&space;a_2\\\\&space;a_3&space;\end{bmatrix}&space;=&space;\left&space;[&space;{\bf&space;e'}_1,{\bf&space;e'}_2,{\bf&space;e'}_3&space;\right&space;]\begin{bmatrix}&space;a'_1\\\\&space;a'_2\\\\&space;a'_3&space;\end{bmatrix})

We can consider it like 
![](https://latex.codecogs.com/gif.latex?\begin{bmatrix}&space;a_1\\\\&space;a_2\\\\&space;a_3&space;\end{bmatrix}&space;=&space;\begin{bmatrix}&space;{\bf&space;e}^T_1{\bf&space;e}'_1&space;&&space;{\bf&space;e}^T_1{\bf&space;e}'_2&space;&{\bf&space;e}^T_1{\bf&space;e}'_3&space;\\\\&space;{\bf&space;e}^T_2{\bf&space;e}'_1&space;&&space;{\bf&space;e}^T_2{\bf&space;e}'_2&space;&{\bf&space;e}^T_2{\bf&space;e}'_3&space;\\\\&space;{\bf&space;e}^T_3{\bf&space;e}'_1&space;&&space;{\bf&space;e}^T_3{\bf&space;e}'_2&space;&{\bf&space;e}^T_3{\bf&space;e}'_3&space;\end{bmatrix}\begin{bmatrix}&space;a'_1\\\\&space;a'_2\\\\&space;a'_3&space;\end{bmatrix}\triangleq&space;\mathbf{R}a')

We call R is rotation matrix.

We can create a rotation matrix just by creating a martrix3d(3\*3 matrix) 
```
Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity()
```
