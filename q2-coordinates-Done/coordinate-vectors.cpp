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
  double vm;
  double ai;
  double aj;
  double am;
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

    // get x y coordinates
    for(int i=0; i<numPoints; i++){
      points[i].x = points[i].range * cos(points[i].angle);
      points[i].y = points[i].range * sin(points[i].angle);
    }

    // calculate velocity and Acceleration vectors
    for(int i=1; i<numPoints-1; i++){
      points[i].vi = (points[i+1].x - points[i-1].x) / 4; // i component
      points[i].vj = (points[i+1].y - points[i-1].y) / 4; // j component
      points[i].vm = sqrt(pow(points[i].vi,2) + pow(points[i].vj,2)); // Magnitude

      points[i].ai = (points[i+1].x - 2*points[i].x + points[i-1].x) / 4; // i component
      points[i].aj = (points[i+1].y - 2*points[i].y + points[i-1].y) / 4; // j component
      points[i].am = sqrt(pow(points[i].ai,2) + pow(points[i].aj,2)); // Magnitude

      cout << "Time: " << (200 + (i * 2)) << " x: " << points[i].x << " y: " << points[i].y  << endl;
      cout << "Velocity Vector [ " << points[i].vi << "i, " << points[i].vj << "j ]" << " Velocity Magnitude: " << points[i].vm << endl;
      cout << "Acceleration Vector [ " << points[i].ai << "i, " << points[i].aj << "j ]" << " Acceleration Magnitude: " << points[i].am << endl << endl;
    }


    return 0;
}
