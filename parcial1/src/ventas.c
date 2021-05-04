/*
 * ventas.c
 *
 *  Created on: 2 may. 2021
 *      Author: ledes
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ventas.h"
#include "utn.h"


int ventas_inicializar(ventas* list, int tamano)
{
    int flag;
    int i;
    if (list != NULL)
    {
        for (i=0; i<tamano; i++)
        {
            list[i].flag = 0;
        }

        flag = 0;
    }
    else
    {
    	flag = -1;
    }

    return flag;
}
void ventas_inicializarConDatos (ventas* list, int tamano)
{
    int i;

    int id[5] = {1,2,3,4,5};
    int cantidadBarbijos[5] = {1,2,3,4,5};
    char direccion[5][50] = {"mendoza","buenos aires","cordoba","salta","jujuy"};
    char colorBarbijo[5][50] = {"blanco","negro","rojo","azul","verde"};


    for (i=0; i<5; i++)
    {
        list[i].id = id[i];
        list[i].cantidadBarbijos = cantidadBarbijos[i];
        strcpy (list[i].direccion, direccion[i]);
        strcpy (list[i].colorBarbijo, colorBarbijo[i]);
        list[i].flag = 1; // OCUPADO.
    }
}
int ventas_alta(ventas* list,int tamano,int* cantidadVentas)
{
    int retorno = -1;
    char estado[20];
    int i;
    int auxiliarIdCliente;
    char auxiliarDireccion[50];
    char auxiliarColorBarbijo[50];
    int auxiliarCantidadBarbijos;
    int id;
    id = ventas_idAutoIncremental(list, tamano);
    i = ventas_buscarEspacio(list, tamano);

    if(i>=0)
    {
    	strcpy(estado,"pendiente");
    	strcpy(list[i].estadoVenta,estado);
    	printf("antes de pedir ID\n");
    	utn_getInt(&auxiliarIdCliente,"Ingrese el ID del cliente:\n" , "error", 0, 999, 3);
    	printf(" es el id %d \n",auxiliarIdCliente);
    	list[i].idCliente=auxiliarIdCliente;


        printf("Ingrese la direccion:\n");
        fflush(stdin);
        gets(auxiliarDireccion);
        strcpy(list[i].direccion, auxiliarDireccion);


        utn_getInt(&auxiliarCantidadBarbijos,"Ingrese la cantidad:\n" , "error", 0, 999, 3);
        list[i].cantidadBarbijos=auxiliarCantidadBarbijos;


        printf("Ingrese el color:\n");
        fflush(stdin);
        gets(list[i].colorBarbijo);
        strcpy(list[i].colorBarbijo, auxiliarColorBarbijo);

        list[i].flag=1;
        list[i].id=id;

        retorno=0;


    }
    printf("la compra se realizo correctamente\n"
    		"");
    return retorno;
}

int ventas_idAutoIncremental(ventas* list, int tamano)
{
    int retorno = 0;
    int i;
    if(tamano > 0 && list != NULL)
    {
        for(i=0; i<tamano; i++)
        {
            if(list[i].flag == 1)
            {
                if(list[i].id > retorno)
                {
                    retorno = list[i].id;
                }
            }
        }
    }
    return retorno+1;
}
int ventas_buscarEspacio (ventas* list, int tamano)
{
    int indice = -1;
    int i;

    for (i=0; i<tamano; i++)
    {
        if (list[i].flag == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int ventas_mostrarDatos(ventas* list, int tamano)
{
    int i;
    printf("\n\nID -- \t Direccion \t Cantidad \t Color de Barbijos \\n\n");
    for(i=0; i<tamano; i++)
    {
        if (list[i].flag == 1)
        {
        	ventas_mostrarUno(list[i]);
        }

    }
    return 0;
}
void ventas_mostrarUno (ventas list)
{
    printf("%d -- %10s %10d %15s \n\n", list.id, list.direccion, list.cantidadBarbijos, list.colorBarbijo);
}

int ventas_encontrarPorId(ventas* list, int tamano, int id)
{
    for(int i=0; i<tamano; i++)
    {
        if(list[i].flag==1 && list[i].id==id)
        {
            return i;
        }
    }


    return -1;
}


