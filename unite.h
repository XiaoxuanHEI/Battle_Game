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
	int Camp;		//identifier de baseA ou baseB
	int TimesAtk;

public:
	Unite(){};
	Unite(string nom,int prix,int hp, int atk);
	void avancer();
	void attaquer();
	void etreAttaque (int atk);
  int getCamp() {return Camp;}
	int getPrix() {return Prix;}
	int getHP() {return HP;}
	int getATK() {return ATK;}
	int getPosition() {return Position;}
	string getNom() {return Nom;}
	~Unite(){}
};
