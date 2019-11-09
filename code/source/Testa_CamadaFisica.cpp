// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

# include "gtest/gtest.h"
# include "CamadaFisica.hpp"


int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
TEST(CodificacaoBinaria, Transmissora) {
    int quadro[]= {1, 1, 1, 1, 0}, i;
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        ASSERT_EQ(quadro[i],
        (CamadaFisicaTransmissoraCodificacaoBinaria(quadro))[i]);
    }
}

TEST(DecodificacaoBinaria, Receptora) {
    int quadro[]= {1, 1, 1, 1, 0}, i;
    for (i = 0; i< sizeof(quadro)/sizeof(int); i++) {
        ASSERT_EQ(quadro[i],
        (CamadaFisicaReceptoraCodificacaoBinaria(quadro))[i]);
    }
}


/*
TEST(QUANTIDADE_DE_LINHAS, sem_linhas_e_comentarios) {
    char name[]="sem_linhas_e_comentarios.c";
    ASSERT_EQ(0, Nline(name));
}
*/
