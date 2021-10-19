/*
 * pedido.c
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
#include "pedido.h"

int InicializarListaPedido(ePedido listaPedidos[],int tam) //todos los espacios de la lista comienzan pendiente
{
	int retorno;
	retorno = 0;

	if(listaPedidos != NULL && tam > 0)
	{
		for(int i=0 ; i<tam; i++ )
		{
			listaPedidos[i].isEmpty= SINPEDIDO;
			retorno = 1;
		}
	}
	return retorno;
}

int CrearPedidoRecoleccion (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido,int* idPedidos)
{
	int indiceCliente;
	int retorno;
	int auxId;
	int auxCantPedidos;
	auxId = *idPedidos;
	retorno = 0;


	if(listaClientes != NULL && tamCliente > 0 && listaPedidos != NULL && tamPedido>0)
	{

		indiceCliente = BuscarCliente(listaClientes,tamCliente);

		if(indiceCliente != -1) //ya estoy trabajando en ese cliente porq trabajo en ese indice
		{
			for(int i = 0; i< tamPedido; i++)
			{
				if(listaPedidos[i].isEmpty == SINPEDIDO)
				{
					listaPedidos[i].idPedido = auxId;
					listaPedidos[i].TotalKilos = IngresarEntero("Ingrese cantiad de kilos totales:  \n");
					listaPedidos[i].isEmpty = PENDIENTE;
					auxCantPedidos = listaClientes[indiceCliente].contadorPedidos;
					auxCantPedidos++;
					listaClientes[indiceCliente].contadorPedidos = auxCantPedidos;
					listaPedidos[i].idCliente = listaClientes[indiceCliente].id;
					auxId++;
					*idPedidos = auxId;
					retorno = 1;
					break;
				}
			}
		}

	}
	return retorno;
}

void MostrarUnPedido(ePedido unPedido)
{
	printf("%4d  %10d \t\n",unPedido.idPedido,unPedido.TotalKilos);
}

int MostrarListaPedidos(ePedido listaPedidos[],int tamPedidos)
{
	int retorno;
	retorno = 0;
	if(listaPedidos != NULL && tamPedidos >0)
	{
		for(int i=0 ; i< tamPedidos; i++)
		{
			MostrarUnPedido(listaPedidos[i]);
			retorno = 1;
		}
	}
	return retorno;
}

int ProcesarPedido(ePedido listaPedidos[],int tamPedido,float* acumuladorPP) //punto5
{
	int iPedido;
	int retorno;
	int auxAcumuladorPP;
	auxAcumuladorPP = *acumuladorPP;


	retorno = 0;
	iPedido = BuscarPedido(listaPedidos,tamPedido);

	if(listaPedidos != NULL && tamPedido >0 && iPedido!= -1)
	{
		for(int i = 0; i<tamPedido; i++)
		{
			if(listaPedidos[i].isEmpty == PENDIENTE)
			{
				listaPedidos[iPedido].isEmpty = COMPLETADO;
				listaPedidos[iPedido].CantidadPP = listaPedidos[iPedido].TotalKilos /3;
				listaPedidos[iPedido].CantidadLDPE = listaPedidos[iPedido].TotalKilos /3;
				listaPedidos[iPedido].CantidadHDPE = listaPedidos[iPedido].TotalKilos /3;
				listaPedidos[iPedido].acumuladorPP = listaPedidos[iPedido].CantidadPP;
				auxAcumuladorPP = listaPedidos[iPedido].acumuladorPP + auxAcumuladorPP;
				*acumuladorPP = auxAcumuladorPP;

				retorno = 1;
				break;
			}

		}
	}
	return retorno;
}


int BuscarPedido(ePedido listaPedidos[],int tamPedido)
{
	int idBuscado;
	int indicePedido;
	indicePedido = -1;

	idBuscado = IngresarEntero("Ingrese id del pedido que desea buscar");
	for(int i=0; i<tamPedido; i++)
	{
		if(listaPedidos[i].isEmpty == PENDIENTE && listaPedidos[i].idPedido == idBuscado)
		{
			indicePedido = i;
			break;

		}
	}
	return indicePedido;
}



int ImprimirPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
	int retorno;
	retorno = 0;
	if(listaClientes != NULL && tamCliente >0 && listaPedidos != NULL && tamPedido >0)
	{
		printf("DATOS PEDIDOS PENDIENTES\n");
		printf("CUIT           DIRECCION     kILOS A RECOLECTAR  \n");
		for(int i= 0; i<tamCliente; i++) //recorro lista clientes
		{
			for(int j=0; j<tamPedido;j++) // recorro pedidos
			{
				if(listaPedidos[j].isEmpty == PENDIENTE && listaClientes[i].id == listaPedidos[j].idCliente)
				{
					printf("%15d  %15s  %15d \n",listaClientes[i].cuit,listaClientes[i].direccion,listaPedidos[j].TotalKilos);

					retorno = 1;
				}
			}
		}
	}
	return retorno;
}


int ImprimirCompletados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
	int retorno;
	retorno = 0;
		if(listaClientes != NULL && tamCliente >0 && listaPedidos != NULL && tamPedido >0)
		{
			printf("DATOS PEDIDOS COMPLETADOS\n");
			printf("CUIT           DIRECCION      CANTIDAD KG HDPE   CANTIDAD KG LDPE    CANTIDAD KG PP    \n");
			for(int i= 0; i<tamCliente; i++) //recorro lista clientes
			{
				for(int j=0; j<tamPedido;j++) // recorro pedidos
				{
					if(listaPedidos[j].isEmpty == COMPLETADO && listaClientes[i].id == listaPedidos[j].idCliente)
					{
						printf("%15d  %15s  %15d  %15d  %15d \n",listaClientes[i].cuit,listaClientes[i].direccion,listaPedidos[j].CantidadHDPE,listaPedidos[j].CantidadLDPE,listaPedidos[j].CantidadPP);
						retorno = 1;
					}
				}
			}
		}
	return retorno;
}

int contadorPedidosLocalidad(eCliente listaClientes[],int tam)
{

	int i;
	i= 0;
	int contador=0;
	MostrarListadoClientes(listaClientes,tam);
	int retornoMygets;
	char localidadEncontrada[50];
	retornoMygets =utn_getString2("ingrese localidad:\n","error",localidadEncontrada,60,3);
	if(retornoMygets!= -1){
		for(i=0; i<tam; i++)
		{
			if((listaClientes[i].isEmpty >0) && (strncmp(listaClientes[i].localidad,localidadEncontrada,50)==0 ))
			{
				printf("clientes %s", listaClientes[i].localidad);

				contador=contador+listaClientes[i].contadorPedidos;
			}

		}
	}
	else{
		printf("no hay clientes con la localidad ingresada \n");
	}

	return contador;

}

