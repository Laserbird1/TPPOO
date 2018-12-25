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
#include <limits>  //utiliser pour "nettoyer" les buffers
                //on utilise la taille maximum en caractères d'un stream
                //pour, après chaque entrée, être certain qu'aucun "résidu"
                //ne se trouve encore dans le buffer, car cela pourrait
                //pertuber la suite du programme.



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
    affichageOptionsMenu() ;
    cin.get(c); //laisse un \n dans le buffer
    cin.clear(); //nettoyage du stream/buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cout <<"nom de fichier non conforme... Reessayez : " ;
            cin.getline(nomfichier,100);
            norme = conformiteNomFichier(nomfichier);
        }
        cout <<"Quel type de restitution souhaitez-vous effectuer?"<< endl ;
        cout <<"Taper [n] pour accéder au service voulu" << endl ;
        cout <<"1. Restitution totale. " << endl ;
        cout <<"2. Restitution selon le type de trajet. "<< endl ;
        cout <<"3. Restitution selon la ville de départ et/ou ville d'arrivée. " << endl ;
        cout <<"4. Restitution selon une sélection de trajets. "<< endl ;
        cout <<"------------------------------------------------------------------"<< endl ;
        char d ;
        cin.get(d) ;
        cin.clear(); //nettoyage du stream/buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        recuperation(nomfichier,d) ;
        return false ;
        
    } else if (c=='7')
    {
        char nomfichier[100] ;
        cout <<"------------------------SAUVEGARDE-------------------------------" <<endl ;
        cout <<"Attention, n'oubliez pas le .txt! Longueur max. 100 char" << endl ;
        cout <<"nom du fichier cible : " ;
        cin.getline(nomfichier,100);
        bool norme = conformiteNomFichier(nomfichier);
        while (!norme)
        {
            cout <<" nom de fichier non conforme... Reessayez : " ; 
            cin.getline(nomfichier,100);
            norme = conformiteNomFichier(nomfichier);
        }
        cout <<"Quel type de sauvegarde souhaitez-vous effectuer?"<< endl ;
        cout <<"Taper [n] pour accéder au service voulu" << endl ;
        cout <<"1. Sauvegarde totale. " << endl ;
        cout <<"2. Sauvegarde selon le type de trajet. "<< endl ;
        cout <<"3. Sauvegarde selon la ville de départ et/ou ville d'arrivée. " << endl ;
        cout <<"4. Sauvegarde selon une sélection de trajets. "<< endl ;
        cout <<"------------------------------------------------------------------"<< endl ;
        char d ;
        cin.get(d);
        cin.clear(); //nettoyage du stream/buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        sauvegarde(nomfichier,d) ;
        return false ;
        
    }else if (c=='8')
    {
        return true;
    
    }else
    {
        cout << "Attention ! Nous ne vous avons pas compris, veuillez \n saisir un numéro entre 1 et 8... " << endl ;
        return false ;
    }
    
    return true;
} //----- Fin de Méthode Menu


//---------------------------------------------------------------- Constructeurs - destructeur

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
    //cin.ignore();
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
        cout<<"Continuer? [1: OUI/ 0:NON] ";
        cin.get(continuer);
        cin.ignore() ;

        TrajetSimple *trajet2= new TrajetSimple(vDsuite,vAsuite, mTsuite);
        ensembleT->AjoutTrajet(trajet2);

        while(continuer!='1' && continuer!='0')
        {
            cout<<"Ressayer  :  ";
            cin.get(continuer);
            cin.clear(); //nettoyage du stream/buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	cout <<"-----------------------------------------------------------------" <<endl ;
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
    //stream vers le fichier de sauvegarde
    fstream fichier(nomfichier);
    
    //booléens témoignant de l'état des sélections à faire
    bool selectTS = true ;
    bool selectTC = true ;
    bool selectvD = false ;
    bool selectvA = false ;
    bool selectIntervalle = false ;
    
    int borneinf = 0 ;
    int bornesup = 0 ;
    char villeDepart[40]={} ;
    char villeArrivee[40]={} ;
    
    //vérification de l'existence du fichier
    if (!fichier.is_open())
    {
        cout <<"Recuperation impossible : fichier non existant " <<endl;
    }
    else
    {
        //choix du type de restitution
        char c ;
        
        string nbTS, nbTC ;
        getline(fichier,nbTS,'-');
        getline(fichier,nbTC);
        int nbrTS = stoi(nbTS);
        int nbrTC = stoi(nbTC);
        
        switch (selection)
        {
            case '1' :
                if (nbrTS==0 && nbrTC==0)
                {
                    cout <<"Fichier ne contenant aucun trajet... " << endl ;
                }
                break ;
            case '2' : //SELON LE TYPE
                cout <<"Choississez le type de trajet à restituer : " << endl ;
                cout <<" 1. Trajets Simples" << endl ;
                cout <<" 2. Trajets Composes" << endl ;
                cout <<"choix : " ;
                cin.get(c);
                cin.clear(); //nettoyage du stream/buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                while (c!='1' && c!='2')
                {
                    cout <<"erreur, reessayez : " ;
                    cin.get(c);
                    cin.clear(); //nettoyage du stream/buffer
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                }
                
                if (c=='1')
                {
                    selectTC = false ;
                }
                else
                {
                    selectTS = false ;
                }
                
                if (nbrTS==0 && nbrTC==0)
                {
                    cout <<"Fichier ne contenant aucun trajet... " << endl ;
                    return ;
                }
                else if (selectTC && nbrTC==0 && (!selectTS))
                {
                    cout <<"Aucun trajet composé présent dans le fichier !" << endl ;
                    return ;
                }
                else if (selectTS && nbrTS==0 && (!selectTC))
                {
                    cout << "Aucun trajet simple présent dans le fichier !" << endl ;
                    return ;
                }
    
                break ;
                
            case '3' : //SELON LES VILLES
                cout <<"Quelle(s) ville(s) souhaitez-vous spécifier? " <<endl ;
                cout <<"1. Ville de départ " << endl ;
                cout <<"2. Ville d'arrivée " << endl ;
                cout <<"3. Ville de départ et d'arrivée " << endl ;
                cout <<"choix : " ;
                //cin.ignore();
                cin.get(c);
                cin.clear(); //nettoyage du stream/buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                while(c!='1' && c!='2' && c!='3')
                {
                    //on nettoie le istream au cas ou l'utilisateur a entrer plusieurs caracteres
                    cout << "erreur,reessayez : " ;
                    cin.get(c);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                }
                
                cout <<" c : " << c << endl ;
                if (c=='1')
                {
                    cout <<"Ville de départ : " ;
                    cin.getline(villeDepart,40) ;
                    selectvD = true ;
                }
                else if (c=='2')
                {
                    cout <<"Ville d'arrivée : " ;
                    cin.getline(villeArrivee,40) ;
                    selectvA = true ;
                }
                else
                {
                    cout <<"Ville de départ : " ;
                    cin.getline(villeDepart,40) ;
                    cout << endl ;
                    cout <<"Ville d'arrivée : " ;
                    cin.getline(villeArrivee,40) ;
                    selectvA = true ;
                    selectvD = true ;
                    
                }
                
                break ;
            
            case '4' :
                char nbr1[40]={} ;
                char nbr2[40]={} ;
                cout <<"borne inférieure : " ;
                cin.getline(nbr1,40) ;
                try
                {
                    borneinf = stoi(nbr1) ;
                }
                catch (const std::invalid_argument& ia)
                {
                    cout << "Ceci n'est pas un nombre. Invalidation de la demande. " << endl ;
                    return ;
                }
                cout <<"borne supérieure : " ;
                cin.getline(nbr2,40) ;
                try
                {
                    bornesup = stoi(nbr2) ;
                }
                catch (const std::invalid_argument& ia)
                {
                    cout << "Ceci n'est pas un nombre. Invalidation de la demande. " << endl ;
                    return ;
                }
                selectIntervalle = true;
                
                
                borneinf = borneinf <= 0 ? 1 : borneinf;
                bornesup = bornesup <= 0 ? 1 : bornesup;//ici la valeur de cb de trajet a prendre !
            
            
                int taille = stoi(nbTS) + stoi(nbTC) ;
                cout << "taille : " << taille << endl ;
                
                if (taille!=0)
                {
                    borneinf = borneinf <= (int) taille ? borneinf : taille;
                    bornesup = bornesup < taille ? bornesup : taille ;
                    bornesup= bornesup < borneinf ? borneinf : bornesup;
                  
                }
                else
                {
                    cout <<"Fichier vide ! Aucun trajet..." ;
                    return ;
                }
        
                break ;
                
        }
        
        string line ;
        int nbrTrajet = 0 ;
        
        while (!fichier.eof())
        {
            getline(fichier,line);
            if (line[0]=='#')
            {
                nbrTrajet ++ ;
                if(line[1]=='S' && selectTS) //CAS D'UN TRAJET SIMPLE
                {
                    
                    int i= 3; //premier caractère appartenant à villeD
                    int j = 0 ;
                    char villeD[40] = {};
                    while(line[i]!=',')
                    {
                        villeD[j]=line[i];
                        i++ ;
                        j++ ;
                    }
                    
                    i++ ; //premier caractère appartenant à villeA
                    j = 0 ;
                    char villeA[40] = {} ;
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
    
                    //si un filtre de ville est selectionné, alors il faut que la ville corresponde.
                    if ((selectvD && strcmp(villeDepart,villeD)==0) || (selectvA && strcmp(villeArrivee,villeA)==0)
                        ||(!(selectvD)&&!(selectvA)&&(!selectIntervalle)) || (selectIntervalle &&nbrTrajet>=borneinf && nbrTrajet<=bornesup))
                    {
                        TrajetSimple *t = new TrajetSimple(villeD,villeA,modeT);
                        AjoutTrajet(t);
                    }
                    
                } else if (line[1]=='C' && selectTC) //CAS D'UN TRAJET COMPOSE
                {
                    Tableau *ensembleT = new Tableau(2);
                    char villeD[40]={} ;
                    int i= 3;
                    int j = 0 ;
                    while (line[i]!=',')
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

                    if ((selectvD&&strcmp(villeDepart,villeD)==0)|| (selectvA && strcmp(villeArrivee,villeA)==0)
                        ||(!(selectvD)&&!(selectvA)&&(!selectIntervalle)) || (selectIntervalle&& nbrTrajet>=borneinf && nbrTrajet<=bornesup))
                    {
                        int nbrEtapes = line[i+1] - '0';
                    
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
    fichier.close();
}

void Catalogue::sauvegarde(const char*nomfichier, char selection)
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
            if (tailleActuelle==0)
            {
                //cout <<"Catalogue vide. " << endl ;
                //return ;
            }
            break;
        case '2':
            cout << "Choisissez le type de trajet à restituer : " << endl;
            cout << " 1. Trajets Simples" << endl;
            cout << " 2. Trajets Composes" << endl;
            cout << "choix : ";
            cin.get(c);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (c != '1' && c != '2')
            {
                //on nettoie le istream au cas ou l'utilisateur à entré plusieurs caractères
              
                cout << "erreur, reessayez : ";
                cin.get(c);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
            }
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
            cin.get(c);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (c != '1' && c != '2' && c != '3')
            {
                //on nettoie le istream au cas ou l'utilisateur a entre plusieurs caracteres
                cout << "erreur, reessayez : ";
                cin.get(c);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (c == '1' || c=='3')
            {
                cout << "Rentrez la ville de départ : " ;
                cin.getline(selectvilleD, 40);
                cout << endl;
            }
            if (c == '2' || c=='3')
            {
                cout << "Rentrez la ville d'arrivée : " ;
                cin.getline(selectvilleA, 40);
                cout << endl;
            }
            break;//du 3
        case '4':
            char b1[5]= {} ;
            char b2[5]= {} ;
            
            cout << "Combien voulez de trajets ? " ;
            cin.getline(b2,5);
            cout << "A partir d'où voulez vous partir ? " ;
            cin.getline(b1,5);
            try
            {
                borne1 = stoi(b1);
                borne2 = stoi(b2);
            
            } catch (const std::invalid_argument& ia)
            {
                cout << "Ceci n'est pas un nombre. Invalidation de la demande. " << endl ;
                return ;
            }
            
            --borne1; //mise en repère tableau (rentrer 1 donnera le premier élément situé en [0])
            
            
            borne1 = borne1 < 0 ? 0 : borne1;
            borne2 = borne2 < 0 ? 0 : borne2;//ici la valeur de cb de trajet a prendre !
            
            borne1 = borne1 < tailleActuelle ? borne1 : tailleActuelle;
            borne2= borne1+borne2 < tailleActuelle ? borne1+borne2 : tailleActuelle;
            break;
    }
    
    
    fstream fichier;
    
    fichier.open(nomfichier);
    
    int nbTC = 0;
    int nbTS = 0;
    
    if (fichier)
    {
        cout << "Le fichier existe déjà, voulez-vous l'écraser ?(e), écrire à la suite ?(s) ou abandonner?(a) " << endl;
        int fait = 0;
        cin.get(c);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (!fait)
        {
            fait = 1;
            if (c == 'e')
            {
                //réouverture du fichier en supprimant le contenu
                fichier.close();
                //en ouvrant avec l'option troncature, on efface le contenu précédent.
                fichier.open(nomfichier, std::ofstream::out | std::ofstream::trunc);
            }
            else if (c == 's')
            {
                //recuperation n° au début
                string nbr1, nbr2 ;
                getline(fichier,nbr1,'-');
                getline(fichier,nbr2);
              
                //pas de try() catch() car nous supposons que le fichier est aux normes
                nbTS = stoi(nbr1);
                nbTC = stoi(nbr2);
                
                fichier.close();
                Erase_First_Line(nomfichier);//effacement de la ligne contenant les numéros au début en réécrivant le reste
                fichier.open(nomfichier, ios_base::ate);//puis réécriture à la fin
                
            }
            else if (c=='a')
            {
                cout << "abandon " << endl ;
                return ;
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
    
    cout << "on redirige le buffer vers le fichier" << endl ;
    streambuf *oldStreamBuffer = cout.rdbuf(fichier.rdbuf());
    fichier.seekp(5); //on fait de la place pour l'affichage des nombres de trajet
    for (unsigned int i = borne1; i < borne2; i++)
    {
        const char type = tableau[i]->getType();

        bool ajout = true;
        
        if (selection == '3' && (c == '1'|| c=='3') && strcmp(tableau[i]->getVilleDepart(),selectvilleD)!=0)
        {
            ajout = false;
        }
        if (selection == '3' && (c == '2' || c == '3') && strcmp(tableau[i]->getVilleArrivee(), selectvilleA) != 0)
        {
            ajout = false;
        }
        if (!(selectTS) && type=='S')
        {
            ajout = false;
        }
        if (!(selectTC) && type=='C')
        {
            ajout = false;
        }
        
        if (ajout)
        {
            fichier << '#' << type << ',';
            //incrémentation du nombre de trajet par type
            if (type=='S')
            {
                nbTS++;
            }
            else
            {
                nbTC++;
            }
            
            tableau[i]->outputFormate();
        }
    }
    
    //on met à jour le fichier avec les nombre de trajet au debut
    fichier.seekp(0);
    cout << nbTS << "-" << nbTC << endl;
    
    cout.rdbuf(oldStreamBuffer);
    fichier.close();
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
