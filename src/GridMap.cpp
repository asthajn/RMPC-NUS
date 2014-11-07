/*
 * GridMap.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: harshul
 */

#include "GridMap.h"
#include <iostream>
//#include "basicgraph.h"
#include "point.h"
#include "gtype.h"
#include <unordered_map>
#include <fontconfig/fontconfig.h>
#include <random>
#include <functional>
using namespace std;

typedef std::multimap<float, float> floatMultiMap;

//maxSizeX = 10.0;
//int GridMap::maxSizeY = 10.0;
//int GridMap::count = 0;
/*
static GridMap *gmObj=NULL;

	GridMap::GridMap()
	{
		gmObj->InitObstaclePointsMap();
		gmObj->InitPointsMap();
		gmObj->InitVariables();
	}*/


/*GridMap* GridMap::getInstance()
{
	if (!gmObj) {
		gmObj = new GridMap;
	}

	return gmObj;
}*/





void GridMap::InitVariables()
{
	maxSizeX = 10.0;
	maxSizeY = 10.0;
	count = 0;
	GPoint points[10000];
}


//Function to select grid points - steps of 0.1
void GridMap::InitPointsMap()
{
//	points.insert(pair<float, float>(0.1,0.1));
	float val_x;
	float val_y;
	int index = 0;

	int number = 5000, range_end=500;
	/*ranlux48 generator;
	uniform_int_distribution<int> distribution(0,range_end);
	double y[number];
	vector<double> dice_roll;
	for(int i=0;i<number;i++)
{
	               dice_roll[i] = distribution(generator);
	               //auto dice = bind(distribution, generator);

	               y[i] = distribution(generator);
	               }

*/
	for (val_x=0.0;val_x<=maxSizeX;val_x+=0.1)
	{
		for (val_y=0.0;val_y<=maxSizeY;val_y+=0.1)
		{
			GPoint pt = GPoint(val_x,val_y);
			points[index] = pt;
			index++;
			count++;
		}

	}
//PrintPointMap(points);
}

//Printing the grid points
void GridMap::PrintPointMap(GPoint pts[])
{
	/*for(multimap<float, float>::iterator it = mmap.begin();it!=mmap.end();++it)
	{
		cout<<"\n["<<(*it).first<<", "<<(*it).second<<" ]";
		count++;
	}*/

	for(int i = 0;i<count;i++)
		{
			cout<<"\nPoint @"<<i<<" is : (" <<pts[i].getX()<<", "<<pts[i].getY()<<")";

		}
}



void GridMap::TestPrint()
{
	cout<<"\n Inside GridMap Class - able to access the methods \n";
	cout<<"\n Number of samples formed : "<<count;
}


//Initializing the obstacle points.
void GridMap::InitObstaclePointsMap()
{

	//obsPoints.insert(pair<float, float>(7.1,8.2)); // Center for the circular obstacle
	//floatMultiMap::iterator it = obsPoints.begin();
	float temp[2] = {obsPoints[0][0],obsPoints[0][1]};

	//obstaclePoints.insert(pair<string, float[]>("Point1",temp));

	/*obsPoints.insert(pair<float, float>(2.1,3.2)); // Obstacle vertex for a rectangular
	obstaclePoints.insert(pai<float, float>(5.6,3.2));
	obsPoints.insert(pair<float, float>(2.1,4.5));	// obstacle
	obstaclePoints.insert(pair<float, float>(5.6,3.2));
	obsPoints.insert(pair<float, float>(5.6,4.5));
	obstaclePoints.insert(pair<float, float>(5.6,3.2));
	obsPoints.insert(pair<float, float>(5.6,3.2));
	obstaclePoints.insert(pair<float, float>(5.6,3.2));*/


}
 /* namespace std */
