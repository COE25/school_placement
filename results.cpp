#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
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

int English, Math, Science, Social;
int French, HomeEcons, Local, Pretech;
int res[8];
unordered_map<string, int> subjects;
void core_courses()
 {
        cout << "Enter scores for your 4 core courses" << endl;
        
        cout << "Enter your score for English: "<<endl;
        cin >> English;
        res[0] = English;
        subjects["English"] = English;
        Results english("English", English);
        cout << "Enter your score for Math: "<<endl;
        cin >> Math;
        res[1] = Math;
        subjects["Math"] = Math;
        Results math("Math", Math);
        cout << "Enter your score for Science: "<<endl;
        cin >> Science;
        res[2] = Science;
        subjects["Science"] = Science;
        Results science("Science", Science);
        cout << "Enter your score for Social: "<<endl;
        cin >> Social;
        res[3] = Social; 
        subjects["Social"] = Social;
        Results social("Social", Social);
 }

void optionalCourse()
 {
    cout << "You have to choose exactly 4 optional courses" << endl;
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
          res[4] = French;
          subjects["French"] = French;
          break;
        case 2:
          cout << "Enter your score for Home Economics: " << endl;
          cin >> HomeEcons;
          res[5] = HomeEcons;
          subjects["Home Economics"] = HomeEcons;
          break;
        case 3:
          cout << "Enter your score for Local Language: " << endl;
          cin >> Local;
          res[6] = Local;
          subjects["Local Language"] = Local;
          break;
        case 4:
          cout << "Enter your score for Pretech: " << endl;
          cin >> Pretech;
          res[7] = Pretech;
          subjects["Pretech"] = Pretech;
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
int compare (const void * a, const void * b)
{
    return (*(int*)b - *(int*)a);
}
int grade = 0;
int grading (int scores)
{
  if (scores <= 100)
  {
      if (scores >= 75)
      {
       grade += 1;
      }
      if (scores <= 39)
      {
       grade += 9;
      }
       switch (scores)
       {
           case 74:
           case 73:
           case 72:
           case 71:
           case 70:
               grade += 2;
               break;
           case 69:
           case 68:
           case 67:
           case 66:
           case 65:
               grade += 3;
               break;
           case 64:
           case 63:
           case 62:
           case 61:
           case 60:
               grade += 4;
               break;
           case 59:
           case 58:
           case 57:
           case 56:
           case 55:
               grade += 5;
               break;
           case 54:
           case 53:
           case 52:
           case 51:
           case 50:
               grade += 6;
               break;
           case 49:
           case 48:
           case 47:
           case 46:
           case 45:
               grade += 7;
               break;
           case 44:
           case 43:
           case 42:
           case 41:
           case 40:
               grade += 8;
               break;
       }
       return grade;
}
  else{
    cout<<"Enter the correct score: "<<endl;

  }
}

void calc()
{
    int i;
    grade = 0; // Reset grade before calculating the grades for optional courses

    // Sorting optional courses' scores in descending order
    qsort(&res[4], 4, sizeof(int), compare);

    // Calculate grades for all core courses
    for (i = 0; i < 4; i++)
    {
        grading(res[i]);
    }

    // Calculate grades for the two best optional courses
    for (i = 4; i < 6; i++)
    {
        grading(res[i]);
    }

    cout << "Total grade: " << grade << endl;
}

int main()
{
  
  core_courses();
  optionalCourse();
  calc();
  cout<<"Your results are as follows\n";
  for (auto it = subjects.begin(); it != subjects.end(); it++) {
    std::cout << it->first << " : " << it->second << std::endl;
  }
  return 0;
  }
