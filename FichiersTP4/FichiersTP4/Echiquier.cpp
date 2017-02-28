/**********************************************
* Titre: Travail pratique #1 - Echiquier.cpp
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
			//delete vecteurPiecesBlanches_[i];
			vecteurPiecesBlanches_[i] = NULL;
		}
		for (int j = 0; j < vecteurPiecesNoires_.size(); j++) {
			//delete vecteurPiecesBlanches_[j];
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
*Descriptions:	permet d'ajouter une piece a l'echiquier. Cette fonction
				verifie qu'aucune autre piece a le meme ID. De plus, la fonciton effectue
				un cast dynamic afin de verifier si le type inserer est compatible. 
*Parametre:		-(Piece*)piece		 : Le pointeur de la piece a ajouter. 
*Retour:		-(Personnel&)this : le personnel modiffie
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
	if (!memeId)
		reconnaiseurDeClasse(*piece, couleurNoir);
	return *this;
}


/*********************************************
*Fonctions:		Echiquier::reconnaiseurDeClasse()
*Descriptions:	Cette fonction permet de construire un pointeur 
				pointant vers un nouvel objet de type Piece en precisant 
				de quel type de piece nous avons affaire.
				
un cast dynamic afin de verifier si le type inserer est compatible.
*Parametre:		-(Piece*)piece		 : Le pointeur de la piece a ajouter.
*Retour:		-(Personnel&)this : le personnel modiffie
*********************************************/
 void Echiquier::reconnaiseurDeClasse(const Piece &p,const bool couleur) {

 	string nomDuType = typeid(p).name();
 	Piece* nouveau = nullptr;
	bool ajouter = false;

	if (nomDuType == "Roi") {
		nouveau = new Roi(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true; 
	}
 	else if (nomDuType == "Pion"){
 		nouveau = new Pion(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true;
	}
 	else if (nomDuType == "Tour"){
 		nouveau = new Tour(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true;
	}
 	else if (nomDuType == "Reine"){
 		nouveau = new Reine(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
		ajouter = true;
	}
	else if (nomDuType == "Fou") {
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












bool Echiquier::promouvoir(Piece &piece) {
	int nombreAll = rand() %2;
	int index = -1;
	bool estBlanc = true;
	for (unsigned i =0; i < vecteurPiecesBlanches_.size(); i++){
		if (vecteurPiecesBlanches_[i]->obtenirId() == piece.obtenirId()) {
			index = i;
			estBlanc = true;
		}
		else if (vecteurPiecesNoires_[i]->obtenirId() == piece.obtenirId()) {
			index = i;
			estBlanc = false;
		}
	}
	Pion* lePion = dynamic_cast<Pion*>(&piece);
	if ((lePion != NULL) && index >= 0) {
		switch (nombreAll) {
		case 0: 
			if (estBlanc) {
				vecteurPiecesBlanches_[index] = new Reine(*lePion);
			}
			else {
				vecteurPiecesNoires_[index] = new Reine(*lePion);
			}
		break;
		case 1: 
			if (estBlanc) {
				vecteurPiecesBlanches_[index] = new Tour(*lePion);
			}
			else {
				vecteurPiecesNoires_[index] = new Tour(*lePion);
			}
		break;
		case 2: 
			if (estBlanc) {
				vecteurPiecesBlanches_[index] = new Fou(*lePion);
			}
			else {
				vecteurPiecesNoires_[index] = new Fou(*lePion);
			}
		break;
		}
		return true;
	}
	return false;
}

/*********************************************
*Fonctions:		operato <<
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