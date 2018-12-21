/**************************************************************************************
 Tableau  -  Réalisation
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/


//---------- Réalisation de la classe <Tableau> (fichier Tableau.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Tableau.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Tableau::AjoutTrajet(Trajet* adresse)
{
	
	if(tailleActuelle==tailleMax)//si le tableau est plein
	{
		
		Trajet** nouveau= new Trajet*[tailleMax+5];
		for(unsigned int i=0; i<(tailleMax); i++)
		{
			nouveau[i]=tableau[i];
		}
        tailleMax+=5;
		delete []tableau;//on delete le tableau
		tableau=nouveau;//on stock l'adresse du nouveau tableau
	}
        tailleActuelle++;
    
	tableau[tailleActuelle-1]=adresse; //on rajoute l'@ du nouveau trajet.
} //----- Fin de Méthode AjoutTrajet


unsigned int Tableau::getTailleActuelle() const
{
    return tailleActuelle ; 
} //----- Fin de Méthode getTailleActuelle

Trajet* Tableau::getElement(unsigned int i) const
{
    if (i<tailleActuelle){
        
        
        return  (tableau[i]);
    }
    else //si l'indice est hors-intervalle. 
    {
        return nullptr;
    }
} //----- Fin de Méthode getElement

void Tableau::Afficher()const
{
	cout<<"-----------------------------CATALOGUE---------------------------"<<endl;
	for(unsigned int i=0; i<tailleActuelle; i++)
        {
		tableau[i]->Afficher();
	}
    cout<<"-----------------------------------------------------------------"<<endl;
} //----- Fin de Méthode Afficher

//-------------------------------------------- Constructeurs - destructeur


Tableau::Tableau (unsigned int tailleMax )
// Algorithme : Si la tailleMax == 0 -> pas d'allocation dynamique dans le constructeur
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Tableau>" << endl;
#endif
    tailleActuelle = 0 ;
    this->tailleMax=tailleMax;
    tableau = (tailleMax==0) ? NULL : new Trajet*[tailleMax] ; 
} //----- Fin de Tableau (constructeur)


Tableau::~Tableau ( )
// Algorithme : Destruction des éléments du tableau puis du tableau lui-même pour
//libérer la mémoire

{
#ifdef MAP
    cout << "Appel au destructeur de <Tableau>" << endl;
#endif
    if (tableau!=NULL)
    {
        for (unsigned int i=0; i<tailleActuelle ; i++)
        {
            delete tableau[i] ;	
        }
        
        delete [] tableau ;
    }
} //----- Fin de ~Tableau


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

