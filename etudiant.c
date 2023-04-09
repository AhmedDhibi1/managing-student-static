#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"

ETUDIANT Lire_etudiant()
{
    ETUDIANT E;
    float totcoef=0,totnotcoef=0;
    int i=0;
    printf("\n Intoduire le nom  ");
    scanf("%s",E.nom );
    printf ("\n Introduire le prenom  ");
    scanf("%s",E.prenom );
    printf("\n Introduire l'adresse  ");
    scanf ("%s %s %d",E.adresse.ville,E.adresse.rue,&E.adresse.codepostale);
    for (i=0;i<5;i++)
    {
        do{
            printf ("\n donner les notes des matieres :%d pour etudiant :  " ,i+1);
            scanf ("%s %f %d",E.tab_notes[i].matiere,&E.tab_notes[i].note,&E.tab_notes[i].coeff);
            if(0>E.tab_notes[i].note ||  20<E.tab_notes[i].note) printf(" \n ERREUR : valeur de la note inconvenable!! ");
        }while(E.tab_notes[i].note<0 || E.tab_notes[i].note>20);

    }
    for (i=0;i<5;i++)
    {
        totnotcoef+=E.tab_notes[i].note*E.tab_notes[i].coeff;
        totcoef+=E.tab_notes[i].coeff;
    }
    E.moyenne=totnotcoef/totcoef;
    return E ;
}
void Afficher_Etudiant(ETUDIANT E)
{
    printf("\n\n le nom est : %s",E.nom);
    printf("\n le prenom est : %s",E.prenom);
    printf("\n l'adresse est: %s  %s  %d",E.adresse.ville,E.adresse.rue,E.adresse.codepostale);
    printf("\n %f",E.moyenne);
    for ( int i=0;i<5;i++)
    {
        printf("\n la matiere%d : %s %f %d",i+1,E.tab_notes[i].matiere,E.tab_notes[i].note,E.tab_notes[i].coeff);
    }
}
  void Lire_Tab_etudiant (ETUDIANT Tab_Etud[],int* N)
{
    char rep[13];
    do{
            Tab_Etud[*N]=Lire_etudiant();
            *N=(*N)+1;
            printf("\n voulez vous ajouter un autre etudiant oui/non :  ");
            scanf("%s",rep);
    }while (strcmp(rep,"oui")==0);

}
 void Affiche_Tab_etudiant (ETUDIANT* Tab_Etud, int N)
 {
     int i=0;
     for(i=0;i<N;i++)
        Afficher_Etudiant(Tab_Etud[i]);
 }
 int Rechercher_etudiant(ETUDIANT Tab_Etud, int N)
{
    int rech=-1 ,i;
    char nomrech[25],prenomrech[25];
    printf("\n introduire le nom et le prenom de l'etudiant à rechercher :");
    scanf("%s %s",nomrech,prenomrech);
    for(i=0;i<N;i++)
        {
        if(strcmp(Tab_Etud[i].nom,nomrech)==0&& strcmp(Tab_Etud[i].prenom,prenomrech)==0)
        {
            return i;
        }

        }
    return -1;
}
void modifier_etudiant(ETUDIANT *E)
{
    int choix ,n ,i ,totcoef=0;
    float totnotcoef=0;
    ETUDIANT Etd ;
    Etd=*E
    printf("\n que voulez vous modifier :");
    printf("\n 1-nom et prenom");
    printf("\n 2-adresse");
    printf("\n 3-la note");
    printf("\n 0-quitter");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
        {
            scanf("%s",Etd.nom);
            scanf("%s",Etd.prenom);
            break;
        }
    case 2:
        {
            ("\n introduire l'adresse ,rue ville , code postale:");
            scanf("%s %s %d",Etd.adresse.rue,Etd.adresse.ville,&Etd.adresse.codepostale);

        }
    case 3:
        {
            do
            {


            printf("\n introduire l'indice de note a modifier(1..5)");
            scanf("%d",&n);
            }while(n<1||n>5);
            printf("\n %d : introduire matiere coef note",n);
            scanf("%s %d %f",Etd.tab_notes[n-1].matiere,Etd.tab_notes[n-1].coeff,Etd.tab_notes[n-1].note);
            for(i=0 ; i<5 ;i++)
            {
                totnotcoef+=Etd.tab_notes[i].note*Etd.tab_notes[i].coeff;
                totcoef+=Etd.tab_notes[i].coeff;
            }
            Etd.moyenne=totnotcoef/totcoef;
            break;
        }
    case 0:
        {
            break;
        }
    default:
        printf("\n choix erroné");
    }
    *E=Etd;
}
void supprimer_etudiant(ETUDIANT Tab_Etud, int* N , int indice)
{
    int i;
    for(i=0 ; i<(*N)-1 ;i++)
    {
        Tab_Etud[i]=Tab_Etud[i+1];
    }
    *N=(*N)-1;
}
