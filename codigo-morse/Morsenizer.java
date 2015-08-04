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
         new JLabel ( "Código Morse equivalente" );
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
	          "O código Morse é, provavelmente, o mais famoso esquema de\n" +
		  "codificação de todos os tempos. Ele foi desenvolvido por\n" +
		  "Samuel Morse em 1832 para ser utilizado com o sistema de telégrafo.\n" +
		  "O código Morse associa uma série de pontos e traços (um para\n" +
		  "cada letra do alfabeto, dígito e alguns caracteres especiais).\n" +
		  "Em sistemas orientados por áudio, o ponto representa um som curto\n" +
		  "e o traço representa um som longo.\n" +
		  "A separação entre palavras é indicada por um espaço, ou, simples-\n" +
		  "mente, a ausência de um ponto ou traço. Em um sistema baseado em\n" +
		  "áudio, o espaço é indicado por um período breve de tempo durante\n" +
		  "o qual não se transmite nenhum som.\n" +
		  "\t\t\tTexto retirado do livro Java: Como Programar - 4a. edição",
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
	          "Escrito por José Lopes de Oliveira Júnior. " +
	          "<jlojunior@gmail.com>\n\n" +
	          "Copyright (C) 2005\n" +
	          "\tEste programa é um software de livre distribuição, que pode ser\n" +
                  "copiado e distribuído sob os termos da Licença Geral GNU,\n" +
                  "conforme publicada pela Free Software Foundation, versão 2\n" +
                  "da licença, ou (a critério do autor) qualquer versão posterior.\n" +
                  "\tEste programa é distribuído na expectativa de ser útil aos seus\n" +
                  "usuários, porém NÃO POSSUI NENHUMA GARANTIA, EXPLÍCITA OU\n" +
                  "IMPLÍCITA, COMERCIAL OU DE ATENDIMENTO A UMA DETERMINADA\n" +
                  "FINALIDADE. Consulte a Licença Pública Geral GNU.",
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