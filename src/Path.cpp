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
#include <cairo/cairo.h>
#include <string>

namespace std {
int temp1 = 1;

GraphEdge geObject(temp1, temp1);
GridMap gmObject(temp1);
Path::Path(int start_index, int goal_index, GraphEdge geObj, GridMap gmObj, std::vector<std::vector<GPoint> > treeEdges,int treeSize, int numberOfSamples) {
	// TODO Auto-generated constructor stub
	cout<<"\nPath class constructor called";
	cout.flush();
	this->start = start_index;
	this->goal = goal_index;
	geObject = geObj;
	gmObject = gmObj;
	this->treeEdgesPath = treeEdges;
	this->treeSize = treeSize;
	this->numberOfSamples = numberOfSamples;
 //  cout<<"\nPath class constructor EXITING";
	cout.flush();

}

/*Path::~Path() {

}*/

int Path::connectStartToTree(GPoint startPnt, GPoint goalPnt, GraphEdge geObj1, GridMap gm2)
{
	//this->path.push_back(goalPnt);
	isStartPntPresent = geObj1.isPointPresent(startPnt, 10000, gm2);
	isGoalPntPresent = geObj1.isPointPresent(goalPnt, 10000, gm2);

	cout<<"\n***isGoalPntPresent  : "<<isGoalPntPresent<<"\n";
	if(isStartPntPresent)
	{
		this->start = geObj1.getIndex(startPnt,gm2);
		cout<<"\nisStartPntPresent  : "<<isStartPntPresent<<"\n";
	}
	else
	{
		this->start = geObj1.getNearestNodeIndex(startPnt);
		this->startPnt = startPnt;
		appendStartFlag = true;
	}

	if(isGoalPntPresent)
	{
		this->goal = geObj1.getIndex(goalPnt,gm2);
		cout<<"\n Goal is present";
		return this->goal;
	}
	else
	{
		this->path.push_back(goalPnt);
		this->goal = geObj1.getNearestNodeIndex(goalPnt);
		cout<<"\nNearest goal index received is : "<<goal;
		return this->goal;
	}


}


/*Function to generate path from tree between a given start and end node*/
void Path::getPath(int goal_idx, GraphEdge geObj2, GridMap gm1, std::vector<std::vector<GPoint> > treeEdgesPath)
{
	cout<<"\n Inside getPath function. Start is :"<<this->start<<"\n";
	//cout.flush();
	cout<<"\nPoint being added to path is "<<gm1.points[goal_idx].getX()<<"--"<<gm1.points[goal_idx].getY();
	this->path.push_back(gm1.points[goal_idx]);
	for(int i = 0;i<this->treeSize;i++)
	{
		//cout<<"\n Value of goal index passed is : "<<goal_idx;
		//cout<<"\nLength of treeEdgePath at i = "<<i<<" is "<<geObject.getLength(treeEdgesPath[i]);
		cout.flush();
		len =  geObj2.getLength(treeEdgesPath[i]);
		if(len!=0)
		{
			for(int j=0;j<len;j++){
				if(gm1.points[goal_idx] == treeEdgesPath[i][j])
				{
					if(i == this->start)
					{
						cout<<"\nStart goal found in the tree"<<this->start;
						this->path.push_back(gm1.points[i]);
						if(appendStartFlag){
							this->path.push_back(startPnt);
						}
						return;
					}
					for (int m =0;m<len;m++){
						if(treeEdgesPath[i][m]==gm1.points[this->start]){
							cout<<"\nSuccessor condition found";
							this->path.push_back(gm1.points[i]);
							this->path.push_back(treeEdgesPath[i][m]);
							return;
						}
					}
					//this->path.push_back(gmObject.points[i]);
					getPath(i,geObj2,gm1, treeEdgesPath);
				}
			}
		}
	}
}

int pathLengh = 0;
void Path::printPath(GraphEdge geObj, GridMap gmObj)
{
	cout<<"\nPath length is : "<<geObj.getLength(this->path);
	cout.flush();
	cout<<"\nPATH IS \n";
	cout.flush();
	for(vector<GPoint>::iterator it = this->path.begin();it!=this->path.end();it++)
	{
		cout<<"("<<(*it).getX()<<", "<<(*it).getY()<<") --> ";
		pathLengh++;
	}
	cout<<"\npathLength : "<<pathLengh;

	cout<<"\nStart node : ("<<gmObj.points[start].getX()<<", "<<gmObj.points[start].getY()<<")";
	cout<<"\nGoal node : ("<<gmObj.points[goal].getX()<<", "<<gmObj.points[goal].getY()<<")\n";
	cairo_surface_t *surface_2;
	cairo_t *cr_2;

	surface_2 = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,500, 500);
	cr_2 = cairo_create(surface_2);

	cairo_set_source_rgb(cr_2, 0, 0, 0);
	cairo_select_font_face(cr_2, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr_2, 40.0);

	cairo_set_line_width (cr_2, 2.0);
	for (int i=0; i<pathLengh; i++)
	  {
		  cairo_arc(cr_2, this->path[i].getX(), this->path[i].getY(), 0.5 , 0 , 2 * 3.14);
	  }
	cairo_stroke(cr_2);
	cairo_surface_write_to_png(surface_2, "path.png");
}


} /* namespace std */
