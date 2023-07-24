#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <fstream>
#include <vector> 
#include <sstream>


using namespace std;
//Student class used for creating an object of students
class Student{
    private:
    string firstName;//students 1st name
    string middleName;//students middle name which is optional name
    string lastName;//students last name or sirname
    unsigned long int index;//stores students index
   
    public: 
    //this function recieves the name of the user and assigns to the private members of the class  
    string setNames(){
        
        string name1;
        string name2;
        string name3;
    cout<<"First Name : \n";
    cin>>name1;
    cout<<"Middle Name : \n";
    cin>>name2;
    cout<<"Last Name : \n";
    cin>>name3;
    firstName = name1;
    middleName = name2;
    lastName = name3;
    return firstName+','+middleName+','+lastName+',';

    }
    //this function recieves the students index number input and assigns to the private member indexNum  
    int indexnumber(){
      unsigned long int indexNum;
      cout<<"Index Number : \n";
    cin>>indexNum;
    int index = indexNum;
    return index;
    }
    //this pure virtual function is used in derived classes for retrieving data of students when needed for display
    virtual void retrievedata()=0;
    
};
//school class used in creating an object for schools
class Schools{
       private:
       string schoolName;//holds the schools name
       int schoolCode;//holds the schools code
       string selectedCourses;//holds the selected courses
       public:
      virtual string schoolsDisplay()=0;//a pure virtualfunction used in derived classes for displaying schools according to category
       
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
void core_courses()
 {
        cout << "Enter scores for your 4 core courses" << endl;
        
        cout << "Enter your score for English: "<<endl;
        cin >> English;
        res[0] = English;
        Results english("English", English);
        cout << "Enter your score for Math: "<<endl;
        cin >> Math;
        res[1] = Math;
        Results math("Math", Math);
        cout << "Enter your score for Science: "<<endl;
        cin >> Science;
        res[2] = Science;
        Results science("Science", Science);
        cout << "Enter your score for Social: "<<endl;
        cin >> Social;
        res[3] = Social; 
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
          break;
        case 2:
          cout << "Enter your score for Home Economics: " << endl;
          cin >> HomeEcons;
          res[5] = HomeEcons;
          break;
        case 3:
          cout << "Enter your score for Local Language: " << endl;
          cin >> Local;
          res[6] = Local;
          break;
        case 4:
          cout << "Enter your score for Pretech: " << endl;
          cin >> Pretech;
          res[7] = Pretech;
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

int calc()
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

    return grade;
}
int rawscore(){
   int sum=0; 
   for (int i= 0;i < 6; i++)
    {
      sum += res[i];
    }
   return sum;
 }

      // a derived class for creating an instance of malestudents, inherits from Students class and School class   
class malestudents : public Student, public Schools{
       private:
       string studentsName;
        string schoolName;
       string schoolA;
       string schoolB;
       string schoolC;
       string schoolD;
       int schoolCode;
       string readCourse;

      public:

      void retrievedata(){
         fstream studentsdatain;
  studentsdatain.open("Malestudentsdatabase.csv", ios::in);
  unsigned long int indexnumber, data;
  int count = 0;
  cout<<"Enter students Index Number\n";
  cin>>indexnumber;

  vector<string> row;
  string line, word, temp;
   while (studentsdatain >> temp) {
  studentsdatain >> temp;
    row.clear();
    getline(studentsdatain,line);
    stringstream s(temp);
    while(getline(s,word, ',')){
      row.push_back(word);
    }
    data = stoul(row[3]);
    int grade = stoi(row[4]);
    if( data == indexnumber){
    count = 1;
    if ( row[1] == "none" ){
      studentsName = row[0]+' '+row[2];
    }
      else{
         studentsName = row[0]+' '+row[1]+' '+row[2];
      }
    if(grade>=6 || grade<=9){
      if(row[9] == "none"&&row[10]== "none"){
        schoolName = row[6]+' '+row[7]+' '+row[8];
      }
      else if(row[10] =="none"){
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9];
      }
      else{
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9]+' '+row[10];
      }
      readCourse = row[11]+' '+row[12];
    }
    else if(grade>=10 || grade<=13){
      if(row[9] == "none"&&row[10]== "none"){
        schoolName = row[6]+' '+row[7]+' '+row[8];
      }
      else if(row[10] =="none"){
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9];
      }
      else{
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9]+' '+row[10];
      }
      readCourse = row[11]+' '+row[12];
    }
    else if(grade>=14 || grade<=18){
      if(row[16] == "none"&&row[17]== "none"){
        schoolName = row[13]+' '+row[14]+' '+row[15];
      }
      else if(row[17] =="none"){
        schoolName = row[13]+' '+row[14]+' '+row[15]+' '+row[16];
      }
      else{
        schoolName = row[13]+' '+row[14]+' '+row[15]+' '+row[16]+' '+row[17];
      }
      readCourse = row[18]+' '+row[19];
    }
    else {
      if(row[9] == "none"&&row[10]== "none"){
        schoolName = row[20]+' '+row[7]+' '+row[8];
      }
      else if(row[10] =="none"){
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9];
      }
      else{
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9]+' '+row[10];
      }
      readCourse = row[11]+' '+row[12];
    }
      }
      cout<<"Name : "<<studentsName<<endl
      <<"Index Number : "<<data<<endl
      <<"Grade : "<<row[4]<<endl
      <<"Rawscore : "<<row[5]<<endl
      <<schoolName<<endl;

   }
    if (count  == 0)
    cout<<"Not found\n";
  
  studentsdatain.close();
  
    }
   string schoolsDisplay(){
      cout<<"Select Schools For Placement By Typing The School Code\n";
      for(int i=0;i<4;i++){
   fstream schools;
   fstream schoolchoice;
   string line, word, temp;
   int count = 0;
   vector<string> school;
   switch(i){
     case 0 : schools.open("CategoryBgirls.csv",ios::in );
     while (getline(schools, line))
   {
      school.push_back(line);
      
   }
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
schoolchoice.open("CategoryBgirls.csv",ios::in);
cout<<"School Code\n";
          cin>>schoolCode;
while (schoolchoice >> temp) {
    school.clear();
    getline(schoolchoice,line);
    stringstream s(temp);
    while(getline(s,word, ',')){
      school.push_back(word);
    }
   
if (schoolCode == stoi(school[0])){
      count = 1;
      schoolA = ','+school[1]+','+school[2]+','+school[3]+','+school[4]+','+school[5];
      
    }
  } 
   schools.close();
 
break;
    case 1 : schools.open("CategoryBgirls.csv",ios::in);
       
   while (getline(schools, line))
   {
      school.push_back(line);
      
   }
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
schoolchoice.open("CategoryBgirls.csv",ios::in);
cout<<"School Code\n";
          cin>>schoolCode;
while (schoolchoice >> temp) {
    school.clear();
    getline(schoolchoice,line);
    stringstream s(temp);
    while(getline(s,word, ',')){
      school.push_back(word);
    }
if (schoolCode == stoi(school[0])){
      count = 1;
      schoolB = ','+school[1]+','+school[2]+','+school[3]+','+school[4]+','+school[5];
      
    }
  } 
  schools.close();
 
break;
    case 2: schools.open("CategoryBgirls.csv", ios::in);
  
   while (getline(schools, line))
   {
      school.push_back(line);
      
   }
   
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
schoolchoice.open("CategoryBgirls.csv",ios::in);
cout<<"School Code\n";
          cin>>schoolCode;
while (schoolchoice >> temp) {
    school.clear();
    getline(schoolchoice,line);
    stringstream s(temp);
    while(getline(s,word, ',')){
      school.push_back(word);
if (schoolCode == stoi(school[0])){
      count = 1;
      schoolC = ','+school[1]+','+school[2]+','+school[3]+','+school[4]+','+school[5];
      
    }
    }
  } 
  schools.close();

break;
    case 3: schools.open("CategoryBgirls.csv",ios::in);
   while (getline(schools, line))
   {
      school.push_back(line);
      
   }
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
schoolchoice.open("CategoryBgirls.csv",ios::in);
cout<<"School Code\n";
          cin>>schoolCode;
while (schoolchoice >> temp) {
    school.clear();
    getline(schoolchoice,line);
    stringstream s(temp);
    while(getline(s,word, ',')){
      school.push_back(word);
    }
if (schoolCode == stoi(school[0])){
      count = 1;
      schoolD = ','+school[1]+','+school[2]+','+school[3]+','+school[4]+','+school[5];
      
    }
  } 
  schools.close();

break;
}
      }
      return schoolA+schoolB+schoolC+schoolD;
      
       }
  
    
 };
    // a derived class for creating an instance of malestudents, inherits from Students class and School class
class femalestudents : public Student, public Schools{
        private:
        string studentsName; 
       string schoolName;
       string schoolA;
       string schoolB;
       string schoolC;
       string schoolD; 
       int schoolCode;
       string readCourse;

      public:

      void retrievedata(){
      ifstream studentsdatain;
  studentsdatain.open("Femalestudentsdatabase.csv", ios::in);
  unsigned long int indexnumber, data;
  int count = 0;
  cout<<"Enter students Index Number\n";
  cin>>indexnumber;

  vector<string> row;
  string line, word, temp;
   while (studentsdatain >> temp) {
    row.clear();
    getline(studentsdatain,line);
    stringstream s(temp);
    while(getline(s,word, ',')){
      row.push_back(word);
    }
    data = stoul(row[3]);
   int grade = stoi(row[4]);
    if( data == indexnumber){
    count = 1;
    if ( row[1] == "none" ){
      studentsName = row[0]+' '+row[2];
    }
      else{
         studentsName = row[0]+' '+row[1]+' '+row[2];
      }
    if(grade>=6 || grade<=9){
      if(row[9] == "none"&&row[10]== "none"){
        schoolName = row[6]+' '+row[7]+' '+row[8];
      }
      else if(row[10] =="none"){
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9];
      }
      else{
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9]+' '+row[10];
      }
      readCourse = row[11]+' '+row[12];
    }
    else if(grade>=10 || grade<=13){
      if(row[9] == "none"&&row[10]== "none"){
        schoolName = row[6]+' '+row[7]+' '+row[8];
      }
      else if(row[10] =="none"){
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9];
      }
      else{
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9]+' '+row[10];
      }
      readCourse = row[11]+' '+row[12];
    }
    else if(grade>=14 || grade<=18){
      if(row[16] == "none"&&row[17]== "none"){
        schoolName = row[13]+' '+row[14]+' '+row[15];
      }
      else if(row[17] =="none"){
        schoolName = row[13]+' '+row[14]+' '+row[15]+' '+row[16];
      }
      else{
        schoolName = row[13]+' '+row[14]+' '+row[15]+' '+row[16]+' '+row[17];
      }
      readCourse = row[18]+' '+row[19];
    }
    else {
      if(row[9] == "none"&&row[10]== "none"){
        schoolName = row[20]+' '+row[7]+' '+row[8];
      }
      else if(row[10] =="none"){
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9];
      }
      else{
        schoolName = row[6]+' '+row[7]+' '+row[8]+' '+row[9]+' '+row[10];
      }
      readCourse = row[11]+' '+row[12];
    }
      }
      cout<<"Name : "<<studentsName<<endl
      <<"Index Number : "<<data<<endl
      <<"Grade : "<<row[4]<<endl
      <<"Rawscore : "<<row[5]<<endl
      <<schoolName<<endl;
   }
     if(count == 0){
    cout<<"Not found\n";
    }
      }
      
       string schoolsDisplay(){
      cout<<"Select Schools For Placement By Typing The School Code\n";
      for(int i=0;i<4;i++){
   fstream schools;
   fstream schoolchoice;
   string line,word,temp;
   int count = 0;
   vector<string> school;
   switch(i){
     case 0 : schools.open("CategoryBgirls.csv",ios::in );
   
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
schoolchoice.open("CategoryBgirls.csv",ios::in);
 cout<<"School Code\n";
          cin>>schoolCode;
while (schoolchoice >> temp) {
    school.clear();
    getline(schoolchoice,line,'\n');
    stringstream s(temp);
    while(getline(s,word, ',')){
      school.push_back(word);
    }
   
if (schoolCode == stoi(school[0])){
      count = 1;
      schoolA = ','+school[1]+','+school[2]+','+school[3]+','+school[4]+','+school[5];
      
    }
  } 
    schoolchoice.close();
break;
    case 1 : schools.open("CategoryBgirls.csv",ios::in);
       
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
schoolchoice.open("CategoryBgirls.csv",ios::in);
 cout<<"School Code\n";
          cin>>schoolCode;
while (schoolchoice >> temp) {
    school.clear();
    getline(schoolchoice,line,'\n');
    stringstream s(temp);
    while(getline(s,word, ',')){
      school.push_back(word);
    }
   
if (schoolCode == stoi(school[0])){
      count = 1;
      schoolB = ','+school[1]+','+school[2]+','+school[3]+','+school[4]+','+school[5];
      
    }
  } 
    schoolchoice.close();
break;
    case 2: schools.open("CategoryBgirls.csv", ios::in);
  
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
schoolchoice.open("CategoryBgirls.csv",ios::in);
 cout<<"School Code\n";
          cin>>schoolCode;
while (schoolchoice >> temp) {
    school.clear();
    getline(schoolchoice,line,'\n');
    stringstream s(temp);
    while(getline(s,word, ',')){
      school.push_back(word);
    }
   
if (schoolCode == stoi(school[0])){
      count = 1;
      schoolC = ','+school[1]+','+school[2]+','+school[3]+','+school[4]+','+school[5];
      
    }
  } 
    schoolchoice.close();
break;
    case 3: schools.open("CategoryBgirls.csv",ios::in);
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
schoolchoice.open("CategoryBgirls.csv",ios::in);
cout<<"School Code\n";
          cin>>schoolCode;
while (schoolchoice >> temp) {
    school.clear();
    getline(schoolchoice,line,'\n');
    stringstream s(temp);
    while(getline(s,word, ',')){
      school.push_back(word);
    }
   
if (schoolCode == stoi(school[0])){
      count = 1;
      schoolD = ','+school[1]+','+school[2]+','+school[3]+','+school[4]+','+school[5];
      
    }
  } 
    schoolchoice.close();
break;
}
      }
      return schoolA+schoolB+schoolC+schoolD;
       }
     };
     
int main(){ 
     int n = 0;
    int mainMenuopt;
    string genderopt;
  fstream malestudentsdataout;
  fstream femalestudentsdataout;

cout<<" GROUP S PLACEMENT SYSYTEM\n";
 cout<< " press 1 - To Register As A New Student\n"
    <<" press 2 - To Check Results\n"
    <<" press 3 - To Exit Application\n";

    cin>>mainMenuopt;
    switch(mainMenuopt){

    case 1 :
    cout<<" Enter your details...\n"
    <<"Male or Female\n";
    cin>>genderopt;

    if(genderopt == "Male" || genderopt == "male"){
     malestudentsdataout.open("Malestudentsdatabase.csv", ios::out | ios::app);

   char choice;

   malestudents *ptrmalestudents[1000];
   do{
     int results[8];
      ptrmalestudents[n] = new malestudents;
      malestudentsdataout<<ptrmalestudents[n]->setNames();malestudentsdataout<<ptrmalestudents[n]->indexnumber();
      core_courses();
      optionalCourse();
      malestudentsdataout<<','<<calc();
      malestudentsdataout<<','<<rawscore();
      malestudentsdataout<<ptrmalestudents[n]->schoolsDisplay();
      malestudentsdataout<<endl;
      n++;
      cout<< "Enter another(y/n)?\n";
      cin>>choice;
   }while (choice == 'y');
    
    malestudentsdataout.close();
    }
    else if(genderopt == "Female" || genderopt == "female"){
      femalestudentsdataout.open("Femalestudentsdatabase.csv", ios::out | ios::app);
      
   char choice;
   femalestudents *ptrfemalestudents[1000];
   do{
     int results[8];
      ptrfemalestudents[n] = new femalestudents;
      femalestudentsdataout<<ptrfemalestudents[n]->setNames();femalestudentsdataout<<ptrfemalestudents[n]->indexnumber();
        core_courses();
      optionalCourse();
      femalestudentsdataout<<','<<calc();
      femalestudentsdataout<<','<<rawscore();
        femalestudentsdataout<<ptrfemalestudents[n]->schoolsDisplay();
      femalestudentsdataout<<endl;
      n++;cout<< "Enter another(y/n)?\n";
      cin>>choice;
   }while (choice == 'y');
    femalestudentsdataout.close();
    }
    break;
    case 2 : 
    malestudents resObjmale;
    femalestudents resObjfemale;
    cout<<" Enter your details...\n"
    <<"Male or Female\n";
    cin>>genderopt;
   if(genderopt == "Male" || genderopt == "male"){
    resObjmale.retrievedata();
   }
   else if(genderopt == "Female" || genderopt == "female"){
     resObjfemale.retrievedata();
   }

    break;
  
    }
    return 0;
}
