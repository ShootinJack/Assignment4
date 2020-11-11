#include <iostream>
#include "Input.h"
#include "Student.h"
#include "Queue.h"
using namespace std;

int main() {
	Input *read = new Input("test.txt");
	read->printList();

	system("pause");
	return 0;
}