// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"
# include "CamadaFisica.hpp"
# include "CamadaEnlace.hpp"



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


