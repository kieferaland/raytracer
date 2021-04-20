#include <fstream>
#include <map>
#include <string>
#include <iostream>

using namespace std;

struct sphere_info
{	
	 int num;
	 int properties[14];
};

struct light_info
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

	 // dictionaries to store environment and object information
	 map<int,string> file_lines;
	 map<string,int> params;
	 map<int,struct sphere_info> spheres;
	 map<int,struct light_info> lights;

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
		  
		  size_t pos = 0;
		  string delimeter = " ";
		  string token;

		  while((pos = line.second(find(delimeter)) != string::npos))
		  {
				token = line.second.substr(0,pos);
				if (token.compare("NEAR"))
				{

				}
		  }


		  return 0;

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
