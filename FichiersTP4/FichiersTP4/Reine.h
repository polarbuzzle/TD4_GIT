/**************************************************
* Titre:	Travail pratique #4 - Reine.h
* Date:		24 fevrier 2017
* Auteur:	FERRON, Samue. FONTAINE, Jean-Frederic.
**************************************************/

#ifndef Reine_H
#define Reine_H

#include "Tour.h"
#include "Fou.h"
#include <string>
#include "Pion.h"
using namespace std;

class Reine : public Piece {

public:
	// Constructeurs
	Reine();
	Reine(const string& id, const string& couleur, int positionX, int positionY);
	Reine(const Pion& pion);
	// Destructeur
	virtual ~Reine();

	virtual bool estMouvementValide(int toX, int toY) const;
	virtual bool deplacer(int toX, int toY);
	virtual ostream&  afficher(ostream& stream) const;

};
#endif