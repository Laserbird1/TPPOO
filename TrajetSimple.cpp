/**************************************************************************************
 TrajetSimple  -  Réalisation
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const
{
    cout <<"Trajet " <<villeDepart << " - "<<villeArrivee<<" ( "<<modeTransport<<" )"<< endl ; 
} //----- Fin de Méthode Afficher

const char* TrajetSimple::getVilleDepart() const
{
    return villeDepart ;
}//----- Fin de Méthode getVilleDepart

const char* TrajetSimple::getVilleArrivee() const
{
    return villeArrivee ;
}//----- Fin de Méthode getVilleArrivee

const char* TrajetSimple::getModeTransport() const
{
    return modeTransport ;
}//----- Fin de Méthode getModeTransport

char TrajetSimple::getType()
{
    return 'S' ;
}//----- Fin de Méthode getType

void TrajetSimple::outputFormate() const 
{
  cout<<villeDepart<<','<<villeArrivee<<','<<modeTransport<<endl; 
}
//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple (char* vD,char* vA, char* leMode) : Trajet(vD, vA), modeTransport(leMode)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    modeTransport = new char[strlen(leMode)+1]; //copie en profondeur
    strcpy(modeTransport,leMode);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete [] modeTransport; 
} //----- Fin de ~TrajetSimple

