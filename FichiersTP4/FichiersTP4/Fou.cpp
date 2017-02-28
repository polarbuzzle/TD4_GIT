/**********************************************
* Titre: Travail pratique #1 - Fou.cpp
* Date: 24 fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Implementation de classe Fou
*********************************************/
#include <cmath>
#include "Fou.h"

/*********************************************
*Fonctions:		Fou()
*Descriptions:	Constructeur par defaut d'un Fou
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Fou::Fou(): Piece("defaultId", "blanc", 0, 0) {}

/*********************************************
*Fonctions:		Fou()
*Descriptions:	Constructeur par parametres Fou
*Parametre:		id : string de l'id
                couleur : string de la couleur de la piece 
                positionX : int de la position en x 
                positionY : int de la position en y
*Retour:		Aucun
*********************************************/
Fou::Fou(const string& id, const string& couleur, int positionX, int positionY) 
    : Piece( id,  couleur, positionX, positionY) {}

/*********************************************
*Fonctions:		Fou()
*Descriptions:	Constructeur par copie d'un Fou
*Parametre:		Pion : Pion
*Retour:		Aucun
*********************************************/
Fou::Fou(const Pion& pion) 
    : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()) {}

/*********************************************
*Fonctions:		Fou()
*Descriptions:	Destructeur Fou
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Fou::~Fou() {}

/*********************************************
*Fonctions:		estMouvementValide()
*Descriptions:	Verifi si le deplacement est valide ou non
*Parametre:		toX : destination en x
                toY : destination en y
*Retour:		estValide : retourne vrai si le mouvement est valide
*********************************************/
bool Fou::estMouvementValide(int toX, int toY) const {
    bool estValide = false;
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
bool Fou::deplacer(int toX, int toY)  {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);		
		return true;
	}
	return false;
}

/*********************************************
*Fonctions:		afficher()
*Descriptions:	affiche les informations du Fou
*Parametre:		stream : flux dans lequel on met les informations
*Retour:		stream : flux dans lequel on a mit les informations
*********************************************/
ostream&  Fou::afficher(ostream& stream) const {
		stream << "Fou " << obtenirCouleur() << " d'id " << obtenirId() << " : " << endl;
		stream << "Position (" << obtenirPositionX() << ", " << obtenirPositionY() << ")" << endl;
		return stream;
}