#include <iostream>
#include "unite.h"

using namespace std;

extern Unite *AllSolda[12];

class Fantassin : public Unite {
public:
Fantassin() : Unite("Fant",10,10,4) {
	Porte[0] = 1;
	Porte[1] = 0;
	Porte[2] = 0;
}
~Fantassin() {
}
void SuperSolda() {
	Nom = "Super";
}
virtual void etreAttaque (Unite* u) {
	HP = HP - u->getATK();
	if(HP <= 0) {
		if(u->getNom() == "Fant") {
			Fantassin* f = (Fantassin*) u;
			f->SuperSolda();
		}
		AllSolda[Position] = NULL;
		if (Camp) {
			cout << "Unité " << Position <<" Fantassin de B est morte." << endl;
			A->OR += (Prix/2);
		}
		else    {
			cout << "Unité " << Position << " Fantassin de A est morte." << endl;
			B->OR += (Prix/2);
		}
	}
}
};

class Archer : public Unite {
public:
Archer() : Unite("Arch",12,8,3) {
	Porte[0] = 1;
	Porte[1] = 2;
	Porte[2] = 3;
}

~Archer() {
}
};

class Catapulte : public Unite {
public:
Catapulte() : Unite("Cata",20,12,6) {
	Porte[0] = 2;
	Porte[1] = 3;
	Porte[2] = 4;
}
~Catapulte() {
}
};
