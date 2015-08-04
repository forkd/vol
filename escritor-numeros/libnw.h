/* libnw ********************************************************************/
/*                                                                          */
/* DESCRICAO                                                                */
/*    Biblioteca do programa nw ( Numb Writer ) responsavel por implementar */
/* as funcoes de geracao das formas cardinal e ordinal do numero.           */
/*                                                                          */
/* INFORMACOES                                                              */
/*    AUTOR : Jose Lopes de Oliveira Junior                                 */
/*    SISTEMA OPERACIONAL : Slackware Linux 10.1 ( kernel 2.4.29 )          */
/*    COMPILADOR : GCC 3.3.4 ( GNU COMPILER C )                             */
/*    DATA : jul/2005                                                       */
/*    CONTATO : jlojunior@gmail.com                                         */
/*                                                                          */
/****************************************************************************/

/* Bibliotecas importadas */
#include <string.h>

/* zeroNovecentosNoventaNove ************************************************/
/* DESCRICAO                                                                */
/*    Cria a forma cardinal de um numero entre 0 ( zero ) e 999 ( novecen-  */
/* tos e noventa e nove ).                                                  */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > int numero : O numero.                                                */
/*  > char *car : O numero em cardinal.                                     */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna em *car o valor por extenso em cardinal de *num.              */
/****************************************************************************/
void zeroNovecentosNoventaNove ( int numero, char *car ) {
   /* Matrizes com os valores por extenso e em cardinal */
   char ZERODEZENOVE[][ 10 ] = {
      "zero","um","dois","três","quatro","cinco","seis","sete",
      "oito","nove","dez","onze","doze","treze","quatorze",
      "quinze","dezesseis","dezessete","dezoito","dezenove"
   };
   char VINTENOVENTA[][ 10 ] = {
      "vinte","trinta","quarenta","cinqüenta",
      "sessenta","setenta","oitenta","noventa"
   };
   char DUZENTOSNOVECENTOS[][ 13 ] = {
      "duzentos","trezentos","quatrocentos","quinhentos",
      "seiscentos","setecentos","oitocentos","novecentos"
   };
   
   /* Este laco eh repetido ate que a variavel */
   /* numero seja igual a zero.                */
   do {
      /* Numero entre 0 e 19 */
      if ( ( numero >= 0 ) && ( numero <= 19 ) ) {
         strcat( car, *( ZERODEZENOVE + numero ) );
         break;
      }

      /* Numero entre 20 e 99 */
      else if ( ( numero >= 20 ) && ( numero <= 99 ) ) {
         strcat( car, *( VINTENOVENTA + ( numero / 10 - 2 ) ) );
         numero %= 10;
	 
         /* Caso a escrita do numero nao tenha sido con-*/
	 /* cluida, deve-se adicionar um conectivo para */
	 /* continuar a concatenacao.                   */
	 if ( numero )
	    strcat( car, " e " );
      }

      /* Numero igual a 100 */
      else if ( numero == 100 ) {
         strcat( car, "cem" );
         numero %= 100;
      }

      /* Numero entre 101 e 199 */
      else if ( ( numero >= 101 ) && ( numero <= 199 ) ) {
         strcat( car, "cento e " );
         numero %= 100;
      }

      /* Numero entre 200 e 999 */
      else if ( ( numero >= 200 ) && ( numero <= 999 ) ) {
         strcat( car, *( DUZENTOSNOVECENTOS + ( numero / 100 -2 ) ) );
         numero %= 100;
	 
         /* Caso a escrita do numero nao tenha sido con-*/
	 /* cluida, deve-se adicionar um conectivo para */
	 /* continuar a concatenacao.                   */
	 if ( numero )
	    strcat( car, " e " );
      }
   } while( numero );
}

/* zeroNoningentesimoNonagesimoNono *****************************************/
/* DESCRICAO                                                                */
/*    Cria a forma ordinal de um numero entre 0 ( zero ) e 999 ( noningente-*/
/* simo nonagesimo nono ).                                                  */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > int numero : O numero.                                                */
/*  > char *ord : O numero em ordinal.                                      */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna em *ord o valor por extenso em ordinal de *num.               */
/****************************************************************************/
void zeroNoningentesimoNonagesimoNono ( int numero, char *ord ) {
   /* Matrizes com os valores por extenso e em ordinal */
   char ZERONONO[][ 9 ] = {
      "zero","primeiro","segundo","terceiro","quarto",
      "quinto","sexto","sétimo","oitavo","nono"
   };
   char DECIMONONAGESIMO[][ 14 ] = {
      "décimo","vigésimo","trigésimo","quadragésimo","qüinquagésimo",
      "sexagésimo","septuagésimo","octogésimo","nonagésimo"
   };
   char CENTESIMONONINGENTESIMO[][ 17 ] = { 
      "centésimo","ducentésimo","trecentésimo",
      "quadringentésimo","qüingentésimo","sexcentésimo",
      "septingentésimo","octingentésimo","noningentésimo"
   };
   
   do {
      /* Numero entre 0 e 19 */
      if ( ( numero >= 0 ) && ( numero <= 9 ) ) {
         strcat( ord, *( ZERONONO + numero ) );
	 break;
      }
      
      /* Numero entre 10 e 99 */
      else if ( ( numero >= 10 ) && ( numero <= 99 ) ) {
         strcat( ord, *( DECIMONONAGESIMO + ( numero / 10 - 1 ) ) );
	 numero %= 10;
	 
	 /* Caso a escrita do numero nao tenha sido */
	 /* concluida, deve-se adicionar um espaco  */
	 /* para continuar a concatenacao.          */
	 if ( numero )
	    strcat( ord, " " );
      }
      
      /* Numero entre 100 e 999 */
      else if ( ( numero >= 100 ) && ( numero <= 999 ) ) {
         strcat( ord, *( CENTESIMONONINGENTESIMO + ( numero / 100 - 1 ) ) );
	 numero %= 100;
	 
	 /* Caso a escrita do numero nao tenha sido */
	 /* concluida, deve-se adicionar um espaco  */
	 /* para continuar a concatenacao.          */
	 if ( numero )
	    strcat( ord, " " );
      }
   } while( numero );
}

/* geraCardinal *************************************************************/
/* DESCRICAO                                                                */
/*    Cria a forma cardinal de um numero entre 0 a 4 294 967 295.           */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > char *num : O numero.                                                 */
/*  > char *car : O numero em cardinal.                                     */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna 1 se a geracao pode ser realizada ou 0 em caso contrario. Re- */
/* torna em *car o valor por extenso em cardinal de *num.                   */
/****************************************************************************/
char geraCardinal ( char *num, char *car ) {
   /* Criando e inicializando a variavel que conterah */
   /* a conversao de String para numerico de *num.    */
   unsigned int numero = atol( num );
   
   do {
      /* Numero entre 0 e 999 */
      if ( ( numero >= 0 ) && ( numero <= 999 ) ) {
         zeroNovecentosNoventaNove( numero, car );
	 break;
      }
      
      /* Numero entre 1 000 e 1 999 */
      else if ( ( numero >= 1000 ) && ( numero <= 1999 ) ) {
         strcat( car, "mil" );
	 numero %= 1000;
	 
	 /* Adicionando o separador de grandezas dos milhares */
         if ( ( ( numero >= 1) && ( numero <= 99 ) ) || 
	    ( ( numero ) && ( ! ( numero % 100 ) ) ) )
            strcat( car, " e " );
         else if ( numero )
	    strcat( car, " " );
      }
      
      /* Numero entre 2 000 e 999 999 */
      else if ( ( numero >= 2000 ) && ( numero <= 999999 ) ) {
         zeroNovecentosNoventaNove( ( numero / 1000 ), car );
	 strcat( car, " mil" );
	 numero %= 1000;
	 
	 /* Adicionando o separador de grandezas dos milhares */
         if ( ( numero >= 101 ) && ( numero <= 999 ) && ( numero % 100 ) )
            strcat( car, " " );
         else if ( numero )
	    strcat( car, " e " );
      }
      
      /* Numero entre 1 000 000 e 1 999 999 */
      else if ( ( numero >= 1000000 ) && ( numero <= 1999999 ) ) {
         strcat( car, "um milhão" );
	 numero %= 1000000;
	 
	 /* Adicionando o separador de grandezas dos milhoes */
         if ( ( ( numero >= 1 ) && ( numero <= 99 ) ) || 
	    ( ( numero ) && ( ! ( numero % 1000 ) ) ) )
            strcat( car, " e " );
         else if ( ( numero >= 1000) && ( numero <= 100000 ) && 
	    ( ! ( numero % 1000 ) ) )
            strcat( car, " e " );
         else  if ( numero )
	    strcat( car, ", " );
      }
      
      /* Numero entre 2 000 000 e 999 999 999 */
      else if ( ( numero >= 2000000 ) && ( numero <= 999999999 ) ) {
         zeroNovecentosNoventaNove( ( numero / 1000000 ), car );
	 strcat( car, " milhões" );
	 numero %= 1000000;
	 
	 /* Adicionando o separador de grandezas dos milhoes */
         if ( ( ( numero >= 1 ) && ( numero <= 99 ) ) || 
	    ( ( numero ) && ( ! ( numero % 1000 ) ) ) )
            strcat( car, " e " );
         else if ( ( numero >= 1000) && ( numero <= 100000 ) && 
	    ( ! ( numero % 1000 ) ) )
            strcat( car, " e " );
         else  if ( numero )
	    strcat( car, ", " );
      }
      
      /* Numero entre 1 000 000 000 e 1 999 999 999 */
      else if ( ( numero >= 1000000000 ) && ( numero <= 1999999999 ) ) {
         strcat( car, "um bilhão" );
	 numero %= 1000000000;
	 
	 /* Adicionando o separador de grandezas dos bilhoes */
         if ( ( ( numero >= 1 ) && ( numero <= 99 ) ) || 
	    ( ( numero ) && ( ! ( numero % 1000 ) ) ) )
            strcat( car, " e " );
         else if ( ( numero >= 1000 ) && ( numero <= 100000 ) && 
	    ( ! ( numero % 1000 ) ) )
            strcat( car, " e " );
         else  if ( numero )
	    strcat( car, ", " );
      }
      
      /* Numero entre 2 000 000 000 e 999 999 999 999 ( 2 147 000 000 ) */
      else if ( ( numero >= 2000000000 ) && ( numero <= 2147000000 ) ) {
         zeroNovecentosNoventaNove( ( numero / 1000000000 ), car );
	 strcat( car, " bilhões" );
	 numero %= 1000000000;
	 
	 /* Adicionando o separador de grandezas dos bilhoes */
         if ( ( ( numero >= 1 ) && ( numero <= 99 ) ) || 
	    ( ( numero ) && ( ! ( numero % 1000 ) ) ) )
            strcat( car, " e " );
         else if ( ( numero >= 1000 ) && ( numero <= 100000 ) && 
	    ( ! ( numero % 1000 ) ) )
            strcat( car, " e " );
         else  if ( numero )
	    strcat( car, ", " );
      }
      
      /* Numero fora dos limites */
      else { 
         numero = 0;
	 return 0;
      }
   } while ( numero );
   
   return 1;
}

/* geraOrdinal **************************************************************/
/* DESCRICAO                                                                */
/*    Cria a forma ordinal de um numero entre 0 a 4 294 967 295.            */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > char *num : O numero.                                                 */
/*  > char *ord : O numero em ordinal.                                      */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna 1 se a geracao pode se realizada ou 0 em caso contrario. Re-  */
/* torna em *car o valor por extenso em ordinal de *num.                    */
/****************************************************************************/
char geraOrdinal ( char *num, char *ord ) {
   /* Criando e inicializando a variavel que conterah */
   /* a conversao de String para numerico de *num.    */
   unsigned int numero = atol( num );
   
   do {
      /* Numero entre 0 e 999 */
      if ( ( numero >= 0 ) && ( numero <= 999 ) ) {
         zeroNoningentesimoNonagesimoNono( numero, ord );
	 break;
      }
      
      /* Numero entre 1 000 e 1 999 */
      else if ( ( numero >= 1000 ) && ( numero <= 1999 ) ) {
         strcat( ord, "milésimo" );
	 numero %= 1000;
	 
	 /* Adicionando o separador de grandezas dos milhares */
	 if ( numero )
	    strcat( ord, " " );
      }
      
      /* Numero entre 2 000 e 999 999 */
      else if ( ( numero >= 2000 ) && ( numero <= 999999 ) ) {
         zeroNoningentesimoNonagesimoNono( ( numero / 1000 ), ord );
	 strcat( ord, " milésimo" );
	 numero %= 1000;
	 
	 /* Adicionando o separador de grandezas dos milhares */
	 if ( numero )
	    strcat( ord, " " );
      }
      
      /* Numero entre 1 000 000 e 1 999 999 */
      else if ( ( numero >= 1000000 ) && ( numero <= 1999999 ) ) {
         strcat( ord, "milionésimo" );
	 numero %= 1000000;
	 
	  /* Adicionando o separador de grandezas dos MILHOES */
          if ( ( numero ) && ( numero >= 1000) )
             strcat( ord, ", " );
          else if ( numero )
	     strcat( ord, " " );
      }
      
      /* Numero entre 2 000 000 e 999 999 999 */
      else if ( ( numero >= 2000000 ) && ( numero <= 999999999 ) ) {
         zeroNoningentesimoNonagesimoNono( ( numero / 1000000 ), ord );
	 strcat( ord, " milionésimo" );
	 numero %= 1000000;
	 
	 /* Adicionando o separador de grandezas dos MILHOES */
          if ( ( numero ) && ( numero >= 1000) )
             strcat( ord, ", " );
          else if ( numero )
	     strcat( ord, " " );
      }
      
      /* Numero entre 1 000 000 000 e 1 999 999 999 */
      else if ( ( numero >= 1000000000 ) && ( numero <= 1999999999 ) ) {
         strcat( ord, "bilionésimo" );
	 numero %= 1000000000;
	 
	 /* Adicionando o separador de grandezas dos bilhoes */
         if ( ( numero ) && ( numero >= 1000 ) )
            strcat( ord, ", " );
         else if ( numero )
	    strcat( ord, " " );
      }
      
      /* Numero entre 2 000 000 000 e 999 999 999 999 ( 2 147 000 000 ) */
      else if ( ( numero >= 2000000000 ) && ( numero <= 2147000000 ) ) {
         zeroNoningentesimoNonagesimoNono( ( numero / 1000000000 ), ord );
	 strcat( ord, " bilionésimo" );
	 numero %= 1000000000;
	 
	 /* Adicionando o separador de grandezas dos bilhoes */
         if ( ( numero ) && ( numero >= 1000 ) )
            strcat( ord, ", " );
         else if ( numero )
	    strcat( ord, " " );
      }
      
      /* Numero fora dos limites */
      else {
         numero = 0;
	 return 0;
      }
   } while ( numero );
   
   return 1;
}
