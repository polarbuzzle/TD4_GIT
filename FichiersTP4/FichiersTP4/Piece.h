
/********************************************
* Titre: Travail pratique #4 - Piece.h
* Date:
* Auteur:
*******************************************/

#ifndef PIECE_H
#define PIECE_H


#include <iostream>
#include <string>

using namespace std;

 class Piece {


public :
	// constructeurs
	Piece() {}
	Piece(const string& id, const string& couleur, int positionX, int positionY):id_(id), couleur_(couleur), positionX_(positionX), positionY_(positionY){}

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

	
	bool estMouvementValide(int toX, int toY) const{
		// A IMPLEMENTER
	} 

     
	bool deplacer(int toX, int toY); // A MODIFIER

	
	string obtenirType() const 	{ 
		// A IMPLEMENTER	
	}

	friend std::ostream& operator<<(std::ostream& out, const Piece& piece)
	{
		//A IMPLEMENTER
	}

	                                            
	ostream&  afficher(ostream& stream) const {  // A MODIFIER SI NECESSAIRE
		stream << "Piece " << couleur_ << " d'id " << id_ << " : " << endl;
		stream << "Position (" << positionX_ << ", " << positionY_ << ")" << endl;
		return stream;
	}

private:

	string id_;
	string couleur_;
	int positionX_;
	int positionY_;

};
#endif