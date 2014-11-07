#include <iostream>
using namespace std;
#include "GridMap.h"
#include "CircularObstacle.h"
//#include <map>
#include <boost/unordered_map.hpp>
#include "point.h"
#include "gtype.h"
#include "GraphEdge.h"
//#include "gobject.h"
#include <fontconfig/fontconfig.h>
#include <random>
#include <functional>
#include <stdlib.h>
#include <zlib.h>
#include <vector>
using namespace std;

int start_index = 2500;
int countNodesTree = 0;
int treeSize = 1000;
//int randNumber;
int nearestIndex = 0;
std::vector<int> randomNumberList;

bool isElementPresent(int num)
{
	for (std::vector<int>::iterator it = randomNumberList.begin();it!=randomNumberList.end();it++)
	{
		if(num == *it)
		{
			return true;
		}
	}

	return false;
}

int main() {

	GridMap gm;
	gm.InitVariables();
	gm.InitPointsMap();

	GraphEdge geObj;

	geObj.setGridMapObject(gm);



	/*geObj.addEdge(gm.points[500],gm.points[9999]);
	geObj.addEdge(gm.points[500],gm.points[9998]);
	geObj.addEdge(gm.points[500],gm.points[9997]);

	geObj.printAllEdges(gm.points[500]);
*/

	/*Loop to generate tree by randomly selecting points between 0 and 10000*/
	int randNumber = rand() % 10000;
	randomNumberList.push_back(randNumber);
	for(int i = 0;i<treeSize;i++)
	{
		while(isElementPresent(randNumber))
		{
			randNumber = rand() % 10000;
		}
		randomNumberList.push_back(randNumber);
		cout<<"\nrandom number being generated : "<<randNumber;
		if(countNodesTree == 0)
		{
			geObj.addEdge(gm.points[start_index],gm.points[randNumber]);
			countNodesTree++;
		}
		else if(countNodesTree > 0)
		{
			nearestIndex = geObj.getNearestNodeIndex(randNumber);
			countNodesTree++;
		}

		geObj.addEdge(gm.points[nearestIndex],gm.points[randNumber]);


	}


	return 0;
}


