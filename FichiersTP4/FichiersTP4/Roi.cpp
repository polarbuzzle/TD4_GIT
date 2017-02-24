
/********************************************
* Titre: Travail pratique #4 - Roi.cpp
* Date:
* Auteur:
*******************************************/
#include <cmath>
#include "Roi.h"

Roi::Roi(): Piece("defaultId", "blanc", 0, 0) {}

Roi::Roi(const string& id, const string& couleur, int positionX, int positionY) : Piece( id,  couleur, positionX, positionY) {
}

bool Roi::estMouvementValide(int toX, int toY)  {
	if (!Piece::estMouvementValide(toX, toY))
		return false;	
	if (abs(obtenirPositionX() - toX) == 1 && abs(obtenirPositionY() - toY) == 1 ||
		abs(obtenirPositionX() - toX) == 0 && abs(obtenirPositionY() - toY) == 1 ||
		abs(obtenirPositionX() - toX) == 1 && abs(obtenirPositionY() - toY) == 0)
		return true;
	else
		return false;
}

Roi::~Roi() {}

bool Roi::deplacer(int toX, int toY)  {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionX(toY);		
		return true;
	}
	return false;
}