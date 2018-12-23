
/**************************************************************************************
 Trajet  -  Interface
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

//--------------------------------------------------- Interfaces utilisées
#include <string.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
//Rôle de la classe <Trajet>
//
//La classe Trajet est une classe représentant un voyage d'une ville A à
//une ville B. C'est une classe abstraite qui nous sert à manipuler des objets
//hétérogènes dans une même structure de données (ici un tableau dynamique),
//comme stipulé dans l'énoncé du TP puisqu'ils ont alors un type en commun.
//Cette classe est donc non-instanciable.
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const  = 0 ;
    //Mode d'emploi : [renvoie sur le terminal un affichage des attributs du Trajet.]
    //méthode virtuelle pure obligeant à une redéfinition
    //dans les classes descendantes.
    //Contrat : aucun
    
    virtual const char* getVilleDepart() const = 0 ;
    //Mode d'emploi : [Renvoie un pointeur sur la valeur de la ville de départ
    //de l'instance du TrajetSimple. (qui est non modifiable).]
    //méthode virtuelle pure obligeant à une redéfinition
    //dans les classes descendantes.
    
    
    virtual const char* getVilleArrivee() const = 0 ;
    //Mode d'emploi : [Renvoie un pointeur sur la valeur de la ville d'arrivée
    //de l'instance du TrajetSimple. (qui est non modifiable).]
    //méthode virtuelle pure obligeant à une redéfinition
    //dans les classes descendantes.
    
    virtual char getType()  = 0 ;
    //Mode d'emploi : méthode virtuelle pure obligeant à une redéfinition,
    //renvoie C si Trajet Compose, S si Trajet Simple en char* tel que cette
    //méthod est redéfinie dans les classes filles.
    //
    
    virtual const char* getModeTransport() const  = 0 ;
    //Mode d'emploi :méthode virtuelle pure obligeant à une redéfinition
    //renvoie le mode de transport si le Trajet est simple,
    //sinon renvoie "compose" si le trajet est compose. (selon les redefinitions de
    //cette methode par les classes filles.
    
    virtual void outputFormate() const = 0 ; 
    //Mode d'emploi : 


//-------------------------------------------- Constructeurs - destructeur
    Trajet (char* vD, char* vA);
    // Mode d'emploi :
    // Ce constructeur est uniquement appelé par les classes filles pour construire
    //des trajets simples ou composés. Il effectue une copie en profondeur des valeurs des paramètres ville départ (vD) et ville arrivée (vA) dans les attributs de la classe villeDépart et villeArrivée pour des raisons des sécurité (évite les modifications de ces derniers en dehors de la classe Trajet. 
    // Contrat : Les villes ne peuvent contenir d'espace
    

    virtual ~Trajet ( );
    // Mode d'emploi :
    // destruction de villeDepart et villeArrivee, alloues dynamiquement. 
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char* villeDepart ;
    char* villeArrivee ;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

