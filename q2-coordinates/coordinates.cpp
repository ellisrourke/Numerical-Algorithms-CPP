#include <iostream>
#include <cmath>
using namespace std;

struct Coord {
  double angle;
  double range;
  double x; //x coord
  double y; //y coord
  double v; //velocity
  double a; //acceleration
};


int main(){
  int numPoints = 6;
  Coord points[numPoints] = {

    {0.75,5120},
    {0.72,5370},
    {0.70,5560},
    {0.68,5800},
    {0.67,6030},
    {0.66,6240},
    //{Radian direction, distance}
    };

    for(int i=0; i<numPoints; i++){
      points[i].x = points[i].range * cos(points[i].angle);
      points[i].y = points[i].range * sin(points[i].angle);
      cout << i << " x " << points[i].x << endl;
      cout << i << " y " << points[i].y << endl;
    }
    cout << endl;

    for(int i=1; i<=numPoints; i++){
      points[i].v = ((sqrt(pow(points[i].x - points[i-1].x,2) + pow(points[i].y - points[i-1].y,2))) / 2); //calculate the velocity from i-1 to i
      points[i].a = (points[i].v - points[i-1].v) / 2; //calculate the acceleration from i-1 to i
      cout << i << " Velocity: " << points[i].v << endl;
      cout << i << " Acceleration: " << points[i].a << endl;
      cout << endl;
    }
}

// find the vector derivative
//v = dx/dt
//a = dv/dt
//v = D / T,
