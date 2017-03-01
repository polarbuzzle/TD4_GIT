/**********************************************
 * Titre:       Travail pratique #4 - Echiquier.cpp
 * Date:        24 fevrier 2017
 * Auteur:      FERRON Samuel, FONTAINE Jean-Frederic
 *Description:  Implementation de la classe Pion
 *********************************************/
#include "Pion.h"

/*********************************************
 *Fonctions:		Pion()
 *Descriptions:     Constructeur par defaut.
 *Parametre:		Aucun
 *Retour:           Aucun
 *********************************************/
Pion::Pion():Piece("defaultId","blanc",0,0),estPositionInitiale_(true){
}

/*********************************************
*Fonctions:         Pion()
*Descriptions:      Constructeur par parametre
*Parametre:		 -(string)id      : string de l'id
*                -(string)couleur : string de la couleur de la piece
*                -(int)positionX  : int de la position en x
*                -(int)positionY  : int de la position en y
*Retour:        Aucun
 *********************************************/
Pion::Pion(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY) {
	estPositionInitiale_ = true;
}
/*********************************************
 *Fonctions:         ~Pion()
 *Descriptions:      Destructeur
 *Parametre:        Aucun
 *Retour:           Aucun
 *********************************************/
Pion::~Pion() {
}

/*********************************************
*Fonctions:         obtenirEstPositionInitiale()
*Descriptions:      Permet dsavoir si la piece a est la position initale de la piece.
*Parametre:         Aucun
*Retour:            -(bool)
 *********************************************/

bool Pion::obtenirEstPositionInitiale() const{
	return estPositionInitiale_;
}
/*********************************************
 *Fonctions:         setEstPositionInitiale
 *Descriptions:      setteur pour mettre le position initiale a true ou false.
 *Parametre:         -(bool)estPositionInitiale : vrai ou faux si position initiale.
 *Retour:            Aucun
 *********************************************/

void Pion::setEstPositionInitiale(bool estPositionInitiale) {
	estPositionInitiale_ = estPositionInitiale;
}

/*********************************************
 *Fonctions:		estMouvementValide()
 *Descriptions:     Verifi si le deplacement est valide ou non
 *Parametre:		-(int)toX           : destination en x
 *                  -(int)toY           : destination en y
 *Retour:           -(bool)estValide    : retourne vrai si le mouvement est valide
 *********************************************/
bool Pion::estMouvementValide(int toX, int toY) {
	if (!Piece::estMouvementValide(toX, toY))
		return false;
	if (obtenirCouleur() == "blanc") {
		if (obtenirEstPositionInitiale()) {
			if (((toY - obtenirPositionY()) <= 2) && (toX == obtenirPositionX()) 
				&& (toY > obtenirPositionY())) {
				return true;
			}
		}
		else
		{
			if ((toY - obtenirPositionY()) <= 1 && (toX == obtenirPositionX()) 
				&& toY > obtenirPositionY()) {
				return true;
			}
		}
	}
	if (obtenirCouleur() == "noir") {
		if (obtenirEstPositionInitiale()) {
			if (((toY - obtenirPositionY()) <= 2) && (toX == obtenirPositionX()) 
				&& (toY < obtenirPositionY())) {
				return true;
			}
		}
		else
		{
			if (((toY - obtenirPositionY()) <= 1) && (toX == obtenirPositionX()) 
				&& (toY < obtenirPositionY())) {
				return true;
			}
		}
	}
	
	return false;
	
}
/*********************************************
 *Fonctions:		estMouvementValide()
 *Descriptions:     Verifi si le deplacement est valide ou non
 *Parametre:		-(int)toX           : destination en x
 *                  -(int)toY           : destination en y
 *Retour:           -(bool)estValide    : retourne vrai si le mouvement est valide
 *********************************************/
bool Pion::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		
		modifierPositionX(toX);
		modifierPositionY(toY);
		estPositionInitiale_ = false;	
		return true;
	}
	return false;
}
