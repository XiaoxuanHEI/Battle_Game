#include <iostream>
#include <string>
#include "base.cpp"
using namespace std;

// int Post[12] = {0};
Unite *AllSolda[12];

Unite *AllSoldaA[12];
Unite *AllSoldaB[12];
int markA = 0;
int markB = 0;

// int MarkAllSolda = 0;
int Tour = 0; // tour = 0, tour de A; tour = 1, tour de B;
int Round;
int FlagA;
int FlagB;
Base *A = new Base(0);
Base *B = new Base(1);

void affiche();
void sort();
void preparer();
void actionTotal();
void action1();
void action2();
void action3();
string getSoldaType(int position);
string getSoldaHp(int position);

int main(int argc, char const *argv[]) {
  for(Round = 1; Round <= 10; Round++){
    A->OR+=8;
    B->OR+=8;
    cout << "Tour " << Round << " START!" << endl;
    affiche();
    // cin >> FlagA;
    if(Round == 1)
    {
      cout << "Joueur A creat un soldat:"<<endl;
      A -> CreatUnite();
      Tour = 1;
      cout << "Joueur B creat un soldat:"<<endl;
      B -> CreatUnite();
      cout <<"Tour "<<Round<<" est fini!"<<endl;
      cout << endl;
      Tour = 0;
      continue;
    }
    cout << endl;
    cout <<Round<< " tour: joueur A actionne!"<<endl;
    actionTotal();
    cout << "Joueur A creat un soldat:"<<endl;
    A -> CreatUnite();
    affiche();
    Tour = 1;
    cout << endl;
    cout <<Round<< " tour: joueur B actionne!"<<endl;
    actionTotal();
    cout << "Joueur B creat un soldat:"<<endl;
    B -> CreatUnite();
    affiche();
    cout <<"Tour "<<Round<<" est fini!"<<endl;
    // cout << endl;
    Tour = 0;
    cout<<endl<<endl;
  }
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
  if(AllSolda[position] == NULL) return " ";
  return AllSolda[position] -> getNom();
}

string getSoldaHp(int position){
  if(AllSolda[position] == NULL) return " ";
  return to_string(AllSolda[position] -> getHP());
}

void actionTotal(){
  sort();
  action1();
  cout<<"Resultat de Action1: "<<endl;
  affiche();
  sort();

  action2();
  cout<<"Resultat de Action2: "<<endl;
  affiche();
  sort();

  action3();
  cout<<"Resultat de Action3: "<<endl;
  affiche();

  // preparer();
  // affiche();
}

// void preparer(){
//   cout<<endl<<endl;
//   cout <<Round<< " tour: joueur A:"<<endl;
//   cin >> FlagA;
//   A -> CreatUnite(FlagA);
//   Tour = 1;
//   cout <<Round<< " tour: joueur B:"<<endl;
//   cin >> FlagB;
//   B -> CreatUnite(FlagB);
//   Round++;
//   Tour = 0;
// }

void sort(){
  for(int i = 0; i < 12; i++)
  {
    AllSoldaA[i] = NULL;
    AllSoldaB[i] = NULL;
  }
  markA = 0;
  markB = 0;

  for(int i = 0; i < 12; i++)
  {
    if(AllSolda[i] == NULL) continue;
    else if(AllSolda[i] -> getCamp() == 0)
    {
      AllSoldaA[markA] = AllSolda[i];
       //cout<<"A0  "<<AllSoldaA[0] -> getPosition()<<endl;
      markA++;
    }
    else if(AllSolda[i] -> getCamp() == 1)
    {
      AllSoldaB[markB] = AllSolda[i];
      // cout<<"B0  "<<AllSoldaB[0] -> getPosition()<<endl;
      markB++;
    }
  }
  // cout<<"bien stocke!!!!!"<<endl;
}

void action1(){
  if(Tour == 0)
  {
    for(int i = 0; i < markA; i++)
    {
       //cout<<AllSoldaA[0] -> getPosition()<<endl;
      // cout<<AllSoldaB[0] -> getPosition()<<endl;
      if(AllSoldaB[0] != NULL){
        int distance = (AllSoldaB[0] -> getPosition()) - (AllSoldaA[i] -> getPosition());
      // cout<<"distance is "<<distance<<endl;
        for(int j = 0; j < 3; j++)
        {
          if(distance == (AllSoldaA[i] -> getPorte())[j])
          {
            AllSoldaA[i] -> attaquer();
            AllSoldaB[0] -> etreAttaque(AllSoldaA[i] -> getATK());
            // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
          }
        }
      }
      else{
        int distance = 11 - (AllSoldaA[i] -> getPosition());
      // cout<<"distance is "<<distance<<endl;
        for(int j = 0; j < 3; j++)
        {
          if(distance == (AllSoldaA[i] -> getPorte())[j])
          {
            AllSoldaA[i] -> attaquer();
            B -> etreAttaque(AllSoldaA[i] -> getATK());
            // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
          }
        }
      }
    }
  }
 //Tour = 1;
  if(Tour == 1)
  {
    for(int i = markB - 1; i >= 0; i--)
    {
      // cout<<AllSoldaA[0] -> getPosition()<<endl;
      // cout<<AllSoldaB[0] -> getPosition()<<endl;
      if(AllSoldaA[0] != NULL) {
        int distance = (AllSoldaB[i] -> getPosition()) - (AllSoldaA[markA - 1] -> getPosition());
      // cout<<"distance is "<<distance<<endl;
        for(int j = 0; j < 3; j++)
        {
          if(distance == (AllSoldaB[i] -> getPorte())[j])
          {
            AllSoldaB[i] -> attaquer();
            AllSoldaA[markA - 1] -> etreAttaque(AllSoldaB[i] -> getATK());
            // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
          }
        }
      }
      else{
        int distance = (AllSoldaB[i] -> getPosition());
      // cout<<"distance is "<<distance<<endl;
        for(int j = 0; j < 3; j++)
        {
          if(distance == (AllSoldaB[i] -> getPorte())[j])
          {
            AllSoldaB[i] -> attaquer();
            A -> etreAttaque(AllSoldaA[i] -> getATK());
            // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
          }
        }
      }
    }
  }
//  Tour = 0;
}

void action2(){
  if(Tour == 0)
  {
    for(int i = markA-1; i >= 0; i--)
    {
      if(AllSoldaA[i] -> getNom() == "Cata")
      continue;
      AllSoldaA[i] -> avancer();
    }
  }
//  Tour = 1;

  if(Tour == 1)
  {
    for(int i = 0; i < markB; i++)
    {
      if(AllSoldaB[i] -> getNom() == "Cata")
      continue;
      AllSoldaB[i] -> avancer();
    }
  }
//  Tour = 0;
}

void action3(){
  if(Tour == 0)
  {
    for(int i = markA-1; i >=0; i--)
    {
      // cout<<"hahahahha"<<endl;
      // cout<<AllSoldaA[0] -> getPosition()<<endl;
      // cout<<AllSoldaB[0] -> getPosition()<<endl;
      if(AllSoldaA[i] -> getNom() == "Fant")
      {
        if(AllSoldaA[i] -> getTimesATK() == 0)
        {
          if(AllSoldaB[0] != NULL) {
            int distance = (AllSoldaB[0] -> getPosition()) - (AllSoldaA[i] -> getPosition());
          // cout<<"distance is "<<distance<<endl;
            for(int j = 0; j < 3; j++)
            {
              if(distance == (AllSoldaA[i] -> getPorte())[j])
              {
                AllSoldaA[i] -> attaquer();
                AllSoldaB[0] -> etreAttaque(AllSoldaA[i] -> getATK());
                // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
              }
            }
          }
        }
      }
      else if(AllSoldaA[i] -> getNom() == "Cata")
      {
        if(AllSoldaA[i] -> getTimesATK() == 0)
        {
          AllSoldaA[i] -> avancer();
        }
      }
    }
  }

// Tour = 1;

 if(Tour == 1)
 {
   for(int i = 0; i < markB; i++)
   {
     // cout<<AllSoldaA[0] -> getPosition()<<endl;
     // cout<<AllSoldaB[0] -> getPosition()<<endl;
     if(AllSoldaB[i] -> getNom() == "Fant")
     {
       if(AllSoldaB[i] -> getTimesATK() == 0)
       {
         if(AllSoldaA[0] != NULL) {
          int distance = (AllSoldaB[i] -> getPosition()) - (AllSoldaA[markA-1] -> getPosition());
         // cout<<"distance is "<<distance<<endl;
           for(int j = 0; j < 3; j++)
           {
             if(distance == (AllSoldaB[i] -> getPorte())[j])
             {
               AllSoldaB[i] -> attaquer();
               AllSoldaA[markA-1] -> etreAttaque(AllSoldaB[i] -> getATK());
               // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
             }
           }
         }
       }
     }
     else if(AllSoldaB[i] -> getNom() == "Cata")
     {
       if(AllSoldaB[i] -> getTimesATK() == 0)
       {
         AllSoldaB[i] -> avancer();
       }
     }
   }
 }
//Tour = 0;
}
