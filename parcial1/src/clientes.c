/*
 * clientes.c
 *
 *  Created on: 2 may. 2021
 *      Author: ledes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utn.h"



int clientes_inicializar(clientes* list, int tamano)
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
void clientes_inicializarConDatos (clientes* list, int tamano)
{
    int i;

    int id[5] = {1,2,3,4,5};
    char nombre[5][50] = {"Agustin","Lautaro","Bruno","Cristian","Gonzalo"};
    char apellido[5][50] = {"Gomez","Coronel","Lopez","Diaz","Romero"};
    char cuit[5][15] = {"18001234561234","25001234567890","24001234567890","10001234567890","20001234567890"};


    for (i=0; i<5; i++)
    {
        list[i].id = id[i];
        strcpy (list[i].nombre, nombre[i]);
        strcpy (list[i].apellido, apellido[i]);
        strcpy (list[i].cuit, cuit[i]);
        list[i].flag = 1; // OCUPADO.
    }
}
int clientes_alta(clientes* list,int tamano)
{
    int retorno = -1;
    char auxiliarCuit;
    int i;
    char auxiliarNombre[50];
    int id;
    id = clientes_idAutoIncremental(list, tamano);
    i = clientes_buscarEspacio(list, tamano);

    if(i>=0)
    {
        printf("Ingrese el nombre:");
        fflush(stdin);
        gets(auxiliarNombre);
        strcpy(list[i].nombre, auxiliarNombre);

        printf("Ingrese el apellido:");
        fflush(stdin);
        gets(list[i].apellido);
        utn_getInt(&auxiliarCuit,"Ingrese el CUIT:\n" , "error", 0, 999, 3);
        list[i].cuit[i]=auxiliarCuit;


        list[i].flag=1;
        list[i].id=id;
        retorno=0;
    }
    printf("el alta se realizo correctamente\n"
    		"");
    return retorno;
}

int clientes_idAutoIncremental(clientes* list, int tamano)
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
int clientes_buscarEspacio (clientes* list, int tamano)
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

int clientes_baja(clientes* list,int tamano)
{
    int i;
    char auxiliarId[50];
    int scanId;

    int opcion;

    int flag = -1; // No se encontro ID

    clientes_mostrarDatos(list, tamano);


    printf("Ingrese la ID del cliente a remover: ");
    fflush(stdin);
    gets(auxiliarId);
    while(esNumerico(auxiliarId)==0)
    {
        printf("Usted ha ingresado un tipo de ID incorrecta. Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxiliarId);
    }
    scanId=atoi(auxiliarId);


    for(i=0; i<tamano; i++)
    {
        if(scanId==list[i].id)
        {
            printf("\nDesea dar de baja el cliente? Ingrese 1 para SI // Ingrese 2 para NO.\n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                list[i].flag = 0;
                list[i].id= 0;
                flag = 0; // Se modifico el cliente.
                break;

            case 2:
            	flag = -2; // Se cancelo la baja.
                break;

            default:
                printf("\n\nUsted ingreso una opcion invalida. Vuelva a intentarlo nuevamente.\n");
                flag = -2;
                break;
            }
        }
    }

    return flag;
}
int clientes_modificacion(clientes* list,int tamano)
{
    int id;
    int indice;


    int retorno=-2;

    char auxiliarId[20];

    if(tamano > 0 && list != NULL)
    {
        retorno=-1;

        clientes_mostrarDatos(list, tamano);

        printf("Ingrese la ID del cliente: ");
        fflush(stdin);
        gets(auxiliarId);
        while(esNumerico(auxiliarId)==0)
        {
            printf("Usted ha ingresado un tipo de ID incorrecta. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxiliarId);
        }
        id=atoi(auxiliarId);


        indice=clientes_encontrarPorId(list, tamano, id);



    }
    return retorno;
}
void clientes_mostrarDatos(clientes* list, int tamano)
{
    int i;
    printf("\n\nID -- \t NOMBRE \t APELLIDO \t CUIT \t COMPRAS \\n\n");
    for(i=0; i<tamano; i++)
    {
        if (list[i].flag == 1)
        {
            clientes_mostrarUno(list[i]);
        }

    }

}
void clientes_mostrarUno (clientes list)
{
    printf("%d -- %10s %15s %15s  \n\n", list.id, list.nombre, list.apellido, list.cuit);
}

int clientes_encontrarPorId(clientes* list, int tamano, int id)
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
