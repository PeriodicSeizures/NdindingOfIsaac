#include "lib/screen.h"
#include "menu/menu.h"

int main()
{
    scr_init();

    beginMenu();
    
    scr_uninit();

    return 0;
}
