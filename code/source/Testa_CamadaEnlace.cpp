// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"
# include "CamadaEnlace.hpp"


/***************TESTE CAMADA ENLACE******************/

TEST(CamadaEnlace, EnquadramentoContagemDeCaracteres) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_cabecalho[] = {
    0, 0, 0, 0, 1, 0, 0, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    1, 1, 0, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_cabecalho[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, EnquadramentoContagemDeCaracteresErroQuadroCabecalho) {
    int quadro[]= {
    1, 1, 0, 1, 1, 1, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_cabecalho[] = {
    1, 0, 0, 0, 1, 0, 0, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    1, 1, 0, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro, &tamanho);
    cout << "\ntamanho " << tamanho;
    for (i = 0; i< tamanho; i++) {
        if (quadro_cabecalho[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}
