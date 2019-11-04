// Copyright [2019] <Copyright Owner>

# include "../include/CamadaFisica.hpp"
# include <stdlib.h>
# include <bitset>
# include <iostream>
# include <string>
# include <cstring>

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
    int i, j;
    int tamanho_mensagem = mensagem.length();
    int tamanho_quadro = tamanho_mensagem*8;
    int* quadro = new int[tamanho_quadro];
    string auxiliar;

    for (i = 0, j = 0; i < tamanho_mensagem; i++) {
        auxiliar = bitset<8>(static_cast<int>(mensagem[i])).to_string();
        cout << auxiliar[0] << "\n";
        for (; j < (i*8) + 1; j++) {
            if (auxiliar[j] == '1') {
                cout << "entrou";
                quadro[j] = 1;
            } else if (auxiliar[j] == '0') {
                quadro[j] = 2;
                cout << "entrou";
            } else {
                break;
            }
        }
        
    }
    cout << quadro[0] << "\n";
    // int quadro[] = mensagem;    // trabalhar com bits!!!
    // chama a proxima camada
    // CamadaFisicaTransmissora(quadro);
}   // fim do metodo CamadaDeAplicacaoTransmissora

int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]) {
    return quadro;
    // implementacao do algoritmo
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria

int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]) {
    // implementacao do algoritmo
    return quadro;
}   // fim do metodo CamadaFisicaTransmissoraCodificacaoManchester

int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]) {
    // implementacao do algoritmo
    return quadro;
}   // fim do CamadaFisicaTransmissoraCodificacaoManchesterDiferencial