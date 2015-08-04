program AnalisadorLexico;
begin
   {Serao armazenados os operadores aritmeticos na tabela de tokens}
   +-*mod/div
   {Hora dos relacionais}
   in <> < > <= >= =
   {booleanos}
   not and or xor
   {De ponteiros}
   @^
   {Delimitadores}
   ;:,.
   {Numeros...}
   {Inteiro} 123 10000
   {Reais} 12.56 14.07 50000.009
   {NUMERO x 10 ^ EXPOENTE ==> numEnum} 14E6 15.009e9 200E-50 500.05E9 50.1e-9
   {Numeros invalidos - tabela de erros} 15r 90t506 15. 56e 900e- 60E*6
   
   (* Identifacadores que vao pra tabela de simbolos - valores repetidos possuirao valor unico, mas se repetirao - LEMBRE-SE: O ANALISADOR NAO EH SENSIVAL AO CASO!!! ID == id == iD == Id*)
   i a identificador i a identificador I A IdEnTiFiCaDoR IDENTIFICADOR
   
   {Simbolos invalidos - tabela de erros}
   ºª§¬¢£³²¹
   
   {O ultimo identificador para a tabela de simbolos}
   jlojunior JLOJunior
end. {Lembre-se de deixar uma linha em branco no fim do arquivo!!!}

