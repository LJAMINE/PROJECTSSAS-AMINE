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
        printf("  %d non trouve.\n", numeroRechercher);
    }
}

void moyenneGenerale() {

    float totalNotes[MAX_DEPARTMENTS] = {0};  // Stocke la somme note a chaque depar
    int counts[MAX_DEPARTMENTS] = {0};        // Stocke   nombre etudiant dans chaque depar
    char departmentNames[MAX_DEPARTMENTS][100];  // Stocke les noms des depar
    int numDepartments = 0;

 //etudiant
     for (int i = 0; i < nombreEtudiant; i++) {
        int found = 0;
        //  depart deetudiant est deja enrogistree
        for (int j = 0; j < numDepartments; j++) {
            if (strcmp(etudiants[i].departement.nom, departmentNames[j]) == 0) {
                // if   depar est trouve ajoutih a a département
                totalNotes[j] += etudiants[i].departement.noteGenerale;
                counts[j]++;
                found = 1;
                break;
            }
        }
        // if depart pas trouvee , ajouter a liste
        if (!found) {
            strcpy(departmentNames[numDepartments], etudiants[i].departement.nom);
            totalNotes[numDepartments] = etudiants[i].departement.noteGenerale;
            counts[numDepartments] = 1;
            numDepartments++;
        }
    }

    // Calcul et affichage des moyennes pour chaque département
    printf("moye generale par depart :\n");
    for (int i = 0; i < numDepartments; i++) {
        printf("departenemet %s : Moyenne = %.2f\n", departmentNames[i], totalNotes[i] / counts[i]);
    }

    // Calcul de la moyen generale de universite
    float totalNotesUniversite = 0;
    int totalCountUniversite = 0;
    for (int i = 0; i < numDepartments; i++) {
        totalNotesUniversite += totalNotes[i];  // Total des notes pour l'université entière
        totalCountUniversite += counts[i];      // Total des étudiants
    }

    // affichir moyen generale de universite
    if (totalCountUniversite > 0) {
        printf("Moyenne genrale de l'universite : %.2f\n", totalNotesUniversite / totalCountUniversite);
    } else {
        printf("no etudiat trouve.\n");
    }
}



/*

void moyenneGenerale() {
    float totalNotes[MAX_DEPARTMENTS] = {0};  // TOTAL NOTE POUR CHAQUE DEPATR
    int counts[MAX_DEPARTMENTS] = {0};        // ETUDUANT CHAQUE DEPART
    char departmentNames[MAX_DEPARTMENTS][100];  //   department names
    int numDepartments = 0;

    // tous etudiant
    for (int i = 0; i < nombreEtudiant; i++) {
        // chaque depart de etudiants
        for (int j = 0; j < etudiants[i].nombreDepartements; j++) {
            int found = 0;
            // cheki ila depaerement counted ou non
            for (int k = 0; k < numDepartments; k++) {
                if (strcmp(etudiants[i].departements[j].nom, departmentNames[k]) == 0) {
                    // ajouti note aux total du departemen
                    totalNotes[k] += etudiants[i].departements[j].noteGenerale;
                    counts[k]++;
                    found = 1;
                    break;
                }
            }
            //ila departement no count, ajouti au list
            if (!found) {
                strcpy(departmentNames[numDepartments], etudiants[i].departements[j].nom);
                totalNotes[numDepartments] = etudiants[i].departements[j].noteGenerale;
                counts[numDepartments] = 1;
                numDepartments++;
            }
        }
    }

    // moy note pou chaque depart
    printf("Moyenne genra par departemenr :\n");
    for (int i = 0; i < numDepartments; i++) {
        printf("depart %s : moyenne = %.2f\n", departmentNames[i], totalNotes[i] / counts[i]);
    }

    // calcul moyen de universite
    float totalNotesUniversite = 0;
    int totalCountUniversite = 0;
    for (int i = 0; i < numDepartments; i++) {
        totalNotesUniversite += totalNotes[i];
        totalCountUniversite += counts[i];
    }

    if (totalCountUniversite > 0) {
        printf("Moyenne gener de universitte : %f\n", totalNotesUniversite / totalCountUniversite);
    } else {
        printf("etudiant ps trouvee.\n");
    }
}
 /*

void affichTotaletudiant() {
    printf("total etudiants %d\n", nombreEtudiant);
}

void afficheEudianpardepartmant() {
    int counts[MAX_DEPARTMENTS] = {0};
    char departmentNames[MAX_DEPARTMENTS][100];
    int numDepartments = 0;

    for (int i = 0; i < nombreEtudiant; i++) {
        for (int j = 0; j < etudiants[i].nombreDepartements; j++) {
            int found = 0;
            for (int k = 0; k < numDepartments; k++) {
                if (strcmp(etudiants[i].departements[j].nom, departmentNames[k]) == 0) {
                    counts[k]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(departmentNames[numDepartments], etudiants[i].departements[j].nom);
                counts[numDepartments]++;
                numDepartments++;
            }
        }
    }

    printf("Nombre etidiant pour chaque depart :\n");
    for (int i = 0; i < numDepartments; i++) {
        printf("%s , %d etuduant\n", departmentNames[i], counts[i]);
    }
}

void affichEtudiantseiul(float seuil) {
    printf("etudiant a moy genrale superieur >= %.2f :\n", seuil);
    for (int i = 0; i < nombreEtudiant; i++) {
        float moyenne = 0;
        for (int j = 0; j < etudiants[i].nombreDepartements; j++) {
            moyenne += etudiants[i].departements[j].noteGenerale;
        }
        moyenne /= etudiants[i].nombreDepartements;

        if (moyenne > seuil) {
            printf("nom : %s, prenom : %s, Moyenne : %.2f\n", etudiants[i].nom, etudiants[i].prenom, moyenne);
        }
    }
}
void statistiques() {
    int choix;
    float seuil;

    printf("1 :  afficha   nombre total etudiant inscrits\n");
    printf("2 : Afficher   nombre etudiant dans chaque departement.\n");
    printf("3 : Afficher   etudiant ayant une moyenne genera superieur A un certain seuil\n");
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

        default:
            printf("Option invalide.\n");
            break;
    }
}


void rechercheEtudiantparnom() {
    char nomRecherche[100];
    int etudiantTrouve = 0;

    printf("entrer nom : ");
    scanf("%s", nomRecherche);

    for (int i = 0; i < nombreEtudiant; i++) {
        if (strcmp(etudiants[i].nom, nomRecherche) == 0) {
            printf("etudian trouvee :\n");
            printf("nemuro unique : %d\n", etudiants[i].nemuroUnique);
            printf("prenom : %s\n", etudiants[i].prenom);
            printf("nom : %s\n", etudiants[i].nom);
            printf("Date de Naissance : %s\n", etudiants[i].date_Naissance);

            for (int j = 0; j < etudiants[i].nombreDepartements; j++) {
                printf("depart : %s, Note genrat : %.2f\n", etudiants[i].departements[j].nom, etudiants[i].departements[j].noteGenerale);
            }

            etudiantTrouve = 1;  //
            break;
        }
    }

    if (!etudiantTrouve) {
        printf("'%s'non trouv.\n", nomRecherche);
    }
}


/*
void rechercherContacts(){
char nomRecherche[100];
  int etudiantTrouve=0;

     printf("entree le nom de etudiant : \n");
    scanf(" %[^\n]", nomRecherche);

    for (int i = 0; i < nombreEtudiant; i++) {
        if (strcmp(etudiants[i].nom, nomRecherche) == 0) {
               printf("etudiant trouvee :\n");
            printf(" Numero Unique : %d\n", etudiants[i].nemuroUnique);
        printf(" Prenom : %s\n", etudiants[i].prenom);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Date de Naissance : %s\n", etudiants[i].date_Naissance);
        printf("Departement : %s\n", etudiants[i].departement);
        printf("Note Generale : %.2f\n", etudiants[i].noteGenerale);
        printf("\n");



 contactTrouve = 1;
            break;

        }

    }


    if (!contactTrouve) {
        printf("contact non trouv.\n");
    }


}
*/
#endif // FUNCTION_H_INCLUDED








