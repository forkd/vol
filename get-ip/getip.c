/*******************************************************************************
NAME
   getip (Get IP - Pega IP)

DESCRIPTION
   Este programa, retirado de http://beej.us/guide/bgnet/examples/getip.c,
recebe, como parametro, um endereco de internet, como www.kernel.org e retorna
o endereco IP referente a ele.
   O AUTOR NAO SE RESPONSABILIZA PELO USO QUE SERA DADO A ESTE PROGRAMA!

REQUIRES
   O dominio que se deseja avaliar.

DATE
   2006/10

LICENCE
   Este programa e um software de livre distribuicao, que pode ser copiado e
distribuido sob os termos da Licença Geral GNU, conforme publicada pela Free
Software Foundation, versao 2 da licença, ou (a criterio do autor) qualquer
versao posterior.
   Este programa e distribuido na expectativa de ser util aos seus usuarios,
porem NAO POSSUI NENHUMA GARANTIA, EXPLICITA OU IMPLICITA, COMERCIAL OU DE
ATENDIMENTO A UMA DETERMINADA FINALIDADE.
   Consulte a Licenca Publica Geral GNU.
*******************************************************************************/

/* Importando bibliotecas necessarias ao funcionamento do programa */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*******************************************************************************
NAME
   main

DESCRIPTION
   Funcao principal do programa.

REQUIRES
   argv[ 1 ] : O dominio a ser avaliado.

RETURNS
   O IP do dominio especificado.
*******************************************************************************/
int main( int argc, char *argv[] )
{
   struct hostent *h;
   
   /* Checando o parametro passado */
   if ( argc != 2 ) {
      fprintf( stderr, "Usage: ./getip [address]\n" );
      exit( 1 );
   }
   
   /* Pegando as informacoes do host */
   if ( ( h = gethostbyname( argv[ 1 ] ) ) == NULL ) {
      herror( "gethostbyname" );
      exit( 1 );
   }
   
   /* Imprimindo as informacoes obtidas */
   printf( "Host name  : %s\n", h -> h_name );
   printf( "IP Address : %s\n", inet_ntoa(
      *( (struct in_addr *) h -> h_addr ) ) );
   
   return 0;
} /* main */
