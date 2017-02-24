/**********************************************
* Titre: Travail pratique #1 - Echiquier.cpp
* Date: 24 fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Implementation de classe Echiquier
*********************************************/
#include "Echiquier.h"
#include <time.h>
#include <string>
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
		vecteurPiecesBlanches_[i] = nullptr; 
	}
	for (int j = 0; j < vecteurPiecesNoires_.size(); j++) {
		delete vecteurPiecesBlanches_[j];
		vecteurPiecesNoires_[j] = nullptr;
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
		if (vecteurPiecesBlanches_[i]->obtenirId == id) {
			deplacementReussi = vecteurPiecesBlanches_[i]->deplacer(toX, toY);
			pieceTrouver = true; 
		}
	}
	for (int j = 0; j < vecteurPiecesNoires_.size() && !pieceTrouver; j++) {
		if (vecteurPiecesNoires_[j]->obtenirId == id) {
			deplacementReussi = vecteurPiecesNoires_[j]->deplacer(toX, toY);
			pieceTrouver = true; 
		}
	}

	return deplacementReussi; 
}





std::ostream & operator<<(std::ostream & out, const Echiquier & echiquier)
{
	out << "------------INFORMATION PIECES BLANCHES------------" << endl;
	out << "Il y a " << << " Pieces blanches" << endl;



	out << endl;
	out << "------------INFORMATION PIECES NOIRES--------------" << endl;
	out << "Il y a " << << " Pieces noires" << endl;

}
