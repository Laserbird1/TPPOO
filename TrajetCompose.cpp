/**************************************************************************************
 TrajetCompose  -  Réalisation
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "Tableau.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher()const{
        
        cout <<"Trajet Compose "<<villeDepart <<" - "<<villeArrivee<<" :"<<endl ;
    
        for (unsigned int i=0 ; i<ensEtapes->getTailleActuelle() ; i++)
        {
		int etape=i+1;//pour commencer à compter le nombre d'étapes de 1 
		cout <<"    Etape "<<etape<<" : ";
            (ensEtapes->getElement(i))->Afficher() ;
            //on fait appel à la fonction Afficher du Trajet stocké. 
        }
}//----- Fin de Méthode Afficher


const char* TrajetCompose::getVilleDepart() const
{
    return villeDepart ;
} //----- Fin de Méthode getVilleDepart


const char* TrajetCompose::getVilleArrivee() const
{
    return villeArrivee ;
} //----- Fin de Méthode getVilleArrivee

const char TrajetCompose::getType() 
{
    return 'C' ; 
}

const char* TrajetCompose::getModeTransport() const
{
    return "compose";
}

void TrajetCompose::outputFormate() const 
{
   cout<<villeDepart<<','<<villeArrivee<<endl; 
   unsigned int tailleA = ensEtapes->getTailleActuelle() ; 
  for (unsigned int i=0 ; i<tailleA; i++)
  {
    ensEtapes->getElement(i))->outputFormate() ;
  }
  
  //attention, le \0 de villedepart et de villearrivee ne sera pas present lors de l'affichage 
}

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose (char* vD,char* vA, Tableau* etapes) : Trajet(vD,vA), ensEtapes (etapes)
{
#ifdef MAP
    cout<< "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    
    delete ensEtapes ; //appel au destructeur de Tableau
	
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

