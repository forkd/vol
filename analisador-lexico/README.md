Analisador Léxico da Linguagem Pascal v.0.5 - Notas do autor

Este analisador léxico é baseado na linguagem pascal, versão compatível com o compilador Turbo Pascal 7.0, da Borland.
Para o correto funcionamento do mesmo, é necessário um código-fonte digitado em um arquivo de texto raso, como o VIM ou o KWrite. Além disso, é importante lembrar que, assim como no GCC, compilador da linguagem C da GNU, deve haver uma linha em branco no final do arquivo com o código-fonte, ou senão a linha será repetida, aparecendo duas ocorrências dela na saída gerada.
Este analisador léxico tem apenas fins de estudo, visto que muitas funcionalidades de um verdadeiro analisador léxico não são implementadas nele, como, por exemplo, uma tabela de símbolos padronizada. Contudo, ele, além de poder ser usado para entender o passo de análise léxica de um compilador, pode ser melhorado por qualquer um com o conhecimento devido e ainda utilizado para se entender a implementação de um autômato.
Tentarei, resumidamente, explicar o funcionamento deste programa. Ele é composto dos arquivos al.c, libal.h e libabstype.h. O arquivo al.c é o arquivo principal do programa, que executa a chamada para todos os outros. O arquivo libal.c é o "cérebro" do programa, pois é a biblioteca que implementa a análise léxica propriamente dita e o arquivo libabstype.h implementa os tipos abstratos de dados Lista, Pilha e Fila como ponteiros, que podem ser usados para implementar a tabela de símbolos do analisador léxico. No caso deste programa, optei por utilizar o tipo de dados Fila (Queue) para implementar a tabela de símbolos, pois, como era minha intenção imprimí-la na ordem em que os tokens entraram, este tipo de dados se mostrou mais indicado. Nesta biblioteca ainda é implementado o método de ordenação por seleção, usado para ordenar uma fila por ponteiros -a tabela de símbolos.
A biblioteca libal.h implementa algumas funções essenciais à análise léxica e bem simples, além de outras um pouco mais complexas, como a função isInQueue -está na fila-, que verifica se um determinado item está ou não na fila. A função isResWord -é palavra reservada- possui uma lista de todas as palavras reservadas da linguagem pascal, retiradas da ajuda do compilador da linguagem pascal citado anteriormente. Enfim, a função lexicalScanner -análise léxica- realiza a análise do código passado como parâmetro para ela. Esta função implementa um autômato -máquina de estados- o qual segue em anexo com o programa, no formato png -sim, é uma imagem!- sob o nome de automato-linguagemPascal.png. Tentei ser o mais fiel possível na transcrição do autômato para a linguagem C. Desta maneira, o algoritmo lexicalScanner pode ser mais facilmente entendido, apenas analisando-se o autômato.
O arquivo al.c possui a verificação dos parâmtros passados pelo usuário ao programa, além de, como já foi dito, as chamadas para as outras funções do programa, a própria licença do programa -em português- e a ajuda do analisador.
Todos os códigos estão bem comentados -mais que o normal, inclusive- para facilitar o entendimento do programa e futuras manutenções ou melhorias. Por isso, o considero bastante didático, especialmente àqueles que estudam a disciplina Compiladores.
Para concluir, segue o arquivo compilado al, pronto para ser executado. Mas caso não seja possível executá-lo, ou seja da vontade do usuário, o código pode ser compilado com a seguinte linha, lembrando que o GCC deve estar corretamente instalado e configurado no sistema:
$ gcc al.c -o al
Isto gerará um novo arquivo executável al, que deve ser utilizado da seguinte maneira:
$ al [opções]
ou
$ al [caminho_do_codigo_fonte_em_Pascal]
Há um diretório chamado exemplos, que traz alguns códigos-fonte na linguagem pascal, prontos para serem analisados lexicamente.
Sugiro que, para se analisar melhor os resultados, o usuário redirecione a saída deste programa para um arquivo texto, de forma que as tabelas geradas possam ser analisadas com mais cuidado -é bom lembrar que, ao se fazer isto, é necessário pressionar a tecla <ENTER> três vezes, que são referentes às três chamadas à função scanf(), no arquivo al.c:
$ ./al <caminhoCodigoFonte>.pas > saidaAnalisadorLexico.txt
A última observação a ser feita é referente à capacidade de armazenamento das variáveis utilizadas no programa. O comprimento máximo de um token -símbolo- aceito pelo analisador é de cem -100- caracteres e o comprimento máximo de uma linha do código-fonte, é de duzentos -200- caracteres (nada mal, pois Turbo Pascal 7.0 da Borland tinha a limitação de 128 caracteres por linha...). É importantíssimo que estes limites sejam respeitados, pois caso não o sejam, o comportamento do analisador será indefinido. Seria relativamente fácil verificar os limites destas variáveis e avisar ao usuário sobre isso. Entretanto seria necessário o gasto adicional de tempo com processamento, o que prejudicaria o desempenho do programa.
Bom, é isso aí! Espero que este programa possa lhes ser útil de alguma forma, contribuindo para o enriquecimento do conhecimento pessoal de cada um!
Obrigado.

José Lopes de Oliveira Júnior
Barbacena, MG, fevereiro de 2006.


{
Publicação orignal: 2006-07-03
URL: http://www.vivaolinux.com.br/script/Analisador-Lexico-0.5/
}

