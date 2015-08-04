// Importando os metodos da classe swing
import javax.swing.*;

// Importando os metodos da classe awt
import java.awt.*;

// Importando os metods da classe events
import java.awt.event.*;

/**
 * Classe que implementa a interface com o usu�rio do programa DIP (Destrinchador de IPs).
 * @author Jos� Lopes de Oliveira J�nior
 */
public class InterfaceDIP extends JApplet implements ActionListener {
   // O endereco a ser manipulado pelo programa
   EnderecoIP enderecoIP = new EnderecoIP();
   
   // Os botoes usados na aplicacao
   private JButton btnOK = new JButton( "Ok" ),
      btnAjuda = new JButton( "Ajuda" ),
      btnSobre = new JButton( "Sobre" );
   
   // Os labels da aplicacao
   private JLabel lblTitulo = new JLabel( "Destrinchador de IPs" ),
      lblEndereco = new JLabel( "Endereco" ),
      lblMascara = new JLabel( "M�scara" ),
      lblClasse = new JLabel( "Classe" ),
      lblTipo = new JLabel( "Tipo" ),
      lblEndRelSR = new JLabel( "Endereco relativo de sub-rede" ),
      lblEndRelRede = new JLabel( "Endereco relativo de rede" ),
      lblNumRelHost = new JLabel( "N�mero relativo de host" ),
      lblNumRelSR = new JLabel( "N�mero relativo de sub-rede" ),
      lblNumRelRede = new JLabel( "N�mero relativo de rede" ),
      lblEnderecoBin = new JLabel( "Endereco em bin�rio" ),
      lblMascaraBin = new JLabel( "M�scara em bin�rio" ),
      lblEndRelSRBin = new JLabel( "Endereco relativo de sub-rede em bin�rio" ),
      lblEndRelRedeBin = new JLabel( "Endereco relativo de rede em bin�rio" ),
      lblNumRelHostBin = new JLabel( "N�mero relativo de host em bin�rio" ),
      lblNumRelSRBin = new JLabel( "N�mero relativo de sub-rede em bin�rio" ),
      lblNumRelRedeBin = new JLabel( "N�mero relativo de rede em bin�rio" ),
      lblEstado = new JLabel();
   
   // Os campos de texto
   private JTextField tfEntrada = new JTextField( "Entre com o n�mero IP aqui.", 32 ),
      tfEndereco = new JTextField( 32 ),
      tfMascara = new JTextField( 32 ),
      tfClasse = new JTextField( 32 ),
      tfTipo = new JTextField( 32 ),
      tfEndRelSR = new JTextField( 32 ),
      tfEndRelRede = new JTextField( 32 ),
      tfNumRelHost = new JTextField( 32 ),
      tfNumRelSR = new JTextField( 32 ),
      tfNumRelRede = new JTextField( 32 ),
      tfEnderecoBin = new JTextField( 32 ),
      tfMascaraBin = new JTextField( 32 ),
      tfEndRelSRBin = new JTextField( 32 ),
      tfEndRelRedeBin = new JTextField( 32 ),
      tfNumRelRedeBin = new JTextField( 32 ),
      tfNumRelSRBin = new JTextField( 32 ),
      tfNumRelHostBin = new JTextField( 32 );
   
   // Os painel de saida.
   private JPanel panelSaida = new JPanel();
   
   /**
    * M�todo respons�vel por inicializar a applet, inserindo e organizando os componentes na mesma.
    */
   public void init ()
   {
      // Adicionando o painel de cabecalho no topo da applet.
      this.getContentPane().add( lblTitulo, BorderLayout.NORTH );
      
      // Adicionando o painel de saida no centro da applet.
      this.getContentPane().add( panelSaida, BorderLayout.CENTER );
      
      // Adicionando o painel de rodape do fundo da applet.
      this.getContentPane().add( lblEstado, BorderLayout.SOUTH );
      
      // Alterando a cor de fundo da applet
      this.getContentPane().setBackground( Color.WHITE );
      
      // Alterando a cor de fundo de alguns componentes
      panelSaida.setBackground( Color.WHITE );
      tfEndereco.setBackground( Color.WHITE );
      tfMascara.setBackground( Color.WHITE );
      tfClasse.setBackground( Color.WHITE );
      tfTipo.setBackground( Color.WHITE );
      tfEndRelRede.setBackground( Color.WHITE );
      tfEndRelSR.setBackground( Color.WHITE );
      tfNumRelRede.setBackground( Color.WHITE );
      tfNumRelSR.setBackground( Color.WHITE );
      tfNumRelHost.setBackground( Color.WHITE );
      tfEnderecoBin.setBackground( Color.WHITE );
      tfMascaraBin.setBackground( Color.WHITE );
      tfEndRelRedeBin.setBackground( Color.WHITE );
      tfEndRelSRBin.setBackground( Color.WHITE );
      tfNumRelRedeBin.setBackground( Color.WHITE );
      tfNumRelSRBin.setBackground( Color.WHITE );
      tfNumRelHostBin.setBackground( Color.WHITE );
      
      // Tratando o centro.
      panelSaida.setLayout( new GridLayout( 18, 2 ) );
      
      // Dados de entrada.
      panelSaida.add( tfEntrada );
      panelSaida.add( btnOK );     
      
      // Dados de saida.
      panelSaida.add( lblEndereco );
      panelSaida.add( tfEndereco );
      panelSaida.add( lblMascara );
      panelSaida.add( tfMascara );
      panelSaida.add( lblClasse );
      panelSaida.add( tfClasse );
      panelSaida.add( lblTipo );
      panelSaida.add( tfTipo );
      panelSaida.add( lblEndRelRede );
      panelSaida.add( tfEndRelRede );
      panelSaida.add( lblEndRelSR );
      panelSaida.add( tfEndRelSR );
      panelSaida.add( lblNumRelRede );
      panelSaida.add( tfNumRelRede );
      panelSaida.add( lblNumRelSR );
      panelSaida.add( tfNumRelSR );
      panelSaida.add( lblNumRelHost );
      panelSaida.add( tfNumRelHost );
      panelSaida.add( lblEnderecoBin );
      panelSaida.add( tfEnderecoBin );
      panelSaida.add( lblMascaraBin );
      panelSaida.add( tfMascaraBin );
      panelSaida.add( lblEndRelRedeBin );
      panelSaida.add( tfEndRelRedeBin );
      panelSaida.add( lblEndRelSRBin );
      panelSaida.add( tfEndRelSRBin );
      panelSaida.add( lblNumRelRedeBin );
      panelSaida.add( tfNumRelRedeBin );
      panelSaida.add( lblNumRelSRBin );
      panelSaida.add( tfNumRelSRBin );
      panelSaida.add( lblNumRelHostBin );
      panelSaida.add( tfNumRelHostBin );
      
      // Informacoes
      panelSaida.add( btnAjuda );
      panelSaida.add( btnSobre );
      
      // Posicionando o nome do programa no centro da applet.
      lblTitulo.setHorizontalAlignment( JLabel.CENTER );
      
      // Tratando os Textfields de saida para que nao sejam editaveis pelo usuario.
      tfEndereco.setEditable( false );
      tfMascara.setEditable( false );
      tfClasse.setEditable( false );
      tfTipo.setEditable( false );
      tfEndRelRede.setEditable( false );
      tfEndRelSR.setEditable( false );
      tfNumRelHost.setEditable( false );
      tfNumRelSR.setEditable( false );
      tfNumRelRede.setEditable( false );
      tfEnderecoBin.setEditable( false );
      tfMascaraBin.setEditable( false );
      tfEndRelRedeBin.setEditable( false );
      tfEndRelSRBin.setEditable( false );
      tfNumRelRedeBin.setEditable( false );
      tfNumRelSRBin.setEditable( false );
      tfNumRelHostBin.setEditable( false );
      
      // Alterando o texto do label da barra de status para a mensagem padrao.
      msgEstado( 10 );
      
      // Deixando o texto da caixa de texto de entrada em negrito
      tfEntrada.setFont( new Font( "", Font.BOLD, 12 ) );
      
      // Selecionando todo o texto da caixa de texto de entrada.
      tfEntrada.selectAll();
      
      // Fazendo os devidos componentes ouvirem eventos do usuario.
      tfEntrada.addActionListener( this );
      btnOK.addActionListener( this );
      btnAjuda.addActionListener( this );
      btnSobre.addActionListener( this );
   } //init
   
   /**
    * Implementa as a��es que devem ser tomadas para cada evento disparado.
    */
   public void actionPerformed ( ActionEvent ae )
   {
      // Testando se o botao Ok foi acionado.
      if ( ( ae.getSource() == tfEntrada ) || ( ae.getSource() == btnOK ) )
         actionOK();
      
      // Testando se o botao Ajuda foi acionado.
      else if ( ae.getSource() == btnAjuda )
         actionAjuda();
      
      // Testando se o botao Sobre foi acionado.
      else if ( ae.getSource() == btnSobre )
         actionSobre();
   } // actionPerformed
   
   /**
    * Implementa a a��o realizada quando o bot�o Ok � acionado.
    */
   private void actionOK ()
   {
      int avalia = enderecoIP.setEnderecoIP( tfEntrada.getText() );
      
      // Enviando a mensagem padrao.
      if ( ( avalia == 2 ) || ( avalia == 3 ) )
         msgEstado( 10 );
      // Enviando mensagens especificas
      else
         msgEstado( avalia );
      
      // Mostrando o endereco IP instanciado
      tfEndereco.setText( enderecoIP.getEndereco() );
      
      // Mostrando mascara instanciada
      tfMascara.setText( enderecoIP.getMascara() );
      
      // Mostrando a classe a qual o endereco pertence
      tfClasse.setText( "" + enderecoIP.classe() );
      
      // Mostrando o tipo do endereco IP
      if ( enderecoIP.tipo() == 'R' )
         tfTipo.setText( "Real" );
      else if ( enderecoIP.tipo() == 'L' )
         tfTipo.setText( "Local" );
      else if ( enderecoIP.tipo() == 'A' )
         tfTipo.setText( "Todas as redes" );
      else
         tfTipo.setText( "Loopback" );
      
      // Mostrando o endereco relativo de rede
      tfEndRelRede.setText( enderecoIP.endRelRede() );
      
      // Mostrando o endereco relativo de sub-rede
      tfEndRelSR.setText( enderecoIP.endRelSR() );
      
      // Mostrando o numero relativo de rede
      tfNumRelRede.setText( enderecoIP.numRelRede() );
      
      // Mostrando o numero relativo de su-rede
      tfNumRelSR.setText( enderecoIP.numRelSR() );
      
      // Mostrando o numero relativo de host
      tfNumRelHost.setText( enderecoIP.numRelHost() );
      
      // Mostrando o endereco em binario
      tfEnderecoBin.setText( enderecoIP.enderecoBin() );
      
      // Mostrando a mascara em binario
      tfMascaraBin.setText( enderecoIP.mascaraBin() );
      
      // Mostrando o endereco relativo de rede em binario
      tfEndRelRedeBin.setText( enderecoIP.endRelRedeBin() );
      
      // Mostrando o endereco relativo de sub-rede em binario
      tfEndRelSRBin.setText( enderecoIP.endRelSRBin() );
      
      // Mostrando o numero relativo de rede em binario
      tfNumRelRedeBin.setText( enderecoIP.numRelRedeBin() );
      
      // Mostrando o numero relativo de su-rede em binario
      tfNumRelSRBin.setText( enderecoIP.numRelSRBin() );
      
      // Mostrando o numero relativo de host em binario
      tfNumRelHostBin.setText( enderecoIP.numRelHostBin() );
   } // actionOK
   
   /**
    * Implementa a a��o realizada quando o bot�o Ajuda � acionado.
    */
   private void actionAjuda ()
   {
      JOptionPane.showMessageDialog( null,
         "Formatos de entrada aceitos:\n" +
         "N.N.N.N ou N.N.N.N/NO ou N.N.N.N/NUM.N.N.N\n" +
         "onde: (0 <= N <= 255), (8 <= NO <= 32) e (NUM = 255).\n\n" +
         "Caso a m�scara n�o seja especificada na entrada ou caso a mesma seja inv�lida, a m�s-\n" +
         "cara natural da classe do endere�o especificado ser� adotada.\n" +
         "A m�scara pode ser especificada no formato padr�o (N.N.N.N) ou somente a sua quanti-\n" +
         "dade de bits pode ser passada.\n\n" +
         "Sa�da gerada:\n" +
         "- Endere�o: � o pr�prio endere�o IP especificado na nota��o decimal.\n" +
         "- M�scara: � a m�scara � qual pertence o endere�o IP especificado na nota��o decimal.\n" +
         "- Classe: � a classe � qual pertence o ender�o IP [A, B, C, D, E].\n" +
         "- Tipo: � o tipo do endere�o [Real ou Local].\n" +
         "- N�mero relativo de host: � o n�mero relativo do host do endere�o IP.\n" +
         "- N�mero relativo de sub-rede: � o n�mero relativo da sub-rede do endere�o IP.\n" +
         "- N�mero relativo de rede: � o n�mero relativo da rede do endere�o IP.\n" +
         "- Endere�o relativo de sub-rede: � o endere�o relativo da sub-rede do endere�o IP na\n" +
         "   nota��o decimal.\n" +
         "- Endere�o relativo de rede: � o endere�o relativo da rede do endere�o IP na nota��o\n" +
         "   decimal.\n" +
         "- Endere�o em bin�rio: � o pr�prio endere�o IP na nota��o bin�ria.\n" +
         "- M�scara em bin�rio: � a m�scara � qual pertence o endere�o IP na nota��o bin�ria.\n" +
         "- Endere�o relativo de sub-rede: � o endere�o relativo da sub-rede do endere�o IP na\n" +
         "   nota��o bin�ria.\n" +
         "- Endere�o relativo de rede: � o endere�o relativo da rede do endere�o IP na nota��o\n" +
         "   bin�ria.\n",
         "Destrinchador de IPs - Ajuda",
         JOptionPane.WARNING_MESSAGE );
   } // actionAjuda
   
   /**
    * Implementa a a��o realizada quando o bot�o Sobre � acionado.
    */
   private void actionSobre ()
   {
      JOptionPane.showMessageDialog( null,
         "DIP - Destrinchador de IPs vers�o 0.5\n" +
         "Escrito por Jos� Lopes de Oliveira J�nior. <jlojunior@gmail.com>\n\n" +
         "Copyright (C) 2005\n" +
         "Este programa � um software de livre distribui��o, que pode ser copiado\n" +
         "e distribu�do sob os termos da Licen�a Geral GNU, conforme publicada pe-\n" +
         "la Free Software Foundation, vers�o 2 da licen�a, ou (a crit�rio do au-\n" +
         "tor) qualquer vers�o posterior.\n" +
         "Este programa � distribu�do na expectativa de ser �til aos seus usu�rios,\n" +
         "por�m N�O POSSUI NENHUMA GARANTIA, EXPL�CITA OU IMPL�CITA, CO-\n" +
         "MERCIAL OU DE ATENDIMENTO A UMA DETERMINADA FINALIDADE.\n" +
         "Consulte a Licen�a P�blica Geral GNU.",
         "Destrinchador de IPs - Sobre",
         JOptionPane.INFORMATION_MESSAGE );
   } // actionSobre
   
   /**
    * Gera uma mensagem a ser exibida na barra de status.
    * @param codigo O C�digo da mensagem a ser exibida. Caso o c�digo seja inv�lido, a mensagem
    *    padr�o � exibida.
    */
   private void msgEstado ( int codigo )
   {
      switch ( codigo ) {
         case -3: // Mensagem de erro
            lblEstado.setForeground( Color.RED );
            lblEstado.setText( "M�scara inv�lida para o endere�o IP especificado. " +
               "Usando a m�scara natural da classe." );
            break;
         
         case -2: // Mensagem de erro
            lblEstado.setForeground( Color.RED );
            lblEstado.setText( "N�mero de bits inv�lido para o endere�o IP especificado. " +
               "Usando o n�mero de bits natural da classe." );
            break;
         
         case -1: // Mensagem de erro
            lblEstado.setForeground( Color.RED );
            lblEstado.setText( "M�scara inv�lida. Usando a m�scara natural da classe." );
            break;
         
         case 0: // Mensagem de erro
            lblEstado.setForeground( Color.RED );
            lblEstado.setText( "Endere�o IP inv�lido. Usando os valores padr�es. Consulte a ajuda." );
            break;
         
         case 1: // Mensagem de aviso
            lblEstado.setForeground( Color.GRAY );
            lblEstado.setText( "M�scara n�o especificada. Usando a m�scara natural da classe." );
            break;
         
         default: // Mensagem padrao
            lblEstado.setForeground( Color.BLACK );
            lblEstado.setText( "Entre com um endere�o IP v�lido e " +
               "clique no bot�o Ok para destrinch�-lo." );
      } // switch
   } // msgEstado
} // InterfaceDip
