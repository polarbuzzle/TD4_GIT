/********************************************
* Titre:	Travail pratique #4 - Piece.h
* Date:		24 février 2017
* Auteur:	FERRON, Samuel. FONTAINE, Jean-Frederic
*******************************************/

#ifndef PIECE_H
#define PIECE_H


#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

 class Piece {


public :
	// constructeurs
	Piece() {}
	Piece(const string& id, const string& couleur, int positionX, int positionY)
		:id_(id), couleur_(couleur), positionX_(positionX), positionY_(positionY){}

	// destructeur
	~Piece() {}

	// acesseur et modificateur
	string obtenirId() const {
		return id_; 
	}

	void modifierId(const string& id) {
		id_ = id;
	}

	string obtenirCouleur() const { 
		return couleur_;
	}

	void modifierCouleur(const string& couleur) {
		couleur_ = couleur; 
	}

	int obtenirPositionX() const {
		return positionX_; 
	}
	void modifierPositionX(int x) {
		positionX_ = x; 
	}

	int obtenirPositionY() const {
		return positionY_; 
	}

	void modifierPositionY(int y) {
		positionY_ = y;
	}
	//Retourne le type (classe) de la piece
	string obtenirType() const 	{ 
		return typeid(*this).name();
	}

	/*********************************************
	*Fonctions:		estMouvementValide()
	*Descriptions:	Verifi si le deplacement est valide ou non
	*Parametre:		toX : destination en x
	               	toY : destination en y
	*Retour:		estValide : retourne vrai si le mouvement est valide
	*********************************************/
	virtual bool estMouvementValide(int toX, int toY) const{
		bool estValide = false;
		bool estValideX = (toX < 8 && toX >= 0);
		bool estValideY = (toY < 8 && toY >= 0);
		if(estValideX && estValideY) {
			estValide = ((toX - obtenirPositionX() != 0) || (toY - obtenirPositionY() != 0));
		}
		return estValide;
	} 

	//Methode virtuelle pure
	virtual bool deplacer(int toX, int toY) = 0;


	virtual ostream&  afficher(ostream& stream) const {
		stream << "Piece " << couleur_ << " d'id " << id_ << " : " << endl;
		stream << "Position (" << positionX_ << ", " << positionY_ << ")" << endl;
		return stream;
	}
	
	friend ostream& operator<<(ostream& out, const Piece& piece)
	{
		piece.afficher(out);
		return out;
	}

private:
	//Attributs
	string id_;
	string couleur_;
	int positionX_;
	int positionY_;

};
#endif
