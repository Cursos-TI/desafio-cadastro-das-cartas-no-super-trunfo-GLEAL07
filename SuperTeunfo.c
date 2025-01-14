#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 32

/* Estrutura que representa uma carta */
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

/* Função para limpar o buffer */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' & c != EOF);
}

/* Função para cadastrar uma carta */
void cadastrarCarta(Carta *carta) {
    printf("Digite o estado (uma letra): ");
    scanf(" %c", &carta->estado);
    limparBuffer(); /* Limpa o buffer após leitura de char */

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);
    limparBuffer(); /* Limpa o buffer após leitura de string curta */ 

    printf("Digite o nome da cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0'; /* Remove o '\n' */

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    limparBuffer();

    printf("Digite a área em km²: ");
    scanf("%f", &carta->area);
    limparBuffer();  /* Limpa o buffer após leitura de float */

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    limparBuffer();  /* Limpa o buffer após leitura de float */ 

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    limparBuffer();
}

/* Função para exibir os dados de uma carta */
void exibirCarta(const Carta *carta) {
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontosTuristicos);
}

int main() {
    Carta cartas[MAX_CARTAS];
    int quantidade = 0;

    printf("Bem-vindo ao cadastro de cartas Super Trunfo - Países!\n");
    
    while (quantidade < MAX_CARTAS) {
        printf("\n== Cadastro da carta %d ==\n", quantidade + 1);
        cadastrarCarta(&cartas[quantidade]);
        quantidade++;

        printf("\nDeseja cadastrar outra carta? (S/N): ");
        char continuar;
        scanf(" %c", &continuar);
        limparBuffer();
        if (continuar == 'N' || continuar == 'n') {
            break;
        }
    }

    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nCarta %d:\n", i + 1);
        exibirCarta(&cartas[i]);
    }

    return 0;
}
