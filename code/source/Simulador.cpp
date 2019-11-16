// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"

# include "CamadaEnlace.hpp"
# include "CamadaFisica.hpp"

int main(void) {
    AplicacaoTransmissora();
    return 0;
}   // fim do metodo main

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
    int tamanho = tamanho_mensagem*BITS;
    int* quadro = new int[tamanho];
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
    // chama a proxima camada enlace
    CamadaEnlaceTransmissora(quadro, &tamanho);
    delete quadro;
}   // fim do metodo CamadaDeAplicacaoTransmissora
