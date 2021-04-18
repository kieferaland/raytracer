#include <iostream>
#include "sphere.h"
#include "hitable_list.h"
#include "float.h"
#include "camera.h"
#include <fstream>
//include "glm/glm.hpp"

using namespace std;
//using namespace glm;

vec3 random_in_unit_sphere()
{
	 vec3 p;
	 do
	 {
		  p = float(2.0)*vec3(drand48(),drand48(),drand48())-vec3(1.0,1.0,1.0);
	 }
	 while (p.squared_length() >= float(1.0));
	 return p;
}

vec3 color(const ray& r, hitable *world)
{	
	 hit_record rec;
	 if(world->hit(r,0.0,MAXFLOAT, rec))
	 {
		  vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		  return float(0.5)*color(ray(rec.p, target-rec.p),world);
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
	 int S = 100;

	 ofs<<"P3\n"<<W<<" "<<H<<"\n255"<<endl;
	 
	 hitable *list[2];
	 list[0] = new sphere(vec3(0,0,-1), float(0.5));
	 list[1] = new sphere(vec3(0, -100.5, -1), float(100));

	 hitable *world = new hitable_list(list, 2);
	 camera cam;
	 for (int h = H-1; h>=0; h--){
		  for (int w = 0; w < W; w++)
		  {
				vec3 col(0,0,0);
				for (int s = 0; s < S; s++)
				{
					 float u = float(w + drand48())/float(W);
					 float v = float(h + drand48())/float(H);
					 ray r = cam.get_ray(u,v);
					 vec3 p = r.parameterize(float(2.0));
					 col += color(r,world);
				}
				col /= float(S);
				col = vec3(sqrt(col[0]),sqrt(col[1]),sqrt(col[2]));
				int ir = int(255.99*col[0]);
				int ig = int(255.99*col[1]);
				int ib = int(255.99*col[2]);
				
				ofs<<ir<<" "<<ig<<" "<<ib<<endl;
		  }
	 }
	 ofs.close();
}
