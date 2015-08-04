/**********************************************************************************
   NOME: al.c
 
   DESCRI��O
   Analisador lexico da linguagem Pascal.
 
   DEPEND�NCIAS
   Necessita do c�digo-fonte pronto (digitado em qualquer editor de textos raso),
      da biblioteca de tipos abstratos libabstype.h -para implementa��o da tabela
      de simbolos- e da biblioteca libal.h.
   
   AUTOR
   Jos� Lopes de Oliveira J�nior
   
   CONTATO
   jlojunior@gmail.com
***********************************************************************************/

/* Bibliotecas importadas */
#include <stdio.h>
#include "libal.h" /* Inclui libabstype.h */

/**********************************************************************************
   NOME: printQueueErrorsTable()
   
   DESCRI��O
   Imprime a tabela de erros na tela.
   
   PAR�METROS
   Queue *queue : Um ponteiro para a fila.
   
   RETORNO
   Retorna 0, caso a opera��o tenha sido realizada com sucesso;
           1, no caso de a lista estar vazia.
**********************************************************************************/
int printQueueErrorsTable ( Queue *queue )
{
   /* Verificando se a Fila estah vazia */
   if ( queueEmpty( queue ) )
      return 1; /* Fila vazia */
   
   else {
      /* A Fila nao estah vazia */
      
      /* Um ponteiro auxiliar para varrer a Fila */
      Pointer aux = queue -> front -> next;
      
      /* Imprime enquanto nao chegar ao fim da Fila */
      while ( aux != NULL ) {
         /* Imprimindo... */
         printf( "< %30s ; %22s ; %4d ; (%4d,%4d) >\n",
            aux -> item.token, aux -> item.class, aux -> item.value,
            aux -> item.coOrdinate.line, aux -> item.coOrdinate.column );
         
         /*printf( "< %50s ; %s ; %4d ; (%4d,%4d) >\n",
            aux -> item.token, aux -> item.class, aux -> item.value,
            aux -> item.coOrdinate.line, aux -> item.coOrdinate.column ); */
         
         /* Atualizando a variavel aux */
         aux = aux -> next;
      } /* while */
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* printQueueErrorsTable */

/**********************************************************************************
   NOME: printQueueTokensTable()
   
   DESCRI��O
   Imprime a tabela de tokens na tela.
   
   PAR�METROS
   Queue *queue : Um ponteiro para a fila.
   
   RETORNO
   Retorna 0, caso a opera��o tenha sido realizada com sucesso;
           1, no caso de a lista estar vazia.
**********************************************************************************/
int printQueueTokensTable ( Queue *queue )
{
   /* Verificando se a Fila estah vazia */
   if ( queueEmpty( queue ) )
      return 1; /* Fila vazia */
   
   else {
      /* A Fila nao estah vazia */
      
      /* Um ponteiro auxiliar para varrer a Fila */
      Pointer aux = queue -> front -> next;
      
      /* Imprime enquanto nao chegar ao fim da Fila */
      while ( aux != NULL ) {
         /* Imprimindo... */
         printf( "< %13s ; %39s ; %4d ; (%4d,%4d) >\n",
            aux -> item.token, aux -> item.class, aux -> item.value,
            aux -> item.coOrdinate.line, aux -> item.coOrdinate.column );
         
         /*printf( "< %50s ; %s ; %4d ; (%4d,%4d) >\n",
            aux -> item.token, aux -> item.class, aux -> item.value,
            aux -> item.coOrdinate.line, aux -> item.coOrdinate.column ); */
         
         /* Atualizando a variavel aux */
         aux = aux -> next;
      } /* while */
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* printQueueTokensTable */

/**********************************************************************************
   NOME: printQueueSymbolTable()
   
   DESCRI��O
   Imprime a tabela de s�mbolos na tela.
   
   PAR�METROS
   Queue *queue : Um ponteiro para a fila.
   
   RETORNO
   Retorna 0, caso a opera��o tenha sido realizada com sucesso;
           1, no caso de a lista estar vazia.
**********************************************************************************/
int printQueueSymbolTable ( Queue *queue )
{
   /* Verificando se a Fila estah vazia */
   if ( queueEmpty( queue ) )
      return 1; /* Fila vazia */
   
   else {
      /* A Fila nao estah vazia */
      
      /* Um ponteiro auxiliar para varrer a Fila */
      Pointer aux = queue -> front -> next;
      
      /* Imprime enquanto nao chegar ao fim da Fila */
      while ( aux != NULL ) {
         /* Imprimindo... */
         printf( "< %50s ; %s ; %4d ; (%4d,%4d) >\n",
            aux -> item.token, aux -> item.class, aux -> item.value,
            aux -> item.coOrdinate.line, aux -> item.coOrdinate.column );
         
         /* Atualizando a variavel aux */
         aux = aux -> next;
      } /* while */
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* printQueueSymbolTable */

/**********************************************************************************
   NOME: main()
   
   DESCRICAO
   Fun��o principal do programa.
   
   PARAMETROS
   int argc : Contador de argumentos.
   char *argv[] : Matriz que armazena os argumentos.
   
   RETORNO
   Retorna 0 caso n�o haja nenhum erro, ou um valor diferente em caso contr�rio.
**********************************************************************************/
int main ( int argc, char *argv[] )
{
   FILE *sourceCode; /* O ponteiro para o arquivo com o codigo-fonte. */
   
   /* Verificando a quantidade de parametros passados */
   if ( argc < 2 ) { /* Faltam paramentros */
      printf( "AL : Falta um par�metro.\n" );
      printf( "\tDigite \"al --ajuda\" para obter ajuda.\n" );
      exit( 1 );
   }
   
   if ( argc > 2 ) { /* Parametros excessivos */
      printf( "AL : Excesso de par�metros\n" );
      printf( "\tDigite \"al --ajuda\" para obter ajuda.\n" );
      exit( 1 );
   }
   
   /* Numero de parametros OK - Verifica se o parametro
         passado eh um parametro especial.              */
   if ( ( ! strcmp( *( argv + 1 ), "--ajuda" ) ) || 
      ( ! strcmp( *( argv + 1 ), "-a" ) ) ) { /* Pedido de ajuda */
      printf( "Uso: al ARQUIVO\n" );
      printf( "\tonde: ARQUIVO � o caminho do arquivo com o\n" );
      printf( "\t   c�digo-fonte a ser analisado.\n" );
      printf( "ou   al [op��es]\n" );
      printf( "Realiza a an�lise l�xica da linguagem pascal.\n" );
      printf( "op��es:\n" );
      printf( "\t--ajuda, -a     Mostra esta ajuda e sai.\n" );
      printf( "\t--versao, -v    Mostra as notas da vers�o e sai.\n" );
      
      exit( 0 );
   }
   
   if ( ( ! strcmp( *( argv + 1 ), "--versao" ) ) || 
      ( ! strcmp( *( argv + 1 ), "-v" ) ) ) { /* Notas da versao */
      printf( "\tAL ( Analisador L�xico ) 0.5\n" );
      printf( "Escrito por Jos� Lopes de Oliveira J�nior. " );
      printf( "<jlojunior@gmail.com>\n\n" );
      printf( "Copyright (C) 2006.\n" );
      
      printf( "\tEste programa � um software de livre distribui��o, que pode\n" ); 
      printf( "ser copiado e distribu�do sob os termos da Licen�a Geral GNU, con-\n" );
      printf( "forme publicada pela Free Software Foundation, vers�o 2 da licen-\n" );
      printf( "�a, ou (a crit�rio do autor) qualquer vers�o posterior.\n" );
      printf( "\tEste programa � distribu�do na expectativa de ser �til aos se-\n" );
      printf( "us usu�rios, por�m N�O POSSUI NENHUMA GARANTIA, EXPL�CITA OU IMPL�-\n" );
      printf( "CITA, COMERCIAL OU DE ATENDIMENTO A UMA DETERMINADA FINALIDADE.\n" );
      printf( "Consulte a Licen�a P�blica Geral GNU.\n" );
      
      exit( 0 );
   }
   
   /* Caso o parametro passado nao seja um parametro especial, este
         so pode ser o caminho do arquivo com o codigo-fonte.       */
   if ( ( sourceCode = fopen( *( argv + 1 ), "r" ) ) == NULL ) {
      /* Erro na abertura do arquivo. */
      printf( "AL : O arquivo n�o p�de ser aberto.\n" );
      printf( "\tDigite \"al --ajuda\" para obter ajuda.\n" );
      
      exit( 1 );
   }
   
   /* Arquivo aberto com sucesso. Aqui inicia-se a analise lexica. */
   else {
      /* A implementacao das tabelas do analisador eh feita utilizando-se
            o conceito de Filas.                                          */
      Queue symbolTable, /* A tabela de simbolos -essencial para o processo
                               de compilacao                                */
            tokensTable, /* Tabela excedente, para armazenar os tokens do co-
                               digo-fonte que NAO entrarem na tabela de sim-
                               bolos, apenas para fins de exibicao para o u-
                               suario -NAO faz parte de um analisador lexico. */
            errorsTable; /* Tabela excedente, que armazena os tokens inv�lidos */
      
      char al, /* Armazena o resultado da analise lexica */
           stop; /* Para fazer a parada, usando scanf */
      
      /* Verificando se a ultima linha do codigo-fonte foi deixada em branco */
      if ( verLastLine( sourceCode ) )
         /* A ultima linha PODE NAO estar em branco */
         /* Mensagem de aviso na tela */
         printf( "AL: A �ltima linha do c�digo-fonte PODE N�O estar em branco.\n" );
      
      /* Criando as tabelas na memoria */
      newQueue( &symbolTable );
      newQueue( &tokensTable );
      newQueue( &errorsTable );
      
      /* Realizando a analise lexica */
      al = lexicalScanner( sourceCode, &symbolTable, &tokensTable, &errorsTable );
      
      /* Ordenando a tabela de simbolos pelo campo valor */
      selectionSort( &symbolTable );
      
      /* Iniciando a impressao das tabelas geradas */
      printf( "\nAnalisador L�xico - [Impress�o das tabelas geradas]\n" );
      printf( "\nOs campos que ser�o mostrados seguem a ordem:\n" );
      printf( "< TOKEN; CLASSE; VALOR; (LINHA,COLUNA)>\n\n" );
      printf( "Tabela no. 1: Tabela de erros. Armazena os erros encontrados.\n" );
      printf( "\tPressione <ENTER> para iniciar a impress�o...\n\n" );
      scanf( "%1c", &stop ); /* Dando uma pausa para o usuario */
      
      /* Verificando se a tabela estah vazia */
      if ( ! printQueueErrorsTable( &errorsTable ) )
         printf( "AL: Fim da tabela de erros.\n" );
      else printf( "AL: A tabela de erros est� vazia.\n" );
      
      printf( "\nTabela no. 2: Tabela de tokens. Armazena os tokens encontrados.\n" );
      printf( "\tPressione <ENTER> para iniciar a impress�o...\n\n" );
      scanf( "%1c", &stop ); /* Dando uma pausa para o usuario */
      
      /* Verificando se a tabela estah vazia */
      if ( ! printQueueTokensTable( &tokensTable ) )
         printf( "AL: Fim da tabela de tokens.\n" );
      else printf( "AL: A tabela de tokens est� vazia.\n" );
      
      printf( "\nTabela no. 3: Tabela de s�mbolos. Armazena os identificadores encontrados.\n" );
      printf( "\tPressione <ENTER> para iniciar a impress�o...\n\n" );
      scanf( "%1c", &stop ); /* Dando uma pausa para o usuario */
      
      /* Verificando se a tabela estah vazia */
      if ( ! printQueueSymbolTable( &symbolTable ) )
         printf( "AL: Fim da tabela de s�mbolos.\n" );
      else printf( "AL: A tabela de s�mbolos est� vazia.\n" );
      
      /* Finalizando a impressao */
      printf( "\nAL: Fim da impress�o das tabelas. " );
      ( ! al ) ? printf( "N�o foram reportados erros l�xicos.\n"):
                 printf( "Foram reportados erros l�xicos.\n" );
      
      /* Fechando o arquivo e finalizando o programa */
      close( sourceCode );
      return 0;
   } /* else */
} /* main */
