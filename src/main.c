#include "../include/affichage.h"
#include "../include/criblage.h"

int main()
{
    // Initialisation du générateur de nombres aléatoires
    srand(0);

    // Création des formes
    Forme *forme1 = nouveauCercle((Point){0, 0}, 1);
    Forme *forme2 = nouvelleUnion();
    forme2 = ajouterForme(forme2, nouveauCercle((Point){1, 1}, 1));
    forme2 = ajouterForme(forme2, nouveauRectangle((Point){-1, -1}, (Point){-0.5, -0.5}));

    // Affichage de l'espace
    afficherEspace(forme1, forme2, (Point){-2, -2}, (Point){3, 3}, 60, 30);

    // Calcul da la surface de l'intersection
    float surfaceIntersection = calculIntersection(forme1, forme2, &(Rectangle){(Point){-2, -2}, (Point){2, 2}}, 1000000);

    printf("Aire de l'intersection: %f\n", surfaceIntersection);

    // Libération de la mémoire
    libererForme(forme1);
    libererForme(forme2);

    return 0;
}
