/*
 * ventas.h
 *
 *  Created on: 2 may. 2021
 *      Author: ledes
 */

#ifndef VENTAS_H_
#define VENTAS_H_
typedef struct
{
    int idCliente;
    int cantidadBarbijos;
    char direccion[64];
    char colorBarbijo[32];
    int idVenta;
    int id;
    int flag;
    float importe;
    char estadoVenta[];
} ventas;

/** \brief limpia el buffer o deja todo en limpio para luego cargar datos
 *
 * \param recibe arrays de ventas y su tamano
 * \return una variable de estad0=flag.
 */
int ventas_inicializar(ventas* list, int tamano);
/** \brief carga datos hard
 *
 * \param recibe arrays de clientes y su tamano
 * \return void.
 */
void ventas_inicializarConDatos (ventas* list, int tamano);
/** \brief se usa para que el usuario cargue datos de ventas
 *
 * \param recibe arrays de ventas y su tamano y la cantidad de ventas
 * \return retorno si esta todo ok, de lo contrario -1.
 */
int ventas_alta(ventas* list,int tamano,int* cantidadVentas);
/** \brief se usa para incrementar IDs en +1 cuadno se realiza una accion
 *
 * \param recibe arrays de ventas y su tamano
 * \return retorno +1.
 */
int ventas_idAutoIncremental(ventas* list, int tamano);
/** \brief busca espacios o indices vacios en donde alojar los nuevos datos ingresafdos
 *
 * \param recibe arrays de ventas y su tamano
 * \return inmdice.
 */
int ventas_buscarEspacio (ventas* list, int tamano);
/** \brief se usa para buscar por ID cada venta y asi obtener sus datos lueggo en otras funciones
 *
 * \param recibe arrays de ventas y su tamano
 * \return -1.
 */
int ventas_encontrarPorId(ventas* list, int tamano, int id);
/** \brief imprime un solo dato de un ID
 *
 * \param recibe arrays de ventas y su tamano
 * \return void.
 */
void ventas_mostrarUno (ventas list);

/** \brief mustra todos los datos solicitados
 *
 * \param recibe arrays de ventas y su tamano
 * \return retorno 0.
 */
int ventas_mostrarDatos(ventas* list, int tamano);




#endif /* VENTAS_H_ */
