#ifndef MATERIALH
#define MATERIALH

#include "hitable.h"


class material: public hitable
{
	 public:
		  virtual bool scatter(const ray& r, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;



};

inline vec3 random_in_unit_sphere()
{
	 vec3 p;
	 do
	 {
		  p = float(2.0)*vec3(drand48(),drand48(),drand48())-vec3(1.0,1.0,1.0);
	 }	
	 while (p.squared_length() >= float(1.0));
	 return p;
}

inline vec3 reflect(const vec3& v, const vec3& n)
{
	 return v - float(2.0)*dot(v,n)*n;
}

#endif
