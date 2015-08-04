/* nw ***********************************************************************/
/*                                                                          */
/* DESCRICAO                                                                */
/*    O programa Numb Writer ( nw ) tem a funcao de gerar e escrever um nu- */
/* mero na tela por extenso nas formas cardinal e ordinal.                  */
/*                                                                          */
/* INFORMACOES                                                              */
/*    AUTOR : Jose Lopes de Oliveira Junior                                 */
/*    SISTEMA OPERACIONAL : Slackware Linux 10.1 ( kernel 2.4.29 )          */
/*    COMPILADOR : GCC 3.3.4 ( GNU COMPILER C )                             */
/*    DATA : jul/2005                                                       */
/*    CONTATO : jlojunior@gmail.com                                         */
/*                                                                          */
/* *  A biblioteca libnw acompanha este programa e eh fundamental para o    */
/* funcionamento deste.                                                     */
/*                                                                          */
/****************************************************************************/

/* Bibliotecas importadas */
#include <ctype.h>
#include <stdio.h>
#include "libnw.h"

/* isNumero *****************************************************************/
/* DESCRICAO                                                                */
/*    Verifica se uma String possui apenas caracteres numericos, ou seja,   */
/* se a String eh um numero valido.                                         */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > char *numero : A String  a ser avaliada.                              */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna 1 caso a String seja um numero valido ou 0 caso algum caracte-*/
/* re dessa String nao seja um digito.                                      */
/****************************************************************************/
char isNumero ( char *numero ) {
   register char i; /* Variavel de controle da iteracao */
   
   for ( i = 0; i <= strlen( numero ) - 1; i++ )
      if ( ! isdigit( *( numero + i ) ) )
         return 0;
   
   return 1;
}

/* main *********************************************************************/
/* DESCRICAO                                                                */
/*    Funcao principal do programa. Nela eh verificado o numero, que deve   */
/* ser passado como parametro, onde ele deve ser validado e processado para */
/* que se gere a saida desejada.                                            */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > int argc     : O contador de argumentos.                              */
/*  > char *argv[] : A matriz que armazena todos os argumentos.             */
/****************************************************************************/
main ( int argc, char *argv[] ) {
   /* Variaveis que armazenarao as formas por extenso do numero */   
   char numeroCardinal[ 250 ] = "\0", numeroOrdinal[ 250 ] = "\0";
   
   /* Verificando a quantidade de parametros passados */
   if ( argc < 2 ) {
      printf( "NW : Falta um parametro.\n" );
      printf( "\tDigite \"nw --ajuda\" para obter ajuda.\n" );
      exit( 1 );
   }
   
   if ( argc > 2 ) {
      printf( "NW : Excesso de parametros\n" );
      printf( "\tDigite \"nw --ajuda\" para obter ajuda.\n" );
      exit( 1 );
   }
   
   /* Numero de parametros OK - Verifica se o parametro */
   /* passado eh um parametro especial.                 */
   if ( ( ! strcmp( *( argv + 1 ), "--ajuda" ) ) || 
      ( ! strcmp( *( argv + 1 ), "-a" ) ) ) {
      printf( "Uso: nw NUMERO\n" );
      printf( "\tonde: 0 <= NUMERO <= 2147000000\n" );
      printf( "ou   nw [opcoes]\n" );
      printf( "Cria as formas cardinal e ordinal de um numero.\n" );
      printf( "opcoes:\n" );
      printf( "\t--ajuda, -a     Mostra esta ajuda e sai.\n" );
      printf( "\t--versao, -v    Mostra as notas da versao e sai.\n" );
      
      exit( 0 );
   }
   
   if ( ( ! strcmp( *( argv + 1 ), "--versao" ) ) || 
      ( ! strcmp( *( argv + 1 ), "-v" ) ) ) {
      printf( "\tNW ( Numb Writer ) 0.5\n" );
      printf( "Escrito por Jose Lopes de Oliveira Júnior. " );
      printf( "<jlojunior@gmail.com>\n\n" );
      printf( "Copyright (C) 2005.\n" );
      
      printf( "\tEste programa é um software de livre distribuição, que pode\n" ); 
      printf( "ser copiado e distribuído sob os termos da Licença Geral\n" );
      printf( "GNU, conforme publicada pela Free Software Foundation,\n" );
      printf( "versão 2 da licença, ou (a critério do autor) qualquer versão\n" );
      printf( "posterior.\n" );
      printf( "\tEste programa é distribuído na expectativa de ser útil aos\n" );
      printf( "seus usuários, porém NÃO POSSUI NENHUMA GARANTIA, EXPLÍCITA OU\n" );
      printf( "IMPLÍCITA, COMERCIAL OU DE ATENDIMENTO A UMA DETERMINADA\n" );
      printf( "FINALIDADE. Consulte a Licença Pública Geral GNU.\n" );
      
      exit( 0 );
   }
   
   /* Caso o parametro passado nao seja um parametro especial,  */
   /* este so pode ser o numero em questao. Aqui realiza-se a   */
   /* validacao do numero.                                      */
   if ( ! isNumero( *( argv + 1 ) ) ) {
      /* Numero invalido. */
      printf( "NW : O parametro nao eh um numero valido.\n" );
      printf( "\tDigite \"nw --ajuda\" para obter ajuda.\n" );
      exit( 1 );
   }
   
   /* Numero valido. Aqui se faz a geracao */
   /* das formas por extenso em cardinal e */
   /* ordinal do numero.                   */
   
   /* Verificando se o numero estah dentro dos limites. */
   if ( geraCardinal( *( argv + 1 ), numeroCardinal ) )
      geraOrdinal ( *( argv + 1 ), numeroOrdinal  );
   else {
      printf( "NW : Numero fora dos limites.\n" );
      printf( "\tDigite \"nw --ajuda\" para obter ajuda.\n" );
      
      exit( 1 );
   }
  
   /* Imprimindo as saidas geradas */
   printf( "NUMERO CARDINAL: %s.\n", numeroCardinal );
   printf( "NUMERO ORDINAL : %s.\n", numeroOrdinal  );
   
   /* Finalizando o programa. */
   exit( 0 );
}
