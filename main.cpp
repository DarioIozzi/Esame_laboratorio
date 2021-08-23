
#include "Controller.h"


int main() {
    Controller game;
    while(true){
        GameEvent event = game.getEvent();
        bool quit = game.update(event);
        if(quit)
            return 0;
    }
}
