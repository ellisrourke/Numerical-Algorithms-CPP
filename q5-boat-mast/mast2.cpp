#include<iostream>
#include<cmath>
using namespace std;

double dydz(double z){
  return (60.0 / (2 * (1.25 * pow(10,8)) * 0.05)) * pow((30.0 - z),2);
}

double rk4(double z0, double zn, double h){
    int n = (int)((zn - z0) / h); //Calculate required iterations for given z value
    double k1, k2, k3, k4;
    double z = z0;

    for (int i=1; i<=n; i++){ //Calculate each component of RK4 formula
        k1 = h*dydz(z0);
        k2 = h*dydz(z0 + k1/2);
        k3 = h*dydz(z0 + k2/2);
        k4 = h*dydz(z0 + k3);

        z += (k1 + 2*k2 + 2*k3 + k4)/6.0; //Calculate next Z value with RK4 formula
    }
    return z;
}

int main(){
    for (double z = 0; z <= 10; z++){
         std::cout << "z = " << z << " y = " << rk4(0.0, z, 0.1) << std::endl;
  }
    return 0;
}
