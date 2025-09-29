#include <stdio.h>
#include <string.h>

// Estrutura para organizar os dados das cartas
typedef struct {
    char estado;
    char codigo[10];
    char pais[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

// Função para calcular densidade demográfica
void calcularIndicadores(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade = (float)carta->populacao / carta->area;
        carta->pibPerCapita = (carta->pib * 1e9f) / carta->populacao;
    } else {
        carta->densidade = 0;
        carta->pibPerCapita = 0;
    }
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n========================================\n");
    printf("       SUPER TRUNFO - MENU DE COMPARACAO\n");
    printf("========================================\n");
    printf("Escolha o atributo para comparacao:\n\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("0 - Sair\n");
    printf("========================================\n");
    printf("Opcao: ");
}

// Função para comparar as cartas
void compararCartas(Carta carta1, Carta carta2, int atributo) {
    printf("\n========================================\n");
    printf("       RESULTADO DA COMPARACAO\n");
    printf("========================================\n");
    printf("Carta 1: %s (%c%s)\n", carta1.pais, carta1.estado, carta1.codigo);
    printf("Carta 2: %s (%c%s)\n", carta2.pais, carta2.estado, carta2.codigo);
    printf("========================================\n");
    
    switch (atributo) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("Carta 1: %lu habitantes\n", carta1.populacao);
            printf("Carta 2: %lu habitantes\n", carta2.populacao);
            printf("----------------------------------------\n");
            
            if (carta1.populacao > carta2.populacao) {
                printf("VENCEDOR: Carta 1 (%s)\n", carta1.pais);
                printf("Diferenca: %lu habitantes\n", 
                       carta1.populacao - carta2.populacao);
            } else if (carta2.populacao > carta1.populacao) {
                printf("VENCEDOR: Carta 2 (%s)\n", carta2.pais);
                printf("Diferenca: %lu habitantes\n", 
                       carta2.populacao - carta1.populacao);
            } else {
                printf("RESULTADO: Empate!\n");
            }
            break;
            
        case 2: // Área
            printf("Atributo: Area\n");
            printf("Carta 1: %.2f km²\n", carta1.area);
            printf("Carta 2: %.2f km²\n", carta2.area);
            printf("----------------------------------------\n");
            
            if (carta1.area > carta2.area) {
                printf("VENCEDOR: Carta 1 (%s)\n", carta1.pais);
                printf("Diferenca: %.2f km²\n", carta1.area - carta2.area);
            } else if (carta2.area > carta1.area) {
                printf("VENCEDOR: Carta 2 (%s)\n", carta2.pais);
                printf("Diferenca: %.2f km²\n", carta2.area - carta1.area);
            } else {
                printf("RESULTADO: Empate!\n");
            }
            break;
            
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("Carta 1: R$ %.2f bilhoes\n", carta1.pib);
            printf("Carta 2: R$ %.2f bilhoes\n", carta2.pib);
            printf("----------------------------------------\n");
            
            if (carta1.pib > carta2.pib) {
                printf("VENCEDOR: Carta 1 (%s)\n", carta1.pais);
                printf("Diferenca: R$ %.2f bilhoes\n", carta1.pib - carta2.pib);
            } else if (carta2.pib > carta1.pib) {
                printf("VENCEDOR: Carta 2 (%s)\n", carta2.pais);
                printf("Diferenca: R$ %.2f bilhoes\n", carta2.pib - carta1.pib);
            } else {
                printf("RESULTADO: Empate!\n");
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("Carta 1: %d pontos turisticos\n", carta1.pontosTuristicos);
            printf("Carta 2: %d pontos turisticos\n", carta2.pontosTuristicos);
            printf("----------------------------------------\n");
            
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("VENCEDOR: Carta 1 (%s)\n", carta1.pais);
                printf("Diferenca: %d pontos turisticos\n", 
                       carta1.pontosTuristicos - carta2.pontosTuristicos);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("VENCEDOR: Carta 2 (%s)\n", carta2.pais);
                printf("Diferenca: %d pontos turisticos\n", 
                       carta2.pontosTuristicos - carta1.pontosTuristicos);
            } else {
                printf("RESULTADO: Empate!\n");
            }
            break;
            
        case 5: // Densidade Demográfica (REGRA INVERTIDA)
            printf("Atributo: Densidade Demografica\n");
            printf("Carta 1: %.2f hab/km²\n", carta1.densidade);
            printf("Carta 2: %.2f hab/km²\n", carta2.densidade);
            printf("----------------------------------------\n");
            printf("REGRA ESPECIAL: Vence a carta com MENOR densidade!\n");
            printf("----------------------------------------\n");
            
            // Validação para evitar divisão por zero
            if (carta1.area <= 0 || carta2.area <= 0) {
                printf("ERRO: Area invalida para calculo de densidade!\n");
            } else {
                // Lógica invertida: menor densidade vence
                if (carta1.densidade < carta2.densidade) {
                    printf("VENCEDOR: Carta 1 (%s)\n", carta1.pais);
                    printf("Diferenca: %.2f hab/km²\n", 
                           carta2.densidade - carta1.densidade);
                } else if (carta2.densidade < carta1.densidade) {
                    printf("VENCEDOR: Carta 2 (%s)\n", carta2.pais);
                    printf("Diferenca: %.2f hab/km²\n", 
                           carta1.densidade - carta2.densidade);
                } else {
                    printf("RESULTADO: Empate!\n");
                }
            }
            break;
            
        case 6: // PIB per Capita
            printf("Atributo: PIB per Capita\n");
            printf("Carta 1: R$ %.2f\n", carta1.pibPerCapita);
            printf("Carta 2: R$ %.2f\n", carta2.pibPerCapita);
            printf("----------------------------------------\n");
            
            if (carta1.pibPerCapita > carta2.pibPerCapita) {
                printf("VENCEDOR: Carta 1 (%s)\n", carta1.pais);
                printf("Diferenca: R$ %.2f\n", 
                       carta1.pibPerCapita - carta2.pibPerCapita);
            } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
                printf("VENCEDOR: Carta 2 (%s)\n", carta2.pais);
                printf("Diferenca: R$ %.2f\n", 
                       carta2.pibPerCapita - carta1.pibPerCapita);
            } else {
                printf("RESULTADO: Empate!\n");
            }
            break;
            
        case 0: // Sair
            printf("Encerrando o jogo...\n");
            break;
            
        default: // Opção inválida
            printf("ERRO: Opcao invalida!\n");
            printf("Por favor, escolha uma opcao entre 0 e 6.\n");
            break;
    }
    
    printf("========================================\n");
}

int main() {
    Carta carta1, carta2;
    int opcao;
    
    // Cadastro da Carta 1
    printf("========================================\n");
    printf("       CADASTRO DA CARTA 1\n");
    printf("========================================\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    
    printf("Codigo da Carta (ex: A01): ");
    scanf("%9s", carta1.codigo);
    
    printf("Nome do Pais: ");
    scanf(" %49[^\n]", carta1.pais);
    
    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);
    
    printf("Area (em km²): ");
    scanf("%f", &carta1.area);
    
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta1.pib);
    
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    
    calcularIndicadores(&carta1);
    
    // Cadastro da Carta 2
    printf("\n========================================\n");
    printf("       CADASTRO DA CARTA 2\n");
    printf("========================================\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    
    printf("Codigo da Carta (ex: B02): ");
    scanf("%9s", carta2.codigo);
    
    printf("Nome do Pais: ");
    scanf(" %49[^\n]", carta2.pais);
    
    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);
    
    printf("Area (em km²): ");
    scanf("%f", &carta2.area);
    
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta2.pib);
    
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    
    calcularIndicadores(&carta2);
    
    // Loop do menu interativo
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        if (opcao != 0) {
            compararCartas(carta1, carta2, opcao);
            
            // Pausa para o usuário ler o resultado
            printf("\nPressione ENTER para continuar...");
            getchar(); // Limpar buffer
            getchar(); // Aguardar ENTER
        }
    } while (opcao != 0);
    
    printf("\nObrigado por jogar Super Trunfo!\n");
    
    return 0;
}



