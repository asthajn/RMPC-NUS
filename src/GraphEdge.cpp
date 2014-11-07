/*
 * GraphEdge.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: harshul
 */

#include "GraphEdge.h"
#include "point.h"
#include "gtype.h"
#include "GridMap.h"
#include <map>
#include <vector>
//#include <unordered_map>
#include <boost/unordered_map.hpp>

namespace std {

GridMap gmObj;
GPoint edges[6][2];//= new GPoint[1][2];
double minDistance = 0.0;
int minDistancePoint = 0;
//boost::unordered_multimap<GPoint, GPoint> edgeMap;
//multimap<GPoint, GPoint> edgeMap;
std::vector< std::vector<GPoint> > treeEdges(10000);

//int countOfEdge;
void GraphEdge::setGridMapObject(GridMap gm)
{
	cout<<"\nSetting object";
	gmObj = gm;
	cout<<"\nObject set";
	cout.flush();
}
void GraphEdge::addEdge(GPoint p1, GPoint p2)
{
	/*cout<<"\nInside Add Edge function";
	cout.flush();*/

	std::vector<GPoint> edgeEndPoints;

	edgeEndPoints.push_back(p2);

	int index = getIndex(p1);
	//cout<<"\nValue of index is :"<<index;
	cout.flush();
	treeEdges[index].push_back(p2);

	cout<<"\nEdge added is  : ("<<p1.getX()<<", "<<p1.getY()<<") --> ("<<p2.getX()<<", "<<p2.getY()<<")\n\n";
	cout.flush();
}

int GraphEdge::getIndex(GPoint p1)
{
	for(int i = 0; i<10000;i++)
	{
		if(gmObj.points[i] == p1)
		{
			return i;
		}
	}

}

bool GraphEdge::isPointPresent(GPoint p1)
{
	int lenPoints = (sizeof(gmObj.points)/sizeof(gmObj.points[0]));
	for (int i = 0;i<lenPoints;i++)
	{
		if(gmObj.points[i] == p1)
		{
			return true;
		}
	}

	return false;
}


void GraphEdge::printAllEdges(GPoint p1)
{
	int index = getIndex(p1);
	int length = getLength(treeEdges[index]);
	cout<<"\n Edges for point ("<<p1.getX()<<", "<<p1.getY()<<")";
	cout.flush();
	for(int i = 0;i<length;i++){
		cout<<"\n("<<treeEdges[index][i].getX()<<", "<<treeEdges[index][i].getY()<<")";
		cout.flush();
	}
}

/*Returns the length of */
int GraphEdge::getLength(std::vector<GPoint> vect)
{
	int count = 0;
	std::vector<GPoint>::iterator it;
	for(it = vect.begin();it!=vect.end();it++)
	{
		count++;
	}
	return count;
}


void GraphEdge::increaseSizeEdgeArray()
{
	int length = sizeof(edges)/sizeof(edges[0]);

	GPoint edgeArrayTemp[length][2];// = new GPoint[length][2];

	memcpy(edgeArrayTemp, edges, length);

/*
	edges = edgeArrayTemp;
	delete[] edgeArrayTemp;
*/

}

void GraphEdge::initTree(GPoint p1)
{
	int index = getIndex(p1);

}

int GraphEdge::getNearestNodeIndex(int randNum)
{
	double dist;
	int len;
	for (int i = 0;i<10000;i++)
	{
		if(getLength(treeEdges[i])!=0)
		{
			dist = getDistance(gmObj.points[i],gmObj.points[randNum]);
			if(minDistance == 0)
			{
				minDistance = dist;
				minDistancePoint = i;
			}

			len = getLength(treeEdges[i]);
			for(int j = 0;j<len;j++)
			{
				dist = getDistance(treeEdges[i][j],gmObj.points[randNum]);
				if(dist<minDistance)
				{
					minDistance = dist;
					minDistancePoint = getIndex(treeEdges[i][j]);
				}

			}
		}

		return minDistancePoint;
	}
}

double GraphEdge::getDistance(GPoint p1, GPoint p2)
{
	return pow((pow((p1.getX() - p2.getX()),2) + pow((p1.getY() - p2.getY()),2)),0.5);
}



void GraphEdge::printGraphEdges()
{
	int length =  6;//sizeof(edges)/sizeof(edges[0]);
	//cout<<"\nTrying to print edges";
	/*for (multimap<GPoint, GPoint>::iterator it = edgeMap.begin();it!=edgeMap.end();it++)
	{
		cout<<"\nGraph edge is : ("<<it->first.getX()<<", "<<it->first.getY()<<") --> ("<<it->second.getX()<<", "<<it->second.getY()<<" )";

	}*/
	/*for (int i = 0;i<length;i++)
	{
		cout<<"\nEdge number "<<i+1<<" is ("<<edges[i][0].getX()<<","<<edges[i][0].getY()<<") --> ("<<edges[i][1].getX()<<", "<<edges[i][1].getY()<<")";
	}*/

}


/*
GraphEdge::GraphEdge() {
	// TODO Auto-generated constructor stub

}

GraphEdge::~GraphEdge() {
	// TODO Auto-generated destructor stub
}*/

} /* namespace std */
