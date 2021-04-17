#include <iostream>

using namespace std;

int main ()
{
	 int W = 200;
	 int H = 100;

	 cout<<"P3\n"<<W<<" "<<H<<"\n255"<<endl;

	 for (int h = H-1; h>=0; h--){
		  for (int w = 0; w < W; w++)
		  {
				float r = float(w)/float(W);
				float g = float(h)/float(H);
				float b = 0.2;

				int ir = int(255.99*r);
				int ig = int(255.99*g);
				int ib = int(255.99*b);
				cout<<ir<<" "<<ig<<" "<<ib<<endl;
		  }
	 }
}
