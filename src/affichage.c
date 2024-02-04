#include "../include/affichage.h"

// Afficher dans la console l'espace
// resolution: nombre de points en largeur et en hauteur
// ' ' si rien de particulier, '1' si appartient à la forme 1, '2' si appartient à la forme 2, 'x' si appartient aux deux (à l'instersection)
void afficherEspace(Forme *forme1, Forme *forme2, Point pointMin, Point pointMax, int resolutionX, int resolutionY)
{
    float pasX = (pointMax.x - pointMin.x) / resolutionX;
    float pasY = (pointMax.y - pointMin.y) / resolutionY;
    for (int i = 0; i < resolutionY; i++)
    {
        for (int j = 0; j < resolutionX; j++)
        {
            // most important line:
            Point point = {pointMin.x + j * pasX + pasX / 2, pointMin.y + i * pasY + pasY / 2};
            
            bool estDansForme1 = forme1->pointEstDedans(point, forme1);
            bool estDansForme2 = forme2->pointEstDedans(point, forme2);
            if (estDansForme1 && estDansForme2)
            {
                printf("x");
            }
            else if (estDansForme1)
            {
                printf("1");
            }
            else if (estDansForme2)
            {
                printf("2");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
