// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

# include "CamadaFisica.hpp"

int tamanho_quadro = BITS;

/*
int main(void) {
    AplicacaoTransmissora();
    return 0;
}   // fim do metodo main
*/


void AplicacaoTransmissora(void) {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    getline(cin, mensagem);  // pega uma mensagem

    CamadaDeAplicacaoTransmissora(mensagem);    // chama a proxima camada
}   // fim do metodo AplicacaoTransmissora

/***************************************************************************
* Função: CamadaDeAplicacaoTransmissora
* Descrição
*   quebra a mensagem em quadro de BITS para cada caractere e atribui a um vetor int quadro[]
*   chama uma funcao CamadaFisicaTransmissora passando como parametro int quadro[]
* Parâmetros
*   mensagem - variavel que armazena a mensagem a ser enviada.
* Valor retornado
*   retorna void.
* Assertiva de entrada
*   mensagem == string mensagem
* Assertiva de saída
*   quadro == int quadro[]
****************************************************************************/
void CamadaDeAplicacaoTransmissora(string mensagem) {
    int i, j, k;
    int tamanho_mensagem = mensagem.length();
    tamanho_quadro = tamanho_mensagem*BITS;
    int* quadro = new int[tamanho_quadro];
    string auxiliar;

    for (i = 0, j = 0; i < tamanho_mensagem; i++) {
        auxiliar = bitset<BITS>(static_cast<int>(mensagem[i])).to_string();
        for (k = 0; k < auxiliar.length(); k++, j++) {
            if (auxiliar[k] == '1') {
                quadro[j] = 1;
            } else if (auxiliar[k] == '0') {
                quadro[j] = 0;
            }
        }
    }
    CamadaFisicaTransmissora(quadro);   // chama a proxima camada
}   // fim do metodo CamadaDeAplicacaoTransmissora


void CamadaFisicaTransmissora(int quadro[]) {
    int tipoDeCodificacao = CODIFICACAO;  // alterar de acordo o teste
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
int* CamadaFisicaTransmissoraCodificacaoManchester(int* quadro) {
    tamanho_quadro = tamanho_quadro*2;
    int i, j;
    int *quadro_manchester = new int[tamanho_quadro];
    for ( i = 0, j = 0; i < tamanho_quadro/2; i++, j+=2 ) {
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
*   quadro - nome da variavel que armazena o conjunto de bits.
* Valor retornado
*   retorna quadro_manchester_diferenciavel[] - array em bits codificado.
* Assertiva de entrada
*   quadro[]= {0,1,0,0,1,1,1,0}
* Assertiva de saída
*   quadro_manchester_diferencial[] = {0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,1};
****************************************************************************/
int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]) {
    tamanho_quadro = tamanho_quadro*2;

    int *quadro_manchester_diferencial = new int[tamanho_quadro];
    int i, j;

    for ( i = 1, j = 2; i < tamanho_quadro/2; i++, j+=2 ) {
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
    int i;
    int *fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    int *fluxoBrutoDeBitsPontoB = new int[tamanho_quadro];
    for (i = 0; i < tamanho_quadro; i++) {
        fluxoBrutoDeBitsPontoB[i] = fluxoBrutoDeBitsPontoA[i];
        // BITS! Sendo transferidos
    }   // fim do while
    //  chama proxima camada
    delete(fluxoBrutoDeBitsPontoA);
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}   // fim do metodo MeioDeTransmissao


void CamadaFisicaReceptora(int quadro[]) {
    int tipoDeDecodificacao = CODIFICACAO;    // alterar de acordo o teste
    int *fluxoBrutoDeBits;    // ATENÇÃO: trabalhar com BITS!!!
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
    tamanho_quadro = tamanho_quadro/2;
    int *quadro_manchester_decodificado = new int[tamanho_quadro];
    int i, j;
    for ( i = 0, j = 0; i < tamanho_quadro; i++, j+=2 ) {
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
    tamanho_quadro = tamanho_quadro/2;
    int *quadro_manchester_diferencial_decodificado = new int[tamanho_quadro];
    int i, j;

    for ( i = 1, j = 2; i < tamanho_quadro; i++, j+=2 ) {
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
*   quadro - variavel que armazena os dados em BITS
* Valor retornado
*   retorna void.
* Assertiva de entrada
*   quadro == int quadro[]
* Assertiva de saída
*   mensagem == string mensagem
****************************************************************************/
void CamadaDeAplicacaoReceptora(int quadro[]) {
    string mensagem = "";    // estava trabalhando com bits
    int i = 0, j = BITS-1;
    int auxiliar = 0;

    for (; i < tamanho_quadro; i++, j--) {
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
