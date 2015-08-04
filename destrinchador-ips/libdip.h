/* libdip.h *****************************************************************/
/*                                                                          */
/* DESCRICAO                                                                */
/*    Biblioteca que implementa rotinas necessarias ao funcionamento do pro-*/
/* grama dip ( Destrinchador de IPs ).                                      */
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

/* verTipoNumIP *************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que verifica e retorna o tipo de um numero IP:                 */
/* Local ou Real.                                                           */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *numIP : O numero IP a ser avaliado.                       */
/*  > const char cIP : A classe a que o numero IP pertence.                 */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna: 0 caso encontre algum erro;                                  */
/*             'L' caso o IP seja do tipo local ou                          */
/*             'R' caso o IP seja do tipo real.                             */
/****************************************************************************/
char verTipoNumIP ( const char *numIP, const char cIP ) {
   register char i = 0; /* Variavel de controle da iteracao */
      
   char nAux[ 3 ] = "\0"; /* String que armazenarah numero por numero. */
   
   switch ( cIP ) {
      case 'A':
         /* Coletando o primeiro octeto do numero IP */
	 while ( *( numIP + i ) != '.' ) {
	    /* Armazenando o ultimo caractere lido em */
	    /* nAux e incrementando a variavel i.     */
	    sprintf( nAux, "%s" "%c", nAux, *( numIP + i ) );
	    ++i;
	 }
	 
	 if ( ! strcmp( nAux, "10" ) )
	    return 'L';
	 else
	    return 'R';
	 
         break;
      
      case 'B':
         /* Coletando o primeiro octeto do numero IP */
	 while ( *( numIP + i ) != '.' ) {
	    /* Armazenando o ultimo caractere lido em */
	    /* nAux e incrementando a variavel i.     */
	    sprintf( nAux, "%s" "%c", nAux, *( numIP + i ) );
	    ++i;
	 }
	 
	 if ( ! strcmp( nAux, "172" ) ) {
	    /* Armazenarah a conversao do octeto de */
	    /* String pra numerico.                 */
	    char nCh;
	    
	    /* Limpando o ultimo octeto lido e incrementando */
	    /* a variavel i pra sair do '.'.                 */
	    strcpy( nAux, "\0" );
	    ++i;
	    
	    /* Coletando o segundo octeto do numero IP */
	    while ( *( numIP + i ) != '.' ) {
	       /* Armazenando o ultimo caractere lido em */
	       /* nAux e incrementando a variavel i.     */
	       sprintf( nAux, "%s" "%c", nAux, *( numIP + i ) );
	       ++i;
	    }
	    
	    /* Convertendo de String pra numerico o octeto coletado */
	    nCh = atoi( nAux );
	    
	    if ( ( nCh >= 16 ) && ( nCh <= 31 ) )
	       return 'L';
	    else
	       return 'R';
	 }
	 else
	    return 'R';
	 
	 break;
      
      case 'C':
         /* Coletando o primeiro octeto do numero IP */
	 while ( *( numIP + i ) != '.' ) {
	    /* Armazenando o ultimo caractere lido em */
	    /* nAux e incrementando a variavel i.     */
	    sprintf( nAux, "%s" "%c", nAux, *( numIP + i ) );
	    ++i;
	 }
	 
	 if ( ! strcmp( nAux, "192" ) ) {
	    /* Limpando o ultimo octeto lido e incrementando */
	    /* a variavel i pra sair do '.'.                 */
	    strcpy( nAux, "\0" );
	    ++i;
	    
	    /* Coletando o segundo octeto do numero IP */
	    while ( *( numIP + i ) != '.' ) {
	       /* Armazenando o ultimo caractere lido em */
	       /* nAux e incrementando a variavel i.     */
	       sprintf( nAux, "%s" "%c", nAux, *( numIP + i ) );
	       ++i;
	    }
	    
	    if ( ! strcmp( nAux, "168" ) )
	       return 'L';
	    else
	       return 'R';
	 }
	 else
	    return 'R';
	 
         break;
      
      default: /* Classe invalida */
         return 0;
	 break;
   }
}

/* ctoi *********************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retorna o valor inteiro de um digito a partir de sua repre-*/
/* sentacao em caracter.                                                    */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > char ch : Caracter que sera convertido.                               */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna a representacao em inteiro do caracter. Caso o parametro pas- */
/* sado nao seja um digito, o valor retornado eh indefinido.                */
/****************************************************************************/
char ctoi ( char ch ) {
   return ( ch - 48 );
}

/* potencia *****************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retorna a potencia de um numero.                           */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > unsigned char base : O numero que representa a base na exponenciacao. */
/*  > unsigned int expoente : O expoente da operacao.                       */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna o numero que representa "BASE elevadada ao EXPOENTE".         */
/****************************************************************************/
unsigned long int potencia ( unsigned char base, unsigned int expoente ) {   
   register unsigned long int aux = 1;
   
   if ( ! expoente )
      return 1;
   else
      for ( ; expoente > 0; expoente-- )
         aux *= base;
   
   return aux;
}

/* decPara ******************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que converte um numero na base 10 para sua representacao numa  */
/* base qualquer definida por base.                                         */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *num : O numero a ser convertido.                          */
/*  > char *res : O numero final (convertido).                              */
/*  > const unsigned char base : A base em que o numero final deve estar.   */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna em *res o numero na base desejada.                            */
/****************************************************************************/
void decPara ( const char *num, char *res, const unsigned char base ) {
   register unsigned long int n = atol( num );
   
   char aux[ 256 ];
   
   strcpy( res, "\0" ); /* Limpando o resultado */
   
   while ( n >= base ) {
      strcpy( aux, res );
      sprintf( res, "%d" "%s", ( n % base ), aux );
      
      n /= base;
   }

   strcpy( aux, res );
   sprintf( res, "%d" "%s", n, aux );
}

/* paraDec ******************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que converte um numero numa base qualquer definida em base pa- */
/* ra sua representacao na base 10.                                         */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *num : O numero a ser convertido.                          */
/*  > char *res : O numero final (convertido).                              */
/*  > const unsigned char base : A base em que o numero se encontra.        */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna em *res o numero na base decimal.                             */
/****************************************************************************/
void paraDec ( const char *num, char *res, const unsigned char base ) {
   register char pos, exp;
   register unsigned long int n = 0;
   
   strcpy( res, "\0" ); /* Limpando o resultado */
   
   for ( pos = strlen( num ) - 1, exp = 0; pos >= 0; pos--, exp++ ) 
      n += potencia( base, exp ) * ctoi( *( num + pos ) );

   sprintf( res, "%d", n );
}

/* convNumIp ****************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que converte um numero IP do formato decimal pra binario e vi- */
/* ce-versa. Formatos devolvidos e aceitos:                                 */
/*    Decimal: NUM.NUM.NUM.NUM                                              */
/*    Binario: NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN                             */
/* onde: ( 0 <= NUM <= 255 ) e ( N = 0 ou N = 1 )                           */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > char *nIPDec : O numero IP em formato decimal.                        */
/*  > char *nIPBin : O numero IP em formato binario.                        */
/*  > const char flag : Indica qual conversao serah feita ( bin > dec ou    */
/*     dec > bin ).                                                         */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna 1 caso a conversao requerida tenha sido realizada com sucesso */
/* ou 0 em caso contrario.                                                  */
/****************************************************************************/
char convNumIP ( char *nIPDec, char *nIPBin, const char flag ) {
   /* Variavel de controle de iteracoes */
   register char i = 0;
   
   /* Variavel auxiliar que guardarah numero por */
   /* numero no formato decimal no tipo String.  */
   char auxDec[ 3 ] = "\0",
   
   /* Variavel auxiliar que guardarah numero por */
   /* numero no formato binario no tipo String.  */
      auxBin[ 8 ] = "\0";
   
   switch ( flag ) {
      case 0: /* Decimal pra Binario */
         *( nIPBin + 0 ) = '\0'; /* Limpando a variavel */
	 
	 while ( i < strlen( nIPDec ) ) {
	    /* Pegando numero por numero no formato */
	    /* decimal e armazenando em auxDec.     */
	    while ( ( *( nIPDec + i ) != '.' ) && 
	       ( *( nIPDec + i ) != '\0' ) ) {
	       sprintf( auxDec, "%s" "%c", auxDec, *( nIPDec + i ) );
	       ++i;
	    }
	    ++i;
	    
	    /* Convertendo o numero retirado de */
	    /* decimal pra binario.             */
	    decPara( auxDec, auxBin, 2 );
	    
	    /* Completando o numero binario com '0's pra */
	    /* manter o formato de 8 bits por numero.    */
	    while ( strlen( auxBin ) < 8 ) {
	       char aux[ 8 ];
	       
	       strcpy( aux, auxBin );
	       
	       sprintf( auxBin, "%c" "%s", '0', aux );
	    }
	    
	    /* Concatenando o octeto gerado */
	    /* em nIPBin pra gerar o numero.*/
	    strcat( nIPBin, auxBin );
	    
	    /* Limpando auxBin pra que ela possa */
	    /* receber o proximo octeto.         */
	    *( auxBin + 0 ) = '\0';
	 }
	 
	 return 1;
	 
         break;
      
      case 1: /* Binario pra Decimal */
         *( nIPDec + 0 ) = '\0'; /* Limpando a variavel */
	 
	 while ( i < strlen( nIPBin ) ) {
	    /* Pegando octeto por octeto no formato */
	    /* binario e armazenando em auxBin.     */
	    while ( ( i != 8 ) && ( i != 16 ) && 
	       ( i != 24 ) && ( i != 32 ) ) {
	       sprintf( auxBin, "%s" "%c", auxBin, 
	          *( nIPBin + i ) );
	       ++i;
	    }
	    
	    /* Convertendo o octeto retirado de */
	    /* binario pra decimal.             */
	    paraDec( auxBin, auxDec, 2 );
	    
	    /* Concatenando o numero gerado */
	    /* em nIPDec pra gerar o numero.*/
	    strcat( nIPDec, auxDec );
	    
	    /* Limpando auxBin pra que ela possa */
	    /* receber o proximo octeto.         */
	    *( auxBin + 0 ) = '\0';
	    
	    /* Pegando um numero para que a variavel */
	    /* i saia da condicao de escape do laco  */
	    /* while acima.                          */
	    /* Se ainda nao se chegou ao ultimo */
	    /* octeto, deve-se acrescentar o '.'*/
	    if ( i < 31 ) {
	       sprintf( auxBin, "%s" "%c", auxBin, 
	          *( nIPBin + i ) );
	       ++i;
	       
	       strcat( nIPDec, "." );
	    }
	 }
	 
	 return 1;
	 
         break;
      
      default: /* Flag invalido */
         *( nIPDec + 0 ) = '\0';
	 *( nIPBin + 0 ) = '\0';
	 
	 return 0;
	 
         break;
   } /* switch */
}

/* verMaskNumIP *************************************************************/
/* DESCRICAO                                                                */
/*    Funcao verifica a validade de uma mascara de determinado numero IP.   */
/* Para um IP de classe A, a mascara deve estar entre 255.0.0.0 e           */
/* 255.255.255.255 ou entre 8 e 32. Para um de classe B, 255.255.0.0 e      */
/* 255.255.255.255 ou entre 16 e 32. Para um de classe C, 255.255.255.0 e   */
/* 255.255.255.255 ou entre 24 e 32.                                        */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char *param : O parametro passado ao programa.                  */
/*  > const char fIP : O formato do parametro - vide retorno de verSinNumIP.*/
/*  > const char cIP : A classe do numero - vide retorno de verSemNumIP.    */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna 1 caso a mascara esteja correta de acordo com a classe do nu- */
/* mero IP ou se fIP e/ou cIP forem incorretos. Retorna 0 caso a mascara    */
/* nao esteja de acordo com a classe do numero IP.                          */
/****************************************************************************/
char verMaskNumIP ( const char *param, const char fIP, const char cIP ) {
   if ( ( fIP == 2 ) || ( fIP == 3 ) ) {
      register char i = 0; /* Variavel de controle de itera- */
                           /* racoes e contagem.             */
      
      char nIPBin[ 32 ] = "\0"; /* Numero IP em binario */
      
      /* Posicionando o ponteiro no inicio da mascara */
      while ( *( param + i ) != '/' ) ++i;
      ++i;
      
      /* Copiando a mascara pra nIPBin */
      while ( i < strlen( param ) ) {
         sprintf( nIPBin, "%s" "%c", nIPBin, *( param + i ) );
	 ++i;
      }
      
      /* A acao eh tomada de acordo com a classe do IP */
      switch ( cIP ) {
         case 'A':
	    if ( fIP == 2 ) {
	       char auxCh = atoi( nIPBin );
	       
	       if ( auxCh >= 8 )
	          return 1;
	       else
	          return 0;
	    }
	    else {
	       /* Armazenarh o numero IP em decimal */
	       char nIPDec[ 15 ];
	       
	       /* Copiando o IP em decimal para a va- */
	       /* riavel correta e limpando nIPBin.   */
	       strcpy( nIPDec, nIPBin );
	       *( nIPBin ) = '\0';
	       
	       /* Gerando a forma binaria do numero IP */
	       convNumIP( nIPDec, nIPBin, 0 );
	       
	       /* Contando quantos '1's tem a forma binaria */
	       for ( i = 0; *( nIPBin + i ) == '1'; i++ );
	       
	       /* Testando de acordo com a classe */
	       if ( i >= 8 )
	          return 1;
	       else
	          return 0;
	    }
	    
	    break;
         
         case 'B':
	    if ( fIP == 2 ) {
	       char auxCh = atoi( nIPBin );
	       
	       if ( auxCh >= 16 )
	          return 1;
	       else
	          return 0;
	    }
	    else {
	       /* Armazenarh o numero IP em decimal */
	       char nIPDec[ 15 ];
	       
	       /* Copiando o IP em decimal para a va- */
	       /* riavel correta e limpando nIPBin.   */
	       strcpy( nIPDec, nIPBin );
	       *( nIPBin ) = '\0';
	       
	       /* Gerando a forma binaria do numero IP */
	       convNumIP( nIPDec, nIPBin, 0 );
	       
	       /* Contando quantos '1's tem a forma binaria */
	       for ( i = 0; *( nIPBin + i ) == '1'; i++ );
	       
	       /* Testando de acordo com a classe */
	       if ( i >= 16 )
	          return 1;
	       else
	          return 0;
	    }
	    
	    break;
         
         case 'C':
	    if ( fIP == 2 ) {
	       char auxCh = atoi( nIPBin );
	       
	       if ( auxCh >= 24 )
	          return 1;
	       else
	          return 0;
	    }
	    else {
	       /* Armazenarh o numero IP em decimal */
	       char nIPDec[ 15 ];
	       
	       /* Copiando o IP em decimal para a va- */
	       /* riavel correta e limpando nIPBin.   */
	       strcpy( nIPDec, nIPBin );
	       *( nIPBin ) = '\0';
	       
	       /* Gerando a forma binaria do numero IP */
	       convNumIP( nIPDec, nIPBin, 0 );
	       
	       /* Contando quantos '1's tem a forma binaria */
	       for ( i = 0; *( nIPBin + i ) == '1'; i++ );
	       
	       /* Testando de acordo com a classe */
	       if ( i >= 24 )
	          return 1;
	       else
	          return 0;
	    }
	    
	    break;
         
         default: /* Classe desconhecida */
	    return 1;
	    break;
      } /* switch */
   }
   else /* Formato nao reconhecido */
      return 1;
}
