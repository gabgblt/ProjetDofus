#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

typedef struct Joueur
{
    int PM, PA, PV;
    int classe;
    int numJoueur;
}t_joueur;

typedef struct classeJoueur
{
    int classeNum;
    char nomClasse[20];
    int attaque;//mettre le nombre de dégat de l'attaque de classe
    char sort[20];//sort de chaque classe
}t_classe;

void Classe1()
{
    t_classe Classe[3];
    Classe[0].classeNum = 0;
    Classe[0].nomClasse[20] = "Le sablier de Xelor";
    Classe[0].attaque = 5;//je laisse tout à 5 pour le moment;
    Classe[0].sort[20] = "Time Travel";

    Classe[1].classeNum = 1;
    Classe[1].nomClasse[20] = "L'ombre de Sram";
    Classe[1].attaque = 5;//je laisse tout à 5 pour le moment;
    Classe[1].sort[20] = "Assassinate";

    Classe[2].classeNum = 2;
    Classe[2].nomClasse[20] = "Le cœur d'Iop";
    Classe[2].attaque = 5;//je laisse tout à 5 pour le moment;
    Classe[2].sort[20] = "Coup de boule";

    Classe[3].classeNum = 3;
    Classe[3].nomClasse[20] = "L'étendue de Crâ";
    Classe[3].attaque = 5;//je laisse tout à 5 pour le moment;
    Classe[3].sort[20] = "Fleche magique";

}


void Menu(BITMAP *decor)
{
    int nbJoueur=0;
    blit(decor,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    rest(100);

    textout_ex(screen, font, "Combien de joueurs etes vous ? ", 0, 5, makecol(0, 255, 255), -1);

    BITMAP *joueur2;
    joueur2=load_bitmap("joueur2.bmp",NULL);
    if (!joueur2)
    {
        allegro_message("joueur2.bmp");
        exit(EXIT_FAILURE);
    }
    draw_sprite(decor, joueur2, 150 ,260);


    BITMAP *joueur3;
    joueur3=load_bitmap("joueur3.bmp",NULL);
    if (!joueur3)
    {
        allegro_message("joueur3.bmp");
        exit(EXIT_FAILURE);
    }
    draw_sprite(decor, joueur3, 450 ,270);


    BITMAP *joueur4;
    joueur4=load_bitmap("joueur4.bmp",NULL);
    if (!joueur4)
    {
        allegro_message("joueur4.bmp");
        exit(EXIT_FAILURE);
    }
    draw_sprite(decor, joueur4, 790 ,285);


    if(mouse_x>=170&&mouse_x<=350&&mouse_y>=290&&mouse_y<=420)
    {
        nbJoueur=2;
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous avez selectionne le mode 2 joueurs.", 100, 100, makecol(0, 255, 255), -1);
            rest(3000);

            Classe(nbJoueur);
        }

    }
    if(mouse_x>=480&&mouse_x<=660&&mouse_y>=260&&mouse_y<=420)
    {
        nbJoueur=3;
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous avez selectionne le mode 3 joueurs.", 100, 100, makecol(0, 255, 255), -1);
            rest(3000);
            Classe(nbJoueur);
        }

    }
    if(mouse_x>=805&&mouse_x<=1000&&mouse_y>=290&&mouse_y<=420)
    {
        nbJoueur=4;
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous avez selectionne le mode 4 joueurs.", 100, 100, makecol(0, 255, 255), -1);
            rest(3000);
            Classe( nbJoueur);
        }

    }

    // la petite pause...
        rest(500);
}


void Classe(int nbJoueur)
{
    while (!key[KEY_ENTER])
    {
    int i=1;
    BITMAP *decor1;
    BITMAP *iop;
    BITMAP *cra;
    BITMAP *sram;
    BITMAP *xelor;

    decor1=load_bitmap("decor1.bmp",NULL);
    if (!decor1)
    {
        allegro_message("decor1.bmp");
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
    draw_sprite(screen, iop, 300 ,250);
    draw_sprite(screen, cra, 650 ,250);
    draw_sprite(screen, sram, 310 ,450);
    draw_sprite(screen, xelor, 650 ,450);
    rest(1000);

    textout_ex(screen, font, "Une fois les classes choisi appuiyez sur entrer pour poursuivre vers le jeu ", 50, 60, makecol(0, 255, 255), -1);

    while (i<=nbJoueur)
    {
        if (key[KEY_ENTER])
        {
            break;
        }
        textout_ex(screen, font, "Choisissez votre classe ? ", 0, 5, makecol(0, 255, 255), -1);
        textprintf_ex(screen,font,40,40,makecol(255,255,255),0,"Joueur %d",i);
        if(mouse_x>=300&&mouse_x<=550&&mouse_y>=220&&mouse_y<=370)
    {
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous avez selectionne la classe IOP.", 100, 100, makecol(0, 255, 255), -1);
            rest(3000);
            i++;
        }

    }
    if(mouse_x>=650&&mouse_x<=870&&mouse_y>=220&&mouse_y<=370)
    {
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous avez selectionne la classe CRA.", 100, 100, makecol(0, 255, 255), -1);
            rest(3000);
            i++;
        }

    }
    if(mouse_x>=300&&mouse_x<=550&&mouse_y>=450&&mouse_y<=600)
    {
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous avez selectionne la classe SRAM.", 100, 100, makecol(0, 255, 255), -1);
            rest(3000);
            i++;
        }

    }
    if(mouse_x>=650&&mouse_x<=870&&mouse_y>=450&&mouse_y<=600)
    {
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous avez selectionne la classe SABLIER DE XELOR.", 100, 100, makecol(0, 255, 255), -1);
            rest(3000);
            i++;
        }

    }

    }

}
}

void Structure()
{
    t_joueur Joueur[3];

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

int FinJeu()
{
    textout_ex(screen, font, "Rejouer : Permet de rejouer la partie avec les memes classes.", 0,575, makecol(255,0,0),-1);
    textout_ex(screen, font, "Recommencer : Permet de recommencer le jeu en choisissant de nouvelle classe.", 0,585, makecol(255,0,0),-1);
    textout_ex(screen, font, "Que souhaitez vous faire ? ", 0,5, makecol(255,0,0),-1);
    rectfill(screen, 110, 270, 250, 330, makecol(0,255,0));
    rectfill(screen, 330, 270, 470, 330, makecol(255,0,0));
    rectfill(screen, 550, 270, 690, 330, makecol(0,0,255));
    if(mouse_x>=110&&mouse_x<=250&&mouse_y>=270&&mouse_y<=330)
    {
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous quittez le jeu.", 100, 100, makecol(0, 255, 255), -1);
            return 0;
        }

    }
    if(mouse_x>=330&&mouse_x<=470&&mouse_y>=270&&mouse_y<=330)
    {
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous rejouez la partie avec les memes classes.", 100, 100, makecol(0, 255, 255), -1);
            return 1;
        }

    }
    if(mouse_x>=550&&mouse_x<=690&&mouse_y>=270&&mouse_y<=330)
    {
        if(mouse_b & 1)
        {
            textout_ex(screen, font, "Vous allez etre redirige vers le menu du jeu.", 100, 100, makecol(0, 255, 255), -1);
            return 2;
        }

    }
}


int main()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,700,0,0))!=0)
    {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *decor;
    decor=load_bitmap("decor.bmp",NULL);
    if (!decor)
    {
        allegro_message("decor.bmp");
        exit(EXIT_FAILURE);
    }


    while (!key[KEY_ESC])
    {
        show_mouse(screen);
        Menu(decor);
        //FinJeu();
    }
    allegro_exit();
    return 0;
}END_OF_MAIN();

