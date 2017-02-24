
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date:
* Auteur:
**************************************************/

#include "Piece.h"
#include "Roi.h"
#include "Tour.h"
#include "Pion.h"
//#include "Echiquier.h"

#include <string.h>
#include <iostream>

using namespace std;

int main()
{


	Piece p("A8", "blanc", 0, 0);



	//1-  Creez les huit pions blancs avec les coordonn�es (i,1) i : 0-->7 et les id A2-->H2
	
	//2-Creez les huit pions noirs avec les coordonn�es (i,6) i : 0-->7 et les id A7-->H7
	
	//3-  Creez les deux tours blanches d'id "A1" et "H1" dans les positions respectives (0,0) et (7,0)
	
	//4-  Creez les deux tours noires  d'id "A8" et "H8" dans les positions respectives (0,7) et (7,7)
	
	//5-  Creez les Fous blanc et noirs
	
	//6-  Creez les deux reines E1 et E8	

	//7-  Creez les deux rois D1 et D8
	
	// 8- Creez un echiquier 
	
	cout << "----------AJOUT DES PIECES----------" << endl;
	//9- Ajoutez toutes les pi�ces pr�cidament d�finies � l'echiquier	
	
	cout << "----------TEST DES DEPLACEMENTS------------" << endl;
	//10-  Deplacer la piece d'id A2 � la position (0,2)  --Deplacement de Pion
	
	//11-  Deplacer le piece d'id H7 � la position (7,4)  --Deplacement du Pion
	
	//12-  Deplacer la piece d'id A2 � la position (0,4)  --Deplacement du Pion
	
	//13-  Deplacer la piece d'id H8 � la position (7,6)  --Deplacement de la Tour
	
	//14-  Deplacer la piece d'id H8 � la position (7,6)  --Deplacement de la Tour
	
	//15-  Enlever la piece d'id A2 

	cout << "----------TEST DES PROMOTIONS------------" << endl;
	
	//16- Promouvoir la piece d'id F6.
	
	//17- Promouvoir la piece d'id B2.	

	//18- Affichage de l'Echiquier
	//cout << unEchiquier;
	//Si vous avez besoin de lancer avec un arret a la fin, faites ctrl+F5;

	return 0;
}

