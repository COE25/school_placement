#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
void schoolsDisplay()
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
}

int main()
{
   schoolsDisplay();
   return 0;
}