#ifndef HEPERS_H_INCLUDED
#define HEPERS_H_INCLUDED
/*
 //-------------------------------------affiche Total etudiant function------------------------------------------

void affichTotaletudiant() {
    printf("total etudiants %d\n", nombreEtudiant);
}


//------------------------------------- affiche Eudiant par departmant function------------------------------------------

void afficheEudianpardepartmant() {
    int counts[5] = {0};
    char departmentNames[5][100];
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
        printf("%s; %d etuudiants \n", departmentNames[i], counts[i]);
    }
}



//-------------------------------------affiche trois Meilleures notes function------------------------------------------


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


//-------------------------------------affichage Etudiant Reeussi Par departemnt function------------------------------------------


void afficheEtudiantReeussiPardepartemnt() {
    int counts[5] = {0};
    char departmentNames[5][100];
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


#endif // HEPERS_H_INCLUDED
*/
