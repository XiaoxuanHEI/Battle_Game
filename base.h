#ifndef _BASE_H_
#define _BASE_H_
#include "unite.h"

class Base {
public:
	int HP;
	int OR;
	int Camp;
	Base(int camp);
	void CreatUnite();
	void etreAttaque(Unite* u);
	int getHP(){
		return HP;
	}
	int getOR(){
		return OR;
	}
	void setOR(){
		OR = 500;
	}
	void setHP() {
		HP = 0;
	}
};

#endif
