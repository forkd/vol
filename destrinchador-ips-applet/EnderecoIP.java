/**
 * Classe que implementa rotinas que geram informações acerca de um endereço IP.
 * @author José Lopes de Oliveira Júnior
 * @version 1.0
 */
public class EnderecoIP {
   private String endereco, // O endereco IP em binario
      mascara; // A mascara do endereco IP, tambem em binario
   
   /**
    * Construtor que inicializa um objeto EnderecoIP com os valores padrões:<br>
    * <b>Endereço: </b>127.0.0.1<br>
    * <b>Máscara : </b>255.0.0.0
    */
   public EnderecoIP ()
   {
      endereco = "01111111000000000000000000000001"; // 127.0.0.1
      mascara  = "11111111000000000000000000000000"; // 255.0.0.0
   } // EnderecoIP
   
   /**
    * Construtor que inicializa um objeto EnderecoIP a partir de um parâmetro.
    * @param parametro O parâmetro pode estar nos padrões:<br>
    *    <b>N.N.N.N</b> - Instancia um objeto com o endereço especificado e a máscara natural dele.<br>
    *    <b>N.N.N.N/NO</b> - Instancia um objeto com o endereço especificado e a máscara com a 
    *       quantidade de bits especificada em NO.<br>
    *    <b>N.N.N.N/NUM.N.N.N</b> - Instancia um objeto com o endereço e com a máscara especificados.
    *    <i>Obs.: (0 <= N <= 255), (8 <= NO <= 32) e (NUM = 255).</i><br>
    * <b><i>Obs.: </b>Caso o parâmetro passado seja inválido, o objeto será instanciado com os valores 
    *    padrões da classe.</i>
    */
   public EnderecoIP ( String parametro )
   {
      // Invocando o outro construtor, com os valores padroes
      this();
      
      // Alterando os valores padroes para aqueles passados como parametro
      this.setEnderecoIP( parametro );
   } // EnderecoIP
   
   /**
    * Obtém o valor do atributo endereco do objeto.
    * @return Retorna o endereço IP na notação decimal.
    */
   public String getEndereco ()
   {
      return ConvIP.endToDec( this.endereco );
   } // getEndereco
   
   /**
    * Obtém o valor do atributo mascara do objeto.
    * @return Retorna a máscara na notação decimal.
    */
   public String getMascara ()
   {
      return ConvIP.endToDec( this.mascara );
   } // getEndereco
   
   /**
    * Altera o valor do endereço IP do objeto.
    * @param parametro O parâmetro pode estar nos padrões:<br>
    *    <b>N.N.N.N</b> - Altera o atributo endereco do objeto, atribuindo a ele a máscara natural 
    *       de sua classe.<br>
    *    <b>N.N.N.N/NO</b> - Altera o atributo endereco do objeto, atribuindo a ele a máscara com 
    *       a quantidade de bits especificada em NO.<br>
    *    <b>N.N.N.N/NUM.N.N.N</b> - Altera os atributos endereco e mascara do objeto.<br>
    *    <i>Obs.: (0 <= N <= 255), (8 <= NO <= 32) e (NUM = 255).</i>
    * @return Retorna:<br>
    *    <b>-3</b> - Caso a máscara passada no paràmetro seja inválida para o endereço IP especificado;<br>
    *    <b>-2</b> - Caso o número de bits da máscara contido no parâmetro seja inválido;<br>
    *    <b>-1</b> - Caso a máscara contida no parâmetro seja inválida;<br>
    *    <b>0</b> - Caso o endereço contido no parâmetro seja inválido;<br>
    *    <b>1</b> - Caso o parâmetro esteja sob a primeira forma;<br>
    *    <b>2</b> - Caso o parâmetro esteja sob a segunda forma;<br>
    *    <b>3</b> - Caso o parâmetro esteja sob a terceira forma;<br>
    * <b><i>Obs.: </b>Caso o endereço do parâmetro passado seja inválido, o objeto não terá seus valores
    *    alterados. Contudo, nos casos -3, -2 e -1, o endereço será alterado com a máscara natural da classe.</i>
    */
   public int setEnderecoIP ( String parametro )
   {      
      int avalia = LibVerIP.valida( parametro ); // Verficando a validade do parametro
      
      // Uma acao diferente serah tomada de acordo com o parametro
      switch ( avalia ) {
         case 1: // N.N.N.N
            // Atribuindo o valor do endereco do objeto
            this.endereco = ConvIP.endToBin( parametro );
            
            // Atribuindo o valor da mascara do objeto
            this.mascara = EnderecoIP.geraMascara( this.endereco );
            
            return avalia;
         
         case 2: // N.N.N.N/NO
            // Atribuindo o valor do endereco do objeto
            this.endereco = ConvIP.endToBin( EnderecoIP.obtemEndereco( parametro ) );
            
            // Encontrando o inicio do numero de bits da mascara no parametro
            int nb = Integer.parseInt( EnderecoIP.obtemMascara( parametro ) );
            
            // Atribuindo o valor da mascara do objeto
            this.mascara = EnderecoIP.geraMascara( nb );
            
            return avalia;
         
         case 3: // N.N.N.N/NUM.N.N.N
            // Atribuindo o valor do endereco do objeto
            this.endereco = ConvIP.endToBin( EnderecoIP.obtemEndereco( parametro ) );
            
            // Atribuindo o valor da mascara do objeto
            this.mascara = ConvIP.endToBin( EnderecoIP.obtemMascara( parametro ) );
            
            return avalia;
         
         case -1: case -2: case -3: // Mascara invalida, atribuindo a mascara natural da classe
            // Atribuindo o valor do endereco do objeto
            this.endereco = ConvIP.endToBin( EnderecoIP.obtemEndereco( parametro ) );
            
            // Atribuindo o valor da mascara do objeto
            this.mascara = EnderecoIP.geraMascara( this.endereco );
            
            return avalia;
         
         default: // Erro no endereco - nao altera os valores atuais
            return avalia;
      } // switch
   } // setEnderecoIP
   
   /**
    * Mostra a qual o objeto pertence.
    * @return Retorna a classe ['A','B','C','D','E'].
    */
   public char classe ()
   {
      // Obtendo o valor do primeiro octeto do endereco e convertendo-o para inteiro decimal
      int priOct = Integer.parseInt( EnderecoIP.toDecimal( 
         this.endereco.substring( 0, 8 ), 2 ) );
      
      if ( ( priOct >= 0 ) && ( priOct <= 127 ) )
         return 'A';
      
      // Classe B
      else if ( ( priOct >= 128 ) && ( priOct <= 191 ) )
         return 'B';
      
      // Classe C
      else if ( ( priOct >= 192 ) && ( priOct <= 223 ) )
         return 'C';
         
      // Classe D 
      else if ( ( priOct >= 224 ) && ( priOct <= 239 ) )
         return 'D';
      
      // Classe E
      else
         return 'E';
   } // classe
   
   /**
    * Mostra o tipo do endereço do objeto.
    * @return Retorna o tipo do endereço ['R' (Real, 'L' (Local),
    *    'A' (Todas as redes), 'B' (LoopBack)].
    */
   public char tipo ()
   {
      // Obtendo o valor do primeiro octeto do endereco e convertendo-o para inteiro decimal
      int priOct = Integer.parseInt( EnderecoIP.toDecimal( 
         this.endereco.substring( 0, 8 ), 2 ) ),
      
         // Pegando o segundo octeto
         segOct = Integer.parseInt( EnderecoIP.toDecimal(
            this.endereco.substring( 8, 16 ), 2 ) );
      
      // Verificando o valor do primeiro octeto
      switch ( priOct ) {
         default:
            return 'R';
         
         case 10:
            return 'L';
         
         case 172:
            if ( ( segOct >= 16 ) && ( segOct <= 31 ) )
               return 'L';
            else
               return 'R';
         
         case 192:
            if ( segOct == 168 )
               return 'L';
            else
               return 'R';
         
         case 127:
            return 'B';
            
         case 0:
            return 'A';
      } // switch
   } // tipo
   
   /**
    * Gera o endereço relativo de rede do endereço IP.
    * @return Retorna o endereço relativo de rede.
    */
   public String endRelRede ()
   {
      return ConvIP.endToDec( this.endRelRedeBin() );
   } // endRelRede
   
   /**
    * Gera o endereço relativo de rede do endereço IP.
    * @return Retorna o endereço relativo de rede.
    */
   public String endRelSR ()
   {
      return ConvIP.endToDec( this.endRelSRBin() );
   } // endRelSR
   
   /**
    * Gera o número relativo de rede do endereço IP.
    * @return Retorna o número relativo de rede.
    */
   public String numRelRede ()
   {
      return EnderecoIP.toDecimal( this.numRelRedeBin(), 2 );
   } // numRelRede
   
   /**
    * Gera o número relativo de sub-rede do endereço IP.
    * @return Retorna o número relativo de sub-rede.
    */
   public String numRelSR ()
   {
      return EnderecoIP.toDecimal( this.numRelSRBin(), 2 );
   } // numRelSR
   
   /**
    * Gera o número relativo de host do endereço IP.
    * @return Retorna o número relativo de host.
    */
   public String numRelHost ()
   {
      return EnderecoIP.toDecimal( this.numRelHostBin(), 2 );
   } // numRelHost
   
   /**
    * Exibe o endereço IP do objeto na notação binária.
    * @return Retorna o endereço IP em binário.
    */
   public String enderecoBin ()
   {
      return this.endereco;
   } // enderecoBin
   
   /**
    * Exibe a máscara do objeto na notação binária.
    * @return Retorna a máscara em binário.
    */
   public String mascaraBin ()
   {
      return this.mascara;
   } // mascaraBin
   
   /**
    * Gera o endereço relativo de rede em binário.
    * @return Retorna o endereço relativo de rede em binário.
    */
   public String endRelRedeBin ()
   {
      String retorno = "", // O retorno do metodo
         maskNatural; // A mascara natural do endereco
      
      int i = 0; // Para varrer a mascara natural
      
      // Gerando a mascara natural
      maskNatural = EnderecoIP.geraMascara( this.classe() );
      
      // Gerando o endereco relativo de rede
      while ( maskNatural.charAt( i ) == '1' ) {
         retorno += this.endereco.charAt( i );
         ++i;
      } // while
      
      // Completando o endereco relativo de rede com '0's.
      while ( i < 32 ) {
         retorno += '0';
         ++i;
      } // while
      
      return retorno;
   } // endRelRedeBin
   
   /**
    * Gera o endereço relativo de sub-rede em binário.
    * @return Retorna o endereço relativo de sub-rede em binário.
    */
   public String endRelSRBin ()
   {
      String retorno = ""; // O retorno do metodo
      
      int i = 0; // Para varrer a mascara
      
      // Gerando o endereco relativo de sub-rede
      while ( this.mascara.charAt( i ) == '1' ) {
         retorno += this.endereco.charAt( i );
         ++i;
      } // while
      
      // Completando o endereco relativo de sub-rede com '0's
      while ( i < 32 ) {
         retorno += '0';
         ++i;
      } // while
      
      return retorno;
   } // endRelSRBin
   
   /**
    * Gera o número relativo de rede do endereço IP, em binário.
    * @return Retorna o número relativo de rede em binário.
    */
   public String numRelRedeBin ()
   {
      String retorno = "", // O retorno do metodo
         maskNatural; // A mascara natural da classe do endereco
      
      int i = 0; // Para varrer a mascara natural e o endereco IP
      
      // Obtendo a mascara natural
      maskNatural = EnderecoIP.geraMascara( this.classe() );
      
      // Gerando o numero relativo de rede
      while ( maskNatural.charAt( i ) == '1' ) {
         retorno += this.endereco.charAt( i );
         ++i;
      } // while
      
      return retorno;
   } // numRelRede
   
   /**
    * Gera o número relativo de sub-rede do endereço IP, em binário.
    * @return Retorna o número relativo de sub-rede em binário.
    */
   public String numRelSRBin ()
   {
      String retorno = "", // O retorno do metodo
         maskNatural; // A mascara natural da classe do endereco
      
      int i = 0; // Para varrer as Strings
      
      // Gerando a mascara natural
      maskNatural = EnderecoIP.geraMascara( this.classe() );
      
      // Encontrando o fim dos bits '1' da mascara natural
      while ( maskNatural.charAt( i ) == '1' )
         ++i;
      
      // Gerando o numero relativo de sub-rede
      while ( this.mascara.charAt( i ) == '1' ) {
         retorno += this.endereco.charAt( i );
         ++i;
      } // while
      
      // Se não há bits no numero relativo de sub-rede devolve zero
      if ( retorno.length() > 0 )
         return retorno;
      else
         return "0";
   } // numRelSRBin
   
   /**
    * Gera o número relativo de host do endereço IP, em binário.
    * @return Retorna o número relativo de host do número IP.
    */
   public String numRelHostBin ()
   {
      String retorno = ""; // O retorno do metodo
      
      int i = 0; // Para varrer as Strings
      
      // Encontrando os '0's da máscara do endereco IP
      while ( this.mascara.charAt( i ) == '1' )
         ++i;
      
      // Gerando o numero relativo de host
      while ( i < this.mascara.length() ) {
         retorno += this.endereco.charAt( i );
         ++i;
      } // while
      
      return retorno;
   } // numRelHostBin
   
   // ---------------
   // Métodos PRIVATE
   // ---------------
   
   /**
    * Obtém a máscara natural da classe de um endereço IP passado como parâmetro.
    * @param endereco O endereço a ser avaliado. O endereço deve estar na notação binária.
    * @return Retorna a máscara natural da classe a qual o endereço pertence.
    */
   private static String geraMascara ( String endereco )
   {
      // Obtendo o valor do primeiro octeto do endereco e convertendo-o para inteiro decimal
      int priOct = Integer.parseInt( EnderecoIP.toDecimal( endereco.substring( 0, 8 ), 2 ) );
      
      // Classe A
      if ( ( priOct >= 0 ) && ( priOct <= 127 ) )
         return "11111111000000000000000000000000";
      
      // Classe B
      else if ( ( priOct >= 128 ) && ( priOct <= 191 ) )
         return "11111111111111110000000000000000";
      
      // Classe C
      else if ( ( priOct >= 192 ) && ( priOct <= 223 ) )
         return "11111111111111111111111100000000";
         
      // Classes D e E
      else
         return "00000000000000000000000000000000";
   } // geraMascara
   
   /**
    * Gera uma máscara na notação binária a partir do número de bits passado como parâmetro.
    * @param nBits O número de bits da máscara. Deve estar entre 8 e 32.
    * @return Retorna a máscara na notação binária.
    */
   private static String geraMascara ( int nBits )
   {
      String retorno = ""; // O retorno do metodo
      
      int i = 0; // Variavel de controle da iteracao
      
      // Colocando os '1's na mascara
      for (; i < nBits; i++ )
         retorno += '1';
      
      // Completando, se necessario, com '0's.
      for (; i < 32; i++ )
         retorno += '0';
      
      return retorno;
   } // geraMascara
   
   /**
    * Gera a máscara natural de uma classe, a partir da especificação da classe.
    * @param classe A classe, a partir de onde deve ser gerada a máscara.
    * @return Retorna a máscara natural da classe em binário.
    */
   private static String geraMascara ( char classe )
   {
      switch ( Character.toUpperCase( classe ) ) {
         case 'A':
            return "11111111000000000000000000000000";

         case 'B':
            return "11111111111111110000000000000000";

         case 'C':
            return "11111111111111111111111100000000";

          default: // Classes D e E nao tem mascara natural
            return "00000000000000000000000000000000";
      } // switch
   } // geraMascara
   
   /**
    * Obtém um endereço IP, a partir de um parâmtro passado.
    * @param parametro O parâmetro que contém o endereço IP. Pode estar nas formas:<br>
    *   <b>N.N.N.N/NO</b> e <b>N.N.N.N/NUM.N.N.N</b>.
    * @return Retorna o endereço IP contido no parâmetro passado.
    */
   private static String obtemEndereco ( String parametro )
   {
      String retorno = ""; // O retorno do metodo
      
      for ( int i = 0; i < parametro.length(); i++ ) {
         if ( parametro.charAt( i ) != '/' )
            retorno += parametro.charAt( i );
         else
            break;
      } // for
      
      return retorno;
   } // obtemEndereco
   
   /**
    * Obtém uma máscara, a partir de um parâmtro passado.
    * @param parametro O parâmetro que contém a máscra. Pode estar nas formas:<br>
    *   <b>N.N.N.N/NO</b> e <b>N.N.N.N/NUM.N.N.N</b>.
    * @return Retorna a máscara contida no parâmetro passado.
    */
   private static String obtemMascara ( String parametro )
   {
      int i = 7; // Usada para varrer o parametro
      String retorno = ""; // O retorno do metodo
      
      // Descobrindo o inicio da mascara
      while ( parametro.charAt( i ) != '/' )
         i++;
      i++;
      
      // Pegando a mascara
      for (; i < parametro.length(); i++ )
         retorno += parametro.charAt( i );
      
      return retorno;
   } // obtemMascara
   
   /**
    * Converte um número, de uma base qualquer, para a base dez.
    * @param num O número a ser convertido.
    * @param base A base na qual o número se encontra.
    * @return Retorna o número na base dez.
    */
   private static String toDecimal ( String num, int base )
   {
      int pos, exp;
      long n = 0;
      String aux = new String( num );
      
      for ( pos = aux.length() - 1, exp = 0; pos >= 0; pos--, exp++ )
         n += Math.pow( base, exp ) * Character.digit( aux.charAt( pos ), base );
   
      return Long.toString( n );
   } // toDecimal
} // EnderecoIP
