#ifndef SWORD_H
#define SWORD_H

#include <iostream>
#include "Weapon.h"

using namespace std;

class Sword : public Weapon{
  public:
    Sword(int d):Weapon(d){}
    
    int attack(){
      cout<< "Your Sword Dealt "<< getDamage() <<" Damage\n";
      return getDamage();
    }
};

#endif