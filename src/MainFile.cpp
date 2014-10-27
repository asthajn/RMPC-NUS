#include <iostream>
using namespace std;
#include "GridMap.h"



int main() {
	//cout << "\nInside Main function !!!\n";
	GridMap gm;

	gm.InitPointsMap();
	gm.PrintPointMap();
	gm.TestPrint();
	return 0;
}

