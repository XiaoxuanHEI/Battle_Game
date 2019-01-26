#include <iostream>
#include "solda.h"

using namespace std;

extern Unite *AllSolda[12];
// extern int MarkAllSolda;

class Base{
protected:
	int HP;
	int OR;
	int Camp;
public:
	Base(int camp){
		HP = 100;
		OR = 8;
		Camp = camp;
	}
	void CreatUnite(int flag){
			if(Tour == 0)
				if(AllSolda[0] == NULL) {
					switch(flag)
					{
					case 0:
						break;
					case 1:
						AllSolda[0] =  new Fantassin();
						break;
					case 2:
						AllSolda[0] = new Archer();
						break;
					case 3:
						AllSolda[0] = new Catapulte();
						break;
					}
				}
				else cout<<"Pas de place pour A!!"<<endl;
			if(Tour == 1){
				if(AllSolda[11] == NULL) {
					switch(flag)
					{
					case 0:
						break;
					case 1:
						AllSolda[11] =  new Fantassin();
						break;
					case 2:
						AllSolda[11] = new Archer();
						break;
					case 3:
						AllSolda[11] = new Catapulte();
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
