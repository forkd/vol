/**********************************************************************************
   NOME: libabstype.h
   
   DESCRIÇÂO
   Biblioteca que implementa os tipos abstratos de dados Lista, Pilha e Fila, a-
      través da utilização de ponteiros.
   
   REQUISITOS
   Para se utilizar esta biblioteca, deve-se alterar o tipo definido Item, para a
      aplicação específica.
   
   OBSERVAÇÃO
   TODOS os tipos aqui implementados fazem uso de uma célula cabeça que, no caso
      da Lista, é a apontada por first, no caso da Pilha é a apontada por top e,
      no caso da Fila, é a apontada por front. É importante que, caso sejam imple-
      mentadas novas funções para manipular estas estruturas, estas células cabeça
      sejam preservadas ou ignoradas, em caso de listagem da estrutura.
   
   AUTOR
   José Lopes de Oliveira Júnior, baseado no livro "Projeto de algoritmos" de
      Nívio Ziviani.
   
   CONTATO
   jlojunior@gmail.com
***********************************************************************************/

/* Biblioteca necessaria para se utilizar o NULL */
#include <stdlib.h>

/* Definindo constantes */
#define ITEMTOKENSIZE 100
#define ITEMCLASSSIZE 40

/* Definindo as estruturas mais basicas, comuns aos tres tipos */

/* Definicoes do tipo Item, que podem ser alteradas segundo a
      necessidade da aplicacao.                               */
/* Definindo a estrutura de coordenadas - linha x coluna */
typedef struct {
   unsigned short int line;
   unsigned char column;
} CoOrdinate;

/* Definindo a estrutura dos itens a serem armazenados */
typedef struct {
   char token[ ITEMTOKENSIZE ], /* O Token lido */
        class[ ITEMCLASSSIZE ]; /* A classe do token */
   long value; /* A posicao do token na tabela de simbolos */
   CoOrdinate coOrdinate; /* A posicao do token no codigo-fonte */
} Item;
/* Fim das definicoes do tipo Item */

/* Definindo o tipo Pointer, que serah o apontador utilizado */
typedef struct TCell *Pointer;

/* Definindo a estrutura das celulas - dois campos :
      um para armazenar um item e outro um ponteiro-
      estrutura simplesmente encadeada.              */
typedef struct TCell {
   Item item;
   Pointer next;
} Cell;
/* Fim das definicoes basicas */

/* Definindo as estruturas Lista, Pilha e Fila */

/* Estrutura de Listas */
typedef struct {
   Pointer first, last;
} List;

/* Estrutura de Pilhas */
typedef struct {
   Pointer top, bottom;
} Stack;

/* Estrutura de Filas */
typedef struct {
   Pointer front, back;
} Queue;
/* Fim das definicoes dos tipos abstratos */

/* Inicia-se agora a definicao das operacoes mais basicas que podem ser realizadas
      com cada um dos tipos abstratos de dados.                                   */

/* Inicio das operacoes basicas sobre Listas */
/**********************************************************************************
   NOME: newList()
   
   DESCRIÇÃO
   Cria uma lista vazia, ou torna uma lista existente, vazia.
   
   PARÂMETROS
   List *list : Um ponteiro para uma lista.
   
   RETORNO
   Retorna 0, indicando sucesso. Retorna na região de memória apontada por *list,
      a lista criada.
**********************************************************************************/
int newList ( List *list )
{
   /* Alocando espaco em memoria e atribuindo-o ao
         primeiro elemento da Lista.               */
   list -> first = ( Pointer ) malloc( sizeof( Cell ) );
   
   /* Fazendo que o ultimo elemento aponte para o
         mesmo local que o primeiro - Lista Vazia */
   list -> last = list -> first;
   
   /* Fazendo com que o proximo elemento apos o
         primeiro, seja o NULO.                 */
   list -> first -> next = NULL;
   
   return 0; /* Retorno com sucesso */
} /* newList */

/**********************************************************************************
   NOME: listEmpty()
   
   DESCRIÇÃO
   Verifica se uma lista está vazia.
   
   PARÂMETROS
   List *list : Um ponteiro para uma lista.
   
   RETORNO
   Retorna 0, no caso de a lista estar vazia, ou um valor diferente em caso con-
      trário.
**********************************************************************************/
int listEmpty ( List *list )
{
   return ( list -> first == list -> last );
} /* listEmpty */

/**********************************************************************************
   NOME: insert()
   
   DESCRIÇÃO
   Insere um item no final de uma lista.
   
   PARÂMETROS
   List *list : Um ponteiro para uma lista.
   Item *item : O item a ser inserido.
   
   RETORNO
   Retorna 0, no caso de a inserção ter sido feita com sucesso, ou um valor dife-
      rente em caso contrário.
**********************************************************************************/
int insert ( List *list, Item *item )
{
   /* Alocando espaco em memoria e atribuindo-o ao
         proximo elemento apos o ultimo da Lista.  */
   list -> last -> next = ( Pointer ) malloc( sizeof( Cell ) );
   
   /* O ultimo item passa a ser aquele que foi criado */
   list -> last = list -> last -> next;
   
   /* O campo item da ultima celula recebe o
         item passado como parametro.        */
   list -> last -> item = *item;
   
   /* O proximo elemento apos o ultimo eh NULO */
   list -> last -> next = NULL;
   
   /* Operacao realizada com exito */
   return 0;
} /* insert */

/**********************************************************************************
   NOME: delete()
   
   DESCRIÇÃO
   Remove um elemento da Lista - o item a ser removido é o seguinte ao apontado
      pelo ponteiro p.
   
   PARÂMETROS
   List *list : Um ponteiro para uma lista.
   Item *item : Retorna o campo item da célula excluida.
   Pointer p : Um ponteiro para o item a ser excluido.
   
   RETORNO
   Retorna 0, caso a exlusao tenha sido feita com sucesso;
           1, caso a lista esteja vazia ou a posição não exista.
**********************************************************************************/
int delete ( List *list, Item *item, Pointer p )
{
   /* Verificando se a Lista estah vazia e se a posicao existe */
   if ( ( listEmpty( list ) ) || ( p == NULL ) ||
      ( p -> next == NULL ) )
      return 1; /* Lista vazia ou posicao inexistente */
   
   else {
      /* A Lista nao estah vazia e a posicao existe */
      
      /* Um ponteiro auxiliar que aponta para o
            proximo elemento a p.               */
      Pointer aux = p -> next;
      
      /* Pegando o item do elemento a ser excluido */
      *item = aux -> item;
      
      /* Ajustando o ponteiro da celula que p aponta */
      p -> next = aux -> next;
      
      /* Verificando se o elemento a ser excluido
            eh o ultimo da lista.                 */
      if ( p -> next == NULL )
         list -> last = p;
      
      /* Liberando espaco em memoria 
            - excluindo o item       */
      free( aux );
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* delete */

/**********************************************************************************
   NOME: first()
   
   DESCRIÇÃO
   Obtém o primeiro elemento de uma lista.
   
   PARÂMETROS
   List *list : Um ponteiro para uma lista.
   Item *item : O item a ser retornado.
   
   RETORNO
   Retorna um ponteiro para o primeiro elemento da lista, ou NULL, se a lista es-
      tiver vazia. Retorna em *item, o conteúdo do primeiro elemento da lista.
**********************************************************************************/
Pointer first ( List *list, Item *item )
{
   /* Verificando se a lista estah vazia */
   if ( listEmpty( list ) )
      /* Lista vazia - retorna um ponteiro nulo */
      return NULL;
   
   /* A lista NAO estah vazia */
   else {
      *item = list -> first -> next -> item; /* Pegando o conteudo do item */
      return ( list -> first -> next ); /* Retornando o ponteiro */
   } /* else */
} /* first */

/**********************************************************************************
   NOME: last()
   
   DESCRIÇÃO
   Obtém o último elemento de uma lista.
   
   PARÂMETROS
   List *list : Um ponteiro para uma lista.
   Item *item : O item a ser retornado.
   
   RETORNO
   Retorna um ponteiro para o último elemento da lista, ou NULL, se a lista es-
      tiver vazia. Retorna em *item, o conteúdo do último elemento da lista.
**********************************************************************************/
Pointer last ( List *list, Item *item )
{
   /* Verificando se a lista estah vazia */
   if ( listEmpty( list ) )
      /* Lista vazia - retorna um ponteiro nulo */
      return NULL;
   
   /* A lista NAO estah vazia */
   else {
      *item = list -> last -> item; /* Pegando o conteudo do item */
      return ( list -> last ); /* Retornando o ponteiro */
   } /* else */
} /* last */

/**********************************************************************************
   NOME: printList()
   
   DESCRIÇÃO
   Imprime o conteúdo de uma lista na tela - a impressão depende dos campos da
      lista.
   
   PARÂMETROS
   List *list : Um ponteiro para uma lista.
   
   RETORNO
   Retorna 0, caso a operação tenha sido realizada com sucesso;
           1, no caso de a lista estar vazia.
**********************************************************************************/
int printList ( List *list )
{
   /* Verificando se a Lista estah vazia */
   if ( listEmpty( list ) )
      return 1; /* Lista vazia */
   
   else {
      /* A Lista nao estah vazia */
      
      /* Um ponteiro auxiliar para varrer a Lista */
      Pointer aux = list -> first -> next;
      
      /* Imprime enquanto nao chegar ao fim da Lista */
      while ( aux != NULL ) {
         /* Imprimindo... */
         printf( "%2d%10s\n", aux -> item.value, aux -> item.token );
         
         /* Atualizando a variavel aux */
         aux = aux -> next;
      } /* while */
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* printList */
/* Fim das operacoes basicas sobre Listas    */

/* Inicio das operacoes basicas sobre Pilhas */
/**********************************************************************************
   NOME: newStack()
   
   DESCRIÇÃO
   Cria uma pilha vazia, ou torna uma pilha existente, vazia.
   
   PARÂMETROS
   Stack *stack : Um ponteiro para uma pilha.
   
   RETORNO
   Retorna 0, indicando sucesso. Retorna na região de memória apontada por *stack,
      a pilha criada.
**********************************************************************************/
int newStack ( Stack *stack )
{
   /* Alocando espaco em memoria e atribuindo-o ao
         elemento do topo da Pilha.                */
   stack -> top = ( Pointer ) malloc( sizeof( Cell ) );
   
   /* Fazendo que o elemento do fundo aponte para o
         mesmo local que o do topo - Pilha Vazia    */
   stack -> bottom = stack -> top;
   
   /* Fazendo com que o proximo elemento apos o
         do topo, seja o NULO.                  */
   stack -> top -> next = NULL;
   
   return 0; /* Retorno com sucesso */
} /* newStack */

/**********************************************************************************
   NOME: emptyStack()
   
   DESCRIÇÃO
   Verifica se uma Pilha está vazia.
   
   PARÂMETROS
   Stack *stack : Um ponteiro para uma pilha.
   
   RETORNO
   Retorna 0, no caso de a pilha estar vazia, ou um valor diferente em caso con-
      trário.
**********************************************************************************/
char stackEmpty ( Stack *stack )
{
   return ( stack -> top == stack -> bottom );
} /* stackEmpty */

/**********************************************************************************
   NOME: push()
   
   DESCRIÇÃO
   Insere um item no topo de uma pilha.
   
   PARÂMETROS
   Stack *stack : Um ponteiro para uma pilha.
   Item *item : O item a ser inserido.
   
   RETORNO
   Retorna 0, no caso de a inserção ter sido feita com sucesso, ou um valor dife-
      rente em caso contrário.
**********************************************************************************/
int push ( Stack *stack, Item *item )
{
   /* Definindo um ponteiro auxiliar e atribuindo
         a ele o endereco de memoria alocado.     */
   Pointer aux = ( Pointer ) malloc( sizeof( Cell ) );
   
   /* Adicionando o elemento no topo da pilha */
   stack -> top -> item = *item;
   
   /* Fazendo com que o proximo elemento de aux
         aponte para o mesmo lugar que o topo.  */
   aux -> next = stack -> top;
   
   /* Fazendo com que aux seja o novo
         topo da pilha.               */
   stack -> top = aux;
   
   /* Operacao realizada com exito */
   return 0;
} /* push */

/**********************************************************************************
   NOME: pop()
   
   DESCRIÇÃO
   Remove um item do topo da pilha.
   
   PARÂMETROS
   Stack *stack : Um ponteiro para uma pilha.
   Item *item : Retorna o campo item da célula excluida.
   
   RETORNO
   Retorna 0, caso a exlusao tenha sido feita com sucesso;
           1, caso a lista esteja vazia ou a posicao nao exista.
**********************************************************************************/
int pop ( Stack *stack, Item *item )
{
   /* Verificando se a pilha estah vazia */
   if ( stackEmpty( stack ) )
      return 1; /* Pilha vazia */
   
   else {
      /* A pilha nao estah vazia */
      
      /* Definindo um ponteiro auxiliar e fazendo com que ele aponte
             para o topo da pilha.                                   */
      Pointer aux = stack -> top;
      
      /* Fazendo com que o topo da pilha seja
            o proximo item a aux.             */
      stack -> top = aux -> next;
      
      /* Atribuindo a item, o item que serah
            excluido.                        */
      *item = aux -> next -> item;
      
      /* Liberando espaco em memoria - excluindo */
      free( aux );
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* pop */

/**********************************************************************************
   NOME: top()
   
   DESCRIÇÃO
   Obtém o elemento do topo de uma pilha.
   
   PARÂMETROS
   Stack *stack : Um ponteiro para uma pilha.
   Item *item : O item a ser retornado.
   
   RETORNO
   Retorna um ponteiro para o elemento do topo da pilha, ou NULL, se a pilha es-
      tiver vazia. Retorna em *item, o conteúdo elemento do topo da pilha.
**********************************************************************************/
Pointer top ( Stack *stack, Item *item )
{
   /* Verificando se a pilha estah vazia */
   if ( stackEmpty( stack ) )
      /* Pilha vazia - retorna um ponteiro nulo */
      return NULL;
   
   /* A pilha NAO estah vazia */
   else {
      *item = stack -> top -> next -> item; /* Pegando o conteudo do item */
      return ( stack -> top -> next ); /* Retornando o ponteiro */
   } /* else */
} /* top */

/**********************************************************************************
   NOME: bottom()
   
   DESCRIÇÃO
   Obtém o elemento do fundo de uma pilha.
   
   PARÂMETROS
   Stack *stack : Um ponteiro para uma pilha.
   Item *item : O item a ser retornado.
   
   RETORNO
   Retorna um ponteiro para o elemento do fundo da pilha, ou NULL, se a pilha es-
      tiver vazia. Retorna em *item, o conteúdo elemento do fundo da pilha.
**********************************************************************************/
Pointer bottom ( Stack *stack, Item *item )
{
   /* Verificando se a pilha estah vazia */
   if ( stackEmpty( stack ) )
      /* Pilha vazia - retorna um ponteiro nulo */
      return NULL;
   
   /* A pilha NAO estah vazia */
   else {
      *item = stack -> bottom -> item; /* Pegando o conteudo do item */
      return ( stack -> bottom ); /* Retornando o ponteiro */
   } /* else */
} /* bottom */

/**********************************************************************************
   NOME: printStack()
   
   DESCRIÇÃO
   Imprime o conteúdo de uma pilha na tela - a impressão depende dos campos da pi-
      lha.
   
   PARÂMETROS
   Stack *stack : Um ponteiro para uma pilha.
   
   RETORNO
   Retorna 0, caso a operação tenha sido realizada com sucesso;
           1, no caso de a lista estar vazia.
**********************************************************************************/
int printStack ( Stack *stack )
{
   /* Verificando se a Pilha estah vazia */
   if ( stackEmpty( stack ) )
      return 1; /* Pilha vazia */
   
   else {
      /* A Pilha nao estah vazia */
      
      /* Um ponteiro auxiliar para varrer a Pilha */
      Pointer aux = stack -> top -> next;
      
      /* Imprime enquanto nao chegar ao fim da Pilha */
      while ( aux != NULL ) {
         /* Imprimindo... */
         printf( "%2d%10s\n", aux -> item.value, aux -> item.token );
         
         /* Atualizando a variavel aux */
         aux = aux -> next;
      } /* while */
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* printStack */
/* Fim das operacoes basicas sobre Pilhas    */

/* Inicio das operacoes basicas sobre Filas  */
/**********************************************************************************
   NOME: newQueue()
   
   DESCRIÇÃO
   Cria uma fila vazia, ou torna uma fila existente, vazia.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para uma fila.
   
   RETORNO
   Retorna 0, indicando sucesso. Retorna na região de memória apontada por *queue,
      a fila criada.
**********************************************************************************/
int newQueue ( Queue *queue )
{
   /* Alocando espaco em memoria e atribuindo-o ao
         elemento do inicio da Fila.               */
   queue -> front = ( Pointer ) malloc( sizeof( Cell ) );
   
   /* Fazendo que o elemento do fim aponte para o
         mesmo local que o do inicio - Fila Vazia */
   queue -> back = queue -> front;
   
   /* Fazendo com que o proximo elemento apos o
         do inicio, seja o NULO.                */
   queue -> front -> next = NULL;
   
   return 0; /* Retorno com sucesso */
} /* newQueue */

/**********************************************************************************
   NOME: queueEmpty()
   
   DESCRIÇÃO
   Verifica se uma fila está vazia.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para uma fila.
   
   RETORNO
   Retorna 0, no caso de a fila estar vazia, ou um valor diferente em caso con-
      trário.
**********************************************************************************/
int queueEmpty ( Queue *queue )
{
   return ( queue -> front == queue -> back );
} /* queueEmpty */

/**********************************************************************************
   NOME: enqueue()
   
   DESCRIÇÃO
   Insere um item no fim de uma fila.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para uma fila.
   Item *item : O item a ser inserido.
   
   RETORNO
   Retorna 0, no caso de a inserção ter sido feita com sucesso, ou um valor dife-
      rente em caso contrário.
**********************************************************************************/
int enqueue ( Queue *queue, Item *item )
{
   /* Atribuindo ao proximo elemento, apos o ultimo,
         o endereco de memoria alocado.              */
   queue -> back -> next = ( Pointer ) malloc( sizeof( Cell ) );
   
   /* Fazendo com que o novo fim da Fila seja o
         elemento recem criado.                 */
   queue -> back = queue -> back -> next;
   
   /* Atribuindo ao novo elemento,
         o item a ser inserido.    */
   queue -> back -> item = *item;
   
   /* Fazendo com que o proximo elemento apos o
         do fim, seja o NULO.                   */
   queue -> back -> next = NULL;
   
   /* Operacao realizada com exito */
   return 0;
} /* enqueue */

/**********************************************************************************
   NOME: dequeue()
   
   DESCRIÇÃO
   Remove um item do início da fila.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para uma fila.
   Item *item : Retorna o campo item da célula excluida.
   
   RETORNO
   Retorna 0, caso a exlusao tenha sido feita com sucesso;
           1, caso a lista esteja vazia ou a posicao nao exista.
**********************************************************************************/
int dequeue ( Queue *queue, Item *item )
{
   /* Verificando se a Fila estah vazia */
   if ( queueEmpty( queue ) )
      return 1; /* Fila vazia */
   
   else {
      /* A Fila nao estah vazia */
      
      /* Definindo um ponteiro auxiliar e apontando-o
            para o inicio da Fila.                    */
      Pointer aux = queue -> front;
      
      /* Fazendo com que o elemento do inicio da Fila
            seja o segundo elemento da Fila.          */
      queue -> front = queue -> front -> next;
      
      /* Atribuindo a item, o item que serah
            excluido.                        */
      *item = queue -> front -> item;
      
      /* Liberando espaco em memoria - excluindo */
      free( aux );
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* dequeue */

/**********************************************************************************
   NOME: printQueue()
   
   DESCRIÇÃO
   Imprime o conteúdo de uma fila na tela - a impressão depende dos campos da fi-
      la.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para uma fila.
   
   RETORNO
   Retorna 0, caso a operação tenha sido realizada com sucesso;
           1, no caso de a lista estar vazia.
**********************************************************************************/
int printQueue ( Queue *queue )
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
         printf( "< %25s ; %32s ; %4d ; (%4d,%4d) >\n",
            aux -> item.token, aux -> item.class, aux -> item.value,
            aux -> item.coOrdinate.line, aux -> item.coOrdinate.column );
         
         /* Atualizando a variavel aux */
         aux = aux -> next;
      } /* while */
   } /* else */
   
   /* Operacao realizada com exito */
   return 0;
} /* printQueue */

/**********************************************************************************
   NOME: selectionSort()
   
   DESCRIÇÃO
   Ordena uma fila pelo campo item.value, utilizando o método de ordenação por se-
      leção.
   
   PARÂMETROS
   Queue *queue : Um ponteiro para uma fila.
   
   RETORNO
   Retorna 0, caso a operação tenha sido realizada com sucesso;
           1, no caso de a lista estar vazia.
**********************************************************************************/
int selectionSort ( Queue *queue )
{
   /* Verificando se a fila estah vazia */
   if ( queueEmpty( queue ) )
      return 1; /* Fila vazia */
   
   /* A fila NAO estah vazia */
   else {
      /* Ponteiros para varrer a fila */
      Pointer i = queue -> front -> next,
              j, min;
      
      Item x; /* Armazena um item */
      
      /* Roda com i, do inicio, ateh o final da fila */
      while ( i != NULL ) {
         min = i;
         
         /* Roda com j, a partir da posicao apos i, ateh o final da fila */
         j = i -> next;
         while ( j != NULL ) {
            /* Testando se o valor que j aponta eh menor que o menor valor. Caso
                  seja, trocam-se os valores deles.                              */
            if ( j -> item.value < min -> item.value )
               min = j;
            
            j = j -> next; /* Atualizando j */
         } /* while */
         
         /* Aqui, efetivamente, sao trocados os valores dos itens */
         x = min -> item;
         min -> item = i -> item;
         i -> item = x;
         
         i = i -> next; /* Atualizando i */
      } /* while */
   } /* else */
   
   /* Retornando sucesso */
   return 0;
} /* selectionSort */
/* Fim das operacoes basicas sobre Filas     */
/* Fim da definicao das operacoes basicas sobre os tipos abstratos de dados.      */
