#include <iostream>
#pragma once
using namespace std;
class Student
{
private:
	int timeNeeded, arrivalTime, stdNum, timeHelped;
public:
	Student();
	Student(int, int, int);
	~Student();
	int getTimeNeeded();
	int getArrivalTime();
	int getTimeHelped();
	void print();
	void setTimeHelped(int);
};

