/*
 * informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: ledes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "cliente.h"
#include "informes.h"
#include "pedido.h"


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
