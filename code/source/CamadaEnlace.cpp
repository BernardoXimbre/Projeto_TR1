// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "CamadaEnlace.hpp"
# include "CamadaFisica.hpp"


void CamadaEnlaceTransmissora(int quadro[], int *tamanho) {
    // chama a proxima camada
    CamadaEnlaceTransmissoraEnquadramento(quadro, tamanho);
    // CamadaEnlaceTransmissoraControleDeErro(quadro, tamanho);
}   // fim do metodo CamadaEnlaceTransmissora


void CamadaEnlaceTransmissoraEnquadramento(int quadro[], int *tamanho) {
    int tipoDeEnquadramento = ENQUADRAMENTO;  // alterar de acordo com o teste
    int *quadroEnquadrado;
    switch (tipoDeEnquadramento) {
        case 0 :    // contagem de caracteres
            quadroEnquadrado =
            CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres
            (quadro, tamanho);
            break;
        case 1 :    // insercao de bytes
            quadroEnquadrado =
            CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes
            (quadro, tamanho);
            break;
        case 2 :    // insercao de bits
            quadroEnquadrado =
            CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits
            (quadro, tamanho);
            break;
        case 3 :    // violacao da camada fisica
            quadroEnquadrado =
            CamadaEnlaceTransmissoraEnquadramentoViolacaoDaCamadaFisica
            (quadro, tamanho);
            break;
    }   // fim do switch/case
    // CamadaFisicaTransmissora(quadroEnquadrado, tamanho);
    CamadaEnlaceTransmissoraControleDeErro(quadroEnquadrado, tamanho);
}   // fim do metodo CamadaEnlaceTransmissoraEnquadramento


/***************************************************************************
* Função: CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres
* Descrição
*   insere em BITS no cabecalho o tamanho de cada quadro
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_enquadrado[] - array em bits
* Assertiva de entrada
*   quadro[] = {1,0,1,1,0,1,0,0}
*   tamanho = 8
* Assertiva de saída
*               |   cabecalho  |
*   quadro[] = {0,0,0,0,1,0,0,1,1,0,1,1,0,1,0,0}
*   tamanho = 16
****************************************************************************/ 
int* CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres
(int quadro[], int *tamanho) {
    string contador = bitset<BITS>(*tamanho/BITS).to_string();
    *tamanho = *tamanho+BITS;
    int i, j;

    int *quadro_enquadrado = new int[*tamanho];

    for (i = 0, j = 0; i < *tamanho; i++) {
        if (i < BITS) {
            if (contador[i] == '1') {
                quadro_enquadrado[i] = 1;
            } else {
                quadro_enquadrado[i] = 0;
            }
        } else {
            quadro_enquadrado[i] = quadro[j];
            j++;
        }
    }
    return quadro_enquadrado;
}   // fim do metodo CamadaEnlaceTransmissoraContagemDeCaracteres


/***************************************************************************
* Função: CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes
* Descrição
*   insere em bytes no comeco e no fim do quadro uma FLAG
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_enquadrado[] - array em bits
* Assertiva de entrada
*   quadro[] = {1, 1, 0, 1, 1, 1, 1, 0}
*   tamanho = 8
* Assertiva de saída
*               |     inicio   |     quadro    |    fim       |
*   quadro[] = {0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1}
*   tamanho = 24
****************************************************************************/
int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes
(int quadro[], int *tamanho) {
    int i, j, k;
    *tamanho = *tamanho+2*BITS;
    int *quadro_enquadrado = new int[*tamanho];

    for (i = 0, j = 0; j < *tamanho; i++, j++) {
        if (j < BITS || j >= *tamanho-BITS) {
            for (k = 0; k < BITS; j++, k++) {
                if (k < BITS/2) {
                    quadro_enquadrado[j] = 0;
                } else {
                    quadro_enquadrado[j] = 1;
                }
            }
        }
        quadro_enquadrado[j] = quadro[i];
    }
    return quadro_enquadrado;
}   // fim do metodo CamadaEnlaceTransmissoraInsercaoDeBytes


/***************************************************************************
* Função: CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits
* Descrição
*   insere em bytes no comeco e no fim do quadro uma FLAG
*   adiciona 0 quando se tem uma sequencia de 1
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_enquadrado[] - array em bits
* Assertiva de entrada
*   quadro[] = {0, 1, 1, 1, 1, 1, 1, 0}
*   tamanho = 8
* Assertiva de saída
*               |     inicio   |     quadro      |    fim       |
*   quadro[] = {0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0}
*   tamanho = 25
****************************************************************************/
int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits
(int quadro[], int *tamanho) {
    int i, j, k, contador_inser;
    for (i = 0, j = 0, contador_inser = 0; i < *tamanho ; i++) {
        if (quadro[i] == 1) {
            if (j == 5) {
                contador_inser++;
            }
            j++;
        } else {
            j = 0;
        }
    }
    *tamanho = *tamanho+2*BITS+contador_inser;
    int *quadro_enquadrado = new int[*tamanho];

    for (i = 0, j = 0, contador_inser = 0; j < *tamanho; i++, j++) {
        if (j < BITS || j >= *tamanho-BITS) {
            for (k = 0; k < BITS; j++, k++) {
                if (k == 0 || k == BITS-1) {
                    quadro_enquadrado[j] = 0;
                } else {
                    quadro_enquadrado[j] = 1;
                }
            }
        }
        if (quadro[i] == 1) {
            if (contador_inser == 5) {
                quadro_enquadrado[j] = 0;
                j++;
                contador_inser = 0;
            } else {
                contador_inser++;
            }
        } else {
            contador_inser = 0;
        }
        quadro_enquadrado[j] = quadro[i];
    }
    return quadro_enquadrado;
}   // fim do metodo CamadaEnlaceTransmissoraInsercaoDeBits


int* CamadaEnlaceTransmissoraEnquadramentoViolacaoDaCamadaFisica
(int quadro[], int *tamanho) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraViolacaoDaCamadaFisica


void CamadaEnlaceTransmissoraControleDeErro(int quadro[], int *tamanho) {
    int tipoDeControleDeErro = CONTROLE_ERRO;   // alterar de acordo com o teste
    int *quadroControleErro;
    switch (tipoDeControleDeErro) {
        case 0 :    // bit de paridade par
            quadroControleErro =
            CamadaEnlaceTransmissoraControleDeErroBitParidadePar
            (quadro, tamanho);
            break;
        case 1 :    // bit de paridade impar
            quadroControleErro =
            CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar
            (quadro, tamanho);
            break;
        break;
        case 2 :    // CRC
            quadroControleErro =
            CamadaEnlaceTransmissoraControleDeErroCRC
            (quadro, tamanho);
            break;
        case 3 :    // codigo de Hamming
            quadroControleErro =
            CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming
            (quadro, tamanho);
            break;
        break;
        }   // fim do switch/case
    // CamadaEnlaceTransmissoraControleDeFluxo(quadro);
    // chama a proxima camada
    CamadaFisicaTransmissora(quadroControleErro, tamanho);
}   // fim do metodo CamadaEnlaceTransmissoraControleDeErro


/***************************************************************************
* Função: CamadaEnlaceTransmissoraControleDeErroBitParidadePar
* Descrição
*   insere 1 bit comeco do quadro indicando paridade
*   0 - se Par
*   1 - se Impar
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_controle_erro[] - array em bits
* Assertiva de entrada
*   quadro[] = {1, 1, 1, 1, 1, 1, 0, 0}
*   tamanho = 8
* Assertiva de saída
*   quadro[] = {1, 1, 1, 1, 1, 1, 0, 0, 0}
*   tamanho = 9
****************************************************************************/
int* CamadaEnlaceTransmissoraControleDeErroBitParidadePar
(int quadro[], int *tamanho) {
    int i, contador;
    *tamanho = *tamanho+1;
    int *quadro_controle_erro = new int[*tamanho];
    for (i = 0, contador = 0; i < *tamanho-1; i++) {
        if (quadro[i] == 1) {
            contador++;
        }
        quadro_controle_erro[i] = quadro[i];
    }
    quadro_controle_erro[i] = !(contador % 2 == 0);
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroBitParidadePar


/***************************************************************************
* Função: CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar
* Descrição
*   insere 1 bit comeco do quadro indicando paridade
*   1 - se Par
*   0 - se Impar
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_controle_erro[] - array em bits
* Assertiva de entrada
*   quadro[] = {1, 1, 1, 1, 1, 1, 0, 0}
*   tamanho = 8
* Assertiva de saída
*   quadro[] = {1, 1, 1, 1, 1, 1, 0, 0, 0}
*   tamanho = 9
****************************************************************************/
int* CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar
(int quadro[], int *tamanho) {
    int i, contador;
    *tamanho = *tamanho+1;
    int *quadro_controle_erro = new int[*tamanho];
    for (i = 0, contador = 0; i < *tamanho-1; i++) {
        if (quadro[i] == 1) {
            contador++;
        }
        quadro_controle_erro[i] = quadro[i];
    }
    quadro_controle_erro[i] = (contador % 2 == 0);
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroBitParidadeImpar


int* CamadaEnlaceTransmissoraControleDeErroCRC(int quadro[], int *tamanho) {
    // implementacao do algoritmo
    // bitset<BITS*sizeof(int)> teste = bitset<BITS*sizeof(int)>(10);
    // bitset<BITS*sizeof(int)> teste2 = bitset<BITS*sizeof(int)>(10);
    // cout << "\n\n" << auxiliar << "\n\n";
    // auxiliar = bitset<BITS>(static_cast<int>(mensagem[i])).to_string();
    // usar polinomio CRC-32(IEEE 802)
    return quadro;
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroCRC


int* CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming
(int quadro[], int *tamanho) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraControleDeErroCodigoDehamming


void CamadaEnlaceReceptora(int quadro[], int *tamanho) {
    // chama proxima camada
    // CamadaEnlaceReceptoraEnquadramento(quadro, tamanho);
    CamadaEnlaceReceptoraControleDeErro(quadro, tamanho);
}   // fim do metodo CamadaEnlaceReceptora

/*
void MeioDeComunicacao (int fluxoBrutoDeBits []) {
 //OBS: trabalhar com BITS e nao com BYTES!!!
 int erro, porcentagemDeErros;
 int fluxoBrutoDeBitsPontoA [], fluxoBrutoDeBitsPontoB [];
 porcentagemDeErros = 0; //10%, 20%, 30%, 40%, ..., 100%
 fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
 while (fluxoBrutoDeBitsPontoB.lenght!=
 fluxoBrutoDeBitsPontoA) {
 if ((rand()%100)== ... ) //fazer a probabilidade do erro
 fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS!!!
 else //ERRO! INVERTER (usa condicao ternaria)
 fluxoBrutoBitsPontoB==0) ?
 fluxoBrutoBitsPontoA=fluxoBrutoBitsPontoB++ :
 fluxoBrutoBitsPontoA=fluxoBrutoBitsPontoB--;
 }//fim do while
}//fim do metodo MeioDeTransmissao

*/

void CamadaEnlaceReceptoraControleDeErro(int quadro[], int *tamanho) {
    int tipoDeControleDeErro = CONTROLE_ERRO;   // alterar de acordo com o teste
    int *quadroControleErro;
    bool verificador;
    int i;

    for (i = 0; i < *tamanho; i++) {
        cout << quadro[i];
    }
    switch (tipoDeControleDeErro) {
        case 0 :    // bit de paridade par
            quadroControleErro =
            CamadaEnlaceReceptoraControleDeErroBitDeParidadePar
            (quadro, tamanho, &verificador);
            break;
        case 1 :    // bit de paridade impar
            quadroControleErro =
            CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar
            (quadro, tamanho, &verificador);
            break;
        break;
        case 2 :    // CRC
            // quadroControleErro =
            // CamadaEnlaceReceptoraControleDeErroCRC
            // (quadro, tamanho, &verificador);
            break;
        case 3 :    // codigo de Hamming
            // quadroControleErro =
            // CamadaEnlaceReceptoraControleDeErroCodigoDeHamming
            // (quadro, tamanho, &verificador);
            break;
        break;
    }   // fim do switch/case
    cout << "\n";
    for (i = 0; i< *tamanho; i++) {
        cout << quadro[i];
    }
    if (verificador == true) {
        // chama a proxima camada
        CamadaEnlaceReceptoraEnquadramento(quadroControleErro, tamanho);
    } else {
        cout << "\n\n QUADRO CORROMPIDO\n\n";
        return;
    }
    // CamadaEnlaceTransmissoraControleDeFluxo(quadro);
}   // fim do metodo CamadaEnlaceReceptoraControleDeErro


/***************************************************************************
* Função: CamadaEnlaceReceptoraControleDeErroBitDeParidadePar
* Descrição
*   verifica se o bit de paridade é par
*   retira 1 bit do comeco do quadro indicando que esta correto
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_controle_erro[] - array em bits
*   verificador - true ou false
* Assertiva de entrada
*   quadro[] = {1, 1, 1, 1, 1, 1, 0, 0, 0}
*   tamanho = 9
* Assertiva de saída
*   quadro[] = {1, 1, 1, 1, 1, 1, 0, 0}
*   tamanho = 8
*   verificador = true
****************************************************************************/
int* CamadaEnlaceReceptoraControleDeErroBitDeParidadePar
(int quadro[], int *tamanho, bool *verificador) {
    int i, contador;
    *tamanho = *tamanho-1;
    int *quadro_controle_erro = new int[*tamanho];
    for (i = 0, contador = 0; i < *tamanho-1; i++) {
        if (quadro[i] == 1) {
            contador++;
        }
        quadro_controle_erro[i] = quadro[i];
    }
    if ((contador % 2) == quadro[*tamanho+1]) {
        *verificador = true;
    } else {
        *verificador = false;
    }
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroBitDeParidadePar


/***************************************************************************
* Função: CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar
* Descrição
*   verifica se o bit de paridade é par
*   retira 1 bit do comeco do quadro indicando que esta correto
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_controle_erro[] - array em bits
*   verificador - true ou false
* Assertiva de entrada
*   quadro[] = {1, 1, 1, 1, 1, 0, 0, 0, 0}
*   tamanho = 9
* Assertiva de saída
*   quadro[] = {1, 1, 1, 1, 1, 1, 0, 0}
*   tamanho = 8
*   verificador = true
****************************************************************************/
int* CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar
(int quadro[], int *tamanho, bool *verificador) {
    int i, contador;
    *tamanho = *tamanho-1;
    int *quadro_controle_erro = new int[*tamanho];
    for (i = 0, contador = 0; i < *tamanho-1; i++) {
        if (quadro[i] == 1) {
            contador++;
        }
        quadro_controle_erro[i] = quadro[i];
    }
    if ((contador % 2 != 0) == quadro_controle_erro[i]) {
        *verificador = true;
    } else {
        *verificador = false;
    }
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar

void CamadaEnlaceReceptoraControleDeErroCRC(int quadro[], int *tamanho) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
    // usar polinomio CRC-32(IEEE 802)
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroCRC

void CamadaEnlaceReceptoraControleDeErroCodigoDeHamming
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroCodigoDeHamming



void CamadaEnlaceReceptoraEnquadramento(int quadro[], int *tamanho) {
    int tipoDeEnquadramento = ENQUADRAMENTO;    // alterar de acordo com o teste
    int *quadroDesenquadrado;
    switch (tipoDeEnquadramento) {
        case 0 :    // contagem de caracteres
            quadroDesenquadrado =
            CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres
            (quadro, tamanho);
            break;
        case 1 :    // insercao de bytes
            quadroDesenquadrado =
            CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes
            (quadro, tamanho);
            break;
        case 2 :    // insercao de bits
            quadroDesenquadrado =
            CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits
            (quadro, tamanho);
            break;
        case 3 :    // violacao da camada fisica
            quadroDesenquadrado =
            CamadaEnlaceReceptoraEnquadramentoViolacaoDaCamadaFisica
            (quadro, tamanho);
            break;
    }   // fim do switch/case
    // CamadaDeAplicacaoReceptora(quadroDesenquadrado, tamanho);
    // CamadaEnlaceReceptoraControleDeErro(quadro, tamanho);
    // CamadaEnlaceReceptoraControleDeFluxo(quadro, tamanho);
    CamadaDeAplicacaoReceptora(quadroDesenquadrado, tamanho);
}   // fim do metodo CamadaEnlaceReceptoraEnquadramento


/***************************************************************************
* Função: CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres
* Descrição
*   retira em BITS no cabecalho o tamanho de cada quadro
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_denquadrado[] - array em bits
* Assertiva de entrada
*               |   cabecalho  |
*   quadro[] = {0,0,0,0,0,0,0,1,1,0,1,1,0,1,0,0}
*   tamanho = 16
* Assertiva de saída
*   quadro[] = {1,0,1,1,0,1,0,0}
*   tamanho = 8
****************************************************************************/ 
int* CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres
(int quadro[], int *tamanho) {
    int i, j, auxiliar = 0;
    for (i = 0, j = BITS - 1; i < BITS ; i++, j--) {
        auxiliar += pow(2, j)*quadro[i];
    }
    *tamanho = auxiliar*BITS;
    int *quadro_denquadrado = new int[*tamanho];
    for (i = 0, j = BITS; i < *tamanho; i++, j++) {
        quadro_denquadrado[i] = quadro[j];
    }
    return quadro_denquadrado;
}   // fim do metodo CamadaEnlaceReceptoraContagemDeCaracteres


/***************************************************************************
* Função: CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes
* Descrição
*   retira os bytes de FLAG no comeco e no fim do quadro
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_desenquadrado[] - array em bits
* Assertiva de entrada
*               |     inicio   |     quadro    |    fim       |
*   quadro[] = {0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1}
*   tamanho = 24
* Assertiva de saída
*   quadro[] = {1, 1, 0, 1, 1, 1, 1, 0}
*   tamanho = 8
****************************************************************************/
int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes
(int quadro[], int *tamanho) {
    int i, j, k;
    *tamanho = *tamanho-2*BITS;
    int *quadro_denquadrado = new int[*tamanho];

    for (i = 0, j = BITS; i < *tamanho; i++, j++) {
        quadro_denquadrado[i] = quadro[j];
    }
    return quadro_denquadrado;
}   // fim do metodo CamadaEnlaceReceptoraInsercaoDeBytes


/***************************************************************************
* Função: CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits
* Descrição
*   retira os bytes no comeco e no fim do quadro uma FLAG
*   retira 0 quando se tem uma sequencia de 1
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_enquadrado[] - array em bits
* Assertiva de entrada
*               |     inicio   |     quadro      |    fim       |
*   quadro[] = {0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0}
*   tamanho = 25
* Assertiva de saída
*   quadro[] = {0, 1, 1, 1, 1, 1, 0, 0}
*   tamanho = 8
****************************************************************************/
int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits
(int quadro[], int *tamanho) {
    int i, j, k, contador_inser;
    for (i = BITS, j = 0, contador_inser = 0; i < *tamanho-BITS ; i++) {
        if (quadro[i] == 1) {
            if (j == 4) {
                contador_inser++;
                j = 0;
            }
            j++;
        } else {
            j = 0;
        }
    }
    *tamanho = *tamanho-2*BITS-contador_inser;
    int *quadro_enquadrado = new int[*tamanho];

    for (i = 0, j = BITS, contador_inser = 0; i < *tamanho; i++, j++) {
        quadro_enquadrado[i] = quadro[j];
        if (quadro[j] == 1) {
            if (contador_inser == 4) {
                j++;
                contador_inser = 0;
            }
            contador_inser++;
        } else {
            contador_inser = 0;
        }
    }
    return quadro_enquadrado;
}   // fim do metodo CamadaEnlaceReceptoraInsercaoDeBits


int* CamadaEnlaceReceptoraEnquadramentoViolacaoDaCamadaFisica
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraViolacaoDaCamadaFisica



void CamadaEnlaceTransmissoraControleDeFluxo(int quadro[], int *tamanho) {
    // algum codigo aqui
}   // fim do metodo CamadaEnlaceTransmissoraControleDeFluxo

void CamadaEnlaceReceptoraControleDeFluxo(int quadro[], int *tamanho) {
    // algum codigo aqui
}   // fim do metodo CamadaEnlaceReceptoraControleDeFluxo
