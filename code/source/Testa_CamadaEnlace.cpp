// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"
# include "CamadaFisica.hpp"

TEST(CAMDAENLACE, Transmissora) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int verificador = 0;
    int *resultado = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
}
