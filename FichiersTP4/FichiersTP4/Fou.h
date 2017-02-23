
/********************************************
* Titre: Travail pratique #4 - Fou.h
* Date:
* Auteur:
*******************************************/

#ifndef FOU_H
#define FOU_H

#include "Piece.h"
#include <string>
#include "Pion.h"
using namespace std;

class Fou : public Piece {

public:
	// Constructeurs
	Fou();
	Fou(const string& id, const string& couleur, int positionX, int positionY);
	Fou(const Pion& pion);
	// Destructeur
	~Fou();

	bool estMouvementValide(int toX, int toY) const;
	bool deplacer(int toX, int toY);
	ostream&  afficher(ostream& stream) const;

	
};
#endif