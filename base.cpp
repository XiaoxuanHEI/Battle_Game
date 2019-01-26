#include <iostream>
#include "solda.h"

using namespace std;

extern Unite *AllSolda[12];
// extern int MarkAllSolda;

class Base{
public:
	int HP;
	int OR;
	int Camp;

	Base(int camp){
		HP = 100;
		OR = 8;
		Camp = camp;
	}
	void CreatUnite(int flag){
		if(Tour == 0){
			if(AllSolda[0] == NULL) {
				switch(flag)
				{
				case 0:
					break;
				case 1:
					if(OR>=10) {
						AllSolda[0] =  new Fantassin();
						OR -= 10;
					}
					else cout << "Or pas suffisant!!" << endl;
					break;
				case 2:
					if(OR>=12) {
						AllSolda[0] = new Archer();
						OR -= 12;
					}
					else cout << "Or pas suffisant!!" << endl;
					break;
				case 3:
					if(OR>=20) {
						AllSolda[0] = new Catapulte();
						OR -= 20;
					}
					else cout << "Or pas suffisant!!" << endl;
					break;
				}
			}
			else cout<<"Pas de place pour A!!"<<endl;
		}

		if(Tour == 1){
			if(AllSolda[11] == NULL) {
				switch(flag)
				{
				case 0:
					break;
				case 1:
					if(OR>=10) {
						AllSolda[11] =  new Fantassin();
						OR -= 10;
					}
					else cout << "Or pas suffisant!!" << endl;
					break;
				case 2:
					if(OR>=12) {
						AllSolda[11] = new Archer();
						OR -= 12;
					}
					else cout << "Or pas suffisant!!" << endl;
					break;
				case 3:
					if(OR>=20) {
						AllSolda[11] = new Catapulte();
						OR -= 20;
					}					
					else cout << "Or pas suffisant!!" << endl;
					break;
				}
			}
		else cout<<"Pas de place pour B!!"<<endl;
		}
	}

	void etreAttaque(int atk){
		HP = HP - atk;
		if(HP <= 0){
			HP = 0;
			cout<<"Cette base est detruit.."<<endl;
		}
	}
	int getHP(){ return HP; }
	int getOR(){ return OR; }
};
