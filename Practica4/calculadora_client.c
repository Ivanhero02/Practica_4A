//Codigo de ejecucion del cliente encargado de hacer las llamadas de las funciones que realizan las operaciones almacenadas en el servidor
#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void
calculadora_prog_1(char *host)
{
	CLIENT *clnt;				//Variables
	float  *result_1;
	valores  suma_1_arg;
	float  *result_2;
	valores  resta_1_arg;
	float  *result_3;
	valores  multiplicacion_1_arg;
	float  *result_4;
	valores  division_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = suma_1(&suma_1_arg, clnt);			//Verificacion resultado
	if (result_1 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = resta_1(&resta_1_arg, clnt);
	if (result_2 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = multiplicacion_1(&multiplicacion_1_arg, clnt);
	if (result_3 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = division_1(&division_1_arg, clnt);
	if (result_4 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	CLIENT *clnt;
	int operacion;
	valores valores_operacion;
	float *resultado;

	// Verificar que se reciban los argumentos necesarios
	if (argc < 2) {
		printf ("Usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

	// Crear el cliente RPC
	clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	// Pedir al usuario la operación que desea realizar
	printf("Seleccione la operación que desea realizar:\n");
	printf("1. Suma\n");
	printf("2. Resta\n");
	printf("3. Multiplicación\n");
	printf("4. División\n");
	scanf("%d", &operacion);

	// Pedir al usuario los valores para la operación seleccionada
	printf("Ingrese el primer valor:\n");
	scanf("%d", &valores_operacion.i);
	printf("Ingrese el segundo valor:\n");
	scanf("%d", &valores_operacion.j);

	// Realizar la operación seleccionada utilizando el cliente RPC
	switch(operacion) {
		case 1:
			resultado = suma_1(&valores_operacion, clnt);
			break;
		case 2:
			resultado = resta_1(&valores_operacion, clnt);
			break;
		case 3:
			resultado = multiplicacion_1(&valores_operacion, clnt);
			break;
		case 4:
			resultado = division_1(&valores_operacion, clnt);
			break;
		default:
			printf("Operación inválida.\n");
			exit(1);
	}

	// Verificar si se obtuvo el resultado de la operación
	if (resultado == (float *) NULL) {
		clnt_perror (clnt, "call failed");
		exit(1);
	}

	// Imprimir el resultado de la operación
	printf("El resultado es: %.2f\n", *resultado);

	// Liberar la memoria utilizada por el cliente RPC
	clnt_destroy (clnt);

	exit (0);
}

