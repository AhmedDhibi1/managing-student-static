#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include "structure.h"

typedef struct etd{
    char nom[25];
    char prenom[25];
    ADRESSE adresse;
    NOTE tab_notes[5] ;
    float moyenne;
}ETUDIANT;
ETUDIANT Lire_etudiant();
void Afficher_Etudiant(ETUDIANT E);
void Lire_Tab_etudiant(ETUDIANT tab_E[],int *N);
void Affiche_Tab_etudiant (ETUDIANT * Tab_Etud, int N) ;
int Rechercher_etudiant(ETUDIANT Tab_Etud, int N);
void modifier_etudiant(ETUDIANT *E);
void supprimer_etudiant(ETUDIANT Tab_Etud, int* N , int indice);

#endif // ETUDIANT_H_INCLUDED
