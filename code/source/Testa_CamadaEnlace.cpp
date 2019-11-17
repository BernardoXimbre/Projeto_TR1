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
