#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student
{
   private:
   string name;
   unsigned long index;
   public:
   Student(string n, unsigned long i)
   {
      name = n;
      index = i;
   }
   string getName()
   {
      return name;
   }
   unsigned long getIndex()
   {
      return index;
   }

};

int main()
{
   cout << "Welcome to our School Placement System!" << endl;
   cout << "Please enter your name: ";
   string name;
   cin >> name;
   cout << "Please enter your index number: ";
   unsigned long index;
   cin >> index;
   Student student(name, index);
   fstream file;
   string directory = "/Users/kagya/martinkagya/student.csv";
   file.open(directory, ios::out | ios::app);
   if (file.is_open())
   {
      file << student.getName() << "," << student.getIndex() << endl;
      file.close();
   }
   else
   {
      cout << "Error opening file" << endl;
   }
}
//This a sketch code for student registration
//more functions will be added later