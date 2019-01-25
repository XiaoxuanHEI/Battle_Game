#include <iostream>
using namespace std;

extern int tour;
extern int Post[12]; // les 12 tions sont libres

class Unite {
protected:
	int Prix;
	int HP;
	int ATK;
	int Position;
	int Porte[3];
	int Camp;
	int TimesAtk;

public:
	Unite(int prix,int hp, int atk) {
		Camp = tour;
		if(Camp == 0) {
			if(Post[0] == 0) {
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
				Position = 11;
				Prix = prix;
				HP = hp;
				ATK = atk;
			}
		else std::cerr << "No space!" << '\n';
		}
	}

virtual	void avancer();

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
	~Unite() {}
};
