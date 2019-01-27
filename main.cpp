#include <iostream>
#include <string>
#include <unistd.h>
#include "unite.cpp"
#include "base.cpp"

using namespace std;

Unite *AllSolda[12]; //tableau qui stocke tous les unites qui sont vives

Unite *AllSoldaA[12]; //tableau qui stocke tous les unite de A en order position
Unite *AllSoldaB[12]; //tableau qui stocke tous les unite de B en order position
int markA = 0; // un 'pointeur' pour AllSoldaA[]
int markB = 0; // un 'pointeur' pour AllSoldaB[]

int Tour = 0; // 0 tour de A / 1 tour de B;
int Mode = 0; // mode rapide 0 / mode precis 1.
int AImode = 0; // mode joueur vs joueur 0 / joueur vs computer 1;

int Round; // le numero de tour actual

Base *A = new Base(0);
Base *B = new Base(1);

void affiche(); //actualiser l'ecran et afficher le jeu
void gameover();
void sort(); //tirer les unites de AllSolda[] a AllSoldaA[] et AllSoldaB[] en ordre

void actionTotal();//contenir les 3 actions et actualiser les AllSoldaA et AllSoldaB apres chaque action
void action1();
void action2();
void action3();
string getSoldaType(int position);
string getSoldaCamp(int position);
string getSoldaHp(int position);

int main(int argc, char const *argv[]) {
  cout<<endl<<"mode rapide ou mode precis?  0 rapide / 1 precis   ";
  cin>>Mode;
  cout<<endl<<"jouer avec computer?  0 vs Joueur / 1 vs Computer   ";
  cin>>AImode;

  for(Round = 1; Round <= 1000; Round++){
    A->OR+=8;
    B->OR+=8;
    affiche();
    sleep(1);
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
    cout << endl<<endl;
    Tour = 0;
    if(A -> getOR() >= 500) // une limite 500 pour nombre d'OR
    {
      A -> setOR();
    }
    if(B -> getOR() >= 500) // une limite 500 pour nombre d'OR
    {
      B -> setOR();
    }
  }
  affiche();
  cout<<endl<<"Vous avez passe 1000 tours, il y a pas un vainqueur!"<<endl;
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
  affiche();
  sort();

  action2();
  affiche();
  sort();

  action3();
  affiche();
}

void sort(){
  /*initialiser les tableau et ses 'pointeurs' pour eviter des ambigues*/
  for(int i = 0; i < 12; i++)
  {
    AllSoldaA[i] = NULL;
    AllSoldaB[i] = NULL;
  }
  markA = 0;
  markB = 0;

  /*parcourir le AllSolda[] pour tirer des unites*/
  for(int i = 0; i < 12; i++)
  {
    if(AllSolda[i] == NULL) continue;
    else if(AllSolda[i] -> getCamp() == 0)
    {
      AllSoldaA[markA] = AllSolda[i];
      markA++;
    }
    else if(AllSolda[i] -> getCamp() == 1)
    {
      AllSoldaB[markB] = AllSolda[i];
      markB++;
    }
  }
}

void action1(){
  /*Tour ici pour distinguer qui et en train de jouer: 0 est A, 1 est B*/
  if(Tour == 0)
  {
    for(int i = 0; i < markA; i++)
    {
      if(AllSoldaB[0] != NULL){
        /*calculer la distance entre cette unite de A et l'unite de B plus proche de la base A */
        int distance = (AllSoldaB[0] -> getPosition()) - (AllSoldaA[i] -> getPosition());
        for(int j = 0; j < 3; j++)
        {
          /*verifier si la distance calcule existe dans la portee de cette unite de A*/
          if(distance == (AllSoldaA[i] -> getPorte())[j])
          {
            /*
             si oui, verifier si cette unite est une catapulte.
             une catapulte peut attaquer 2 points: 2,3 ou 3,4
             cas particulie:
             si distance ici egale 4, la catapulte ne peut attaquer qu'une seul unite (4 et deja la plus proche)
             si distance ici egale 2 ou 3, faut on trouver si il existe une unite d'ennemi dans la case a cote de celle-ci,
             - oui: attaquer les deux aux memes temps
             - non: n'attaquer que celle-ci
            */
            if((AllSoldaA[i] -> getNom() == "Cata") && distance != 4 )
            {
              if((AllSoldaB[1] != NULL) && ((AllSoldaB[1]-> getPosition() - AllSoldaA[i] ->getPosition()) == (distance + 1)))
              {
                AllSoldaA[i] -> attaquer(); // memoriser si l'action1 a excecute qui sert a organiser l'action3
                AllSoldaB[0] -> etreAttaque(AllSoldaA[i]); //effectuer l'attaque
                AllSoldaB[1] -> etreAttaque(AllSoldaA[i]);
                break;
              }
            }
            AllSoldaA[i] -> attaquer();
            AllSoldaB[0] -> etreAttaque(AllSoldaA[i]);
            break;
          }
        }
      }
      /*
        si AllSoldaA[] est NULL c-a-d il n'y a pas d'unite de B dans le champ.
        c-a-d il est possible pour A d'attaquer la base de B
      */
      else{
        int distance = 11 - (AllSoldaA[i] -> getPosition());
        for(int j = 0; j < 3; j++)
        {
          if(distance == (AllSoldaA[i] -> getPorte())[j])
          {
            AllSoldaA[i] -> attaquer();
            B -> etreAttaque(AllSoldaA[i]);
            if(B -> getHP() <= 0)
            {
              B -> setHP(); // HP est moins de 0 c'est bizzare.. donc on le rendra 0.
              gameover();
            }
          }
        }
      }
    }
  }
  /*Tour de B, tout est la meme sauf que la direction est en diverse.*/
  if(Tour == 1)
  {
    for(int i = markB - 1; i >= 0; i--)
    {
      if(AllSoldaA[0] != NULL) {
        int distance = (AllSoldaB[i] -> getPosition()) - (AllSoldaA[markA - 1] -> getPosition());
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
            break;
          }
        }
      }
      else{
        int distance = (AllSoldaB[i] -> getPosition());
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
          }
        }
      }
    }
  }
  /*cette partie est pour simuler une 'reflexion' de computeur.. le ralentir un peu si on est dans la mode precis*/
  if(Mode && Tour && AImode)
  {
    cout<<"Action1 est fini."<<endl;
    sleep(1);
  }
  /*si c'est un joueur reel, on pause*/
  else if(Mode == 1)
  {
  int c;
  cout<<endl;
  cout<<"Action1 est fini.   Countinuer? [ 8 pour quitter ] ";
  cin.ignore(1024,'\n'); //pour enlever le '\n' qu'on a taper tout de suite en entrant le c.
  c = cin.get();
  if(c != '\n') exit(0);
  }

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
  {
    cout<<"Action2 est fini."<<endl;
    sleep(1);
  }
  else if(Mode == 1)
  {
  int c;
  cout<<endl;
  cout<<"Action2 est fini.   Countinuer? [ 8 pour quitter ] ";
  c = cin.get();
  if(c != '\n') exit(0);
  }

}

void action3(){
  if(Tour == 0)
  {
    for(int i = markA-1; i >=0; i--)
    {
      if(AllSoldaA[i] -> getNom() == "Fant")
      {
        if(AllSoldaA[i] -> getTimesATK() == 0) //si il n'a pas applique l'action1 il va faire action3
        {
          if(AllSoldaB[0] != NULL) {
            int distance = (AllSoldaB[0] -> getPosition()) - (AllSoldaA[i] -> getPosition());
            for(int j = 0; j < 3; j++)
            {
              if(distance == (AllSoldaA[i] -> getPorte())[j])
              {
                AllSoldaA[i] -> attaquer();
                AllSoldaB[0] -> etreAttaque(AllSoldaA[i]);
              }
            }
          }
          else{
            int distance = 11 - (AllSoldaA[i] -> getPosition());
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
              }
            }
          }
        }
        else
        {
          AllSoldaA[i] -> setTimesATK(); // on inisialise l'etat a 'n'a pas applique action1'
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
            for(int j = 0; j < 3; j++)
            {
              if(distance == (AllSoldaA[i] -> getPorte())[j])
              {
                AllSoldaA[i] -> attaquer();
                AllSoldaB[0] -> etreAttaque(AllSoldaA[i]);
              }
            }
          }
          else{
            int distance = 11 - (AllSoldaA[i] -> getPosition());
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
              }
            }
          }
          AllSoldaA[i] -> setTimesATK();
        }
      }
    }

 if(Tour == 1)
 {
   for(int i = 0; i < markB; i++)
   {
     if(AllSoldaB[i] -> getNom() == "Fant")
     {
       if(AllSoldaB[i] -> getTimesATK() == 0)
       {
         if(AllSoldaA[0] != NULL) {
          int distance = (AllSoldaB[i] -> getPosition()) - (AllSoldaA[markA-1] -> getPosition());
           for(int j = 0; j < 3; j++)
           {
             if(distance == (AllSoldaB[i] -> getPorte())[j])
             {
               AllSoldaB[i] -> attaquer();
               AllSoldaA[markA-1] -> etreAttaque(AllSoldaB[i]);
             }
           }
         }
         else{
           int distance = (AllSoldaB[i] -> getPosition());
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
     else if(AllSoldaB[i] -> getNom() == "Super")
     {
       if(AllSoldaA[0] != NULL) {
        int distance = (AllSoldaB[i] -> getPosition()) - (AllSoldaA[markA-1] -> getPosition());
         for(int j = 0; j < 3; j++)
         {
           if(distance == (AllSoldaB[i] -> getPorte())[j])
           {
             AllSoldaB[i] -> attaquer();
             AllSoldaA[markA-1] -> etreAttaque(AllSoldaB[i]);
           }
         }
       }
       else{
         int distance = (AllSoldaB[i] -> getPosition());
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
           }
         }
       }
       AllSoldaB[i] -> setTimesATK();
     }
   }
 }
 if(Mode && Tour && AImode)
 {
   cout<<"Action3 est fini."<<endl;
   sleep(1);
 }
 else if(Mode == 1)
 {
 int c;
 cout<<endl;
 cout<<"Action3 est fini.   Countinuer? [ 8 pour quitter ] ";
 c = cin.get();
 if(c != '\n') exit(0);
 }
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
