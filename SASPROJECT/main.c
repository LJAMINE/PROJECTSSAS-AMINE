#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "function.h"
//#include "hepers.h"



//new commit
int main()
{
int choix;

  do{
        printf("| |         BIENVENUE A VOTRE ESPACE ETUDIANTS                            |\n");
        printf("| ----------------------------------------------------------- ------------|\n");
        printf("| -----------------------------------------------------------             |\n");

        printf("| |--------------[ menu principal]-------------------------- ------------ |\n");

        printf(" 1 :  ajoute Etudiant.                                                    |\n");
        printf(" 2 :  afficher Etudiant                                         .         |\n");
        printf(" 3 :  modifier etudiant .                                                 |\n");
        printf(" 4 :  supprimer Etudiant                                                  |\n");
        printf(" 5 :  moyenneG enerale  .                                                 |\n");
        printf(" 6 :  statistiques.                                                       |\n");
        printf(" 7 :  recherche Etudiant par nom.                                         |\n");
        printf(" 8 :  liste Etudiant Inscrit dans departement.                            |\n");
        printf(" 9 : tri Des Etudiants.                                                   |\n");

        printf(" 10 : quitter.                                                            |\n");


            printf("\nChoisir une option :                                                |\n");
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
      case 8 :
             listeEtudiantInscritdansdepartement();
    break;
  case 9 :
             triDesEtudiants();
    break;





    }

}while(choix!=10 );






    return 0;

    }












