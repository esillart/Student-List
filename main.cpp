#include "student.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{

  string inputFile;							//input and output stream objects
  string outputFile;

  int numStu;								//counter for # of students in array

  ifstream studentList;						//create istream object
  

  do 
  {
    cout << "Please enter the name of the input file." << endl << "Filename: \n";	//ask for names of input and output files.  
    cin >> inputFile;

    cout << "Please enter the name of the output file." << endl << "Filename: \n";
    cin >> outputFile;

    studentList.open(inputFile.c_str());

    if (!studentList)
    {
  	cout << "There was an error opening the file. Please enter file name again.\n";

    }
  } 
  while (!studentList);								//if there was an error, ask user to input again


  studentList >> numStu;					//read in an int from the file and store into variable

  Student** studentPointer = NULL;

  studentPointer = new Student*[numStu];				//dynamically allocated heterogenous list 

  for (int i = 0; i < numStu; i++)
{
  string* tempLastName = new string;				//dynamic strings made on the fly to temporarily store strings
  string* tempFirstName = new string;
  string* tempCourse = new string;


  getline(studentList, *tempLastName, ',');			//extract a string with white space until a comma is reached, store in temp last name string

  studentList.ignore(); 					//ignore space after the comma

  getline(studentList, *tempFirstName);				//extract string until newline is reached, store in temp first name string

  getline(studentList, *tempCourse, ' ');			//extract string until a space is reached, store in temp course string


  if (*tempCourse == "Math")
  {
    int* grades = NULL;

    grades = new int[8];					//dynamically allocate 8 integer grades to store upcoming grade in file

    studentList >> grades[0] >> grades[1] >> grades[2] >> grades[3] >> grades[4] >> grades[5] >> grades[6] >> grades[7];

    Math* temp = new Math(*tempLastName, *tempFirstName, *tempCourse, grades[0], grades[1], grades[2], grades[3], grades[4], grades[5], grades[6], grades [7]); 

    studentPointer[i] = temp;					//^^read in ints from file and store in array of ints, pass into Math object
							// then pass into array of Student pointers, then delete array of ints 
    delete [] grades;
    delete  tempLastName;				//deallocate strings and the list of int grades
    delete  tempFirstName;
    delete  tempCourse;

  }

  if (*tempCourse == "English")					//similar to math 
  {
    int* grades = NULL;

    grades = new int[3];

    studentList >> grades[0] >> grades[1] >> grades [2];

    English* temp = new English(*tempLastName, *tempFirstName, *tempCourse, grades[0], grades[1], grades[2]);

    studentPointer[i] = temp;

    delete [] grades; 
    delete  tempLastName;
    delete  tempFirstName;
    delete  tempCourse;
  }

  

   if (*tempCourse == "History")					//similar to math as well
   {
     int* grades = NULL;

     grades = new int[4];

     studentList >> grades[0] >> grades[1] >> grades[2] >> grades[3];

     History* temp = new History(*tempLastName, *tempFirstName, *tempCourse, grades[0], grades[1], grades[2], grades[3]);

     studentPointer[i] = temp;

     delete [] grades; 
     delete  tempLastName;
     delete  tempFirstName;
     delete  tempCourse;
   }
  
}

  studentList.close();						//detach object when finished


//----------------- END OF FILE ISTREAM ---------------------------------------------------------------------------------

  int counterA = 0, counterB = 0, counterC = 0, counterD = 0, counterF = 0;		//counters for grades
  
  char letterGrade;					
  double gradeAverage;


  ofstream gradeSummary;						//attach object to output stream

  gradeSummary.open(outputFile.c_str());	


  gradeSummary << "Student Grade Summary\n" << " ---------------------\n\n";
  
  gradeSummary << "ENGLISH CLASS\n\n";

  gradeSummary << left << setw(37) << "Student" << setw(10) << "Final" << setw(10) << "Final" << setw(10) << "Letter" << endl;
  gradeSummary << left << setw(37) << "Name" << setw(10) <<  "Exam" << setw(10) << "Avg" << setw(10) << "Grade" << endl;
  gradeSummary << "----------------------------------------------------------------" << endl;

  for (int i = 0; i < numStu; i++)		//loop that runs through student pointer array
  {

    if(studentPointer[i]->ReturnCourse() == "English")		//if the course is english, 
    {
	if(studentPointer[i]->Average() >= 90.00)		//check average and store appropriate values
	{
	  letterGrade = 'A';
	  counterA++;	
	}
	else if(studentPointer[i]->Average() >= 80.00 && studentPointer[i]->Average() < 90.00)
	{
	  letterGrade = 'B';
	  counterB++;
	}
	else if(studentPointer[i]->Average() >= 70.00 && studentPointer[i]->Average() < 80.00)
	{
	  letterGrade = 'C';
	  counterC++;
	}
	else if(studentPointer[i]->Average() >= 60.00 && studentPointer[i]->Average() < 70.00)
	{
	  letterGrade = 'D';
	  counterD++;
	}
	else
	{ 
	  letterGrade = 'F';
	  counterF++;
	}
	
	gradeAverage = studentPointer[i]->Average();			//store average into double for output 


       studentPointer[i]->Display(gradeSummary);		//call display function to output strings to file
       gradeSummary << setw(10) << left << setw(10) << gradeAverage << setw(10) << letterGrade << endl;		//then output rest of info

    } 		//just a note: I know format is first name then last name, but when I switched it, it adds a newline OUT OF NOWHERE.
		//I tried a bunch of stuff to get it to go away but this is the only way it would not happen	
	

  }


  gradeSummary << endl << endl << "HISTORY CLASS\n\n";					//SAME AS ENGLISH

  gradeSummary << left << setw(37) << "Student" << setw(10) << "Final" << setw(10) << "Final" << setw(10) << "Letter" << endl;
  gradeSummary << left << setw(37) << "Name" << setw(10) <<  "Exam" << setw(10) << "Avg" << setw(10) << "Grade" << endl;
  gradeSummary << "----------------------------------------------------------------" << endl;

  for (int i = 0; i < numStu; i++)
  {

    if(studentPointer[i]->ReturnCourse() == "History")
    {
	if(studentPointer[i]->Average() >= 90.00)
	{
	  letterGrade = 'A';
	  counterA++;	
	}
	else if(studentPointer[i]->Average() >= 80.00 && studentPointer[i]->Average() < 90.00)
	{
	  letterGrade = 'B';
	  counterB++;
	}
	else if(studentPointer[i]->Average() >= 70.00 && studentPointer[i]->Average() < 80.00)
	{
	  letterGrade = 'C';
	  counterC++;
	}
	else if(studentPointer[i]->Average() >= 60.00 && studentPointer[i]->Average() < 70.00)
	{
	  letterGrade = 'D';
	  counterD++;
	}
	else
	{ 
	  letterGrade = 'F';
	  counterF++;
	}
	
	gradeAverage = studentPointer[i]->Average();


       studentPointer[i]->Display(gradeSummary);
       gradeSummary << setw(10) << left << setw(10) << gradeAverage << setw(10) << letterGrade << endl;

    }

  }



  gradeSummary << endl << endl << "MATH CLASS\n\n";		//SAME AS HISTORY AND ENGLISH

  gradeSummary << left << setw(37) << "Student" << setw(10) << "Final" << setw(10) << "Final" << setw(10) << "Letter" << endl;
  gradeSummary << left << setw(37) << "Name" << setw(10) <<  "Exam" << setw(10) << "Avg" << setw(10) << "Grade" << endl;
  gradeSummary << "----------------------------------------------------------------" << endl;

  for (int i = 0; i < numStu; i++)
  {

    if(studentPointer[i]->ReturnCourse() == "Math")
    {
	if(studentPointer[i]->Average() >= 90.00)
	{
	  letterGrade = 'A';
	  counterA++;	
	}
	else if(studentPointer[i]->Average() >= 80.00 && studentPointer[i]->Average() < 90.00)
	{
	  letterGrade = 'B';
	  counterB++;
	}
	else if(studentPointer[i]->Average() >= 70.00 && studentPointer[i]->Average() < 80.00)
	{
	  letterGrade = 'C';
	  counterC++;
	}
	else if(studentPointer[i]->Average() >= 60.00 && studentPointer[i]->Average() < 70.00)
	{
	  letterGrade = 'D';
	  counterD++;
	}
	else
	{ 
	  letterGrade = 'F';
	  counterF++;
	}
	
	gradeAverage = studentPointer[i]->Average();


       studentPointer[i]->Display(gradeSummary);
       gradeSummary << setw(10) << left << setw(10) << gradeAverage << setw(10) << letterGrade << endl;

    }

  }

	gradeSummary << endl << endl << "OVERALL GRADE DISTRIBUTION" << endl << endl;
	
	gradeSummary << "A:\t" << counterA << endl;
	gradeSummary << "B:\t" << counterB << endl;
	gradeSummary << "C:\t" << counterC << endl;
	gradeSummary << "D:\t" << counterD << endl;
	gradeSummary << "F:\t" << counterF << endl;

  gradeSummary.close();

  for (int i = 0; i < numStu; i++)
  {
    delete  studentPointer[i];
  }

  delete [] studentPointer; 





return 0;


}
