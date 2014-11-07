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
//#include <unordered_map>
#include <map>
#include <boost/unordered_map.hpp>

namespace std {

class GraphEdge {
public:
	GridMap gmObj;
	GPoint edges[1][2];
	//int countOfEdge;
	int countOfEdge;
	//boost::unordered_multimap<GPoint, GPoint> edgeMap;
	//multimap<GPoint, GPoint> edgeMap;

	void setGridMapObject(GridMap gm);
	void addEdge(GPoint p1, GPoint p2);
	//void getEdgeForPoint(GPoint p1);
	bool isPointPresent(GPoint p1);
	void increaseSizeEdgeArray();
	void printGraphEdges();
	int getIndex(GPoint p1);
	void printAllEdges(GPoint p1);
	int getLength(std::vector<GPoint> vect);
	void initTree(GPoint p1);
	int getNearestNodeIndex(int randNum);
	double getDistance(GPoint p1, GPoint p2);
	/*GraphEdge();
	virtual ~GraphEdge();*/
};

} /* namespace std */
#endif /* GRAPHEDGE_H_ */
