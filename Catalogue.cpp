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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char c ;
    affichageOptionsMenu(0) ;
    cin >> c ;
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
    
    }else if (c=='6')
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
	cout <<"------------------------AJOUT TRAJET SIMPLE----------------------" <<endl ;
	cout<<"Attention: ne pas inserer d'espaces" <<endl;
	cout<<"Ville de depart    : ";
    cin>>villeDep;
    cout<<endl;
    cout<<"Ville de d'arrivee : ";
    cin>>villeArr;
    cout<<endl;
	cout<<"Moyen de transport : ";
    cin>>modeT;
    cout<<endl;
    
	TrajetSimple *trajet = new TrajetSimple(villeDep, villeArr, modeT);
    bool exists = false ;
    for (unsigned int i=0 ; i<tailleActuelle ; i++)
    {
        if (strcmp(trajet->getType(),tableau[i]->getType())==0)
        {
            if (strcmp(trajet->getType(),"TS")==0)
            {
                if (strcmp(villeDep,tableau[i]->getVilleDepart())==0 && strcmp(villeArr, tableau[i]->getVilleArrivee())==0 && strcmp(modeT,tableau[i]->getModeTransport())==0)
                {
                        exists = true ;
                }
            }
        }
    }
    if (exists==false)
    {
        AjoutTrajet(trajet);
        cout<<"                          TRAJET AJOUTE                   "<<endl;
    }
    else
    {
        cout <<"! TRAJET NON AJOUTE : DEJA EXISTANT OU NON VALIDE ! " <<endl ; 
    }
    
	
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
   	cin>>vD;
    cout<<endl;
	cout<<"Ville d'arrivee    : ";
    cin>>vA;
    cout<<endl;
	
	/*while (strcmp(vD, vA) == 0)
	{
		cout << "IMPOSSIBLE : VILLE DE DEPART DOIT ETRE DIFFERENTE DE VILLE D'ARRIVEE " << endl;
		cout << "REESSAYER : " << endl;
		cout << "\n " << endl;
        cout << "RAPPEL : La ville de depart est  " << vD<<endl;
		cout << "Ville d'arrivee    : ";
		cin >> vA;
		cout << endl;
	}*/

	cout << "Moyen de transport : ";
	cin >> mT;
	cout << endl;
    strcpy(villeDepart,vD);
    strcpy(villeArrPrecedente,vA);
	i++;

	TrajetSimple *trajet= new TrajetSimple(vD, vA, mT);
	ensembleT->AjoutTrajet(trajet);
	ensembleT->Afficher();
    
	while(continuer=='1')
	{
		char* vDsuite=new char[40];
		char* vAsuite=new char[40];
		char* mTsuite=new char[40];
		cout<<i<<"e Etape : "<< endl;
		cout<<"Ville de depart    : ";
		cin>>vDsuite;
		cout<<endl;
      
        while (strcmp(vDsuite,villeArrPrecedente)!=0)
        {

            cout <<"INCOMPATIBLE AVEC ETAPE PRECEDENTE : " << villeArrPrecedente << endl;
            cout <<"REESSAYER : " ;
            cout << "\n " << endl;
            cout << "RAPPEL Ville d'arrivée précédente : " << vD<< endl;
            cout<<"Ville de depart    : " <<endl ;
            cin >> vDsuite ;
            cout << endl ;
        }

	
        cout<<"Ville d'arrivee    : ";
        cin>>vAsuite;
        /*while (strcmp(vDsuite, vAsuite) == 0)
        {
            cout << "VILLE DE DEPART DOIT ETRE DIFFERENTE DE VILLE D'ARRIVEE  "  << endl;
            cout << "REESSAYER : " << endl;
            cout << "\n " << endl;
            cout << "La ville de depart est" << vDsuite <<endl;
            cout << "Ville d'arrivee    : " ;
            cin >> vAsuite;
            cout << endl;
        }*/ 
        villeArrPrecedente =
        strcpy(villeArrPrecedente,vAsuite);

        cout << endl;
        cout << "Moyen de transport : ";
        cin >> mTsuite;
        cout << endl;
        cout<<"Continuer? [1: OUI/ 0:NON]";
        cin>>continuer;

        TrajetSimple *trajet2= new TrajetSimple(vDsuite,vAsuite, mTsuite);
        ensembleT->AjoutTrajet(trajet2);

        while(continuer!='1' && continuer!='0')
        {
            cout<<"Ressayer  :  ";
            cin>>continuer;
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

void Catalogue::affichageOptionsMenu() const {
    cout <<"--------------------------------MENU-----------------------------" <<endl ;
    cout <<"Bienvenue sur le catalogue des trajets !" << endl ;
    cout << "Taper [n] pour accéder au service voulu" << endl ;
    cout <<"1. Effectuer une recherche de trajet simple." <<endl ;
    cout <<"2. Effectuer une recherche de trajet complexe." <<endl ;
    cout <<"3. Ajouter un trajet simple. " << endl ;
    cout <<"4. Ajouter un trajet compose. " << endl ;
    cout <<"5. Afficher le catalogue. "<<endl;
    cout <<"6. Sortir de l'application."<< endl;
    cout <<"-----------------------------------------------------------------" << endl ;
    cout << "CHOIX : " ;
} //----- Fin de Méthode affichageOptionsMenu

void Catalogue::recuperationTotale()
{
  
};

void Catalogue::recuperationType()
{
  
}

void Catalogue::recuperationSelectionVille()
{
  
}

void Catalogue::recuperationIntervalle()
{
  
}

void Catalogue::sauvegardeTotale(const char*nomfichier, char selection)
//saveType :
//1 sauvegarde tout
//2 sauvegarde les TC ou TS
//3 sauvegarde selon la ville de depart/arrivee
//4 selon une selection de trajet
{
	bool selectTC = true;
	bool selectTS = true;
	char* selectvilleA = new char[40];
	char* selectvilleD = new char[40];
	unsigned int borne1 = 0;
	unsigned int borne2 = tailleActuelle;
	char c;

	switch (selection)
	{
	case '1':
		break;
	case '2':
		cout << "Choisissez le type de trajet à restituer : " << endl;
		cout << " 1. Trajets Simples" << endl;
		cout << " 2. Trajets Composes" << endl;
		cout << "choix : ";
		cin >> c;
		while (c != '1' && c != '2')
		{
			//on nettoie le istream au cas ou l'utilisateur a entre plusieurs caracteres
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "erreur, reessayez : ";
			cin >> c;

		}
		cin.ignore();
		if (c == '1')
		{
			selectTC = false;
		}
		else
		{
			selectTS = false;
		}
		break;
	case '3':
		cout << "Quelle(s) ville(s) souhaitez-vous spécifier? " << endl;
		cout << "1. Ville de départ " << endl;
		cout << "2. Ville d'arrivée " << endl;
		cout << "3. Ville de départ et d'arrivée " << endl;
		cout << "choix : ";
		cin >> c;
		while (c != '1' && c != '2' && c != '3')
		{
			//on nettoie le istream au cas ou l'utilisateur a entre plusieurs caracteres
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "erreur,reesayez : ";
			cin >> c;
		}
		if (c == '1' || c=='3')
		{
			cout << "Rentrz la ville de départ :" << endl;
			cin.getline(selectvilleD, 40);
			cout << endl;
		}
		if (c == '2' || c=='3')
		{
			cout << "Rentrz la ville d'arrivée :" << endl;
			cin.getline(selectvilleA, 40);
			cout << endl;
		}
		break;//du 3
	case '4':
		cout << "Combien voulez de trajets ?" << endl;
		cin >> borne2;
		cout << "A partir d'où voulez vous partir ?" << endl;
		cin >> borne1;

		--borne1;
		--borne2;//mise en repère tableau (rentrer 1 donnera le premier élément situé en [0])

		borne1 = borne1 < 0 ? 0 : borne1;
		borne2 = borne2 < 0 ? 0 : borne2;//ici a valeur de cb de trajet a prendre !

		borne1 = borne1 < tailleActuelle ? borne1 : tailleActuelle;
		borne2=borne1+borne2 < tailleActuelle ? borne1+borne2 : tailleActuelle;
		break;
	}


	std::fstream fichier;

	fichier.open(nomfichier, ios_base::in);
	//
	int nbTC = 0;
	int nbTS = 0;

	if (fichier)
	{
		cout << "Le fichier existe déjà, voulez-vous l'écraser ?(e) ou écrire à la suite ?(s)" << endl;
		int fait = 0;
		cin >> c;
		while (!fait)
		{
			fait = 1;
			if (c == 'e')
			{
				//réouverture du fichier en supprimant le contenu
				fichier.close();
				fichier.open(nomfichier, ios_base::trunc);
			}
			else if (c == 's')
			{
				//recuperation n° au début 
				fichier >> nbTS;
				fichier >> nbTC;
				fichier.close();
				Erase_First_Line(nomfichier);//effacement de la ligne contenant les numéros au début en réécrivant le reste 
				fichier.open(nomfichier, ios_base::ate);//puis réécriture à la fin

			}
			else
			{
				cout << "Attention ! Nous ne vous avons pas compris, veuillez \n saisir e ou s... " << endl;
				fait = 0;
			}
		}
	}
	else//le fichier n'existe pas
	{
		fichier.close();
		fichier.open(nomfichier, ios_base::out);
	}

	if (fichier)//si ouverture (a priori le fichier existe maintenant)
	{
		streambuf*oldStreamBuffer = cout.rdbuf(fichier.rdbuf());


	for (unsigned int i = borne1; i < borne2; i++)
	{
		const char *type = tableau[i]->getType();
		bool ajout = true;

		if (selection == '3' && (c == '1'|| c=='3') && strcmp(tableau[i]->getVilleDepart(),selectvilleD)!=0)
		{
			ajout = false;
		}
		if (selection == '3' && (c == '2' || c == '3') && strcmp(tableau[i]->getVilleArrivee(), selectvilleA) != 0)
		{
			ajout = false;
		}
		if (!(selectTS && strcmp(type, "S")))
		{
			ajout = false;
		}
		if (!(selectTC && strcmp(type, "C")))
		{
			ajout = false;
		}

		if (ajout)
		{
			cout << '#' << type << ',';
			//incrémentation du nombre de trajet par type
			if (strcmp(type, "S") == 0) nbTS++;
			else nbTC++;
			tableau[i]->outputFormate();
		}
	}

	//on met à jour le fichier avec les nombre de trajet au debut
	if (nbTC != 0 && nbTS != 0)
	{
		fichier.seekp(0);
		cout << nbTS << " " << nbTC << endl;
	}
	cout.rdbuf(oldStreamBuffer);
	fichier.close();
	}
	else
		cerr << "Ouverture du fichier impossible impossible" << endl;
}
void Catalogue::sauvegardeType()
{
  
}

void Catalogue::sauvegardeSelectionVille()
{
  
}

void Catalogue::sauvegardeIntervalle()
{
  
}

//----------------------------------------------------- Méthodes protégées
void Catalogue::Erase_First_Line(const char* File)
{
	string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier
	ifstream ReadFile(File);
	if (ReadFile) //Si le fichier est trouvé
	{
		string line=new char[200];
		int Line = 0;
		while (getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
		{
			Line++;
			if (Line != 0) //Si la ligne atteinte est différente de la ligne à supprimer...
				Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
		}
	}
	ReadFile.close(); //On ferme le fichier en lecture

	ofstream WriteFile(File); //On ouvre ce même fichier en écriture
	WriteFile << Buffer.c_str(); //On écris le texte dedans
	WriteFile.close(); //et on ferme le fichier
}

