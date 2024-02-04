#include "../include/point.h"

float distance(Point pt1, Point pt2)
{
	float dx = pt1.x - pt2.x;
	float dy = pt1.y - pt2.y;
	return sqrt(dx*dx+dy*dy);
}

Point pointAleatoire(Point sommet1, Point sommet2)
{
	Point p;
	p.x = sommet1.x + (rand()/(float)RAND_MAX)*(sommet2.x-sommet1.x);
	p.y = sommet1.y + (rand()/(float)RAND_MAX)*(sommet2.y-sommet1.y);
	return p;
}
