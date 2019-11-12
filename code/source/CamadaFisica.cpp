// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

# include "CamadaFisica.hpp"

void main(void) {
    AplicacaoTransmissora();
}   // fim do metodo main

void AplicacaoTransmissora(void) {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;
    // chama a proxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
    // em um exemplo mais realistico, aqui seria dado um SEND do SOCKET
}   // fim do metodo AplicacaoTransmissora

void CamadaDeAplicacaoTransmissora(string mensagem) {
    // int quadro [] = mensagem //trabalhar com bits!!!
    // chama a proxima camada
    CamadaFisicaTransmissora(quadro);
}   // fim do metodo CamadaDeAplicacaoTransmissora

void CamadaFisicaTransmissora(int quadro[]) {
    int tipoDeCodificacao = 0;  // alterar de acordo o teste
    int *fluxoBrutoDeBits;    // ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeCodificacao) {
        case 0 :    // codificao binaria
            fluxoBrutoDeBits =
            CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
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


/* Este metodo simula a transmissao da informacao no meio de
* comunicacao, passando de um pontoA (transmissor) para um
* ponto B (receptor)
*/
void MeioDeComunicacao(int fluxoBrutoDeBits[]) {
    // OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!
    int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
        fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA;
        // BITS! Sendo transferidos
    }   // fim do while
    //  chama proxima camada
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


/***************************************************************************
* Função: CamadaFisicaReceptoraDecodificacaoBinaria
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
int* CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[]) {
    return quadro;  // implementacao do algoritmo para DECODIFICAR
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoBinaria



/***************************************************************************
* Função: CamadaFisicaReceptoraDecodificacaoManchester
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
int* CamadaFisicaReceptoraDecodificacaoManchester(int quadro[]) {
    int *quadro_manchester_decodificado = new int[TAMANHO_QUADRO];
    int i, j;
    for ( i = 0, j = 0; i < TAMANHO_QUADRO; i++, j+=2 ) {
        quadro_manchester_decodificado[i] = quadro[j];
    }
    return quadro_manchester_decodificado;
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoManchester



/***************************************************************************
* Função: CamadaFisicaReceptoraDecodificacaoManchesterDiferencial
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
int* CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(int quadro[]) {
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

void CamadaDeAplicacaoReceptora(int quadro[]) {
    // string mensagem = quadro []; //estava trabalhando com bits
    // chama proxima camada
    AplicacaoReceptora(mensagem);
}   // fim do metodo CamadaDeAplicacaoReceptora

void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi:" << mensagem << endl;
}   // fim do metodo AplicacaoReceptora
