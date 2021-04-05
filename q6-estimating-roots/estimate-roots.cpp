#include <iostream>
#include <cmath>
using namespace std;
const double EulerConstant = std::exp(1.0);


double func(double x){
    return (pow(EulerConstant,-x) - x);
}

void bisection(double xi, double xu, double xr, double(* func)(double), int num){
    
    //calculate stopping condition
    
    while(true){
        double previous = xr;
        xr = (xi + xu) / 2;
        
        if(abs(((xr - previous) / xr)*100) < 0.0005){
            cout << "stopping" << endl;
            break;
        }
        
        if((func(xi) * func(xr)) < 0){
            xu = xr;
        } else {
            xi = xr;
        }
        
        num++;
    }
    cout << "Bisection Estimate " << fixed << xr << endl;
    return;
    
    
    
}


int main(){
  cout << "Estimate Function Roots" << endl;
  //Bisection, Newton- Raphson and Secant
  // f(x) = e^-x -x
  // x(-1) = 0
  // x(0) = 1
  double xi = 0;
  double xu = 1;
    double xr;
  bisection(xi, xu, xr, func, 0);
  return 0;
}
