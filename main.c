#include <allegro.h>

void affichage();

int main(int argc, char *argv[])
{

    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    while ( !key[KEY_ESC] )
    {

        if(key[KEY_ENTER])
        {
            clear_bitmap(screen);
        }

        if(key[KEY_SPACE])
        {
            affichage();
        }

    }

    return 0;
}
END_OF_MAIN();



void affichage()
{
    int couleur;
    show_mouse(screen);

    // Avoir une couleur (ici du blanc)
    couleur=makecol(255,255,255);



    // Rectangle plein (rouge couleur directe)
    rectfill(screen,460,170,220,140,makecol(255,0,0));
    rectfill(screen,460,220,220,190,makecol(100,100,100));
    rectfill(screen,460,270,220,240,makecol(255,0,255));


    // afficher du texte (couleur=blanc)
    textprintf_ex(screen,font,250,150,couleur,-1,"Rejouer la partie ");
    textprintf_ex(screen,font,250,200,couleur,-1,"Relancer une autre partie");
    textprintf_ex(screen,font,250,250,couleur,-1,"Quitter la partie ");

while( !key[KEY_ENTER] )
{


    if ( mouse_b&1 && mouse_x<=460 && mouse_y<=170 && mouse_x>=220 && mouse_y>=140)
    {
        clear_bitmap(screen);
        textprintf_ex(screen,font,250,150,couleur,-1,"Vous rejouez la partie ");
    }

        if ( mouse_b&1 && mouse_x<=460 && mouse_y<=220 && mouse_x>=220 && mouse_y>=190)
    {
        clear_bitmap(screen);
        textprintf_ex(screen,font,250,150,couleur,-1,"Vous relancez une autre partie ");
    }

        if ( mouse_b&1 && mouse_x<=460 && mouse_y<=270 && mouse_x>=220 && mouse_y>=240)
    {
        clear_bitmap(screen);
        textprintf_ex(screen,font,250,150,couleur,-1,"Vous quittez la partie ");
    }
}
    readkey();
}


