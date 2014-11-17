#include <iostream>
using namespace std;
#include "GridMap.h"
#include "CircularObstacle.h"
#include <boost/unordered_map.hpp>
#include "point.h"
#include "gtype.h"
#include "GraphEdge.h"
#include <fontconfig/fontconfig.h>
#include <random>
#include <functional>
#include <stdlib.h>
#include <zlib.h>
#include <vector>
#include "Path.h"
#include <cairo/cairo.h>

using namespace std;

int start_index = 172;
int goal_index = 2142;
int countNodesTree = 0;
int treeSize = 150;
std::vector<std::vector<GPoint> > tree(treeSize);
int nearestIndex = 0;
//std::vector<int> randomNumberList;
std::vector<GPoint> pathPoints;
int range_end = 500;
int goal;
//Start node : (33.9734, 89.7077)
//Goal node : (240.522, 256.619)


int main() {

	GPoint startPnt = GPoint(33.9734, 89.7077);
	GPoint goalPnt = GPoint(432.962, 410.464);		//412.464


	/*Defining sample points */
	GridMap gm;
	gm.InitVariables();
	gm.InitPointsMap();


	/*Making rapidly exploring random tree*/
	GraphEdge geObj;
	geObj.setGridMapObject(gm);
	int randNumber = rand() % treeSize;
	geObj.makeTree(treeSize, start_index,randNumber);
	tree  = geObj.getTreeToMain();


	/*Getting path based on  a fixed goal node*/
	Path pathObj(start_index,goal_index,geObj,gm,tree,treeSize);
	goal = pathObj.connectStartToTree(startPnt, goalPnt);
	pathObj.getPath(goal);
	pathObj.printPath();


	  return 0;
}


