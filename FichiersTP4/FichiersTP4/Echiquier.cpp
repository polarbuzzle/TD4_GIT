#include "Echiquier.h"
#include <time.h>

std::ostream & operator<<(std::ostream & out, const Echiquier & echiquier)
{
	out << "------------INFORMATION PIECES BLANCHES------------" << endl;
	out << "Il y a " << << " Pieces blanches" << endl;



	out << endl;
	out << "------------INFORMATION PIECES NOIRES--------------" << endl;
	out << "Il y a " << << " Pieces noires" << endl;

}
