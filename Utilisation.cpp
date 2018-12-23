/***************************************************************************************
  Utilisation  -  Réalisation
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Réalisation du module <Utilisation> (fichier Utilisation.cpp)

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Utilisation.h"
#include "Catalogue.h"

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ()
// Algorithme : Tant que le menu du catalogue renvoit faux, on continue de solliciter ce dernier car
// il ne passe à vrai que si l'utilisateur choisi de quitter. 
//
{
	Catalogue *c=new Catalogue();
    //(*c).Menu() ;
	while (!(*c).Menu())
	{
	
	}

    delete c ; 
    return 0 ; 
} //----- fin de main

