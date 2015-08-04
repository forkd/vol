// Importando os metodos da classe swing
import javax.swing.*;

// Importando os metodos da classe awt
import java.awt.*;

// Importando os metods da classe events
import java.awt.event.*;

/**
 * Classe que implementa a interface com o usuário do programa DIP (Destrinchador de IPs).
 * @author José Lopes de Oliveira Júnior
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
      lblMascara = new JLabel( "Máscara" ),
      lblClasse = new JLabel( "Classe" ),
      lblTipo = new JLabel( "Tipo" ),
      lblEndRelSR = new JLabel( "Endereco relativo de sub-rede" ),
      lblEndRelRede = new JLabel( "Endereco relativo de rede" ),
      lblNumRelHost = new JLabel( "Número relativo de host" ),
      lblNumRelSR = new JLabel( "Número relativo de sub-rede" ),
      lblNumRelRede = new JLabel( "Número relativo de rede" ),
      lblEnderecoBin = new JLabel( "Endereco em binário" ),
      lblMascaraBin = new JLabel( "Máscara em binário" ),
      lblEndRelSRBin = new JLabel( "Endereco relativo de sub-rede em binário" ),
      lblEndRelRedeBin = new JLabel( "Endereco relativo de rede em binário" ),
      lblNumRelHostBin = new JLabel( "Número relativo de host em binário" ),
      lblNumRelSRBin = new JLabel( "Número relativo de sub-rede em binário" ),
      lblNumRelRedeBin = new JLabel( "Número relativo de rede em binário" ),
      lblEstado = new JLabel();
   
   // Os campos de texto
   private JTextField tfEntrada = new JTextField( "Entre com o número IP aqui.", 32 ),
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
    * Método responsável por inicializar a applet, inserindo e organizando os componentes na mesma.
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
    * Implementa as ações que devem ser tomadas para cada evento disparado.
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
    * Implementa a ação realizada quando o botão Ok é acionado.
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
    * Implementa a ação realizada quando o botão Ajuda é acionado.
    */
   private void actionAjuda ()
   {
      JOptionPane.showMessageDialog( null,
         "Formatos de entrada aceitos:\n" +
         "N.N.N.N ou N.N.N.N/NO ou N.N.N.N/NUM.N.N.N\n" +
         "onde: (0 <= N <= 255), (8 <= NO <= 32) e (NUM = 255).\n\n" +
         "Caso a máscara não seja especificada na entrada ou caso a mesma seja inválida, a más-\n" +
         "cara natural da classe do endereço especificado será adotada.\n" +
         "A máscara pode ser especificada no formato padrão (N.N.N.N) ou somente a sua quanti-\n" +
         "dade de bits pode ser passada.\n\n" +
         "Saída gerada:\n" +
         "- Endereço: é o próprio endereço IP especificado na notação decimal.\n" +
         "- Máscara: é a máscara à qual pertence o endereço IP especificado na notação decimal.\n" +
         "- Classe: é a classe à qual pertence o enderço IP [A, B, C, D, E].\n" +
         "- Tipo: é o tipo do endereço [Real ou Local].\n" +
         "- Número relativo de host: é o número relativo do host do endereço IP.\n" +
         "- Número relativo de sub-rede: é o número relativo da sub-rede do endereço IP.\n" +
         "- Número relativo de rede: é o número relativo da rede do endereço IP.\n" +
         "- Endereço relativo de sub-rede: é o endereço relativo da sub-rede do endereço IP na\n" +
         "   notação decimal.\n" +
         "- Endereço relativo de rede: é o endereço relativo da rede do endereço IP na notação\n" +
         "   decimal.\n" +
         "- Endereço em binário: é o próprio endereço IP na notação binária.\n" +
         "- Máscara em binário: é a máscara à qual pertence o endereço IP na notação binária.\n" +
         "- Endereço relativo de sub-rede: é o endereço relativo da sub-rede do endereço IP na\n" +
         "   notação binária.\n" +
         "- Endereço relativo de rede: é o endereço relativo da rede do endereço IP na notação\n" +
         "   binária.\n",
         "Destrinchador de IPs - Ajuda",
         JOptionPane.WARNING_MESSAGE );
   } // actionAjuda
   
   /**
    * Implementa a ação realizada quando o botão Sobre é acionado.
    */
   private void actionSobre ()
   {
      JOptionPane.showMessageDialog( null,
         "DIP - Destrinchador de IPs versão 0.5\n" +
         "Escrito por José Lopes de Oliveira Júnior. <jlojunior@gmail.com>\n\n" +
         "Copyright (C) 2005\n" +
         "Este programa é um software de livre distribuição, que pode ser copiado\n" +
         "e distribuído sob os termos da Licença Geral GNU, conforme publicada pe-\n" +
         "la Free Software Foundation, versão 2 da licença, ou (a critério do au-\n" +
         "tor) qualquer versão posterior.\n" +
         "Este programa é distribuído na expectativa de ser útil aos seus usuários,\n" +
         "porém NÃO POSSUI NENHUMA GARANTIA, EXPLÍCITA OU IMPLÍCITA, CO-\n" +
         "MERCIAL OU DE ATENDIMENTO A UMA DETERMINADA FINALIDADE.\n" +
         "Consulte a Licença Pública Geral GNU.",
         "Destrinchador de IPs - Sobre",
         JOptionPane.INFORMATION_MESSAGE );
   } // actionSobre
   
   /**
    * Gera uma mensagem a ser exibida na barra de status.
    * @param codigo O Código da mensagem a ser exibida. Caso o código seja inválido, a mensagem
    *    padrão é exibida.
    */
   private void msgEstado ( int codigo )
   {
      switch ( codigo ) {
         case -3: // Mensagem de erro
            lblEstado.setForeground( Color.RED );
            lblEstado.setText( "Máscara inválida para o endereço IP especificado. " +
               "Usando a máscara natural da classe." );
            break;
         
         case -2: // Mensagem de erro
            lblEstado.setForeground( Color.RED );
            lblEstado.setText( "Número de bits inválido para o endereço IP especificado. " +
               "Usando o número de bits natural da classe." );
            break;
         
         case -1: // Mensagem de erro
            lblEstado.setForeground( Color.RED );
            lblEstado.setText( "Máscara inválida. Usando a máscara natural da classe." );
            break;
         
         case 0: // Mensagem de erro
            lblEstado.setForeground( Color.RED );
            lblEstado.setText( "Endereço IP inválido. Usando os valores padrões. Consulte a ajuda." );
            break;
         
         case 1: // Mensagem de aviso
            lblEstado.setForeground( Color.GRAY );
            lblEstado.setText( "Máscara não especificada. Usando a máscara natural da classe." );
            break;
         
         default: // Mensagem padrao
            lblEstado.setForeground( Color.BLACK );
            lblEstado.setText( "Entre com um endereço IP válido e " +
               "clique no botão Ok para destrinchá-lo." );
      } // switch
   } // msgEstado
} // InterfaceDip
