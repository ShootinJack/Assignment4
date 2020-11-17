#include "Window.h"



Window::Window() // default constructor 
{
	tempStudent = NULL;
	currentTime = 0;
	helpTime = 0;
	idleTime = 0;
	open = true;
	overFive = false;
}


Window::~Window()
{
}

void Window::acceptStudent(Student* in) // sets data for accepting student
{
	tempStudent = in;
	timeIn = currentTime;
	tempStudent->setTimeHelped(currentTime);
	timeNeeded = tempStudent->getTimeNeeded();
}

void Window::exitStudent() // removes student 
{
	tempStudent = NULL;
	helpTime = 0;
	setOpen();
}

void Window::setOpen() // sets open window boolean
{
	if (open) {
		open = false;
	}
	else {
		open = true;
	}
}

bool Window::isOpen() // returns boolean value
{
	return open;
}

void Window::updateTime(int t) // updates time 
{
	currentTime = t;
	if (isOpen() == false) {
		++helpTime;
	}
	else {
		++idleTime;
		if (idleTime > 5) {
			overFive = true;
		}
	}
}

bool Window::isStudentFinished() // checks if student is done at the window
{
	if (tempStudent == NULL) {
		return false;
	}
	if (isOpen() == false) {
		if (helpTime >= tempStudent->getTimeNeeded()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int Window::getIdleTime() // returns idle time for window
{
	return idleTime;
}

bool Window::getOverFive() // returns boolean value to see if the window was idle over 5 seconds
{
	return overFive;
}