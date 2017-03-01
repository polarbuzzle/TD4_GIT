/**************************************************
* Titre:        Travail pratique #4 - Tour.cpp
* Date:         24 fevrier 2017
* Auteur:       FERRON, Samue. FONTAINE, Jean-Frederic.
*Description:   Implementation de la classe Tour
**************************************************/

#include "Tour.h"


/*********************************************
 *Fonctions:		Tour()
 *Descriptions:     Constructeur pas defaut
 *Parametre:		Aucun
 *Retour:           Aucun
 *********************************************/
Tour::Tour() :Piece("defaultId", "blanc", 0, 0){
}
/*********************************************
 *Fonctions:		Tour()
 *Descriptions:     Constructeur par parametre
 *Parametre:		-(string&)id    : Id de la piece.
 *                  -(string&)couleur: couleur de la piece.
 *                  -(int)positionX : Position en X.
 *                  -(int)positionY : Position en Y.
 *Retour:           Aucun
 *********************************************/
Tour::Tour(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY){
}
/*********************************************
 *Fonctions:		Tour()
 *Descriptions:     Constructeur pas copie
 *Parametre:		-(Pion&)pion    : Le pion a partir duquel
 *                  construire la tour .
 *Retour:           Aucun
 *********************************************/
Tour::Tour(const Pion & pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()){
}
/*********************************************
 *Fonctions:		~Tour()
 *Descriptions:     Destructeur
 *Parametre:		Aucun
 *Retour:           Aucun
 *********************************************/
Tour::~Tour(){
}
/*********************************************
 *Fonctions:		estMouvementValide()
 *Descriptions:     Verifie si le deplacement est 
 *                  un mouvement valide selon les regles
 *                  des echecs associe a cette piece.
 *Parametre:		-(int)toX   : nouvel position en X 
 *                  -(int)toY   :nouvel poisition en Y
 *Retour:           -(bool)     : vrai/faut mouvement valide
 *********************************************/
bool Tour::estMouvementValide(int toX, int toY) const{
	if (!Piece::estMouvementValide(toX, toY))
		return false;
	if ((obtenirPositionX() == toX)  || (obtenirPositionY() == toY))		
		return true;
	else
		return false;
}
/*********************************************
*Fonctions:         deplacer()
*Descriptions:      selon le retour de la fonction estMouvementValide()
*                   effectue le deplacement demande.
*Parametre:         -(int)toX    : Nouvel position en X
*                   -(int)toY    : Nouvel position en Y
*Retour:            -(bool)     : vrai ou faux selon si le deplacement a ete fait.
 *********************************************/
bool Tour::deplacer(int toX, int toY){
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		return true;
	}
	return false;
}
