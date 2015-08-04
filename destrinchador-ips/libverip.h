/* libverip.h ***************************************************************/
/*                                                                          */
/* DESCRICAO                                                                */
/*    Biblioteca que implementa rotinas de validacao de numeros IP.         */
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
#include <ctype.h>
#include <stdio.h>

/* verSinNumIP **************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que verifica a sintaxe de um numero IP sob as formas:          */
/*       1. NUM.NUM.NUM.NUM ou                                              */
/*       2. NUM.NUM.NUM.NUM/N ou                                            */
/*       3. NUM.NUM.NUM.NUM/NUM.NUM.NUM.NUM                                 */
/*    Verifica se os numeros, pontos e barra ( se houver ) estao na posicao */
/* correta.                                                                 */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *numIP : O numero IP a ser avaliado.                       */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna: 0 caso encontre algum erro;                                  */
/*             1 caso esteja sob a primeira forma;                          */
/*             2 caso esteja sob a segunda forma ou                         */
/*             3 caso esteja sob a terceira forma.                          */
/****************************************************************************/
char verSinNumIP ( const char *numIP ) {
   register char i, /* Variavel de controle da iteracao. */
      estado = 1,   /* O estado em que a funcao se encontra. */
      chLido;       /* O ultimo caractere lido. */
   
   /* Este laco se repete ateh que seja atingido o fim */
   /* da variavel numIP.                               */
   for ( i = 0; i < strlen( numIP ); i++ ) {
      /* Lendo um caractere de numIP e gravando-o em chLido. */
      chLido = *( numIP + i );
      
      /* Uma acao serah tomada dependendo do estado. */
      switch ( estado ) {
         case 1:
	    if ( isdigit( chLido ) )
	       estado = 2;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 2:
	    if ( isdigit( chLido ) )
	       estado = 3;
	    else if ( chLido == '.' )
	       estado = 5;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 3:
	    if ( isdigit( chLido ) )
	       estado = 4;
	    else if ( chLido == '.' )
	       estado = 5;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 4:
	    if ( chLido == '.' )
	       estado = 5;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 5:
	    if ( isdigit( chLido ) )
	       estado = 6;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 6:
	    if ( isdigit( chLido ) )
	       estado = 7;
	    else if ( chLido == '.' )
	       estado = 9;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 7:
	    if ( isdigit( chLido ) )
	       estado = 8;
	    else if ( chLido == '.' )
	       estado = 9;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 8:
	    if ( chLido == '.' )
	       estado = 9;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 9:
	    if ( isdigit( chLido ) )
	       estado = 10;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 10:
	    if ( isdigit( chLido ) )
	       estado = 11;
	    else if ( chLido == '.' )
	       estado = 13;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 11:
	    if ( isdigit( chLido ) )
	       estado = 12;
	    else if ( chLido == '.' )
	       estado = 13;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 12:
	    if ( chLido == '.' )
	       estado = 13;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 13:
	    if ( isdigit( chLido ) )
	       estado = 14;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 14: /* Estado final */
	    if ( isdigit( chLido ) )
	       estado = 15;
	    else if ( chLido == '/' )
	       estado = 17;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 15: /* Estado final */
	    if ( isdigit( chLido ) )
	       estado = 16;
	    else if ( chLido == '/' )
	       estado = 17;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 16: /* Estado final */
	    if ( chLido == '/' )
	       estado = 17;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 17:
	    if ( isdigit( chLido ) )
	       estado = 18;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 18: /* Estado final */
	    if ( isdigit( chLido ) )
	       estado = 19;
	    else if ( chLido == '.' )
	       estado = 21;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 19: /* Estado final */
	    if ( isdigit( chLido ) )
	       estado = 20;
	    else if ( chLido == '.' )
	       estado = 21;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 20:
	    if ( chLido == '.' )
	       estado = 21;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 21:
	    if ( isdigit( chLido ) )
	       estado = 22;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 22:
	    if ( isdigit( chLido ) )
	       estado = 23;
	    else if ( chLido == '.' )
	       estado = 25;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 23:
	    if ( isdigit( chLido ) )
	       estado = 24;
	    else if ( chLido == '.' )
	       estado = 25;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 24:
	    if ( chLido == '.' )
	       estado = 25;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 25:
	    if ( isdigit( chLido ) )
	       estado = 26;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 26:
	    if ( isdigit( chLido ) )
	       estado = 27;
	    else if ( chLido == '.' )
	       estado = 29;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 27:
	    if ( isdigit( chLido ) )
	       estado = 28;
	    else if ( chLido == '.' )
	       estado = 29;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 28:
	    if ( chLido == '.' )
	       estado = 29;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 29:
	    if ( isdigit( chLido ) )
	       estado = 30;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 30: /* Estado final */
	    if ( isdigit( chLido ) )
	       estado = 31;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 31: /* Estado final */
	    if ( isdigit( chLido ) )
	       estado = 32;
	    else {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 case 32: /* Estado Final */
	    if ( chLido != '\0' ) {
	       --i; /* Voltando ao ultimo caractere lido */
	       estado = 0; /* Indo ao estado de erro */
	    }
	    
	    break;
	 
	 default: /* Estado de erro */
	    /* Forcando a saida da iteracao */
	    i = strlen( numIP ) - 1;
	    
	    break;
      } /* switch */
   } /* for */
   
   /* Verificando qual foi o estado de saida da iteracao, */
   /* para poder saber qual serah o retorno da funcao.    */
   switch ( estado ) {
      /* NUM.NUM.NUM.NUM */
      case 14: case 15: case 16:
         return 1;
	 break;
      
      /* NUM.NUM.NUM.NUM/N */
      case 18: case 19:
         return 2;
	 break;
      
      /* NUM.NUM.NUM.NUM/NUM.NUM.NUM.NUM.NUM */
      case 30: case 31: case 32:
         return 3;
	 break;
      
      /* Erro encontrado */
      default:
         return 0;
	 break;
   } /* switch */
}

/* verSemNumIP **************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que verifica a semantica de um numero IP sob as formas:        */
/*       1. NUM.NUM.NUM.NUM ou                                              */
/*       2. NUM.NUM.NUM.NUM/N ou                                            */
/*       3. NUM.NUM.NUM.NUM/NUM.NUM.NUM.NUM                                 */
/*    Verifica se ( 0 <= NUM <=255 ) e ( 0 <= N <= 32 ). O ideal eh que es- */
/* ta funcao seja executada apos a verSinNumIP, ou seja, apos a sintaxe ter */
/* sido verificada e nao terem sido encontrados erros.                      */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *numIP : O numero IP a ser avaliado.                       */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna: 0 caso encontre algum erro ou                                */
/*             A classe do numero IP caso nao sejam encontrados erros.      */
/*                Classes de retorno: A, B, C, D, E ou L ( Loopback ).      */
/****************************************************************************/
char verSemNumIP ( const char *numIP ) {
   register char i, /* Variavel de controle de iteracao */
      
      estado = 1,   /* O estado em que a funcao se encontra. */
      
      chLido, /* O ultimo caractere lido de numIP. */
      
      classe; /* A classe do numero IP. */
      
   int numCh; /* Armazena a conversao de um numero no tipo String */
              /* para um numero no tipo numerico.                 */
      
   char nStr[ 3 ] = "\0"; /* String que armazenarah numero por numero. */
      
   /* Este laco serah repetido ateh que se atinja o fim do numero IP */
   /* ou que seja encontrado algum erro.                             */
   for ( i = 0; i < strlen( numIP ); i++ ) {
      /* Lendo um caractere de numIP e gravando-o em chLido. */
      chLido = *( numIP + i );
      
      switch ( estado ) {
         case 1:
	    if ( isdigit( chLido ) )
	       /* Concatenando numeros ao fim da String */
	       sprintf( nStr, "%s" "%c", nStr, chLido );
	    
	    else if ( chLido == '.' ) {
	       /* Convertendo o numero encontrado de String */
	       /* para numerico.                            */
	       numCh = atoi( nStr );
	       
	       /* Verificando se o numero estah dentro da faixa */
	       if ( ( numCh < 1 ) || ( numCh > 255 ) )
	          /* Numero fora da faixa */
		  estado = 0; /* Indo para o estado de Erro */
	       
	       else {
	          /* Numero dentro da faixa */
		  
		  /* Verificando a classe que o numero IP pertence*/
		  if ( ( numCh >= 1 ) && ( numCh <= 126 ) )
		     classe = 'A';
		  else if ( ( numCh >= 128 ) && ( numCh <= 191 ) )
		     classe = 'B';
		  else if ( ( numCh >= 192 ) && ( numCh <= 223 ) )
		     classe = 'C';
		  else if ( ( numCh >= 224 ) && ( numCh <= 239 ) )
		     classe = 'D';
		  else if ( ( numCh >= 240 ) && ( numCh <= 255 ) )
		     classe = 'E';
		  else if ( numCh == 127 )
		     classe = 'L';
		  
	          estado = 2; /* Indo para o proximo estado */
	       }
	       
	       /* Limpando a String auxiliar */
	       strcpy( nStr, "\0" );
	    }
	    
	    break;
	 
	 case 2:
	    if ( isdigit( chLido) )
	       /* Concatenando numeros ao fim da String */
	       sprintf( nStr, "%s" "%c", nStr, chLido );
	    else if ( chLido == '.' ) {
	       /* Convertendo o numero encontrado de String */
	       /* para numerico.                            */
	       numCh = atoi( nStr );
	       
	       /* Verificando se o numero estah dentro da faixa */
	       if ( numCh > 255 )
	          /* Numero fora da faixa */
		  estado = 0; /* Indo para o estado de Erro */
	       else
	          /* Numero dentro da faixa */
		  estado = 3; /* Indo para o proximo estado */
	       
	       /* Limpando a String auxiliar */
	       strcpy( nStr, "\0" );
	    }
	    
	    break;
	 
	 case 3:
	    if ( isdigit( chLido) )
	       /* Concatenando numeros ao fim da String */
	       sprintf( nStr, "%s" "%c", nStr, chLido );
	    else if ( chLido == '.' ) {
	       /* Convertendo o numero encontrado de String */
	       /* para numerico.                            */
	       numCh = atoi( nStr );
	       
	       /* Verificando se o numero estah dentro da faixa */
	       if (  numCh > 255 )
	          /* Numero fora da faixa */
		  estado = 0; /* Indo para o estado de Erro */
	       else
	          /* Numero dentro da faixa */
		  estado = 4; /* Indo para o proximo estado */
	       
	       /* Limpando a String auxiliar */
	       strcpy( nStr, "\0" );
	    }
	    
	    break;
	 
	 case 4: /* Estado final */
	    if ( isdigit( chLido) ) {
	       /* Concatenando numeros ao fim da String */
	       sprintf( nStr, "%s" "%c", nStr, chLido );
	       
	       /* Verificando se o fim do numero IP foi atingido */
	       if ( i == strlen( numIP ) - 1 ) {
	          /* Convertendo o numero encontrado de String */
	          /* para numerico.                            */
	          numCh = atoi( nStr );
		  
		  /* Verificando se o numero estah dentro da faixa */
	          if ( numCh > 255 )
	             /* Numero fora da faixa */
		     estado = 0; /* Indo para o estado de Erro */
	       }
	    }
	    else if ( chLido == '/' ) {
	       /* Convertendo o numero encontrado de String */
	       /* para numerico.                            */
	       numCh = atoi( nStr );
	       
	       /* Verificando se o numero estah dentro da faixa */
	       if ( numCh > 255 )
	          /* Numero fora da faixa */
		  estado = 0; /* Indo para o estado de Erro */
	       else
	          /* Numero dentro da faixa */
		  estado = 5; /* Indo para o proximo estado */
	       
	       /* Limpando a String auxiliar */
	       strcpy( nStr, "\0" );
	    }
	    
	    break;
	
	 case 5: /* Estado final */
	    if ( isdigit( chLido) ) {
	       /* Concatenando numeros ao fim da String */
	       sprintf( nStr, "%s" "%c", nStr, chLido );
	       
	       /* Verificando se o fim do numero IP foi atingido */
	       if ( i == strlen( numIP ) - 1 ) {
	          /* Convertendo o numero encontrado de String */
	          /* para numerico.                            */
	          numCh = atoi( nStr );
		  
		  /* Verificando se o numero estah dentro da faixa */
	          if ( numCh > 32 )
	             /* Numero fora da faixa */
		     estado = 0; /* Indo para o estado de Erro */
	       }
	    }
	    else if ( chLido == '.' ) {
	       /* Convertendo o numero encontrado de String */
	       /* para numerico.                            */
	       numCh = atoi( nStr );
	       
	       /* Verificando se o numero estah dentro da faixa */
	       if ( numCh > 255 )
	          /* Numero fora da faixa */
		  estado = 0; /* Indo para o estado de Erro */
	       else
	          /* Numero dentro da faixa */
		  estado = 6; /* Indo para o proximo estado */
	       
	       /* Limpando a String auxiliar */
	       strcpy( nStr, "\0" );
	    }
	    
	    break;
	 
	 case 6:
	    if ( isdigit( chLido) )
	       /* Concatenando numeros ao fim da String */
	       sprintf( nStr, "%s" "%c", nStr, chLido );
	    else if ( chLido == '.' ) {
	       /* Convertendo o numero encontrado de String */
	       /* para numerico.                            */
	       numCh = atoi( nStr );
	       
	       /* Verificando se o numero estah dentro da faixa */
	       if ( numCh > 255 )
	          /* Numero fora da faixa */
		  estado = 0; /* Indo para o estado de Erro */
	       else
	          /* Numero dentro da faixa */
		  estado = 7; /* Indo para o proximo estado */
	       
	       /* Limpando a String auxiliar */
	       strcpy( nStr, "\0" );
	    }
	    
	    break;
	 
	 case 7:
	    if ( isdigit( chLido) )
	       /* Concatenando numeros ao fim da String */
	       sprintf( nStr, "%s" "%c", nStr, chLido );
	    else if ( chLido == '.' ) {
	       /* Convertendo o numero encontrado de String */
	       /* para numerico.                            */
	       numCh = atoi( nStr );
	       
	       /* Verificando se o numero estah dentro da faixa */
	       if ( numCh > 255 )
	          /* Numero fora da faixa */
		  estado = 0; /* Indo para o estado de Erro */
	       else
	          /* Numero dentro da faixa */
		  estado = 8; /* Indo para o proximo estado */
	       
	       /* Limpando a String auxiliar */
	       strcpy( nStr, "\0" );
	    }
	    
	    break;
	 
	 case 8: /* Estado final */
	    if ( isdigit( chLido) ) {
	       /* Concatenando numeros ao fim da String */
	       sprintf( nStr, "%s" "%c", nStr, chLido );
	       
	       /* Verificando se o fim do numero IP foi atingido */
	       if ( i == strlen( numIP ) - 1 ) {
	          /* Convertendo o numero encontrado de String */
	          /* para numerico.                            */
	          numCh = atoi( nStr );
		  
		  /* Verificando se o numero estah dentro da faixa */
	          if ( numCh > 255 )
	             /* Numero fora da faixa */
		     estado = 0; /* Indo para o estado de Erro */
	       }
	    }
	    
	    break;
	 
	 default: /* Estado de Erro */
	    /* Forcando a saida da iteracao */
	    i = strlen( numIP ) - 1;
	    
	    break;
      } /* switch */
   } /* for */
   
   /* Verificando qual foi o estado de saida da iteracao, */
   /* para poder saber qual serah o retorno da funcao.    */
   switch ( estado ) {
      case 4: case 5: case 8:
         return classe;
	 break;
      
      default : /* Erro encontrado */
         return 0;
	 break;
   } /* switch */
}
