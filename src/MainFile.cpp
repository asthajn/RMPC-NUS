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
#include "Path.h"
using namespace std;

int start_index = 2500;
int goal_index = 9792;
int countNodesTree = 0;
int treeSize = 5000;
std::vector<std::vector<GPoint> > tree(1000);
//int randNumber;
int nearestIndex = 0;
std::vector<int> randomNumberList;
std::vector<GPoint> pathPoints;

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
	randomNumberList.push_back(randNumber);  //This list will maintain the random numbers already selected
	for(int i = 0;i<treeSize;i++)
	{
		while(isElementPresent(randNumber))		//IF a particular random number (index) has already been considered,
		{										//we don't consider it again.
			randNumber = rand() % 10000;
		}
		randomNumberList.push_back(randNumber);
	//	cout<<"\nRandom number being generated : "<<randNumber;
		if(countNodesTree == 0)
		{
			//cout<<"\nAdding the first node into tree";
			geObj.addEdge(gm.points[start_index],gm.points[randNumber]);
			countNodesTree++;
		}
		else if(countNodesTree > 0)
		{
			//cout<<"\nAdding a node to the tree";

			nearestIndex = geObj.getNearestNodeIndex(randNumber);
			///cout<<"\nNearest point's index is : "<<nearestIndex;
			geObj.addEdge(gm.points[nearestIndex],gm.points[randNumber]);
			countNodesTree++;
		}




	}

	cout<<"\nSize of tree is :"<<geObj.sizeOfTree;
	cout.flush();

	tree  = geObj.getTreeToMain();

	Path pathObj(start_index,goal_index,geObj,gm,tree);// = new Path(start_index,goal_index,geObj,gm);

	//pathObj.Path(start_index,goal_index,geObj,gm);
	pathObj.path.push_back(gm.points[goal_index]);

	pathObj.getPath(goal_index);
	cout<<"\n Outside get Path function, length of the path is "<<geObj.getLength(pathObj.path);
	cout.flush();
	pathObj.printPath();


	return 0;
}


