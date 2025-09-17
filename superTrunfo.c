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
    float superPoder1, superPoder2;

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

    // Super Poder = população + área + PIB + pontos turísticos + PIB per capita + (1 / densidade)
    superPoder1 = (float)populacao1 + area1 + pib1 * 1e9f + pontos1 + pibPerCapita1 + (1 / densidade1);
    superPoder2 = (float)populacao2 + area2 + pib2 * 1e9f + pontos2 + pibPerCapita2 + (1 / densidade2);

    // Exibição das informações
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Comparações
    printf("\nComparação de Cartas:\n");

    // Comparação de População
    printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    // Comparação de Área
    printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
    // Comparação de PIB
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    // Comparação de Pontos Turísticos
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontos1 > pontos2);
    // Comparação de Densidade Populacional (quanto menor a densidade, maior a vitória)
    printf("Densidade Populacional: Carta 2 venceu (%d)\n", densidade1 > densidade2);
    // Comparação de PIB per Capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1 > pibPerCapita2);
    // Comparação de Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);

    return 0;
}
