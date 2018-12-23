/**************************************************************************************
 Catalogue  -  Interface
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "Tableau.h"

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// La classe Catalogue permet à l'utilisateur d'ajouter des trajets (simples
// ou composés) au catalogue, mais aussi d'afficher l'ensemble des trajets disponibles,
// et de faire des recherches de trajet en fonction de la ville de départ et
// de la ville d'arrivée.
// La classe Catalogue est une classe Fille de Tableau (héritage public) afin qu'elle
//accède plus facilement au tableau dynamique stockant les trajets ainsi qu'a la
//taille actuelle du tableau.
//------------------------------------------------------------------------

class Catalogue: public Tableau
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Menu ();
    // Mode d'emploi : Méthode simulant une "interface utilisateur", elle propose 6
    //options à l'Utilisateur qui sélectionne le service voulu grâce à une entrée
    //standard au clavier. Cette dernière renvoit vrai si et seulement si le service
    //voulut est une extension de la "connection" : Alors, dans la réalisation de Utilisation,
    //nous ne rentrons plus dans la boucle et nous sortons de l'application.
    // Contrat : aucun

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );
    // Mode d'emploi : 
    // La construction d'un Catalogue s'appuie sur la construction d'un Tableau de tailleMax initiale 0. 
    // Contrat : aucun
    

    virtual ~Catalogue ( );
    // Mode d'emploi :
    // aucun ; c'est le destructeur de Tableau qui s'en occupe et qui fait appel aux destructeurs de
    //TrajetSimple/TrajetCompose.
    // Contrat : aucun
    

    
    
    

//------------------------------------------------------------------ PRIVE
private : 
    void ajouterUnTrajetSimple();
    //Mode d'emploi: demande avec des entrées (Clavier) /sorties standard
    //les elements necessaires pour construire un trajet simple,
    //le construit et l'ajoute au tableau via un pointeur.
    
    void ajouterUnTrajetCompose();
    //Mode d'emploi: demande avec des entrées (Clavier) /sorties standard
    //les elements necessaires pour construire un trajet compose,
    //le construit et l'ajoute au tableau via un pointeur.
    
    void rechercherUnTrajet() const  ;
    //Mode d'emploi: Demande via des entrées/sorties standards la ville
    //de départ et la ville d'arrivée concernées, et affiche tous les trajets
    //simple et/ou compose ayant ces attributs exactement. Il ne compose pas de trajet
    //simples et/ou composes.
    //contrat : la ville de départ et la ville d'arrivée doivent faire moins de 39 characteres sans espace.
    
    void rechercherUnTrajetAvance() const ;
    //Mode d'emploi: Demande via des entrées/sorties standards la ville de
    //départ et la ville d'arrivée, affiche tous les trajets possibles
    //en composant Trajets Simples et Trajets Composes.
    //contrat : la ville de départ et la ville d'arrivée doivent faire moins de 39 characteres sans espace.

    
    void affichageOptionsMenu() const ;
    //Mode d'emploi: méthode de sorties standards permettant d'afficher les instructions
    //du menu. (sinon, surchage de la méthode Menu();
    //contrat: choix entre 0 et 2
    
    bool isIn(Trajet* test);
    //Mode d'emploi: pour sauvegarde, eviter les doublons
    //Contrat :
    
    void recuperation(const char* nomfichier, char selection);
    //Mode d'emploi: 
    //Contrat :
    
    void recuperationSelectionVille(const char* nomfichier);
    //Mode d'emploi: 
    //Contrat :
    
    void recuperationIntervalle(const char* nomfichier);
    //Mode d'emploi: 
    //Contrat :
    
    void sauvegardeTotale(const char* nomfichier);
    //Mode d'emploi:
    //Contrat :
    
    void sauvegardeType(const char* nomfichier);
    //Mode d'emploi:
    //Contrat :
    
    void sauvegardeSelectionVille(const char* nomfichier);
    //Mode d'emploi:
    //Contrat :
    
    void sauvegardeIntervalle(const char* nomfichier);
    //Mode d'emploi:
    //Contrat :
    
    bool conformiteNomFichier(const char* nomfichier) ;
    //Mode d'emploi: prend en paramètre un nom de fichier souhaité. Cette
    //méthode vérifie la conformité du nom de fichier pour la création:
    //le nom doit se terminer par .txt, ne peut contenir ':', et ne peut commencer
    //par un '.'.
    //Contrat : aucun 
    
    void lectureTS(string line) ;
    //Mode d'emploi:
    //contrat :
  
protected:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés

};



#endif // Catalogue_H

