#include <stdio.h>
#include <string.h>

#define QTD 5 // número de territórios a serem cadastrados

// Definindo a struct
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    Territorio territorios[QTD];
    int i;

    //Cadastrando Territórios
    printf("\n===== Vamos cadastrar os 05 territórios iniciais deste Mundo =====\n");
    for (i = 0; i < QTD; i++) {
        printf("\n --- Cadastro do Território %d --- \n", i + 1);
        printf("Nome do Territótio: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // remove \n na leitura do fgets

        printf("Cor do Exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Número de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa o \n deixado pelo scanf
    }
    
    printf("\nCadastro inicial realizado com sucesso!\n");

    // Exibição dos Territórios
    printf("\n===== Lista de Territórios Cadastrados =====\n");
    for (i = 0; i < QTD; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("- Nome: %s\n", territorios[i].nome);
        printf("- Dominado por: Exército %s\n", territorios[i].cor);
        printf("- Tropas: %d\n", territorios[i].tropas);
}

return 0;
}