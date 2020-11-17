#include <iostream>
#include "Input.h"
#include "Student.h"
#include "Queue.h"
#include "Room.h"
using namespace std;

int main(int argc, char** argv) {
	Input *read = new Input(argv[1]);
	Queue<Student> line = read->getLine();
	Room main(line, read->getStdNum(), read->getWindowNum());
	main.startDay();

	delete read;
	system("pause");
	return 0;
}