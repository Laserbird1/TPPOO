/**************************************************************************************
 Catalogue  -  Réalisation
 -------------------
 début                : 20/11/2018
 copyright            : (C)2018 par Grazia Giulia RIBBENI et Julie DELPUECH
 e-mail               : julie.delpuech@insa-lyon.fr, grazia-giulia.ribbeni@insa-lyon.fr
 ***************************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Catalogue::Menu ()
{
    cin.clear();
    char c ;
    affichageOptionsMenu() ;
    cin.get(c);
    cin.ignore();
    if (c=='1')
    {
        rechercherUnTrajet() ;
        return false;

    } else if (c=='2')
    {
        rechercherUnTrajetAvance() ;
        return false ;
    }else if (c=='3')
    {
        ajouterUnTrajetSimple();
        return false;
    
    }else if (c=='4')
    {
        ajouterUnTrajetCompose();
        return false;
    
    }else if (c=='5')
    {
        Afficher();
        return false;
    } else if (c=='6')
    {
        char nomfichier[100] ;
        cout <<"------------------------RESTITUTION-------------------------------" <<endl ;
        cout <<"Attention, n'oubliez pas le .txt! Longueur max. 100 char" << endl ;
        cout <<"nom du fichier source : ";
    
        cin.getline(nomfichier,100);
        bool norme = conformiteNomFichier(nomfichier);
        while(!norme)
        {
            cout <<"nom de fichier non conforme... Reessayez :" ;
            cin.getline(nomfichier,100);
            norme = conformiteNomFichier(nomfichier);
        }
            
        cout << nomfichier << endl ;
        cout <<"Quel type de restitution souhaitez-vous effectuer?"<< endl ;
        cout <<"Taper [n] pour accéder au service voulu" << endl ;
        cout <<"1. Restitution totale. " << endl ;
        cout <<"2. Restitution selon le type de trajet. "<< endl ;
        cout <<"3. Restitution selon la ville de départ et/ou ville d'arrivée. " << endl ;
        cout <<"4. Restitution selon une sélection de trajets. "<< endl ;
        cout <<"------------------------------------------------------------------"<< endl ;
        char d ;
        cin >> d ;
        recuperation(nomfichier,d) ;
        return false ;
        
    } else if (c=='7')
    {
        char nomfichier[100] ;
        cout <<"------------------------SAUVEGARDE-------------------------------" <<endl ;
        cout <<"Attention, n'oubliez pas le .txt! Longueur max. 100 char" << endl ;
        cout <<"nom du fichier cible : " ;
        bool norme = false ;
        while (!norme)
        {
            cin.ignore() ;
            cin.getline(nomfichier,100);
            norme = conformiteNomFichier(nomfichier);
        }
        cout << nomfichier ;
        cout <<"Quel type de sauvegarde souhaitez-vous effectuer?"<< endl ;
        cout <<"Taper [n] pour accéder au service voulu" << endl ;
        cout <<"1. Sauvegarde totale. " << endl ;
        cout <<"2. Sauvegarde selon le type de trajet. "<< endl ;
        cout <<"3. Sauvegarde selon la ville de départ et/ou ville d'arrivée. " << endl ;
        cout <<"4. Sauvegarde selon une sélection de trajets. "<< endl ;
        cout <<"------------------------------------------------------------------"<< endl ;
        char d  = '\0' ;
        switch (d)
        {
            case '1' :
                sauvegardeTotale(nomfichier);
                break ;
            case '2' :
                sauvegardeType(nomfichier) ;
                break ;
            case '3' :
                sauvegardeSelectionVille(nomfichier) ;
                break ;
            case '4' :
                sauvegardeIntervalle(nomfichier);
                break ;

        }
        
        return false ;
        
    }else if (c=='8')
    {
        return true;
    
    }else
    {
        cout << "Attention ! Nous ne vous avons pas compris, veuillez \n saisir un numéro entre 1 et 6... " << endl ;
        return false ;
    }
    
    return true;
} //----- Fin de Méthode Menu




//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( ): Tableau(0)
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
    
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE
void Catalogue::rechercherUnTrajet() const {
    char* depart = new char[40];
    char* arrivee = new char[40];
    cout <<"----------------------------RECHERCHE-----------------------------" << endl ;
    cout <<"DEPART SOUHAITE: " ;
    cin >> depart;
    cout << endl ;
    cout << "ARRIVEE SOUHAITE : " ;
    cin >> arrivee ;
    cout << endl ;
    int findings = 0 ;
    
    for (unsigned int i=0 ; i<tailleActuelle ; i++)
    {
         if (strcmp(tableau[i]->getVilleDepart(),depart)==0 && strcmp(tableau[i]->getVilleArrivee(),arrivee)==0)
         {
             tableau[i]->Afficher() ;
             findings ++ ;
         }
    }
    if (findings==0)
    {
        cout << "aucun trajet correspondant à vos critères n'est disponible..." << endl ;
    }
    
    cout <<"-----------------------------------------------------------------"<< endl ;
    delete [] depart ;
    delete [] arrivee ; 
}//----- Fin de Méthode RechercherUnTrajet

void Catalogue::ajouterUnTrajetSimple()
{
	char* villeDep=new char[40];
	char* villeArr=new char[40];
	char* modeT=new char[40];
	cout<<"------------------------AJOUT TRAJET SIMPLE----------------------" <<endl ;
	cout<<"Attention: ne pas inserer d'espaces" <<endl;
	cout<<"Ville de depart    : ";
    cin.ignore(); //ignore le dernier char dans le buffer (car utilisation cin dans le menu)
    cin.getline(villeDep,40);
    cout<<endl;
    cout<<"Ville de d'arrivee : ";
    cin.clear() ;
    cin.getline(villeArr,40);
    cout<<endl;
	cout<<"Moyen de transport : ";
    cin.getline(modeT,40);
    cout<<endl;
    cout <<villeDep <<", "<<villeArr<<", "<<modeT<<endl ;
	TrajetSimple *trajet = new TrajetSimple(villeDep, villeArr, modeT);
    AjoutTrajet(trajet);
    cout <<"                           TRAJET AJOUTE                         "<<endl;
	cout <<"-----------------------------------------------------------------" <<endl ;
	delete [] villeDep;
	delete [] villeArr;
	delete [] modeT;

} //----- Fin de Méthode AjouterUnTrajetSimple

void Catalogue::ajouterUnTrajetCompose()
{
	char* vD=new char[40];
	char* vA=new char[40];
	char* mT=new char[40];
	char* villeDepart = new char[40] ;
    char* villeArrPrecedente = new char[40];
	int i=1;
	Tableau *ensembleT=new Tableau(2);
	char continuer='1';
	cout <<"------------------------AJOUT TRAJET COMPOSE---------------------" <<endl ;
    cout<<"Attention: ne pas insérer d'espaces"<<endl;
	cout<<i<<"e Etape : "<< endl;
	cout<<"Ville de depart    : ";
    cin.ignore(); //ignore le dernier char dans le buffer (car utilisation cin dans le menu)
    cin.getline(vD,40);
    cout<<endl;
	cout<<"Ville d'arrivee    : ";
    cin.getline(vA,40);
    cout<<endl;
	cout << "Moyen de transport : ";
    cin.getline(mT,40);
	cout << endl;
    strcpy(villeDepart,vD);
    strcpy(villeArrPrecedente,vA);
	i++;
	TrajetSimple *trajet= new TrajetSimple(vD, vA, mT);
	ensembleT->AjoutTrajet(trajet);
    
	while(continuer=='1')
	{
		char* vDsuite=new char[40];
		char* vAsuite=new char[40];
		char* mTsuite=new char[40];
		cout<<i<<"e Etape : "<< endl;
        strcpy(vDsuite,villeArrPrecedente);
        cout<<"Ville de passage   : ";
        cin.getline(vAsuite,40);
        villeArrPrecedente = strcpy(villeArrPrecedente,vAsuite);

        cout << endl;
        cout << "Moyen de transport : ";
        cin.getline(mTsuite,40);
        cout << endl;
        cout<<"Continuer? [1: OUI/ 0:NON]";
        cin.get(continuer);
        cin.ignore() ;

        TrajetSimple *trajet2= new TrajetSimple(vDsuite,vAsuite, mTsuite);
        ensembleT->AjoutTrajet(trajet2);

        while(continuer!='1' && continuer!='0')
        {
            cout<<"Ressayer  :  ";
            cin.get(continuer);
            cin.ignore();
        }
        cout<<endl ;
        i++;
        delete [] vDsuite;
        delete [] vAsuite;
        delete [] mTsuite; 
	}
    
    ensembleT->Afficher() ;
	TrajetCompose *tc=new TrajetCompose(villeDepart,villeArrPrecedente,ensembleT);
    tc->Afficher() ;
   	AjoutTrajet(tc);
    
	cout<<"                          TRAJET AJOUTE                           "<<endl;	
	cout <<"----------------------------------------------------------------" <<endl ;
    delete [] vD ;
    delete [] vA ;
    delete [] mT ;
    delete [] villeDepart ;
    delete [] villeArrPrecedente ;
	 
} //----- Fin de Méthode AjouterUnTrajetCompose

void Catalogue::affichageOptionsMenu() const {
    cout <<"--------------------------------MENU-----------------------------" <<endl ;
    cout <<"Bienvenue sur le catalogue des trajets !" << endl ;
    cout << "Taper [n] pour accéder au service voulu" << endl ;
    cout <<"1. Effectuer une recherche de trajet simple." <<endl ;
    cout <<"2. Effectuer une recherche de trajet complexe." <<endl ;
    cout <<"3. Ajouter un trajet simple. " << endl ;
    cout <<"4. Ajouter un trajet compose. " << endl ;
    cout <<"5. Afficher le catalogue. "<<endl;
    cout <<"6. Restituer un ancien catalogue. " << endl ;
    cout <<"7. Sauvegarder le catalogue courant. " << endl ;
    cout <<"8. Sortir de l'application sans sauvegarde."<< endl;
    cout <<"-----------------------------------------------------------------" << endl ;
    cout << "CHOIX : " ;
} //----- Fin de Méthode affichageOptionsMenu



void Catalogue::recuperation(const char* nomfichier, char selection)
{
    fstream fichier(nomfichier);
    bool selectTS = true ;
    bool selectTC = true ;
    string villeDepart ;
    string villeArrivee ;
    
    if (!fichier.is_open())
    {
        cout <<"Recuperation impossible : fichier non existant " <<endl;
    }
    else
    {
        char c ;
        switch (selection)
        {
            case '1' :
                break ;
            case '2' :
                cout <<"Choississez le type de trajet à restituer : " << endl ;
                cout <<" 1. Trajets Simples" << endl ;
                cout <<" 2. Trajets Composes" << endl ;
                cout <<"choix : " ;
                cin.ignore();
                cin.get(c);
                while (c!='1' && c!='2')
                {
                    //on nettoie le istream au cas ou l'utilisateur a entrer plusieurs caracteres
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout <<"erreur, reessayez : " ;
                    cin.get(c);
                
                }
                cin.ignore() ;
                if (c=='1')
                {
                    selectTC = false ;
                }
                else
                {
                    selectTS = false ;
                }
                break ;
            case '3' :
                cout <<"Quelle(s) ville(s) souhaitez-vous spécifier? " <<endl ;
                cout <<"1. Ville de départ " << endl ;
                cout <<"2. Ville d'arrivée " << endl ;
                cout <<"3. Ville de départ et d'arrivée " << endl ;
                cout <<"choix : " ;
                cin.ignore();
                cin.get(c);
                while(c!='1' && c!='2' && c!='3')
                {
                    //on nettoie le istream au cas ou l'utilisateur a entrer plusieurs caracteres
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "erreur,reesayez : " ;
                    cin.get(c);
                }
                break ;
            case '4' :
                break ;
                
        }
        
        string line ;
        while (!fichier.eof())
        {
            getline(fichier,line);
            cout << line << endl ;
            
            if (line[0]=='#')
            {
                if(line[1]=='S' && selectTS)
                {
                    lectureTS(line);
                    
                } else if (line[1]=='C' && selectTC)
                {
                    Tableau *ensembleT = new Tableau(2);
                    char villeD[40]={} ;
                    int i= 3;
                    int j = 0 ;
                    while(line[i]!=',')
                    {
                        villeD[j]=line[i];
                        i++ ;
                        j++ ;
                    }
                    
                    i++ ;
                    char villeA[40]={} ;
                    j= 0 ;
                    while(line[i]!=',')
                    {
                        villeA[j]=line[i];
                        i++ ;
                        j++ ;
                    }
                    
                    int nbrEtapes = line[i+1] - '0';
                    cout <<"char " << line[i+1] << endl ;
                    cout <<"nombre etapes : "<< nbrEtapes << endl ;
                   
                    
                    for (int e=0 ; e<nbrEtapes ; e++) //AJOUT D'UNE VARIABLE NBR ETAPES
                    {
                        getline(fichier,line);
                        int i= 0;
                        int j = 0 ;
                        char etapeD[40] = {};
                        while(line[i]!=',') //on commence au premier caractere appartenant a villeD
                        {
                            etapeD[j]=line[i];
                            i++ ;
                            j++ ;
                        }
                        i++ ;
                        char etapeA[40] = {} ;
                        j= 0 ;
                        
                        while(line[i]!=',')
                        {
                            etapeA[j]=line[i];
                            i++ ;
                            j++ ;
                        }
                        char mT[40] = {} ;
                        j =0 ;
                        for (unsigned long k=i+1 ; k<line.length(); k++)
                        {
                            mT[j]=line[k];
                            j++ ;
                        }
                        TrajetSimple *t = new TrajetSimple(etapeD,etapeA,mT);
                        ensembleT->AjoutTrajet(t);
                    }
                    TrajetCompose *tc = new TrajetCompose(villeD,villeA,ensembleT);
                    AjoutTrajet(tc);
                
                }
            }
        }
    }
}

void Catalogue::lectureTS(string line)
{
    int i= 3;
    int j = 0 ;
    char villeD[40] = {};
    while(line[i]!=',') //on commence au premier caractere appartenant a villeD
    {
        villeD[j]=line[i];
        i++ ;
        j++ ;
    }
    i++ ;
    char villeA[40] = {} ;
    j= 0 ;
    
    while(line[i]!=',')
    {
        villeA[j]=line[i];
        i++ ;
        j++ ;
    }
    char modeT[40] = {} ;
    j =0 ;
    for (unsigned long k=i+1 ; k<line.length(); k++)
    {
        modeT[j]=line[k];
        j++ ;
    }
    TrajetSimple *t = new TrajetSimple(villeD,villeA,modeT);
    AjoutTrajet(t);
}

void Catalogue::recuperationSelectionVille(const char* nomfichier)
{
  
}

void Catalogue::recuperationIntervalle(const char* nomfichier)
{
  
}

void Catalogue::sauvegardeTotale(const char* nomfichier)
{
  /*fstream fichier ;
  fichier.open(nomfichier,ofstream::app);
  
  long pos =fichier.tellp();
  int nbTC;
  int nbTS;
  if(pos>0)
  {
    fichier.seekp(ios_base::beg);
    //recuperation n° au début 
    char s[8];
    fichier.getline(fichier,s,',');
    int TS=stoi(s) ;
    
    fichier.seekp(pos);
  }
  else
  {
    nbTC=0;
    nbTS=0;
  }
  
  streambuf*oldStreamBuffer=cout.rdbuf(fichier.rdbuf());
  for(unsigned int i=0 ; i<tailleActuelle ; i++)
  {
    cout<<"#"<<tableau[i]->getType()<<" ";
    //placement numero de trajet
    tableau[i]->outputFormate();
  }
  
  cout.rdbuf(oldStreamBuffer); */
}

void Catalogue::sauvegardeType(const char* nomfichier)
{
  
}

void Catalogue::sauvegardeSelectionVille(const char* nomfichier)
{
  
}

void Catalogue::sauvegardeIntervalle(const char* nomfichier)
{
  
}

bool Catalogue::conformiteNomFichier(const char* nomfichier)
{
    int length = strlen(nomfichier);
    if (nomfichier[0]=='.') //le nom ne peut pas commencer par un point
    {
        return false ;
    }
    for (int i=0 ; i<length-4 ; i++)
    {
        if (nomfichier[i]==':'){ //le double point n'est jamais accepté sous Linux/Mac
            return false ;
        }
        
    }
    
    //l'extension doit etre la bonne
    if (nomfichier[length-1]=='t' && nomfichier[length-2]=='x' && nomfichier[length-3]=='t'
        && nomfichier[length-4]=='.')
    {
        return true ;
    }
    else
    {
        return false ;
    }
}


void Catalogue::rechercherUnTrajetAvance() const {
    char* depart = new char[40];
    char* arrivee = new char[40];
    cout << "----------------------------RECHERCHE-----------------------------" << endl;
    cout << "DEPART : ";
    cin >> depart;
    cout << endl;
    cout << "ARRIVEE : ";
    cin >> arrivee;
    cout << endl;
    
    int trouve = 0;
    const char* dpt = depart;
    const char* arv = arrivee;
    Tableau *resInterm = new Tableau(1);
    
    unsigned int indiceASauter= 2000;
    unsigned int indiceASauter2 = 2000;
    unsigned int indiceASauter3 = 2000;
    int k = resInterm->getTailleActuelle();
    
    // bool stop2 = false;
    for (unsigned int i = 0; i < tailleActuelle; i++)
    {
        if (strcmp(dpt, tableau[i]->getVilleDepart()) == 0 && (strcmp(arv, tableau[i]->getVilleArrivee()) == 0))
        {
            tableau[i]->Afficher();
            i++;
            trouve++;
        }
        
        if (strcmp(dpt, tableau[i]->getVilleDepart()) == 0 && i < tailleActuelle)
        {
            //delete resInterm ; //reinitialisation du tableau stockant toutes les
            //etapes aboutissant a la ville d'Arrivee
            resInterm = new Tableau(5);
            resInterm->AjoutTrajet(tableau[i]);
            //trouve++;
            k = resInterm->getTailleActuelle();
            
            if (strcmp(arv, tableau[i]->getVilleArrivee()) != 0 /*&& stop2==false */&& indiceASauter != i)
            {
                for (unsigned int j = 0; j < tailleActuelle; j++)
                {
                    
                    if (strcmp(tableau[i]->getVilleArrivee(), tableau[j]->getVilleDepart()) == 0 && indiceASauter2 != j)
                    {
                        Tableau *res2 = resInterm;
                        //Tableau *res2 = new Tableau(5);
                        resInterm->AjoutTrajet(tableau[j]);
                        trouve++;
                        k = resInterm->getTailleActuelle();
                        
                        if (strcmp(arv, resInterm->getElement(k - 1)->getVilleArrivee()) == 0)
                        {
                            resInterm->Afficher();
                        }
                        //delete resInterm ;
                        resInterm = new Tableau(5);
                        resInterm->AjoutTrajet(tableau[i]);
                        trouve++;
                        k = resInterm->getTailleActuelle();
                        
                        if (strcmp(arv, tableau[j]->getVilleArrivee()) != 0)
                        {
                            for (unsigned int u = 0; u < tailleActuelle; u++)
                            {
                                if (strcmp(tableau[j]->getVilleArrivee(), tableau[u]->getVilleDepart()) == 0 && indiceASauter3 != u)
                                {
                                    res2->AjoutTrajet(tableau[u]);
                                    trouve++;
                                    k = res2->getTailleActuelle();
                                    if (strcmp(arv, res2->getElement(k - 1)->getVilleArrivee()) == 0)
                                    {
                                        res2->Afficher();
                                        //delete res2;
                                        res2 = new Tableau(5);
                                        res2->AjoutTrajet(tableau[i]);
                                        trouve++;
                                        //res2->AjoutTrajet(tableau[j]);////
                                        k = res2->getTailleActuelle();
                                        //delete res2 ;
                                    }
                                }
                                else {
                                    indiceASauter3 = u;
                                }
                            }
                            
                        }
                        //delete [] res2 ;
                        //delete resInterm ;
                    }
                    else {
                        indiceASauter2 = j;
                    }
                }
                
            }
            else {
                indiceASauter = i;
                
            }
            //delete resInterm ;
        }
        
    }
    
    if (trouve == 0)
    {
        cout << "aucun trajet correspondant à vos critères n'est disponible..." << endl;
    }
    
    cout << "-----------------------------------------------------------------" << endl;
    //delete resInterm ;
    delete [] depart ;
    delete [] arrivee ;
    
    
} //----- Fin de Méthode RechercherUnTrajetAvance

//----------------------------------------------------- Méthodes protégées

