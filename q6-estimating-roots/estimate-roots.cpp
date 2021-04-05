#include <iostream>
#include <cmath>
using namespace std;
const double EulerConstant = std::exp(1.0);


double func(double x){
    return (pow(EulerConstant,-x) - x);
}

double dfunc(double x){
  return (-1.0 * pow(EulerConstant,-x) - 1);
}

void bisection(double xi, double xu, double xr, double(* func)(double), int num){
  //calculate stopping condition
  double previous;
  while(true){
    previous = xr;
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

void newtonRaphson(double xi, double xu, double(* func)(double), int num){
  //x0 = xi
  //x1 = xu
  double previous;
  while(true){
    previous = xi;
    xi = previous - (func(previous) / dfunc(previous));
    cout << xi << endl;
    if(abs(((xi - previous))*100) < 0.0005){
      break;
    }
  }






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

  //bisection(xi, xu, xr, func, 0);
  newtonRaphson(xi, xu, func, 0);

  return 0;
}
