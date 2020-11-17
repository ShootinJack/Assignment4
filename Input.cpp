#include "Input.h"



Input::Input() // default constructor
{
}

Input::Input(string n) //overloaded constructor checks to see if filename passed is valid. If not it reprompts user
{
	filename = n;
	stdNum = 0;
	windowNum = 0;
	inFile.open(filename);
	if (inFile.good()) {
		inFile.close();
		parseFile();
	}
	else {
		cout << "Invalid file name\n";
		repromptUser();
	}
	inFile.close();
}

Input::~Input()
{
}

void Input::parseFile() // parse through the file and create doubly linked list of students
{
	bool first = true;
	inFile.open(filename);
	while (inFile.good()) {
		inFile >> openWindows >> time >> numStudents;
		if (first) {
			windowNum = openWindows;
			first = false;
		}
		for (int i = 0; i < numStudents; i++) {
			inFile >> timeNeeded;
			stdNum++;
			Student *in = new Student(time, timeNeeded, stdNum);
			myQueue.insertBack(in);
		}
	}
}

int Input::getWindowNum() // return the number of open windows for the simulation
{
	return windowNum;
}

void Input::repromptUser() // function to reprompt if the txt entry is not valid
{
	cout << "Enter file name: ";
	cin >> filename;
	inFile.open(filename);
	if (inFile.good()) {
		parseFile();
	}
	else {
		cout << "Invalid file name\n";
		repromptUser();
	}
	inFile.close();
}

void Input::printList() // prints the linked list
{
	myQueue.printList();
}

int Input::getStdNum() // gets number of students in simulation
{
	return stdNum;
}

Queue<Student> Input::getLine() // returns the linked list
{
	return myQueue;
}

