#include "Student.h"



Student::Student() // default constructor
{
}

Student::Student(int at, int tn, int n) // overloaded constructor, stores student data
{
	arrivalTime = at;
	timeNeeded = tn;
	stdNum = n;
}


Student::~Student()
{
}

int Student::getTimeNeeded() // returns time needed at window
{
	return timeNeeded;
}

int Student::getTimeHelped() // returns time the student was sent to a window
{
	return timeHelped;
}

int Student::getArrivalTime() // returns time arrived to the office
{
	return arrivalTime;
}

void Student::print() { // prints student number
	cout << "Student: " << stdNum;
}

void Student::setTimeHelped(int t) // sets time student was helped at the window
{
	timeHelped = t;
}