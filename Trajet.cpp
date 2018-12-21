/**************************************************************************************
 Trajet  -  Réalisation
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet (char* vD, char*vA)
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    villeDepart = new char[strlen(vD)+1]; //copie en profondeur
    strcpy(villeDepart,vD) ;
    villeArrivee = new char[strlen(vA)+1];//copie en profondeur
    strcpy(villeArrivee,vA) ;
} //----- Fin de Trajet


Trajet::~Trajet ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif

	delete [] villeDepart ; 
	delete [] villeArrivee ; 
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

