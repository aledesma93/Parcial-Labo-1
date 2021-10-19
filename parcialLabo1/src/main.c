/*
 ============================================================================
 Name        : PrimerParcialLabo.c
 Author      : ALEDESMA
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "harcodeo.h"
#include "pedido.h"
#include "cliente.h"
#define TAM_PEDIDO 1000
#define TAM_CLIENTE 100


int main(void)
{
	setbuf(stdout,NULL);

	char salir;
	salir = 'n';
	int idAutomatico;
	int idPedidos;
	int contadorClientes;
	float acumuladorPP;
	float promedioPP;

	acumuladorPP = 0;
	idPedidos = 1;
	idAutomatico = 1;
	contadorClientes = 10;


	eCliente listaClientes[TAM_CLIENTE];
	ePedido listaPedidos[TAM_PEDIDO];
	InicializarListaProductos(listaClientes,TAM_CLIENTE);
	InicializarListaPedido(listaPedidos,TAM_PEDIDO);
	hardcorearClientes(listaClientes,TAM_CLIENTE,10,&idAutomatico);


		do
		{
			switch(MenuPrincipal())
			{
				case 1:
					if(AltaCliente(listaClientes,TAM_CLIENTE,&idAutomatico))
					{
					  printf("Cliente agregado\n");
					  contadorClientes++;
					}
					else
					{
						printf("No se agrego el cliente \n");
					}
					break;
				case 2:
					if(ModificarCliente(listaClientes,TAM_CLIENTE))
					{
						printf("Cliente Modificado\n");
					}
					else
					{
						printf("No se modifico\n");
					}
					break;
				case 3:
					if(BajaCliente(listaClientes,TAM_CLIENTE))
					{
						printf("Cliente eliminado\n");
					}
					else
					{
						printf("No se elimino al cliente\n");
					}
					break;
				case 4:
					if(CrearPedidoRecoleccion (listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO,&idPedidos))
					{
						printf("Su pedido ha pasado a  estado pendiente\n");
					}
					else
					{
						printf("No se realizo el pedido\n");
					}
					break;
				case 5:
					MostrarListaPedidos(listaPedidos,TAM_PEDIDO);
					if(ProcesarPedido(listaPedidos,TAM_PEDIDO,&acumuladorPP))
					{
						printf("Su pedido ha pasado a completado\n");
					}
					else
					{
						printf("No se proceso el pedido\n");
					}
					break;
				case 6:
				if(MostrarListadoClientes(listaClientes,TAM_CLIENTE))
				{
					printf("Listado mostrado correctamente \n");
				}
				else
				{
					printf("Lista vacia\n");
				}
					break;
				case 7:
					if(ImprimirPendientes(listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO))
					{
						printf("Pedidos pendientes impresos \n");
					}
					else
					{
						printf("No se imprimio los pendientes\n");
					}
					break;
				case 8:
					if(ImprimirCompletados(listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO))
					{
						printf("Pedidos completados impresos \n");
					}
					else
					{
						printf("No se imprimieron los completados\n");
					}
					break;
				case 9:

					printf("en esa localidad hay %d pedidos pendientes \n",contadorPedidosLocalidad(listaClientes,TAM_CLIENTE) );


					break;
				case 10:
					promedioPP = acumuladorPP/contadorClientes;
					printf("Promedio %f", promedioPP);
					break;
				case 11:
					printf("Desea Salir s/n: \n");
					fflush(stdin);
					scanf("%c",&salir);
					break;
				default:
					printf("Error \n");
			}

		}while(salir != 's');





































	return EXIT_SUCCESS;



}
