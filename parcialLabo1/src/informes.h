/*
 * informes.h
 *
 *  Created on: 19 oct. 2021
 *      Author: ledes
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "pedido.h"


int ImprimirPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido);
int ImprimirCompletados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido);
int contadorPedidosLocalidad(eCliente listaClientes[],int tam);


#endif /* INFORMES_H_ */
