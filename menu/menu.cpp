// menu.cpp

//#include <vector>

#include <os.h>
#include <libndls.h>

#include "menu.h"

#include "../game/gamemanager.h"

#include "../lib/screen.h"

#include "../resources/animations/splash.h"
#include "../resources/textures/template_title_screen.png.h"
#include "../resources/textures/title.png.h"

enum Menu {
    TITLE = 0, SELECT_FILE = 1, GAME_SCREEN = 2
    //, CHALLENGES = 3,
    //MODS = 5, STATS = 6, OPTIONS = 7
};

void beginMenu() {

    unsigned int frame = 0;

    int h = 1;
    int hChange = 1;



    unsigned int currentTime = 0;
    const unsigned int delay = 5;



    Menu state = Menu::TITLE;
    unsigned int slot = 0;

    bool enterPressed = false;
    bool escPressed = false;
    
    //scr_fill(0, 0, 0);

    while(true) {


        switch (state) {

            case Menu::TITLE: {
                //scr_drawTexture(&title, 160-splash.width/2, 100);
                scr_drawTexture(&template_title_screen, 0, 0);

                scr_drawAnimationFrame(&splash, 160-splash.width/2, 130-splash.height/2, frame); // frame

                if (h == 0 || h == 4) hChange*=-1;
                h+=hChange;

                scr_drawTexture(&title, 160-title.width/2, 55 + h);

                //frame++;

                //scr_flip();

                if (currentTime > delay) {
                    frame++;
                    currentTime = 0;
                } else currentTime++;

                if (frame >= splash.count) {
                    frame = 0;
                }
                break;
            }
            case Menu::SELECT_FILE: {
                scr_fillRect(200, 200, 200, 80, 60, 160, 120);
                break;
            }
            case Menu::GAME_SCREEN: {
                scr_fillRect(100, 100, 100, 80, 60, 160, 120);
            }
        }
        

        if (isKeyPressed(KEY_NSPIRE_ESC)) {
            if (!escPressed) {
                escPressed = true;
                switch(state) {
                    case Menu::TITLE:
                        return;
                    case Menu::SELECT_FILE:
                        state = Menu::TITLE;
                        break;
                    case Menu::GAME_SCREEN:
                        state = Menu::SELECT_FILE;
                }
            }
        } else escPressed = false;
//state == Menu::TITLE) break;

        //if (isKeyPressed(KEY_NSPIRE_ENTER)) scr_fill(127, 127, 127);
        //else scr_fill(127,50,0);
        //scr_flip();

        if (isKeyPressed(KEY_NSPIRE_ENTER)) {
            if (!enterPressed) {
                enterPressed = true;
                switch(state) {
                    case Menu::TITLE:        
                        state = Menu::SELECT_FILE; 
                        slot = 0;
                        break;
                    case Menu::SELECT_FILE:  
                        state = Menu::GAME_SCREEN; 
                        slot = 0;
                        break;
                    case Menu::GAME_SCREEN:
                        // start game
                        newGame();
                        break;


                }
            }
        } else enterPressed = false;

        scr_flip();
        //msleep(250);
    }

}