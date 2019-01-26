#include <iostream>
#include <string>
#include "unite.h"
#include "base.h"

using namespace std;

extern int Tour;
extern Unite *AllSolda[12];
extern Base *A;
extern Base *B;

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
		else std::cerr << "Vous ne pouvez pas avancer!" << '\n';
	}
	if(Camp == 1) {
		if(AllSolda[Position-1] == NULL) {
		 AllSolda[Position] = NULL;
			Position --;
		 AllSolda[Position] = this;
		}
		else std::cerr << "Vous ne pouvez pas avancer!" << '\n';
	}
}

void Unite::attaquer() {TimesAtk = 1;}

void Unite::etreAttaque(Unite* u) {
	HP = HP - u->getATK();
	if(HP <= 0){
		AllSolda[Position] = NULL;
		if (Camp) {
			cout << "Unité " << Position << getNom() << " de B est morte." << endl;
			A->OR += (Prix/2);
		}
		else	{
			cout << "Unité " << Position << getNom() << " de A est morte." << endl;
			B->OR += (Prix/2);
		}
	}
}

void Unite::detruit() {
	HP = 0;
	AllSolda[Position] = NULL;
	cout << "Unité " << Position << getNom() << " de A est détruite." << endl;
}
