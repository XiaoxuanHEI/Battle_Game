#ifndef _UNITE_H_
#define _UNITE_H_

#include <iostream>
#include <string>
using namespace std;

class Unite {
protected:
	string Nom;
	int Prix;
	int HP;
	int ATK;
	int Position;
	int Porte[3];
	int Camp;		//identifier si une unite est venu de baseA ou de baseB
	int TimesAtk;

public:
	Unite(){};
	Unite(string nom,int prix,int hp, int atk);
	void avancer();
	void attaquer();
  void setTimesATK(){TimesAtk = 0;}
	virtual void etreAttaque (Unite* u);
	void detruit();
  int getCamp() {return Camp;}
	int getPrix() {return Prix;}
	int getHP() {return HP;}
	int getATK() {return ATK;}
	int getPosition() {return Position;}
  int *getPorte() {return Porte;}
  int getTimesATK() {return TimesAtk;}
	string getNom() {return Nom;}
	~Unite(){}
};

#endif
