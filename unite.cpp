#include <iostream>
#include <string>
using namespace std;

extern int Tour;
extern int Post[12]; // les 12 tions sont libres

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
	Unite(){}
	Unite(string nom,int prix,int hp, int atk) {
		Camp = Tour;
		if(Camp == 0) {
			if(Post[0] == 0) {
				Post[0] = 1;
				Nom = nom;
				Position = 0;
				Prix = prix;
				HP = hp;
				ATK = atk;
				TimesAtk = 0;
			}
		else std::cerr << "No space!" << '\n';
		}

		if(Camp == 1) {
			if(Post[11] == 0) {
				Post[11] = 1;
				Position = 11;
				Prix = prix;
				HP = hp;
				ATK = atk;
			}
		else std::cerr << "No space!" << '\n';
		}
	}

	void avancer() {
		if(Camp == 0) {
			if(Post[Position+1] == 0){
				Post[Position] = 0;
				Position ++;
				Post[Position] = 1;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
		if(Camp == 1) {
			if(Post[Position-1] == 0) {
				Post[Position] = 0;
				Position --;
				Post[Position] = 1;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
	}

	void attaquer() {TimesAtk++;}
	void etreAttaque (int atk) {
		HP = HP - atk;
		if(HP <= 0){
			Post[Position] = 0;
			cout << "Unite" << Position << "est mort.."<<endl;
		}
	}

	int getPrix() {return Prix;}
	int getHP() {return HP;}
	int getATK() {return ATK;}
	int getPosition() {return Position;}
	string getNom() {return Nom;}
	~Unite(){}
};
