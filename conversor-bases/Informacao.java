import javax.swing.JOptionPane;

/**
 * @author José Lopes de Oliveira Júnior
 */
public class Informacao {
   private static String nomePrograma = "",
      versaoPrograma = "",
      textoAjuda = "";
   
   // Metodos GET
   
   /**
    * Obtém o nome do programa.
    */
   public static String getNomePrograma ()
   {
      return nomePrograma;
   }
   
   /**
    * Obtém a versão do programa.
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
    * Altera a versão do programa.
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
    * Exibe a janela de créditos do programa.
    */
   public static void janelaSobre ()
   {
      JOptionPane.showMessageDialog( null,
         nomePrograma + " " + versaoPrograma + "\n" +
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
	 nomePrograma + " - Sobre",
	 JOptionPane.INFORMATION_MESSAGE );
   } // Fim do metodo janelaSobre
} // Fim da classe Informacao