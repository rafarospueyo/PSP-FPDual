#include <stdio.h>
#include <string.h>
#include "persona.h"


int main(int argc, char const *argv[])
{
	
	persona p1;
	strcpy(p1.nombre,"Juan");
	strcpy(p1.apellido,"Lopez");


	p1.fecha_nac.anyo=1994;
	p1.fecha_nac.mes=11;
	p1.fecha_nac.dia=8;

	printf("Nombre: %s\nApellido: %s\nEdad: %d\n",p1.nombre, p1.apellido, obtener_edad(&p1) );
	return 0;
}