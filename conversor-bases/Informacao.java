import javax.swing.JOptionPane;

/**
 * @author Jos� Lopes de Oliveira J�nior
 */
public class Informacao {
   private static String nomePrograma = "",
      versaoPrograma = "",
      textoAjuda = "";
   
   // Metodos GET
   
   /**
    * Obt�m o nome do programa.
    */
   public static String getNomePrograma ()
   {
      return nomePrograma;
   }
   
   /**
    * Obt�m a vers�o do programa.
    */
   public static String getVersaoPrograma ()
   {
      return versaoPrograma;
   }
   
   // Metodos SET
   
   /**
    * Altera o nome do programa.
    */
   public static void setNomePrograma ( String nome )
   {
      nomePrograma = nome;
   }
   
   /**
    * Altera o texto da ajuda.
    */
   public static void setTextoAjuda ( String tA )
   {
      textoAjuda = tA;
   }
   
   /**
    * Altera a vers�o do programa.
    */
   public static void setVersaoPrograma ( String versao )
   {
      versaoPrograma = versao;
   }
   
   /**
    * Exibe a janela de ajuda do programa.
    */
   public static void janelaAjuda ()
   {
      JOptionPane.showMessageDialog( null,
         textoAjuda,
	 nomePrograma + " - Ajuda",
	 JOptionPane.WARNING_MESSAGE );
   }
   
   /**
    * Exibe a janela de cr�ditos do programa.
    */
   public static void janelaSobre ()
   {
      JOptionPane.showMessageDialog( null,
         nomePrograma + " " + versaoPrograma + "\n" +
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
	 nomePrograma + " - Sobre",
	 JOptionPane.INFORMATION_MESSAGE );
   } // Fim do metodo janelaSobre
} // Fim da classe Informacao