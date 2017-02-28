/**********************************************
* Titre: Travail pratique #4 - Echiquier.cpp
* Date: 24 fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Fichier header de la classe Echiquier
*********************************************/

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

//#include "Piece.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
#include "Fou.h"
#include "Reine.h"
#include "vector"

#include <string>


class Echiquier{



public:
	// Constructeur par defaut
	Echiquier();

	// Destructeur
	~Echiquier();

	//Deplace une piece si le mouvement est valide
	bool deplacerPiece(const string& id, int toX, int toY);
	
	//Fonction permettant de reconnaitre la piece a ajouter dans l'echiquier
	void reconnaiseurDeClasse(const Piece &p, const bool couleur);
	//Fonction permettant d'ajouter une piece dans l'echiquier
	Echiquier& operator+=(Piece* piece);
	//Donction permettant de retirer une piece de l'echiquier
	Echiquier& operator-=(const string& id);
	//permet de promouvoir un pion 
	bool promouvoir(const string& id);
	friend std::ostream& operator<<(std::ostream& out, const Echiquier& echiquier);
	
private :
	vector<Piece*>   vecteurPiecesBlanches_;
	vector<Piece*>   vecteurPiecesNoires_;	

};
#endif