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
  return nums[x/2];
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
  int segments = 1;
  double **Rows;
  double result;
  Rows = new double * [20];
  Rows[1] = new double [2];

  Rows[1][1] = multiApplicationTrapezoidal(a,b,func,segments);

  segments *= 2;

  for(int i=2; i<20; i++){
    Rows[i] = new double [i + 1];
    for(int j=1; j<=i; j++){
      if(j == 1){
        Rows[i][j] = multiApplicationTrapezoidal(a,b,func,segments);
        segments *= 2;
      } else {
        Rows[i][j] = Rows[i][j-1] + (Rows[i][j - 1] - Rows[i - 1][j - 1]) / (pow(4, j - 1) - 1);
          cout << "values " << Rows[i][j] << " " << Rows[i][j-1] << endl;
          cout << "Error " << (Rows[i][j] - Rows[i][j-1]) * 100 / Rows[i][j] << endl;

        if((Rows[i][j] - Rows[i][j-1]) * 100 / Rows[i][j] < 1){
          result = Rows[i][j];
          i = 100;
          break;

        }
      }
    }
  }


  for (int x=1; x<4; x++) {
      for (int k=1; k <=x; k++) {
          std::cout << std::fixed << Rows[x][k] << " ";
      }
      std::cout << endl;
    }

  return result;
}

int main(){
  double a = 0.0;
  double b = 16.0;
  cout << "Romberg result = " << romberg(a,b,function) << endl;
  return 0;
}

//0.000000
//19.200000 25.600000
//26.600000 29.066667 29.297778
//Answer = 29.297778
