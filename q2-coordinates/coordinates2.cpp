#include <iostream>
#include <cmath>
using namespace std;

struct Coord {
  double angle;
  double range;
  double x; //x coord
  double y; //y coord
  double vi;
  double vj;
  double ai;
  double aj;
};

//velcoity = derivative of (R*cos(theta)) i + derivative of (R*sin(theta)) j

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
      points[i].vi = points[i].range * -1 * sin(points[i].angle);
      points[i].vj = points[i].range * (cos(points[i].angle));
      cout << "Velocity Vector = " << points[i].vi << "i + " << points[i].vj << "j" << endl;
      points[i].ai = points[i].range * -1 * cos(points[i].angle);
      points[i].aj = points[i].range * (sin(points[i].angle));
      cout << "Acceleration Vector = " << points[i].ai << "i - " << points[i].aj << "j" << endl <<endl<<endl;
    }
    cout << endl << endl;


}

// find the vector derivative
//v = dx/dt
//a = dv/dt
//v = D / T,
