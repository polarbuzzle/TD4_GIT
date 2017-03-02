/**********************************************
* Titre: Travail pratique #4 - Echiquier.cpp
* Date: 24 fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Implementation de classe Echiquier
*********************************************/
#include "Echiquier.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Piece.h"
using namespace std;

/*********************************************
*Fonctions:		Echiquier()
*Descriptions:	Constructeur par defaut d'un echiquier
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Echiquier::Echiquier() {}

/*********************************************
*Fonctions:		Echiquier::~Echiquier()
*Descriptions:	Destructeur de la classe echiquier qui s'assure de 
				supprimmer non-seulement les pointeurs qu'il contient 
				mais aussi les pieces vers lesquelles ceux-ci pointent. 
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
	Echiquier::~Echiquier() {
		for (int i = 0; i < vecteurPiecesBlanches_.size(); i++) {
			delete vecteurPiecesBlanches_[i];
			vecteurPiecesBlanches_[i] = NULL;
			 
		}
		for (int j = 0; j < vecteurPiecesNoires_.size(); j++) {
			delete vecteurPiecesNoires_[j];
			vecteurPiecesNoires_[j] = NULL;
		}
	}

/*************************************************************************************
*Fonctions:		Echiquier::deplacerPiece()
*Descriptions:	Fonction qui permet de modifier les coordonne d'une
*				piece, c'est-a-dire effectuer un deplacement. Cette fonction 
*				verifie indirectement la possibilite de ce deplacement par 
*				la fonction virtuelle 'deplacer' de chaque piece.  
*Parametre:		-(const string)id			: Id de la piece a deplacer
*				-(int)toX					: Nouvel coordone en X
*				-(int)toY					: Nouvel coordonne en Y
*Retour:		-(bool)deplacementReussi	: retourne vrai si le deplacement a ete effecuer, 
											  faux si le contaire. 
*************************************************************************************/
bool Echiquier::deplacerPiece(const string& id, int toX, int toY) {
	bool deplacementReussi; 
	bool pieceTrouver = false; 

	for (int i = 0; i < vecteurPiecesBlanches_.size(); i++) {
		if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			deplacementReussi = vecteurPiecesBlanches_[i]->deplacer(toX, toY);
			pieceTrouver = true; 
		}
	}
	for (int j = 0; j < vecteurPiecesNoires_.size() && !pieceTrouver; j++) {
		if (vecteurPiecesNoires_[j]->obtenirId() == id) {
			deplacementReussi = vecteurPiecesNoires_[j]->deplacer(toX, toY);
			pieceTrouver = true; 
		}
	}

	if (deplacementReussi) {
		cout << "Deplacement de la piece reussie" << endl;
	}
	else {
		cout << "Mouvement non valide" << endl;
	}

	return deplacementReussi; 
}
/*********************************************
*Fonctions:		Echiquier::operator+=()
*Descriptions:	Permet d'ajouter une piece a l'echiquier. Cette fonction
*				verifie qu'aucune autre piece a le meme ID. Si l'objet qu'on 
*				tente d'inserer nest pas compatible un message d'erreur sera affiche.
*Parametre:		-(Piece*)piece		 : Le pointeur de la piece a ajouter. 
*Retour:		-(Personnel&)this	 : le personnel modiffie
*********************************************/
Echiquier& Echiquier::operator+=(Piece* piece) {
	bool memeId = false; 
	//string couleur = piece->obtenirCouleur();
	bool couleurNoir = piece->obtenirCouleur() == "noir";

	if (!couleurNoir) {

		for (int i = 0; i < vecteurPiecesBlanches_.size(); i++) {
			if (vecteurPiecesBlanches_[i]->obtenirId() == piece->obtenirId()) {
				memeId = true;
				cout << "Piece avec la meme ID, impossible d'ajouter !" << endl;
			}
		}
	}
	else if (couleurNoir) {
		for (int j = 0; j < vecteurPiecesNoires_.size(); j++) {
			if (vecteurPiecesNoires_[j]->obtenirId() == piece->obtenirId()) {
				memeId = true;
				cout << "Piece avec la meme ID, impossible d'ajouter !" << endl;
			}
			
		}
	}
	if (!memeId) {
		reconnaiseurDeClasse(*piece, couleurNoir);
	}
	return *this;
}
/*********************************************
*Fonctions:		Echiquier::reconnaiseurDeClasse()
*Descriptions:	Cette fonction est utilise dans la fonction += afin 
*				de reconnaitre a quel type de piece nous avons affaire. Ensuite, 
*				on insere la piece dans le vecteur approprier selon la couleur 
*				de celle-ci. 
*Parametre:		-(Piece)piece		: Le pointeur de la piece a ajouter.
*				-(bool)couleur		: Couleur de la piece. 
*Retour:		-(Personnel&)this	: le personnel modiffie
*********************************************/
 void Echiquier::reconnaiseurDeClasse(const Piece &p,const bool couleur) {

 	string nomDuType = typeid(p).name();
 	Piece* nouveau = nullptr;
	bool ajouter = false;

	if (nomDuType == "class Roi") {
		nouveau = new Roi(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true; 
	}
 	else if (nomDuType == "class Pion"){
 		nouveau = new Pion(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true;
	}
 	else if (nomDuType == "class Tour"){
 		nouveau = new Tour(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true;
	}
 	else if (nomDuType == "class Reine"){
 		nouveau = new Reine(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true;
	}
	else if (nomDuType == "class Fou") {
		nouveau = new Fou(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true;
	}
	else
		cout << "Cet objet est incompatible !" << endl;
 	
	if (!couleur && ajouter)
 		vecteurPiecesBlanches_.push_back(nouveau);
 	else if (ajouter)
 		vecteurPiecesNoires_.push_back(nouveau);
 }
 /*******************************************************************
*Fonctions:			Echiquier::operator+=()
*Descriptions:		Fonction qui permet de retirer une piece de
*					l'echiquier. 
*Parametre:			-(string&)id		: L'id de la piece a retirer
*Retour:			-(Echiquie&)*this	: L'echiquier avec l'element en moin. 
 *******************************************************************/
 Echiquier& Echiquier::operator-=(const string& id) {

	 bool trouver = false;
	 for (int i = 0; i < vecteurPiecesBlanches_.size(); i++) {
		 if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			 delete vecteurPiecesBlanches_[i];
			 vecteurPiecesBlanches_[i] = vecteurPiecesBlanches_[vecteurPiecesBlanches_.size() - 1];
			 vecteurPiecesBlanches_.pop_back();
			 trouver = true;
		 }
	 }
	 for (int i = 0; i < vecteurPiecesNoires_.size() && !trouver; i++) {
		 if (vecteurPiecesNoires_[i]->obtenirId() == id) {
			 delete vecteurPiecesNoires_[i];
			 vecteurPiecesNoires_[i] = vecteurPiecesNoires_[vecteurPiecesNoires_.size() - 1];
			 vecteurPiecesNoires_.pop_back();
			 trouver = true;
		 }
	 }
	 return *this; 
 }
/*******************************************************************
*Fonctions:			Echiquier::promouvoir()
*Descriptions:		Fonction qui permet de promouvoir une piece de type Pion
*					au titre de la piece choisi par le joueur. 
*Parametre:		-(Piece*)piece		 : Le pion a promouvoir 
*Retour:		-(bool)				 : Vrai si le pion a ete promu, faux dans le cas contaire. 
 *******************************************************************/
bool Echiquier::promouvoir(const string& id) {
	int nombreAll = rand() %2;
	int index = -1;
	bool estBlanc = true;
	bool estTrouve = false;
	bool estPion = false;
	Pion* lePion = nullptr;
	for (unsigned i = 0; i < vecteurPiecesBlanches_.size(); i++) {
		if (vecteurPiecesBlanches_[i]->obtenirId() == id && vecteurPiecesBlanches_[i]->obtenirType() == "class Pion") {
			lePion = new Pion(vecteurPiecesBlanches_[i]->obtenirId(),
				vecteurPiecesBlanches_[i]->obtenirCouleur(),
				vecteurPiecesBlanches_[i]->obtenirPositionX(),
				vecteurPiecesBlanches_[i]->obtenirPositionY());
			estBlanc = true;
			estTrouve = true;
			index = i;
		}
	}
	for(unsigned i = 0; i < vecteurPiecesNoires_.size() && !estTrouve; i++) {
		 if (vecteurPiecesNoires_[i]->obtenirId() == id && vecteurPiecesNoires_[i]->obtenirType() == "class Pion") {
			 lePion = new Pion(vecteurPiecesNoires_[i]->obtenirId(),
				 vecteurPiecesNoires_[i]->obtenirCouleur(),
				 vecteurPiecesNoires_[i]->obtenirPositionX(),
				 vecteurPiecesNoires_[i]->obtenirPositionY());
			estBlanc = false;
			estTrouve = true;
			index = i;
		}
	}

	if (estTrouve) {
		
		switch (nombreAll) {
		case 0: 
			if (estBlanc) {
				vecteurPiecesBlanches_[index] = new Reine(*lePion);
			}
			else {
				vecteurPiecesNoires_[index] = new Reine(*lePion);
			}
			cout << "Le pion d'id " << id << "est maintenant une reine" << endl;
		break;
		case 1: 
			if (estBlanc) {
				vecteurPiecesBlanches_[index] = new Tour(*lePion);
			}
			else {
				vecteurPiecesNoires_[index] = new Tour(*lePion);
			}
			cout << "Le pion d'id " << id << "est maintenant une tour" << endl;
		break;
		case 2: 
			if (estBlanc) {
				vecteurPiecesBlanches_[index] = new Fou(*lePion);
			}
			else {
				vecteurPiecesNoires_[index] = new Fou(*lePion);
			}
			cout << "Le pion d'id " << id << "est maintenant un fou" << endl;
		break;
		}
		delete lePion;
		return true;
	}
	cout << "Promotion impossible" << endl;
	return false;
}

/*********************************************
*Fonctions:		operator <<
*Descriptions:	Permet d'afficher toutes les informations
				de chacune des pieces dans ses vecteurs.				
*Parametre:		out : flux dans lequel on met les informations
				echiquier : l'echiquier que nous voulons afficher
*Retour:		out : flux dans lequel on a mit les informations
*********************************************/
std::ostream & operator<<(std::ostream & out, const Echiquier & echiquier)
{
	out << "------------INFORMATION PIECES BLANCHES------------" << endl;
	out << "Il y a " << echiquier.vecteurPiecesBlanches_.size() << " Pieces blanches" << endl;
	for (unsigned i = 0 ; i < echiquier.vecteurPiecesBlanches_.size(); i++) {
		cout << *(echiquier.vecteurPiecesBlanches_[i]) << endl;
	}

	out << endl;
	out << "------------INFORMATION PIECES NOIRES--------------" << endl;
	out << "Il y a " << echiquier.vecteurPiecesNoires_.size() << " Pieces noires" << endl;
	for (unsigned i = 0; i < echiquier.vecteurPiecesNoires_.size(); i++) {
		cout << *(echiquier.vecteurPiecesNoires_[i]) << endl;
	}
	return out;
}