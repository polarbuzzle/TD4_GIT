
/********************************************
* Titre: Travail pratique #4 - Tour.cpp
* Date:
* Auteur:
*******************************************/

#include "Tour.h"

Tour::Tour() :Piece("defaultId", "blanc", 0, 0){
}

Tour::Tour(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY){
}

Tour::Tour(const Pion & pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()){
}

Tour::~Tour(){
}


bool Tour::estMouvementValide(int toX, int toY) const{
	if (!Piece::estMouvementValide(toX, toY))
		return false;
	if ((obtenirPositionX() == toX)  || (obtenirPositionY() == toY))		
		return true;
	else
		return false;
}

bool Tour::deplacer(int toX, int toY){
	if (estMouvementValide(toX, toY)) {
		cout << "ok" << endl;
		modifierPositionX(toX);
		modifierPositionY(toY);
		return true;
	}
	return false;
}