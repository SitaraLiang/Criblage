#include "criblage.h"

// Tirer au hasard nbTirages
// Compter combien sont dans l'intersetion
// En déduire une estimation de la surface de l'intersection
float calculIntersection(Forme *forme1, Forme *forme2, Rectangle *espaceCrible, int nbTirages)
{
    int nbDansIntersection = 0;
    for (int i = 0; i < nbTirages; i++)
    {
        Point point = pointAleatoire(espaceCrible->sommet1, espaceCrible->sommet2);
        if (forme1->pointEstDedans(point, forme1) && forme2->pointEstDedans(point, forme2))
        {
            nbDansIntersection++;
        }
    }
    float surfaceEspaceCrible = (espaceCrible->sommet2.x - espaceCrible->sommet1.x) * (espaceCrible->sommet2.y - espaceCrible->sommet1.y);
    float surfaceIntersection = surfaceEspaceCrible * nbDansIntersection / nbTirages;
    return surfaceIntersection;
}
