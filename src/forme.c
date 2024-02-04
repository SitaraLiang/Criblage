#include "../include/forme.h"
#include "../include/appartenance.h"

Forme *nouveauCercle(Point centre, float rayon)
{
    Forme *forme = malloc(sizeof(Forme));
    forme->pointEstDedans = estDansCercle;
    forme->type = CERCLE;
    forme->cercle.centre = centre;
    forme->cercle.rayon = rayon;
    return forme;
}

Forme *nouveauRectangle(Point sommet1, Point sommet2)
{
    Forme *forme = malloc(sizeof(Forme));
    forme->pointEstDedans = estDansRectangle;
    forme->type = RECTANGLE;
    forme->rectangle.sommet1 = sommet1;
    forme->rectangle.sommet2 = sommet2;
    return forme;
}

Forme *nouvelleUnion()
{
    Forme *forme = malloc(sizeof(Forme));
    forme->pointEstDedans = estDansUnion;
    forme->type = UNION;
    forme->unionFormes.nbFormes = 0;
    return forme;
}

Forme *ajouterForme(Forme *unionFormes, Forme *forme)
{
    // on peut ajouter que pour le type d'unionFormes 
    if (unionFormes->type != UNION) {
        printf("Erreur: la forme n'est pas une union\n");
        exit(1);
    }
    // if outofbound
    if (unionFormes->unionFormes.nbFormes >= NB_MAX_FORMES) {
        printf("Erreur: trop de formes dans l'union\n");
        exit(1);
    }
    // i++ : lire puis increment
    unionFormes->unionFormes.formes[unionFormes->unionFormes.nbFormes++] = forme;
    return unionFormes;
}

void libererForme(Forme *forme)
{
    if (forme->type == UNION) {
        for (int i = 0; i < forme->unionFormes.nbFormes; i++) {
            libererForme(forme->unionFormes.formes[i]);
        }
    }
    free(forme);
}
