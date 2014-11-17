/*
 * GraphEdge.h
 *
 *  Created on: Nov 4, 2014
 *      Author: harshul
 */

#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_
#include "point.h"
#include "gtype.h"
#include "GridMap.h"
#include <vector>
//#include <unordered_map>
#include <map>
//#include <boost/unordered_map.hpp>

namespace std {

class GraphEdge {
public:
	GridMap gmObj;
	GPoint edges[1][2];
	int countOfEdge;
	int sizeOfTree = 0;
	int range_end = 500;
	std::vector<int> randomNumberList;
	int countNodesTree = 0;
	int nearestIndex = 0;
	void setGridMapObject(GridMap gm);
	void addEdge(GPoint p1,GPoint p2);
	//void getEdgeForPoint(GPoint p1);
	bool isPointPresent(GPoint p1, int size);
	void increaseSizeEdgeArray();
	void printGraphEdges();
	int getIndex(GPoint p1);
	void printAllEdges(GPoint p1);
	int getLength(std::vector<GPoint> vect);
	void initTree(GPoint p1);
	int getNearestNodeIndex(GPoint pnt);
	double getDistance(GPoint p1, GPoint p2);
	bool isElementPresent(int num);
	std::vector<std::vector<GPoint> > getTreeToMain();
	std::vector<std::vector<GPoint> > makeTree(int treeSize,int startIndex, int randomNumber);
	/*GraphEdge();
	virtual ~GraphEdge();*/
};

} /* namespace std */
#endif /* GRAPHEDGE_H_ */
