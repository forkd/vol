#!/bin/bash
#
# Distro Recognizer 0.05
# Description: Este script verifica qual � a distribui��o utilizada no computador
#    e informa o seu nome ao usu�rio.
# Author: Jos� Lopes de Oliveira J�nior
# Date: 2006/march
# NOTES: Dar permiss�o de execu��o ao arquivo ($ chmod 711 dr.sh).

# Verificando se foram passados paramentros
case "$1" in
   "-v")
      echo "Distro Recognizer 0.05"
      echo ""
      echo "Escrito por Jos� Lopes de Oliveira J�nior <jlojunior@gmail.com>"
      echo ""
      echo "   Este programa � um software de livre distribui��o, que pode ser"
      echo "copiado e distribu�do sob os termos da Licen�a Geral GNU, conforme"
      echo "publicada pela Free Software Foundation, vers�o 2 da lice�a, ou (a"
      echo "crit�rio do autor) qualquer vers�o posterior."
      echo "   Este programa � distribu�do na expectativa de ser �til aos seus"
      echo "usu�rios, por�m N�O POSSUI NENHUMA GARANTIA, EXPL�CITA OU IMPL�CI-"
      echo "TA, COMERCIAL OU DE ATENDIMENTO A UMA DETERMINADA FINALIDADE."
      echo "Consulte a Licen�a P�blica Geral GNU."
      
      exit 0
   ;;
   
   "-a")
      echo "Distro Recognizer"
      echo "   Este script verifica qual � a distribui��o Linux que est� insta-"
      echo "lada no computador onde for executado."
      
      exit 0
   ;;
   
   *)
      if [ ! -z $1 ]; then
         echo "Distro Recognizer: Op��o desconhecida."
         
         exit 1
      fi
   ;;
esac

# Verificando qual a distro que est� sendo utilizada.

# A id�ia b�sica utilizada nesta verifica��o � a de localizar o arquivo que
#    informa sobre o nome da distro e sua vers�o, em /etc.

# Variaveis a serem utilizadas
distro=""        # Armazena o nome da distro
distroDetails="" # Armazena o caminho para o arquivo de versao
desconhecida="y" # Desconhecida == "y". Reconhecida == "n"

# Verificando se � Debian Linux
if [ -a /etc/debian_version ]; then
   distro="Debian Linux"
   distroDetails="/etc/debian_version"
   desconhecida="n"

# Verificando se � Slackware Linux
elif [ -a /etc/slackware-version ]; then
   distro="Slackware Linux"
   distroDetails="/etc/slackware-version"
   desconhecida="n"

# Verificando se � Red Hat Linux
elif [ -a /etc/redhat-release ]; then
   distro="Red Hat Linux"
   distroDetails="/etc/redhat-release"
   desconhecida="n"

# Verificando se � Conectiva Linux
elif [ -a /etc/conectiva-release ]; then
   distro="Conectiva Linux"
   distroDetails="/etc/conectiva-release"
   desconhecida="n"

# Verificando se � Mandrake Linux
elif [ -a /etc/mandrake-release ]; then
   distro="Mandrake Linux"
   distroDetails="/etc/mandrake-release"
   desconhecida="n"

# Verificando se � Knoppix Linux
elif [ -a /etc/knoppix-version ]; then
   distro="Knoppix Linux"
   distroDetails="/etc/knoppix-version"
   desconhecida="n"

############################################
# Adicionar novas entradas aqui, no padr�o:
# NOME DA DISTRO COMENTADO
# elif [ -a CAMINHO_ARQUIVO_DISTRO ]; then
#    distro="NOME_DISTRO"
#    distroDetails="CAMINHO_ARQUIVO_DISTRO"
#    desconhecida="n"
############################################

# Verificando se � Blue Point Linux
elif [ -a /etc/bluepoint-release ]; then
   distro="Blue Point Linux"
   distroDetails="/etc/bluepoint-release"
   desconhecida="n"
fi

# Imprimindo os resultados encontrados...

# Verificando se a distro foi reconhecida.
if [ $desconhecida = "y" ]; then # Distro desconhecida
   echo "Distro Recognizer: Distribui��o desconhecida."
   echo "Distro Recognizer: Verifique o diret�rio /etc"
   echo "   e procure por um arquivo no formato"
   echo "   *-version, *_version ou *-release, onde *"
   echo "   ser� a distro."


else # Distro reconhecida
   echo "Distro Recognizer: Sua distro � a $distro."
   echo "Distro Recognizer [Notas da vers�o da distro]:"
   cat $distroDetails
fi