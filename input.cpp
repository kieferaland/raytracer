#include <fstream>
#include <map>
#include <string>
#include <iostream>

using namespace std;
// sphere parameters stored in these class objects
// i initialize 14 because i cant figure out how to create new ones... i'm new to cpp
class sphere_info
{	
	 public:
		  int num;
		  string name;
		  float position[3];
		  float scaling[3];
		  float color[3];
		  float illumination[3];
		  int specular;
		  int params[14];
}si[14];

class light_info
{
	 int num;
	 int properties[6];
};

int main ()
{
	 // define file for reading parameters from
	 ifstream in_file;
	 string file_line;

	 // line and object identifiers
	 int line_num = 0;
	 int sphere_num = 0;
	 int light_num = 0;

	 // dictionary to store lines read from file 
	 map<int,string> file_lines;
	 
	 // once we have the lines in a dictionary we can parse them out into maps and arrays for later lookup
	 // params map is for viewport parameters
	 map<string,int> params;
	 
	 // resolution width and height respectively in this array
	 int RES[2];
	 
	 // two maps to store our objects parameters
	 map<int,struct sphere_info> spheres;
	 map<int,struct light_info> lights;

	 int BACK[3];
	 int AMBIENT[3];
	 
	 string OUTPUT;

	 // open file and store text lines in file_lines dictionary
	 in_file.open("testAmbient.txt");
	 while (getline(in_file, file_line))
	 {
		  line_num++;
		  file_lines[line_num] = file_line;
	 }
	 // print lines from file_lines dictionary as a test
	 for (auto line : file_lines)
	 {
		  cout<<line.first<<" : "<<line.second<<endl;
	 }
	 // print number of items in the file_lines dictionary 
	 // which should match the number of lines in file
	 cout<<"there are "<<line_num<<" lines in this input file."<<endl;
	 // parse lines and store parameters in respective dictionaries for the line header
	 for (auto line: file_lines)
	 {		
		  cout<<line.first<<endl;
		  cout<<line.second<<endl;
		  // parse the lines delim by spaces
		  size_t last = 0;
		  size_t next = 0;
		  string delimeter = " ";
		  string token;
		  
		  // for each line
		  while((next = line.second.find(delimeter,last)) != string::npos)
		  {
				// current token 
				token = line.second.substr(last,next-last);
				//cout<<token<<endl;
				
				// if the first token of a line is not sphere or light
				if (token.compare("SPHERE")!=0 && token.compare("LIGHT")!=0)
				{	
					 if (token.compare("NEAR")==0)
					 {
					 }
					 cout<<"found an environment param token"<<endl;
					 params[token]; 
				}
				// first token of line is sphere	
				else if (token.compare("SPHERE")==0)
				{
					 spheres[sphere_num+1] = si[sphere_num];
					 	  
					 si[sphere_num]
					 sphere_num++;
	 			}
				// first token of line is light
				else if (token.compare("LIGHT")==0)
				{

				}
				// increment the last pointer to after the current delimeter
				last = next+delimeter.length();
		  }
		  // dont forget the last token
		  // this is wrong as it stands
		  params[token] = stoi(line.second.substr(last));
		  
		  cout<<"dictionary entry for "<<token<<" is "<<params[token]<<endl;

		  

		  //return 0;
		  /* 
		  if (*line.first == "SPHERE")
		  {
				// seperate string into tokens delimeted by spaces
				sphere_num++;
				size_t pos = 0;
				string delimeter = " ";
				string token;
				while ((pos = s.find(delimeter)) != string::npos)
				{
					 
				}
		  }
		  */
	 }
	 in_file.close();
}
