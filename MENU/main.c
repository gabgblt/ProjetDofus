#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <allegro/font.h>
#define SAISIE_MAX 10
#define NTUILE     213   // Nombre de tuiles graphiques utilisées
#define TXTUILE    16    // Largeur des tuiles
#define TYTUILE    16    // Hauteur des tuiles
#define NCOLTUILE  20    // Nombre de colonnes de tuiles dans le fichier image

#define NXMAP      85      // Nombre de tuiles en largeur sur le terrain
#define NYMAP      50

typedef struct Joueur
{
    int PM, PA, PV;
    int classe;
    int numJoueur;
}t_joueur;

typedef struct Classe
{
    char nomClasse[20];
    int numClasse;
    char body[20];
    int bodyPA;
    int bodyDeg;
    char sort1[20];
    char sort2[20];
    int degSort1, degSort2;
    int sort1PA, sort2PA;
}t_classe;



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



void Charger()
{
    textout_ex(screen, font, "Vous chargez la partie ", 0, 5, makecol(0, 255, 255), -1);
}

void Debut(BITMAP *image,BITMAP *decor)
{
    blit(image,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    BITMAP *jouer;
    jouer=load_bitmap("jouer.bmp",NULL);
    if (!jouer)
    {
        allegro_message("jouer.bmp");
        exit(EXIT_FAILURE);
    }
    draw_sprite(image, jouer, 330,140);
    blit(image,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    BITMAP *continuer;
    continuer=load_bitmap("continuer.bmp",NULL);
    if (!continuer)
    {
        allegro_message("continuer.bmp");
        exit(EXIT_FAILURE);
    }
    draw_sprite(image, continuer, 300,360);
    blit(image,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    if(mouse_x>=310&&mouse_x<=640&&mouse_y>=130&&mouse_y<=408)
    {
        if(mouse_b & 1)
        {
            rest(500);
            while (!key[KEY_ESC])
            {
                Menu(decor);
            }
        }
    }
    if(mouse_x>=280&&mouse_x<=560&&mouse_y>=360&&mouse_y<=460)
    {
        if(mouse_b & 1)
        {
            rest(500);
            while (!key[KEY_ESC])
            {
                Charger();
            }
        }
    }
}



void Menu(BITMAP *decor, BITMAP *option, int *nbJoueur)
{
    BITMAP *joueur2;
    BITMAP *joueur3;
    BITMAP *joueur4;
    joueur2=load_bitmap("joueur2.bmp",NULL);
    if (!joueur2)
    {
        allegro_message("joueur2.bmp");
        exit(EXIT_FAILURE);
    }

    joueur3=load_bitmap("joueur3.bmp",NULL);
    if (!joueur3)
    {
        allegro_message("joueur3.bmp");
        exit(EXIT_FAILURE);
    }

    joueur4=load_bitmap("joueur4.bmp",NULL);
    if (!joueur4)
    {
        allegro_message("joueur4.bmp");
        exit(EXIT_FAILURE);
    }
    option=load_bitmap("option.bmp",NULL);
    if (!option)
    {
        allegro_message("option.bmp");
        exit(EXIT_FAILURE);
    }
    int numeroJoueur=1;
    blit(decor,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    textout_ex(decor, font, "Combien de joueurs etes vous ? ", 0, 5, makecol(0, 255, 255), -1);
    draw_sprite(decor, joueur2, 350,75);
    draw_sprite(decor, joueur3, 350,240);
    draw_sprite(decor, joueur4, 350,410);
    draw_sprite(decor, option, 900,20);
    blit(decor,screen, 0,0,0,0,SCREEN_W,SCREEN_H);

    if(mouse_x>=350&&mouse_x<=550&&mouse_y>=70&&mouse_y<=200)
    {
        nbJoueur=1;
        if(mouse_b & 1)
        {
            textout_ex(decor, font, "Vous avez selectionne le mode 2 joueurs.", 100, 100, makecol(0, 255, 255), -1);
            blit(decor,screen, 0,0,0,0,SCREEN_W,SCREEN_H);
            rest(1000);
            Classe(nbJoueur,decor);
        }

    }
    if(mouse_x>=350&&mouse_x<=550&&mouse_y>=240&&mouse_y<=400)
    {
        nbJoueur=2;
        if(mouse_b & 1)
        {
            textout_ex(decor, font, "Vous avez selectionne le mode 3 joueurs.", 100, 100, makecol(0, 255, 255), -1);
            blit(decor,screen, 0,0,0,0,SCREEN_W,SCREEN_H);
            rest(1000);
            Classe(nbJoueur,decor);
        }

    }
    if(mouse_x>=350&&mouse_x<=550&&mouse_y>=430&&mouse_y<=560)
    {
        nbJoueur=3;
        if(mouse_b & 1)
        {
            textout_ex(decor, font, "Vous avez selectionne le mode 4 joueurs.", 100, 100, makecol(0, 255, 255), -1);
            blit(decor,screen, 0,0,0,0,SCREEN_W,SCREEN_H);
            rest(1000);
            Classe(nbJoueur,decor);
        }

    }
    if(mouse_x>=900&&mouse_x<=1000&&mouse_y>=10&&mouse_y<=100)
    {
        if(mouse_b & 1)
        {
            show_mouse(screen);
            BITMAP *decor2;
            BITMAP *option1;
            decor2=load_bitmap("decor2.bmp",NULL);
                if (!decor2)
                {
                    allegro_message("decor2.bmp");
                    exit(EXIT_FAILURE);
                }
            option1=load_bitmap("option1.bmp",NULL);
                if (!option1)
                {
                    allegro_message("option1.bmp");
                    exit(EXIT_FAILURE);
                }
            blit(decor2,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(decor,option1,250,150);
            blit(decor2,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
    }

    // la petite pause...

}


void Classe(int *nbJoueur, BITMAP *option, BITMAP *decor,t_joueur Joueur[], t_classe Classe[])
{
        int i=0;
        BITMAP *decor1;
        BITMAP *iop;
        BITMAP *cra;
        BITMAP *sram;
        BITMAP *xelor;
        BITMAP *guerrier;
        BITMAP *assassin;
        BITMAP *archer;
        BITMAP *mage;

        option=load_bitmap("option.bmp",NULL);
        if (!option)
        {
            allegro_message("option.bmp");
            exit(EXIT_FAILURE);
        }
        decor1=load_bitmap("decor1.bmp",NULL);
        if (!decor1)
        {
            allegro_message("decor1.bmp");
            exit(EXIT_FAILURE);
        }

        guerrier=load_bitmap("guerrier.bmp",NULL);
        if (!guerrier)
        {
            allegro_message("guerrier.bmp");
            exit(EXIT_FAILURE);
        }

        archer=load_bitmap("archer.bmp",NULL);
        if (!archer)
        {
            allegro_message("archer.bmp");
            exit(EXIT_FAILURE);
        }

        assassin=load_bitmap("assassin.bmp",NULL);
        if (!assassin)
        {
            allegro_message("assassin.bmp");
            exit(EXIT_FAILURE);
        }

        mage=load_bitmap("mage.bmp",NULL);
        if (!mage)
        {
            allegro_message("mage.bmp");
            exit(EXIT_FAILURE);
        }

        iop=load_bitmap("iop.bmp",NULL);
        if (!iop)
        {
            allegro_message("iop.bmp");
            exit(EXIT_FAILURE);
        }

        cra=load_bitmap("cra.bmp",NULL);
        if (!cra)
        {
            allegro_message("cra.bmp");
            exit(EXIT_FAILURE);
        }

        sram=load_bitmap("sram.bmp",NULL);
        if (!sram)
        {
            allegro_message("sram.bmp");
            exit(EXIT_FAILURE);
        }

        xelor=load_bitmap("xelor.bmp",NULL);
        if (!xelor)
        {
            allegro_message("xelor.bmp");
            exit(EXIT_FAILURE);
        }

        blit(decor1,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(decor1, iop, 20,120);
        draw_sprite(decor1, cra, 500,130);
        draw_sprite(decor1, sram, 20,330);
        draw_sprite(decor1, xelor, 500,340);
        draw_sprite(decor1, option, 900,20);
        draw_sprite(decor1, guerrier, 290,180);
        draw_sprite(decor1, archer, 780,180);
        draw_sprite(decor1, assassin, 290,390);
        draw_sprite(decor1, mage, 780,400);
        blit(decor1,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(500);

        textout_ex(screen, font, "Une fois les classes choisi appuiyez sur entrer pour poursuivre vers le jeu ", 50, 60, makecol(0, 255, 255), -1);


    for (i=0;i<=nbJoueur;)
        {
            if (key[KEY_ENTER])
            {
                break;
            }
            textout_ex(screen, font, "Choisissez votre classe ? ", 0, 5, makecol(0, 255, 255), -1);
            textprintf_ex(screen,font,40,40,makecol(255,255,255),0,"Joueur %d",i);
            if(mouse_x>=20&&mouse_x<=280&&mouse_y>=150&&mouse_y<=330)
            {
                if(mouse_b & 1)
                {
                    textout_ex(screen, font, "Vous avez selectionne la classe IOP.", 100, 90, makecol(0, 255, 255), -1);
                    Joueur[i].classe = 3;
                    rest(2000);
                    i++;
                }

            }
            if(mouse_x>=500&&mouse_x<=730&&mouse_y>=150&&mouse_y<=330)
            {
                if(mouse_b & 1)
                {
                    textout_ex(screen, font, "Vous avez selectionne la classe CRA.", 100, 110, makecol(0, 255, 255), -1);
                    Joueur[i].classe = 4;
                    rest(2000);
                    i++;
                }

            }
            if(mouse_x>=20&&mouse_x<=280&&mouse_y>=400&&mouse_y<=560)
            {
                if(mouse_b & 1)
                {
                    textout_ex(screen, font, "Vous avez selectionne la classe SRAM.",   450, 90, makecol(0, 255, 255), -1);
                    Joueur[i].classe = 2;
                    rest(2000);
                    i++;
                }

            }
            if(mouse_x>=500&&mouse_x<=730&&mouse_y>=400&&mouse_y<=560)
            {
                if(mouse_b & 1)
                {
                    textout_ex(screen, font, "Vous avez selectionne la classe SABLIER DE XELOR.", 450, 110, makecol(0, 255, 255), -1);
                    Joueur[i].classe = 1;
                    rest(2000);
                    i++;
                }

            }

        }
        //phaseDeJeu();
}





int main()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1000,600,0,0))!=0)
    {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int *nbJoueur=NULL;
    BITMAP *image;
    BITMAP *decor;
    BITMAP *option;
    image=load_bitmap("image.bmp",NULL);
    if (!image)
    {
        allegro_message("image.bmp");
        exit(EXIT_FAILURE);
    }
    decor=load_bitmap("decor.bmp",NULL);
    if (!decor)
    {
        allegro_message("decor.bmp");
        exit(EXIT_FAILURE);
    }


    while (!key[KEY_ESC])
    {
        show_mouse(screen);
        Debut(image,decor);
        //FinJeu();
    }
    allegro_exit();
    return 0;
}
END_OF_MAIN();
