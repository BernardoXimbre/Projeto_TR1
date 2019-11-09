// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#include "CamadaFisica.hpp"

/***************************************************************************
* Função: CamadaFisicaTransmissoraCodificacaoBinaria
* Descrição
*   Codifica o quadro de bits em binario
* Parâmetros
*   quadro - nome da variavel que armazena o conjunto de bits.
* Valor retornado
*   retorna quadro[] - array em bits da variavel quadro.
* Assertiva de entrada
*   quadro[] == {1,0,1,1,0,1,0,0}
* Assertiva de saída
*   quadro[] == {1,0,1,1,0,1,0,0}
****************************************************************************/ 
int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]) {
    return quadro;  // implementacao do algoritmo
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria


/***************************************************************************
* Função: CamadaFisicaReceptoraCodificacaoBinaria
* Descrição
*   Decodifica o quadro de bits em binario
* Parâmetros
*   quadro - nome da variavel que armazena o conjunto de bits.
* Valor retornado
*   retorna quadro[] - array em bits da variavel quadro.
* Assertiva de entrada
*   quadro[] == {1,0,1,1,0,1,0,0}
* Assertiva de saída
*   quadro[] == {1,0,1,1,0,1,0,0}
****************************************************************************/ 
int* CamadaFisicaReceptoraCodificacaoBinaria(int quadro[]) {
    return quadro;  // implementacao do algoritmo para DECODIFICAR
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoBinaria


int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]) {
    // implementacao do algoritmo
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoManchester

int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]) {
    // implementacao do algoritmo
}   // fim do CamadaFisicaTransmissoraCodificacaoManchesterDiferencial

int* CamadaFisicaReceptoraCodificacaoManchester(int quadro[]) {
    // implementacao do algoritmo para DECODIFICAR
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoManchester

int* CamadaFisicaReceptoraCodificacaoManchesterDiferencial(int quadro[]) {
    // implementacao do algoritmo para DECODIFICAR
}   // fim do CamadaFisicaReceptoraDecodificacaoManchesterDiferencial
