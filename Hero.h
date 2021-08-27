#ifndef HERO_H
#define HERO_H

#include <vector>
#include "Weapon.h"
#include "Knife.h"
#include "Sword.h"
#include "Pistol.h"
#include "Rifle.h"
#include "Character.h"

using namespace std;

class Hero : public Character{
private:
  Weapon* inv[1];
  int money;
public:
  Hero(string n, int h, int m):Character(n, h){
    money = m;
  }

  void weaponChoice(Weapon * w){
    inv[0] = w;
  }

  int attack(){
    cout << getName() << " Has Attacked!" << endl;
      Weapon* w = inv[0];
      w -> attack();
      return w->getDamage();
  }

  bool isDead(){
    bool isDead = false;
    if(getHealth() <= 0){
      isDead = true;
    }
    return isDead;
  }

  void addMoney(int m) {
    money = money + m;
  }

  int getMoney() {
    return money;
  }

  void takeMoney(int m){
    money = money - m;
  }

};

#endif