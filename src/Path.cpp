/*
 * Path.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: harshul
 */

#include "Path.h"
#include "GraphEdge.h"
#include "GridMap.h"
#include "gtype.h"
#include "point.h"
#include <vector>

namespace std {


Path::Path(int start_index, int goal_index, GraphEdge geObj, GridMap gmObj, std::vector<std::vector<GPoint> > treeEdges) {
	// TODO Auto-generated constructor stub
	cout<<"\nPath class constructor called";
	cout.flush();
	this->start = start_index;
	this->goal = goal_index;
	this->geObject = geObj;
	this->gmObject = gmObj;
	this->treeEdgesPath = treeEdges;
	cout<<"\nPath class constructor EXITING";
	cout.flush();

}

/*Path::~Path() {

}*/


/*Function to generate path from tree between a given start and end node*/
void Path::getPath(int goal_index)
{
	cout<<"\n Inside getPath function";
	cout.flush();
		for(int i = 0;i<10000;i++)
		{
			//cout<<"\n Value of goal index passed is : "<<goal_index;
			//cout<<"\nLength of treeEdgePath at i = "<<i<<" is "<<geObject.getLength(treeEdgesPath[i]);
			cout.flush();
			if(geObject.getLength(treeEdgesPath[i])!=0)
			{
				len = geObject.getLength(treeEdgesPath[i]);
				for(int j =0;j<len;j++){
					if(gmObject.points[goal_index] == treeEdgesPath[i][j])
					{
						if(i == start)
						{
							this->path.push_back(gmObject.points[i]);
							return;
						}
						this->path.push_back(gmObject.points[i]);
						getPath(i);
					}
				}
			}
		}
}

void Path::printPath()
{
	cout<<"\nPath length is : "<<geObject.getLength(this->path);
	cout.flush();
	cout<<"\nPATH IS \n";
	cout.flush();
	for(vector<GPoint>::iterator it = this->path.begin();it!=this->path.end();it++)
	{
		cout<<"("<<(*it).getX()<<", "<<(*it).getY()<<") --> ";
	}
}
} /* namespace std */
