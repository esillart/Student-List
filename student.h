#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

//const int MAXSIZE = 21;					//const gloval variable for maximum size allowed for first and last name strings

class Student
{
  public:
    virtual double Average() = 0;			//pure virtual function, making Student an abstract class 
    virtual void Display(ostream &os) = 0;
    virtual string ReturnCourse() = 0;

  protected:
    Student(string ln, string fn, string crs);		//constructor with parameters 

   string firstName;					//strings for student info 
   string lastName;
   string course;

   int finalExam;					//all Students have final exam grades
	
  private:
    int numStudents;					//tracker variable for number of students in Student array

};

class English : public Student 
{
  public:
    English(string ln, string fn, string crs, int term, int mid, int fnl);
    double Average();
    void Display(ostream &os);
    string ReturnCourse();     

  private:
    int termPaper;
    int midterm;

};

class History : public Student 
{
  public:
    History(string ln, string fn, string crs, int attend, int proj, int mid, int fnl);
    double Average();
    void Display(ostream &os);
    string ReturnCourse();    

  private: 
    int attendance;
    int project;
    int midterm;

};

class Math : public Student 
{
  public: 
    Math(string ln, string fn, string crs, int qz1, int qz2, int qz3, int qz4, int qz5, int tst1, int tst2, int fnl);
    double Average();
    void Display(ostream &os);   
    string ReturnCourse();

  private:
    int quiz1, quiz2, quiz3, quiz4, quiz5;
    int test1, test2;

};
