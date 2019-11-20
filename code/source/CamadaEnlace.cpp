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

    string contador = bitset<BITS*4>(*tamanho/BITS).to_string();
    int cabecalho = BITS*4;
    *tamanho = *tamanho + cabecalho;
    int i, j;
    int *quadro_enquadrado = new int[*tamanho];

    for (i = 0, j = 0; i < *tamanho; i++) {
        if (i < cabecalho) {
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
    if (contador % 2 == 0) {
        quadro_controle_erro[i] = 0;
    } else {
        quadro_controle_erro[i] = 1;
    }
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
    if (contador % 2 != 0) {
        quadro_controle_erro[i] = 0;
    } else {
        quadro_controle_erro[i] = 1;
    }
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroBitParidadeImpar


/***************************************************************************
* Função: CamadaEnlaceTransmissoraControleDeErroCRC
* Descrição
*   descobre o polinomio gerador
*   atribui quadro a vetor de operacao
*   realiza divisao binaria entre vetor de operacao e gerador
*   atribui vetor operacao a vetor retorno
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_controle_erro[] - array em bits
* Assertiva de entrada
*   quadro[] = {1, 0, 0, 1, 0, 0}
*   polinomio = 0x04C11DB7
*   tamanho = 6
* Assertiva de saída
*   quadro[] = {1, 0, 0, 1, 0, 0, 0, 1,
                1, 0, 1, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 1, 1, 0, 1,
                1, 0, 0, 0, 1, 1, 1, 1}
*   tamanho = 32
****************************************************************************/
int* CamadaEnlaceTransmissoraControleDeErroCRC(int quadro[], int *tamanho) {
    //  Macro representacao polinomial R_P
    //  Macro representacao polinomial size R_P_S
    int i, j;
    string auxiliar = bitset<R_P_S>(R_P).to_string();

    int tamanho_polinomio = auxiliar.length();
    int *polinomio = new int[tamanho_polinomio];

    *tamanho = *tamanho + tamanho_polinomio - 1;
    int *quadro_controle_erro = new int[*tamanho];
    int *resto_divicao = new int[*tamanho];

    // converte string em vetor de int binarios
    for (i = 0; i < tamanho_polinomio; i++) {
        polinomio[i] = (auxiliar[i] == '1');
    }

    // atribui os valores do quadro a variavel de operacao
    for (i = 0; i < *tamanho; i++) {
        if (i < (*tamanho - tamanho_polinomio + 1)) {
            resto_divicao[i] = quadro[i];
        } else {
            resto_divicao[i] = 0;
        }
    }

    // operacao de divisao binaria com resto
    for (i = 0; (i + tamanho_polinomio - 1) < *tamanho; i++) {
        if (resto_divicao[i] != 0) {
            for (j = 0; j < tamanho_polinomio; j++) {
            resto_divicao[j+i] = resto_divicao[j+i] ^ polinomio[j];
            }
        }
    }

    // coloca valores de quadro no inicio de resto
    for (i = 0; i < (*tamanho - tamanho_polinomio + 1); i++) {
        resto_divicao[i] = quadro[i];
    }

    // transfere resto = quadro + CRC para variavel de retorno
    for (i = 0; i < *tamanho; i++) {
        quadro_controle_erro[i] = resto_divicao[i];
    }
    delete polinomio;
    delete resto_divicao;
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroCRC


/***************************************************************************
* Função: CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming
* Descrição
*   descobre o tamanho do novo quadro com os controladores
*   insere os bits M nas respectivas posicoes
*   calcula os Ps de acordo com os respectivos algarismos significativos
*   atribui vetor operacao a vetor retorno
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_controle_erro[] - array em bits
* Assertiva de entrada
*   quadro[] = {0, 1, 0, 1}
*   tamanho = 4
* Assertiva de saída
*   quadro[] = {0, 1, 0, 0, 1, 0, 1}
*   tamanho = P + M = 7
****************************************************************************/
int* CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming
(int quadro[], int *tamanho) {
    int i, j, k, v, w, contador;
    string auxiliar;
    // descobre o numero de P necessario para controle
    for (i = 0, j = 0, contador = 0; i < *tamanho; i = pow(2, j), j++) {
        contador++;
    }
    *tamanho += contador;
    int *quadro_controle_erro = new int[*tamanho];

    // insere os bits M em suas determinadas posicoes
    for (i = 0, j = 0, w = 0; i < *tamanho; i++) {
        if (i+1 == pow(2, j)) {
            quadro_controle_erro[i] = 0;
            j++;
        } else {
            quadro_controle_erro[i] = quadro[w];
            w++;
        }
    }

    // calcula cada P de acordo com o algarismo menos significativo
    for (i = 0, j = 0, w = 1; i < *tamanho; i++) {
        if (i+1 == pow(2, j)) {
            j++;
            for (k = 1,  contador = 0, v = 0; k <= *tamanho; k++) {
                // verifica se a posicao atual e um P ou um M
                if (k == pow(2, v)) {
                    v++;
                } else {
                // quebra o M respectivo e verifica o algarismo significativo
                    auxiliar = bitset<32>(k).to_string();
                    if (auxiliar[auxiliar.length()-w] == '1') {
                        // verifica paridade se elemento e 1
                        if (quadro_controle_erro[k-1] == 1) {
                            contador++;
                        }
                    }
                }
            }
            w++;
            // verifica contador se contador for par entao 0
            if (contador % 2 == 0) {
                quadro_controle_erro[i] = 0;
            } else {
                quadro_controle_erro[i] = 1;
            }
        }
    }
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceTransmissoraControleDeErroCodigoDehamming


void CamadaEnlaceReceptora(int quadro[], int *tamanho) {
    // chama proxima camada
    CamadaEnlaceReceptoraControleDeErro(quadro, tamanho);
}   // fim do metodo CamadaEnlaceReceptora


void CamadaEnlaceReceptoraControleDeErro(int quadro[], int *tamanho) {
    int tipoDeControleDeErro = CONTROLE_ERRO;   // alterar de acordo com o teste
    int *quadroControleErro;
    bool verificador = true;
    int i;
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
            quadroControleErro =
            CamadaEnlaceReceptoraControleDeErroCRC
            (quadro, tamanho, &verificador);
            break;
        case 3 :    // codigo de Hamming
            quadroControleErro =
            CamadaEnlaceReceptoraControleDeErroCodigoDeHamming
            (quadro, tamanho);
            break;
        break;
    }   // fim do switch/case
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
    for (i = 0, contador = 0; i < *tamanho; i++) {
        quadro_controle_erro[i] = quadro[i];
        if (quadro[i] == 1) {
            contador++;
        }
    }

    if ((contador % 2) == quadro[i]) {
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
    for (i = 0, contador = 0; i < *tamanho; i++) {
        if (quadro[i] == 1) {
            contador++;
        }
        quadro_controle_erro[i] = quadro[i];
    }
    if (!(contador % 2) == quadro[i]) {
        *verificador = true;
    } else {
        *verificador = false;
    }
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar


/***************************************************************************
* Função: CamadaEnlaceReceptoraControleDeErroCRC
* Descrição
*   descobre o polinomio gerador
*   atribui quadro a vetor de operacao
*   realiza divisao binaria entre vetor de operacao e gerador
*   verifica se resto divisao e 0
*   atribui vetor operacao a vetor retorno
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_controle_erro[] - array em bits
* Assertiva de entrada
*   quadro[] = {1, 0, 0, 1, 0, 0, 0, 1,
                1, 0, 1, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 1, 1, 0, 1,
                1, 0, 0, 0, 1, 1, 1, 1}
*   polinomio = 0x04C11DB7
*   tamanho = 32
* Assertiva de saída
*   quadro[] = {1, 0, 0, 1, 0, 0}
*   tamanho = 6
****************************************************************************/
int* CamadaEnlaceReceptoraControleDeErroCRC
(int quadro[], int *tamanho, bool *verificador) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
    // usar polinomio CRC-32(IEEE 802)

    //  Macro representacao polinomial R_P
    //  Macro representacao polinomial size R_P_S
    int i, j;
    string auxiliar = bitset<R_P_S>(R_P).to_string();

    int tamanho_polinomio = auxiliar.length();
    int *polinomio = new int[tamanho_polinomio];

    int *quadro_controle_erro = new int[*tamanho - tamanho_polinomio + 1];
    int *resto_divicao = new int[*tamanho];

    // converte string em vetor de int binarios
    for (i = 0; i < tamanho_polinomio; i++) {
        polinomio[i] = (auxiliar[i] == '1');
    }

    // atribui os valores do quadro a variavel de operacao
    for (i = 0; i < *tamanho; i++) {
        resto_divicao[i] = quadro[i];
    }

    // operacao de divisao binaria com resto
    for (i = 0; (i + tamanho_polinomio - 1) < *tamanho; i++) {
        if (resto_divicao[i] != 0) {
            for (j = 0; j < tamanho_polinomio; j++) {
            resto_divicao[j+i] = resto_divicao[j+i] ^ polinomio[j];
            }
        }
    }

    for (i = 0; i < *tamanho; i++) {
        if (resto_divicao[i] != 0) {
            *verificador = false;
            break;
        } else {
            *verificador = true;
        }
    }
    *tamanho = *tamanho - tamanho_polinomio + 1;
    for (i = 0; i < *tamanho; i++)
        quadro_controle_erro[i] = quadro[i];
    delete polinomio;
    delete resto_divicao;
    return quadro_controle_erro;
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroCRC


/***************************************************************************
* Função: CamadaEnlaceReceptoraControleDeErroCodigoDeHamming
* Descrição
*   descobre o numero de P
*   recalcula os P 
*   compara os novos P com os antigos
*   se der um valor maior que 0 substitui o bit na posicao indicada
*   retorna quadro limpo sem os verificadores
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_controle_erro[] - array em bits
* Assertiva de entrada
*   quadro[] = {0, 1, 0, 0, 1, 0, 1}
*   tamanho = P + M = 7
* Assertiva de saída
*   quadro[] = {0, 1, 0, 1}
*   tamanho = 4
****************************************************************************/
int* CamadaEnlaceReceptoraControleDeErroCodigoDeHamming
(int quadro[], int *tamanho) {
    int i, j, k, v, w, z, contador, numero_P;
    string auxiliar;
    // descobre o numero de P necessario para controle
    for (i = 0, j = 0, numero_P = -1; i < *tamanho; i = pow(2, j), j++) {
        numero_P++;
    }

    int *erro = new int[numero_P];
    int *quadro_controle_erro = new int[*tamanho-numero_P];

    // calcula cada P de acordo com o algarismo menos significativo
    for (i = 0, j = 0, w = 1, z = 0; i < *tamanho; i++) {
        if (i+1 == pow(2, j)) {
            j++;
            for (k = 1,  contador = 0, v = 0; k <= *tamanho; k++) {
                // verifica se a posicao atual e um P ou um M
                if (k == pow(2, v)) {
                    v++;
                } else {
                // quebra o M respectivo e verifica o algarismo significativo
                    auxiliar = bitset<32>(k).to_string();
                    if (auxiliar[auxiliar.length()-w] == '1') {
                        // verifica paridade se elemento e 1
                        if (quadro[k-1] == 1) {
                            contador++;
                        }
                    }
                }
            }
            w++;
            // verifica contador se contador for par entao 0
            if (contador % 2 == 0) {
                erro[z] = 0;
            } else {
                erro[z] = 1;
            }
            z++;
        }
    }
    // verifica valor erro com o P respectivo
    for (i = 0, j=0 , z= 0 , contador = 0; i < *tamanho; i++) {
        if (i+1 == pow(2, j)) {
            erro[z] = erro[z] ^ quadro[i];
            z++;
            j++;
        }
    }
    // conta a posicao em que se encontra o erro
    for (i = 0, contador = 0; i < numero_P; i++)
        contador+= erro[i]*pow(2, i);

    // retira os P e atribui os M com a correcao do erro
    for (i = 0, j=0 , z= 0 , contador = 0; i < *tamanho; i++) {
        if (i+1 == pow(2, j)) {
            j++;
        } else {
            if (contador != 0 && i == contador-1) {
                quadro_controle_erro[z] = !(quadro[i]);
            } else {
                quadro_controle_erro[z] = quadro[i];
            }
            z++;
        }
    }
    *tamanho = *tamanho - numero_P;
    delete erro;
    return quadro_controle_erro;
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
    for (i = 0, j = BITS*4 - 1; i < BITS*4 ; i++, j--) {
        auxiliar += pow(2, j)*quadro[i];
    }

    *tamanho = auxiliar*BITS;
    int *quadro_denquadrado = new int[*tamanho];
    for (i = 0, j = BITS*4; i < *tamanho; i++, j++) {
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
