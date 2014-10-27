/*
 * GridMap.h
 *
 *  Created on: Oct 27, 2014
 *      Author: harshul
 */

#ifndef GRIDMAP_H_
#define GRIDMAP_H_
#include <iostream>
#include <map>
//#include "multimap.h"
namespace std {

class GridMap {
public:
	/*GridMap();
	virtual ~GridMap();*/
	int maxSizeX = 10.0;
	int maxSizeY = 10.0;
	int count = 0;
	multimap<float, float> points;

	void TestPrint();
	void InitPointsMap();
	void PrintPointMap();


};

} /* namespace std */
#endif /* GRIDMAP_H_ */
