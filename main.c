#include <stdio.h>
#include <stdlib.h>


typedef struct Joueur
{
    int PM, PA, PV;
    int classe;
    int numJoueur;
}t_joueur;

void enregistrementDonneesJoueurs(t_joueur Joueur[]);
void InitStructure(t_joueur Joueur[]);
void renduDonneesJoueurs(t_joueur Joueur[]);


int main()
{
    t_joueur Joueur[3];
    InitStructure(Joueur);
    enregistrementDonneesJoueurs(Joueur);
    renduDonneesJoueurs(Joueur);
    return 0;
}



void InitStructure(t_joueur Joueur[])
{

    Joueur[0].PM = 3;
    Joueur[0].PA = 5;
    Joueur[0].PV = 150;
    Joueur[0].classe;
    Joueur[0].numJoueur = 1;

    Joueur[1].PM = 3;
    Joueur[1].PA = 5;
    Joueur[1].PV = 150;
    Joueur[1].classe;
    Joueur[1].numJoueur = 2;

    Joueur[2].PM = 3;
    Joueur[2].PA = 5;
    Joueur[2].PV = 150;
    Joueur[2].classe;
    Joueur[2].numJoueur = 3;

    Joueur[3].PM = 3;
    Joueur[3].PA = 5;
    Joueur[3].PV = 150;
    Joueur[3].classe;
    Joueur[3].numJoueur = 4;
}



void enregistrementDonneesJoueurs(t_joueur Joueur[])
{
    FILE* fp = fopen("Data.txt", "w");

    if(fp == NULL)
    {
        printf("erreur de fichier");
    }

    for(int i =1; i<5; i++)
    {
    fprintf(fp,"%d", Joueur[i].PM);
    fprintf(fp,"%d", Joueur[i].PA);
    fprintf(fp,"%d", Joueur[i].PV);
    }

    printf("donnees enregistrees : \n");

    for(int i =0; i<4; i++)
    {
    printf("%d\n", Joueur[i].PM);
    printf("%d\n", Joueur[i].PA);
    printf("%d\n", Joueur[i].PV);
    }

fclose(fp);
fp = NULL;
}

void renduDonneesJoueurs(t_joueur Joueur[])
{
    FILE* fp = fopen("Data.txt", "r");

    if(fp == NULL)
    {
        printf("erreur de fichier");
    }

    for(int i =0; i<4; i++)
    {
    fscanf(fp,"%d", &Joueur[i].PM);
    fscanf(fp,"%d", &Joueur[i].PA);
    fscanf(fp,"%d", &Joueur[i].PV);

    printf("Points de mouvement du joueur %d : [%d]\n",i+1, Joueur[i].PM);
    printf("Points d'attaque du joueur %d : [%d]\n",i+1, Joueur[i].PA);
    printf("Points de vie du joueur %d : [%d]\n",i+1, Joueur[i].PV);
    }

}
