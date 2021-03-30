#include <iostream>
#include <cmath>
using namespace std;

double function(int x){
  double nums[] = {5120,
                   5370,
                   5560,
                   5800,
                   6030,
                   6240};
  return nums[x];
}

struct Coord {
  double angle;
  double range;
  double x;
  double y;
  double v;
  double a;
};


int main(){
  int numPoints = 6;
  Coord points[6] = {
    {0.75,5120},
    {0.72,5370},
    {0.70,5560},
    {0.68,5800},
    {0.67,6030},
    {0.66,6240},
    };

    for(int i=0; i<numPoints; i++){
      points[i].x = points[i].range * cos(points[i].angle);
      points[i].y = points[i].range * sin(points[i].angle);
      cout << i << " x " << points[i].x << endl;
      cout << i << " y " << points[i].y << endl;
    }
    cout << endl;

    for(int i=1; i<=numPoints; i++){
      points[i].v = ((sqrt(pow(points[i].x - points[i-1].x,2) + pow(points[i].y - points[i-1].y,2))) / 2);
      points[i].a = (points[i].v - points[i-1].v) / 2;
      cout << i << " Velocity: " << points[i].v << endl;
      cout << i << " Acceleration: " << points[i].a << endl;
      cout << endl;
    }
}




//v = dx/dt
//a = dv/dt
//v = D / T,
