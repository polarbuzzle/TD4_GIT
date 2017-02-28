/**************************************************
* Titre:	Travail pratique #4 - Main.cpp
* Date:		24 fevrier 2017
* Auteur:	FERRON, Samue. FONTAINE, Jean-Frederic.
**************************************************/

#include "Piece.h"
#include "Roi.h"
#include "Tour.h"
#include "Pion.h"
#include "Echiquier.h"
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	//1-  Creez les huit pions blancs avec les coordonn�es (i,1) i : 0-->7 et les id A2-->H2
	Pion pb1("A2", "blanc", 0, 1);
	Pion pb2("B2", "blanc", 1, 1);
	Pion pb3("C2", "blanc", 2, 1);
	Pion pb4("D2", "blanc", 3, 1);
	Pion pb5("E2", "blanc", 4, 1);
	Pion pb6("F2", "blanc", 5, 1);
	Pion pb7("G2", "blanc", 6, 1);
	Pion pb8("H2", "blanc", 7, 1);

	//2-Creez les huit pions noirs avec les coordonn�es (i,6) i : 0-->7 et les id A7-->H7
	Pion pn1("A7", "noir", 0, 6);
	Pion pn2("B7", "noir", 1, 6);
	Pion pn3("C7", "noir", 2, 6);
	Pion pn4("D7", "noir", 3, 6);
	Pion pn5("E7", "noir", 4, 6);
	Pion pn6("F7", "noir", 5, 6);
	Pion pn7("G7", "noir", 6, 6);
	Pion pn8("H7", "noir", 7, 6);

	//3-  Creez les deux tours blanches d'id "A1" et "H1" dans les positions respectives (0,0) et (7,0)
	Tour tb1("A1", "blanc", 0, 0);
	Tour tb2("H1", "blanc", 7, 0);

	//4-  Creez les deux tours noires  d'id "A8" et "H8" dans les positions respectives (0,7) et (7,7)
	Tour tn1("A8", "noir", 0, 7);
	Tour tn2("H8", "noir", 7, 7);

	//5-  Creez les Fous blanc et noirs
	Fou fb1("C1","blanc", 2, 0);
	Fou fb2("F1","blanc", 6, 0);
	Fou fn1("C8","noir", 1, 7);
	Fou fn2("F8","noir", 6, 7);

	//6-  Creez les deux reines E1 et E8	
	Reine rb("E1", "blanc", 4, 0);
	Reine rn("E8", "noir", 4, 7);

	//7-  Creez les deux rois D1 et D8
	Roi roib("D1", "blanc", 3, 0);
	Roi roin("D8", "noir", 3, 0);
	
	// 8- Creez un echiquier 
	Echiquier unEchiquier;	

	cout << "----------AJOUT DES PIECES----------" << endl;
	//9- Ajoutez toutes les pi�ces pr�cidament d�finies � l'echiquier	
	unEchiquier += &pb1;
	unEchiquier += &pb2;
	unEchiquier += &pb3;
	unEchiquier += &pb4;
	unEchiquier += &pb5;
	unEchiquier += &pb6;
	unEchiquier += &pb7;
	unEchiquier += &pb8;
	unEchiquier += &pn1;
	unEchiquier += &pn2;
	unEchiquier += &pn3;
	unEchiquier += &pn4;
	unEchiquier += &pn5;
	unEchiquier += &pn6;
	unEchiquier += &pn7;
	unEchiquier += &pn8;
	unEchiquier += &tb1;
	unEchiquier += &tb2;
	unEchiquier += &tn1;
	unEchiquier += &tn2;
	unEchiquier += &fb1;
	unEchiquier += &fb2;
	unEchiquier += &fn1;
	unEchiquier += &fn2;
	unEchiquier += &rb;
	unEchiquier += &rn;
	unEchiquier += &roib;
	unEchiquier += &roin;

	cout << "----------TEST DES DEPLACEMENTS------------" << endl;
	//10-  Deplacer la piece d'id A2 � la position (0,2)  --Deplacement de Pion
	unEchiquier.deplacerPiece("A2", 0, 2);
	//11-  Deplacer le piece d'id H7 � la position (7,4)  --Deplacement du Pion
	unEchiquier.deplacerPiece("H7", 7, 4);
	//12-  Deplacer la piece d'id A2 � la position (0,4)  --Deplacement du Pion
	unEchiquier.deplacerPiece("A2", 0, 4);
	//13-  Deplacer la piece d'id H8 � la position (7,6)  --Deplacement de la Tour
	unEchiquier.deplacerPiece("H8", 7, 6);
	//14-  Deplacer la piece d'id H8 � la position (7,6)  --Deplacement de la Tour
	unEchiquier.deplacerPiece("H8", 7, 6);
	//15-  Enlever la piece d'id A2 
	unEchiquier -= "A2";

	cout << "----------TEST DES PROMOTIONS------------" << endl;
	//16- Promouvoir la piece d'id F6.
	unEchiquier.promouvoir("F6");
	//17- Promouvoir la piece d'id B2.	
	unEchiquier.promouvoir("B2");
	//18- Affichage de l'Echiquier
	cout << unEchiquier << endl;
	//Si vous avez besoin de lancer avec un arret a la fin, faites ctrl+F5;

	/*QUESTIONS
	1- 	La classe pièce est une classe abstraite car nous ne devons pas créer cet objet.
		Cette classe sert seulement a encapsuler les differents attributs et méthodes
		communes au différents types de pièces. Dans le contexte du jeux d'échec, il est 
		insensé de créer une objet de type Piece car il est un concept et non un objet 
		physique.

	2-	Puisque nos objets sont tous dans un vecteur de type pièce, il est intéressant
		d'avoir un destructeur virtuel dans la classe mère (Piece). Par exempl, si nous
		avions une classe fille ayant des attributs supplémentaire, dont des pointeurs,
		il est important de détruire ces pointeurs, mais la classe mère ne fait pas
		nécessairement cest manupulations.

	3-	Nous aurions pu faire de l'héritage multiple avec les classes Fou et Tour pour
		implémenter la fonction estMouvementValide puisque la reine bouge de ces deux
		façon. Il est important maintenant que Four et Tour héritent virtuellement de 
		la classe Piece afin d'éviter le problème du diamant.
	*/
	return 0;
}

