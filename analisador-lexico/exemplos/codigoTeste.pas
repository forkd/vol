(* Este eh um programa de teste do Analisador Lexico. Isto eh um comnetario, portanto serah ignorado pelo analisador. Este comentario eh feito com os caracteres (, ) e *. *)
{ Este eh o segundo tipo de comentario em pascal, utilizando chaves. Serah ignorado tambem.
  AUTOR: Jose Lopes de Oliveira Junior
  DATA: fev/2006
}

program testeAL;

label inicio;

var x:string;
    i:integer;

{ Isto estah ERRADO, e serah reportado na tabela de erros }
34t
14.r
34.4b
4e*5
ºª§¬£²³¹
10E-9l

BeGiN { O analisador NAO eh sensivel ao caso... }
   x:='Teste AL.'; (* O que estah entre as aspas serah ignorado. *)
   i:=0;
   
   { Testando uma estrutura de repeticao... }
   for i := 1 to 200 do
   begin
      { Testando uma estrutura de selecao }
      if(x<>'TESTE AL!') then
         i:=i+45
      else 
         i:=i+1;
      
      { Writeln nao eh palavra reservada, por isso serah tratado como
           identificador.                                             }
      writeln( 'Teste do analisador lexico!' );
   end;
   
   (* Teste do repeat *)
   repeat
      write( 'jlojunion:' );
      i := i + 1;
      
      (* Teste do CASE *)
      case i of
         1: write( 'Isto faz nada...' );
         2: i := 0;
         0:
         begin
            i := 2000;
            writeln( 'O valor de i eh: ', i );
         end;
      end;
   until i > 1000;
   
   { Teste do while... }
   while ( i < 0 ) do
   begin
      x := 'A criatividade eh um dom de Deus... rs';
      writeln( 'Olha no que eu pensei: ', x );
      i:=5000;
   end;
   
   { Ateh o goto funciona, mas nao lembro como se usa... }
   i:=0;
   inicio:
     i := I+1; {NAO eh sensivel ao caso... i==I!}
     if i <= 10 then goto inicio;

{ Comentario de 1,
                2,
           	3 linhas com os delimitadores { e
}

(* Uma linha com varios espacos em branco *)
           identificador      :=  IDENTIFICADOR +	4 ;    

end. { A ULTIMA LINHA DEVE ESTAR EM BRANCO!!!! }

