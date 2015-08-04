/**
 * Classe que implementa rotinas de validação da classe EnderecoIP.
 * @author José Lopes de Oliveira Júnior
 * @version 1.0
 */
class LibVerIP {
   /**
    * Verifica se um parâmetro está sob uma das formas: N.N.N.N; N.N.N.N/NO; N.N.N.N/N.N.N.N.
    *    <b><i>Obs.: </b>(0 <= N <= 255), (0 <= NO <= 32) e (NO = 255).</i>
    * @param parametro O parâmetro pode estar nos padrões: N.N.N.N; N.N.N.N/NO; N.N.N.N/NUM.N.N.N. 
    *    Obrigatoriamente as seguintes especificações devem ser respeitadas: (0 <= N <= 255), 
    *    (0 <= NO <= 32) e (NO = 255).
    * @return Retorna:<br>
    *    <b>-3</b> - Caso a máscara passada no paràmetro seja inválida para o endereço IP especificado;<br>
    *    <b>-2</b> - Caso o número de bits da máscara contido no parâmetro seja inválido;<br>
    *    <b>-1</b> - Caso a máscara contida no parâmetro seja inválida;<br>
    *    <b>0</b> - Caso o endereço contido no parâmetro seja inválido;<br>
    *    <b>1</b> - Caso o parâmetro esteja sob a primeira forma;<br>
    *    <b>2</b> - Caso o parâmetro esteja sob a segunda forma;<br>
    *    <b>3</b> - Caso o parâmetro esteja sob a terceira forma;<br>
    */
   public static int valida ( String parametro )
   {
      String param = parametro.trim(); // Retirando os espacos no inicio e no fim do parametro
      int avalia = sintatica( param ); // Verificando a sintaxe.
      
      if ( ( avalia < 1 ) || ( avalia > 3 ) )
         return avalia; // Erro de sintaxe
      
      else {
         avalia = semantica( param ); // Sintaxe OK. Verificando a semantica.
         
         // Semantica OK, verificando a validade da mascara, perante o IP
         if ( ( avalia < 1 ) || ( avalia > 3 ) )
            return avalia;
         
         else {
            int aux = avalia;
            
            if ( aux != 1 ) // Padrao N.N.N.N nao tem mascara
               avalia = verMascara( param, aux );
            else
               return 1;
            
            return avalia;
         }
      }
   } // valida
   
   /**
    * Método que verifica a sintaxe do parâmetro passado.
    * @param parametro O parâmetro pode estar nos padrões: N.N.N.N; N.N.N.N/NO; N.N.N.N/N.N.N.N.
    *    <b><i>Obs.: </b>(0 <= N <= 999) e (0 <= NO <= 99).</i>
    * @return Retorna:<br>
    *    <b>-1</b> - Caso a máscara contida no parâmetro seja inválida;<br>
    *    <b>0</b> - Caso o endereço contido no parâmetro seja inválido;<br>
    *    <b>1</b> - Caso o parâmetro esteja sob a primeira forma;<br>
    *    <b>2</b> - Caso o parâmetro esteja sob a segunda forma;<br>
    *    <b>3</b> - Caso o parâmetro esteja sob a terceira forma;<br>
    */
   private static int sintatica ( String parametro )
   {
      int estado = 1; // O estado em que a funcao se encontra.
      
      char chLido; // O ultimo caractere lido.
   
   // Este laco se repete ateh que seja atingido o fim
   // da variavel numIP.
   for ( int i = 0; i < parametro.length(); i++ ) {
      // Lendo um caractere de numIP e gravando-o em chLido.
      chLido = parametro.charAt( i );
      
      // Uma acao serah tomada dependendo do estado.
      switch ( estado ) {
         case 1:
            if ( Character.isDigit( chLido ) )
               estado = 2;
            else {
               --i; // Voltando ao ultimo caractere lido
               estado = 0; // Indo ao estado de erro
            }
            
            break;
         
         case 2:
            if ( Character.isDigit( chLido ) )
               estado = 3;
            else if ( chLido == '.' )
               estado = 5;
            else {
               --i; // Voltando ao ultimo caractere lido
               estado = 0; // Indo ao estado de erro
            }
            
            break;
         
         case 3:
            if ( Character.isDigit( chLido ) )
               estado = 4;
            else if ( chLido == '.' )
               estado = 5;
            else {
               --i; // Voltando ao ultimo caractere lido
               estado = 0; // Indo ao estado de erro
            }
            
            break;
         
         case 4:
            if ( chLido == '.' )
               estado = 5;
            else {
               --i; // Voltando ao ultimo caractere lido
               estado = 0; // Indo ao estado de erro
            }
            
            break;
         
         case 5:
            if ( Character.isDigit( chLido ) )
               estado = 6;
            else {
               --i; // Voltando ao ultimo caractere lido
               estado = 0; // Indo ao estado de erro
            }
            
            break;
         
         case 6:
            if ( Character.isDigit( chLido ) )
               estado = 7;
            else if ( chLido == '.' )
               estado = 9;
            else {
               --i; // Voltando ao ultimo caractere lido
               estado = 0; // Indo ao estado de erro
            }
            
            break;
         
         case 7:
            if ( Character.isDigit( chLido ) )
               estado = 8;
            else if ( chLido == '.' )
               estado = 9;
            else {
               --i; // Voltando ao ultimo caractere lido
               estado = 0; // Indo ao estado de erro
            }
            
            break;
         
            case 8:
               if ( chLido == '.' )
                  estado = 9;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 9:
               if ( Character.isDigit( chLido ) )
                  estado = 10;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 10:
               if ( Character.isDigit( chLido ) )
                  estado = 11;
               else if ( chLido == '.' )
                  estado = 13;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 11:
               if ( Character.isDigit( chLido ) )
                  estado = 12;
               else if ( chLido == '.' )
                  estado = 13;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 12:
               if ( chLido == '.' )
                  estado = 13;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 13:
               if ( Character.isDigit( chLido ) )
                  estado = 14;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 14: // Estado final
               if ( Character.isDigit( chLido ) )
                  estado = 15;
               else if ( chLido == '/' )
                  estado = 17;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 15: // Estado final
               if ( Character.isDigit( chLido ) )
                  estado = 16;
               else if ( chLido == '/' )
                  estado = 17;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 16: // Estado final
               if ( chLido == '/' )
                  estado = 17;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = 0; // Indo ao estado de erro
               }
               
               break;
            
            case 17:
               if ( Character.isDigit( chLido ) )
                  estado = 18;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 18: // Estado final
               if ( Character.isDigit( chLido ) )
                  estado = 19;
               else if ( chLido == '.' )
                  estado = 21;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 19: // Estado final
               if ( Character.isDigit( chLido ) )
                  estado = 20;
               else if ( chLido == '.' )
                  estado = 21;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 20:
               if ( chLido == '.' )
                  estado = 21;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 21:
               if ( Character.isDigit( chLido ) )
                  estado = 22;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 22:
               if ( Character.isDigit( chLido ) )
                  estado = 23;
               else if ( chLido == '.' )
                  estado = 25;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 23:
               if ( Character.isDigit( chLido ) )
                  estado = 24;
               else if ( chLido == '.' )
                  estado = 25;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 24:
               if ( chLido == '.' )
                  estado = 25;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 25:
               if ( Character.isDigit( chLido ) )
                  estado = 26;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 26:
               if ( Character.isDigit( chLido ) )
                  estado = 27;
               else if ( chLido == '.' )
                  estado = 29;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 27:
               if ( Character.isDigit( chLido ) )
                  estado = 28;
               else if ( chLido == '.' )
                  estado = 29;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 28:
               if ( chLido == '.' )
                  estado = 29;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 29:
               if ( Character.isDigit( chLido ) )
                  estado = 30;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 30: // Estado final
               if ( Character.isDigit( chLido ) )
                  estado = 31;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 31: // Estado final
               if ( Character.isDigit( chLido ) )
                  estado = 32;
               else {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            case 32: // Estado Final
               if ( i != parametro.length() - 1 ) {
                  --i; // Voltando ao ultimo caractere lido
                  estado = -1; // Indo ao estado de erro
               }
               
               break;
            
            default: // Estado de erro
               // Forcando a saida da iteracao.
               i = parametro.length() - 1;
               
               break;
         } // switch
      } // for
      
      // Verificando qual foi o estado de saida da iteracao,
      // para poder saber qual serah o retorno da funcao.
      switch ( estado ) {
         // N.N.N.N
         case 14: case 15: case 16:
            return 1;
         
         // N.N.N.N/NO
         case 18: case 19:
            return 2;
         
         // N.N.N.N/NUM.N.N.N.N
         case 30: case 31: case 32:
            return 3;
         
         // Erro no endereco IP
         case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
         case 9: case 10: case 11: case 12: case 13:
            return 0;
         
         // Erro encontrado na mascara
         default:
            return -1;
      } // switch
   } // sintaxe
   
   /**
    * Método que verifica a semàntica do paràmetro passado. Este método deve ser executado apenas 
    *    após o parâmetro já ter sido avaliado pelo verificador de sintaxe e nenhum erro ter sido
    *    encontrado.
    * @param parametro O parâmetro pode estar nos padrões: N.N.N.N; N.N.N.N/NO; N.N.N.N/NUM.N.N.N. 
    *    Obrigatoriamente as seguintes especificações devem ser respeitadas: (0 <= N <= 255), 
    *    (0 <= NO <= 32) e (NO = 255).
    * @return Retorna:<br>
    *    <b>-2</b> - Caso o número de bits da máscara contido no parâmetro seja inválido;<br>
    *    <b>-1</b> - Caso a máscara contida no parâmetro seja inválida;<br>
    *    <b>0</b> - Caso o endereço contido no parâmetro seja inválido;<br>
    *    <b>1</b> - Caso o parâmetro esteja sob a primeira forma;<br>
    *    <b>2</b> - Caso o parâmetro esteja sob a segunda forma;<br>
    *    <b>3</b> - Caso o parâmetro esteja sob a terceira forma;<br>
    */
   private static int semantica ( String parametro )
   {
      int estado = 1, // O estado em que a funcao se encontra.
         numInt = 0;  // Armazenarah octeto por octeto
      
      String numStr = ""; // Armazenarah octeto por octeto
      
      char chLido; // O ultimo caractere lido de numIP.
      
      // Este laco serah repetido ateh que se atinja o fim do numero IP
      // ou que seja encontrado algum erro.
      for ( int i = 0; i < parametro.length(); i++ ) {
         // Lendo um caractere de numIP e gravando-o em chLido.
         chLido = parametro.charAt( i );
         
         // Uma acao serah tomada dependendo do estado.
         switch ( estado ) {
            case 1:
               if ( Character.isDigit( chLido ) )
                  // Concatenando digitos ao fim da String
                  numStr += chLido;
               
               else if ( chLido == '.' ) {
                  // Convertendo o numero encontrado de String
                  // para numerico.
                  numInt = Integer.parseInt( numStr );
                  
                  // Verificando se o numero estah dentro da faixa
                  if ( numInt > 255 )
                     // Numero fora da faixa
                     estado = 0; // Indo para o estado de erro
                  
                  else
                     estado = 2; // Indo para o proximo estado
                  
                  // Limpando a String auxiliar
                  numStr = "";
               }
               
               break;
            
            case 2:
               if ( Character.isDigit( chLido ) )
                  // Concatenando digitos ao fim da String
                  numStr += chLido;
               
               else if ( chLido == '.' ) {
                  // Convertendo o numero encontrado de String
                  // para numerico.
                  numInt = Integer.parseInt( numStr );
                  
                  // Verificando se o numero estah dentro da faixa
                  if ( numInt > 255 )
                     // Numero fora da faixa
                     estado = 0; // Indo para o estado de erro
                  
                  else
                     // Numero dentro da faixa
                     estado = 3; // Indo para o proximo estado
                  
                  // Limpando a String auxiliar
                  numStr = "";
               }
               
               break;
            
            case 3:
               if ( Character.isDigit( chLido ) )
                  // Concatenando digitos ao fim da String
                  numStr += chLido;
               
               else if ( chLido == '.' ) {
                  // Convertendo o numero encontrado de String
                  // para numerico.
                  numInt = Integer.parseInt( numStr );
                  
                  // Verificando se o numero estah dentro da faixa
                  if (  numInt > 255 )
                     // Numero fora da faixa
                     estado = 0; // Indo para o estado de erro
                  
                  else
                     // Numero dentro da faixa
                     estado = 4; // Indo para o proximo estado
                  
                  // Limpando a String auxiliar
                  numStr = "";
               }
               
               break;
            
            case 4: // Estado final
               if ( Character.isDigit( chLido ) ) {
                  // Concatenando digitos ao fim da String
                  numStr += chLido;
                  
                  // Verificando se o fim do numero IP foi atingido
                  if ( i == parametro.length() - 1 ) {
                     // Convertendo o numero encontrado de String
                     // para numerico.
                     numInt = Integer.parseInt( numStr );
                     
                     // Verificando se o numero estah dentro da faixa
                     if ( numInt > 255 )
                        // Numero fora da faixa
                        estado = 0; // Indo para o estado de Erro
                  }
               }
               
               else if ( chLido == '/' ) {
                  // Convertendo o numero encontrado de String
                  // para numerico.
                  numStr += chLido;
                  
                  // Verificando se o numero estah dentro da faixa
                  if ( numInt > 255 )
                     // Numero fora da faixa
                     estado = 0; // Indo para o estado de erro
                  
                  else
                     // Numero dentro da faixa
                     estado = 5; // Indo para o proximo estado
                  
                  // Limpando a String auxiliar
                  numStr = "";
               }
               
               break;
            
            case 5: // Estado final
               if ( Character.isDigit( chLido ) ) {
                  // Concatenando digitos ao fim da String
                  numStr += chLido;
                  
                  // Verificando se o fim do numero IP foi atingido
                  if ( i == parametro.length() - 1 ) {
                     // Convertendo o numero encontrado de String
                     // para numerico.
                     numInt = Integer.parseInt( numStr );
                     
                     // Verificando se o numero estah dentro da faixa
                     if ( ( numInt < 8 ) || ( numInt > 32 ) )
                        // Numero fora da faixa
                        estado = -2; // Indo para o estado de erro
                  }
               }
               else if ( chLido == '.' ) {
                  // Convertendo o numero encontrado de String
                  // para numerico.
                  numInt = Integer.parseInt( numStr );
                  
                  // Verificando se o numero estah dentro da faixa
                  if ( numInt != 255 )
                     // Numero fora da faixa
                     estado = -1; // Indo para o estado de erro
                  
                  else
                     // Numero dentro da faixa
                     estado = 6; // Indo para o proximo estado
                  
                  // Limpando a String auxiliar
                  numStr = "";
               }
               
               break;
            
            case 6:
               if ( Character.isDigit( chLido) )
                  // Concatenando digitos ao fim da String
                  numStr += chLido;
               
               else if ( chLido == '.' ) {
                  // Convertendo o numero encontrado de String
                  // para numerico.
                  numInt = Integer.parseInt( numStr );
                  
                  // Verificando se o numero estah dentro da faixa
                  if ( numInt > 255 )
                     // Numero fora da faixa
                     estado = -1; // Indo para o estado de erro
                  
                  else
                     // Numero dentro da faixa
                     estado = 7; // Indo para o proximo estado
                  
                  // Limpando a String auxiliar
                  numStr = "";
               }
               
               break;
            
            case 7:
               if ( Character.isDigit( chLido) )
                  // Concatenando digitos ao fim da String
                  numStr += chLido;
               
               else if ( chLido == '.' ) {
                  // Convertendo o numero encontrado de String
                  // para numerico.
                  numInt = Integer.parseInt( numStr );
                  
                  // Verificando se o numero estah dentro da faixa
                  if ( numInt > 255 )
                     // Numero fora da faixa
                     estado = -1; // Indo para o estado de erro
                  
                  else
                     // Numero dentro da faixa
                     estado = 8; // Indo para o proximo estado
                  
                  // Limpando a String auxiliar
                  numStr = "";
               }
               
               break;
            
            case 8: // Estado final
               if ( Character.isDigit( chLido ) ) {
                  // Concatenando digitos ao fim da String
                  numStr += chLido;
                  
                  // Verificando se o fim do numero IP foi atingido
                  if ( i == parametro.length() - 1 ) {
                     // Convertendo o numero encontrado de String
                     // para numerico.
                     numInt = Integer.parseInt( numStr );
                     
                     // Verificando se o numero estah dentro da faixa
                     if ( numInt > 255 )
                        // Numero fora da faixa
                        estado = -1; // Indo para o estado de Erro
                  }
               }
               
               break;
            
            default: // Estado de erro
               // Forcando a saida da iteracao
               i = parametro.length() - 1;
               
               break;
         } // switch
      } // for
      
      // Verificando qual foi o estado de saida da iteracao,
      // para poder saber qual serah o retorno da funcao.
      switch ( estado ) {
         case 4: // N.N.N.N
            return 1;
         
         case 5: // N.N.N.N/NO
            return 2;
         
          case 8: // N.N.N.N/NUM.N.N.N
            return 3;
         
         case 0: // Endereco IP invalido
            return 0;
         
         case -2: // Numero de bits da mascara invalido
            return -2;
         
         default : // Erro encontrado na mascara
            return -1;
      } // switch
   } // semantica
   
   /**
    * Método que verifica se uma máscara é válida para um endereço IP.
    * @param parametro O parâmetro a ser avalidado. Deve estar no padrão N.N.N.N/NO ou N.N.N.N/NUM.N.N.N.
    * @return Retorna:<br>
    *    <b>-3</b> - Caso a máscara passada no paràmetro seja inválida para o endereço IP especificado;<br>
    *    <b>-2</b> - Caso o número de bits da máscara contido no parâmetro seja inválido;<br>
    *    <b>-1</b> - Caso a máscara contida no parâmetro seja inválida;<br>
    *    <b>0</b> - Caso o endereço contido no parâmetro seja inválido;<br>
    *    <b>1</b> - Caso o parâmetro esteja sob a primeira forma;<br>
    *    <b>2</b> - Caso o parâmetro esteja sob a segunda forma;<br>
    *    <b>3</b> - Caso o parâmetro esteja sob a terceira forma;<br>
    */
   private static int verMascara ( String parametro, int forma )
   {
      int numInt; // Armazenarah os octetos no formato int
      
      String numStr = ""; // Armazenarah os octetos no formato String
      
      char classe; // Armazena a classe
      
      // Coletando o primeiro octeto para reconhecer a classe do endereço.
      for ( int i = 0; i < parametro.length(); i++ ) {
         if ( parametro.charAt( i ) != '.' )
            numStr += parametro.charAt( i );
         
         else
            break;
      }
      
      numInt = Integer.parseInt( numStr );
      
      // Limpando a String
      numStr = "";
      
      // Reconhecendo a classe
      if ( ( numInt >= 0 ) && ( numInt <= 127 ) )
         classe = 'A';
      
      else if ( ( numInt >= 128 ) && ( numInt <= 191 ) )
         classe = 'B';
      
      else if ( ( numInt >= 192 ) && ( numInt <= 223 ) )
         classe = 'C';
      
      else // Classes D ou E
         classe = 'D';
      
      // A avaliacao da mascara depende da classe encontrada.
      // No caso da classe A, nao eh necessario avalia-la,
      //    pois ela ja foi avaliada no metodo semantica.
      switch ( classe ) {
         case 'A':
            return forma;
         
         case 'B':
            if ( forma == 2 ) { // N.N.N.N/NO
               int i = 7; // Para varrer a String
               
               // Encontrando o inicio da mascara
               while ( parametro.charAt( i ) != '/' )
                  ++i;
               ++i;
               
               // Pegando o numero de bits da mascara
               while ( i < parametro.length() ) {
                  numStr += parametro.charAt( i );
                  ++i;
               }
                              
               numInt = Integer.parseInt( numStr );
               
               if ( numInt < 16 )
                  return -3;
               
               else
                  return forma;
            } // if
            else { // N.N.N.N/NUM.N.N.N
               int i = 7; // Para varrer a String
               
               // Deve-se pegar o segundo octeto da mascara
               // Encontrando o inicio da mascara
               while ( parametro.charAt( i ) != '/' )
                  ++i;
               ++i;
               
               // Encontrando o segundo octeto
               while ( parametro.charAt( i ) != '.' )
                  ++i;
               ++i;
               
               // Pegando o segundo octeto
               while ( parametro.charAt( i ) != '.' ) {
                  numStr += parametro.charAt( i );
                  ++i;
               }
               
               if ( numStr.equals( "255" ) )
                  return forma;
               else
                  return -3;
            } // else
         
         case 'C':
            if ( forma == 2 ) { // N.N.N.N/NO
               int i = 7; // Para varrer a String
               
               // Encontrando o inicio da mascara
               while ( parametro.charAt( i ) != '/' )
                  ++i;
               ++i;
               
               // Pegando o numero de bits da mascara
               while ( i < parametro.length() ) {
                  numStr += parametro.charAt( i );
                  ++i;
               }
                              
               numInt = Integer.parseInt( numStr );
               
               if ( numInt < 24 )
                  return -3;
               
               else
                  return forma;
            } // if
            else { // N.N.N.N/NUM.N.N.N
               int i = 7; // Para varrer a String
               
               // Deve-se pegar o segundo octeto da mascara
               // Encontrando o inicio da mascara
               while ( parametro.charAt( i ) != '/' )
                  ++i;
               ++i;
               
               // Encontrando o segundo octeto
               while ( parametro.charAt( i ) != '.' )
                  ++i;
               ++i;
               
               // Pegando o segundo octeto
               while ( parametro.charAt( i ) != '.' ) {
                  numStr += parametro.charAt( i );
                  ++i;
               }
               
               // Se o segundo octeto nao for igual a 255, o metodo termina com erro
               if ( ! numStr.equals( "255" ) )
                  return -3;
               
               // Encontrando o terceiro octeto
               while ( parametro.charAt( i ) != '.' )
                  ++i;
               ++i;
               
               // Pegando o terceiro octeto
               while ( parametro.charAt( i ) != '.' ) {
                  numStr += parametro.charAt( i );
                  ++i;
               }
               
               if ( numStr.equals( "255255" ) ) // A String nao foi limpa do segundo octeto
                  return forma;
               else
                  return -3;
            } // else
         
         default: // Classes D e E. As mascaras nao sao avaliadas.
            return forma;
      } // switch
   } // verMascara
} // Validacao
