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

void bisection(double xi, double xu, double xr, double(* func)(double)){
  //calculate stopping condition
  double previous;
  while(true){
    previous = xr;
    xr = (xi + xu) / 2;
    if(abs(((xr - previous) / xr)*100) < 0.0005){
      break;
    }

    if((func(xi) * func(xr)) < 0){
        xu = xr;
    } else {
        xi = xr;
    }
  }

  cout << "Bisection Estimate " << fixed << xr << endl;
  return;
}

void newtonRaphson(double xi, double xu, double(* func)(double)){
  double previous;
  while(true){
    previous = xi;
    xi = previous - (func(previous) / dfunc(previous));
    if(abs(((xi - previous))*100) < 0.0005){
      cout << "Newton Raphson Estimate " << fixed << xi << endl;
      break;
    }
  }

}

void secant(double xi, double xu, double(* func)(double)){
  double previous;
  while(true){
    previous = xi;
    xi = xi - (xi - xu) / (func(xi) - func(xu)) * func(xi);
    if(abs(((xi - previous))*100) < 0.0005){
      cout << "Secant Estimate " << fixed << xi << endl;
      break;
    }
  }
}


int main(){
  cout << "Estimate Function Roots" << endl << endl;
  //Bisection, Newton- Raphson and Secant
  // f(x) = e^-x -x
  // x(-1) = 0
  // x(0) = 1
  double xi = 0;
  double xu = 1;
  double xr;

  bisection(xi, xu, xr, func);
  newtonRaphson(xi, xu, func);
  secant(xi, xu, func);
  return 0;
}
