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
		switch(flag)
		{
		case 0:
			break;
		case 1:
			AllSolda[0] =  new Fantassin();
			// MarkAllSolda++;
			break;
		case 2:
		 	AllSolda[0] = new Archer();
			// MarkAllSolda++;
			break;
		case 3:
		 	AllSolda[0] = new Catapulte();
			// MarkAllSolda++;
			break;
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
