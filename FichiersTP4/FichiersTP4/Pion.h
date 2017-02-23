
/********************************************
* Titre: Travail pratique #4 - Pion.h
* Date:
* Auteur:
*******************************************/

#pragma once

#ifndef PION_H
#define PION_H


#include "Piece.h"
#include <string>

using namespace std;

class Pion : public Piece {

public:
	// Constructeurs
	Pion();
	Pion(const string& id, const string & couleur, int positionX, int positionY);

	// Destructeur
	~Pion();
	
	bool obtenirEstPositionInitiale() const;
	void setEstPositionInitiale(bool estPositionInitiale);

	bool estMouvementValide(int toX, int toY);
	bool deplacer(int toX, int toY);

private:
	bool estPositionInitiale_;

};
#endif
