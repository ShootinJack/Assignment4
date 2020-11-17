#include "Office.h"



Office::Office()
{
	time = 0;
	overFiveNum = 0;
}

Office::~Office()
{
	delete[] window;
}

void Office::setWindowCount(int in) // overloaded constructor sets size of array of windows dynamically
{
	length = in;
	window = new Window[in];
}

bool Office::isFull() // checks if all the windows are full 
{
	for (int i = 0; i < length; ++i) {
		if (window[i].isOpen()) {
			return false;
		}
	}
	return true;
}

Window Office::getOpenWindow() // returns open window
{
	for (int i = 0; i < length; ++i) {
		if (window[i].isOpen()) {
			window[i].setOpen();
			return window[i];
		}
	}
}

void Office::sendToOpenWindow(Student *in) // sends student to open window
{
	if (!isFull()) {
		for (int i = 0; i < length; ++i) {
			if (window[i].isOpen()) {
				window[i].acceptStudent(in);
				window[i].setOpen();
				Stack.push(window[i].getIdleTime());
				break;
			}
		}
	}

}

void Office::updateTime(int t) // updates time
{
	time = t;
	for (int i = 0; i < length; ++i) {
		window[i].updateTime(time);
		if (window[i].isStudentFinished()) {
			window[i].exitStudent();
		}
	}
}

void Office::setStats() // calculates and sets window stats
{
	int count = 0, sum = 0, greatest = 0;
	while (!Stack.isEmpty()) {
		++count;
		if (greatest < Stack.peek()) {
			greatest = Stack.peek();
		}
		sum = sum + Stack.pop();
	}
	for (int i = 0; i < length; ++i) {
		if (window[i].getOverFive()) {
			++overFiveNum;
		}
	}
	mean = double(sum) / double(count);
	longestIdle = greatest;
}

void Office::printStats() // prints stats
{
	cout << "The mean window idle time is: " << mean << endl;
	cout << "The longest window idle time is: " << longestIdle << endl;
	cout << "The number of windows idle for over 5 minutes was: " << overFiveNum << endl;
}
