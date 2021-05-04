/*
 * informes.c
 *
 *  Created on: 4 may. 2021
 *      Author: ledes
 */

#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "ventas.h"

#include "utn.h"
int suma_ventas(clientes list[], int tamano,int idCliente){

	int indiceIncremental;
	indiceIncremental=clientes_encontrarPorId(list,tamano,idCliente);
	list[indiceIncremental].cantidadVentas++;

	return 0;

}
