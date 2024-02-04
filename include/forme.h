#ifndef __FORME_H__
#define __FORME_H__

#define NB_MAX_FORMES 100

#include <stdbool.h>

#include "point.h"
#include "forme.h"

struct Forme;
struct UnionFormes;
struct Rectangle;
struct Cercle;

typedef struct Forme Forme;
typedef struct UnionFormes UnionFormes;
typedef struct Rectangle Rectangle;
typedef struct Cercle Cercle;

typedef bool (*FctAppartenance)(Point, struct Forme *);

struct Cercle
{
    Point centre;
    float rayon;
};

struct Rectangle
{
    Point sommet1;
    Point sommet2;
};

struct UnionFormes
{
    struct Forme *formes[NB_MAX_FORMES];
    int nbFormes;
};

struct Forme
{
    FctAppartenance pointEstDedans; // un pointeur sur la fonction
    enum {CERCLE, RECTANGLE, UNION} type;
    // on n'a pas besoin d'initialiser l'union
    union
    {
        Cercle cercle;
        Rectangle rectangle;
        UnionFormes unionFormes;
    };
};

Forme *nouveauCercle(Point centre, float rayon);
Forme *nouveauRectangle(Point sommet1, Point sommet2);
Forme *nouvelleUnion();
Forme *ajouterForme(Forme *unionFormes, Forme *forme);
void libererForme(Forme *forme);

#endif // __FORME_H__
