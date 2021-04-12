#include <iostream>
#include <cmath>
using namespace std;
#define N 5


double function(double x){
  return ( (-0.1*pow(x,4)) - (0.15*pow(x,3)) - (0.5*pow(x,2)) - (0.15*x) + 1.2 );
}

double derivativeFunction(double x){
  return ((-0.4*pow(x,3)) - (0.45*pow(x,2)) - (x) -0.15);
}

double centralDifference(double (*f)(double), double x, double h){
  return (f(x + h) - f(x - h)) / (2 * h);
}


int main(){
  double x = 0.5;
  double h = 1.0;
  double hValues[] = {5,4,3,2,1,0.5,0.25,0.1,0.01,0.001};



  cout << "at x = " << x << endl;
  cout << "function = " << function(x) << endl;
  cout << "derivative = " << derivativeFunction(x) << endl << endl;

  for(int i=0;i<10;i++){
    cout << "Central Difference approximation (h = " << hValues[i] << ") = "<< centralDifference(function,  x,  hValues[i]) << endl;
    cout << "Error = " << centralDifference(function,  x,  hValues[i]) - ((centralDifference(function,  x+1,  hValues[i]) - centralDifference(function,  x-1,  hValues[i])) / (2*h)) << endl;

  }
}
