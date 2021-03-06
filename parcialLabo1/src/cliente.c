/*
 * cliente.c
 *
*  Created on: 14 oct. 2021
 *      Author: ALEDESMA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "cliente.h"

int InicializarListaProductos(eCliente listaClientes[],int tam) //todos los espacios de la lista comienzan vacios
{
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		for(int i=0 ; i<tam; i++ )
		{
			listaClientes[i].isEmpty= LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}

int AltaCliente(eCliente listaClientes[],int tam,int* idAutomatico) // CARGO EL ARRAY CON LOS DATOS DE LA ESTRUCTURA
{
	int retorno;
	int auxId;
	auxId = *idAutomatico;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		for(int i=0 ; i<tam; i++ )
		{
			if(listaClientes[i].isEmpty == LIBRE )
			{
				listaClientes[i].id = auxId;
				myGets(listaClientes[i].NombreEmpresa,"Ingrese nombre de la empresa: \n",sizeof(listaClientes[i].NombreEmpresa));
				listaClientes[i].cuit = IngresarEntero("Ingrese nro de Cuit: \n");
				myGets(listaClientes[i].direccion,"Ingrese direccion de la empresa: \n",sizeof(listaClientes[i].direccion));
				myGets(listaClientes[i].localidad,"Ingrese localidad de la empresa: \n",sizeof(listaClientes[i].localidad));
				listaClientes[i].isEmpty = OCUPADO;

				auxId++;
				*idAutomatico = auxId;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

void MostrarUnCliente(eCliente unCliente)
{
  printf("%4d   %10s       %10d  %15s %15s  %15d \t\n",unCliente.id,unCliente.NombreEmpresa, unCliente.cuit,unCliente.direccion, unCliente.localidad,unCliente.contadorPedidos);
}


int MostrarListadoClientes(eCliente listaClientes[], int tamCliente)
{
    int retorno;
    retorno = 0;

    printf("ID CLIENTE   NOMBRE EMPRESA   CUIT      DIRECCION         LOCALIDAD     CANTIDAD EN ESTADO PENDIENTE \t \n");

    if(listaClientes != NULL && tamCliente > 0)
    {	for(int i=0; i<tamCliente ; i++)
    	{
    		if(listaClientes[i].isEmpty == OCUPADO)
    		{
    			MostrarUnCliente(listaClientes[i]);
    			retorno = 1;
    		}
    	}
    }
    return retorno;
}

int ModificarCliente(eCliente listaClientes[],int tam)//busco un producto por su id modifico direccion y localidad
{
	int idBuscado;
	int subMenu;
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		//MostrarListadoClientes(listaClientes,tam);
		idBuscado = IngresarEntero("Ingrese id del cliente \n");

		for(int i=0; i<tam; i++)//buscar dato
		{
			if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].id == idBuscado)
			{
				printf("1)Modificar direccion\n 2)Modificar localidad\n");
				subMenu =  IngresarEntero("Ingrese opcion\n");
				switch(subMenu)
				{
				   case 1:
					   myGets(listaClientes[i].direccion,"Ingrese direccion de la empresa: \n",sizeof(listaClientes[i].direccion));
				       break;
				   case 2:
					   myGets(listaClientes[i].localidad,"Ingrese localidad de la empresa: \n",sizeof(listaClientes[i].localidad));
				       break;
				   default:
					   printf("Opcion erronea\n");
					   break;
				 }
				 retorno = 1;
				 break;
			}
		}
	}
	return retorno;
}

int BajaCliente(eCliente listaClientes[],int tam) //Se ingresa el ID del cliente. Luego se preguntar? si se quiere confirmar la eliminaci?n.
{
	int idBuscado;
	int retorno;
	char respuesta;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		idBuscado = BuscarCliente(listaClientes,tam);
		if(idBuscado != -1)
		{
			MostrarUnCliente(listaClientes[idBuscado]);
			printf("Desea eliminar este cliente: s/n");
			fflush(stdin);
			scanf("%c",&respuesta);
			if(respuesta == 's')
			{
				listaClientes[idBuscado].isEmpty = LIBRE;
				retorno = 1;
			}
		}
	}
	return retorno;
}

int BuscarCliente(eCliente listaClientes[],int tam)
{
	int idBuscado;
	int indiceCliente;
	indiceCliente = -1;

	MostrarListadoClientes(listaClientes,tam);

	idBuscado = IngresarEntero("Ingrese id de cliente que desea buscar");
	for(int i=0; i<tam; i++)
	{
		if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].id == idBuscado)
		{
			indiceCliente = i;
			break;
		}
	}
	return indiceCliente;
}

