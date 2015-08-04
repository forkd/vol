#!/bin/bash
#
# Distro Recognizer 0.05
# Description: Este script verifica qual é a distribuição utilizada no computador
#    e informa o seu nome ao usuário.
# Author: José Lopes de Oliveira Júnior
# Date: 2006/march
# NOTES: Dar permissão de execução ao arquivo ($ chmod 711 dr.sh).

# Verificando se foram passados paramentros
case "$1" in
   "-v")
      echo "Distro Recognizer 0.05"
      echo ""
      echo "Escrito por José Lopes de Oliveira Júnior <jlojunior@gmail.com>"
      echo ""
      echo "   Este programa é um software de livre distribuição, que pode ser"
      echo "copiado e distribuído sob os termos da Licença Geral GNU, conforme"
      echo "publicada pela Free Software Foundation, versão 2 da liceça, ou (a"
      echo "critério do autor) qualquer versão posterior."
      echo "   Este programa é distribuído na expectativa de ser útil aos seus"
      echo "usuários, porém NÃO POSSUI NENHUMA GARANTIA, EXPLÍCITA OU IMPLÍCI-"
      echo "TA, COMERCIAL OU DE ATENDIMENTO A UMA DETERMINADA FINALIDADE."
      echo "Consulte a Licença Pública Geral GNU."
      
      exit 0
   ;;
   
   "-a")
      echo "Distro Recognizer"
      echo "   Este script verifica qual é a distribuição Linux que está insta-"
      echo "lada no computador onde for executado."
      
      exit 0
   ;;
   
   *)
      if [ ! -z $1 ]; then
         echo "Distro Recognizer: Opção desconhecida."
         
         exit 1
      fi
   ;;
esac

# Verificando qual a distro que está sendo utilizada.

# A idéia básica utilizada nesta verificação é a de localizar o arquivo que
#    informa sobre o nome da distro e sua versão, em /etc.

# Variaveis a serem utilizadas
distro=""        # Armazena o nome da distro
distroDetails="" # Armazena o caminho para o arquivo de versao
desconhecida="y" # Desconhecida == "y". Reconhecida == "n"

# Verificando se é Debian Linux
if [ -a /etc/debian_version ]; then
   distro="Debian Linux"
   distroDetails="/etc/debian_version"
   desconhecida="n"

# Verificando se é Slackware Linux
elif [ -a /etc/slackware-version ]; then
   distro="Slackware Linux"
   distroDetails="/etc/slackware-version"
   desconhecida="n"

# Verificando se é Red Hat Linux
elif [ -a /etc/redhat-release ]; then
   distro="Red Hat Linux"
   distroDetails="/etc/redhat-release"
   desconhecida="n"

# Verificando se é Conectiva Linux
elif [ -a /etc/conectiva-release ]; then
   distro="Conectiva Linux"
   distroDetails="/etc/conectiva-release"
   desconhecida="n"

# Verificando se é Mandrake Linux
elif [ -a /etc/mandrake-release ]; then
   distro="Mandrake Linux"
   distroDetails="/etc/mandrake-release"
   desconhecida="n"

# Verificando se é Knoppix Linux
elif [ -a /etc/knoppix-version ]; then
   distro="Knoppix Linux"
   distroDetails="/etc/knoppix-version"
   desconhecida="n"

############################################
# Adicionar novas entradas aqui, no padrão:
# NOME DA DISTRO COMENTADO
# elif [ -a CAMINHO_ARQUIVO_DISTRO ]; then
#    distro="NOME_DISTRO"
#    distroDetails="CAMINHO_ARQUIVO_DISTRO"
#    desconhecida="n"
############################################

# Verificando se é Blue Point Linux
elif [ -a /etc/bluepoint-release ]; then
   distro="Blue Point Linux"
   distroDetails="/etc/bluepoint-release"
   desconhecida="n"
fi

# Imprimindo os resultados encontrados...

# Verificando se a distro foi reconhecida.
if [ $desconhecida = "y" ]; then # Distro desconhecida
   echo "Distro Recognizer: Distribuição desconhecida."
   echo "Distro Recognizer: Verifique o diretório /etc"
   echo "   e procure por um arquivo no formato"
   echo "   *-version, *_version ou *-release, onde *"
   echo "   será a distro."


else # Distro reconhecida
   echo "Distro Recognizer: Sua distro é a $distro."
   echo "Distro Recognizer [Notas da versão da distro]:"
   cat $distroDetails
fi