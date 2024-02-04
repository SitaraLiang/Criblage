#include "../include/appartenance.h"

bool estDansCercle(Point point, Forme *forme)
{
    Cercle *cercle = &forme->cercle; // Interpreter l'union comme un cercle
    return distance(point, cercle->centre) <= cercle->rayon;
}

bool estDansRectangle(Point point, Forme *forme)
{
    Rectangle *rectangle = &forme->rectangle; // Interpreter l'union comme un rectangle
    return point.x >= rectangle->sommet1.x && point.x <= rectangle->sommet2.x
        && point.y >= rectangle->sommet1.y && point.y <= rectangle->sommet2.y;
}

bool estDansUnion(Point point, Forme *forme)
{
    UnionFormes *unionFormes = &forme->unionFormes; // Interpreter l'union (au sens C) comme une union (au sens mathematique)
    for (int i = 0; i < unionFormes->nbFormes; i++) {
        if (unionFormes->formes[i]->pointEstDedans(point, unionFormes->formes[i])) {
            return true;
        }
    }
    return false;
}
