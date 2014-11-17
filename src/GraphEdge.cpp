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
#include <cairo/cairo.h>
#include <time.h>

namespace std {

GridMap gmObj;
double minDistance = 0.0;
int minDistancePoint = 0;
std::vector<std::vector<GPoint> > treeEdges(10000);


void GraphEdge::setGridMapObject(GridMap gm)
{
	gmObj = gm;
	cout.flush();
}
void GraphEdge::addEdge(GPoint p1, GPoint p2)
{
	std::vector<GPoint> edgeEndPoints;

	edgeEndPoints.push_back(p2);

	int index = getIndex(p1);
	//cout<<"\nValue of index is :"<<index;
	cout.flush();
	treeEdges[index].push_back(p2);

	//cout<<"\nEdge added is  : ("<<p1.getX()<<", "<<p1.getY()<<") --> ("<<p2.getX()<<", "<<p2.getY()<<")\n\n";
	cout.flush();
	sizeOfTree++;
}

int GraphEdge::getIndex(GPoint p1)
{
	for(int i = 0; i<1000;i++)
	{
		if(gmObj.points[i] == p1)
		{
			return i;
		}
	}

}

bool GraphEdge::isPointPresent(GPoint p1, int size)
{
	int lenPoints = size;		//(sizeof(gmObj.points)/sizeof(gmObj.points[0]));
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
	//cout<<"\n Edges for point ("<<p1.getX()<<", "<<p1.getY()<<")";
	cout.flush();
	for(int i = 0;i<length;i++){
		//cout<<"\n("<<treeEdges[index][i].getX()<<", "<<treeEdges[index][i].getY()<<")";
		cout.flush();
	}
}

/*Returns the length of a vector of type GPoint*/
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

}

void GraphEdge::initTree(GPoint p1)
{
	int index = getIndex(p1);
}

int GraphEdge::getNearestNodeIndex(GPoint pnt)
{
	double dist;
	int len;
	for (int i = 0;i<1000;i++)
	{
		if(getLength(treeEdges[i])!=0)
		{
			//cout<<"\nLength at index "<<i<<" is "<<getLength(treeEdges[i]);
			dist = getDistance(gmObj.points[i],pnt);
			if(minDistance == 0)
			{
				minDistance = dist;
				minDistancePoint = i;
			}

			len = getLength(treeEdges[i]);
			for(int j = 0;j<len;j++)
			{
				dist = getDistance(treeEdges[i][j],pnt);
				if(dist<minDistance)
				{
					minDistance = dist;
					minDistancePoint = getIndex(treeEdges[i][j]);
				}

			}
		}

	}
	minDistance = 0;
	return minDistancePoint;

}

double GraphEdge::getDistance(GPoint p1, GPoint p2)
{
	return pow((pow((p1.getX() - p2.getX()),2) + pow((p1.getY() - p2.getY()),2)),0.5);
}

std::vector<std::vector<GPoint> > GraphEdge::makeTree(int treeSize,int start_index, int randNumber)
{
	/*Setting up surface in
	 * cairo to print the tree*/
	cairo_surface_t *surface_1;
	cairo_t *cr_1;

	surface_1 = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, range_end, range_end);
	cr_1 = cairo_create(surface_1);
	cairo_set_source_rgb(cr_1, 0, 0, 0);
	cairo_select_font_face(cr_1, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr_1, 40.0);
	cairo_set_line_width (cr_1, 2.0);



		//srand (time(NULL));
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
				addEdge(gmObj.points[start_index],gmObj.points[randNumber]);
				countNodesTree++;
			}
			else if(countNodesTree > 0)
			{
				//cout<<"\ngmObj.points[start_index] : "<<nearestIndex<<"--("<<gmObj.points[nearestIndex].getX()<<", "<<gmObj.points[nearestIndex].getY()<<")";
				//cout<<"\ngmObj.points[randNumber] : "<<randNumber<<"--"<<gmObj.points[randNumber].getX()<<", "<<gmObj.points[randNumber].getY()<<")";
				nearestIndex = getNearestNodeIndex(gmObj.points[randNumber]);
				addEdge(gmObj.points[nearestIndex],gmObj.points[randNumber]);
				countNodesTree++;
			}


			  cairo_arc(cr_1, gmObj.points[nearestIndex].getX(), gmObj.points[nearestIndex].getY(), 0.5 , 0 , 2 * 3.14);
			  cairo_arc(cr_1, gmObj.points[randNumber].getX(), gmObj.points[randNumber].getY(), 0.5 , 0 , 2 * 3.14);
			  cairo_stroke(cr_1);

		}
		cairo_surface_write_to_png(surface_1, "tree.png");
		return treeEdges;
}


bool GraphEdge::isElementPresent(int num)
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

std::vector<std::vector<GPoint> > GraphEdge::getTreeToMain()
{
	return treeEdges;
}


/*
GraphEdge::GraphEdge() {
	// TODO Auto-generated constructor stub

}

GraphEdge::~GraphEdge() {
	// TODO Auto-generated destructor stub
}*/

} /* namespace std */
