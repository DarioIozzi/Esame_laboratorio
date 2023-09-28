//
// Created by dario on 12/08/21.
//
#include "GameCharacter.h"
void GameCharacter::move(int x, int y) {
    if(abs(posX + x) <= WorldMap::getMW()-80 && (posX + x) <= 0 && abs(posY +y) <= WorldMap::getMH()-80 && (posY + y) <= 0  ) {
        int c = map->getCosto(abs(posX), abs(posY));
            if(x == 0){       //VERTICALE
                if(y < 0) {   //BASSO
                    for (int i = 0; i < 10 - c; i++) {
                        if (map->getCosto(abs(posX), abs(posY - i - 80)) == 9) {
                            posY -= i;
                            notify();
                            return;
                        }
                    }
                    if(map->getCosto(abs(posX), abs(posY- 80)) != 0){
                        posY += y + map->getCosto(abs(posX), abs(posY - 80));
                        notify();
                        return;
                    }
                    posY += y + c;
                    notify();                               //TODO FUNZIONE InRange?
                }
                else{    //ALTO
                    for (int i = 0; i < 10 - c; i++) {
                        if (map->getCosto(abs(posX), abs(posY + i + 1)) == 9) {
                            posY += i;
                            notify();
                            return;
                        }
                    }
                    if(map->getCosto(abs(posX), abs(posY - 80)) !=0){
                        posY += y - map->getCosto(abs(posX), abs(posY - 80));
                        notify();
                        return;
                    }
                    posY += y - c;
                    notify();
                }
            }
            else if(y == 0){   //ORIZZONTALE
                if(x < 0) {    //DESTRA
                    for (int j = 0; j < 10 - c; j++) {
                        if (map->getCosto(abs(posX - j - 80), abs(posY)) == 9) {
                            posX -= j;
                            notify();
                            return;
                        }
                    }
                    if(map->getCosto(abs(posX - 80), abs(posY)) != 0){
                        posX += x + map->getCosto(abs(posX- 80), abs(posY));
                        notify();
                        return;
                    }
                    posX += x + c;
                    notify();
                }
                else{       //SINISTRA
                    for (int j = 0; j < 10 - c; j++) {
                        if (map->getCosto(abs(posX + j + 1), abs(posY)) == 9) {
                            posX += j;
                            notify();
                            return;
                        }
                    }
                    if(map->getCosto(abs(posX - 80), abs(posY)) != 0){
                        posX += x - map->getCosto(abs(posX- 80), abs(posY));
                        notify();
                        return;
                    }
                    posX += x - c;
                    notify();
                }
            }

    }
}

void GameCharacter::subscribe(Observer* o) {
    observers.push_back(o);
}

void GameCharacter::unsubscribe(Observer* o) {
    observers.remove(o);
}

void GameCharacter::notify() const {
    for(auto obs : observers){
        obs->update();
    }
}

GameCharacter::GameCharacter(int x, int y, int WW, int WH, WorldMap* map) : posX(x), posY(y), WinWidth(WW), WinHeight(WH), map(map) {
}

GameCharacter::GameCharacter(int x, int y) : posX(x), posY(y){
}