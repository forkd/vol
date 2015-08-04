/* verData ******************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que 0 ou 1 no caso de uma data ser invalida ou valida.         */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char dSemana : O dia da semana.                                 */
/*  > const char dia : O dia.                                               */
/*  > const char mes : O mes.                                               */
/*  > const unsigned long int ano : O ano.                                  */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna 0 se a data for invalida ou 1 caso ela seja valida.           */
/****************************************************************************/
char verData ( char dS; const char dia, const char mes, 
   const unsigned int ano ) {
   /* Validando o ano */
   if ( ! ( ano >= 0 ) )
      return 0;
   
   /* Validando o mes */
   if ( ! ( ( mes >= 0 ) && ( mes <= 11 ) ) )
      return 0;
   else {
      
      /* validando o dia */
      switch ( mes ) {
         case 0: case 2: case 4: case 6: case 7: case 9: case 11:
	 if ( ! ( ( dia >= 1 ) && ( dia <= 31 ) ) )
	    return 0;
	 break;
      
      case 3: case 5: case 8: case 10:
         if ( ! ( ( dia >= 1 ) && ( dia <= 30 ) ) )
	    return 0;
	 break;
      
      case 1:
         if( ! ( ano % 4 ) )
	    if ( ! ( ( dia >= 1 ) && ( dia <= 29 ) ) )
	       return 0;
	 else
	    if ( ! ( ( dia >= 1 ) && ( dia <= 28 ) ) )
	       return 0;
	 break;
      }
   }
   
   /* Validando o dia da semana */
   if ( ! ( ( dS >= 0 ) && ( dS <= 6 ) ) )
      return 0;
   
   /* Data Valida */
   return 1;
}

/* totalDiasMes *************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retorna a quantidade de dias de um mes e um ano especifi-  */
/* cos.                                                                     */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char mes : O mes.                                               */
/*  > const unsigned long int ano : O ano.                                  */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna a quantidade de dias que o mes possui.                        */
/****************************************************************************/
char totalDiasMes ( const char mes, const unsigned long int ano ) {
   switch ( mes ){
      case 0: case 2: case 4: case 6: case 7: case 9: case 11:
	 return 31;
	 break;
      
      case 3: case 5: case 8: case 10:
         return 30 ;
	 break;
      
      case 1:
         if( ! ( ano % 4 ) )
	    return 29;
	 else
	    return 28;
	 break;
      
      default:
         return 0;
	 break;
   }
}

/* calculaDias **************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retorna a quantidade de dias entre duas datas.             */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char diaIni : Dia inicial.         [ 1 - 31 ]                   */
/*  > const char mesIni : Mes inicial.         [ 0 - 11 ]                   */
/*  > const unsigned int anoIni : Ano inicial. [ 0 - 99999+ ]               */
/*  > const char diaFim : Dia final.           [ 1 - 31 ]                   */
/*  > const char mesFim : Mes final.           [ 0 - 11 ]                   */
/*  > const unsigned int anoFim : Ano final.   [ 0 - 99999+ ]               */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna a quantidade de dias entre as duas datas.                     */
/****************************************************************************/
unsigned long int calculaDias ( const char diaIni, const char mesIni, 
   const unsigned int anoIni, const char diaFim, const char mesFim, 
   const unsigned int anoFim ) {
   
   /* Variaveis auxiliares para manipulacao da data inicial. */
   register char dI = diaIni, mI = mesIni;
   register unsigned long int aI = anoIni;
   
   /* Variavel que armazenarah o resultado da subtracao entre */
   /* as duas datas em dias.                                  */
   register unsigned long int cDias = 0;
   
   /* Armazena a quantidade de dias que o mes possui. */
   char qtdeDiasMes;
   
   /* Verificando se foram passadas datas iguais. */
   if ( ! ( ( diaIni == diaFim ) && ( mesIni == mesFim ) && 
      ( anoIni == anoFim ) ) )      
      
      /* Este laco sera repetido ateh que a data inicial */      
      /* seja igual a data final.                        */
      do {
         /* Armazenando quantos dias tem o mes corrente na funcao. */
	 qtdeDiasMes = totalDiasMes( mI, aI );
	 
	 /* Verificando se o fim do mes foi atingido. */
	 if ( dI == qtdeDiasMes ) {
	    /* Atualizando o dia e o mes. */
	    dI = 1; ++mI;
	    
	    /* Atualizando o contador de dias. */
	    ++cDias;
	    
	    /* Verficando se o fim do ano foi atingido. */
	    if ( mI > 11 ) {
	       /* Atualizando o mes e o ano. */
	       mI = 0; ++aI;
	       
	       /* Atualizando a quantidade de dias que o mes possui. */
	       qtdeDiasMes = totalDiasMes( mI, aI );
	    }
	    else
	       /* Atualizando a quantidade de dias que o mes possui. */
	       qtdeDiasMes = totalDiasMes( mI, aI ); 
	 }
	 
	 /* Verificando se as datas ainda sao iguais. */
	 if ( ! ( ( dI == diaFim ) && ( mI == mesFim ) && 
	    ( aI == anoFim ) ) )
	    
	    /* Este laco eh repetido ateh que seja atingido o fim do */
	    /* mes ou que o dia, o mes e o ano ( inicial e final )   */
	    /* sejam iguais - data final atingida.                   */
	    for ( ; dI < qtdeDiasMes; dI++ ) {
	       /* Atualiza o contador de dias. */
	       ++cDias;
	       
	       /* Verifica se a data final foi atingida. */
	       if ( ( dI == diaFim ) && ( mI == mesFim ) && 
	          ( aI == anoFim ) ) {
	          /* No caso de a saida do laco for ser por aqui, */
		  /* um dia a mais serah contabilizado. Portanto, */
		  /* subtrai-se este dia antes de sair.           */
		  --cDias;
		  
	          break;
	       }
	    }
      } while ( ! ( ( dI == diaFim ) && ( mI == mesFim ) && 
         ( aI == anoFim ) ) );
   
   return cDias;
}

/* calculaDias **************************************************************/
/* DESCRICAO                                                                */
/*    Funcao que retorna, a partir de uma data inicial e uma quantidade de  */
/* dias, uma data que eh o resultado da soma da data inicial com os dias.   */
/*                                                                          */
/* ENTRADA                                                                  */
/*  > const char diaSemIni : Dia da semana inicial.                         */
/*  > const char diaIni    : Dia inicial.                                   */
/*  > const char mesIni    : Mes inicial.                                   */
/*  > const unsigned int anoIni : Ano inicial.                              */
/*  > unsigned longint dias : A quantidade de dias a ser somada.            */
/*  > char *diaSemFim : Ponteiro para o dia da semana final.                */
/*  > char *diaFim    : Ponteiro para o dia final.                          */
/*  > char *mesFim    : Ponteiro para o mes final.                          */
/*  > unsigned int *anoFim : Ponteiro para o ano final.                     */
/*                                                                          */
/* RETORNO                                                                  */
/*    Retorna, em dSF, dF, mF e aF, a data final.                           */
/*                                                                          */
/* OBSERVACAO                                                               */
/*    Na chamada desta funcao, deve-se passar os enderecos de memoria da da-*/
/* ta final utilizando o operador & antes de cada variavel que compoe a da- */
/* ta final - *diaSemFim, *diaFim, *mesFim, *anoFim.                        */
/****************************************************************************/
void calculaData ( const char diaSemIni, const char diaIni, const char mesIni,
   const unsigned int anoIni, unsigned long int dias,
   char *diaSemFim, char *diaFim, char *mesFim, unsigned long int *anoFim ) {
   
   /* Variaveis auxiliares para manipulacao da data final. */
   register char dSF = diaSemIni, dF = diaIni, mF = mesIni;
   register unsigned long int aF = anoIni;
   
   /* Armazena a quantidade de dias que o mes possui. */
   char qtdeDiasMes;
   
   /* Este laco se repetirah ateh que a variavel dias */
   /* seja igual a 0.                                 */
   do {
      /* Atualizando a quantidade de dias total do mes */
      qtdeDiasMes = totalDiasMes( mF, aF );
      
      /* Verficando se o fim do mes foi atingido */
      if ( dF == qtdeDiasMes ) {
         /* Atualizando variaveis */
	 dF = 1; ++dSF; ++mF; --dias;
	 
	 /* Verificando e tratando o fim da semana. */
	 if ( dSF > 6 ) dSF = 0;
	 
	 /* Verficando e tratando o final do ano. */
	 if ( mF > 11 ) {
	    /* Atualizando o mes e o ano. */
	    mF = 0; ++aF;
	    
	    /* Atualizando a quantidade de dias total do mes */
	    qtdeDiasMes = totalDiasMes( mF, aF );
	 }
	 else
	    /* Atualizando a quantidade de dias total do mes */
	    qtdeDiasMes = totalDiasMes( mF, aF );
      }
      
      /* Se ainda houverem dias a serem somados */
      if ( dias )
         
	 /* Este laco se repete ateh que o final do mes corrente */
	 /* seja atingido ou que nao hajam mais dias a serem so- */
	 /* mados.                                               */
	 for ( ; dF < qtdeDiasMes; dF++ ) {
	    /* Atualizando variaveis: somando mais um dia e */
	    /* subtraindo um dia da contagem.               */
	    ++dSF; --dias;
	    
	    /* Verificando e tratando o fim da semana. */
	    if ( dSF > 6 ) dSF = 0;
	    
	    /* Verificando se a contagem terminou. Caso */
	    /* tenha terminado, um dia eh acrescido.    */
	    if ( ! dias ) {
	       ++dF;
	       
	       break;
	    }
	 }
   } while ( dias );
   
   /* Gerando o retorno da funcao. */
   *diaSemFim = dSF; *diaFim = dF; 
   *mesFim    = mF;  *anoFim = aF;
}
