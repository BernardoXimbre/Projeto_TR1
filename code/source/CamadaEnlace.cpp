// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "CamadaEnlace.hpp"
# include "CamadaFisica.hpp"

void CamadaEnlaceTransmissora(int quadro[]) {
    CamadaEnlaceTransmissoraEnquadramento(quadro);
    CamadaEnlaceTransmissoraControleDeErro(quadro);
    CamadaEnlaceTransmissoraControleDeFluxo(quadro);
    CamadaFisicaTransmissora(quadro);  // chama proxima camada
}   // fim do metodo CamadaEnlaceTransmissora

void CamadaEnlaceTransmissoraEnquadramento(int quadro[]) {
    int tipoDeEnquadramento = 0;  // alterar de acordo com o teste
    int *quadroEnquadrado;
    switch (tipoDeEnquadramento) {
        case 0 :    // contagem de caracteres
            quadroEnquadrado =
            CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case 1 :    // insercao de bytes
            quadroEnquadrado =
            CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        case 2 :    // insercao de bits
            quadroEnquadrado =
            CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro);
            break;
        case 3 :    // violacao da camada fisica
            quadroEnquadrado =
            CamadaEnlaceTransmissoraEnquadramentoViolacaoDaCamadaFisica(quadro);
            break;
    }   // fim do switch/case
}   // fim do metodo CamadaEnlaceTransmissoraEnquadramento

int* CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraContagemDeCaracteres

int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraInsercaoDeBytes

int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraInsercaoDeBits

int* CamadaEnlaceTransmissoraEnquadramentoViolacaoDaCamadaFisica(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraViolacaoDaCamadaFisica

void CamadaEnlaceReceptora(int quadro[]) {
    CamadaEnlaceReceptoraEnquadramento(quadro);
    CamadaEnlaceReceptoraControleDeErro(quadro);
    CamadaEnlaceReceptoraControleDeFluxo(quadro);
    CamadaDeAplicacaoReceptora(quadro);  // chama proxima camada
}   // fim do metodo CamadaEnlaceReceptora

void CamadaEnlaceReceptoraEnquadramento(int quadro[]) {
    int tipoDeEnquadramento = 0;    // alterar de acordo com o teste
    int *quadroDesenquadrado;
    switch (tipoDeEnquadramento) {
        case 0 :    // contagem de caracteres
            quadroDesenquadrado =
            CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case 1 :    // insercao de bytes
            quadroDesenquadrado =
            CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        case 2 :    // insercao de bits
            quadroDesenquadrado =
            CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits(quadro);
            break;
        case 3 :    // violacao da camada fisica
            quadroDesenquadrado =
            CamadaEnlaceReceptoraEnquadramentoViolacaoDaCamadaFisica(quadro);
            break;
    }   // fim do switch/case
}   // fim do metodo CamadaEnlaceReceptoraEnquadramento

int* CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres(int quadro[]) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraContagemDeCaracteres

int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes(int quadro[]) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraInsercaoDeBytes

int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits(int quadro[]) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraInsercaoDeBits

int* CamadaEnlaceReceptoraEnquadramentoViolacaoDaCamadaFisica
(int quadro[]) {
    // implementacao do algoritmo para DESENQUADRAR
}   // fim do metodo CamadaEnlaceReceptoraViolacaoDaCamadaFisica

void CamadaEnlaceTransmissoraControleDeErro(int quadro[]) {
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

void CamadaEnlaceTransmissoraControleDeErroBitParidadePar(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroBitParidadePar

void CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroBitParidadeImpar

void CamadaEnlaceTransmissoraControleDeErroCRC(int quadro[]) {
    // implementacao do algoritmo
    // usar polinomio CRC-32(IEEE 802)
}   // fim do metodo CamadaEnlaceTransmissoraControledeErroCRC

void CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming(int quadro[]) {
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
void CamadaEnlaceReceptoraControleDeErro(int quadro[]) {
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

void CamadaEnlaceReceptoraControleDeErroBitDeParidadePar(int quadro[]) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroBitDeParidadePar

void CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar(int quadro[]) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar

void CamadaEnlaceReceptoraControleDeErroCRC(int quadro[]) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
    // usar polinomio CRC-32(IEEE 802)
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroCRC

void CamadaEnlaceReceptoraControleDeErroCodigoDeHamming(int quadro[]) {
    // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}   // fim do metodo CamadaEnlaceReceptoraControleDeErroCodigoDeHamming


void CamadaEnlaceTransmissoraControleDeFluxo(int quadro[]) {
    // algum codigo aqui
}   // fim do metodo CamadaEnlaceTransmissoraControleDeFluxo

void CamadaEnlaceReceptoraControleDeFluxo(int quadro[]) {
    // algum codigo aqui
}   // fim do metodo CamadaEnlaceReceptoraControleDeFluxo
