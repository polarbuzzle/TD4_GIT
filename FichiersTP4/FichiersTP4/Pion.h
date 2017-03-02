/**************************************************
* Titre:	Travail pratique #4 - Pion.h
* Date:		24 fevrier 2017
* Auteur:	FERRON, Samue. FONTAINE, Jean-Frederic.
**************************************************/

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

	virtual bool estMouvementValide(int toX, int toY);
	virtual bool deplacer(int toX, int toY);

private:
	bool estPositionInitiale_;

};
#endif
