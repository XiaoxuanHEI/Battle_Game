#include <iostream>
#include "solda.h"

using namespace std;

class Base{
protected:
	int HP;
public:
	Unite *CreatUnite(int flag){
		switch(flag) {
		case 1: return new Fantassin();
			break;
		case 2: return new Archer();
			break;
		case 3: return new Catapulte();
			break;
		}
	}
	
	void etreAttaque(int atk){
		HP = HP - atk;
		if(HP <= 0){
			cout<<"Cette base est detruit.."<<endl;
		}
	}
};
