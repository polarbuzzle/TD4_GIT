
/********************************************
* Titre: Travail pratique #4 - Reine.cpp
* Date:
* Auteur:
*******************************************/
#include <cmath>
#include "Reine.h"

Reine::Reine(): Piece("defaultId", "blanc", 0, 0) {}

Reine::Reine(const string& id, const string& couleur, int positionX, int positionY) 
    : Piece( id,  couleur, positionX, positionY) {}

Reine::Reine(const Pion& pion) 
    : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()) {}

Reine::~Reine() {}

bool Reine::estMouvementValide(int toX, int toY) const{
    bool estValide = false;
	if (Piece::estMouvementValide(toX, toY)) {
		if ((obtenirPositionX() == toX)  || (obtenirPositionY() == toY))		
		estValide = true;
	}
	if (Piece::estMouvementValide(toX, toY)) {
        int diffX = abs(toX - obtenirPositionX());
        int diffY = abs(toY - obtenirPositionY());
        if (diffX == diffY) {
            estValide = true;
        }
    }
    return estValide;
}

bool Reine::deplacer(int toX, int toY)  {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);		
		return true;
	}
	return false;
}

ostream&  Reine::afficher(ostream& stream) const {  // A MODIFIER SI NECESSAIRE
		stream << "Reine " << obtenirCouleur() << " d'id " << obtenirCouleur() << " : " << endl;
		stream << "Position (" << obtenirPositionX() << ", " << obtenirPositionY() << ")" << endl;
		return stream;
}