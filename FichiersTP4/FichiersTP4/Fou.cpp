
/********************************************
* Titre: Travail pratique #4 - Fou.cpp
* Date:
* Auteur:
*******************************************/
#include <cmath>
#include "Fou.h"

Fou::Fou(): Piece("defaultId", "blanc", 0, 0) {}

Fou::Fou(const string& id, const string& couleur, int positionX, int positionY) 
    : Piece( id,  couleur, positionX, positionY) {}

Fou::Fou(const Pion& pion) 
    : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()) {}

Fou::~Fou() {}

bool Fou::estMouvementValide(int toX, int toY) const {
    bool estValide = false;
	if (Piece::estMouvementValide(toX, toY)) {
        int diffX = abs(toX - obtenirPositionX());
        int diffY = abs(toY - obtenirPositionY());
        if (toX == toY) {
            estValide = true;
        }
    }
    return estValide;
}

bool Fou::deplacer(int toX, int toY)  {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionX(toY);		
		return true;
	}
	return false;
}

ostream&  Fou::afficher(ostream& stream) const {  // A MODIFIER SI NECESSAIRE
		stream << "Fou " << obtenirCouleur() << " d'id " << obtenirCouleur() << " : " << endl;
		stream << "Position (" << obtenirPositionX() << ", " << obtenirPositionY() << ")" << endl;
		return stream;
}