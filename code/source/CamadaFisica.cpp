// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

# include "CamadaFisica.hpp"

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


/***************************************************************************
* Função: CamadaFisicaTransmissoraCodificacaoManchester
* Descrição
*   Codifica o quadro de bits de acordo com a transicao do clock 01
* Parâmetros
*   quadro - nome da variavel que armazena o conjunto de bits.
* Valor retornado
*   retorna quadro_manchester[] - array em bits codificado.
* Assertiva de entrada
*   quadro[] = {1, 0, 1, 1, 0, 1, 0, 0}
* Assertiva de saída
*   quadro_manchester[] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1}
****************************************************************************/
int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]) {
    int *quadro_manchester = new int[TAMANHO_QUADRO*2];
    int i, j;

    for ( i = 0, j = 0; i < TAMANHO_QUADRO*2; i++, j++ ) {
        if (quadro[i] == 0) {
            quadro_manchester[j] = 0;
            quadro_manchester[++j] = 1;
        } else {
            quadro_manchester[j] = 1;
            quadro_manchester[++j] = 0;
        }
    }
    return quadro_manchester;
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoManchester


/***************************************************************************
* Função: CamadaFisicaReceptoraCodificacaoManchester
* Descrição
*   Decodifica o quadro_manchester de bits de acordo com a transicao do clock 01
* Parâmetros
*   quadro - nome da variavel que armazena o conjunto de bits.
* Valor retornado
*   retorna quadro_manchester_decodigicado[] - array em bits decodificado.
* Assertiva de entrada
*   quadro[] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1}
* Assertiva de saída
*   quadro_manchester_decodificado[] == {1, 0, 1, 1, 0, 1, 0, 0}
****************************************************************************/
int* CamadaFisicaReceptoraCodificacaoManchester(int quadro[]) {
    int *quadro_manchester_decodificado = new int[TAMANHO_QUADRO];
    int i, j;
    for ( i = 0, j = 0; i < TAMANHO_QUADRO; i++, j+=2 ) {
        quadro_manchester_decodificado[i] = quadro[j];
    }
    return quadro_manchester_decodificado;
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoManchester


/***************************************************************************
* Função: CamadaFisicaTransmissoraCodificacaoManchesterDiferencial
* Descrição
*   Codifica o quadro de bits de acordo com a transicao de 0 e 1 do quadro com CLOCK = 01
* Parâmetros
*   quadro - nome da variavel que armazena o conjunto de bits.
* Valor retornado
*   retorna quadro_manchester_diferenciavel[] - array em bits codificado.
* Assertiva de entrada
*   quadro[]= {0,1,0,0,1,1,1,0}
* Assertiva de saída
*   quadro_manchester_diferencial[] = {0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,1};
****************************************************************************/
int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]) {
    int *quadro_manchester_diferencial = new int[TAMANHO_QUADRO*2];
    int i, j;

    for ( i = 1, j = 2; i < TAMANHO_QUADRO; i++, j+=2 ) {
        if (quadro[0] == 0) {
            quadro_manchester_diferencial[0] = 0;
            quadro_manchester_diferencial[1] = 1;
        } else {
            quadro_manchester_diferencial[0] = 1;
            quadro_manchester_diferencial[1] = 0;
        }
        if (quadro[i] == 1) {                       // CLOCK 01
            quadro_manchester_diferencial[j] =
            quadro_manchester_diferencial[j-1];
            quadro_manchester_diferencial[j+1] =
            !(quadro_manchester_diferencial[j]);
        } else {
            quadro_manchester_diferencial[j] =
            !(quadro_manchester_diferencial[j-1]);
            quadro_manchester_diferencial[j+1] =
            !(quadro_manchester_diferencial[j]);
        }
    }

    return quadro_manchester_diferencial;
}   // fim do CamadaFisicaTransmissoraCodificacaoManchesterDiferencial


/***************************************************************************
* Função: CamadaFisicaReceptoraCodificacaoManchesterDiferencial
* Descrição
*   Decodifica o quadro_manchester_diferencial de bits de acordo com a o valor do quadro anterior
* Parâmetros
*   quadro - nome da variavel que armazena o conjunto de bits
*   clock 01
* Valor retornado
*   retorna quadro_manchester_diferencial_decodificado[] - array em bits decodificado
* Assertiva de entrada
*   quadro_manchester_diferencial[] = {0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,1};
* Assertiva de saída
*   quadro_manchester_diferencial_decodificado[]= {0,1,0,0,1,1,1,0};
****************************************************************************/
int* CamadaFisicaReceptoraCodificacaoManchesterDiferencial(int quadro[]) {
    int *quadro_manchester_diferencial_decodificado = new int[TAMANHO_QUADRO];
    int i, j;

    for ( i = 1, j = 2; i < TAMANHO_QUADRO; i++, j+=2 ) {
        if (quadro[0] == 0) {
            quadro_manchester_diferencial_decodificado[0] = 0;
        }
        if (quadro[j] == quadro[j-1]) {
            quadro_manchester_diferencial_decodificado[i] = 1;
        } else {
            quadro_manchester_diferencial_decodificado[i] = 0;
        }
    }
    
    return quadro_manchester_diferencial_decodificado;
}   // fim do CamadaFisicaReceptoraDecodificacaoManchesterDiferencial
