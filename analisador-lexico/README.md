Analisador L�xico da Linguagem Pascal v.0.5 - Notas do autor

Este analisador l�xico � baseado na linguagem pascal, vers�o compat�vel com o compilador Turbo Pascal 7.0, da Borland.
Para o correto funcionamento do mesmo, � necess�rio um c�digo-fonte digitado em um arquivo de texto raso, como o VIM ou o KWrite. Al�m disso, � importante lembrar que, assim como no GCC, compilador da linguagem C da GNU, deve haver uma linha em branco no final do arquivo com o c�digo-fonte, ou sen�o a linha ser� repetida, aparecendo duas ocorr�ncias dela na sa�da gerada.
Este analisador l�xico tem apenas fins de estudo, visto que muitas funcionalidades de um verdadeiro analisador l�xico n�o s�o implementadas nele, como, por exemplo, uma tabela de s�mbolos padronizada. Contudo, ele, al�m de poder ser usado para entender o passo de an�lise l�xica de um compilador, pode ser melhorado por qualquer um com o conhecimento devido e ainda utilizado para se entender a implementa��o de um aut�mato.
Tentarei, resumidamente, explicar o funcionamento deste programa. Ele � composto dos arquivos al.c, libal.h e libabstype.h. O arquivo al.c � o arquivo principal do programa, que executa a chamada para todos os outros. O arquivo libal.c � o "c�rebro" do programa, pois � a biblioteca que implementa a an�lise l�xica propriamente dita e o arquivo libabstype.h implementa os tipos abstratos de dados Lista, Pilha e Fila como ponteiros, que podem ser usados para implementar a tabela de s�mbolos do analisador l�xico. No caso deste programa, optei por utilizar o tipo de dados Fila (Queue) para implementar a tabela de s�mbolos, pois, como era minha inten��o imprim�-la na ordem em que os tokens entraram, este tipo de dados se mostrou mais indicado. Nesta biblioteca ainda � implementado o m�todo de ordena��o por sele��o, usado para ordenar uma fila por ponteiros -a tabela de s�mbolos.
A biblioteca libal.h implementa algumas fun��es essenciais � an�lise l�xica e bem simples, al�m de outras um pouco mais complexas, como a fun��o isInQueue -est� na fila-, que verifica se um determinado item est� ou n�o na fila. A fun��o isResWord -� palavra reservada- possui uma lista de todas as palavras reservadas da linguagem pascal, retiradas da ajuda do compilador da linguagem pascal citado anteriormente. Enfim, a fun��o lexicalScanner -an�lise l�xica- realiza a an�lise do c�digo passado como par�metro para ela. Esta fun��o implementa um aut�mato -m�quina de estados- o qual segue em anexo com o programa, no formato png -sim, � uma imagem!- sob o nome de automato-linguagemPascal.png. Tentei ser o mais fiel poss�vel na transcri��o do aut�mato para a linguagem C. Desta maneira, o algoritmo lexicalScanner pode ser mais facilmente entendido, apenas analisando-se o aut�mato.
O arquivo al.c possui a verifica��o dos par�mtros passados pelo usu�rio ao programa, al�m de, como j� foi dito, as chamadas para as outras fun��es do programa, a pr�pria licen�a do programa -em portugu�s- e a ajuda do analisador.
Todos os c�digos est�o bem comentados -mais que o normal, inclusive- para facilitar o entendimento do programa e futuras manuten��es ou melhorias. Por isso, o considero bastante did�tico, especialmente �queles que estudam a disciplina Compiladores.
Para concluir, segue o arquivo compilado al, pronto para ser executado. Mas caso n�o seja poss�vel execut�-lo, ou seja da vontade do usu�rio, o c�digo pode ser compilado com a seguinte linha, lembrando que o GCC deve estar corretamente instalado e configurado no sistema:
$ gcc al.c -o al
Isto gerar� um novo arquivo execut�vel al, que deve ser utilizado da seguinte maneira:
$ al [op��es]
ou
$ al [caminho_do_codigo_fonte_em_Pascal]
H� um diret�rio chamado exemplos, que traz alguns c�digos-fonte na linguagem pascal, prontos para serem analisados lexicamente.
Sugiro que, para se analisar melhor os resultados, o usu�rio redirecione a sa�da deste programa para um arquivo texto, de forma que as tabelas geradas possam ser analisadas com mais cuidado -� bom lembrar que, ao se fazer isto, � necess�rio pressionar a tecla <ENTER> tr�s vezes, que s�o referentes �s tr�s chamadas � fun��o scanf(), no arquivo al.c:
$ ./al <caminhoCodigoFonte>.pas > saidaAnalisadorLexico.txt
A �ltima observa��o a ser feita � referente � capacidade de armazenamento das vari�veis utilizadas no programa. O comprimento m�ximo de um token -s�mbolo- aceito pelo analisador � de cem -100- caracteres e o comprimento m�ximo de uma linha do c�digo-fonte, � de duzentos -200- caracteres (nada mal, pois Turbo Pascal 7.0 da Borland tinha a limita��o de 128 caracteres por linha...). � important�ssimo que estes limites sejam respeitados, pois caso n�o o sejam, o comportamento do analisador ser� indefinido. Seria relativamente f�cil verificar os limites destas vari�veis e avisar ao usu�rio sobre isso. Entretanto seria necess�rio o gasto adicional de tempo com processamento, o que prejudicaria o desempenho do programa.
Bom, � isso a�! Espero que este programa possa lhes ser �til de alguma forma, contribuindo para o enriquecimento do conhecimento pessoal de cada um!
Obrigado.

Jos� Lopes de Oliveira J�nior
Barbacena, MG, fevereiro de 2006.


{
Publica��o orignal: 2006-07-03
URL: http://www.vivaolinux.com.br/script/Analisador-Lexico-0.5/
}

