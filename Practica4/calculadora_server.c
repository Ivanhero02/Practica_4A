//Programa servidor encargado de realizar las operaciones de acuerdo con lo solicitado por el cliente y devolver un resultado.
#include "calculadora.h"

float *suma_1_svc(valores *argp, struct svc_req *rqstp) {	//función que realiza cuando se solicita suma
	static float  result;
	result = (float)argp->i + (float)argp->j;
	return &result;
}

float *resta_1_svc(valores *argp, struct svc_req *rqstp) {      //función que realiza cuando se solicita resta
	static float  result;
	result = (float)argp->i - (float)argp->j;
	return &result;
}

float *
multiplicacion_1_svc(valores *argp, struct svc_req *rqstp)	//función que realiza cuando se solicita multitplicacion
{
	static float  result;
	result = (float)argp->i * (float)argp->j;
	return &result;
}

float *division_1_svc(valores *argp, struct svc_req *rqstp) {	//función que realiza cuando se solicita division
	static float  result;
	if (argp->j != 0) {
           result = (float)argp->i / (float)argp->j;
    	} else {
           printf("Error: Division by zero\n");
    	}
	return &result;
}
