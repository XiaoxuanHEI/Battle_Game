#include <iostream>
#include <string>
#include "unite.h"
using namespace std;

extern int Tour;
extern Unite *AllSolda[12];
// extern int Post[12]; // les 12 tions sont libres

Unite::Unite(string nom,int prix,int hp, int atk) {
	Camp = Tour;
	if(Camp == 0) {
			AllSolda[0] = this;
			Nom = nom;
			Position = 0;
			Prix = prix;
			HP = hp;
			ATK = atk;
			TimesAtk = 0;
	}
	if(Camp == 1) {
			Nom = nom;
			AllSolda[11] = this;
			Position = 11;
			Prix = prix;
			HP = hp;
			ATK = atk;
			TimesAtk = 0;
	}
}

void Unite::avancer() {
		if(Camp == 0) {
			if(AllSolda[Position+1] == NULL){
			 AllSolda[Position] = NULL;
				Position ++;
			 AllSolda[Position] = this;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
		if(Camp == 1) {
			if(AllSolda[Position-1] == NULL) {
			 AllSolda[Position] = NULL;
				Position --;
			 AllSolda[Position] = this;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
	}

void Unite::attaquer() {TimesAtk = 1;}
void Unite::etreAttaque (int atk) {
		HP = HP - atk;
		if(HP <= 0){
			AllSolda[Position] = NULL;
			cout << "Unite " << Position << " est mort.."<<endl;
		}
	}
