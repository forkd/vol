/**********************************************************************************
   NOME: al.c
 
   DESCRIÇÃO
   Analisador lexico da linguagem Pascal.
 
   DEPENDÊNCIAS
   Necessita do código-fonte pronto (digitado em qualquer editor de textos raso),
      da biblioteca de tipos abstratos libabstype.h -para implementação da tabela
      de simbolos- e da biblioteca libal.h.
   
   AUTOR
   José Lopes de Oliveira Júnior
   
   CONTATO
   jlojunior@gmail.com
***********************************************************************************/

/* Bibliotecas importadas */
#include <stdio.h>
#include "libal.h" /* Inclui libabstype.h */

/**********************************************************************************
   NOME: printQueueErrorsTable()
   
   DESCRIÇÃO
   Imprime a tabela de erros na tela.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para a fila.
   
   RETORNO
   Retorna 0, caso a operação tenha sido realizada com sucesso;
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
   
   DESCRIÇÃO
   Imprime a tabela de tokens na tela.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para a fila.
   
   RETORNO
   Retorna 0, caso a operação tenha sido realizada com sucesso;
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
   
   DESCRIÇÃO
   Imprime a tabela de símbolos na tela.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para a fila.
   
   RETORNO
   Retorna 0, caso a operação tenha sido realizada com sucesso;
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
   Função principal do programa.
   
   PARAMETROS
   int argc : Contador de argumentos.
   char *argv[] : Matriz que armazena os argumentos.
   
   RETORNO
   Retorna 0 caso não haja nenhum erro, ou um valor diferente em caso contrário.
**********************************************************************************/
int main ( int argc, char *argv[] )
{
   FILE *sourceCode; /* O ponteiro para o arquivo com o codigo-fonte. */
   
   /* Verificando a quantidade de parametros passados */
   if ( argc < 2 ) { /* Faltam paramentros */
      printf( "AL : Falta um parâmetro.\n" );
      printf( "\tDigite \"al --ajuda\" para obter ajuda.\n" );
      exit( 1 );
   }
   
   if ( argc > 2 ) { /* Parametros excessivos */
      printf( "AL : Excesso de parâmetros\n" );
      printf( "\tDigite \"al --ajuda\" para obter ajuda.\n" );
      exit( 1 );
   }
   
   /* Numero de parametros OK - Verifica se o parametro
         passado eh um parametro especial.              */
   if ( ( ! strcmp( *( argv + 1 ), "--ajuda" ) ) || 
      ( ! strcmp( *( argv + 1 ), "-a" ) ) ) { /* Pedido de ajuda */
      printf( "Uso: al ARQUIVO\n" );
      printf( "\tonde: ARQUIVO é o caminho do arquivo com o\n" );
      printf( "\t   código-fonte a ser analisado.\n" );
      printf( "ou   al [opções]\n" );
      printf( "Realiza a análise léxica da linguagem pascal.\n" );
      printf( "opções:\n" );
      printf( "\t--ajuda, -a     Mostra esta ajuda e sai.\n" );
      printf( "\t--versao, -v    Mostra as notas da versão e sai.\n" );
      
      exit( 0 );
   }
   
   if ( ( ! strcmp( *( argv + 1 ), "--versao" ) ) || 
      ( ! strcmp( *( argv + 1 ), "-v" ) ) ) { /* Notas da versao */
      printf( "\tAL ( Analisador Léxico ) 0.5\n" );
      printf( "Escrito por José Lopes de Oliveira Júnior. " );
      printf( "<jlojunior@gmail.com>\n\n" );
      printf( "Copyright (C) 2006.\n" );
      
      printf( "\tEste programa é um software de livre distribuição, que pode\n" ); 
      printf( "ser copiado e distribuído sob os termos da Licença Geral GNU, con-\n" );
      printf( "forme publicada pela Free Software Foundation, versão 2 da licen-\n" );
      printf( "ça, ou (a critério do autor) qualquer versão posterior.\n" );
      printf( "\tEste programa é distribuído na expectativa de ser útil aos se-\n" );
      printf( "us usuários, porém NÃO POSSUI NENHUMA GARANTIA, EXPLÍCITA OU IMPLÍ-\n" );
      printf( "CITA, COMERCIAL OU DE ATENDIMENTO A UMA DETERMINADA FINALIDADE.\n" );
      printf( "Consulte a Licença Pública Geral GNU.\n" );
      
      exit( 0 );
   }
   
   /* Caso o parametro passado nao seja um parametro especial, este
         so pode ser o caminho do arquivo com o codigo-fonte.       */
   if ( ( sourceCode = fopen( *( argv + 1 ), "r" ) ) == NULL ) {
      /* Erro na abertura do arquivo. */
      printf( "AL : O arquivo não pôde ser aberto.\n" );
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
            errorsTable; /* Tabela excedente, que armazena os tokens inválidos */
      
      char al, /* Armazena o resultado da analise lexica */
           stop; /* Para fazer a parada, usando scanf */
      
      /* Verificando se a ultima linha do codigo-fonte foi deixada em branco */
      if ( verLastLine( sourceCode ) )
         /* A ultima linha PODE NAO estar em branco */
         /* Mensagem de aviso na tela */
         printf( "AL: A última linha do código-fonte PODE NÃO estar em branco.\n" );
      
      /* Criando as tabelas na memoria */
      newQueue( &symbolTable );
      newQueue( &tokensTable );
      newQueue( &errorsTable );
      
      /* Realizando a analise lexica */
      al = lexicalScanner( sourceCode, &symbolTable, &tokensTable, &errorsTable );
      
      /* Ordenando a tabela de simbolos pelo campo valor */
      selectionSort( &symbolTable );
      
      /* Iniciando a impressao das tabelas geradas */
      printf( "\nAnalisador Léxico - [Impressão das tabelas geradas]\n" );
      printf( "\nOs campos que serão mostrados seguem a ordem:\n" );
      printf( "< TOKEN; CLASSE; VALOR; (LINHA,COLUNA)>\n\n" );
      printf( "Tabela no. 1: Tabela de erros. Armazena os erros encontrados.\n" );
      printf( "\tPressione <ENTER> para iniciar a impressão...\n\n" );
      scanf( "%1c", &stop ); /* Dando uma pausa para o usuario */
      
      /* Verificando se a tabela estah vazia */
      if ( ! printQueueErrorsTable( &errorsTable ) )
         printf( "AL: Fim da tabela de erros.\n" );
      else printf( "AL: A tabela de erros está vazia.\n" );
      
      printf( "\nTabela no. 2: Tabela de tokens. Armazena os tokens encontrados.\n" );
      printf( "\tPressione <ENTER> para iniciar a impressão...\n\n" );
      scanf( "%1c", &stop ); /* Dando uma pausa para o usuario */
      
      /* Verificando se a tabela estah vazia */
      if ( ! printQueueTokensTable( &tokensTable ) )
         printf( "AL: Fim da tabela de tokens.\n" );
      else printf( "AL: A tabela de tokens está vazia.\n" );
      
      printf( "\nTabela no. 3: Tabela de símbolos. Armazena os identificadores encontrados.\n" );
      printf( "\tPressione <ENTER> para iniciar a impressão...\n\n" );
      scanf( "%1c", &stop ); /* Dando uma pausa para o usuario */
      
      /* Verificando se a tabela estah vazia */
      if ( ! printQueueSymbolTable( &symbolTable ) )
         printf( "AL: Fim da tabela de símbolos.\n" );
      else printf( "AL: A tabela de símbolos está vazia.\n" );
      
      /* Finalizando a impressao */
      printf( "\nAL: Fim da impressão das tabelas. " );
      ( ! al ) ? printf( "Não foram reportados erros léxicos.\n"):
                 printf( "Foram reportados erros léxicos.\n" );
      
      /* Fechando o arquivo e finalizando o programa */
      close( sourceCode );
      return 0;
   } /* else */
} /* main */
