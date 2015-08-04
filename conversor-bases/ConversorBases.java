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
      
      lblRadEntrada = new JLabel( "Radical do n�mero de entrada" );
      cmbBoxRadEntrada = new JComboBox( radicais );
      cmbBoxRadEntrada.setSelectedIndex( 8 );
      container.add( lblRadEntrada );
      container.add( cmbBoxRadEntrada );
      
      lblNumEntrada = new JLabel( "N�mero de entrada" );
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
		     "Entre com um n�mero v�lido.",
		     "N�mero em branco",
		     JOptionPane.ERROR_MESSAGE );
		  
		  //txtFldNumEntrada.setFocus();
	       }
	       else if ( resultado == 2 ) {
	          JOptionPane.showMessageDialog( null,
		     "O n�mero deve conter APENAS d�gitos v�lidos.",
		     "Caractere inv�lido",
		     JOptionPane.ERROR_MESSAGE );
		  
		  //txtFldNumEntrada.setFocus();
	       }
	       else if ( resultado == 3 ) {
	          JOptionPane.showMessageDialog( null,
		     "Cada d�gito do n�mero deve ser MENOR que o radical.",
		     "N�mero inv�lido para o radical especificado",
		     JOptionPane.ERROR_MESSAGE );
	          
		  //txtFldNumEntrada.setFocus();
	       }
	    }
	 } // Fim da classe anonima
      );
      
      container.add( txtFldNumEntrada );
      
      lblRadSaida = new JLabel( "Radical do n�mero de sa�da" );
      cmbBoxRadSaida = new JComboBox( radicais );
      container.add( lblRadSaida );
      container.add( cmbBoxRadSaida );
      
      lblNumSaida = new JLabel( "N�mero de sa�da" );
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
		     "Entre com um n�mero v�lido.",
		     "N�mero em branco",
		     JOptionPane.ERROR_MESSAGE );
	       }
	       else if ( resultado == 2 ) {
	          JOptionPane.showMessageDialog( null,
		     "O n�mero deve conter APENAS d�gitos v�lidos.",
		     "Caractere inv�lido",
		     JOptionPane.ERROR_MESSAGE );
	       }
	       else if ( resultado == 3 ) {
	          JOptionPane.showMessageDialog( null,
		     "Cada d�gito do n�mero deve ser MENOR que o radical.",
		     "N�mero inv�lido para o radical especificado",
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
         "Para fazer a convers�o entre radicais (bases) de um n�mero, selecione\n" +
	 "em \"Radical do n�mero de entrada\", a base em que o n�mero se encontra.\n" +
	 "Digite o n�mero em \"N�mero de entrada\", escolha o radical em que o\n" +
	 "n�mero dever� estar ap�s a convers�o e clique no bot�o \"Converter\".\n\n" +
	 "Lembre-se de que cada d�gito do n�mero de entrada deve ser MENOR que o\n" +
	 "radical do n�mero de entrada e que s�o aceitos APENAS d�gitos e letras\n" +
	 "na composi��o dos n�meros.\n\n" +
	 "Para converter um n�mero de uma base pra outra manualmente, converta o\n" +
	 "n�mero inicial para a base 10, multiplicando, da esquerda pra direita\n" +
	 "(de quem olha para o n�mero) cada d�gito (entenda como d�gito as letras,\n" +
	 "se comporem o n�mero, tamb�m) pelo radical em que ele se encontra. Some\n" +
	 "todos os valores obtidos e voc� ter� o n�mero no radical 10. Com este n�-\n" +
	 "mero em m�os, divida-o pela base em que ele deve ficar sucessivamente at�\n" +
	 "que o quociente seja menor que o radical. Feito isso, concatene, na ordem\n" +
	 "inversa com que foram obtidos, o �ltimo quociente e todos os restos das di-\n" +
	 "vis�es. O n�mero obtido com esta concatena��o � o n�mero na base final."
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