/**
 * @author José Lopes de Oliveira Júnior
 * @date 2005/set
 */
public class Numero {
   private byte radical; // O Radical (base) do numero
   private String valor; // O Valor do numero
   
   /**
    * Obtém o valor do radical.
    */
   public byte getRadical ()
   {
      return radical;
   }
   
   /**
    * Obtém o valor do numero.
    */
   public String getValor ()
   {
      return valor;
   }
   
   /**
    * Altera o valor do radical.
    */
   public void setRadical ( byte r )
   {
      if ( ( r >= 2 ) && ( r <= 36 ) )
         radical = r;
      else
         radical = 10;
   }
   
   /**
    * Altera o valor do valor do numero, baseado no radical informado.
    */
   public byte setValor ( String v, byte r )
   {
      byte resultado = verValor( v, r );
      
      if ( resultado == 0 )
         valor = v;
      else
         valor = "0";
      
      return resultado;
   }
   
   /**
    * Converte o valor do número corrente para sua representação
    * no radical passado como parâmetro.
    */
   public String toRadical ( byte r )
   {
      String aux = new String( valor );
      
      if ( radical == r )
         return String.valueOf( aux );
      else if ( radical == 10 )
         return decPara( String.valueOf( aux ), r );
      else if ( r == 10 )
         return paraDec( String.valueOf( aux ), radical );
      else
         return decPara( paraDec( String.valueOf( aux ), radical ), r );
   }
   
   /**
    * Verifica se o valor do número é correspondente ao radical.
    */
   private byte verValor ( String v, byte r )
   {
      String val = new String ( v );
      
      // Verificando se algo foi digitado
      if ( val.length() > 0 ) {
         
	 // Verificando cada digito do numero de entrada
	 for ( int pos = 0; pos < val.length(); pos++ ) {
            
	    // Podem haver apenas letras ou digitos no numero
	    if ( Character.isDigit( val.charAt( pos ) ) ||
	       Character.isLetter( val.charAt( pos ) ) ) {
	       
		  // Verificando se o digito condiz com a base especificada
		  if ( Character.digit( val.charAt( pos ), 36 ) >= r )
	             return ( byte ) 3;
	    }
	    else
	       return ( byte ) 2; // Caracter invalido
         } // For
         
         return ( byte ) 0; // Valor valido
      }
      else
         return ( byte ) 1; // Valor nulo
   }
   
   /**
    * Converte um número de decimal para uma base qualquer.
    */
   private String decPara ( String num, byte base )
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
   }

   
   /**
    * Converte um número, de uma base qualquer, para decimal.
    */
   private String paraDec ( String num, byte base )
   {
      int pos, exp;
      long n = 0;
      String aux = new String( num );
      
      for ( pos = aux.length() - 1, exp = 0; pos >= 0; pos--, exp++ )
	    n += Math.pow( base, exp ) * Character.digit( aux.charAt( pos ), base );
   
      return Long.toString( n );
   }
} // Fim da classe Numero