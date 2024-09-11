#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#define MAX_DEPARTMENTS 5



struct Departement {
    char nom[50];
    float noteGenerale;
};
typedef struct Etudiant{
int  nemuroUnique ;
 char nom[100];
 char prenom[100];
 char date_Naissance[100];
  int nombreDepartements;
  struct Departement departement;
  };



#endif // STRUCTURE_H_INCLUDED
