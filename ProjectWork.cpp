#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <fstream>
#include <vector> 
#include <sstream>


using namespace std;
class Student{
    private:
    string firstName;
    string middleName;
    string lastName;
    unsigned long int index;
    int tempresults[8];
   
    public:
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
    int indexnumber(){
      unsigned long int indexNum;
      cout<<"Index Number : \n";
    cin>>indexNum;
    int index = indexNum;
    return index;
    }

    virtual void retrievedata()=0;
    
};

class Schools{
       private:
       string schoolName;
       int schoolCode;
       string selectedCourses;
       public:
       virtual string schools()=0;
       
     };

    
     class malestudents : public Student, public Schools{
       private:
       string schoolName;
       int schoolCode;
       string readCourses;

      public:

      void retrievedata(){
      ifstream studentsdatain;
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
    if( data == indexnumber){
    count++;
      cout<<"Great job";
      break;
    }
   }
    if (count  == 0)
    cout<<"Not found\n";
  
  studentsdatain.close();
  
    }
    string schools(){
         cout<<"Select Schools For Placement By Typing The School Code\n";
          cin>>schoolCode;
       fstream openschool;
       int count = 0; 
       openschool.open("CategoryBgirls.csv", ios::in);
       vector<string> row;
  string line, word, temp;
   while (openschool >> temp) {
    row.clear();
    getline(openschool,line);
    stringstream s(temp);
    while(getline(s,word, ',')){
      row.push_back(word);
    }
    if (schoolCode == stoi(row[0])){
      count = 1;
      schoolName = ','+row[1]+','+row[2]+','+row[3]+','+row[4];
      
    }
       }
       return schoolName;
       }
      
    };

     class femalestudents : public Student, public Schools{
        private:
       string schoolName;
       int schoolCode;
       string readCourses;

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
    if( data == indexnumber){
    count = 1;
      cout<<"Great job";
      break;
    }
   }
     if(count == 0){
    cout<<"Not found\n";
    }
      }
      string schools(){
         cout<<"Select Schools For Placement By Typing The School Code\n";
          cin>>schoolCode;
       fstream openschool;
       int count = 0; 
       openschool.open("CategoryBgirls.csv", ios::in);
       vector<string> row;
  string line, word, temp;
   while (openschool >> temp) {
    row.clear();
    getline(openschool,line);
    stringstream s(temp);
    while(getline(s,word, ',')){
      row.push_back(word);
    }
    if (schoolCode == stoi(row[0])){
      count = 1;
      schoolName = ','+row[1]+','+row[2]+','+row[3]+','+row[4];
      
    }
       }
       return schoolName;
       }
     };

int main(){ 
     int n = 0;
    int mainMenuopt;
    string genderopt;
  fstream malestudentsdataout;
  fstream femalestudentsdataout;

cout<<" GROUP S SCHOOL PLACEMENT SYSYTEM\n";
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
      cout<<"Enter Students Results\n";
      for(int i = 0; i < 8; i++){
        switch(i){
          case 0:cout<<"Mathematics : \n";
        cin>>results[i];
        break;
        case 1:cout<<"Integrated Science : \n";
        cin>>results[i];
        break;
        case 2:cout<<"English Language : \n";
        cin>>results[i];
        break;
        case 3:cout<<"Social Studies : \n";
        cin>>results[i];
        break;
        case 4:cout<<"Religious And Moral Education :\n";
        cin>>results[i];
        break;
        case 5:cout<<"Information And Communication Technology : \n";
        cin>>results[i];
        break;
        case 6:cout<<"Asante Twi : \n";
        cin>>results[i];
        break;
        case 7:cout<<"Basic Design And Technology  : \n";
        cin>>results[i];
        break;
        }
        malestudentsdataout<<','<<results[i];
      }
      malestudentsdataout<<ptrmalestudents[n]->schools();
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
      cout<<"Enter Students Results\n";
      for(int i = 0; i < 8; i++){
        switch(i){
          case 0:cout<<"Mathematics : \n";
        cin>>results[i];
        
        break;
        case 1:cout<<"Integrated Science : \n";
        cin>>results[i];
        break;
        case 2:cout<<"English Language : \n";
        cin>>results[i];
        break;
        case 3:cout<<"Social Studies : \n";
        cin>>results[i];
        break;
        case 4:cout<<"Religious And Moral Education :\n";
        cin>>results[i];
        break;
        case 5:cout<<"Information And Communication Technology : \n";
        cin>>results[i];
        break;
        case 6:cout<<"Asante Twi : \n";
        cin>>results[i];
        break;
        case 7:cout<<"Prevocational Skills : \n";
        cin>>results[i];
        break;
        }
        int *res = &results[i];
        int sum = 0;
        sum += results[i];
        femalestudentsdataout<<','<<results[i];
      }
        ;femalestudentsdataout<<ptrfemalestudents[n]->schools();
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
