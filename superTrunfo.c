#include <stdio.h>

int main() {
    // Estruturas para armazenar as cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2; // População como unsigned long int
    float area1, area2;
    float pib1, pib2; // em bilhões de reais
    int pontos1, pontos2;

    // Variáveis calculadas
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // Entrada de dados para a primeira carta
    printf("Digite os dados da Carta 1:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %s", cidade1);

    printf("População: ");
    scanf("%lu", &populacao1); // Leitura de população como unsigned long int

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // Entrada de dados para a segunda carta
    printf("\nDigite os dados da Carta 2:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %s", cidade2);

    printf("População: ");
    scanf("%lu", &populacao2); // Leitura de população como unsigned long int

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // Cálculos

    // Densidade = população / área (hab/km²)
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    // PIB per capita = PIB em reais / população
    pibPerCapita1 = pib1 * 1e9f / populacao1;
    pibPerCapita2 = pib2 * 1e9f / populacao2;

    // Inserção do atributo para comparação
    int atributo;
    printf("\nEscolha o atributo para comparação (1 - População, 2 - Área, 3 - PIB, 4 - PIB per Capita, 5 - Densidade Populacional): ");
    scanf("%d", &atributo);

    // Comparação baseada no atributo escolhido
    if (atributo == 1) { // Comparar População
        printf("\nComparação de Cartas (Atributo: População):\n");
        printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
        printf("Carta 2 - %s: %lu\n", cidade2, populacao2);

        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (populacao2 > populacao1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo == 2) { // Comparar Área
        printf("\nComparação de Cartas (Atributo: Área):\n");
        printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);

        if (area1 > area2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (area2 > area1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo == 3) { // Comparar PIB
        printf("\nComparação de Cartas (Atributo: PIB):\n");
        printf("Carta 1 - %s: %.2f bilhões de reais\n", cidade1, pib1);
        printf("Carta 2 - %s: %.2f bilhões de reais\n", cidade2, pib2);

        if (pib1 > pib2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (pib2 > pib1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo == 4) { // Comparar PIB per Capita
        printf("\nComparação de Cartas (Atributo: PIB per Capita):\n");
        printf("Carta 1 - %s: R$ %.2f\n", cidade1, pibPerCapita1);
        printf("Carta 2 - %s: R$ %.2f\n", cidade2, pibPerCapita2);

        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (pibPerCapita2 > pibPerCapita1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo == 5) { // Comparar Densidade Populacional
        printf("\nComparação de Cartas (Atributo: Densidade Populacional):\n");
        printf("Carta 1 - %s: %.2f hab/km²\n", cidade1, densidade1);
        printf("Carta 2 - %s: %.2f hab/km²\n", cidade2, densidade2);

        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (densidade2 < densidade1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}


