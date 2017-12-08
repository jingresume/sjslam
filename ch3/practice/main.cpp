#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;

int main(int argc, char **argv) {
    
    Eigen::Quaterniond q1 = ( 0.35,0.2,0.3,1.0 );
    
    cout << "q1 = " << q1.coeffs()<<endl;
    
    return 0;
}
