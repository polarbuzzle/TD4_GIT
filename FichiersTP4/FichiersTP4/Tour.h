/**************************************************
* Titre:        Travail pratique #4 - Tour.h
* Date:         24 fevrier 2017
* Auteur:       FERRON, Samue. FONTAINE, Jean-Frederic.
*Description:   Fichier header de la classe Tour
**************************************************/

#ifndef TOUR_H
#define TOUR_H

#include "Piece.h"
#include <string>
#include "Pion.h"

using namespace std;

class Tour : public Piece {

public:
	// Constructeurs
	Tour();
	Tour(const string& id, const string& couleur, int positionX, int positionY);
	Tour(const Pion& pion);

	// Destructeur
	virtual ~Tour();
	
	virtual bool estMouvementValide(int toX, int toY) const;
	virtual bool deplacer(int toX, int toY);
};
#endif
