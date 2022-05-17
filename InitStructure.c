#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "headers.h"


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

void ClasseStructure(t_classe Classe[])
{

    strcpy(Classe[0].nomClasse, "Le sablier de Xelor");
    Classe[0].numClasse = 1;
    strcpy(Classe[0].body, "Coup de poing");
    Classe[0].bodyPA = 1;
    Classe[0].bodyDeg = 7;
    strcpy(Classe[0].sort1, "Aiguille");
    strcpy(Classe[0].sort2, "Frappe de Xelor");
    Classe[0].degSort1 = 12;
    Classe[0].degSort2 = 10;
    Classe[0].sort1PA = 3;
    Classe[0].sort2PA = 2;

    strcpy(Classe[1].nomClasse, "L ombre de Sram");
    Classe[1].numClasse = 2;
    strcpy(Classe[1].body, "Attaque Mortelle");
    Classe[1].bodyPA = 1;
    Classe[1].bodyDeg = 10;
    strcpy(Classe[1].sort1, "Toxines");
    strcpy(Classe[1].sort2, "Eclair de feu");
    Classe[1].degSort1 = 8;
    Classe[1].degSort2 = 11;
    Classe[1].sort1PA = 2;
    Classe[1].sort2PA = 3;

    strcpy(Classe[2].nomClasse, "Le coeur de lop");
    Classe[2].numClasse = 3;
    strcpy(Classe[2].body, "Epee divine");
    Classe[2].bodyPA = 1;
    Classe[2].bodyDeg = 6;
    strcpy(Classe[2].sort1, "Tempete de puissance");
    strcpy(Classe[2].sort2, "Fureur");
    Classe[2].degSort1 = 14;
    Classe[2].degSort2 = 9;
    Classe[2].sort1PA = 3;
    Classe[2].sort2PA = 2;

    strcpy(Classe[3].nomClasse, "L entendue de Cra");
    Classe[3].numClasse = 4;
    strcpy(Classe[3].body, "Frappe celeste");
    Classe[3].bodyPA = 1;
    Classe[3].bodyDeg = 8;
    strcpy(Classe[3].sort1, "Fleche magique");
    strcpy(Classe[3].sort2, "Multi fleche");
    Classe[3].degSort1 = 10;
    Classe[3].degSort2 = 15;
    Classe[3].sort1PA = 2;
    Classe[3].sort2PA = 3;
}
