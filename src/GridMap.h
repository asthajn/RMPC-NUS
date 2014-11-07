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
#include "basicgraph.h"
#include "point.h"
#include "gtype.h"
//#include "gobject.h"
//#include <unordered_map>
//#include <boost/unordered_map.hpp>

//#include "multimap.h"
namespace std {
typedef std::multimap<float, float> floatMultiMap;

class GridMap {

/*GridMap();*/

	//virtual ~GridMap();
public:
	float maxSizeX;
	float maxSizeY;
	int count;
	GPoint points[10000];
	float obsPoints[5][2] = {{7.1,8.2},
			{2.1,3.2},
			{2.1,4.5},
			{5.6,4.5},
			{5.6,3.2}};
	//float obsPoints[5][2];

/*public:
	static GridMap* getInstance();*/

public:
	void InitVariables();
	void TestPrint();
	void InitPointsMap();
	void InitObstaclePointsMap();
	void PrintPointMap(GPoint pt[]);


};

} /* namespace std */
#endif /* GRIDMAP_H_ */
