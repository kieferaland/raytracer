#include <iostream>
#include "sphere.h"
#include "hitable_list.h"
#include "float.h"
#include <fstream>
//include "glm/glm.hpp"

using namespace std;
//using namespace glm;

vec3 color(const ray& r, hitable *world)
{	
	 hit_record rec;
	 if(world->hit(r,0.0,MAXFLOAT, rec))
	 {
		  return float(0.5)*vec3(rec.normal.i+float(1.0), rec.normal.j+float(1.0), rec.normal.k+float(1.0));
	 }
	 else
	 {
		  vec3 unit_direction = normalize(r.direction());
		  float t = float(0.5)*unit_direction.j+float(1.0);
		  return((float(1.0)-t)*vec3(1.0,1.0,1.0)+t*(vec3(0.5,0.7,1.0)));
	 }
}

int main ()
{
	 ofstream ofs;
	 ofs.open("scene1.ppm", ios::trunc);
	 
	 /*
	 vec3 v = vec3(1.3,1.3,1.3);
	 float vdv = dot(v,v);
	 cout<<"vdotv = "<<vdv<<endl;
	 */

	 int W = 200;
	 int H = 100;

	 ofs<<"P3\n"<<W<<" "<<H<<"\n255"<<endl;
	 
	 vec3 lower_left_corner(-2.0, -1.0, -1.0);
	 vec3 horizontal(4.0,0.0,0.0);
	 vec3 vertical(0.0, 2.0, 0.0);
	 vec3 origin(0.0,0.0,0.0);

	 hitable *list[2];
	 list[0] = new sphere(vec3(0,0,-1), float(0.5));
	 list[1] = new sphere(vec3(0, -100.5, -1), float(100));

	 hitable *world = new hitable_list(list, 2);

	 for (int h = H-1; h>=0; h--){
		  for (int w = 0; w < W; w++)
		  {
				float u = float(w)/float(W);
				float v = float(h)/float(H);
				
				ray r(origin, lower_left_corner + u*horizontal + v*vertical);

				vec3 p = r.parameterize(float(2.0));
				vec3 col = color(r,world);
				
				int ir = int(255.99*col[0]);
				int ig = int(255.99*col[1]);
				int ib = int(255.99*col[2]);
				
				ofs<<ir<<" "<<ig<<" "<<ib<<endl;
		  }
	 }
	 ofs.close();
}
