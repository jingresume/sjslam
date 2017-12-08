#include <iostream>
#include <Eigen/Core>
#include <cmath>
#include <Eigen/Geometry>

using namespace std;
int main(int argc, char **argv) {
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    
    Eigen::AngleAxisd  rotation_vector ( M_PI/4, Eigen::Vector3d( 0,0,1 ) );
    cout.precision(3);
    
    cout << "rotation matrix =\n" <<rotation_vector.matrix()<<endl;
    
    rotation_matrix = rotation_vector.toRotationMatrix();
    
    Eigen::Vector3d v (1,0,0);
    Eigen::Vector3d v_rotated = rotation_vector*v;
    cout << "(1,0,0) after rotation ="<<v_rotated.transpose()<<endl;
    
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation ="<<v_rotated.transpose()<<endl;
    
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2,1,0) ; // eulerAngles(2,1,0) denote the order of rotation is ZYX
    
    cout<< "yaw pitch roll = " << euler_angles.transpose() << endl;
    
    Eigen::Isometry3d T=Eigen::Isometry3d::Identity();
    T.rotate( rotation_vector );   //set rotation matrix
    
 //   cout<<"rotation vector after T.rotate = "<< rotation_vector <<endl;
    
    T.pretranslate ( Eigen::Vector3d ( 1,3,4 ) );  //set translation vector
    
    cout << "Transform matrix = \n" << T.matrix() << endl;
    
    Eigen::Vector3d v_transformed = T*v;
    
    cout << "v transform = " << v_transformed.transpose() << endl;
    
    Eigen::Quaterniond q = Eigen::Quaterniond ( rotation_vector );
    
    cout << "quaterniond = \n" << q.coeffs() <<endl;
  
    q = Eigen::Quaterniond (rotation_matrix);
    
    cout << "quaterniond = \n" << q.coeffs() <<endl;
    
    v_rotated = q*v;
    
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
    
    
    return 0;
}








