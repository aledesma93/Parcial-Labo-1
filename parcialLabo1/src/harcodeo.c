/*
 * harcodeo.c
 *
*  Created on: 14 oct. 2021
 *      Author: ALEDESMA
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harcodeo.h"

#include "cliente.h"




int cuit[10] = {141,132,555,666,777,455,735,123,567};
int contadorPedidos [10] = {0,0,0,0,0,0,0,0,0,0};

char nombreEmpresa[10][14] =
{{"coto"},{"carrefour"},{"vea"},{"nike"},{"adidas"},{"jumbo"},{"easy"},{"dell"},{"hp"},{"bangho"},};

char direccion[10][18] =
{{"gabaston 55"},{"mendoza 44"},{"irigoyen 96"},{"madero 63"},{"jujuy 19"}, {"salta 220"},{"meeks 098"}, {"caseros 391"}, {"rosas 563"},{"belgrano 162"}};

char localidades[10][24] =
{ {"lanus"},{"lanus"},{"san isidro"},{"lomas"},{"lomas"},{"avellaneda"},{"avellaneda"},{"turdera"},{"turdera"},{"turdera"},};



int hardcorearClientes(eCliente lista[],int tam, int cantCargar, int* pIdC)
{
    int cantidad = 0;

    if(lista!= NULL && cantCargar > 0 && cantCargar <= tam && pIdC != NULL)
    {
        for(int i=0; i<cantCargar; i++)
        {
            lista[i].id = (*pIdC);
            strcpy(lista[i].NombreEmpresa, nombreEmpresa[i]);
            strcpy(lista[i].direccion, direccion[i]);
            strcpy(lista[i].localidad, localidades[i]);
            lista[i].cuit = cuit[i];
            lista[i].contadorPedidos = contadorPedidos[i];
            lista[i].isEmpty = OCUPADO;
            (*pIdC)++;
             cantidad++;
        }
    }
    return cantidad;
}



