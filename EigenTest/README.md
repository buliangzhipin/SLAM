Add Eigen library

There are four ways to express rotation in Eigen.
* rotation matrix
* Axis–angle representation
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

### Axis–angle representation
In mathematics, the axis–angle representation of a rotation parameterizes a rotation in a three-dimensional Euclidean space by two quantities: a unit vector **e** indicating the direction of an axis of rotation, and an angle **θ** describing the magnitude of the rotation about the axis. 

Only two numbers, not three, are needed to define the direction of a unit vector e rooted at the origin because the magnitude of e is constrained. For example, the elevation and azimuth angles of e suffice to locate it in any particular Cartesian coordinate frame.

And by Rodrigues's Formula, we can translate it to rotation matrix as below

![](https://latex.codecogs.com/gif.latex?\mathbf{R}=\cos{\theta&space;}\mathbf{I}&plus;(1-\cos{\theta})\mathbf{v}\mathbf{v}^T&plus;\sin{\theta}\mathbf{v}^\wedge)

![](https://latex.codecogs.com/gif.latex?\mathbf{v}^\wedge=\begin{bmatrix}&space;0&space;&&space;-v_3&space;&&space;v_2\\\\&space;v_3&space;&&space;0&space;&&space;-v_1\\\\&space;v_2&space;&&space;v_1&space;&&space;0&space;\end{bmatrix}) (skew-symmetrix matrix)

And it can be created as 
```
Eigen::AngleAxisd rotation_vector(EIGEN_PI/4,Eigen::Vector3d(0,0,1)); //
Rotate 45 degrees along the z axis
```
