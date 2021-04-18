#include <iostream>
#include "ray.h"
#include <fstream>
//include "glm/glm.hpp"

using namespace std;
//using namespace glm;

bool hit_sphere(const vec3& centre, float radius, const ray& r)
{
	 vec3 oc = r.origin()-centre;
	 float a = dot(r.direction(),r.direction());
	 return true;
}

vec3 color(const ray& r)
{
	 vec3 unit_direction = normalize(r.direction());
	 float t = 0.5*(unit_direction.j + 1.0);
	 return float(1.0-t)*vec3(1.0,1.0,1.0)+t*vec3(0.5,0.7,1.0);
}

int main ()
{
	 ofstream ofs;
	 ofs.open("scene.ppm", ios::trunc);

	 vec3 v = vec3(1.3,1.3,1.3);
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
				
				ofs<<ir<<" "<<ig<<" "<<ib<<endl;
		  }
	 }
	 ofs.close();
}
