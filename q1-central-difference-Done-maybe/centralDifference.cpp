#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;
#define N 5


double function(double x){
  return ( (-0.1*pow(x,4)) - (0.15*pow(x,3)) - (0.5*pow(x,2)) - (0.15*x) + 1.2 );
}

double derivativeFunction(double x){
  return ((-0.4*pow(x,3)) - (0.45*pow(x,2)) - (x) -0.15);
}

double secondDerivative(double x){
  return( (-1.2*pow(x,2)) - 0.9*x - 1 );
}

double thirdDerivative(double x){
  return( -2.4 * x - 0.9 );
}
double centralDifference(double (*f)(double), double x, double h){
  return (f(x + h) - f(x - h)) / (2 * h);
}


int main(){
  double x = 0.5;
    double hopt = -1*cbrt((3*numeric_limits<double>::epsilon()/thirdDerivative(x)));
    double hValues[] = {10,5,4,3,2,1.5,1,0.5,0.25,0.1,hopt};

  double calculatedValue;
  double roundOffError;
  double truncationError;
  cout << "at x = " << x << endl;
  cout << "function = " << function(x) << endl;
  cout << "derivative = " << derivativeFunction(x) << endl << endl;
  cout << "H-opt = " << hopt << endl;
    for(int i=0;i<11;i++){
    calculatedValue = centralDifference(function,  x,  hValues[i]);
    roundOffError = calculatedValue - ((centralDifference(function,  x+1,  hValues[i]) - centralDifference(function,  x-1,  hValues[i])) / (2* hValues[i]));
    truncationError = (thirdDerivative(numeric_limits<double>::epsilon())/6) * (hValues[i] * hValues[i]);
    cout << "Central Difference approximation (h = " << hValues[i] << ") = " << calculatedValue << endl;
    cout << "Round off error = " << roundOffError << endl;
    cout << "Truncation error = " << truncationError << endl;
    cout << "True value = " << (calculatedValue + roundOffError - truncationError) << endl << endl;
  }
}
