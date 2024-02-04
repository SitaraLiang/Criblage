#ifndef __APPARTENANCE_H__
#define __APPARTENANCE_H__

#include <stdbool.h>

#include "forme.h"

bool estDansCercle(Point point, Forme *forme);
bool estDansRectangle(Point point, Forme *forme);
bool estDansUnion(Point point, Forme *forme);

#endif // __APPARTENANCE_H__
