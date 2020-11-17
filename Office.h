#include <iostream>
#include "Window.h"
#include "GenStack.h"
#pragma once
class Office
{
private:
	Window *window;
	GenStack<int> Stack;
	int time, longestIdle, overFiveNum, length;
	double mean;
public:
	Office();
	~Office();
	void setWindowCount(int);
	bool isFull();
	Window getOpenWindow();
	void updateTime(int);
	void sendToOpenWindow(Student*);
	void setStats();
	void printStats();
};

