#include<iostream>
#include<cmath>
using namespace std;

int main(){
  //f = Wind force
  //E = Modulus of elasticity
  //L = Mast length
  //I = Momnet of inertia

  //y = 0
  //dy/dz = 0 at z=0
  //f = 60
  //E = 1.25 * 10^8
  //L = 30
  //I = 0.05
  double f = 60.0;
  double z = 0.0;
  double x = 60.0;
  double e = 1.25 * pow(10,8);
  double l = 30.0;
  double i = 0.05;
  //cout <<  (-1 * ((f * x * x) / (6 * e * i)) * (3 * l * x)) << endl;
  cout <<  ( (f)/(2 * e * i) * pow(l,2) ) << endl;

}
