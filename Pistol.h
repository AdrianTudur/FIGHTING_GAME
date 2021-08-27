#ifndef PISTOL_H
#define PISTOL_H

#include <iostream>
#include "Weapon.h"

using namespace std;

class Pistol : public Weapon{
  public:
    Pistol(int d):Weapon(d){}
    
    int attack(){
      cout<< "Your Pistol Dealt "<< getDamage() <<" Damage\n";
      return getDamage();
    }
};

#endif