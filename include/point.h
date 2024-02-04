#ifndef __POINT_H__
#define __POINT_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point;

typedef struct Point Point;

struct Point 
{
  float x;
  float y;
};

Point pointAleatoire(Point sommet1, Point sommet2);
float distance(Point pt1, Point pt2);

#endif // __POINT_H__
