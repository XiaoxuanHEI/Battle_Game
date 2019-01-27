#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "solda.h"
#include "saveload.cpp"

#define MIN 0
#define MAX 3

using namespace std;
int FlagA;
int FlagB;
extern int AImode;
extern Unite *AllSolda[12];


Base::Base(int camp){
	HP = 100;
	OR = 8;
	Camp = camp;
}

void Base::CreatUnite(){
	if(Tour == 0) {
		if(AllSolda[0] == NULL) {
LabelA:
			FlagA = 0;
			cin>>FlagA;
			if(cin.fail())
			{
				cout << "Entrer illegal!" << endl;
				cout << "Entrer 1,2,3 ou 0:" << endl;
				cin.clear();
				cin.sync();
				cin.ignore(1024,'\n');
				goto LabelA;
			}
			else{
				switch(FlagA)
				{
				case 0:
					break;
				case 1:
					if(OR>=10) {
						AllSolda[0] =  new Fantassin();
						OR -= 10;
					}
					else
					{
						cout << "Or pas suffisant pour un Fantassin!!" << endl;
						cout << "Choisir un autre type de solda:" << endl;
						goto LabelA;
					}
					break;

				case 2:
					if(OR>=12) {
						AllSolda[0] = new Archer();
						OR -= 12;
					}
					else
					{
						cout << "Or pas suffisant pour un Archer!!" << endl;
						cout << "Choisir un autre type de solda:" << endl;
						goto LabelA;
					}
					break;

				case 3:
					if(OR>=20) {
						AllSolda[0] = new Catapulte();
						OR -= 20;
					}
					else
					{
						cout << "Or pas suffisant pour un Catapulte!!" << endl;
						cout << "Choisir un autre type de solda:" << endl;
						goto LabelA;
					}
					break;
				case 8:
					int flag;
label1:
					cout << "Vous voulez enregistrer?  0 Non / 1 Oui   ";
					cin >> flag;
					switch (flag) {
					case 0:
						exit(0);
					case 1:
						save();
						exit(0);
					default:
						goto label1;
					}
				default:
					cout << "Il n'existe pas ce type!!" << endl;
					cout << "Choisir un autre type de solda:" << endl;
					goto LabelA;
				}
			}
		}
		else cout << "Pas de place pour A!" << endl;
	}

	if(Tour == 1 && AImode == 0) {
		if(AllSolda[11] == NULL) {
LabelB:
			FlagB = 0;
			cin>>FlagB;
			if(cin.fail())
			{
				cout << "Entrée illegal!" << endl;
				cout << "Entrer 1,2,3 ou 0:" << endl;
				cin.clear();
				cin.sync();
				cin.ignore(1024,'\n');
				goto LabelB;
			}
			else{
				switch(FlagB)
				{
				case 0:
					break;
				case 1:
					if(OR>=10) {
						AllSolda[11] =  new Fantassin();
						OR -= 10;
					}
					else
					{
						cout << "Or pas suffisant pour un Fantassin!!" << endl;
						cout << "Choisir un autre type de solda:" << endl;
						goto LabelB;
					}
					break;

				case 2:
					if(OR>=12) {
						AllSolda[11] = new Archer();
						OR -= 12;
					}
					else
					{
						cout << "Or pas suffisant pour un Archer!!" << endl;
						cout << "Choisir un autre type de solda:"<<endl;
						goto LabelB;
					}
					break;

				case 3:
					if(OR>=20) {
						AllSolda[11] = new Catapulte();
						OR -= 20;
					}
					else
					{
						cout << "Or pas suffisant pour un Catapulte!" << endl;
						cout << "Choisir un autre type de soldat:" << endl;
						goto LabelB;
					}
					break;
				case 8:
					int flag;
label2:
					cout << "Vous voulez enregistrer?  0 Non / 1 Oui   ";
					cin >> flag;
					switch (flag) {
					case 0:
						exit(0);
					case 1:
						save();
						exit(0);
					default:
						goto label2;
					}
				default:
					cout << "Il n'existe pas ce type!" << endl;
					cout << "Choisir un autre type de soldat:" << endl;
					goto LabelB;
				}
			}
		}
		else cout << "Pas de place pour B!" << endl;
	}

	/*Le coeur de notre AI*/
	else if(Tour == 1 && AImode == 1) {
		if(AllSolda[11] == NULL) {
			srand((unsigned)time(NULL));
LabelB1:
			FlagB = MIN + rand() % (MAX - MIN + 1);

			switch(FlagB)
			{
			case 0:
				break;
			case 1:
				if(OR>=10) {
					AllSolda[11] =  new Fantassin();
					OR -= 10;
				}
				else goto LabelB1;
				break;

			case 2:
				if(OR>=12) {
					AllSolda[11] = new Archer();
					OR -= 12;
				}
				else goto LabelB1;
				break;

			case 3:
				if(OR>=20) {
					AllSolda[11] = new Catapulte();
					OR -= 20;
				}
				else goto LabelB1;
				break;
			}
		}
	}
}

void Base::etreAttaque(Unite* u){
	HP = HP - u->getATK();
}
