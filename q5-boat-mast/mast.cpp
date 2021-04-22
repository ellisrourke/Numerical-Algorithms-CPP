#include<iostream>
#include<cmath>
using namespace std;

#define L 30.0
#define F 60.0
#define E pow(1.25*10,8)
#define I 0.05

double func_dydz(double z){
  return (60.0 / (2 * pow(1.25*10,8) * 0.05)) * (30.0 - z) * (30.0 - z);
}

double rk(double y0, double z0, double v0, double zt, double dz){
    int n = (int)((zt - z0) / dz);

    double ky1, ky2, ky3, ky4;
    double kv1, kv2, kv3, kv4;

    double z=z0, y=y0, v=v0;

    for (int i=1; i<=n; i++)
    {
        ky1=dz*func_dydz(z);
        ky2=dz*func_dydz(z+dz/2);
        ky3=dz*func_dydz(z+dz/2);
        ky4=dz*func_dydz(z+dz);


        kv1=dz*v;
        kv2=dz*v;
        kv3=dz*v;
        kv4=dz*v;

        // Step in z direction
        z += dz;

        // y(i+1)
        y = y + (ky1 + 2*ky2 + 2*ky3 + ky4)/6.0;
        // v(i+1)
        v = v + (kv1 + 2*kv2 + 2*kv3 + kv4)/6.0;
    }

    return y;
}


int main(){

  //cout << func_dydz(1) << endl;
  //cout << dydz(1) << endl;
  for (double z = 0.0; z <= 10.0; z++) {
       std::cout << "For z=" << z <<  "\ty=" << rk(0.0, 0.0, 0.0, z, 0.1) << std::endl;
}




}
