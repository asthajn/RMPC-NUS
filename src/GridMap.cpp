/*
 * GridMap.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: harshul
 */

#include "GridMap.h"
#include <iostream>
using namespace std;


/*GridMap::GridMap() {
	// TODO Auto-generated constructor stub

}

GridMap::~GridMap() {
	// TODO Auto-generated destructor stub
}*/

void GridMap::InitPointsMap()
{
//	points.insert(pair<float, float>(0.1,0.1));
	for (float i = 0.1;i<maxSizeX;i+=0.1)
	{
		for (float j = 0.1;j<maxSizeY;j+=0.1)
		{
			points.insert(pair<float, float>(i,j));
		}

	}
}

void GridMap::PrintPointMap()
{
	for(multimap<float, float>::iterator it = points.begin();it!=points.end();++it)
	{
		cout<<"\n["<<(*it).first<<", "<<(*it).second<<" ]";
		count++;
	}
}

void GridMap::TestPrint()
{
	cout<<"\n Inside GridMap Class - able to access the methods \n";
	cout<<"\n Number of samples formed : "<<count;
}

 /* namespace std */
