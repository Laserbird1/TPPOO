/**************************************************************************************
 TrajetCompose  -  Interface
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Tableau.h"
#include <stdlib.h>
#include <string.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Tableau ;
//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//La classe TrajetCompose est une classe fille de Trajet : elle en hérite
//publiquement et se définit donc comme un trajet entre une ville A et
//une ville B, composé de plusieurs étapes. Une étape est un Trajet.
//Un TrajetCompose comporte au minimum deux étapes.
//Ses étapes sont comprises dans un Tableau d'addresse de Trajet ordonné dans le sens
//du trajet. Ce Tableau a donc une taille minimum de deux. Les Trajets dont les addresses
//sont stockées dans ce Tableau sont cohérents entre eux : la ville d'arrivée du premier
//correspond à la ville de départ du second, etc. Ces vérifications sont faites dans la
//classe Catalogue, avant la création du trajet.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    //Mode d'emploi : Affiche les caractéristiques du TrajetCompose (Ville
    //de depart et d'arrivée, suivit de toutes les caractéristiques de
    //ses étapes).
    //contrat : Le tableau n'est pas vide
    
    const char* getVilleDepart() const;
    //Mode d'emploi : Renvoie un pointeur sur la valeur de la ville de départ
    //de l'instance du TrajetCompose. (qui est non modifiable).
    //contrat : Le tableau n'est pas vide (car sinon, indéfini...)
    
    const char* getVilleArrivee() const;
    //Mode d'emploi : Renvoie un pointeur sur la valeur de la ville d'arrivée
    //de l'instance du TrajetCompose. (qui est non modifiable).
    //contrat : Le tableau n'est pas vide (car sinon, indéfini...)
    
    const char getType() ;
    //Mode d'emploi : renvoie C
    
    const char* getModeTransport() const  ;
    //Mode d'emploi : Renvoie "compose" 

    void outputFormate() const ; 
    
//-------------------------------------------- Constructeurs - destructeur


    TrajetCompose (char* vD, char*vA,Tableau* etapes);
    // Mode d'emploi :
    //La construction d'un TrajetCompose s'appuie sur la construction
    //d'un Trajet (vD et vA). etapes est un tableau de pointeurs de trajets constituant
    //le trajetcompose a construire. 
    //
    // Contrat : Les noms des villes ne contiennent pas d'espaces
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // Destruction des attributs du trajet 
    // Contrat :
    // aucun 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Tableau* ensEtapes ;
//----------------------------------------------------- Attributs protégés

};



#endif // TrajetCompose_H

