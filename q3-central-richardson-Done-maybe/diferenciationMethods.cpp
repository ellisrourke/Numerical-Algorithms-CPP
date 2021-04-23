#include <iostream>
#include <cmath>
using namespace std;
#define N 5

double fnc(double x){
  return ( -(0.1 * pow(x,4)) - (0.15*pow(x,3)) - (0.5*pow(x,2)) - (0.25*x) + 1.2 );
}

double derivativefnc(double x){
  return ( -(0.4*pow(x,3)) - (0.45*pow(x,2)) - x - 0.25);

}

void richardsonExtrapolation(double (*f)(double), double x, double h, double trueValue){
  double ht;
  double results[N][N];
  ht = h;
  for(int i=0; i<N; i++){
    results[i][0] = (fnc(x + ht) - fnc(x - ht)) / (2 * ht);
    for(int j=1; j<=i; j++){
      results[i][j] = results[i][j-1] + (results[i][j-1] - results[i-1][j-1]) / (pow(4,j) - 1);
    }
    ht /= 2;
  }

  cout << "Central Difference value = " << results[1][0] << endl;
  cout << "Error " << fixed << abs((trueValue - results[1][0])/trueValue)*100 << "%" << endl << endl;
  cout << "Richardson Extrapolation value = " << results[N-1][0] << endl;
  cout << "Error " << fixed << abs((trueValue - results[N-1][0])/trueValue)*100 << "%" << endl << endl;

  return;
}//


int main(){
    double x = 0.5;
    double hValues[] = {2,1,0.5,0.25,0.1};
    double trueValue = derivativefnc(x);
    cout << "Richardson Extrapolation vs Central Difference" << endl << endl;

    cout << "True value of fnc = " << fnc(x) << endl;
    cout << "True value of derivative = " << trueValue << endl << endl;



    for(int i=0; i<5; i++){
        cout << "---- Results for h = " << hValues[i] << " ----" << endl;
        richardsonExtrapolation(&fnc, x, hValues[i], trueValue);
        cout << "----------------------------------------------" << endl;
    }


}
