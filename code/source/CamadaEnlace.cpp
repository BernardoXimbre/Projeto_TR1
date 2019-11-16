// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "CamadaEnlace.hpp"
# include "CamadaFisica.hpp"

void CamadaEnlaceTransmissora(int quadro[], int *tamanho) {
    // chama a proxima camada
    CamadaEnlaceTransmissoraEnquadramento(quadro, tamanho);
}   // fim do metodo CamadaEnlaceTransmissora

void CamadaEnlaceTransmissoraEnquadramento(int quadro[], int *tamanho) {
    int tipoDeEnquadramento = 0;  // alterar de acordo com o teste
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
    // CamadaEnlaceTransmissoraControleDeErro(quadro);
    // CamadaEnlaceTransmissoraControleDeFluxo(quadro);
    // chama a proxima camada
    CamadaFisicaTransmissora(quadroEnquadrado, tamanho);
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
*   quadro[] = {0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,0}
*   tamanho = 8
****************************************************************************/ 
int* CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres
(int quadro[], int *tamanho) {
    *tamanho = *tamanho*2;
    int i, j;

    int *quadro_enquadrado = new int[*tamanho];
    string contador = bitset<BITS>(BITS).to_string();
    for (i = 0, j = 0; i < *tamanho; i++, j--) {
        if (j == 0) {
            while (j < BITS) {
                if (contador[j] == '1') {
                    quadro_enquadrado[i+j] = 1;
                } else {
                    quadro_enquadrado[i+j] = 0;
                }
                j++;
            }
            i += j;
        }
        quadro_enquadrado[i] = quadro[i];
    }

    // implementacao do algoritmo
    return quadro_enquadrado;
}   // fim do metodo CamadaEnlaceTransmissoraContagemDeCaracteres

int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes
(int quadro[], int *tamanho) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraInsercaoDeBytes

int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits
(int quadro[], int *tamanho) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraInsercaoDeBits

int* CamadaEnlaceTransmissoraEnquadramentoViolacaoDaCamadaFisica
(int quadro[], int *tamanho) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraViolacaoDaCamadaFisica

void CamadaEnlaceReceptora(int quadro[], int *tamanho) {
    // CamadaEnlaceReceptoraEnquadramento(quadro, tamanho);
    // CamadaEnlaceReceptoraControleDeErro(quadro, tamanho);
    // CamadaEnlaceReceptoraControleDeFluxo(quadro, tamanho);
    CamadaDeAplicacaoReceptora(quadro, tamanho);   // chama proxima camada
}   // fim do metodo CamadaEnlaceReceptora

void CamadaEnlaceReceptoraEnquadramento(int quadro[], int *tamanho) {
    int tipoDeEnquadramento = 0;    // alterar de acordo com o teste
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
}   // fim do metodo CamadaEnlaceReceptoraEnquadramento

int* CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraContagemDeCaracteres

int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraInsercaoDeBytes

int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraInsercaoDeBits

int* CamadaEnlaceReceptoraEnquadramentoViolacaoDaCamadaFisica
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraViolacaoDaCamadaFisica

void CamadaEnlaceTransmissoraControleDeErro(int quadro[], int *tamanho) {
    int tipoDeControleDeErro = 0;   // alterar de acordo com o teste
    switch (tipoDeControleDeErro) {
        case 0 :    // bit de paridade par
            // codigo
            break;
        case 1 :    // bit de paridade impar
            // codigo
        break;
        case 2 :    // CRC
            // codigo
        case 3 :    // codigo de Hamming
            // codigo
        break;
        }   // fim do switch/case
}   // fim do metodo CamadaEnlaceTransmissoraControleDeErro

void CamadaEnlaceTransmissoraControleDeErroBitParidadePar
(int quadro[], int *tamanho) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroBitParidadePar

void CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar
(int quadro[], int *tamanho) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroBitParidadeImpar

void CamadaEnlaceTransmissoraControleDeErroCRC(int quadro[], int *tamanho) {
    // implementacao do algoritmo
    // usar polinomio CRC-32(IEEE 802)
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroCRC

void CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming
(int quadro[], int *tamanho) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraControleDeErroCodigoDehamming

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
    int tipoDeControleDeErro = 0;   // alterar de acordo com o teste
    switch (tipoDeControleDeErro) {
        case 0 :    // bit de paridade par
        // codigo
        break;
        case 1 :    // bit de paridade impar
        // codigo
        break;
        case 2 :    // CRC
        // codigo
        case 3 :    // codigo de hamming
        // codigo
        break;
    }   // fim do switch/case
}   // fim do metodo CamadaEnlaceReceptoraControleDeErro

void CamadaEnlaceReceptoraControleDeErroBitDeParidadePar
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroBitDeParidadePar

void CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar

void CamadaEnlaceReceptoraControleDeErroCRC(int quadro[], int *tamanho) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
    // usar polinomio CRC-32(IEEE 802)
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroCRC

void CamadaEnlaceReceptoraControleDeErroCodigoDeHamming
(int quadro[], int *tamanho) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroCodigoDeHamming


void CamadaEnlaceTransmissoraControleDeFluxo(int quadro[], int *tamanho) {
    // algum codigo aqui
}   // fim do metodo CamadaEnlaceTransmissoraControleDeFluxo

void CamadaEnlaceReceptoraControleDeFluxo(int quadro[], int *tamanho) {
    // algum codigo aqui
}   // fim do metodo CamadaEnlaceReceptoraControleDeFluxo
