// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"
# include "CamadaEnlace.hpp"


/***************TESTE CAMADA ENLACE******************/

TEST(CamadaEnlace, EnquadramentoContagemDeCaracteres) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_cabecalho[] = {
    0, 0, 0, 0, 0, 0, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
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
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, DenquadramentoContagemDeCaracteres) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_cabecalho[] = {
    0, 0, 0, 0, 0, 0, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro_cabecalho)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres
    (quadro_cabecalho, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, DenquadramentoContagemDeCaracteresErroQuadro) {
    int quadro[]= {0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_cabecalho[] = {
    0, 0, 0, 0, 0, 0, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro_cabecalho)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres
    (quadro_cabecalho, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, EnquadramentoInsercaoDeBytes) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_inse_bytes[] = {
    0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 0, 1, 1, 1, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 1, 1, 1, 1
    };
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_inse_bytes[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, EnquadramentoInsercaoDeBytesErroQuadro) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_inse_bytes[] = {
    1, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 0, 1, 1, 1, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 1, 1, 1, 1
    };
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_inse_bytes[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, DenquadramentoInsercaoDeBytes) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_inse_bytes[] = {
    0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 0, 1, 1, 1, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 1, 1, 1, 1
    };
    int tamanho = sizeof(quadro_inse_bytes)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes
    (quadro_inse_bytes, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, DenquadramentoInsercaoDeBytesErroQuadro) {
    int quadro[]= {0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0}, i;
    int quadro_inse_bytes[] = {
    0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 0, 1, 1, 1, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 1, 1, 1, 1
    };
    int tamanho = sizeof(quadro_inse_bytes)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes
    (quadro_inse_bytes, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, EnquadramentoInsercaoDeBits) {
    int quadro[]= {0, 1, 1, 1, 1, 1, 1, 0}, i;
    int quadro_inse_bits[] = {
    0, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 0, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_inse_bits[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, EnquadramentoInsercaoDeBitsB) {
    int quadro[]= {1, 1, 1, 1, 1, 1, 1, 0}, i;
    int quadro_inse_bits[] = {
    0, 1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 1, 0, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_inse_bits[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, EnquadramentoInsercaoDeBitsErroQuadro) {
    int quadro[]= {1, 1, 1, 1, 1, 1, 1, 0}, i;
    int quadro_inse_bits[] = {
    1, 1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 1, 0, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_inse_bits[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, DenquadramentoInsercaoDeBits) {
    int quadro[]= {0, 1, 1, 1, 1, 1, 0, 0}, i;
    int quadro_inse_bits[] = {
    0, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro_inse_bits)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits
    (quadro_inse_bits, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, DenquadramentoInsercaoDeBitsB) {
    int quadro[]= {1, 1, 1, 1, 1, 1, 1, 1}, i;
    int quadro_inse_bits[] = {
    0, 1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro_inse_bits)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits
    (quadro_inse_bits, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, DenquadramentoInsercaoDeBitsErroQuadro) {
    int quadro[]= {1, 1, 1, 1, 1, 1, 1, 0}, i;
    int quadro_inse_bits[] = {
    0, 1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 1, 1, 1, 1, 0
    };
    int tamanho = sizeof(quadro_inse_bits)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits
    (quadro_inse_bits, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceTransmissoraControleDeErroBitParidadePar) {
    int quadro[]= {1, 1, 1, 1, 1, 1, 0, 0}, i;
    int quadro_ParidadePar[] = {1, 1, 1, 1, 1, 1, 0, 0, 0};
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraControleDeErroBitParidadePar
    (quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_ParidadePar[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceTransmissoraControleDeErroBitParidadeParErro) {
    int quadro[]= {1, 1, 1, 1, 1, 1, 0, 0}, i;
    int quadro_ParidadePar[] = {1, 1, 1, 1, 1, 1, 0, 0, 1};
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraControleDeErroBitParidadePar
    (quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_ParidadePar[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceReceptoraControleDeErroBitDeParidadePar) {
    int quadro[]= {1, 1, 1, 1, 1, 1, 0, 0}, i;
    int quadro_ParidadePar[] = {1, 1, 1, 1, 1, 1, 0, 0, 0};
    int tamanho = sizeof(quadro_ParidadePar)/sizeof(int);
    bool validade;
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraControleDeErroBitDeParidadePar
    (quadro_ParidadePar, &tamanho, &validade);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    ASSERT_EQ(validade, true);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceReceptoraControleDeErroBitDeParidadeParErro) {
    int quadro[]= {1, 1, 1, 1, 1, 1, 0, 1}, i;
    int quadro_ParidadePar[] = {1, 1, 1, 1, 1, 1, 0, 0, 0};
    int tamanho = sizeof(quadro_ParidadePar)/sizeof(int);
    bool validade;
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraControleDeErroBitDeParidadePar
    (quadro_ParidadePar, &tamanho, &validade);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    ASSERT_EQ(validade, true);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar) {
    int quadro[]= {1, 1, 1, 1, 1, 0, 0, 0}, i;
    int quadro_ParidadeImpar[] = {1, 1, 1, 1, 1, 0, 0, 0, 0};
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar
    (quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_ParidadeImpar[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceTransmissoraControleDeErroBitParidadeImparErro) {
    int quadro[]= {1, 1, 1, 1, 1, 0, 0, 0}, i;
    int quadro_ParidadeImpar[] = {1, 1, 1, 1, 1, 1, 0, 0, 1};
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar
    (quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_ParidadeImpar[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar) {
    int quadro[]= {1, 1, 1, 1, 1, 0, 0, 0}, i;
    int quadro_ParidadeImpar[] = {1, 1, 1, 1, 1, 0, 0, 0, 0};
    int tamanho = sizeof(quadro_ParidadeImpar)/sizeof(int);
    bool validade;
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar
    (quadro_ParidadeImpar, &tamanho, &validade);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    ASSERT_EQ(validade, true);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceReceptoraControleDeErroBitDeParidadeImparErro) {
    int quadro[]= {1, 1, 1, 1, 1, 0, 0, 1}, i;
    int quadro_ParidadeImpar[] = {1, 1, 1, 1, 1, 0, 0, 0, 0};
    int tamanho = sizeof(quadro_ParidadeImpar)/sizeof(int);
    bool validade;
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar
    (quadro_ParidadeImpar, &tamanho, &validade);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    ASSERT_EQ(validade, true);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceTransmissoraControleDeErroCRC) {
    int quadro[]= {1, 0, 0, 1, 0, 0}, i;
    int quadro_CRC[] = {1, 0, 0, 1, 0, 0, 0, 1,
                        1, 0, 1, 0, 0, 0, 0, 1,
                        1, 0, 0, 0, 1, 1, 0, 1,
                        1, 0, 0, 0, 1, 1, 1, 0};
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraControleDeErroCRC
    (quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_CRC[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceTransmissoraControleDeErroCRCErro) {
    int quadro[]= {1, 0, 0, 1, 0, 0}, i;
    int quadro_CRC[] = {1, 0, 0, 1, 0, 0, 0, 1,
                        1, 0, 1, 0, 0, 0, 0, 1,
                        1, 0, 0, 0, 1, 1, 0, 1,
                        1, 0, 0, 0, 1, 1, 1, 1};
    int tamanho = sizeof(quadro)/sizeof(int);
    int verificador = 0;
    int *resultado =
    CamadaEnlaceTransmissoraControleDeErroCRC
    (quadro, &tamanho);

    for (i = 0; i< tamanho; i++) {
        if (quadro_CRC[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_NE(verificador, 0);
    delete resultado;
}

TEST(CamadaEnlace, CamadaEnlaceReceptoraControleDeErroCRC) {
    int quadro[]= {1, 0, 0, 1, 0, 0}, i;
    int quadro_CRC[] = {1, 0, 0, 1, 0, 0, 0, 1,
                        1, 0, 1, 0, 0, 0, 0, 1,
                        1, 0, 0, 0, 1, 1, 0, 1,
                        1, 0, 0, 0, 1, 1, 1, 0};
    int tamanho = sizeof(quadro_CRC)/sizeof(int);
    bool validade;
    int verificador = 0;
    int *resultado =
    CamadaEnlaceReceptoraControleDeErroCRC
    (quadro_CRC, &tamanho, &validade);

    for (i = 0; i< tamanho; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
            break;
        }
    }
    ASSERT_EQ(verificador, 0);
    ASSERT_EQ(validade, true);
    delete resultado;
}

/*
for (i = 0; i< tamanho; i++) {
        cout << quadro[i];
}
cout << "\n";
for (i = 0; i< tamanho; i++) {
    cout << resultado[i];
}
cout << "\n";
*/
