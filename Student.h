#include <iostream>
#pragma once
using namespace std;
class Student
{
private:
	int timeNeeded, arrivalTime, stdNum;
public:
	Student();
	Student(int, int, int);
	~Student();
	int getTN();
	friend ostream& operator<<(ostream& os, const Student& s);
};

