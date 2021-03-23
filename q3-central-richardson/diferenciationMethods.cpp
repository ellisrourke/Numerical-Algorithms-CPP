#include <iostream>
#include <cmath>
using namespace std;
#define N 5

double function(double x){
  return ( -(0.1 * pow(x,4)) - (0.15*pow(x,3)) - (0.5*pow(x,2)) - (0.25*x) + 1.2 );
}

double derivativeFunction(double x){
  return ( -(0.4*pow(x,3)) - (0.45*pow(x,2)) - x - 0.25);

}

double richardsonExtrapolation(double (*f)(double), double x, double h){
  double ht;
  double results[N][N];
  ht = h;
  for(int i=0; i<N; i++){
    results[i][0] = (function(x + ht) - function(x - ht)) / (2 * ht);
    for(int j=1; j<=i; j++){
      results[i][j] = results[i][j-1] + (results[i][j-1] - results[i-1][j-1]) / (pow(4,j) - 1);
    }
  ht /= 2;
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<=i; j++){
      cout << results[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Central Difference value = " << results[1][0] << endl;
  cout << "Richardson Extrapolation value = " << results[N-1][N-1] << endl;

}//


int main(){
  double x = 0.5;
  richardsonExtrapolation(&function, x, 0.5);
  cout << "True value of function = " << function(x) << endl;
  cout << "True value of derivative = " << derivativeFunction(x) << endl;

}
