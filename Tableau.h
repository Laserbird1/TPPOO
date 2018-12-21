 /**************************************************************************************
 Tableau  -  Interface
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Interface de la classe <Tableau> (fichier Tableau.h) ----------------
#if ! defined ( Tableau_H )
#define Tableau_H

//--------------------------------------------------- Interfaces utilisées
class Trajet;

//------------------------------------------------------------- Constantes
const unsigned int TAILLE_MAX = 10 ;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Tableau>
//
//La classe Tableau est une collection de pointeurs de Trajet. Elle sert
//à deux classes : Catalogue, dont l'ensemble des Trajets est stocké dans un Tableau,
//et TrajetCompose, dont l'ensemble des étapes est stocké dans un Tableau.
//Pour ce dernier type, il est primordial que l'ordre d'entrée des étapes ne soit pas
//changé car cela nuirait à la cohérence du trajet. Nous avons donc décidé de ne pas
// trier le tableau. C'est elle qui maitrise l'ajout de pointeur de Trajet.
// De plus, elle se définit par sa tailleActuelle (nombre de Trajets actuellement stockés)
//et par sa tailleMax, qui est automatiquement agrandit lorsque tailleActuelle est
//égal à tailleMax.
//
//------------------------------------------------------------------------

class Tableau
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  
    void AjoutTrajet(Trajet* adresse) ;
    //Mode d'emploi : Ajout de l'adresse d'un Trajet au tableau dynamique
    //Contrat : toute contrainte liée à la création du Trajet et à sa capacité à
    //être introduit dans le tableau est vérifié avant.

    void Afficher() const ;
    //Mode d'emploi : Renvoie sur le terminal un affichage de chaque Trajet dont
    //le pointeur est stocké dans le tableau dynamique
    
    
    unsigned int getTailleActuelle() const ;
    //Mode d'emploi : Renvoie la taille actuelle du tableau
    
    Trajet* getElement(unsigned int i) const ;
    //Mode d'emploi : renvoie le ieme élément du tableau. Si i n'est pas dans le tableau,
    //alors renvoie un pointeur null. 

//-------------------------------------------- Constructeurs - destructeur
 
    Tableau(unsigned int tailleMax = TAILLE_MAX );
    // Mode d'emploi : construit un tableau dynamique vide de taille maximale par défaut 10
    //ssi tailleMax différente de 0.
    // Contrat : aucun
    

    virtual ~Tableau ( );
    // Mode d'emploi : détruit d'abord les éléments Trajets du tableau, puis le tableau
    //lui même car ces éléments sont sur le tas (allocation dynamique).
    // Contrat : aucun


//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    Trajet **tableau ; //Tableau de pointeurs de trajets
    unsigned int tailleActuelle ;
    unsigned int tailleMax ;
};

#endif // Tableau_H

