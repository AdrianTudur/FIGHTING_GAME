#ifndef RIFLE_H
#define RIFLE_H

#include <iostream>
#include "Weapon.h"

using namespace std;

class Rifle : public Weapon{
  public:
    Rifle(int d):Weapon(d){}
    
    int attack(){
      cout<< "Your Rifle Dealt "<< getDamage() <<" Damage\n";
      return getDamage();
    }
};

#endif