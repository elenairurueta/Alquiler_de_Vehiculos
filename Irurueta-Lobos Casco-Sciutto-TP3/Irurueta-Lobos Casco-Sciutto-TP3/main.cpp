#include <iostream>
#include <string>
#include "cAutomovil.h"
using namespace std;

int main() {

	cAutomovil* automovil = new cAutomovil();
	cout << automovil << endl;
	system("pause");

	delete automovil;
	return 0;
}