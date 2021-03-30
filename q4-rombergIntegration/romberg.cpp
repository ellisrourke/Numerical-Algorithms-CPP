#include <iostream>
#include <cmath>
#include <map>
using namespace std;


double function(int x){
  double nums[] = {0.0,
                   1.9,
                   2.0,
                   2.0,
                   2.4,
                   2.6,
                   2.25,
                   1.12,
                   0.0};
  return nums[x / 2];
}



double multiApplicationTrapezoidal(double a, double b, double(* func)(int), int n){
  double result = func(a) + func(b);
  double h = (b - a) / n;
  for(int i=1;i<n;i++){
    result += 2 * func(a + i * h);
  }
  result *= (b - a) / (2*n);
  return result;
}

double romberg(double a, double b, double(* func)(int)){
  int segments = 2;
  double **Rows, result;
  Rows = new double * [100];

  Rows[1] = new double [2];
  Rows[1][1] = multiApplicationTrapezoidal(a,b,func,segments);
  segments *= 2;

  for(int i=2; i<100; i++){
    Rows[i] = new double [i + 1];
    for(int j=1;j<i;j++){
      if(j == 1){
        Rows[i][j] = multiApplicationTrapezoidal(a,b,func,segments);
        segments *= 2;
      } else {
        Rows[i][j] = Rows[i][j-1] + (Rows[i][j - 1] - Rows[i - 1][j - 1]) / (pow(4, j-1)-1);
        cout << "progress: " << Rows[i][j] << std::endl;
        if((Rows[i][j] - Rows[i][j-1]) * 100 / Rows[i][j] < 0.01){
          result = Rows[i][j];
          cout << "here?" << Rows[i][j] << endl;
          i = 100;
          break;
        }
      }
    }
  }
  for (int x=0; x< 10; x++) {
      for (int k=1; k <=x; k++) {
          std::cout << std::fixed << Rows[x][k] << " ";
      }
      std::cout << endl;
    }

  return result;
}

int main(){
  cout << romberg(0,16,function) << endl;
  return 0;
}
