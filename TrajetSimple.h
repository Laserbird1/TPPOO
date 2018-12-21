/**************************************************************************************
                           TrajetSimple  -  Interface
                             -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
***************************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) -----------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//La classe TrajetSimple est une classe fille de Trajet : elle en hérite
//publiquement. Elle définit un sous-type de Trajet ne comportant qu'une
//seule étape. (C'est un trajet direct). Elle se définit aussi par son mode
//de transport (char*) en plus de la ville de départ et d'arrivée définissant
//un Trajet.
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
    
//----------------------------------------------------- Méthodes publiques
   
    void Afficher() const;
    //Mode d'emploi : Affiche les caractéristiques du Trajet Simple (Ville
    //de depart, d'arrivée et mode de transport sur le terminal (sortie standard).
    
    const char* getVilleDepart() const;
    //Mode d'emploi : Renvoie un pointeur sur la valeur de la ville de départ
    //de l'instance du TrajetSimple. (qui est non modifiable).
    
    const char* getVilleArrivee() const;
    //Mode d'emploi : Renvoie un pointeur sur la valeur de la ville d'arrivée
    //de l'instance du TrajetSimple. (qui est non modifiable).
    
    const char* getModeTransport() const  ;
    //Mode d'emploi : Renvoie un pointeur sur la valeur du mode de transport
    //de l'instance du TrajetSimple. (qui est non modifiable).
    
    const char getType() ;
    //Mode d'emploi : renvoie S. 
    
    void outputFormate() const ; 
    //Mode d'emploi : 
    
    //-------------------------------------------- Constructeurs - destructeur

   
    TrajetSimple (char* vD,char* vA, char* leMode);
    // Mode d'emploi :
    //La construction d'un TrajetSimple s'appuie sur la construction d'un Trajet
    //on effectue un copie en profondeur de la valeur pointée par leMode dans modeTransport
    //
    // Contrat : Pas d'espace dans les noms d'attributs !
    

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //Destruction des attributs du TrajetSimple, en l'occurence ici
    //de modeTransport
    //
 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char* modeTransport ;
    
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

