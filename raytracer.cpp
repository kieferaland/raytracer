#include <iostream>
#include "glm/glm.hpp"
#include "ray.h"

using namespace std;
using namespace glm;

vec3 color(const ray& r)
{
	 vec3 unit_direction = normalize(r.direction());
	 float t = 0.5*(unit_direction.y + 1.0);
	 return float(1.0-t)*vec3(1.0,1.0,1.0)+t*vec3(0.5,0.7,1.0);
}

int main ()
{

	 int W = 200;
	 int H = 100;

	 cout<<"P3\n"<<W<<" "<<H<<"\n255"<<endl;
	 
	 vec3 lower_left_corner(-2.0, -1.0, -1.0);
	 vec3 horizontal(4.0,0.0,0.0);
	 vec3 vertical(0.0, 2.0, 0.0);
	 vec3 origin(0.0,0.0,0.0);

	 for (int h = H-1; h>=0; h--){
		  for (int w = 0; w < W; w++)
		  {
				float u = float(w)/float(W);
				float v = float(h)/float(H);
				
				ray r(origin, lower_left_corner + u*horizontal + v*vertical);
				vec3 col = color(r);
				
				int ir = int(255.99*col[0]);
				int ig = int(255.99*col[1]);
				int ib = int(255.99*col[2]);
				
				cout<<ir<<" "<<ig<<" "<<ib<<endl;
		  }
	 }
}
