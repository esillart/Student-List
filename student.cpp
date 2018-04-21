#include "student.h"

Student::Student(string ln, string fn, string crs)
{
  lastName = ln;
  firstName = fn;
  course = crs;
};

/*Student::~Student()
{
  delete [] list;
};*/


English::English(string ln, string fn, string crs, int term, int mid, int fnl) : Student(ln, fn, crs)
{
  termPaper = term;
  midterm = mid;
  finalExam = fnl;
};


History::History(string ln, string fn, string crs, int attend, int proj, int mid, int fnl) : Student(ln, fn, crs)
{
  attendance = attend;
  project = proj;
  midterm = mid;
  finalExam = fnl;
};

Math::Math(string ln, string fn, string crs, int qz1, int qz2, int qz3, int qz4, int qz5, int tst1, int tst2, int fnl) : Student(ln, fn, crs)
{
  quiz1 = qz1;
  quiz2 = qz2;
  quiz3 = qz3;
  quiz4 = qz4;
  quiz5 = qz5;
  test1 = tst1;
  test2 = tst2;
  finalExam = fnl;
};


double English::Average()
{
  cout << setprecision(2) << fixed;

  double avg = (termPaper * .25) + (midterm * .35) + (finalExam * .40);

  return avg;
};


double History::Average()
{
  cout << setprecision(2) << fixed;

  double avg = (attendance * .10) + (project * .30) + (midterm * .30) + (finalExam * .30);

  return avg;
};


double Math::Average()
{
  cout << setprecision(2) << fixed;

  double avg = (((quiz1 + quiz2 + quiz3 + quiz4 + quiz5) / 5.00) * .15) + (test1 * .25) + (test2 * .25) + (finalExam * .35);

  return avg;
};


void English::Display(ostream &os)
{
  os << left << lastName << ' ' << setw(25) << firstName << setw(10) << finalExam << ' ';
};


void History::Display(ostream &os)
{
  os << left << lastName << ' ' << setw(25) << firstName << setw(10) << finalExam << ' ';
};



void Math::Display(ostream &os)
{
  os << left << lastName << ' ' << setw(25) << firstName << setw(10) << finalExam << ' ';
};


string English::ReturnCourse()
{
  return course;
};


string History::ReturnCourse()
{
  return course;
};


string Math::ReturnCourse()
{
  return course;
};


