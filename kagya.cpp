#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
/*void schoolsDisplay()
{
   ifstream schools;
   schools.open("student.csv", ios::in);
   string line;
   vector<string> school;
   while (getline(schools, line))
   {
      school.push_back(line);
      
   }
   schools.close();
   
   cout << "\nCODE\tSCHOOLS\n"<<endl;
   for (int i = 0; i < school.size(); i++)
   {
         if (school[i].find(",") != -1)
         {
            for(int j = 0; j < school[i].length(); j++)
            {
               if(school[i][j] == ',')
               {
                  school[i][j] = ' ';
               }
            }
         cout << school[i] << endl;
   }
}
}*/
unordered_map<string, string> courseMap;

string courseSelection() {
string code;
do{
   cout << "Enter code: ";
   cin >> code;

  if (courseMap.find(code) != courseMap.end()) {
    return courseMap[code];
  } else {
      return "Invalid code";
  }

}while(courseMap.find(code) == courseMap.end());
}



int main()
{
   cout<<"Select course by typing the course code\n";
   courseMap["452"] = "General Arts";
   courseMap["432"] = "General Science";
   courseMap["111"] = "Business";
   courseMap["789"] = "Visual Arts";
   courseMap["182"] = "Home Economics";
   courseMap["879"] = "Pre-Technical Skills";
   for (auto it = courseMap.begin(); it != courseMap.end(); ++it)
   {
      cout << it->first << ":\t" << it->second << endl;
   }
   cout << courseSelection() << endl;
   //schoolsDisplay();
   return 0;
}