/**
 * Classe que implementa rotinas de conversão de bases entre endereços IP.
 * @author José Lopes de Oliveira Júnior
 * @version 1.0
 */
class ConvIP {
   /**
    * Converte um endereço IP, de sua notação em decimal, para sua notação em binário.
    * @param endereco O endereço a ser convertido.
    * @return Retorna o endereço na notação binária.
    */
   public static String endToBin ( String endereco )
   {
      String retorno = "", // O retorno do metodo
         auxDec = "", // Armazena octeto por octeto em decimal.
         auxBin = ""; // Armazena a conversao de decimal para binario de cada octeto
      
      int i = 0; // Usado para varrer o endereco e controlar a iteracao
      
      // Varre o endereco todo, convertendo-o para binario
      while ( i < endereco.length() ) {
         // Pegando numero por numero no formato decimal e armazenando em auxDec.
         while ( ( i < endereco.length() ) && ( endereco.charAt( i ) != '.' ) ) {
            auxDec += endereco.charAt( i );
            ++i;
         }
         ++i;
         
         // Convertendo o numero retirado de decimal pra binario.
         auxBin = decimalTo( auxDec, 2 );
         
         // Completando o numero binario com '0's para manter o formato de 8 bits
         while ( auxBin.length() < 8 ) {
            String aux = "";
            aux = auxBin;
            auxBin = '0' + aux;
         }
         
         // Concatenando o octeto gerado em retorno pra gerar o numero.
         retorno += auxBin;
         
         // Limpando auxBin pra que ela possa receber o proximo octeto.
         auxBin = "";
         auxDec = "";
      } // while
      
      return retorno;
   } // endToBin
   
   /**
    * Converte um endereço IP, de sua notação em binário, para sua notação em decimal.
    * @param endereco O endereço a ser convertido.
    * @return Retorna o endereço na notação decimal.
    */
   public static String endToDec ( String endereco )
   {
      String retorno = "", // O retorno do metodo
         auxDec = "", // Armazena octeto por octeto em decimal.
         auxBin = ""; // Armazena a conversao de decimal para binario de cada octeto
      
      int i = 0; // Variavel de controle da iteracao e de varredura do endereco
      
      // Varre o endereco todo, convertendo-o para binario
      while ( i < endereco.length() ) {
         // Pegando octeto por octeto no formato binario e armazenando em auxBin.
         while ( ( i != 8 ) && ( i != 16 ) && ( i != 24 ) && ( i != 32 ) ) {
            auxBin += endereco.charAt( i );
            ++i;
         }
         
         // Convertendo o octeto retirado, de binario pra decimal.
         auxDec = toDecimal( auxBin, 2 );
         
         // Concatenando o numero gerado em retorno, para gerar a saida.
         retorno += auxDec;
         
         // Limpando auxBin pra que ela possa receber o proximo octeto.
         auxBin = "";
         auxDec = "";
         
         // Pegando um numero para que a variavel i saia da condicao de
         //   escape do laco while acima.
         // Se ainda nao se chegou ao ultimo octeto, deve-se acrescentar
         //   o '.'
         if ( i < 31 ) {
            auxBin += endereco.charAt( i );
            ++i;
            
            retorno += '.';
         }
      } // while
      
      return retorno;
   } // endToDec
   
   /**
    * Converte um número na base dez para outra base qualquer.
    * @param num O número a ser convertido.
    * @param base A base onde o número deverá estar.
    * @return Retorna o número na base especificada.
    */
   protected static String decimalTo ( String num, int base )
   {
      long n = Long.parseLong( num );
      String retorno = "";
      
      while ( n >= base ) {
         if ( n % base < 9 )
            retorno = ( n % base ) + retorno;
         else
            retorno = Character.forDigit( ( byte ) ( n % base ), base ) + retorno;
         n /= base;
      }
   
      if ( n < 9 )
         retorno = n + retorno;
      else
         retorno = Character.forDigit( ( byte ) ( n % base ), base ) + retorno;
      
      return retorno;
   } // decimalTo
   
   /**
    * Converte um número, de uma base qualquer, para a base dez.
    * @param num O número a ser convertido.
    * @param base A base na qual o número se encontra.
    * @return Retorna o número na base dez.
    */
   protected static String toDecimal ( String num, int base )
   {
      int pos, exp;
      long n = 0;
      String aux = new String( num );
      
      for ( pos = aux.length() - 1, exp = 0; pos >= 0; pos--, exp++ )
         n += Math.pow( base, exp ) * Character.digit( aux.charAt( pos ), base );
   
      return Long.toString( n );
   } // toDecimal
} // Conversao
