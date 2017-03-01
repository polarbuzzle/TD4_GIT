/**********************************************
 * Titre:       Travail pratique #4 - Echiquier.cpp
 * Date:        24 fevrier 2017
 * Auteur:      FERRON Samuel, FONTAINE Jean-Frederic
 *Description:  Implementation de la classe roi 
 *********************************************/
#include <cmath>
#include "Roi.h"


/*********************************************
*Fonctions:		Roi()
*Descriptions:     Constructeur par defaut d'une Reine
*Parametre:		Aucun
*Retour:           Aucun
 *********************************************/
Roi::Roi(): Piece("defaultId", "blanc", 0, 0) {}


/*********************************************
*Fonctions:         Reine()
*Descriptions:     Constructeur par parametres Reine
*Parametre:        -(string)id      : string de l'id
*                  -(string)couleur : string de la couleur de la piece
*                  -(int)positionX  : int de la position en x
*                  -(int)positionY  : int de la position en y
*Retour:            Aucun
 *********************************************/
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
		modifierPositionY(toY);		
		return true;
	}
	return false;
}
