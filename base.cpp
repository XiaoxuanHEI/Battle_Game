#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "solda.h"

#define MIN 0    //随机数产生的范围
#define MAX 3

using namespace std;
extern int FlagA;
extern int FlagB;
extern int AImode;
extern Unite *AllSolda[12];


Base::Base(int camp){
		HP = 100;
		OR = 8;
		Camp = camp;
}

void Base::CreatUnite(){
	if(Tour == 0){
		if(AllSolda[0] == NULL) {
LabelA:	FlagA = 0;
			FlagB = 0;
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
						// cout << FlagA<<endl;
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
					// cout << FlagA<<endl;
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
				exit(0);
			default:
				cout << "Il n'existe pas ce type!!" << endl;
				cout << "Choisir un autre type de solda:" << endl;
				goto LabelA;
			}
		}
		}
		else cout << "Pas de place pour A!" << endl;
	}

	if(Tour == 1 && AImode == 0){
		if(AllSolda[11] == NULL) {
LabelB: FlagA = 0;
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
					// cout << "Or pas suffisant pour un Fantassin!!" << endl;
					cout << Tour <<  endl;
					cout << FlagA << endl;
					cout << FlagB << endl << endl << endl;
				 	cout << "Choisir un autre type de solda:" << endl;
					// FlagB = 0;
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
				exit(0);
			default:
				cout << "Il n'existe pas ce type!" << endl;
				cout << "Choisir un autre type de soldat:" << endl;
				goto LabelB;
			}
		}
		}
	else cout << "Pas de place pour B!" << endl;
	}


	else if(Tour == 1 && AImode == 1){
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
				else
				{
					// cout << "Or pas suffisant pour un Fantassin!!" << endl;
					cout << Tour <<  endl;
					cout << FlagA << endl;
					cout << FlagB << endl << endl << endl;
				 	cout << "Choisir un autre type de solda:" << endl;
					// FlagB = 0;
					goto LabelB1;
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
					goto LabelB1;
				}
				break;

			case 3:
				if(OR>=20) {
					AllSolda[11] = new Catapulte();
					OR -= 20;
				}:
				else
				{
					cout << "Or pas suffisant pour un Catapulte!" << endl;
				 	cout << "Choisir un autre type de soldat:" << endl;
					goto LabelB1;
				}
				break;
			}

		}
	else cout << "Pas de place pour B!" << endl;

	}
}

void Base::etreAttaque(Unite* u){
		HP = HP - u->getATK();
}
