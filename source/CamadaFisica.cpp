// Copyright [2019] <Copyright Owner>

# include "../include/CamadaFisica.hpp"
# include <iostream>

using std::string;

int main() {
    AplicacaoTransmissora();
}   // fim do metodo main

void AplicacaoTransmissora(void) {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;
    // chama a proxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
}   // fim do metodo AplicacaoTransmissora

void CamadaDeAplicacaoTransmissora(string mensagem) {
    int quadro[] = mensagem;    // trabalhar com bits!!!
    // chama a proxima camada
    CamadaFisicaTransmissora(quadro);
}   // fim do metodo CamadaDeAplicacaoTransmissora

void CamadaFisicaTransmissora(int quadro[]) {
    int tipoDeCodificacao = 0;  // alterar de acordo o teste
    int fluxoBrutoDeBits[];  // ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeCodificacao) {
        case 0 :  // codificao binaria
        fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
        break;
        case 1 :    // codificacao manchester
        fluxoBrutoDeBits =
        CamadaFisicaTransmissoraCodificacaoManchester(quadro);
        break;
        case 2 :    // codificacao manchester diferencial
        fluxoBrutoDeBits =
        CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);
        break;
    }   // fim do switch/case
    MeioDeComunicacao(fluxoBrutoDeBits);
}   // fim do metodo CamadaFisicaTransmissora

int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria

int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoManchester

int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]) {
    // implementacao do algoritmo
}   // fim do CamadaFisicaTransmissoraCodificacaoManchesterDiferencial
/* Este metodo simula a transmissao da informacao no meio de
* comunicacao, passando de um pontoA (transmissor) para um
* ponto B (receptor)
*/

void MeioDeComunicacao(int fluxoBrutoDeBits[]) {
// OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!
    int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    while (fluxoBrutoDeBitsPontoB.lenght!=
    fluxoBrutoDeBitsPontoA) {
    fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA;   // BITS! Sendo transferidos
    }   // fim do while
    // chama proxima camada
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}   // fim do metodo MeioDeTransmissao

void CamadaFisicaReceptora(int quadro[]) {
    int tipoDeDecodificacao = 0;    // alterar de acordo o teste
    int fluxoBrutoDeBits[];    // ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeDecodificacao) {
        case 0 :    // codificao binaria
        fluxoBrutoDeBits =
        CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
        break;
        case 1 :    // codificacao manchester
        fluxoBrutoDeBits =
        CamadaFisicaReceptoraDecodificacaoManchester(quadro);
        break;
        case 2 :    // codificacao manchester diferencial
        fluxoBrutoDeBits =
        CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(quadro);
        break;
    }   // fim do switch/case
    // chama proxima camada
    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}   // fim do metodo CamadaFisicaTransmissora

int* CamadaFisicaReceptoraCodificacaoBinaria(int quadro[]) {
    // implementacao do algoritmo para DECODIFICAR
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoBinaria

int* CamadaFisicaReceptoraCodificacaoManchester(int quadro[]) {
    // implementacao do algoritmo para DECODIFICAR
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoManchester

int* CamadaFisicaReceptoraCodificacaoManchesterDiferencial(int quadro[]) {
    // implementacao do algoritmo para DECODIFICAR
}   // fim do CamadaFisicaReceptoraDecodificacaoManchesterDiferencial

void CamadaDeAplicacaoReceptora(int quadro[]) {
    string mensagem = quadro;    // estava trabalhando com bits
    // chama proxima camada
    AplicacaoReceptora(mensagem);
}   // fim do metodo CamadaDeAplicacaoReceptora

void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi:" << mensagem << endl;
}   // fim do metodo AplicacaoReceptora

