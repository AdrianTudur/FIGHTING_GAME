#ifndef KNIFE_H
#define KNIFE_H

#include <iostream>
#include "Weapon.h"
#include <time.h>

using namespace std;

class Knife : public Weapon{
  public:
    Knife(int d):Weapon(d){}
    
    int attack(){
      cout<< "Your Knife Dealt "<< getDamage() <<" Damage\n";
      return getDamage();
    }
};

#endif