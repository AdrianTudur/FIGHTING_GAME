#include <iostream>
#include <fstream>
#include "Character.h"
#include "Hero.h"
#include "Villian.h"
#include <time.h>
void saveGame(Character* h, Character* v);

int main() {
  int hHealth, hMoney, vHealth;
  string hName;
  int gamechoice;
  cout << " 1 | New Game \n 2 | Load Game " << endl;
  cin >> gamechoice;

  switch(gamechoice) {
    case 1: {
      hName = "Adrian";
      hHealth = 100;
      hMoney = 55;
      vHealth = 100;
      break;
    }
    case 2: {
      int number;
      int data[3];
      ifstream input_file("game.out");
      if (!input_file.is_open()) {
        cout << "File not found!" << endl;
        exit(1);
      }

      while (input_file >> number) {
        int i;
        data[i++] = number;
      }
        hHealth = data[0];
        hMoney = data[1];
        vHealth = data[2];
      cout << endl;
      input_file.close();
    }
  }

  Character * heroP = new Hero(hName, hHealth, hMoney);
  Character * vilP = new Villian("Villian", 100);
  srand (time(NULL));
  int sdamage = rand() % 10;
  do {
    int randmoney = rand() % 30 + 20;
    // CREATE WEAPONS //
    int kdamage = rand() % 10 + 1;
    int sdamage = rand() % 10 + 10;
    int pdamage = rand() % 10 + 25;
    int rdamage = rand() % 10 + 35;
    Knife bk(1);
    Knife k(kdamage);
    Sword s(sdamage);
    Pistol p(pdamage);
    Rifle r(rdamage);

    // HEAL MENU //
    cout << "+--+ HEALTH MENU | Balance: $" << heroP -> getMoney() << " +--+" << endl;
    cout << " 1 | +20HP - $50 \n 2 | +50HP - $100 \n 3 | Skip " << endl;;
    cout << " Enter Number For Heal: ";
    int healoption;
    cin >> healoption;
    cout << endl;

    switch(healoption) {
      case 1:
        if(heroP -> getMoney() < 50) {
        cout << "You Cant Afford That! Heal Skipped" << endl;
        cout << endl;
        break;
        } else {
        heroP -> heal(20);
        heroP -> takeMoney(50);
        break;
        }
      case 2:
        if(heroP -> getMoney() < 100) {
        cout << "You Cant Afford That! Heal Skipped" << endl;
        cout << endl;
        break;
        } else {
        heroP -> heal(50);
        heroP -> takeMoney(100);
        break;
        }
      case 3:
        break;
    }

    // BUY MENU //
    cout << "+--+ BUY MENU | Balance: $" << heroP -> getMoney() << " +--+" << endl;
    cout << " 1 | Knife - $30 \n 2 | Sword - $55 \n 3 | Pistol - $90 \n 4 | Rifle - $135 \n 5 | Broken Knife - Free " << endl;;
    cout << " Enter Number For Weapon: ";
    int option;
    cin >> option;
    cout << endl;

    switch(option) {
      case 1:
        if(heroP -> getMoney() < 30) {
          heroP -> weaponChoice(&bk);
          cout << "You Cant Afford That! Recieved Broken Knife" << endl;
          cout << endl;
          break;
        } else {
          heroP -> weaponChoice(&k);
          heroP -> takeMoney(30);
          break;         
        }
      case 2:
        if(heroP -> getMoney() < 55) {
          heroP -> weaponChoice(&bk);
          cout << "You Cant Afford That! Recieved Broken Knife" << endl;
          cout << endl;
          break;
        } else {
          heroP -> weaponChoice(&s);
          heroP -> takeMoney(55);
          break;          
        }  
      case 3:
        if(heroP -> getMoney() < 90) {
          heroP -> weaponChoice(&bk);
          cout << "You Cant Afford That! Recieved Broken Knife" << endl;
          cout << endl;
          break;
        } else {
          heroP -> weaponChoice(&p);
          heroP -> takeMoney(90);
          break;
        }
      case 4:
        if(heroP -> getMoney() < 135) {
          heroP -> weaponChoice(&bk);
          cout << "You Cant Afford That! Recieved Broken Knife" << endl;
          cout << endl;
          break;
        } else {
          heroP -> weaponChoice(&r);
          heroP -> takeMoney(135);
          break;
        }
      case 5:
        heroP -> weaponChoice(&bk);
    }

    cout << "+--------------------------------------+" << endl;
    cout << endl;
    vilP -> takeDamage(heroP -> attack());
    heroP -> addMoney(randmoney);
    cout << "Money : $" << heroP -> getMoney();
    cout << endl;
    heroP -> takeDamage(vilP -> attack());
    cout << endl;
    cout << "+--------------------------------------+" << endl;
    cout << endl;
    
    if(heroP -> getHealth() < 0) {
      cout << heroP -> getName() << " Health: " << "0" << "HP" << endl;
    } else {
      cout << heroP -> getName() << " Health: " << heroP -> getHealth() << "HP" << endl;
    }

    if(vilP -> getHealth() < 0) {
      cout << vilP -> getName()  << " Health: " << "0" << "HP" << endl;
    } else {
      cout << vilP -> getName()  << " Health: " << vilP -> getHealth() << "HP" << endl;
    }
    cout << endl;
    cout << "+--------------------------------------+" << endl;
    cout << endl;
    saveGame(heroP, vilP);
  }
  while (vilP -> isDead() == false && heroP -> isDead() == false);
  if(vilP -> isDead() == true) {
    cout << "YOU HAVE WON! GAME OVER!" << endl;
  }
  if(heroP -> isDead() == true) {
    cout << "YOU HAVE LOST! GAME OVER!" << endl;
  }
}

void saveGame(Character* h, Character* v) {
  ofstream fout("game.out");
  fout << h -> getHealth() << " " << h -> getMoney() << endl;
  fout << v -> getHealth() << endl;
  fout.close();
}