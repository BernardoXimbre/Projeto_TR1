// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"
# include "CamadaFisica.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/***************TESTE CAMADA FISICA******************/


TEST(CamadaFisica, CodificacaoBinariaTransmissora) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaFisicaTransmissoraCodificacaoBinaria(quadro, &tamanho);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
}

TEST(CamadaFisica, CodificacaoBinariaTransmissoraErroQuadro) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado = CamadaFisicaTransmissoraCodificacaoBinaria
    (quadro, &tamanho);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 1);
}

TEST(CamadaFisica, CodificacaoBinariaReceptora) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaFisicaReceptoraDecodificacaoBinaria(quadro, &tamanho);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
}

TEST(CamadaFisica, CodificacaoBinariaReceptoraErroQuadro) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaFisicaReceptoraDecodificacaoBinaria(quadro, &tamanho);
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 1);
}

TEST(CamadaFisica, CodificacaoManchesterTransmissora) {
    int quadro[]= {0, 1, 0, 1, 0, 0, 1, 1}, i;
    int tamanho = sizeof(quadro)/sizeof(int);
    int q_m[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};

    int verificador = 0;
    int * resultado =
    CamadaFisicaTransmissoraCodificacaoManchester(quadro, &tamanho);

    for (i = 0; i< sizeof(q_m)/sizeof(int); i++) {
        if (q_m[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterTransmissoraErroQuadro) {
    int quadro[]= {1, 1, 0, 1, 0, 0, 1, 1}, i;
    int tamanho = sizeof(quadro)/sizeof(int);
    int q_m[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};

    int verificador = 0;
    int * resultado =
    CamadaFisicaTransmissoraCodificacaoManchester(quadro, &tamanho);
    for (i = 0; i< sizeof(q_m)/sizeof(int); i++) {
        if (q_m[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterTransmissoraErroQuadroManchester) {
    int quadro[]= {0, 1, 0, 1, 0, 0, 1, 1}, i;
    int q_m[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int * resultado =
    CamadaFisicaTransmissoraCodificacaoManchester(quadro, &tamanho);
    for (i = 0; i< sizeof(q_m)/sizeof(int); i++) {
        if (q_m[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterReceptora) {
    int quadro[]= {0, 1, 0, 1, 0, 0, 1, 1}, i;
    int q_m[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};
    int tamanho = sizeof(q_m)/sizeof(int);
    int *resultado =
    CamadaFisicaReceptoraDecodificacaoManchester(q_m, &tamanho);
    int verificador = 0;
    for (i = 0; i < sizeof(quadro)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterReceptoraErroQuadro) {
    int quadro[]= {1, 1, 0, 1, 0, 0, 1, 1}, i;
    int q_m[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};
    int tamanho = sizeof(q_m)/sizeof(int);
    int *resultado =
    CamadaFisicaReceptoraDecodificacaoManchester(q_m, &tamanho);
    int verificador = 0;
    for (i = 0; i < sizeof(q_m)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterReceptoraErroQuadroManchester) {
    int quadro[]= {0, 1, 0, 1, 0, 0, 1, 1}, i;
    int q_m[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};
    int tamanho = sizeof(q_m)/sizeof(int);
    int *resultado =
    CamadaFisicaReceptoraDecodificacaoManchester(q_m, &tamanho);
    int verificador = 0;
    for (i = 0; i < sizeof(q_m)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterDiferencialTransmissora) {
    int quadro[]= {0, 1, 0, 0, 1, 1, 1, 0}, i;
    int q_m_d[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int tamanho = sizeof(q_m_d)/sizeof(int);
    int *resultado =
    CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro, &tamanho);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (q_m_d[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterDiferencialTransmissoraErroQuadro) {
    int quadro[]= {1, 1, 0, 0, 1, 1, 1, 0}, i;
    int q_m_d[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int tamanho = sizeof(q_m_d)/sizeof(int);
    int *resultado =
    CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro, &tamanho);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (q_m_d[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica,
CodificacaoManchesterDiferencialTransmissoraErroQuadroManchester) {
    int quadro[]= {0, 1, 0, 0, 1, 1, 1, 0}, i;
    int q_m_d[] = {1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int tamanho = sizeof(q_m_d)/sizeof(int);
    int *resultado =
    CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro, &tamanho);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (q_m_d[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterDiferencialReceptora) {
    int quadro[]= {0, 1, 0, 0, 1, 1, 1, 0}, i;
    int q_m_d[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int tamanho = sizeof(q_m_d)/sizeof(int);
    int *resultado =
    CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(q_m_d, &tamanho);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica, CodificacaoManchesterDiferencialReceptoraErroQuadro) {
    int quadro[]= {1, 1, 0, 0, 1, 1, 1, 0}, i;
    int q_m_d[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int tamanho = sizeof(q_m_d)/sizeof(int);
    int *resultado =
    CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(q_m_d, &tamanho);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaFisica,
CodificacaoManchesterDiferencialReceptoraErroQuadroManchesterDiferencial) {
    int quadro[]= {1, 1, 0, 0, 1, 1, 1, 0}, i;
    int q_m_d[] = {1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int verificador = 0;
    int tamanho = sizeof(q_m_d)/sizeof(int);
    int *resultado =
    CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(q_m_d, &tamanho);

    for (i = 0; i< sizeof(q_m_d)/sizeof(int); i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}
