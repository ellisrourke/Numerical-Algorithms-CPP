#include<iostream>
#include<cmath>
//using namespace std;

double dydz( double z, double y, double v) { return (30.0-z) * (30.0-z) * 60.0/(2.0*pow(1.25*10,8)*0.05); }
double dvdz( double z, double y, double v) { return v; }

double rk4(double y0, double z0, double v0, double zt, double dz)
{
    int n = (int)((zt - z0) / dz);

    double ky1, ky2, ky3, ky4;
    double kv1, kv2, kv3, kv4;

    double z=z0, y=y0, v=v0;

    for (int i=1; i<=n; i++)
    {
        ky1=dz*dydz(z,y,v);
        kv1=dz*dvdz(z,y,v);
        ky2=dz*dydz(z+dz/2,y+ky1/2,v+kv1/2);
        kv2=dz*dvdz(z+dz/2,y+ky1/2,v+kv1/2);
        ky3=dz*dydz(z+dz/2,y+ky2/2,v+kv2/2);
        kv3=dz*dvdz(z+dz/2,y+ky2/2,v+kv2/2);
        ky4=dz*dydz(z+dz,y+ky3,v+kv3);
        kv4=dz*dvdz(z+dz,y+ky3,v+kv3);

        // Step in z direction
        z += dz;

        // y(i+1)
        y = y + (ky1 + 2*ky2 + 2*ky3 + ky4)/6.0;
        // v(i+1)
        v = v + (kv1 + 2*kv2 + 2*kv3 + kv4)/6.0;
    }

    return y;
}

int main()
{
    // Solve for different heights z.
    for (double z = 0.0; z <= 10.0; z++) {
        std::cout << "For z=" << z <<  "\ty="
                  << rk4(0.0, 0.0, 0.0, z, 0.1)
                  << std::endl;
    }

    return 0;
}
