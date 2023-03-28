/* Archivo calculadora.x*/

struct valores{ 
   int i;
   int j;
};

program CALCULADORA_PROG{
   version CALCULADORA_VERS{
   float SUMA(valores) = 1;
   float RESTA(valores) = 2;
   float MULTIPLICACION(valores) = 3;
   float DIVISION(valores) = 4;
   } = 1;
} = 0x23451111;
