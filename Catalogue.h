/**************************************************************************************
 Catalogue  -  Interface
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Edouard DE BRYE et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, edouard.de-brye@insa-lyon.fr
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
    //contrat : la ville de départ et la ville d'arrivée doivent faire
    // moins de 39 characteres sans espace.
    
    void rechercherUnTrajetAvance() const ;
    //Mode d'emploi: Demande via des entrées/sorties standards la ville de
    //départ et la ville d'arrivée, affiche tous les trajets possibles
    //en composant Trajets Simples et Trajets Composes.
    //contrat : la ville de départ et la ville d'arrivée doivent faire
    //moins de 39 characteres sans espace.

    void affichageOptionsMenu() const ;
    //Mode d'emploi: méthode de sorties standards permettant d'afficher les instructions
    //du menu. (sinon, surchage de la méthode Menu();
    //contrat: choix entre 0 et 2
    
    void recuperation(const char* nomfichier, char selection);
    //Mode d'emploi: prend en paramètre le nom du fichier et le type de sélection
    //à opérer. En fonction de ce dernier, les trajets compris dans le fichier de nom nomfichier
    //seront ajoutés ou non au catalogue.
    //Types de récupérations :
    //totale - tous les trajets sont ajoutés au catalogue
    //selon le type - tous les trajets du type selectionné sont ajoutés (le type est soit
    //trajet simple, soit trajet composé)
    //selon la ville de départ - tous les trajets ayant cette ville de départ sont ajoutés
    //selon la ville d'arrivée - tous les trajets ayant cette ville d'arrivée sont ajoutés
    //selon la ville de départ ET la ville d'arrivée - tous les trajets ayant cette ville de
    //départ ET cette ville d'arrivée sont ajoutés
    //selon un intervalle [a,b] - tous les trajets compris dans cette intervalle sont ajoutés.
    //si l'intervalle déborde, alors il est ramené aux limites du possible.
    
    //Contrat : le fichier correspondant au nomfichier, s'il existe, doit être aux normes stipulées
    //dans notre compte-rendu.
    
    void sauvegarde(const char* nomfichier,char selection);
    //Mode d'emploi:  prend en paramètre le nom du fichier et le type de sélection
    //à opérer. En fonction de ce dernier, les trajets compris dans le catalogue
    //seront ajoutés ou non au fichier dûment choisi.
    //Contrat : il ne faut pas rentrer un nom de fichier qui est dans un dossier non repertorié.
    // le nom du fichier lui même peut ne pas exister, il sera créé. MAIS PAS LE DOSSIER.

    bool conformiteNomFichier(const char* nomfichier) ;
    //Mode d'emploi: prend en paramètre un nom de fichier souhaité. Cette
    //méthode vérifie la conformité du nom de fichier pour la création:
    //ne peut contenir ':', et ne peut commencer par un '.'.
    //Contrat : aucun
    
    char* verificationInput(int size, bool typeChaine);
    //Mode d'emploi: méthode appelée à chaque entrée de type chaîne de caractère.
    //vérifie l'état du buffer et nettoie le buffer.
    //Contrat : 
    
    void addTrajetSimple(string line, Tableau *ensembleT) ;
    //Mode d'emploi : Ajoute un trajet simple dont les informations (aux normes
    //stipulées dans notre CR) sont comprise dans la chaîne prise en paramètre "line"
    //à un ensemble de type Tableau.
    //Contrat :
    
  
protected:
//----------------------------------------------------- Méthodes protégées

    
//----------------------------------------------------- Attributs protégés

};



#endif // Catalogue_H

