/*
 * Path.h
 *
 *  Created on: Nov 7, 2014
 *      Author: harshul
 */

#ifndef PATH_H_
#define PATH_H_

#include "GraphEdge.h"
#include "GridMap.h"
#include "gtype.h"
#include "point.h"
#include <vector>


namespace std {

class Path {
public:
	vector<GPoint> path;
	int start, goal,len, treeSize;
	bool isStartPntPresent, isGoalPntPresent, appendStartFlag;
	GraphEdge geObject;
	GridMap gmObject;
	GPoint startPnt;
	std::vector<std::vector<GPoint> > treeEdgesPath;
	Path(int start_index, int goal_index, GraphEdge geObj, GridMap gmObj, std::vector<std::vector<GPoint> > treeEdges,int treeSize);
	void getPath(int goal_idx);
	void printPath();
	int connectStartToTree(GPoint startPnt, GPoint goalPnt);

};

} /* namespace std */
#endif /* PATH_H_ */
