#include <iostream>
#include <string>
#include "base.cpp"
using namespace std;

// int Post[12] = {0};
Unite *AllSolda[12];
// int MarkAllSolda = 0;
int Tour = 0; // tour = 0, tour de A; tour = 1, tour de B;
int FlagA;
int FlagB;
Base *A = new Base(0);
Base *B = new Base(1);

void affiche();
void action1();
string getSoldaType(int position);
string getSoldaHp(int position);

int main(int argc, char const *argv[]) {
  affiche();
  cout << "Premiere tour: Commencer par joueur A:"<<endl;
  cin >> FlagA;
  A -> CreatUnite(FlagA);
  Tour = 1;
  cout << "Premiere tour: joueur B:"<<endl;
  cin >> FlagB;
  B -> CreatUnite(FlagB);
  Tour = 0;
  affiche();
  action1();
  return 0;
}

void affiche(){
  cout << "|A\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|B\t"<<"|\t"<<'\n';
  cout << "|HP:"<<A -> getHP()<<"\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|HP:"<<B -> getHP()<<"\t"<<"|\t"<<'\n';
  cout << "|OR:"<<A -> getOR()<<"\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|\t"<<"|OR:"<<B -> getOR()<<"\t"<<"|\t"<<'\n';
  cout << "|"<<getSoldaType(0)<<"\t"<<"|"<<getSoldaType(1)<<"\t"<<"|"<<getSoldaType(2)<<"\t"<<"|"<<getSoldaType(3)<<"\t"<<"|"<<getSoldaType(4)
  <<"\t"<<"|"<<getSoldaType(5)<<"\t"<<"|"<<getSoldaType(6)<<"\t"<<"|"<<getSoldaType(7)<<"\t"<<"|"<<getSoldaType(8)<<"\t"<<"|"<<getSoldaType(9)
  <<"\t"<<"|"<<getSoldaType(10)<<"\t"<<"|"<<getSoldaType(11)<<"\t"<<"|\t"<<'\n';
  cout << "|"<<getSoldaHp(0)<<"\t"<<"|"<<getSoldaHp(1)<<"\t"<<"|"<<getSoldaHp(2)<<"\t"<<"|"<<getSoldaHp(3)<<"\t"<<"|"<<getSoldaHp(4)
  <<"\t"<<"|"<<getSoldaHp(5)<<"\t"<<"|"<<getSoldaHp(6)<<"\t"<<"|"<<getSoldaHp(7)<<"\t"<<"|"<<getSoldaHp(8)<<"\t"<<"|"<<getSoldaHp(9)
  <<"\t"<<"|"<<getSoldaHp(10)<<"\t"<<"|"<<getSoldaHp(11)<<"\t"<<"|\t"<<'\n';
}

string getSoldaType(int position){
  // for(int i = 0; i<12; i++){
  //   if(AllSolda[i] == NULL) return "0";
  //   if(AllSolda[i] -> getPosition() == position)
  //   {
  //     return AllSolda[i] -> getNom();
  //   }
  // }
  // return " ";
  if(AllSolda[position] == NULL) return " ";
  return AllSolda[position] -> getNom();
}

string getSoldaHp(int position){
  // for(int i = 0; i<12; i++){
  //   if(AllSolda[i] == NULL) return "0";
  //   if(AllSolda[i] -> getPosition() == position)
  //   {
  //     return to_string(AllSolda[i] -> getHP());
  //   }
  // }
  // return " ";
  if(AllSolda[position] == NULL) return " ";
  return to_string(AllSolda[position] -> getHP());
}

void action1(){
  Unite *AllSoldaA[12];
  Unite *AllSoldaB[12];
  int markA = 0;
  int markB = 0;
  for(int i = 0; i < 12; i++)
  {
    if(AllSolda[i] = NULL) continue;
    if(AllSolda[i] -> getCamp() == 0)
    {
      AllSoldaA[markA] = AllSolda[i];
      markA++;
    }
    else if(AllSolda[i] -> getCamp() == 1)
    {
      AllSoldaA[markB] = AllSolda[i];
      markB++;
    }
  }
  cout<<"bien stocke!!!!!"<<endl;
  if(Tour == 0)
  {
    for(int i = 0; i < markA; i++)
    {
      int distance = AllSoldaB[0] - AllSoldaA[i];
      for(int j = 0; j < 3; j++)
      {
        if(distance = (AllSoldaA[i] -> getPorte())[j])
        {
          AllSoldaB[0] -> etreAttaque(AllSoldaA[i] -> getATK());
        }
      }
    }
  }
}
