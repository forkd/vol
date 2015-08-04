// Pacotes do nucleo de Java
import java.awt.*;
import java.awt.event.*;

// Pacotes de extensao de Java
import javax.swing.*;

public class Morsenizer extends JFrame {
   // Dados do programa
   private final String NOMEPROGRAMA = "Morsenizer",
      VERSAOPROGRAMA = "0.5";
   
   private String entrada, // O texto de entrada
      saida; // O texto de saida
   
   // Componentes graficos da interface com o usuario
   private JLabel lblEntrada, lblSaida;
   private JTextField txtFldEntrada, txtFldSaida;
   private JButton btnAjuda, btnSobre;
   
   // O construtor da classe
   public Morsenizer ()
   {
      super( "Morsenizer" );
      
      Container container = getContentPane();
      container.setLayout( new FlowLayout() );
      
      lblEntrada =
         new JLabel ( "Digite a String a ser convertida e tecle <ENTER>" );
      container.add( lblEntrada );
      
      txtFldEntrada = new JTextField( 20 );
      
      txtFldEntrada.addActionListener (
         new ActionListener () {
            // Tratando o evento do campo texto
	    public void actionPerformed ( ActionEvent event )
	    {
	       String s = event.getActionCommand();
	       entrada = String.valueOf( s );
	       constroiSaida();
	    }
	 }
      ); // Chamada final ao Action Listener
      
      container.add( txtFldEntrada );
      
      lblSaida =
         new JLabel ( "C�digo Morse equivalente" );
      container.add( lblSaida );
      
      txtFldSaida = new JTextField( 50 );
      txtFldSaida.setEditable( false );
      container.add( txtFldSaida );
      
      btnAjuda = new JButton( "Ajuda" );
      
      btnAjuda.addActionListener (
         new ActionListener () {
	    public void actionPerformed ( ActionEvent actionEvent )
	    {
	       JOptionPane.showMessageDialog( null,
	          "O c�digo Morse �, provavelmente, o mais famoso esquema de\n" +
		  "codifica��o de todos os tempos. Ele foi desenvolvido por\n" +
		  "Samuel Morse em 1832 para ser utilizado com o sistema de tel�grafo.\n" +
		  "O c�digo Morse associa uma s�rie de pontos e tra�os (um para\n" +
		  "cada letra do alfabeto, d�gito e alguns caracteres especiais).\n" +
		  "Em sistemas orientados por �udio, o ponto representa um som curto\n" +
		  "e o tra�o representa um som longo.\n" +
		  "A separa��o entre palavras � indicada por um espa�o, ou, simples-\n" +
		  "mente, a aus�ncia de um ponto ou tra�o. Em um sistema baseado em\n" +
		  "�udio, o espa�o � indicado por um per�odo breve de tempo durante\n" +
		  "o qual n�o se transmite nenhum som.\n" +
		  "\t\t\tTexto retirado do livro Java: Como Programar - 4a. edi��o",
		  "Ajuda",
		  JOptionPane.INFORMATION_MESSAGE );
	    }
	 }
      );
      
      container.add( btnAjuda );
      
      btnSobre = new JButton( "Sobre" );
      
      btnSobre.addActionListener (
         new ActionListener () {
	    public void actionPerformed ( ActionEvent actionEvent )
	    {
	       JOptionPane.showMessageDialog( null, 
	          NOMEPROGRAMA + " " + VERSAOPROGRAMA + "\n" +
	          "Escrito por Jos� Lopes de Oliveira J�nior. " +
	          "<jlojunior@gmail.com>\n\n" +
	          "Copyright (C) 2005\n" +
	          "\tEste programa � um software de livre distribui��o, que pode ser\n" +
                  "copiado e distribu�do sob os termos da Licen�a Geral GNU,\n" +
                  "conforme publicada pela Free Software Foundation, vers�o 2\n" +
                  "da licen�a, ou (a crit�rio do autor) qualquer vers�o posterior.\n" +
                  "\tEste programa � distribu�do na expectativa de ser �til aos seus\n" +
                  "usu�rios, por�m N�O POSSUI NENHUMA GARANTIA, EXPL�CITA OU\n" +
                  "IMPL�CITA, COMERCIAL OU DE ATENDIMENTO A UMA DETERMINADA\n" +
                  "FINALIDADE. Consulte a Licen�a P�blica Geral GNU.",
	          "Sobre",
	          JOptionPane.INFORMATION_MESSAGE );
	    }
	 }
      );
      
      container.add( btnSobre );
      
      setSize( 600, 125 ); // Configurando o tamanho da janela
      setResizable( false ); // Nao permitindo a alteracao das dimensoes da janela
      show(); // Mostra a janela
   }
   
   // Converte uma String de ASCII para Morse, retornando-a
   public String conversorASCIIMorse ( String stringASCII )
   {
      String retorno = "";
      
      for ( int i = 0; i < stringASCII.length(); i++ )
         switch ( Character.toUpperCase( stringASCII.charAt( i ) ) ) {
	    case 'A': retorno += ".- ";
	              break;
	    case 'B': retorno += "-... ";
	              break;
	    case 'C': retorno += "-.-. ";
	              break;
	    case 'D': retorno += "-.. ";
	              break;
	    case 'E': retorno += ". ";
	              break;
	    case 'F': retorno += "..-. ";
	              break;
	    case 'G': retorno += "--. ";
	              break;
	    case 'H': retorno += ".... ";
	              break;
	    case 'I': retorno += ".. ";
	              break;
	    case 'J': retorno += ".--- ";
	              break;
	    case 'K': retorno += "-.- ";
	              break;
	    case 'L': retorno += ".-.. ";
	              break;
	    case 'M': retorno += "-- ";
	              break;
	    case 'N': retorno += "-. ";
	              break;
	    case 'O': retorno += "--- ";
	              break;
	    case 'P': retorno += ".--. ";
	              break;
	    case 'Q': retorno += "--.- ";
	              break;
	    case 'R': retorno += ".-. ";
	              break;
	    case 'S': retorno += "... ";
	              break;
	    case 'T': retorno += "- ";
	              break;
	    case 'U': retorno += "..- ";
	              break;
	    case 'V': retorno += "...- ";
	              break;
	    case 'W': retorno += ".-- ";
	              break;
	    case 'X': retorno += "-..- ";
	              break;
	    case 'Y': retorno += "-.-- ";
	              break;
	    case 'Z': retorno += "--.. ";
	              break;
	    case '0': retorno += "----- ";
	              break;
	    case '1': retorno += ".--- ";
	              break;
	    case '2': retorno += "..--- ";
	              break;
	    case '3': retorno += "...-- ";
	              break;
	    case '4': retorno += "....- ";
	              break;
	    case '5': retorno += "..... ";
	              break;
	    case '6': retorno += "-.... ";
	              break;
	    case '7': retorno += "--... ";
	              break;
	    case '8': retorno += "---.. ";
	              break;
	    case '9': retorno += "----. ";
	              break;
	    
	    // O espaco em branco nao consta no codigo Morse.
	    // No codigo, o espaco em branco eh representado
	    //    por um intervalo de tempo sem transmissao de
	    //    informacoes.
	    case ' ': retorno += "   ";
	              break;
	    
	    default: // Caracter nao suportado
	             break;
	 } // switch
      
      return retorno; 
   }
   
   // Constroi as informacoes de saida do programa
   public void constroiSaida ()
   {
      saida = conversorASCIIMorse( entrada );
      txtFldSaida.setText( saida );
   }
   
   // Executa o aplicativo
   public static void main ( String args[] )
   {
      Morsenizer aplicacao = new Morsenizer();
      
      aplicacao.addWindowListener (
         new WindowAdapter() {
	    public void windowClosing ( WindowEvent windowEvent )
	    {
	       System.exit( 0 );
	    }
	 }
      );
   }
}