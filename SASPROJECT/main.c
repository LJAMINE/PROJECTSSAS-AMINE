#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "function.h"


//new commit
int main()
{
int choix;

  do{
        printf("| |         BIENVENUE A VOTRE ESPACE ETUDIANTS                      |     |\n");
        printf("| -----------------------------------------------------------      |\n");
        printf("| -----------------------------------------------------------      |\n");

        printf("| |--------------[ menu principal]-----------------|               |\n");

        printf(" 1 :ajoute Etudiant.                                                |\n");
        printf(" 2 : afficher Etudiant                                         .   |\n");
        printf(" 3 :modifier  etudiant .                                          |\n");
        printf(" 4 : supprimerEtudiant                                             |\n");
        printf(" 5 :  moyenneGenerale  .                                           |\n");
        printf(" 6 : statistiques.                                                      |\n");
        printf(" 7 : rechercheEtudiantparnom.                                                      |\n");
        printf(" 8 : quitter.                                                      |\n");


            printf("\nChoisir une option : ");
            scanf("%d",&choix);

    switch(choix)
    {
        case 1 :
            ajouterEtudiant();
            break;
       case 2 :
            afficherEtudiant();
            break;

        case 3 :
            modifierEtudiant() ;
            break;

             case 4 :
            supprimerEtudiant() ;
            break;



       case 5:
             moyenneGenerale();
      break;


     case 6 :
             statistiques();
    break;


         case 7 :
             rechercheEtudiantparnom();
    break;






    }

}while(choix!=9 );






    return 0;}












