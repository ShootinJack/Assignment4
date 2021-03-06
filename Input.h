#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "Queue.h"
#pragma once
using namespace std;

class Input
{
private:
	string filename;
	ifstream inFile;
	Queue<Student> myQueue;
	int openWindows, time, numStudents, timeNeeded, stdNum, windowNum;

public:
	Input();
	Input(string);
	~Input();
	void parseFile();
	void repromptUser();
	void printList();
	int getWindowNum();
	int getStdNum();
	Queue<Student> getLine();
};

