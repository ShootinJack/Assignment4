#include "Input.h"



Input::Input()
{
}

Input::Input(string n)
{
	filename = n;
	stdNum = 0;
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

void Input::parseFile()
{
	inFile.open(filename);
	while (inFile.good()) {
		inFile >> openWindows >> time >> numStudents;
		for (int i = 0; i < numStudents; i++) {
			inFile >> timeNeeded;
			stdNum++;
			Student *in = new Student(time, timeNeeded, stdNum);
			cout << "Created Student\n";
			myQueue->insertBack(in);
		}
	}
}

void Input::repromptUser()
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

void Input::printList()
{
	myQueue->printList();
}

