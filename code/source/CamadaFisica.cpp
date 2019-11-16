// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "CamadaFisica.hpp"
# include "CamadaEnlace.hpp"


void CamadaFisicaTransmissora(int quadro[], int *tamanho) {
    int tipoDeCodificacao = CODIFICACAO;  // alterar de acordo o teste
    int *fluxoBrutoDeBits;    // ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeCodificacao) {
        case 0 :    // codificao binaria
            fluxoBrutoDeBits =
            CamadaFisicaTransmissoraCodificacaoBinaria(quadro, tamanho);
            break;
        case 1 :    // codificacao manchester
            fluxoBrutoDeBits =
            CamadaFisicaTransmissoraCodificacaoManchester(quadro, tamanho);
            break;
        case 2 :    // codificacao manchester diferencial
            fluxoBrutoDeBits =
            CamadaFisicaTransmissoraCodificacaoManchesterDiferencial
            (quadro, tamanho);
            break;
    }   // fim do switch/case
    MeioDeComunicacao(fluxoBrutoDeBits, tamanho);
}   // fim do metodo CamadaFisicaTransmissora


/***************************************************************************
* Função: CamadaFisicaTransmissoraCodificacaoBinaria
* Descrição
*   Codifica o quadro de bits em binario
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro[] - array em bits da variavel quadro.
* Assertiva de entrada
*   quadro[] = {1,0,1,1,0,1,0,0}
*   tamanho = 8
* Assertiva de saída
*   quadro[] == {1,0,1,1,0,1,0,0}
*   tamanho = 8
****************************************************************************/ 
int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[], int *tamanho) {
    return quadro;  // implementacao do algoritmo
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria


/***************************************************************************
* Função: CamadaFisicaTransmissoraCodificacaoManchester
* Descrição
*   Codifica o quadro de bits de acordo com a transicao do clock 01
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_manchester[] - array em bits codificado.
* Assertiva de entrada
*   quadro[] = {1, 0, 1, 1, 0, 1, 0, 0}
*   tamanho = 8
* Assertiva de saída
*   quadro_manchester[] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1}
*   tamanho = 16
****************************************************************************/
int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[], int *tamanho) {
    int i, j;
    *tamanho = *tamanho*2;
    int *quadro_manchester = new int[*tamanho];
    for ( i = 0, j = 0; i < *tamanho/2; i++, j+=2 ) {
        if (quadro[i] == 0) {
            quadro_manchester[j] = 0;
            quadro_manchester[j+1] = 1;  // CLOCK 01
        } else {
            quadro_manchester[j] = 1;
            quadro_manchester[j+1] = 0;
        }
    }

    return quadro_manchester;
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoManchester


/***************************************************************************
* Função: CamadaFisicaTransmissoraCodificacaoManchesterDiferencial
* Descrição
*   Codifica o quadro de bits de acordo com a transicao de 0 e 1 do quadro com CLOCK = 01
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_manchester_diferenciavel[] - array em bits codificado.
* Assertiva de entrada
*   quadro[] = {0,1,0,0,1,1,1,0}
*   tamanho = 8
* Assertiva de saída
*   quadro_manchester_diferencial[] = {0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,1};
*   tamanho = 16
****************************************************************************/
int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial
(int quadro[], int *tamanho) {
    *tamanho = *tamanho*2;
    int *quadro_manchester_diferencial = new int[*tamanho];
    int i, j;

    for ( i = 1, j = 2; i < *tamanho/2; i++, j+=2 ) {
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
void MeioDeComunicacao(int fluxoBrutoDeBits[], int *tamanho) {
    // OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!
    int i;
    int *fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    int *fluxoBrutoDeBitsPontoB = new int[*tamanho];
    for (i = 0; i < *tamanho; i++) {
        fluxoBrutoDeBitsPontoB[i] = fluxoBrutoDeBitsPontoA[i];
    }
    delete fluxoBrutoDeBitsPontoA;
    // chama a proxima camada
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB, tamanho);
}   // fim do metodo MeioDeTransmissao


void CamadaFisicaReceptora(int quadro[], int *tamanho) {
    int tipoDeDecodificacao = CODIFICACAO;    // alterar de acordo o teste
    int *fluxoBrutoDeBits;    // ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeDecodificacao) {
        case 0 :    // codificao binaria
            fluxoBrutoDeBits =
            CamadaFisicaReceptoraDecodificacaoBinaria(quadro, tamanho);
            break;
        case 1 :    // codificacao manchester
            fluxoBrutoDeBits =
            CamadaFisicaReceptoraDecodificacaoManchester(quadro, tamanho);
            break;
        case 2 :    // codificacao manchester diferencial
            fluxoBrutoDeBits =
            CamadaFisicaReceptoraDecodificacaoManchesterDiferencial
            (quadro, tamanho);
            break;
    }   // fim do switch/case
    CamadaEnlaceReceptora(fluxoBrutoDeBits, tamanho);
}   // fim do metodo CamadaFisicaTransmissora


/***************************************************************************
* Função: CamadaFisicaReceptoraDecodificacaoBinaria
* Descrição
*   Decodifica o quadro de bits em binario
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro[] - array em bits da variavel quadro.
* Assertiva de entrada
*   quadro[] = {1,0,1,1,0,1,0,0}
*   tamanho = 8
* Assertiva de saída
*   quadro[] = {1,0,1,1,0,1,0,0}
*   tamanho = 8
****************************************************************************/ 
int* CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[], int *tamanho) {
    return quadro;  // implementacao do algoritmo para DECODIFICAR
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoBinaria


/***************************************************************************
* Função: CamadaFisicaReceptoraDecodificacaoManchester
* Descrição
*   Decodifica o quadro_manchester de bits de acordo com a transicao do clock 01
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_manchester_decodigicado[] - array em bits decodificado.
* Assertiva de entrada
*   quadro[] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1}
*   tamanho = 16
* Assertiva de saída
*   quadro_manchester_decodificado[] == {1, 0, 1, 1, 0, 1, 0, 0}
*   tamanho = 8
****************************************************************************/
int* CamadaFisicaReceptoraDecodificacaoManchester(int quadro[], int *tamanho) {
    *tamanho = *tamanho/2;
    int *quadro_manchester_decodificado = new int[*tamanho];
    int i, j;
    for ( i = 0, j = 0; i < *tamanho; i++, j+=2 ) {
        quadro_manchester_decodificado[i] = quadro[j];
    }
    return quadro_manchester_decodificado;
}   // fim do metodo CamadaFisicaReceptoraDecodificacaoManchester


/***************************************************************************
* Função: CamadaFisicaReceptoraDecodificacaoManchesterDiferencial
* Descrição
*   Decodifica o quadro_manchester_diferencial de bits de acordo com a o valor do quadro anterior
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna quadro_manchester_diferencial_decodificado[] - array em bits decodificado
* Assertiva de entrada
*   quadro_manchester_diferencial[] = {0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,1};
*   tamanho = 16
* Assertiva de saída
*   quadro_manchester_diferencial_decodificado[]= {0,1,0,0,1,1,1,0};
*   tamanho = 8
****************************************************************************/
int* CamadaFisicaReceptoraDecodificacaoManchesterDiferencial
(int quadro[], int *tamanho) {
    *tamanho = *tamanho/2;
    int *quadro_manchester_diferencial_decodificado = new int[*tamanho];
    int i, j;

    for ( i = 1, j = 2; i < *tamanho; i++, j+=2 ) {
        if (quadro[0] == 0) {
            quadro_manchester_diferencial_decodificado[0] = 0;
        }
        if (quadro[j] == quadro[j-1]) {
            quadro_manchester_diferencial_decodificado[i] = 1;  // transicao 0
        } else {
            quadro_manchester_diferencial_decodificado[i] = 0;
        }
    }
    return quadro_manchester_diferencial_decodificado;
}   // fim do CamadaFisicaReceptoraDecodificacaoManchesterDiferencial

/***************************************************************************
* Função: CamadaDeAplicacaoReceptora
* Descrição
*   converte cada quadro de BITS para um caractere e atribui a uma string mensagem
*   chama uma funcao AplicacaoReceptora passando como parametro mensagem
* Parâmetros
*   quadro - armazena o conjunto de bits
*   tamanho - armazena o tamanho do quadro
* Valor retornado
*   retorna void.
* Assertiva de entrada
*   quadro == int quadro[]
*   tamanho = int
* Assertiva de saída
*   mensagem == string mensagem
****************************************************************************/
void CamadaDeAplicacaoReceptora(int quadro[], int *tamanho) {
    string mensagem = "";    // estava trabalhando com bits
    int i = 0, j = BITS-1;
    int auxiliar = 0;

    for (; i < *tamanho; i++, j--) {
        auxiliar += pow(2, j)*quadro[i];
        if  (j == 0) {
            mensagem = mensagem + (static_cast<char>(auxiliar));
            auxiliar = 0;
            j = BITS;
        }
    }
    delete(quadro);
    AplicacaoReceptora(mensagem);   // chama proxima camada
}   // fim do metodo CamadaDeAplicacaoReceptora


void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi:" << mensagem << endl;
}   // fim do metodo AplicacaoReceptora
