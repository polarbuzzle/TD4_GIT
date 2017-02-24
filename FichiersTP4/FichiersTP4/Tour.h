
/********************************************
* Titre: Travail pratique #4 - Tour.h
* Date:
* Auteur:
*******************************************/

#ifndef TOUR_H
#define TOUR_H

#include "Piece.h"
#include <string>
#include "Pion.h"

using namespace std;

class Tour : virtual public Piece {

public:
	// Constructeurs
	Tour();
	Tour(const string& id, const string& couleur, int positionX, int positionY);
	Tour(const Pion& pion);

	// Destructeur
	~Tour();
	
	virtual bool estMouvementValide(int toX, int toY);
	virtual bool deplacer(int toX, int toY);
};
#endif