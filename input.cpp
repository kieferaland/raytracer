#include <fstream>
#include <map>
#include <string>
#include <iostream>

using namespace std;
// sphere parameters stored in these class objects
// i initialize 14 because i cant figure out how to name new objects without pre initializing... i'm new to cpp
class sphere_info
{	
	 public:
		  float position[3];
		  float scaling[3];
		  float colour[3];
		  float illumination[3];
		  int specular;
}si[14];

class light_info
{
	 public:
		  float position[3];
		  float intensity[3];
}li[9];

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
	 map<string,float> params;
	 
	 // resolution width and height respectively in this array
	 int RES[2];
	 
	 // two maps to store our objects parameters
	 map<int,struct sphere_info> spheres;
	 map<int,struct light_info> lights;

	 float BACK[3];
	 float AMBIENT[3];
	 
	 string OUTPUT;

	 // open file and store text lines in file_lines dictionary
	 in_file.open("testAmbient.txt");
	 while (getline(in_file, file_line))
	 {
		  line_num++;
		  file_lines[line_num] = file_line;
	 }
	 // print lines from file_lines dictionary as a test
	 cout<<"\nPrinting lines from file_lines dictionary:\n"<<endl;
	 for (auto line : file_lines)
	 {
		  cout<<line.first<<" : "<<line.second<<endl;
	 }
	 
	 // print number of items in the file_lines dictionary 
	 // which should match the number of lines in file
	 cout<<"there were "<<line_num<<" lines in this input file.\n"<<endl;
	 // parse lines and store parameters in respective dictionaries for the line header token
	 for (auto line: file_lines)
	 {		
		  //cout<<line.first<<endl;
		  //cout<<line.second<<endl;
		  
		  // parse the lines delimited by spaces
		  size_t last = 0;
		  size_t next = 0;
		  string delimiter = " ";
		  string token;
		  
		  // for each line
		  while((next = line.second.find(delimiter,last)) != string::npos)
		  {
				// get current token 
				token = line.second.substr(last, next-last);
				//cout<<token<<endl;
				// if the first token of a line is OUTPUT we are on the last line
				if (token.compare("OUTPUT")==0)
				{
					 cout<<"we didnt come this far to come this far"<<endl;
					 last = next+delimiter.length();
					 OUTPUT = line.second.substr(last);
					 cout<<"drumroll pls...\n OUTPUT -> "<<OUTPUT<<endl;
					 goto after_loop;
				}
				// if the first token of a line is not SPHERE or LIGHT
				else if (token.compare("SPHERE")!=0 && token.compare("LIGHT")!=0)
				{	
					 // if the token is not RES, BACK, or AMBIENT its going into the params map
					 if (token.compare("RES")==0)
					 {
						  for (int i =0; i<2; i++)
						  {
								last = next+delimiter.length();
								next = line.second.find(delimiter,last);
								token = line.second.substr(last, next-last);
								RES[i] = stoi(token);
						  }
						  goto end_of_loop;
					 }
					 else if (token.compare("BACK")==0)
					 {
						  for (int i=0; i<3; i++)
						  {
								last = next+delimiter.length();
								next = line.second.find(delimiter,last);
								token = line.second.substr(last, next-last);
								BACK[i] = stof(token);
						  }
						  goto end_of_loop;
					 }
					 else if (token.compare("AMBIENT")==0)
					 {
						  for (int i=0; i<3; i++)
						  {
								last = next+delimiter.length();
								next = line.second.find(delimiter,last);
								token = line.second.substr(last, next-last);
								AMBIENT[i] = stof(token);
						  }
						  goto end_of_loop;
					 }
					 else
					 {
					 cout<<"found an hello environment param token : "<<token<<endl;
					 params[token];
					 }
				}
				// first token of line is SPHERE	
				else if (token.compare("SPHERE")==0)
				{	
					 // skip the name we don't need it
					 last = next+delimiter.length();
					 next = line.second.find(delimiter,last);
					 for (int i=0; i<3; i++)
					 {
						  last = next+delimiter.length();
						  next = line.second.find(delimiter,last);
						  token = line.second.substr(last, next-last);
						  si[sphere_num].position[i] = stof(token);
					 }
					 for (int i=0; i<3; i++)
					 {
						  last = next+delimiter.length();
						  next = line.second.find(delimiter,last);
						  token = line.second.substr(last, next-last);
						  si[sphere_num].scaling[i] = stof(token);
					 }
					 for (int i=0; i<3; i++)
					 {
						  last = next+delimiter.length();
						  next = line.second.find(delimiter,last);
						  token = line.second.substr(last, next-last);
						  si[sphere_num].colour[i] = stof(token);
					 }
					 for (int i=0; i<3; i++)
					 {
						  last = next+delimiter.length();
						  next = line.second.find(delimiter,last);
						  token = line.second.substr(last, next-last);
						  si[sphere_num].illumination[i] = stof(token);
					 }
					 last = next+delimiter.length();
					 si[sphere_num].specular = stoi(line.second.substr(last));
					 spheres[sphere_num] = si[sphere_num];
					 sphere_num++;
					 goto end_of_loop;
	 			}
				// first token of line is LIGHT
				else if (token.compare("LIGHT")==0)
				{	
					 // skip the name
					 last = next+delimiter.length();
					 next = line.second.find(delimiter,last);
					 for (int i=0; i<3; i++)
					 {
						  last = next+delimiter.length();
						  next = line.second.find(delimiter,last);
						  token = line.second.substr(last, next-last);
						  li[light_num].position[i] = stof(token);
					 }
					 for (int i=0; i<3; i++)
					 {
						  last = next+delimiter.length();
						  next = line.second.find(delimiter,last);
						  token = line.second.substr(last, next-last);
						  li[light_num].intensity[i] = stof(token);
					 }
					 lights[light_num] = li[light_num];
					 light_num++;
					 goto end_of_loop;
				}
				// increment the last pointer to after the current delimeter
				last = next+delimiter.length();

		  }
		  // dont forget the last token
		  // this is wrong as it stands
		  cout<<"end of loop dict entry : token = "<<token<<endl;
		  params[token] = stoi(line.second.substr(last));
		  cout<<"dictionary entry for "<<token<<" is "<<params[token]<<endl;
end_of_loop:
	 }
after_loop:
	 in_file.close();

	 // lets see what we've got so far
	 for (auto param : params)
	 {
		  cout<<param.first<<" : "<<param.second<<endl;
	 }

	 cout<<"RES : ("<<RES[0]<<", "<<RES[1]<<")"<<endl;

}
