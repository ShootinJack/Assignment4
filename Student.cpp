#include "Student.h"



Student::Student()
{
}

Student::Student(int at, int tn, int n)
{
	arrivalTime = at;
	timeNeeded = tn;
	stdNum = n;
}


Student::~Student()
{
}

int Student::getTN()
{
	return timeNeeded;
}

ostream& operator<<(ostream& os, const Student& s) {
	os << "Student: " << s.stdNum << endl;
	return os;
}