#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

struct Etudiant etudiants[100];
int nombreEtudiant=0;



 int existeDecontact(int verifieNom[]) {
    for (int i = 0; i < nombreEtudiant; i++) {
        if ( etudiants[i].nemuroUnique == verifieNom ) {
            return i;
        }
    }
    return -1;
}

//ajouter Etudiant

 void ajouterEtudiant() {
       if (nombreEtudiant >= MAX_DEPARTMENTS) {
        printf("plein.\n");
        return;
    }
    struct Etudiant newEtudiant;
    int indice;

     printf("Entrez le NUm unique : ");
    scanf("%d", &newEtudiant.nemuroUnique);

     indice = existeDecontact(newEtudiant.nemuroUnique);
    if (indice != -1) {
        printf("etudiant deja existe.\n");
        return;
    }


    printf("Entrez le nom : ");
    scanf("%s", newEtudiant.nom);

    printf("Entrez le prenom : ");
    scanf("%s", newEtudiant.prenom);

    printf("Entrez la date de naissance : ");
    scanf("%s", newEtudiant.date_Naissance);

    printf("Entrez le nom du departement : ");
    scanf("%s", newEtudiant.departement.nom);

    printf("Entrez la note generale pour le departement %s : ", newEtudiant.departement.nom);
    scanf("%f", &newEtudiant.departement.noteGenerale);

    // Add the new student to the list
    etudiants[nombreEtudiant] = newEtudiant;
    nombreEtudiant++;

    printf("etudiant ajoutee.\n");
}



//afficher Etudiant

 void afficherEtudiant() {
    for (int i = 0; i < nombreEtudiant; i++) {
        printf("numero Unique : %d\n", etudiants[i].nemuroUnique);
        printf("prenom : %s\n", etudiants[i].prenom);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Date de Naissance : %s\n", etudiants[i].date_Naissance);
        printf("DEPARTEMENT : %s\n", etudiants[i].departement.nom);
        printf("Note genera : %.2f\n", etudiants[i].departement.noteGenerale);
        printf("\n");
    }
}


//modifier eEtudiant

void modifierEtudiant() {
    int numeroRechercher;
    int etudiantTrouve = 0;

    printf("Entrez le NUM unique POUR MODIFIER : ");
    scanf("%d", &numeroRechercher);

    for (int i = 0; i < nombreEtudiant; i++) {
        if (etudiants[i].nemuroUnique == numeroRechercher) {
            etudiantTrouve = 1;

            printf("new nom : ");
            scanf("%s", etudiants[i].nom);

            printf("new prenom : ");
            scanf("%s", etudiants[i].prenom);

            printf("new date de naissance : ");
            scanf("%s", etudiants[i].date_Naissance);

            printf("new nom du departement : ");
            scanf("%s", etudiants[i].departement.nom);

            printf("new note generale : ");
            scanf("%f", &etudiants[i].departement.noteGenerale);

            printf("Etudiant modifier.\n");
            break;
        }
    }

    if (!etudiantTrouve) {
        printf(" %d non trouvee.\n", numeroRechercher);
    }
}


//supprimer etidiant

 void supprimerEtudiant() {
    int numeroRechercher;
    int etudiantTrouve = 0;

     printf(" entrere numero unique pour supprimer : ");
    scanf("%d", &numeroRechercher);

    for (int i = 0; i < nombreEtudiant; i++) {
        if (etudiants[i].nemuroUnique == numeroRechercher) {
                //trouvee
             etudiantTrouve = 1;

            // move to left pour supprimer
            for (int j = i; j < nombreEtudiant - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }

            // decrementationn sizedu  tableau
            nombreEtudiant--;

            printf("  %d  est supprimee !\n", numeroRechercher);
            break;
        }
    }
    if (!etudiantTrouve) {
        printf("%d non trouve.\n", numeroRechercher);
    }
}

void moyenneGenerale() {


    float totalNotes[MAX_DEPARTMENTS] = {0};  // Stockiw la somme note f  chaque depar O n3toh 0 a chaques elements
    int counts[MAX_DEPARTMENTS] = {0};        // Stockeiw   nombre etudiant f chaque depar chaque depar O n3toh 0 a chaques elements
    char departmentNames[MAX_DEPARTMENTS][100];  // Stockiw les noms des departem
    int numDepartments = 0;

 //etudiant aziz
     for (int i = 0; i < nombreEtudiant; i++) {
        int found = 0;
        //  depart deetudiant est deja enrogistree
        for (int j = 0; j < numDepartments; j++) {
            if (strcmp(etudiants[i].departement.nom, departmentNames[j]) == 0) {
                // if   depar est trouve ajoutih a a departement
                totalNotes[j] += etudiants[i].departement.noteGenerale;
                //incremeter aziz
                counts[j]++;
                found = 1;
                break;
            }
        }
        // if depart pas trouvee , ajouter a liste aziz 2
        if (!found) {
            strcpy(departmentNames[numDepartments], etudiants[i].departement.nom);
            totalNotes[numDepartments] = etudiants[i].departement.noteGenerale;
            counts[numDepartments] = 1;
            numDepartments++;
        }
    }

    // Calcul et affichage des moyennes pour chaque departament
    printf("moyen generale par depart :\n");
    for (int i = 0; i < numDepartments; i++) {
            //moyenne=totNote/counts
        printf("departenemet %s : Moyenne = %.2f\n", departmentNames[i], totalNotes[i] / counts[i]);
    }

    //  moy generale universite
    float totalNotesUniversite = 0;
    int totalCountUniversite = 0;
    for (int i = 0; i < numDepartments; i++) {
        totalNotesUniversite += totalNotes[i];  // Total des notes pour universite
        totalCountUniversite += counts[i];      // Total des étudiants
    }

    //   moyen generale de universite


    if (totalCountUniversite > 0) {
        printf("Moyenne genrale de universite : %.2f\n", totalNotesUniversite / totalCountUniversite);
    } else {
        printf("no etudiat trouve.\n");
    }
}




void affichTotaletudiant() {
    printf("total etudiants %d\n", nombreEtudiant);
}








void afficheEtudiantParDepartement() {
    int counts[MAX_DEPARTMENTS] = {0};
    char departmentNames[MAX_DEPARTMENTS][100];
    int numDepartments = 0;
     for (int i = 0; i < nombreEtudiant; i++) {
        int found = 0;

         for (int k = 0; k < numDepartments; k++) {
            if (strcmp(etudiants[i].departement.nom, departmentNames[k]) == 0) {
                counts[k]++;
                found = 1;
                break;
            }
        }

         if (!found) {
            strcpy(departmentNames[numDepartments], etudiants[i].departement.nom);
            counts[numDepartments] = 1;
            numDepartments++;
        }
    }

     printf("Nombre Etudiant pour chaque departement:\n");
    for (int i = 0; i < numDepartments; i++) {
        printf("%s : %d etudiants\n", departmentNames[i], counts[i]);
    }
}


void affichEtudiantseiul(float seuil) {
    printf("etudiabt avec moyenne general >=  %.2f :\n", seuil);

    for (int i = 0; i < nombreEtudiant; i++) {
         float moyenne = etudiants[i].departement.noteGenerale;

        if (moyenne >= seuil) {
            printf("Nom : %s, prenom : %s, Moyenne : %.2f\n", etudiants[i].nom, etudiants[i].prenom, moyenne);
        }
    }
}

void affichertroisMeilleuresnotes() {
    // tri a bulle methode
    for (int i = 0; i < nombreEtudiant - 1; i++) {
        for (int j = 0; j < nombreEtudiant - i - 1; j++) {
            if (etudiants[j].departement.noteGenerale < etudiants[j + 1].departement.noteGenerale) {
                struct Etudiant temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }

     //if
    int top = (nombreEtudiant < 3 )? nombreEtudiant : 3;
    printf("Les %d meilleurs etudiants sont:\n", top);

    for (int i = 0; i < top; i++) {
        printf("Prenom : %s, Nom : %s, Note Generale : %.2f\n",
               etudiants[i].prenom,
               etudiants[i].nom,
               etudiants[i].departement.noteGenerale);
    }
}

void afficheEtudiantReeussiPardepartemnt() {
    int counts[MAX_DEPARTMENTS] = {0};
    char departmentNames[MAX_DEPARTMENTS][100];
    int numDepartments = 0;

    // tous etudiant d'apres aziz formateur
    for (int i = 0; i < nombreEtudiant; i++) {
        // n chekiw if departement exist
        int found = 0;
        for (int k = 0; k < numDepartments; k++) {
            if (strcmp(etudiants[i].departement.nom, departmentNames[k]) == 0) {
                // si departemt, inccremment fach kay passed the test
                if (etudiants[i].departement.noteGenerale >= 10) {
                    counts[k]++;
                }
                found = 1;
                break;
            }
        }

        // si departemnt not found , ajouti l la liste
        if (!found) {
            strcpy(departmentNames[numDepartments], etudiants[i].departement.nom);
            if (etudiants[i].departement.noteGenerale >= 10) {
                counts[numDepartments] = 1;
            } else {
                counts[numDepartments] = 0;
            }
            numDepartments++;
        }
    }


    printf("nombre  etudiant qui  reussi sur  chaque departement :\n");
    for (int i = 0; i < numDepartments; i++) {
        printf("%s : %d etudiants\n", departmentNames[i], counts[i]);
    }
}


void statistiques() {
    int choix;
    float seuil;

    printf("1 : afficher   nombre total etudiant inscrits\n");
    printf("2 : Afficher   nombre etudiant dans chaque departement.\n");
    printf("3 : Afficher   etudiant ayant une moyenne genera superieur A un certain seuil\n");
    printf("4 : Afficher les 3 etudiants ayant les meilleures notes.\n");
    printf("5 :  Afficher le nombre etudiant qui  reussi  dans chaque departement.\n");

    printf("Choisissez une option : ");
    scanf("%d", &choix);

    switch(choix) {
        case 1:
            affichTotaletudiant();
            break;
        case 2:
            afficheEudianpardepartmant();
            break;

        case 3:
            printf("  le seuil  ");
            scanf("%f", &seuil);
            affichEtudiantseiul(seuil);
            break;
             case 4:
            affichertroisMeilleuresnotes();
            break;

             case 5:
                afficheEtudiantReeussiPardepartemnt();
                break;



        default:
            printf("Option invalide.\n");
            break;
    }
}


void afficheEudianpardepartmant() {
    int counts[MAX_DEPARTMENTS] = {0};
    char departmentNames[MAX_DEPARTMENTS][100];
    int numDepartments = 0;

    //etudiant
    for (int i = 0; i < nombreEtudiant; i++) {
        int found = 0;

        // department
        for (int j = 0; j < numDepartments; j++) {
            if (strcmp(etudiants[i].departement.nom, departmentNames[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }

        // If !found , ajouter au liste
        if (!found) {
            strcpy(departmentNames[numDepartments], etudiants[i].departement.nom);
            counts[numDepartments] = 1;
            numDepartments++;
        }
    }

    //
    printf("Nombre etudiant pour chaque departm:\n");
    for (int i = 0; i < numDepartments; i++) {
        printf("%s : %d etuudiants \n", departmentNames[i], counts[i]);
    }
}

void rechercheEtudiantparnom(){

char  nomrecherer[100];
    int  etudiantTrouve =0;

    printf("Entrez le nom rechercher : ");
    scanf("%s", nomrecherer);

    for (int i = 0; i < nombreEtudiant; i++) {
          if (strcmp(etudiants[i].nom, nomrecherer) == 0) {
            printf("numero Unique : %d\n", etudiants[i].nemuroUnique);
        printf("prenom : %s\n", etudiants[i].prenom);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Date de Naissance : %s\n", etudiants[i].date_Naissance);
        printf("DEPARTEMENT : %s\n", etudiants[i].departement.nom);
        printf("Note genera : %.2f\n", etudiants[i].departement.noteGenerale);
           etudiantTrouve=1;
             break;


}

    }

if (!etudiantTrouve) {
        printf(" %s non trouvee.\n", nomrecherer);
    }
}



#endif // FUNCTION_H_INCLUDED
