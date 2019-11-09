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
    for (i = 0; i< TAMANHO_QUADRO; i++) {
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
    for (i = 0; i< TAMANHO_QUADRO; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 1);
}

TEST(DecodificacaoBinaria, Receptora) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int verificador = 0;
    int *resultado = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
    for (i = 0; i< TAMANHO_QUADRO; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_EQ(verificador, 0);
}

TEST(DecodificacaoBinaria, Receptora_erro_quadro) {
    int quadro[]= {1, 1, 0, 1, 1, 1, 1, 0}, i;
    int verificador = 0;
    int *resultado = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
    for (i = 0; i< TAMANHO_QUADRO; i++) {
        if (quadro[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 1);
}

TEST(CodificacaoManchester, Transmissora) {
    int quadro[]= {1, 0, 1, 1, 0, 1, 0, 0};
    int quadro_manchester[] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int i, *resultado = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
    int verificador = 0;
    for (i = 0; i< TAMANHO_QUADRO*2; i++) {
        if (quadro_manchester[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_EQ(verificador, 0);
}
TEST(CodificacaoManchester, Transmissora_erro_quadro) {
    int quadro[]= {0, 0, 1, 1, 0, 1, 0, 0};
    int quadro_manchester[] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    int i, *resultado = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
    int verificador = 0;
    for (i = 0; i< TAMANHO_QUADRO*2; i++) {
        if (quadro_manchester[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
}

TEST(CodificacaoManchester, Transmissora_erro_quadro_manchester) {
    int quadro[]= {1, 0, 1, 1, 0, 1, 0, 0};
    int quadro_manchester[] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0};
    int i, *resultado = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
    int verificador = 0;
    for (i = 0; i< TAMANHO_QUADRO*2; i++) {
        if (quadro_manchester[i] != resultado[i]) {
            verificador = 1;
        }
    }
    ASSERT_NE(verificador, 0);
}
/*
TEST(DecodificacaoManchester, Receptora) {
    int quadro[]= {1, 0, 1, 1, 0, 1, 0, 0},
    quadro_manchester[] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1},
    i,
    *resultado = CamadaFisicaReceptoraCodificacaoManchester(quadro_manchester);

    for (i = 0; i< TAMANHO_QUADRO; i++) {
        ASSERT_EQ(quadro[i],
        resultado[i]);
    }
}



TEST(QUANTIDADE_DE_LINHAS, sem_linhas_e_comentarios) {
    char name[]="sem_linhas_e_comentarios.c";
    ASSERT_EQ(0, Nline(name));
}
*/
