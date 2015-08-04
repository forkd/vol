/* dip.c ********************************************************************/
/*                                                                          */
/* DESCRICAO                                                                */
/*    Este programa recebe como entrada um numero IP, bem como sua mascara, */
/* faz a validacao dos parametros passados e imprime na tela informacoes    */
/* detalhadas sobre o numero para o usuario.                                */
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
#include <stdio.h>
#include "libdip.h"
#include "libverip.h"

/* geraMascaraNumIP *********************************************************/
/* DESCRICAO                                                                */
/*    Funcao responsavel por gerar a mascara do numero IP passado em forma- */
/* to decimal e bianrio.                                                    */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *param : O parametro passado ao programa.                  */
/*  > const char format : O formato em que o parametro foi passado ( vide   */
/*     retorno de verSinNumIP() ).                                          */
/*  > char *maskDec : A mascara que serah devolvida em formato decimal.     */
/*  > char *maskBin : A mascara que serah devolvida em formato binario.     */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna 0 em caso de erro ou 1, em caso de sucesso. Retorna em *mask  */
/* a mascara do numero IP passado ao programa.                              */
/****************************************************************************/
char geraMascaraNumIP ( const char *param, const char format, char *maskDec,
   char *maskBin ) {
   
   register char i = 0, /* Variavel de controle de iteracao */
      aux; /* Variavel auxiliar pra conversao de String pra numerico */
   
   /* Limpando as variaveis mask */
   *( maskBin + 0 ) =  '\0' ;
   *( maskDec + 0 ) =  '\0' ;
   
   switch ( format ) {
      case 2:
         /* Avancando pelo parametro ateh atingir a mascara */
         while ( *( param + i ) != '/' ) ++i;
	 ++i;
	 
	 /* Concatenando cada caractere da mascara do parametro */
	 /* em maskBin.                                         */
	 for ( ; i < strlen( param ); i++ )
	    sprintf( maskBin, "%s" "%c", maskBin, *( param + i ) );
	 
	 /* Convertendo a mascara pra numerico */
	 aux = atoi( maskBin );
	 
	 *( maskBin + 0 ) =  '\0' ; /* Limpando a variavel mask */
	 
	 /* Gerando a mascara em binario */
	 for ( i = 1; i <= aux; i++ ) /* Inserindo os '1's */
	    strcat( maskBin, "1" );
	 for ( ; i <= 32; i++ ) /* Completando com '0's */
	    strcat( maskBin, "0" );
	 
	 /* Gerando a mascara em decimal */
	 convNumIP( maskDec, maskBin, 1 );
	 
	 return 1;
	    
         break;
      
      case 3:
         /* Avancando pelo parametro ateh atingir a mascara */
         while ( *( param + i ) != '/' ) ++i;
	 ++i;
	 
	 /* Concatenando cada caractere da mascara do parametro */
	 /* em mask para gerar a mascara em decimal.            */
	 for ( ; i < strlen( param ); i++ )
	    sprintf( maskDec, "%s" "%c", maskDec, *( param + i ) );
	 
	 /* Gerando a mascara em binario */
	 convNumIP( maskDec, maskBin, 0 );
	 
	 return 1;
	 
         break;
      
      default:
         return 0;
         break;
   } /* switch */
}

/* geraEndIPHost ************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retira do parametro passado ao programa o numero IP isola- */
/* damente.                                                                 */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *param : O parametro passado ao programa.                  */
/*  > char *nIPDec : O numero IP a ser devolvido no formato decimal.        */
/*  > char *nIPBin : O numero IP a ser devolvido no formato binario.        */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna em *nIPDec e *nIPBin o endereco IP do host nos formatos deci- */
/* mal e binario respectivamente.                                           */
/****************************************************************************/
void geraEndIPHost ( const char *param, char *nIPDec, char *nIPBin ) {
    register char i = 0; /* Variavel de controle da iteracao */
    
    /* Limpando as variaveis de retorno */
    *( nIPDec + 0 ) = '\0';
    *( nIPBin + 0 ) = '\0';
    
    /* Este laco se repetirah ateh que se encontre a '/', */
    /* que marca o fim do numero IP no parametro.         */
    while ( *( param + i ) != '/' ) {
       /* Concatenando caractere por caractere do parametro em numIP */
       sprintf( nIPDec, "%s" "%c", nIPDec, *( param + i ) );
       
       ++i; /* Incrementando a variavel de controle */
    }
    
    /* Convertendo o endereco encontrado de decimal pra binario */
    convNumIP( nIPDec, nIPBin, 0 );
}

/* geraEndIPSR **************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que gera o endereco IP da sub rede.                            */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *nIPBin : O numero IP em binario.                          */
/*  > const char *maskBin : A mascara do numero IP em binario.              */
/*  > char *nIPSRDec : O endereco IP da sub rede em decimal.                */
/*  > char *nIPSRBin : O endereco IP da sub rede em binario.                */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna em *nIPSRDec e *nIPSRBin o endereco IP da sub rede em binario */
/* e decimal.                                                               */
/****************************************************************************/
void geraEndIPSR ( const char *nIPBin, const char *maskBin,
   char *nIPSRDec, char *nIPSRBin ) {
   
   /* Variavel de controle da iteracao */
   register char i = 0;
   
   /* Limpando as variaveis de saida */
   *( nIPSRDec + 0 ) = '\0';
   *( nIPSRBin + 0 ) = '\0';
   
   /* Gerando o numero IP da sub rede */
   while ( *( maskBin + i ) == '1' ) {
      sprintf( nIPSRBin, "%s" "%c", nIPSRBin, *( nIPBin + i ) );
      ++i;
   }
   while ( strlen( nIPSRBin ) < 32 )
      strcat( nIPSRBin, "0" );
   
   /* Convertendo o numero IP da sub rede de binario pra decimal */
   convNumIP( nIPSRDec, nIPSRBin, 1 );
}

/* geraEndIPRede ************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que gera o endereco IP da rede.                                */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *nIPBin : O numero IP em binario.                          */
/*  > const char cIP : A classe a que o endereco IP pertence.               */
/*  > char *nIPRedeDec : O endereco IP da sub rede em decimal.              */
/*  > char *nIPRedeBin : O endereco IP da sub rede em binario.              */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna em *nIPRedeDec e *nIPRedeBin o endereco IP da sub rede em bi- */
/* nario e decimal.                                                         */
/****************************************************************************/
void geraEndIPRede ( const char *nIPBin, const char cIP,
   char *nIPRedeDec, char *nIPRedeBin ) {
   
   /* Limpando as variaveis de saida */
   *( nIPRedeDec + 0 ) = '\0';
   *( nIPRedeBin + 0 ) = '\0';
   
   switch ( cIP ) {
      case 'A':
         /* Gerando o numero IP da rede */
	 strncpy( nIPRedeBin, nIPBin, 8 );
	 *( nIPRedeBin + 8 ) = '\0';
	 strcat( nIPRedeBin, "000000000000000000000000" );
	 
	 /* Convertendo o endereco gerado pra decimal */
	 convNumIP( nIPRedeDec,nIPRedeBin, 1 );
	 
         break;
      
      case 'B':
         /* Gerando o numero IP da rede */
	 strncpy( nIPRedeBin, nIPBin, 16 );
	 *( nIPRedeBin + 16 ) = '\0';
	 strcat( nIPRedeBin, "0000000000000000" );
	 
	 /* Convertendo o endereco gerado pra decimal */
	 convNumIP( nIPRedeDec,nIPRedeBin, 1 );
	 
         break;
      
      case 'C':
         /* Gerando o numero IP da rede */
	 strncpy( nIPRedeBin, nIPBin, 24 );
	 *( nIPRedeBin + 24 ) = '\0';
	 strcat( nIPRedeBin, "00000000" );
	 
	 /* Convertendo o endereco gerado pra decimal */
	 convNumIP( nIPRedeDec,nIPRedeBin, 1 );
	 
         break;
      
      default: /* Classe invalida */
         break;
   } /* switch */
}

/* geraNumRelHost ***********************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retorna o numero relativo de host de um numero IP.         */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *nIPBin : O numero IP em binario.                          */
/*  > const char *maskBin : A mascara do numero IP em binario.              */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna o numero relativo do host.                                    */
/****************************************************************************/
unsigned long int geraNumRelHost ( const char *nIPBin, const char *maskBin ) {
   register char i = 0; /* Variavel de controle da iteracao */
   
   /* Variavel que armazenarah o numero relativo */
   /* do host em binario. E variavel que armaze- */
   /* narah o numero de retorno como String.     */
   char auxBin[ 32 ] = "\0",
      auxDec[ 10 ] = "\0";
   
   while ( *( maskBin + i ) == '1' ) ++i;
   
   while ( i < 32 ) {
      sprintf( auxBin, "%s" "%c", auxBin, *( nIPBin + i ) );
      ++i;
   }
   
   paraDec( auxBin, auxDec, 2 );
   
   return atol( auxDec );
}

/* geraNumRelSR *************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retorna o numero relativo da sub rede de um numero IP.     */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *nIPBin : O numero IP em binario.                          */
/*  > const char *maskBin : A mascara do numero em binario.                 */
/*  > const char cIP : A classe a que o numero pertence.                    */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna o numero relativo da sub rede.                                */
/****************************************************************************/
unsigned long int geraNumRelSR ( const char *nIPBin, const char *maskBin, 
   const char cIP ) {
   
   register char i; /* Variavel de controle da iteracao */
   
   /* Variavel que armazenarah o numero relativo */
   /* do host em binario. E variavel que armaze- */
   /* narah o numero de retorno como String.     */
   char auxBin[ 32 ] = "\0",
      auxDec[ 10 ] = "\0";
   
   /* Verificando a classe pra saber onde comecarah */
   /* a concatenacao do numero relativo de sub rede.*/
   switch ( cIP ) {
      case 'A':
         i = 8;
      break;
      
      case 'B':
         i = 16;
         break;
      
      case 'C':
         i = 24;
         break;
      
      default: /* Classe invalida */
         return 0;
         break;
   } /* switch */
   
   while ( *( maskBin + i ) == '1' ) {
      sprintf( auxBin, "%s" "%c", auxBin, *( nIPBin + i ) );
      ++i;
   }
   
   paraDec( auxBin, auxDec, 2 );
   
   return atol( auxDec );
}

/* geraNumRelRede ***********************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retorna o numero relativo da rede de um numero IP.         */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *nIPBin : O numero IP em binario.                          */
/*  > const char cIP : A classe a que o numero pertence.                    */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna o numero relativo da rede.                                    */
/****************************************************************************/
unsigned long int geraNumRelRede ( const char *nIPBin, const char cIP ) {
   register char i; /* Variavel de controle da iteracao */
   
   /* Variavel que armazenarah o numero relativo */
   /* do host em binario. E variavel que armaze- */
   /* narah o numero de retorno como String.     */
   char auxBin[ 32 ] = "\0",
      auxDec[ 10 ] = "\0";
   
   switch ( cIP ) {
      case 'A':
         for ( i = 0; i <= 7; i++ )
	    sprintf( auxBin, "%s" "%c", auxBin, *( nIPBin + i ) );
	 
	 paraDec( auxBin, auxDec, 2 );
	 
	 return atol( auxDec );
	 
         break;
      
      case 'B':
         for ( i = 0; i <= 15; i++ )
	    sprintf( auxBin, "%s" "%c", auxBin, *( nIPBin + i ) );
	 
	 paraDec( auxBin, auxDec, 2 );
	 
	 return atol( auxDec );
	 
         break;
      
      case 'C':
         for ( i = 0; i <= 23; i++ )
	    sprintf( auxBin, "%s" "%c", auxBin, *( nIPBin + i ) );
	 
	 paraDec( auxBin, auxDec, 2 );
	 
	 return atol( auxDec );
	 
         break;
      
      default: /* Classe invalida */
         return 0;
         break;
   } /* switch */
}


/* main *********************************************************************/
/* DESCRICAO                                                                */
/*    Funcao principal do programa. Nela sao verificados os parametros pas- */
/* sados e sao feitas as chamadas as funcoes das bibliotecas do programa de */
/* modo a processar e mostrar ao usuario o resultado de sua requisicao.     */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > int argc     : O contador de argumentos.                              */
/*  > char *argv[] : A matriz que armazena todos os argumentos.             */
/****************************************************************************/
main ( int argc, char *argv[] ) {
   /* Verificando a quantidade de parametros passados */
   if ( argc < 2 ) {
      printf( "DIP : Falta um parametro.\n" );
      printf( "\tDigite \"DIP --ajuda\" para obter ajuda.\n" );
      
      exit( 1 );
   }
   
   if ( argc > 2 ) {
      printf( "DIP : Excesso de parametros.\n" );
      printf( "\tDigite \"DIP --ajuda\" para obter ajuda.\n" );
      
      exit( 1 );
   }
   
   /* Numero de parametros OK - Verifica se o parametro */
   /* passado eh um parametro especial.                 */
   /* Impressao da ajuda do programa */
   if ( ( ! strcmp( *( argv + 1 ), "--ajuda" ) ) || 
      ( ! strcmp( *( argv + 1 ), "-a" ) ) ) {
      printf( "Uso: dip NUMERO_IP/MASCARA\n" );
      printf( "\tonde: NUMERO_IP eh um numero IP valido e\n" );
      printf( "\t   MASCARA eh uma mascara de IP valida.\n" );
      printf( "ou   dip [opcoes]\n" );
      printf( "Gera e mostra informacoes acerca de um numero IP.\n" );
      printf( "opcoes:\n" );
      printf( "\t--ajuda, -a     Mostra esta ajuda e sai.\n" );
      printf( "\t--versao, -v    Mostra as notas da versao e sai.\n" );
      
      exit( 0 );
   }
   
   /* Impressao das notas da versao do programa */
   if ( ( ! strcmp( *( argv + 1 ), "--versao" ) ) || 
      ( ! strcmp( *( argv + 1 ), "-v" ) ) ) {
      printf( "\tDIP ( Destrinchador de IPs ) 0.5   :)\n" );
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
   
   /* Se o parametro passado nao for um parametro especial, */
   /* este soh pode ser o numero IP a ser analisado.        */
   
   /* O bloco seguinte soh eh executado se o usuario entrar */
   /* com um parametro nao especial. Eh usado um bloco pois */
   /* a alocacao de variaveis soh ocorre caso o programa en-*/
   /* tre nele. Caso contrario as variaveis nao sao aloca-  */
   /* das.                                                  */
   {
      /* INFORMACOES SOBRE O NUMERO IP */
      register char classe, /* A classe do numero IP [A,B,C,D,E ou Loopback] */
         tipo; /* O tipo do numero IP [Local ou Real] */
      
      char mascaraBinario[ 32 ], /* A mascara do IP em binario */
         mascaraDecimal[ 15 ],   /* A mascara do IP em decimal */
         endIPHostBinario[ 32 ], /* O endereco IP do host em binario */
         endIPHostDecimal[ 15 ], /* O endereco IP do host em decimal */
         endIPSRBinario[ 32 ],   /* O endereco IP da sub rede em binario */
         endIPSRDecimal[ 15 ],   /* O endereco IP da sub rede em decimal */
         endIPRedeBinario[ 32 ], /* O endereco IP da rede em binario */
         endIPRedeDecimal[ 15 ]; /* O endereco IP da rede em decimal */
      
      unsigned long int numRelHost, /* Numero relativo do host */
         numRelSR,                  /* Numero relativo da sub rede */
         numRelRede;                /* Numero relativo da rede */
      
      /* Variaveis necessarias ao funcionamento do programa */
      /* Armazena o resultado da analise sintatica do */
      /* numero IP passado ao programa como argumento.*/
      char resAnaliseSintatica = verSinNumIP( *( argv + 1 ) );
   
      /* Verificando o resultado da analise sintatica */
      if ( ( resAnaliseSintatica == 2 ) || ( resAnaliseSintatica == 3 ) ) {
         /* Sintaxe do parametro OK */
         /*Executando a analise semantica */
         classe = verSemNumIP( *( argv + 1 ) );
	 
	 /* Verificando se a mascara passada estah de acordo */
	 /* com o numero - se obedece aos limites.           */	 
	 if ( ( classe ) && ( ! ( verMaskNumIP( *( argv + 1 ), 
	    resAnaliseSintatica, classe ) ) ) ) {
	    printf( "DIP : Para um numero IP de classe %c,", classe );
	    printf( " eh esperada uma mascara de,\n\tpelo menos, " );
	    if ( classe == 'A' )
	       printf( "8 bits.\n" );
	    else if ( classe == 'B' )
	       printf( "16 bits.\n" );
	    else if ( classe == 'C' )
	       printf( "24 bits.\n" );
	    printf( "\tDigite \"dip --ajuda\" para obter ajuda.\n" );
	    
	    exit( 1 );
	 }
         
         /* Verificando o retorno da analise semantica */
         switch ( classe ) {
            case 'A': case 'B': case 'C':
	       /* Obtendo o numero IP isoladamente a */
	       /* partir do parametro passado.       */
	       geraEndIPHost( *( argv + 1 ), endIPHostDecimal,
	          endIPHostBinario );
	       
	       /* Imprimindo as informacoes do numero IP */
	       printf( "CLASSE......................: %c\n", classe );
	       
	       /* Obtendo o tipo do endereco 'L' ou 'R' */
	       tipo = verTipoNumIP( *( argv + 1 ), classe );
	       ( tipo == 'R' ) ?
	          printf( "TIPO........................: REAL\n" ):
		  printf( "TIPO........................: LOCAL\n" );
	       
	       /* Obtendo e imprimindo a mascara do endereco */
	       geraMascaraNumIP( *( argv + 1 ), resAnaliseSintatica,
	          mascaraDecimal, mascaraBinario );
	       printf( "MASCARA.....................: %s\n", mascaraDecimal );
	       
	       /* Obtendo o numero IP isoladamente a partir */
	       /* do parametro passado. E o imprimindo.     */
	       geraEndIPHost( *( argv + 1 ), endIPHostDecimal, endIPHostBinario );
	       printf( "ENDERECO IP DO HOST.........: %s\n", endIPHostDecimal );
	       
	       /* Obtendo o endereco IP da sub rede e o imprimindo */
	       geraEndIPSR( endIPHostBinario, mascaraBinario,
	          endIPSRDecimal, endIPSRBinario );
	       printf( "ENDERECO IP DA SUB REDE.....: %s\n", endIPSRDecimal );
	       
	       /* Obtendo o endereco IP da rede e o imprimindo */
	       geraEndIPRede( endIPHostBinario, classe,
	           endIPRedeDecimal, endIPRedeBinario );
	       printf( "ENDERECO IP DA REDE.........: %s\n", endIPRedeDecimal );
	       
	       /* Obtendo o numero relativo do host e o imprimindo */
	       numRelHost = geraNumRelHost( endIPHostBinario, mascaraBinario );
	       printf( "NUMERO RELATIVO DO HOST.....: %d\n", numRelHost );
	       
	       /* Obtendo o numero relativo da sub rede e o imprimindo */
	       numRelSR = geraNumRelSR( endIPHostBinario, mascaraBinario, classe );
	       printf( "NUMERO RELATIVO DA SUB REDE.: %d\n", numRelSR );
	       
	       /* Obtendo o numero relativo da rede e o imprimindo */
	       numRelRede = geraNumRelRede( endIPHostBinario, classe );
	       printf( "NUMERO RELATIVO DA REDE.....: %d\n", numRelRede );
	       
	       exit( 0 );
	       
	       break;
	    
	    case 'D': case 'E': /* Classes nao usadas */
	       /* Obtendo o numero IP isoladamente a */
	       /* partir do parametro passado.       */
	       geraEndIPHost( *( argv + 1 ), endIPHostDecimal, endIPHostBinario );
	       
	       /* Imprimindo as informacoes do numero IP */
	       printf( "CLASSE......................: %c\n", classe );
	       ( classe == 'D' ) ?
	          printf( "TIPO........................: MULTICAST\n" ):
		  printf( "TIPO........................: RESERVADO\n" );
	       printf( "MASCARA.....................: -\n" );
	       printf( "ENDERECO IP DO HOST.........: %s\n", endIPHostDecimal );
	       printf( "ENDERECO IP DA SUB REDE.....: -\n" );
	       printf( "ENDERECO IP DA REDE.........: -\n" );
	       printf( "NUMERO RELATIVO DO HOST.....: -\n" );
	       printf( "NUMERO RELATIVO DA SUB REDE.: -\n" );
	       printf( "NUMERO RELATIVO DA REDE.....: -\n" );
	       
	       exit( 0 );
	       
	       break;
	    
	    case 'L': /* Endereco de Loopback */
	       /* Obtendo o numero IP isoladamente a */
	       /* partir do parametro passado.       */
	       geraEndIPHost( *( argv + 1 ), endIPHostDecimal, endIPHostBinario );
	       
	       /* Imprimindo as informacoes do numero IP */
	       printf( "CLASSE......................: -\n" );
	       printf( "TIPO........................: LOOPBACK\n" );
	       printf( "MASCARA.....................: 255.0.0.0\n" );
	       printf( "ENDERECO IP DO HOST.........: %s\n", endIPHostDecimal );
	       printf( "ENDERECO IP DA SUB REDE.....: -\n" );
	       printf( "ENDERECO IP DA REDE.........: -\n" );
	       printf( "NUMERO RELATIVO DO HOST.....: -\n" );
	       printf( "NUMERO RELATIVO DA SUB REDE.: -\n" );
	       printf( "NUMERO RELATIVO DA REDE.....: -\n" );
	       
	       exit( 0 );
	       
	       break;
	    
	    default: /* Erro de semantica */
	       printf( "DIP : Numero IP invalido.\n" );
               printf( "\tDigite \"DIP --ajuda\" para obter ajuda.\n" );
	       
	       exit( 1 );
	       
	       break;
         } /* switch */
      }
      else { /* Erro de sintaxe */
         if ( resAnaliseSintatica ) {
	    /* Sintaxe do parametro OK  para Loopback ou classes D e E */
            /*Executando a analise semantica */
            classe = verSemNumIP( *( argv + 1 ) );
	       
	    switch ( classe ) {
	       case 'D': case 'E': /* Classes nao usadas */
	          /* Imprimindo as informacoes do numero IP */
	          printf( "CLASSE......................: %c\n", classe );
	          ( classe == 'D' ) ?
	             printf( "TIPO........................: MULTICAST\n" ):
		     printf( "TIPO........................: RESERVADO\n" );
	          printf( "MASCARA.....................: -\n" );
	          printf( "ENDERECO IP DO HOST.........: %s\n", *( argv + 1 ) );
	          printf( "ENDERECO IP DA SUB REDE.....: -\n" );
	          printf( "ENDERECO IP DA REDE.........: -\n" );
	          printf( "NUMERO RELATIVO DO HOST.....: -\n" );
	          printf( "NUMERO RELATIVO DA SUB REDE.: -\n" );
	          printf( "NUMERO RELATIVO DA REDE.....: -\n" );
	          
	          exit( 0 );
	          
	          break;
	       
	       case 'L': /* Endereco de Loopback */
	          /* Imprimindo as informacoes do numero IP */
	          printf( "CLASSE......................: -\n" );
	          printf( "TIPO........................: LOOPBACK\n" );
	          printf( "MASCARA.....................: 255.0.0.0\n" );
	          printf( "ENDERECO IP DO HOST.........: %s\n", *( argv + 1 ) );
	          printf( "ENDERECO IP DA SUB REDE.....: -\n" );
	          printf( "ENDERECO IP DA REDE.........: -\n" );
	          printf( "NUMERO RELATIVO DO HOST.....: -\n" );
	          printf( "NUMERO RELATIVO DA SUB REDE.: -\n" );
	          printf( "NUMERO RELATIVO DA REDE.....: -\n" );
	          
	          exit( 0 );
	          
	          break;
	       
	       default: /* Erro de semantica */
	          printf( "DIP : Numero IP invalido.\n" );
                  printf( "\tDigite \"dip --ajuda\" para obter ajuda.\n" );
	          
	          exit( 1 );
	          
	          break;
	    } /* switch */
         }
	 
         printf( "DIP : Numero IP invalido.\n" );
         printf( "\tDigite \"dip --ajuda\" para obter ajuda.\n" );
         
         exit( 1 );
      }
   }
}
