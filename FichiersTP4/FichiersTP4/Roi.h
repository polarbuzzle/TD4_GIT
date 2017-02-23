
/********************************************
* Titre: Travail pratique #4 - Roi.h
* Date:
* Auteur:
*******************************************/

#ifndef ROI_H
#define ROI_H


#include "Piece.h"
#include <string>

using namespace std;

class Roi : public Piece{

public :
	Roi();
	Roi(const string& id, const string& couleur, int positionX, int positionY);
	~Roi();	

	bool estMouvementValide(int toX, int toY);  
	bool deplacer(int toX, int toY);

};
#endif