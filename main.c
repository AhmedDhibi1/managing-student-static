#include <stdio.h>
#include <stdlib.h>
#include "etudiant.c"
int main()
    {


    int taille=0 , choix=0 , rech=-1;
    ETUDIANT E , tab_E[30];
    char rep[3];
    while(1){
    printf("**********************\n");
    printf("          MENU        \n");
    printf("**********************\n");
    printf("1-saisir un etudiant :\n");
    printf("2-saisir un ensemble d'etudiant :\n" );
    printf("3-afficher un ensemble d'etudiant :\n");
    printf("4-Rechercher un etudiant");
    printf("5-Modifier un etudiant");
    printf("6-Supprimer un etudiant");
    printf("0_quitter");
    printf("introduire le choix :");
    scanf("%d",&choix);
    int n;
    switch (choix)
    {
    case 1:

        E=Lire_etudiant();
        Afficher_Etudiant(E);
        break;
    case 2:

        Lire_Tab_etudiant( tab_E,&taille);
        break;
    case 3:

        Affiche_Tab_etudiant(tab_E, taille);
        break;
    case 4:(rech=Rechercher_etudiant(tab_E,taille);
            if (rech==-1)
            {
                printf("\n etudiant non existant");
            }
            else
            {
                Afficher_Etudiant(tab_E[rech]);
            }
            break;
    case 5:(rech=Rechercher_etudiant(tab_E,taille);
            if (rech==-1)
            {
                printf("\n etudiant non existant");
            }
            else
            {
                Afficher_Etudiant(tab_E[rech]);
                printf("\n vous etes sure de vouloir modifier cet etudiant");
                scanf("%s",rep);
                if (strcmp(rep,"oui")==0
                    {
                        modifier_etudiant(&tab_E[rech]);
                    }
            }
            break;
    case 6:(rech=Rechercher_etudiant(tab_E,taille);
            if (rech==-1)
            {
                printf("\n etudiant non existant");
            }
            else
            {
                Afficher_Etudiant(tab_E[rech]);
                printf("\n vous etes sure de vouloir supprimer cet etudiant");
                scanf("%s",rep);
                if (strcmp(rep,"oui")==0
                    {
                       supprimer_etudiant(tab_E,&taille,rech);
                    }
            }
            break;


        exit(0);
    default:
        printf("selectionner un choix :%d",choix);


    }
    }


}
