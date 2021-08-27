#ifndef CHARACTER_H
#define CHARACTER_H
#include <time.h>
#include <string>
#include <iostream>
#include "Weapon.h"

using namespace std;

class Character{
private:
  string name;
  int health;
public:
  Character(string n, int h){
    name = n;
    health = h;
  }
  virtual void weaponChoice(Weapon * w){}

  virtual int attack(){
    return 0;
  }

  virtual bool isDead(){
    return 0;
  }
  
  virtual void addMoney(int m){}

  virtual int getMoney(){
    return 0;
  }

  virtual void takeMoney(int m){};

  void heal(int h){
    health = health + h;
  }

  void takeDamage(int h){
    health = health - h;
  }
  int getHealth(){
    return health;
  }

  string getName(){
    return name;
  }

};

#endif