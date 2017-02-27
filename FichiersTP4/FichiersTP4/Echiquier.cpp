/**********************************************
* Titre: Travail pratique #1 - Echiquier.cpp
* Date: 24 fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Implementation de classe Echiquier
*********************************************/
#include "Echiquier.h"
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
	string couleur = piece->obtenirCouleur();
	bool couleurNoir = false; 
	if (couleur == "blanc") {

		for (int i = 0; i < vecteurPiecesBlanches_.size(); i++) {
			if (vecteurPiecesBlanches_[i]->obtenirId() == piece->obtenirId())
				memeId = true;

		}
	}
	else if (couleur == "noir") {
		couleurNoir = true; 
		for (int j = 0; j < vecteurPiecesNoires_.size(); j++) {
			if (vecteurPiecesNoires_[j]->obtenirId() == piece->obtenirId()) {
				memeId = true;
			}
		}
	}

	


	


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

	if (nomDuType == "Roi") 
		nouveau = new Roi(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
	else if (nomDuType == "Pion")
		nouveau = new Pion(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
	else if (nomDuType == "Tour")
		nouveau = new Tour(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
	else if (nomDuType == "Reine")
		nouveau = new Reine(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());
	else if (nomDuType == "Fou")
		nouveau = new Fou(p.obtenirId(), p.obtenirCouleur(), p.obtenirPositionX(), p.obtenirPositionY());

	if (!couleur)
		vecteurPiecesBlanches_.push_back(nouveau);
	else
		vecteurPiecesNoires_.push_back(nouveau);
}












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

}
