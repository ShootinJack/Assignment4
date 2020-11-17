#include "Room.h"



Room::Room() // default constructor
{
}

Room::Room(Queue<Student> in, int num, int wNum) // Room overloaded constructor
{
	office.setWindowCount(wNum); // sets how many windows will be open in the office
	time = -1; 
	length = num;
	helped = 0;
	overTen = 0;
	line = in;				// imports the line of students
	studentStats = new int[num];			// dynamically creates array for student wait times
}


Room::~Room() // destructor deleting dynamically created array
{
	delete[] studentStats;
}

void Room::startDay() // main function of the program, loops through until the line is empty. 
{
	while (line.notEmpty()) {
		++time;
		if (checkFrontOfLine()) {
			while (checkFrontOfLine()) { // if we have an available student and an open window the student is sent to the window
				if (!office.isFull()) {
					tempStudent = getFrontOfLine();
					office.sendToOpenWindow(tempStudent);
					studentStats[helped] = (time - tempStudent->getArrivalTime());
					if (studentStats[helped] > 10) {
						++overTen;
					}
					++helped;
				}
				else {
					break;
				}
			}
		}
		if (line.notEmpty()) {
			office.updateTime(time);
		}
		
		
	}
	reorderArray();			//after loop is completed the stats are produced and printed for the user
	setStudentStats();
	printStudentStats();
	office.setStats();
	office.printStats();
	cout << endl;
}

bool Room::checkFrontOfLine() // checks to see if there is a student in line
{
	Student *tempStudent = line.peekFront();
	if (tempStudent == NULL) {
		return false;
	}
	if (tempStudent->getArrivalTime() <= time) {
		return true;
	}
	else {
		return false;
	}
}

Student* Room::getFrontOfLine() // returns student at the front of the line
{
	Student *tempStudent = line.removeFront();
	return tempStudent;
}

void Room::reorderArray() // function reorders the array in ascending order
{
	sort(&studentStats[0], &studentStats[length]);
}

void Room::setStudentStats() // calculates and sets all the students stats
{
	int sum = 0, greatest = 0, waitingStudents = 0; 
	median = studentStats[length / 2];
	mean = 0;
	for (int i = 0; i < length; ++i) {
		sum = sum + studentStats[i];
		if (studentStats[i] > 0) {
			++waitingStudents;
		}
		if (studentStats[i] > greatest) {
			greatest = studentStats[i];
		}
	}
	if (waitingStudents == 0) {
		mean = 0;
	}
	else {
		mean = double(sum) / double(waitingStudents);
	}
	longest = greatest;
}

void Room::printStudentStats() // prints stats
{
	cout << "The mean student wait time was " << mean << " minutes\n";
	cout << "The median student wait time was " << median << " minutes\n";
	cout << "The longest student wait time was " << longest << " minutes\n";
	cout << "The number of students what waited over 10 minutes was " << overTen << endl;
}
