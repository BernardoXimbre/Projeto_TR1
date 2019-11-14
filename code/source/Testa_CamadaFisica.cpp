// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"
# include "CamadaFisica.hpp"
# include "CamadaEnlace.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/***************TESTE CAMADA FISICA******************/


TEST(CodificacaoBinaria, Transmissora) {
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

TEST(CodificacaoBinaria, Transmissora_erro_quadro) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int verificador = 0;
    int *resultado = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
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
            break;
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
            break;
        }
    }
    ASSERT_NE(verificador, 1);
}
/***************************************************/

TEST(Transmissora_Manchester, correto) {
    int quadro[]= {0, 1, 0, 1, 0, 0, 1, 1};
    int i;
    int q_m[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};

    int verificador = 0;
    int * resultado = CamadaFisicaTransmissoraCodificacaoManchester(quadro);

    for (i = 0; i< sizeof(q_m)/sizeof(int); i++) {
        if (q_m[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(Transmissora_Manchester, erro_quadro) {
    int quadro[]= {1, 1, 0, 1, 0, 0, 1, 1};
    int i;
    int q_m[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};

    int verificador = 0;
    int * resultado = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
    for (i = 0; i< sizeof(q_m)/sizeof(int); i++) {
        if (q_m[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(Transmissora_Manchester, erro_quadro_manchester) {
    int quadro[]= {0, 1, 0, 1, 0, 0, 1, 1};
    int i;
    int q_m[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};

    int verificador = 0;
    int * resultado = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
    for (i = 0; i< sizeof(q_m)/sizeof(int); i++) {
        if (q_m[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(Receptora_Manchester, correto) {
    int quadro[]= {0, 1, 0, 1, 0, 0, 1, 1};
    int q_m[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};
    int i;
    int *resultado = CamadaFisicaReceptoraDecodificacaoManchester(q_m);
    int verificador = 0;
    for (i = 0; i < sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(Receptora_Manchester, erro_quadro) {
    int quadro[]= {1, 1, 0, 1, 0, 0, 1, 1};
    int q_m[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};
    int i,
    *resultado = CamadaFisicaReceptoraDecodificacaoManchester(q_m);
    int verificador = 0;
    for (i = 0; i < sizeof(q_m)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(Receptora_Manchester, erro_quadro_manchester) {
    int quadro[]= {0, 1, 0, 1, 0, 0, 1, 1};
    int q_m[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};
    int i;
    int *resultado = CamadaFisicaReceptoraDecodificacaoManchester(q_m);
    int verificador = 0;
    for (i = 0; i < sizeof(q_m)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}
/***************************************************/

TEST(Transmissora_Manchester_Diferencial, correto) {
    int quadro[]= {0, 1, 0, 0, 1, 1, 1, 0};
    int q_m_d[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int i,
    *resultado =
    CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (q_m_d[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(Transmissora_Manchester_Diferencial, errado_quadro) {
    int quadro[]= {1, 1, 0, 0, 1, 1, 1, 0};
    int q_m_d[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int i,
    *resultado =
    CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (q_m_d[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(Transmissora_Manchester_Diferencial, errado_quadro_manchester) {
    int quadro[]= {0, 1, 0, 0, 1, 1, 1, 0};
    int q_m_d[] = {1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int i,
    *resultado =
    CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (q_m_d[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(Receptora_Manchester_Diferencial, correto) {
    int quadro[]= {0, 1, 0, 0, 1, 1, 1, 0};
    int q_m_d[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int i,
    *resultado =
    CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(q_m_d);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(Receptora_Manchester_Diferencial, erro_quadro) {
    int quadro[]= {1, 1, 0, 0, 1, 1, 1, 0};
    int q_m_d[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int i,
    *resultado =
    CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(q_m_d);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(Receptora_Manchester_Diferencial, erro_quadro_manchester_diferencial) {
    int quadro[]= {1, 1, 0, 0, 1, 1, 1, 0};
    int q_m_d[] = {1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int i,
    *resultado =
    CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(q_m_d);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}
/***************************************************/


/***************TESTE CAMADA ENLACE******************/

