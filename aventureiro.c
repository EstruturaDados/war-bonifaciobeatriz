#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QTD 5 // número de territórios

// Definindo a struct
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void exibirTerritorios(Territorio territorios[], int qtd) {
    printf("\n====================================\n");
    printf("    MAPA DO MUNDO - ESTADO ATUAL    ");
    printf("\n====================================\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s (Exército %s, Tropas: %d)\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }
}

int rolarDado() {
    return (rand() % 6) + 1; // número entre 1 e 6
}

int main() {
    Territorio territorios[QTD];
    int i;

    srand(time(NULL)); // inicializa números aleatórios

    // Cadastro de territórios
    printf("\n======================================\n");
    printf("  WAR ESTRUTURADO - CADASTRO INICIAL  ");
    printf("\n======================================\n");
    for (i = 0; i < QTD; i++) {
        printf("\n--- Cadastrando Território %d ---\n", i + 1);

        printf("Nome do Território: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do Exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Número de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa o \n do buffer
    }

    while (1) {
        int atacante, defensor;

        // Exibe territórios
        exibirTerritorios(territorios, QTD);

        // Escolher atacante
        printf("\n--- FASE DE ATAQUE ---");
        printf("\nEscolha o território atacante (1 a 5, ou 0 para sair): ");
        scanf("%d", &atacante);
        getchar();
        if (atacante == 0) break;

        // Escolher defensor
        printf("Escolha o território defensor (1 a 5): ");
        scanf("%d", &defensor);
        getchar();

        // Ajusta índices
        atacante--;
        defensor--;

        // Valida escolhas
        if (atacante < 0 || atacante >= QTD || defensor < 0 || defensor >= QTD || atacante == defensor) {
            printf("\nEscolha inválida! Tente novamente.\n");
            continue;
        }

        // Rolagem de dados
        int dadoAtacante = rolarDado();
        int dadoDefensor = rolarDado();

        printf("\n--- RESULTADO DA BATALHA ---");
        printf("\nBatalha: %s (A) vs %s (D)\n", territorios[atacante].nome, territorios[defensor].nome);
        printf("O Atacante %s rolou o dado e tirou: %d\n", territorios[atacante].nome, dadoAtacante);
        printf("O Defensor %s rolou o dado e tirou: %d\n", territorios[defensor].nome, dadoDefensor);

        // Resultado
        if (dadoAtacante > dadoDefensor) {
            printf("Vitória do Atacante! O defensor perdeu 1 tropa.\n");
            territorios[defensor].tropas -= 1;
            if (territorios[defensor].tropas < 0) territorios[defensor].tropas = 0;
        } else {
            printf("Vitória do Defensor! O atacante perdeu 1 tropa.\n");
            territorios[atacante].tropas -= 1;
            if (territorios[atacante].tropas < 0) territorios[atacante].tropas = 0;
        }

        // Próximo turno
        printf("\nPressione ENTER para próximo turno...");
        getchar();
    }

    return 0;
}