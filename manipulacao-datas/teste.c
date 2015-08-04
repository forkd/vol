#include "libdata.h"

main () {
   int diaSem1, dia1, mes1;
   unsigned long int ano1, ano2;
   char diaSem2, dia2, mes2;
   
   unsigned long int dias;
   
   printf( "Entre com o dia da semana1: " ); scanf( "%d", &diaSem1 );
   printf( "Entre com o dia1: " ); scanf( "%d", &dia1 );
   printf( "Entre com o mes1: " ); scanf( "%d", &mes1 );
   printf( "Entre com o ano1: " ); scanf( "%d", &ano1 );
   
   printf( "\nEntre com a quantidade de dias a ser somada: " ); scanf( "%d", &dias );
   
   calculaData( diaSem1, dia1, mes1, ano1, dias, &diaSem2, &dia2, &mes2, &ano2 );
   
   printf( "\n\nA data final eh: %d - %d/%d/%d.\n", diaSem2, dia2, mes2, ano2 );
}
