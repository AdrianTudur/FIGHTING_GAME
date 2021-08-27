#ifndef WEAPON_H
#define WEAPON_H
#include <time.h>

class Weapon{
private:
  int damage;
public:
  Weapon(int d){
    damage = d;
  }
  int getDamage(){
    return damage;
  }
  
  virtual int attack(){
    return 0;
  }

};

#endif