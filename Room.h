#include <iostream>
#include <algorithm>
#include "Queue.h"
#include "Student.h"
#include "Office.h"
#include "Window.h"
#pragma once
class Room
{
private:
	int time, helped, *studentStats, length, median, longest, overTen;
	double mean;
	Queue<Student> line;
	Office office;
	Student *tempStudent;
public:
	Room();
	Room(Queue<Student>, int, int);
	~Room();
	void startDay();
	bool checkFrontOfLine();
	void reorderArray();
	void setStudentStats();
	void printStudentStats();
	Student* getFrontOfLine();

};

