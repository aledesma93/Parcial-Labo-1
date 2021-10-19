/*
 * pedido.h
 *
*  Created on: 14 oct. 2021
 *      Author: ALEDESMA
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

#define SINPEDIDO -1
#define PENDIENTE 0
#define COMPLETADO 1

typedef struct
{
	int idCliente;
	int idPedido;
	int CantidadHDPE;
	int CantidadLDPE;
	int CantidadPP;
	int TotalKilos;
	int acumuladorPP;
	int isEmpty;


}ePedido;

int InicializarListaPedido(ePedido listaPedidos[],int tam);
int CrearPedidoRecoleccion (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido,int* idPedidos);
void MostrarUnPedido(ePedido unPedido);
int MostrarListaPedidos(ePedido listaPedidos[],int tamPedidos);
int BuscarPedido(ePedido listaPedidos[],int tamPedido);
int ProcesarPedido(ePedido listaPedidos[],int tamPedido, float* acumuladorPP);


#endif /* PEDIDO_H_ */

