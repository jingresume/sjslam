#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;

int main(int argc, char **argv) {
    
    Eigen::Quaterniond q1 = Eigen::Quaterniond(0.35,0.2,0.3,0.1);
    Eigen::Vector3d t1 (0.3,0.1,0.1);
    cout << "q1 = " << q1.coeffs()<<endl;
    
    Eigen::Quaterniond q2 = Eigen::Quaterniond(-0.5,0.4,-0.1,0.2);
    Eigen::Vector3d t2 (-0.1,0.5,0.3);

    Eigen::Isometry3d Tcw1=Eigen::Isometry3d::Identity();
    Eigen::Isometry3d Tcw2=Eigen::Isometry3d::Identity();
 
    Tcw1.rotate ( q1 );
    Tcw1.pretranslate ( t1 );
    
    Tcw2.rotate ( q2 );
    Tcw2.pretranslate ( t2 );

    cout <<"Tcw1 = \n" << Tcw1.matrix() << endl;
    cout <<"Tcw2 = \n" << Tcw2.matrix() << endl;

    Eigen::Vector3d pc1 (0.5,0,0.2);
    Eigen::Vector3d pc2;
    Eigen::Vector3d pw;

    pw=Tcw1.inverse()*pc1;
    pc2 = Tcw2*pw;

    cout << "the cooridinate = " << pc2.transpose() <<endl;
    return 0;
}
