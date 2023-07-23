#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

class Results {
 public:
  Results(const string& course, int score) : course_(course), score_(score) {}

  const string& course() const { return course_; }
  int score() const { return score_; }

 private:
  std::string course_;
  int score_;
};
void core_courses()
 {
        cout << "Enter scores for your 4 core courses" << endl;
        int English, Math, Science, Social;
        cout << "Enter your score for English: "<<endl;
        cin >> English;
        Results english("English", English);
        cout << "Enter your score for Math: "<<endl;
        cin >> Math;
        Results math("Math", Math);
        cout << "Enter your score for Science: "<<endl;
        cin >> Science;
        Results science("Science", Science);
        cout << "Enter your score for Social: "<<endl;
        cin >> Social;
        Results social("Social", Social);
 }

 void optionalCourse()
 {
    cout << "You have to choose exactly 4 optional courses" << endl;
  int French, HomeEcons, Local, Pretech;
  int choiceCount = 0;
  int choice;
  cout << "1. French\n2. Home Economics\n3. Local Language\n4. Pretech" << endl;
  do {
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice < 1 || choice > 4) {
      cout << "Invalid choice. Please choose again." << endl;
    } else {
      switch (choice) {
        case 1:
          cout << "Enter your score for French: " << endl;
          cin >> French;
          break;
        case 2:
          cout << "Enter your score for Home Economics: " << endl;
          cin >> HomeEcons;
          break;
        case 3:
          cout << "Enter your score for Local Language: " << endl;
          cin >> Local;
          break;
        case 4:
          cout << "Enter your score for Pretech: " << endl;
          cin >> Pretech;
          break;
      }
      choiceCount++;
    }
  } while (choiceCount < 4);
    Results french("French", French);
    Results homeEcons("Home Economics", HomeEcons);
    Results local("Local Language", Local);
    Results pretech("Pretech", Pretech);
 }
 
int main()
{
   
   core_courses();
   optionalCourse();
       
        //cout << "Welcome to our School Placement System!" << endl;
   //cout << "Please enter your name: ";
   //string name;
   //cin >> name;
   //cout << "Please enter your index number: ";
   //unsigned long index;
   //cin >> index;
   //Student student(name, index);
   //fstream file;
   //string directory = "/Users/kagya/martinkagya/student.csv";
   //file.open(directory, ios::out | ios::app);
   //if (file.is_open())
   //{
   //   file << student.getName() << "," << student.getIndex() << endl;
   //   file.close();
   //}
   //else
   //{
   //   cout << "Error opening file" << endl;
   //}
}
//This a sketch code for student registration
//more functions will be added later