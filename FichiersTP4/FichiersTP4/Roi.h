/**************************************************
* Titre:	Travail pratique #4 - Roi.h
* Date:		24 fevrier 2017
* Auteur:	FERRON, Samue. FONTAINE, Jean-Frederic.
**************************************************/

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

	virtual bool estMouvementValide(int toX, int toY);  
	virtual bool deplacer(int toX, int toY);

};
#endif
