#include <iostream>
#include <string>
#include "tinyxml.h"
#include "base.h"
#include "solda.h"

extern int Tour;
extern int Mode;
extern int AImode;
extern int Round;
extern Unite *AllSolda[12];
extern Base *A;
extern Base *B;

FILE *mem;
void save();
int load();

void save() {
  TiXmlDocument xmlDocument;

  xmlDocument.LinkEndChild(new TiXmlDeclaration( "1.0", "GBK", "" ));

  TiXmlElement * xmlRoot = new TiXmlElement("root");
  xmlDocument.LinkEndChild(xmlRoot);

  xmlRoot->SetAttribute("mode", Mode);
  xmlRoot->SetAttribute("AImode", AImode);
  xmlRoot->SetAttribute("round", Round);
  xmlRoot->SetAttribute("tour", Tour);

  TiXmlElement* xmlChild1 = new TiXmlElement("BaseA");
  xmlRoot->LinkEndChild(xmlChild1);
  xmlChild1->SetAttribute("HP", A->HP);
  xmlChild1->SetAttribute("OR", A->OR);

  TiXmlElement* xmlChild2 = new TiXmlElement("BaseB");
  xmlRoot->LinkEndChild(xmlChild2);
  xmlChild2->SetAttribute("HP", B->HP);
  xmlChild2->SetAttribute("OR", B->OR);

  for(int i = 0; i<12; i++) {
    if(AllSolda[i] != NULL) {
      TiXmlElement* xmlChild3 = new TiXmlElement("soldier");
      xmlRoot->LinkEndChild(xmlChild3);
      TiXmlElement* xmlChild3_01 = new TiXmlElement("name");
      xmlChild3->LinkEndChild(xmlChild3_01);

      if(AllSolda[i]->getNom() == "Fant"){
        xmlChild3_01->LinkEndChild(new TiXmlText("Fantassin"));
      }
      else if(AllSolda[i]->getNom() == "Arch"){
        xmlChild3_01->LinkEndChild(new TiXmlText("Archer"));
      }
      else if(AllSolda[i]->getNom() == "Cata"){
        xmlChild3_01->LinkEndChild(new TiXmlText("Catapulte"));
      }
      xmlChild3->SetAttribute("HP", AllSolda[i]->getHP());
      xmlChild3->SetAttribute("camp", AllSolda[i]->getCamp());
      xmlChild3->SetAttribute("position", AllSolda[i]->getPosition());
    }
  }

  xmlDocument.SaveFile("memory.xml");

}

int load() {
  TiXmlDocument xmlDocument("memory.xml");
	if (!xmlDocument.LoadFile())
	{
    cout << "Il n'y a pas d'enregistrement! " << endl;
		return -1;
	}

	TiXmlElement* xmlRoot = xmlDocument.RootElement();
	if (xmlRoot == NULL)
	{
		return -1;
	}

  xmlRoot->QueryIntAttribute("mode", &Mode);
  xmlRoot->QueryIntAttribute("AImode", &AImode);
  xmlRoot->QueryIntAttribute("round", &Round);
  xmlRoot->QueryIntAttribute("tour", &Tour);

	//获取子节点信息1
	TiXmlElement* xmlNode1 = xmlRoot->FirstChildElement("BaseA");
	xmlNode1->QueryIntAttribute("HP", &A->HP);
  xmlNode1->QueryIntAttribute("OR", &A->OR);
  A->Camp = 0;

	//获取子节点信息2
  TiXmlElement* xmlNode2 = xmlRoot->FirstChildElement("BaseB");
  xmlNode2->QueryIntAttribute("HP", &B->HP);
  xmlNode2->QueryIntAttribute("OR", &B->OR);
  B->Camp = 1;

  TiXmlElement* xmlNode3 = xmlRoot->FirstChildElement("soldier");
  int p,hp,camp;
  for(int i = 0; i<12; i++) {
    AllSolda[i] = NULL;
  }

  for (; xmlNode3 != NULL; xmlNode3 = xmlNode3->NextSiblingElement() ) {
    for(int i = 0; i<12; i++) {
      xmlNode3->QueryIntAttribute("position", &p);
      if (i == p) {
        cout << p <<endl;
        xmlNode3->QueryIntAttribute("HP", &hp);
        xmlNode3->QueryIntAttribute("camp", &camp);
        TiXmlElement* xmlNode3_01 = xmlNode3->FirstChildElement("name");
  	    if(!strcmp(xmlNode3_01->GetText(), "Fantassin")) {
          AllSolda[i] = new Fantassin(p);
        }
        else if(!strcmp(xmlNode3_01->GetText(), "Archer")) {
          AllSolda[i] = new Archer(p);
        }
        else if(!strcmp(xmlNode3_01->GetText(), "Catapulte")) {
          AllSolda[i] = new Catapulte(p);
        }
        AllSolda[i]->setHP(hp);
        AllSolda[i]->setCamp(camp);
        AllSolda[i]->setTimesATK();
      }
      else continue;
    }
  }
  return 0;
}
