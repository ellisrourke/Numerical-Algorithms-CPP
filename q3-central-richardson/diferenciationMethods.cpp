#include <iostream>
#include <cmath>
using namespace std;

double func(double x){
  return ( (-0.1 * pow(x,4)) - (0.15*pow(x,3)) - (0.5*pow(x,2)) - (0.25*x) + 1.2 );
}

double centralDifference(double (*f)(double), double x, double h){
  cout << f(x) << endl;
}

double richardsonExtrapolation(double (*f)(double), double x, double h){
  cout << f(x) << endl;
}

int main(){
  double x = 0.5;
  cout << func(x) << endl;
  centralDifference(&func, x, 1);
}
