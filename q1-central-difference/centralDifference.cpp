#include <iostream>
#include <cmath>
using namespace std;
#define N 5


double function(double x){
  return ( (-0.1*pow(x,4)) - (0.1*pow(x,3)) - (0.5*pow(x,2)) - (0.15*x) + 1.2 );
}

double derivativeFunction(double x){
  return ( (-0.4*pow(x,3)) - (-0.45*pow(x,2)) - (x) -0.15);

}

int main(){
  double x = 0.5;
  cout << "at x = " << x << endl;
  cout << "function = " << function(x) << endl;
  cout << "derivative = " << derivativeFunction(x) << endl;
}
//cd = (function(x + ht) - function(x - ht)) / (2 * ht);
