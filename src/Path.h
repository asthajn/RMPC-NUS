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
	int start, goal,len;
	GraphEdge geObject;
	GridMap gmObject;
	std::vector<std::vector<GPoint> > treeEdgesPath;
	Path(int start_index, int goal_index, GraphEdge geObj, GridMap gmObj, std::vector<std::vector<GPoint> > treeEdges);
	//virtual ~Path();
	void getPath(int goal_index);
	void printPath();
};

} /* namespace std */
#endif /* PATH_H_ */
