/**********************************************
 * Titre:       Travail pratique #4 - Echiquier.cpp
 * Date:        24 fevrier 2017
 * Auteur:      FERRON Samuel, FONTAINE Jean-Frederic
 *Description:  Implementation de classe Reine
 *********************************************/

#include <cmath>
#include "Reine.h"

/*********************************************
*Fonctions:		Reine()
*Descriptions:	Constructeur par defaut d'une Reine
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Reine::Reine(): Piece("defaultId", "blanc", 0, 0) {}

/*********************************************
*Fonctions:		Reine()
*Descriptions:	Constructeur par parametres Reine
*Parametre:		-(string)id      : string de l'id
                -(string)couleur : string de la couleur de la piece
                -(int)positionX  : int de la position en x
                -(int)positionY  : int de la position en y
*Retour:		Aucun
*********************************************/
Reine::Reine(const string& id, const string& couleur, int positionX, int positionY) 
    : Piece( id,  couleur, positionX, positionY) {}

/*********************************************
*Fonctions:		Reine()
*Descriptions:	Constructeur par copie d'une Reine
*Parametre:		Pion : Pion
*Retour:		Aucun
*********************************************/
Reine::Reine(const Pion& pion) 
    : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()) {}

/*********************************************
*Fonctions:		Reine()
*Descriptions:	Destructeur Reine
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Reine::~Reine() {}

/*********************************************
*Fonctions:		estMouvementValide()
*Descriptions:	Verifi si le deplacement est valide ou non
*Parametre:		toX : destination en x
                toY : destination en y
*Retour:		estValide : retourne vrai si le mouvement est valide
*********************************************/
bool Reine::estMouvementValide(int toX, int toY) const{
    bool estValide = false;
	if (Piece::estMouvementValide(toX, toY)) {
		if ((obtenirPositionX() == toX)  || (obtenirPositionY() == toY))		
		estValide = true;
	}
	if (Piece::estMouvementValide(toX, toY)) {
        int diffX = abs(toX - obtenirPositionX());
        int diffY = abs(toY - obtenirPositionY());
        if (diffX == diffY) {
            estValide = true;
        }
    }
    return estValide;
}

/*********************************************
*Fonctions:		deplacer()
*Descriptions:	fait une tentative de deplacement
*Parametre:		toX : destination en x
                toY : destination en y
*Retour:		estValide : retourne vrai si le mouvement est fait
*********************************************/
bool Reine::deplacer(int toX, int toY)  {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);		
		return true;
	}
	return false;
}

/*********************************************
*Fonctions:		afficher()
*Descriptions:	affiche les informations de la Reine
*Parametre:		stream : flux dans lequel on met les informations
*Retour:		stream : flux dans lequel on a mit les informations
*********************************************/
ostream&  Reine::afficher(ostream& stream) const {  // A MODIFIER SI NECESSAIRE
		stream << "Reine " << obtenirCouleur() << " d'id " << obtenirCouleur() << " : " << endl;
		stream << "Position (" << obtenirPositionX() << ", " << obtenirPositionY() << ")" << endl;
		return stream;
}
