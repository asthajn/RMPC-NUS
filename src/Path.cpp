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

namespace std {


Path::Path(int start_index, int goal_index, GraphEdge geObj, GridMap gmObj, std::vector<std::vector<GPoint> > treeEdges,int treeSize) {
	// TODO Auto-generated constructor stub
//	cout<<"\nPath class constructor called";
	cout.flush();
	this->start = start_index;
	this->goal = goal_index;
	this->geObject = geObj;
	this->gmObject = gmObj;
	this->treeEdgesPath = treeEdges;
	this->treeSize = treeSize;
 //  cout<<"\nPath class constructor EXITING";
	cout.flush();

}

/*Path::~Path() {

}*/

int Path::connectStartToTree(GPoint startPnt, GPoint goalPnt)
{
	this->path.push_back(goalPnt);
	isStartPntPresent = geObject.isPointPresent(startPnt, 10000);
	isGoalPntPresent = geObject.isPointPresent(goalPnt, 10000);
	if(isStartPntPresent)
	{
		this->start = geObject.getIndex(startPnt);

	}
	else
	{
		this->start = geObject.getNearestNodeIndex(startPnt);
		this->startPnt = startPnt;
		appendStartFlag = true;
	}

	if(isGoalPntPresent)
	{
		this->goal = geObject.getIndex(goalPnt);
		return this->goal;
	}
	else
	{
		this->path.push_back(goalPnt);
		this->goal = geObject.getNearestNodeIndex(goalPnt);
		return this->goal;
	}


}



/*Function to generate path from tree between a given start and end node*/
void Path::getPath(int goal_idx)
{
	cout<<"\n Inside getPath function";
	cout.flush();

		this->path.push_back(gmObject.points[goal_idx]);
		for(int i = 0;i<this->treeSize;i++)
		{
			//cout<<"\n Value of goal index passed is : "<<goal_index;
			//cout<<"\nLength of treeEdgePath at i = "<<i<<" is "<<geObject.getLength(treeEdgesPath[i]);
			cout.flush();
			len =  geObject.getLength(treeEdgesPath[i]);
			if(len!=0)
			{
				for(int j=0;j<len;j++){
					if(gmObject.points[goal_idx] == treeEdgesPath[i][j])
					{
						if(i == this->start)
						{
							this->path.push_back(gmObject.points[i]);
							if(appendStartFlag){
								this->path.push_back(startPnt);
							}
							return;
						}
						for (int m =0;m<len;m++){
							if(treeEdgesPath[i][m]==gmObject.points[this->start]){
								this->path.push_back(gmObject.points[i]);
								this->path.push_back(treeEdgesPath[i][m]);
								return;
							}
						}
						//this->path.push_back(gmObject.points[i]);
						getPath(i);
					}
				}
			}
		}
}

int pathLengh = 0;
void Path::printPath()
{
	cout<<"\nPath length is : "<<geObject.getLength(this->path);
	cout.flush();
	cout<<"\nPATH IS \n";
	cout.flush();
	for(vector<GPoint>::iterator it = this->path.begin();it!=this->path.end();it++)
	{
		cout<<"("<<(*it).getX()<<", "<<(*it).getY()<<") --> ";
		pathLengh++;
	}
	cout<<"\npathLength : "<<pathLengh;

	cout<<"\nStart node : ("<<gmObject.points[start].getX()<<", "<<gmObject.points[start].getY()<<")";
	cout<<"\nGoal node : ("<<gmObject.points[goal].getX()<<", "<<gmObject.points[goal].getY()<<")\n";
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
		  cairo_arc(cr_2, path[i].getX(), path[i].getY(), 0.5 , 0 , 2 * 3.14);
	  }
	cairo_stroke(cr_2);
	cairo_surface_write_to_png(surface_2, "path.png");
}


} /* namespace std */
