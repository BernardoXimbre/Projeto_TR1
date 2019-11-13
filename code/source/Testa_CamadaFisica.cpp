// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"
# include "CamadaFisica.hpp"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CodificacaoBinaria, Transmissora) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int verificador = 0;
    int *resultado = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_EQ(verificador, 0);
}

TEST(CodificacaoBinaria, Transmissora_erro_quadro) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int verificador = 0;
    int *resultado = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 1);
}

TEST(Receptora_Binaria, correto) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int verificador = 0;
    int *resultado = CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_EQ(verificador, 0);
}

TEST(Receptora_Binaria, erro_quadro) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int verificador = 0;
    int *resultado = CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 1);
}
/***************************************************/



