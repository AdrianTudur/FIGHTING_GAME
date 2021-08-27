#ifndef VILLIAN_H
#define VILLIAN_H

#include "Character.h"
#include <time.h>


class Villian : public Character{
private:
public:
Villian(string n, int h):Character("Villan", h){}

  int attack(){
    srand (time(NULL));
    int dam = rand() % 20 + 1;
    cout << getName() << " Has Attacked! "<< endl;
    cout << "He Has Dealt " << dam << " Damage!" << endl;
    return dam;
  }

  bool isDead(){
    bool isDead = false;
    if(getHealth() <= 0){
      isDead = true;
    }
    return isDead;
  }
};

#endif