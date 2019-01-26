#include <iostream>
#include <string>
#include <unistd.h>
#include "unite.cpp"
#include "base.cpp"

using namespace std;

// int Post[12] = {0};
Unite *AllSolda[12];

Unite *AllSoldaA[12];
Unite *AllSoldaB[12];
int markA = 0;
int markB = 0;

int Tour = 0; // tour = 0, tour de A; tour = 1, tour de B;
int Mode = 0; // mode rapide 0 ou mode precis 1.
int AImode = 0; // mode joueur vs joueur 0 ou joueur vs computer 1;

int Round;
int FlagA;
int FlagB;
Base *A = new Base(0);
Base *B = new Base(1);

void affiche();
void gameover();
void sort();
void preparer();
void actionTotal();
void action1();
void action2();
void action3();
string getSoldaType(int position);
string getSoldaCamp(int position);
string getSoldaHp(int position);

int main(int argc, char const *argv[]) {
  cout<<"mode rapide ou mode precis?  0 rapide / 1 precis   ";
  cin>>Mode;
  cout<<endl<<" jouer avec computer?  0 non / 1 oui   ";
  cin>>AImode;

  for(Round = 1; Round <= 1000; Round++){
    A->OR+=8;
    B->OR+=8;
    affiche();
    if(Round == 1)
    {
      cout <<endl<< "Joueur A creat un soldat: (1.Fantassin 2.Archer 3.Catapulte 0.Pass   [ 8.Qitter ce jeu ] )   ";
      A -> CreatUnite();
      Tour = 1;
      cout <<endl<< "Joueur B creat un soldat: (1.Fantassin 2.Archer 3.Catapulte 0.Pass   [ 8.Qitter ce jeu ] )   ";
      B -> CreatUnite();
      cout << endl;
      Tour = 0;
      continue;
    }
    // cout << endl;
    cout <<endl<<"Tour "<<(Round-1)<<" est fini!"<<endl<<endl;
    cout << "Tour "<<Round<< " joueur A actionne!"<<endl;
    actionTotal();
    cout <<endl<< "Joueur A creat un soldat: (1.Fantassin 2.Archer 3.Catapulte 0.Pass   [ 8.Qitter ce jeu ] )   ";
    A -> CreatUnite();
    affiche();
    Tour = 1;
    cout << endl;
    cout <<"Tour "<<Round<<" joueur B actionne!"<<endl;
    actionTotal();
    cout <<endl<< "Joueur B creat un soldat: (1.Fantassin 2.Archer 3.Catapulte 0.Pass   [ 8.Qitter ce jeu ] )   ";
    B -> CreatUnite();
    affiche();
    // cout << endl;
    Tour = 0;
    cout<<endl<<endl;
  }
  return 0;
}


void affiche(){
  system("clear");
  if(Mode == 0)
  cout<< "Mode rapide:                                  Tour " << Round << endl;
  else
  cout<< "Mode precis:                                  Tour " << Round << endl;

  cout<< "    |>                                                                                     <|    " <<endl;
  cout<< "    |                                                                                       |    " <<endl;
  cout<< "{~~~~~~~}       ^       ^       ^       ^       ^       ^       ^       ^       ^       [^^^^^^^]" <<endl;



  cout << "|"<<getSoldaCamp(0)<<"\t"<<"|"<<getSoldaCamp(1)<<"\t"<<"|"<<getSoldaCamp(2)<<"\t"<<"|"<<getSoldaCamp(3)<<"\t"<<"|"<<getSoldaCamp(4)
  <<"\t"<<"|"<<getSoldaCamp(5)<<"\t"<<"|"<<getSoldaCamp(6)<<"\t"<<"|"<<getSoldaCamp(7)<<"\t"<<"|"<<getSoldaCamp(8)<<"\t"<<"|"<<getSoldaCamp(9)
  <<"\t"<<"|"<<getSoldaCamp(10)<<"\t"<<"|"<<getSoldaCamp(11)<<"\t"<<"|\t"<<'\n';

  cout << "|"<<getSoldaHp(0)<<"\t"<<"|"<<getSoldaHp(1)<<"\t"<<"|"<<getSoldaHp(2)<<"\t"<<"|"<<getSoldaHp(3)<<"\t"<<"|"<<getSoldaHp(4)
  <<"\t"<<"|"<<getSoldaHp(5)<<"\t"<<"|"<<getSoldaHp(6)<<"\t"<<"|"<<getSoldaHp(7)<<"\t"<<"|"<<getSoldaHp(8)<<"\t"<<"|"<<getSoldaHp(9)
  <<"\t"<<"|"<<getSoldaHp(10)<<"\t"<<"|"<<getSoldaHp(11)<<"\t"<<"|\t"<<'\n';
  cout << "|"<<getSoldaType(0)<<"\t"<<"|"<<getSoldaType(1)<<"\t"<<"|"<<getSoldaType(2)<<"\t"<<"|"<<getSoldaType(3)<<"\t"<<"|"<<getSoldaType(4)
  <<"\t"<<"|"<<getSoldaType(5)<<"\t"<<"|"<<getSoldaType(6)<<"\t"<<"|"<<getSoldaType(7)<<"\t"<<"|"<<getSoldaType(8)<<"\t"<<"|"<<getSoldaType(9)
  <<"\t"<<"|"<<getSoldaType(10)<<"\t"<<"|"<<getSoldaType(11)<<"\t"<<"|\t"<<'\n';
  cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" <<endl;
  cout << "|       |-------------------------------------------------------------------------------|       |" <<endl;
  cout << "|Base A\t"<<"|-------------------------------- <            > -------------------------------"<<"|Base B\t"<<"|\t"<<'\n';
  cout << "|HP:"<<A -> getHP()<<"\t"<<"|-------------------------------- < AGE OF WAR > -------------------------------"<<"|HP:"<<B -> getHP()<<"\t"<<"|\t"<<'\n';
  cout << "|OR:"<<A -> getOR()<<"\t"<<"|-------------------------------- <            > -------------------------------"<<"|OR:"<<B -> getOR()<<"\t"<<"|\t"<<'\n';
  cout << "|||||||||-------------------------------------------------------------------------------|||||||||" <<endl;
}

string getSoldaType(int position){
  if(AllSolda[position] == NULL) return " ";
  if(AllSolda[position] -> getCamp())
  return " " + AllSolda[position] -> getNom();
  else return AllSolda[position] -> getNom();
}

string getSoldaCamp(int position){
  if(AllSolda[position] == NULL) return " ";
  if(AllSolda[position] -> getCamp())
  return "<--- B";
  else return "A --->";
}

string getSoldaHp(int position){
  if(AllSolda[position] == NULL) return " ";
  if(AllSolda[position] -> getCamp())
  return "   " + to_string(AllSolda[position] -> getHP());
  else return to_string(AllSolda[position] -> getHP());
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
}

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
            if((AllSoldaA[i] -> getNom() == "Cata") && distance != 4 )
            {
              if((AllSoldaB[1] != NULL) && ((AllSoldaB[1]-> getPosition() - AllSoldaA[i] ->getPosition()) == (distance + 1)))
              {
                AllSoldaA[i] -> attaquer();
                AllSoldaB[0] -> etreAttaque(AllSoldaA[i]);
                AllSoldaB[1] -> etreAttaque(AllSoldaA[i]);
                break;
              }
            }
            AllSoldaA[i] -> attaquer();
            AllSoldaB[0] -> etreAttaque(AllSoldaA[i]);
            break;
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
            B -> etreAttaque(AllSoldaA[i]);
            if(B -> getHP() <= 0)
            {
              B -> setHP();
              gameover();
            }
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
            if((AllSoldaB[i] -> getNom() == "Cata") && distance != 4 )
            {
              if((AllSoldaA[markA-2] != NULL) && ((AllSoldaB[i] -> getPosition())-(AllSoldaA[markA-2]-> getPosition()) == (distance + 1)))
              {
                AllSoldaB[i] -> attaquer();
                AllSoldaA[markA-1] -> etreAttaque(AllSoldaB[i]);
                AllSoldaA[markA-2] -> etreAttaque(AllSoldaB[i]);
                break;
              }
            }
            AllSoldaB[i] -> attaquer();
            AllSoldaA[markA - 1] -> etreAttaque(AllSoldaB[i]);
            // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
            break;
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
            A -> etreAttaque(AllSoldaB[i]);
            if(A -> getHP() <= 0)
            {
              A -> setHP();
              gameover();
            }
            // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
          }
        }
      }
    }
  }
  if(Mode && Tour && AImode)
  sleep(3);
  else if(Mode == 1)
  {
  int c;
  cout<<endl;
  cout<<"Action1 est fini.   Countinuer? [ 8 pour quitter ] ";
  cin.ignore(1024,'\n');
  c = cin.get();
  if(c != '\n') exit(0);
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
      if(AllSoldaA[i]->getPosition()==11) {
        AllSoldaA[i]->detruit();
        AllSoldaA[i] = NULL;
        markA--;
      }
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
      if(AllSoldaB[i]->getPosition()==0) {
        AllSoldaB[i]->detruit();
        AllSoldaB[i] = NULL;
        markB--;
      }
    }
  }
  if(Mode && Tour && AImode)
  sleep(3);
  else if(Mode == 1)
  {
  int c;
  cout<<endl;
  cout<<"Action2 est fini.   Countinuer? [ 8 pour quitter ] ";
  // cin.ignore(1024,'\n');
  c = cin.get();
  if(c != '\n') exit(0);
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
                AllSoldaB[0] -> etreAttaque(AllSoldaA[i]);
                // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
              }
            }
          }
        }
        else
        {
          AllSoldaA[i] -> setTimesATK();
        }
      }
      else if(AllSoldaA[i] -> getNom() == "Cata")
      {
        if(AllSoldaA[i] -> getTimesATK() == 0)
        {
          AllSoldaA[i] -> avancer();
        }
        else
        {
          AllSoldaA[i] -> setTimesATK();
        }
      }
      else if(AllSoldaA[i] -> getNom() == "Super")
      {
          if(AllSoldaB[0] != NULL) {
            int distance = (AllSoldaB[0] -> getPosition()) - (AllSoldaA[i] -> getPosition());
          // cout<<"distance is "<<distance<<endl;
            for(int j = 0; j < 3; j++)
            {
              if(distance == (AllSoldaA[i] -> getPorte())[j])
              {
                AllSoldaA[i] -> attaquer();
                AllSoldaB[0] -> etreAttaque(AllSoldaA[i]);
                // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
              }
            }
          }
          AllSoldaA[i] -> setTimesATK();
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
               AllSoldaA[markA-1] -> etreAttaque(AllSoldaB[i]);
               // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
             }
           }
         }
       }
       else
       {
         AllSoldaB[i] -> setTimesATK();
       }
     }
     else if(AllSoldaB[i] -> getNom() == "Cata")
     {
       if(AllSoldaB[i] -> getTimesATK() == 0)
       {
         AllSoldaB[i] -> avancer();
       }
       else
       {
         AllSoldaB[i] -> setTimesATK();
       }
     }
     else if(AllSoldaB[i] -> getNom() == "Fant")
     {
       if(AllSoldaA[0] != NULL) {
        int distance = (AllSoldaB[i] -> getPosition()) - (AllSoldaA[markA-1] -> getPosition());
       // cout<<"distance is "<<distance<<endl;
         for(int j = 0; j < 3; j++)
         {
           if(distance == (AllSoldaB[i] -> getPorte())[j])
           {
             AllSoldaB[i] -> attaquer();
             AllSoldaA[markA-1] -> etreAttaque(AllSoldaB[i]);
             // cout<<"hp "<<AllSoldaB[0]->getHP()<<endl;
           }
         }
       }
       AllSoldaB[i] -> setTimesATK();
     }
   }
 }
 if(Mode && Tour && AImode)
 sleep(3);
 else if(Mode == 1)
 {
 int c;
 cout<<endl;
 cout<<"Action3 est fini.   Countinuer? [ 8 pour quitter ] ";
 // cin.ignore(1024,'\n');
 c = cin.get();
 if(c != '\n') exit(0);
 }
//Tour = 0;
}

void gameover(){
  system("clear");
  affiche();
  if(Tour)
  {
    cout<<endl<<"Joueur B est ganie!!"<<endl;
  }
  else cout<<endl<<"Joueur A est ganie!!"<<endl;
  cout<<endl;
  exit(0);
}
