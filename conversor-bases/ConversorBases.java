// Pacotes do nucleo de Java
import java.awt.*;
import java.awt.event.*;

// Pacotes de extensao de Java
import javax.swing.*;

public class ConversorBases extends JFrame {
   Numero numero = new Numero(); // O objeto numero
   
   // Componentes da Interface Grafica com o Usuario
   private JButton btnAjuda, btnSobre, btnConverter, btnSair;
   private JComboBox cmbBoxRadEntrada, cmbBoxRadSaida;
   private JLabel lblNumEntrada, lblRadEntrada, lblNumSaida, lblRadSaida;
   private JTextField txtFldNumEntrada, txtFldNumSaida;
   
   // Construtor da classe
   public ConversorBases ()
   {
      super( Informacao.getNomePrograma() );
      
      String radicais[] = {
         "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13",
	 "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25",
	 "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36" };
      
      // Configura a GUI e o tratamento de eventos
      Container container = getContentPane();
      container.setLayout( new FlowLayout() );
      
      lblRadEntrada = new JLabel( "Radical do número de entrada" );
      cmbBoxRadEntrada = new JComboBox( radicais );
      cmbBoxRadEntrada.setSelectedIndex( 8 );
      container.add( lblRadEntrada );
      container.add( cmbBoxRadEntrada );
      
      lblNumEntrada = new JLabel( "Número de entrada" );
      container.add( lblNumEntrada );
      
      txtFldNumEntrada = new JTextField( 10 );
      
      txtFldNumEntrada.addActionListener(
         // Classe interna anonima
	 new ActionListener() {
	    // Tratamento do evento
	    public void actionPerformed ( ActionEvent actionEvent )
	    {
	       numero.setRadical( ( byte ) 
	          ( cmbBoxRadEntrada.getSelectedIndex() + 2 ) );
	       
	       int resultado = numero.setValor( txtFldNumEntrada.getText(),
	          numero.getRadical() );
	       
	       if ( resultado == 0 )
		  txtFldNumSaida.setText( numero.toRadical( ( byte ) 
		     ( cmbBoxRadSaida.getSelectedIndex() + 2 ) ) );
	       else if ( resultado == 1 ) {
	          JOptionPane.showMessageDialog( null,
		     "Entre com um número válido.",
		     "Número em branco",
		     JOptionPane.ERROR_MESSAGE );
		  
		  //txtFldNumEntrada.setFocus();
	       }
	       else if ( resultado == 2 ) {
	          JOptionPane.showMessageDialog( null,
		     "O número deve conter APENAS dígitos válidos.",
		     "Caractere inválido",
		     JOptionPane.ERROR_MESSAGE );
		  
		  //txtFldNumEntrada.setFocus();
	       }
	       else if ( resultado == 3 ) {
	          JOptionPane.showMessageDialog( null,
		     "Cada dígito do número deve ser MENOR que o radical.",
		     "Número inválido para o radical especificado",
		     JOptionPane.ERROR_MESSAGE );
	          
		  //txtFldNumEntrada.setFocus();
	       }
	    }
	 } // Fim da classe anonima
      );
      
      container.add( txtFldNumEntrada );
      
      lblRadSaida = new JLabel( "Radical do número de saída" );
      cmbBoxRadSaida = new JComboBox( radicais );
      container.add( lblRadSaida );
      container.add( cmbBoxRadSaida );
      
      lblNumSaida = new JLabel( "Número de saída" );
      txtFldNumSaida = new JTextField( 15 );
      txtFldNumSaida.setEditable( false );
      container.add( lblNumSaida );
      container.add( txtFldNumSaida );
      
      btnAjuda = new JButton( "Ajuda" );
      
      btnAjuda.addActionListener(
         // Classe interna anonima
	 new ActionListener() {
	    // Tratamento do evento
	    public void actionPerformed ( ActionEvent actionEvent )
	    {
	       Informacao.janelaAjuda();
	    }
	 } // Fim da classe anonima
      );
      
      container.add( btnAjuda );
      
      btnSobre = new JButton( "Sobre" );
      
      btnSobre.addActionListener(
         // Classe interna anonima
	 new ActionListener() {
	    // Tratamento do evento
	    public void actionPerformed ( ActionEvent actionEvent )
	    {
	       Informacao.janelaSobre();
	    }
	 } // Fim da classe anonima
      );
      
      container.add( btnSobre );
      
      btnConverter = new JButton( "Converter" );
      
      btnConverter.addActionListener(
         // Classe interna anonima
	 new ActionListener() {
	    // Tratamento do evento
	    public void actionPerformed ( ActionEvent actionEvent )
	    {
	       numero.setRadical( ( byte ) 
	          ( cmbBoxRadEntrada.getSelectedIndex() + 2 ) );
	       
	       int resultado = numero.setValor( txtFldNumEntrada.getText(),
	          numero.getRadical() );
	       
	       if ( resultado == 0 )
		  txtFldNumSaida.setText( numero.toRadical( ( byte ) 
		     ( cmbBoxRadSaida.getSelectedIndex() + 2 ) ) );
	       else if ( resultado == 1 ) {
	          JOptionPane.showMessageDialog( null,
		     "Entre com um número válido.",
		     "Número em branco",
		     JOptionPane.ERROR_MESSAGE );
	       }
	       else if ( resultado == 2 ) {
	          JOptionPane.showMessageDialog( null,
		     "O número deve conter APENAS dígitos válidos.",
		     "Caractere inválido",
		     JOptionPane.ERROR_MESSAGE );
	       }
	       else if ( resultado == 3 ) {
	          JOptionPane.showMessageDialog( null,
		     "Cada dígito do número deve ser MENOR que o radical.",
		     "Número inválido para o radical especificado",
		     JOptionPane.ERROR_MESSAGE );
	       }
	    }
	 } // Fim da classe anonima
      );
      
      container.add( btnConverter );
      
      btnSair = new JButton( "Sair" );
      
      btnSair.addActionListener(
         // Classe interna anonima
	 new ActionListener() {
	    // Tratamento do evento
	    public void actionPerformed ( ActionEvent actionEvent )
	    {
	       System.exit( 0 );
	    }
	 } // Fim da classe anonima
      );
      
      container.add( btnSair );
      
      setSize( 570, 120 ); // Configura as dimensoes da janela
      setResizable( false ); // Nao permite o redimensionamento da janela
      show(); // Mostra a janela
   } // Fim do Construtor
   
   // Executa o aplicativo
   public static void main ( String args[] )
   {
      Informacao.setNomePrograma( "Conversor de Bases" );
      Informacao.setVersaoPrograma( "0.5" );
      Informacao.setTextoAjuda(
         "Para fazer a conversão entre radicais (bases) de um número, selecione\n" +
	 "em \"Radical do número de entrada\", a base em que o número se encontra.\n" +
	 "Digite o número em \"Número de entrada\", escolha o radical em que o\n" +
	 "número deverá estar após a conversão e clique no botão \"Converter\".\n\n" +
	 "Lembre-se de que cada dígito do número de entrada deve ser MENOR que o\n" +
	 "radical do número de entrada e que são aceitos APENAS dígitos e letras\n" +
	 "na composição dos números.\n\n" +
	 "Para converter um número de uma base pra outra manualmente, converta o\n" +
	 "número inicial para a base 10, multiplicando, da esquerda pra direita\n" +
	 "(de quem olha para o número) cada dígito (entenda como dígito as letras,\n" +
	 "se comporem o número, também) pelo radical em que ele se encontra. Some\n" +
	 "todos os valores obtidos e você terá o número no radical 10. Com este nú-\n" +
	 "mero em mãos, divida-o pela base em que ele deve ficar sucessivamente até\n" +
	 "que o quociente seja menor que o radical. Feito isso, concatene, na ordem\n" +
	 "inversa com que foram obtidos, o último quociente e todos os restos das di-\n" +
	 "visões. O número obtido com esta concatenação é o número na base final."
      );
      
      ConversorBases aplicacao = new ConversorBases();
      
      aplicacao.addWindowListener (
         // Classe interna anonima
	 new WindowAdapter () {
	    // Trata o evento quando o usuario fechar a janela
	    public void windowClosing ( WindowEvent windowEvent )
	    {
	       System.exit( 0 );
	    }
	 }
      );
   } // Fim do metodo main
} // Fim da classe ConversorBases