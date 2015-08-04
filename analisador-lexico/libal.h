/**********************************************************************************
   NOME: libal.h
 
   DESCRIÇÃO
   Biblioteca do programa al (analisador léxico) responsável por implementar as
      funções de análise -a principal parte do programa.
 
   DEPENDÊNCIAS
   Necessita do código-fonte pronto (digitado em qualquer editor de textos raso),
      da biblioteca de tipos abstratos libabstype.h -para implementação da tabela
      de simbolos- e da biblioteca libal.h.
   
   OBSERVAÇÃO
   Para o correto funcionamento da função "analiseLexica", o arquivo texto com o
      código-fonte DEVE possuir uma linha em branco ao seu final.
   Caso esta orientação não seja seguida, a saída gerada pela função é imprevisi-
      vel. Em testes realizados, a última linha válida do arquivo com o códio-fon-
      te era repetida, no caso de não se deixar uma linha em branco no fim
      do arquivo.
   
   AUTOR
   José Lopes de Oliveira Júnior
   
   CONTATO
   jlojunior@gmail.com
***********************************************************************************/

/* Bibliotecas importadas */
#include <ctype.h>
#include <stdio.h>
#include "libabstype.h"

/* CONSTANTES */
/* O tamanho da maior palavra reservada */
#define RESWORDSIZE  25

/* O tamanho maximo de uma linha lida do codigo-fonte */
#define LINESIZE     200

/* Aspas simples e duplas */
#define SINGLEQUOTES 39
#define DOUBLEQUOTES 34

/**********************************************************************************
   NOME: verLastLine()
   
   DESCRIÇÃO
   Verifica se a última linha do código-fonte foi deixada em branco.
   
   PARÂMETROS
   FILE *sc : Ponteiro para o código-fonte.
   
   RETORNO
   Retorna 0, caso a última linha esteja em branco, ou 1 em caso contrário.
**********************************************************************************/
int verLastLine ( FILE *sc )
{
   char line[ LINESIZE ]; /* Para armazenar as linhas */
   
   /* Percorre o codigo-fonte ateh o fim, pegando cada linha */
   while ( !feof( sc ) )
      fgets( line, ( LINESIZE -2 ), sc );
   
   /* Rebobinando o codigo-fonte */
   rewind( sc );
   
   /* Verifica se a ultima linha estah em branco e gera o retorno */
   if ( strlen( line ) <= 1 ) return 0;
   else return 1;
} /* verLastLine */

/**********************************************************************************
   NOME: cleanItem()
   
   DESCRIÇÃO
   Limpa um item, colocando seus valores padrões.
   
   PARÂMETROS
   Item *item : Ponteiro para o item a ser limpo.
   
   RETORNO
   Retorna o item limpo em *item.
**********************************************************************************/
void cleanItem ( Item *item )
{
   strcpy( item -> token, "\0" );
   strcpy( item -> class, "\0" );
   
   item -> value = 0;
   
   item -> coOrdinate.line = 0;
   item -> coOrdinate.column = 0;
} /* cleanItem */

/**********************************************************************************
   NOME: action1()
   
   DESCRIÇÃO
   Realiza uma seqüência de ações a serem tomadas, que se repetem no autômato.
   
   PARÂMETROS
   Queue *queue : A tabela onde o item será inserido.
   Item *item : O item auxiliar utilizado pelo analisador léxico.
   char *tkn : O valor para o nome do token.
   char *cls : O valor para a classe do token.
   long val : O valor do item.
   unsigned short int y : A linha do token no código-fonte.
   unsigned char x : A coluna do token no código-fonte.
   char *sta : Para alterar o estado do autômato para o primeiro.

   RETORNO
   -
**********************************************************************************/
void action1 ( Queue *queue, Item *item, char *tkn, char *cls, long val,
   unsigned short int y, unsigned char x, char *sta )
{
   strcpy( item -> token, tkn ); /* Ajustando o nome e a classe do token */
   strcpy( item -> class, cls );
   
   item -> value = val; /* Ajustando o valor */
   
   item -> coOrdinate.line = y; /* Ajustando as coordenadas no codigo-fonte */
   item -> coOrdinate.column = x;
   
   /* Gravando o token na tabela*/
   enqueue( queue, item );
   
   /* Limpando o item... */
   cleanItem( item );
   
   /* Voltando ao estado 1 do automato */
   *sta = 1;
} /* action1 */

/**********************************************************************************
   NOME: concat()
   
   DESCRIÇÃO
   Concatena um caractere no final de uma String.
   
   PARÂMETROS
   char *str : Um ponteiro para a String.
   char ch : O caractere a ser concatenado.
   
   RETORNO
   ch é concatenado na última posição da String apontada por *str.
**********************************************************************************/
void concat ( char *str, char ch ) {
   register int i = strlen( str ); /* Armazena o tamanho atual da String */
   
   *( str + i ) = ch; /* Adicionando o caractere no fim da String */
   *( str + ( i + 1 ) ) = '\0'; /* Marcando o novo final da String */
} /* concat */

/**********************************************************************************
   NOME: isHex()
   
   DESCRIÇÃO
   Verifica se um caractere é válido para a notação hexadecimal [0..9] ou [a..F].
   
   PARÂMETROS
   char c : O caracter a ser avaliado.
   
   RETORNO
   Retorna 1 em caso positivo ou 0 em caso negativo.
**********************************************************************************/
char isHex ( char c )
{
   return ( ( isdigit( c ) ) || ( c == 'a') || ( c == 'A') || ( c == 'b') ||
      ( c == 'B') || ( c == 'c') || ( c == 'C') || ( c == 'd') || ( c == 'D') ||
      ( c == 'e') || ( c == 'E') || ( c == 'f') || ( c == 'F') );
} /* isHex */

/**********************************************************************************
   NOME: isLetter()
   
   DESCRIÇÃO
   Verifica se um caractere é uma letra ou underscore '_'.
   
   PARÂMETROS
   char c : O caracter a ser avaliado.
   
   RETORNO
   Retorna 1 em caso positivo ou 0 em caso negativo.
**********************************************************************************/
char isLetter ( char c )
{
   return ( ( isalpha( c ) ) || ( c == '_' ) );
} /* isLetter */

/**********************************************************************************
   NOME: toLowerCase()
   
   DESCRIÇÃO
   Converte todos os caracteres de uma String para letras minúsculas.
   
   PARÂMETROS
   const char *str1 : Um ponteiro para a String de origem.
   char *str2 : Um ponteiro para a String de destino.
   
   RETORNO
   *str2 tem seu valor alterado para a representação em letras minúsculas de str1.
**********************************************************************************/
void toLowerCase ( const char *str1, char *str2 )
{
   register int i = 0; /* Para varrer *str1 */
   
   *( str2 + 0 ) = '\0'; /* Limpando *str2 */
   
   /* Varrendo *str1 e criando *str2 */
   for (; i < strlen( str1 ); i++ )
      *( str2 + i ) = tolower( *( str1 + i ) );
   
   *( str2 + i ) = '\0'; /* Adicionando o caractere nulo no final de *str2 */
} /* toLowerCase */

/**********************************************************************************
   NOME: isInQueue()
   
   DESCRIÇÃO
   Verifica se um token está na fila.
   
   PARÂMETROS
   Queue *queue : O ponteiro para a fila.
   char *tkn : O ponteiro para o token a ser analisado.
   
   RETORNO
   Retorna -1 caso não haja ocorrência de *tkn em *queue, ou o valor de *tkn na
      fila em caso contrário.
**********************************************************************************/
long isInQueue ( Queue *queue, char *tkn )
{
   /* Para armazenar os tokens em minusculo - Para grarantir que NAO eh sen-
         sivel ao caso.                                                      */
   char strAux1[ ITEMTOKENSIZE ], strAux2[ ITEMTOKENSIZE ];
   
   toLowerCase( tkn, strAux2 ); /* Convertendo o token passado para minusculo */
   
   /* Verificando se a fila estah vazia */
   if ( ! queueEmpty( queue ) ){
      /* Ponteiro para varrer a fila */
      Pointer aux = queue -> front -> next;
      
      /* Roda enquanto nao atingir o fim da fila ou nao encontrar o token */
      while ( aux != NULL ) {
         /* Convertendo o token da posicao para minusculo */
         toLowerCase( aux -> item.token, strAux1 );
         
         /* Verificando se o token jah foi gravado. Caso tenha sido, retorna-
               se o seu valor.                                                */
         if ( ! strcmp( strAux1, strAux2 ) )
            return ( aux -> item.value ); /* Retornando o valor do token */
         
         aux = aux -> next; /* Incrementando o ponteiro */
      } /* while */
      
      return -1; /* Item nao encontrado */
   }
   else
      /* Fila vazia */
      return -1;
} /* isInQueue */

/**********************************************************************************
   NOME: getTokenClass()
   
   DESCRIÇÃO
   Obtém a classe de um determinado token, a partir de seu número de identificação.
   
   PARÂMETROS
   int index : O número de identificação do token.
   char *class : A classe que será retornada.
   
   RETORNO
   Retorna a classe do token *class -é de extrema que index corresponda SEMPRE a
      uma posição válida.
**********************************************************************************/
void getTokenClass ( int index, char *class )
{
   /* Matriz que guarda a lista com o nome de cada classe */
   /* OBS.: Ao ser adicionado ou exluido algum item, deve-se atualizar o
      primeiro indice da matriz.                                         */
   char TOKENCLASSES[][ ITEMCLASSSIZE ] = {
/*00*/"comando de classe geral",
/*01*/"comando de desvio de fluxo de execução",
/*02*/"comando de iteração",
/*03*/"comando de manipulação de objetos",
/*04*/"comando de manipulação de registros",
/*05*/"comando de seleção",
/*06*/"comando relativo à unidades",
/*07*/"constante numérica",
/*08*/"declaração de variáveis",
/*09*/"delimitador",
/*10*/"delimitador de bloco de comandos",
/*11*/"delimitador de comando",
/*12*/"delimitador de comentários",
/*13*/"delimitador de parâmetros",
/*14*/"id",
/*15*/"identificador de anulação de operador",
/*16*/"identificador de caractere ASCII",
/*17*/"identificador de número hexadecimal",
/*18*/"indicador de faixa de valores",
/*19*/"manipulação de ponteiros",
/*20*/"operador aritmético",
/*21*/"operador de atribuição",
/*22*/"operador booleano",
/*23*/"operador lógico",
/*24*/"operador relacional",
/*25*/"programação de baixo nível",
      
/*26*/"caractere inválido",
/*27*/"identificador inválido"
   };
   
   /* Copia a classe do token para a variavel de retorno */
   strcpy( class, *( TOKENCLASSES + index ) );
} /* getTokenClass */

/**********************************************************************************
   NOME: isResWord()
   
   DESCRIÇÃO
   Verifica se um token é, ou não, uma palavra reservada da linguagem.
   
   PARÂMETROS
   const char *token : Ponteiro para o token a ser avaliado.
   char *cToken : Caso seja uma palavra reservada, retorna a classe. Caso contrá-
      rio, retorna uma string nula.
   
   RETORNO
   Retorna 1 se o token for uma palavra reservada ou 0 em caso contrario.
**********************************************************************************/
char isResWord ( const char *token, char *cToken ) {
   /* Matriz que guarda a lista de palavras reservadas */
   char RESERVEDWORDS[][ RESWORDSIZE ] = {
      /* Delimitadores de bloco de comandos [ 0-1 ] */
      "begin","end",
      
      /* Declaracao de variaveis [ 2-18 ] */
      "var","string","function","procedure","const","type","array","record",
      "set","file","uses","program","unit","label","packed","library",
      "exports",
      
      /* Comandos de iteracao [ 19-24 ] */
      "for","to","downto","repeat","until","while",
      
      /* Comandos de selecao [ 25-28 ] */
      "if","then","else","case",
      
      /* Operadores booleanos [ 29-32 ] */
      "not","and","or","xor",
      
      /* Operadores aritmeticos [ 33-34 ] */
      "mod","div",
      
      /* Operador relacional [ 35 ] */
      "in",
      
      /* Operadores logicos [ 36-37 ] */
      "shl","shr",
      
      /* Manipulacao de ponteiros [ 38 ] */
      "nil",
      
      /* Comandos de classes diversas [ 39-40 ] */
      "of","do",
      
      /* Comandos usados em unidades [ 41-42 ] */
      "implementation","interface",
      
      /* Comando de manipulacao de registros [ 43 ] */
      "with",
      
      /* Comando de desvio de fluxo execucao [ 44 ] */
      "goto",
      
      /* Comandos de manipulacao de objetos [ 45-48 ] */
      "constructor","destructor","inherited","object",
      
      /* Programacao de baixo nivel [ 49-50 ] */
      "asm","inline"
   };
   
   register char i; /* Variavel de controle da iteracao */
   
   /* Para armazenar a representacao do token em minusculo */
   char auxStr[ ITEMTOKENSIZE ];
   
   /* Gerando a representacao em minusculo do token */
   /* GARANTE QUE A ANALISE NAO SERAH SENSIVEL AO CASO */
   toLowerCase( token, auxStr );
      
   *( cToken + 0 ) = '\0'; /* Anulando a classe do token */
   
   /* Varrendo a matriz de palavras reservadas para verificar se
         o token faz parte dela. Caso faca, a sua classe eh de-
         finida.                                                 */
   for ( i = 0; i <= 50; i++ )
      
      /* Testando se eh palavra reservada*/
      if ( ! strcmp( auxStr, *( RESERVEDWORDS + i ) ) ) {
         
         /* Definindo a classe da palavra reservada */
          switch ( i ) {
            case 0: case 1: 
               getTokenClass( 10, cToken );
               
               break;
               
            case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
               case 10: case 11: case 12: case 13: case 14: case 15:
               case 16: case 17: case 18:
               getTokenClass( 8, cToken );
               
               break;
                     
            case 19: case 20: case 21: case 22: case 23: case 24:
               getTokenClass( 2, cToken );
               
               break;
            
            case 25: case 26: case 27: case 28:
               getTokenClass( 5, cToken );
               
               break;
            
            case 29: case 30: case 31: case 32:
               getTokenClass( 22, cToken );
               
               break;
            
            case 33: case 34:
               getTokenClass( 20, cToken );
               
               break;
            
            case 35:
               getTokenClass( 24, cToken );
               
               break;
            
            case 36: case 37:
               getTokenClass( 23, cToken );
               
               break;
            
            case 38:
               getTokenClass( 19, cToken );
               
               break;
            
            case 39: case 40:
               getTokenClass( 0, cToken );
               
               break;
            
            case 41: case 42:
               getTokenClass( 6, cToken );
               
               break;
            
            case 43:
               getTokenClass( 4, cToken );
               
               break;
            
            case 44:
               getTokenClass( 1, cToken );
               
               break;
            
            case 45: case 46: case 47: case 48:
               getTokenClass( 3, cToken );
               
               break;
            
            case 49: case 50:
               getTokenClass( 25, cToken );
               
               break;
         } /* switch */
         
         return 1; /* Eh palavra reservada */
      } /* if */
      
   return 0; /* Nao eh palavra reservada */
} /* isResWord */

/**********************************************************************************
   NOME: lexicalScanner()
   
   DESCRIÇÃO
   Esta é a funcao que realizará a análise léxica. É a principal função desta bi-
      blioteca.
   
   PARÂMETROS
   FILE *sCode : O ponteiro para o arquivo com o código-fonte.
   Queue *sTable : Ponteiro para a tabela de símbolos.
   Queue *tTable : Ponteiro para a tabela de tokens que nao fazem parte da tabela
      de símbolos -tabela de tokens.
   Queue *eTable : Ponteiro para a tabela de erros, que armazena os tokens inváli-
      dos.
   
   RETORNO
   Retorna 0 caso a análise não tenha produzido erro;
          -1 caso o erro tenha sido na manipulação do arquivo;
           1 caso haja um erro léxico no código-fonte.
**********************************************************************************/
int lexicalScanner ( FILE *sCode, Queue *sTable, Queue *tTable, Queue *eTable )
{
   char chRead, /* O ultimo caractere lido */
        state = 1, /* O estado em que se encontra o analisador lexico */
        atualLine[ LINESIZE ], /* Armazena a ultima linha lida do arquivo */
        ret = 0; /* O retorno da funcao */
   
   /* Armazena o valor mais alto de um item da tabela de simbolos */
    long maxValue = 0;
   
   /* Informacoes de posicionamento no arquivo - linha x coluna */
   CoOrdinate cFile;
   
   /* Informacoes dos tokens */
   Item item;
   
   /* Armazena o comprimento da linha, para evitar calculos repetidos */
   int lineSize;
   
   /* Inicializando variaveis */
   /* Inicializando as coordenadas do arquivo */
   cFile.line = 0;
   
   /* Inicializando os valores do item */
   strcpy( item.token, "\0" );
   strcpy( item.class, "\0" );
   item.value = 0;
   item.coOrdinate.line = 0;
   item.coOrdinate.column = 0;
   
   /* Laco que varre o arquivo do inicio ao fim, em linhas */
   while ( ! feof( sCode ) ) {
      /* Lendo a linha atual do arquivo com o codigo-fonte e
            armazenando-a em atualLine.                      */
      fgets( atualLine, ( LINESIZE -2 ), sCode );
      
      lineSize = strlen( atualLine ); /* Obtendo o comprimento da linha */
      
      /* Laco que varre a linha atual */
      for ( cFile.column = 0; cFile.column < lineSize; cFile.column++ ) {
         /* Lendo o caractere da String atualLine e o armazenando em chLido */
         chRead = *( atualLine + cFile.column );
         
         /* A acao a ser tomada depende do estado em que o algoritmo
               se encontra e do caractere lido.                      */
         switch ( state ) {
            case 1: /* Estado inicial */
               if ( isspace( chRead ) ) { /* Consome espacos */
                  ++cFile.column; /* Avancando a coluna */
                  
                  /* Roda ateh o fim da linha ou enquanto ler espacos */
                  while ( ( cFile.column < lineSize ) &&
                     ( isspace( *( atualLine + cFile.column ) ) ) )
                     ++cFile.column;
                  
                  /* Caso nao seja o fim da linha, um caractere jah
                         foi lido, portando deve ser relido         */
                  if ( cFile.column < lineSize )
                     --cFile.column;
               }
               
               /* Encontrado ; */
               else if ( chRead == ';' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 2;
               }
               
               /* Inicio de identificador encontrado */
               else if ( isLetter( chRead ) ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Alterando o estado */
                  state = 3;
               }
               
               /* Inicio de numero encontrado */
               else if ( isdigit( chRead ) ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Alterando o estado */
                  state = 4;
               }
               
               /* Encontrado . */
               else if ( chRead == '.' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Alterando o estado */
                  state = 11;
               }
               
               /* Encontrado = */
               else if ( chRead == '=' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 13;
               }
               
               /* Encontrado < */
               else if ( chRead == '<' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Alterando o estado */
                  state = 14;
               }
               
               /* Encontrado > */
               else if ( chRead == '>' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Alterando o estado */
                  state = 17;
               }
               
               /* Encontrado : */
               else if ( chRead == ':' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Alterando o estado */
                  state = 19;
               }
               
               /* Encontrado ; */
               else if ( chRead == ',' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 21;
               }
               
               /* Encontrado ' */
               else if ( chRead == '\'' ) {
                  /* Completando informacoes sobre o token */
                  strcpy( item.token, "\'" );
                  getTokenClass( 9, item.class );
                  item.value = -1;
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Gravando o token na fila */
                  enqueue( tTable, &item );
                  
                  /* Limpando o item */
                  cleanItem( &item );
                  
                  /* Alterando o estado */
                  state = 22;
               }
               
               /* Encontrado " */
               else if ( chRead == '\"' ) {
                  /* Completando informacoes sobre o token */
                  strcpy( item.token, "\"" );
                  getTokenClass( 9, item.class );
                  item.value = -1;
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Gravando o token na fila */
                  enqueue( tTable, &item );
                  
                  /* Limpando o item */
                  cleanItem( &item );
                  
                  /* Alterando o estado */
                  state = 24;
               }
               
               /* Encontrado +,-,* ou / */
               else if ( ( chRead == '+' ) || ( chRead == '-' ) ||
                  ( chRead == '*' ) || ( chRead == '/' ) ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 26;
               }
               
               /* Encontrado ( */
               else if ( chRead == '(' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Alterando o estado */
                  state = 27;
               }
               
               /* Encontrado [,] ou ) */
               else if ( ( chRead == '[' ) || ( chRead == ']' ) ||
                  ( chRead == ')' ) ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 31;
               }
               
               /* Encontrado { */
               else if ( chRead == '{' ) {
                  /* Completando informacoes sobre o token */
                  strcpy( item.token, "{" );
                  getTokenClass( 12, item.class );
                  item.value = -1;
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Gravando o token na fila */
                  enqueue( tTable, &item );
                  
                  /* Limpando o item */
                  cleanItem( &item );
                  
                  /* Alterando o estado */
                  state = 32;
               }
               
               /* Encontrado # */
               else if ( chRead == '#' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 34;
               }
               
               /* Encontrado @ ou ^ */
               else if ( ( chRead == '@' ) || ( chRead == '^' ) ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 35;
               }
               
               /* Encontrado & */
               else if ( chRead == '&' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 36;
               }
               
               /* Encontrado $ */
               else if ( chRead == '$' ) {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                                    
                  /* Alterando o estado */
                  state = 37;
               }
               
               /* Caractere nao reconhecido encontrado */
               else {
                  /* Concatenando o caractere encontrado no token */
                  concat( item.token, chRead );
                  
                  /* Armazenando as coordenadas do token no codigo-fonte */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 39;
               }
               break;
            
            case 2: /* Estado final - ; */
               /* Completando as informacoes sobre o token */
               getTokenClass( 11 ,item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 3: /* Estado final - identificadores */
               if ( ( isLetter( chRead ) ) || ( isdigit( chRead ) ) )
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
               
               else {
                  /* Verificando se o token eh uma palavra reservada */
                  if ( isResWord( item.token, item.class ) ) {
                     /* Eh uma palavra reservada */
                     
                     /* Realizando a acao padrao */
                     action1( tTable, &item, item.token, item.class,
                        -1, item.coOrdinate.line, item.coOrdinate.column,
                        &state );
                  }
                  else {
                     /* NAO eh uma palavra reservada */
                     
                     /* Verificando se o identificador jah foi gravado */
                     long saved = isInQueue( sTable, item.token );
                     
                     if ( saved == -1 ) { /* NAO foi gravado */
                        /* Completando informacoes sobre o token */
                        getTokenClass( 14, item.class );
                        item.value = maxValue;
                        
                        /* Inserindo na tabela de simbolos */
                        enqueue( sTable, &item );
                        
                        /* Incrementando o valor maximo */
                        ++maxValue;
                     }
                     else { /* Jah foi gravado */
                        /* Completando informacoes sobre o token */
                        getTokenClass( 14, item.class );
                        item.value = saved;
                        
                        /* Inserindo na tabela de simbolos */
                        enqueue( sTable, &item );
                     }
                  } /* else */
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Limpando o item lido */
                  cleanItem( &item );
                  
                  /* Alterando o estado */
                  state = 1;
               } /* else */
               break;
            
            case 4: /* Estado final - numeros inteiros */
               if ( isdigit( chRead ) ) /* Digito lido */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
               
               else if ( chRead == '.' ) { /* Ponto lido */
                 /* Concatenando o caractere lido no token */
                 concat( item.token, chRead );
                 
                 /* Alterando o estado */
                 state = 5;
               }
               
               else if ( isalpha( chRead ) ) { /* Letra lida */
                  /* Letras validas */
                  if ( ( chRead == 'e' ) || ( chRead == 'E' ) ) {
                     /* Concatenando o caractere lido no token */
                     concat( item.token, chRead );
                     
                     /* Alterando o estado */
                     state = 7;
                  }
                  else { /* ERRO */
                     /* Concatenando o caractere lido no token */
                     concat( item.token, chRead );
                     
                     /* Alterando o estado */
                     state = 10;
                  }
               } /* else if */
               
               else { /* Numero totalmente lido */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 7, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               } /* else */
               break;
            
            case 5: /* Lendo numero . */
               if ( isdigit( chRead ) ) { /* Digito lido */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 6;
               }
               else if ( chRead == '.' ) { /* Encontrado .. */
                  /* Removendo o ultimo caractere do token - . */
                  *( item.token + ( strlen( item.token ) -1 ) ) = '\0';
                  
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 7, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Adicionando o ponto retirado no token e o ponto lido */
                  strcpy( item.token, ".." );
                  
                  /* Ajustando as coordenadas do token */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column - 1;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Indo para o estado do token .. */
                  state = 12;
               }
               
               /* Numero ponto letra : ERRO */
               else if ( isLetter( chRead ) ) {
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 10;
               }
               
               else { /* Erro */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 27, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( eTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Garantindo retorno de erro */
                  ret = 1;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 6: /* Estado final - numeros reais */
               if ( isdigit( chRead ) ) /* Digito lido */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
               
               else if ( isLetter( chRead ) ) { /* Letra lida */
                  /* Letras validas */
                  if ( ( chRead == 'e' ) || ( chRead == 'E' ) ) {
                     /* Concatenando o caractere lido no token */
                     concat( item.token, chRead );
                     
                     /* Alterando o estado */
                     state = 7;
                  }
                  else { /* ERRO */
                     /* Concatenando o caractere lido no token */
                     concat( item.token, chRead );
                     
                     /* Alterando o estado */
                     state = 10;
                  }
               } /* else if */
               
               else {
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 7, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 7: /* Estado final - numero em notacao E */
               if ( isdigit( chRead ) ) { /* Digito lido */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 9;
               }
               
               /* Sinal lido */
               else if ( ( chRead == '+' ) || ( chRead == '-' ) ) {
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 8;
               }
               
               else if ( isLetter( chRead ) ) { /* Letra lida */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 10;
               }
               
               else { /* ERRO */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 27, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( eTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 8: /* Estado final - numeros em notacao E com sinal */
               if ( isdigit( chRead ) ) {
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 9;
               }
               
               else if ( isLetter( chRead ) ) { /* Letra lida */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 10;
               }
               
               else {
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 27, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               } /* else */
               break;
            
            case 9: /* Estado final - numeros em notacao E */
               if ( isdigit( chRead ) )
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
               
               else if ( isLetter( chRead ) ) { /* Letra lida */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 10;
               }
               
               else { /* Numero totalmente lido */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 7, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 10: /* Estado final - numero seguido de letra - ERRO */
               if ( ( isLetter( chRead ) ) || ( isdigit( chRead ) ) ) {
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
               }
               else {
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 27, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( eTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Retornando erro */
                  ret = 1;
               }
               break;
            
            case 11: /* Estado final - . */
               if ( chRead == '.' ) { /* .. lido */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 12;
               }
               else {
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 9, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 12: /* Estado final - .. */
               /* Completando as informacoes sobre o token */
               getTokenClass( 18, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 13: /* Estado final - = */
               /* Completando as informacoes sobre o token */
               getTokenClass( 24, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 14: /* Estado final - < */
               if ( chRead == '=' ) { /* Lido <= */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 15;
               }
               else if ( chRead == '>' ) { /* Lido <> */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 16;
               }
               else { /* Lido < */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 24, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 15: /* Estado final - <= */
               /* Completando as informacoes sobre o token */
               getTokenClass( 24, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 16: /* Estado final - <> */
               /* Completando as informacoes sobre o token */
               getTokenClass( 24, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 17: /* Estado final - > */
               if ( chRead == '=' ) {
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 18;
               }
               else { /* Lido > */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 24, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 18: /* Estado final - >= */
               /* Completando as informacoes sobre o token */
               getTokenClass( 24, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 19: /* Estado final - : */
               if ( chRead == '=' ) { /* Lido := */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 20;
               }
               else { /* Lido : */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 9, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 20: /* Estado final - := */
               /* Completando as informacoes sobre o token */
               getTokenClass( 21, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 21: /* Estado final - , */
               /* Completando as informacoes sobre o token */
               getTokenClass( 9, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 22: /* Dentro de ' */
               if ( chRead != '\'' ) { /* Consome a constante literal */
                  ++cFile.column; /* Avancando a coluna */
                  
                  /* Roda ateh o fim da linha ou
                        ateh o fim da constante  */
                  while ( ( cFile.column < lineSize ) &&
                     ( *( atualLine + cFile.column ) != '\'' ) )
                     ++cFile.column;
                  
                  /* Caso nao seja o fim da linha, o fim
                        do comentario foi encontrado.    */
                  if ( cFile.column < lineSize ) {
                     /* Concatenando o caractere lido no token */
                     concat( item.token, *( atualLine + cFile.column ) );
                     
                     /* Ajustando as coordenadas */
                     item.coOrdinate.line = cFile.line;
                     item.coOrdinate.column = cFile.column;
                     
                     /* Voltando a coluna, para nao perder caracteres */
                     --cFile.column;
                     
                     /* Alterando o estado */
                     state = 23;
                  } /* if */
               }
               
               else { /* Lido ' */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Ajustando as coordenadas */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 23;
               }
               break;
            
            case 23: /* Estado final - ' */
               /* Completando as informacoes sobre o token */
               getTokenClass( 9, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 24: /* Dentro de " */
               if ( chRead != '\"' ) { /* Consome a constante literal */
                  ++cFile.column; /* Avancando a coluna */
                  
                  /* Roda ateh o fim da linha ou
                        ateh o fim da constante  */
                  while ( ( cFile.column < lineSize ) &&
                     ( *( atualLine + cFile.column ) != '\"' ) )
                     ++cFile.column;
                  
                  /* Caso nao seja o fim da linha, o fim
                        do comentario foi encontrado.    */
                  if ( cFile.column < lineSize ) {
                     /* Concatenando o caractere lido no token */
                     concat( item.token, *( atualLine + cFile.column ) );
                     
                     /* Ajustando as coordenadas */
                     item.coOrdinate.line = cFile.line;
                     item.coOrdinate.column = cFile.column;
                     
                     /* Voltando a coluna, para nao perder caracteres */
                     --cFile.column;
                     
                     /* Alterando o estado */
                     state = 25;
                  } /* if */
               }
               
               else { /* Lido ' */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Ajustando as coordenadas */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 25;
               }
               break;
            
            case 25: /* Estado final - " */
               /* Completando as informacoes sobre o token */
               getTokenClass( 9, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 26: /* Estado final - +-* / */
               /* Completando as informacoes sobre o token */
               getTokenClass( 20, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 27: /* Estado final - ( */
               if ( chRead != '*' ) { /* Lido ( */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 13, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               else {  /* Lido (* */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 12, item.class );
                  item.value = -1;
                  
                  /* Gravando o token */
                  enqueue( tTable, &item );
                  
                  /* Limpando o item */
                  cleanItem( &item );
                  
                  /* Alterando o estado */
                  state = 28;
               } /* else */
               break;
            
            case 28:  /* Dentro de (*  */
               if ( chRead != '*' ) { /* Consome comentarios */
                  ++cFile.column; /* Avancando a coluna */
                  
                  /* Roda ateh o fim da linha ou
                        ateh o fim do comentario */
                  while ( ( cFile.column < lineSize ) &&
                     ( *( atualLine + cFile.column ) != '*' ) )
                     ++cFile.column;
                  
                  /* Caso nao seja o fim da linha, o fim
                        do comentario foi encontrado.    */
                  if ( cFile.column < lineSize ) {
                     /* Concatenando o caractere lido no token */
                     concat( item.token, *( atualLine + cFile.column ) );
                     
                     /* Alterando o estado */
                     state = 29;
                  } /* if */
               }
               
               else { /* Possivel fim de comentario encontrado */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 29;
               }
               break;
            
            case 29: /* Lido * dentro de (* */
               if ( chRead == ')' ) { /* Fim de comentario encontrado */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Ajustando as coordenadas */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column - 1;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 30;
               }
               
               else if ( chRead == '*' ) ; /* Consome *s */
               
               else { /* Nao eh fim de comentario */
                  /* Limpando o token */
                  strcpy( item.token, "" );
                  
                  /* Alterando o estado */
                  state = 28;
               }
               break;
            
            case 30: /* Estado final - *) */
               /* Completando as informacoes sobre o token */
               getTokenClass( 12, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 31: /* Estado final - []) */
               /* Completando as informacoes sobre o token */
               getTokenClass( 13, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 32: /* Dentro de { */
               if ( chRead != '}' ) { /* Consome comentarios */
                  ++cFile.column; /* Avancando a coluna */
                  
                  /* Roda ateh o fim da linha ou
                        ateh o fim do comentario */
                  while ( ( cFile.column < lineSize ) &&
                     ( *( atualLine + cFile.column ) != '}' ) )
                     ++cFile.column;
                  
                  /* Caso nao seja o fim da linha, o fim
                        do comentario foi encontrado.    */
                  if ( cFile.column < lineSize ) {
                     /* Concatenando o caractere lido no token */
                     concat( item.token, *( atualLine + cFile.column ) );
                     
                     /* Ajustando as coordenadas */
                     item.coOrdinate.line = cFile.line;
                     item.coOrdinate.column = cFile.column;
                     
                     /* Voltando a coluna, para nao perder caracteres */
                     --cFile.column;
                     
                     /* Alterando o estado */
                     state = 33;
                  } /* if */
               }
               
               else { /* Fim de comentario encontrado */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Ajustando as coordenadas */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
                  
                  /* Alterando o estado */
                  state = 33;
               }
               break;
            
            case 33: /* Estado final - } */
               /* Completando as informacoes sobre o token */
               getTokenClass( 12, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 34: /* Estado final - # */
               /* Completando as informacoes sobre o token */
               getTokenClass( 16, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 35: /* Estado final - @^ */
               /* Completando as informacoes sobre o token */
               getTokenClass( 19, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 36: /* Estado final - & */
               /* Completando as informacoes sobre o token */
               getTokenClass( 15, item.class );
               
               /* Realizando a acao padrao */
               action1( tTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            case 37: /* Estado final - $ */
               if ( isHex( chRead ) ) { /* Constante hexadecimal encontrada */
                  /* Grava-se o $ e inicia a leitura da constante */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 17, item.class );
                  item.value = -1;
                  
                  /* Gravando o item */
                  enqueue( tTable, &item );
                  
                  /* Limpando o item */
                  cleanItem( &item );
                  
                  /* Ajustando as coordenadas */
                  item.coOrdinate.line = cFile.line;
                  item.coOrdinate.column = cFile.column;
                  
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 38;
               }
               else {
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 15, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
               }
               break;
            
            case 38: /* Estado final - [0..9][a..F] */
               if ( isHex( chRead ) ) /* Lendo a constate hexadecimal */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
               
               else if ( isLetter( chRead ) ) { /* ERRO */
                  /* Concatenando o caractere lido no token */
                  concat( item.token, chRead );
                  
                  /* Alterando o estado */
                  state = 10;
               }
               
               else { /* Constante hexadecimal lida */
                  /* Completando as informacoes sobre o token */
                  getTokenClass( 15, item.class );
                  
                  /* Realizando a acao padrao */
                  action1( tTable, &item, item.token, item.class, -1,
                     item.coOrdinate.line, item.coOrdinate.column, &state );
                  
                  /* Voltando a coluna, para nao perder caracteres */
                  --cFile.column;
               }
               break;
            
            case 39: /* Estado final - Caractere desconhecido */
               /* Completando as informacoes sobre o token */
                  getTokenClass( 26, item.class );
               
               /* Realizando a acao padrao */
               action1( eTable, &item, item.token, item.class, -1,
                  item.coOrdinate.line, item.coOrdinate.column, &state );
               break;
            
            default:
               /* Forcando a saida do laco for */
               cFile.column = lineSize;
               
               /* Retornando erro */
               ret = -1;
               break;
         } /* switch*/
      } /* for */
      
      /* Incrementando a linha atual */
      ++cFile.line;
   } /* while */
   
   /* Rebobinando o codigo-fonte */
   rewind( sCode );
   
   /* Retornando o resultado da analise lexica */
   /* -1 - Erro na manipulacao do arquivo. */
   /*  0 - Nao foram encontrados erros.    */
   /*  1 - Erro lexico encontrado.         */
   return ret;
} /* lexicalAnalysis */
