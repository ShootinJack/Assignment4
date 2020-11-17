#include<iostream>
#include "Student.h"
#pragma once
class Window
{
private:
	Student *tempStudent;
	int timeIn, currentTime, timeNeeded, idleTime, helpTime;
	bool open, overFive;
public:
	Window();
	~Window();
	int getIdleTime();
	void acceptStudent(Student*);
	void exitStudent();
	void updateTime(int);
	void setOpen();
	bool isOpen();
	bool isStudentFinished();
	bool getOverFive();
};

