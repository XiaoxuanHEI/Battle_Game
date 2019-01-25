#include <iostream>
#include "solda.h"

using namespace std;

extern Unite *AllSolda[12];
extern int MarkAllSolda;

class Base{
protected:
	int HP = 100;
	int OR = 8;
	int Camp;
public:
	Base(int camp){
		Camp = camp;
	}
	void CreatUnite(int flag){
		switch(flag)
		{
		case 1:
			AllSolda[MarkAllSolda] =  new Fantassin();
			MarkAllSolda++;
			break;
		case 2:
		 	AllSolda[MarkAllSolda] = new Archer();
			MarkAllSolda++;
			break;
		case 3:
		 	AllSolda[MarkAllSolda] = new Catapulte();
			MarkAllSolda++;
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
