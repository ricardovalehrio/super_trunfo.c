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

// Função para calcular indicadores derivados
void calcularIndicadores(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade = (float)carta->populacao / carta->area;
        carta->pibPerCapita = (carta->pib * 1e9f) / carta->populacao;
    } else {
        carta->densidade = 0;
        carta->pibPerCapita = 0;
    }
}

// Função para exibir o menu completo de atributos
void exibirMenuCompleto() {
    printf("\n========================================\n");
    printf("    ESCOLHA O ATRIBUTO PARA COMPARACAO\n");
    printf("========================================\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("========================================\n");
    printf("Opcao: ");
}

// Função para exibir menu dinâmico (excluindo atributo já escolhido)
void exibirMenuDinamico(int atributoExcluido) {
    printf("\n========================================\n");
    printf("   ESCOLHA O SEGUNDO ATRIBUTO\n");
    printf("========================================\n");
    
    // Exibe apenas as opções não escolhidas anteriormente
    if (atributoExcluido != 1) printf("1 - Populacao\n");
    if (atributoExcluido != 2) printf("2 - Area\n");
    if (atributoExcluido != 3) printf("3 - PIB\n");
    if (atributoExcluido != 4) printf("4 - Numero de Pontos Turisticos\n");
    if (atributoExcluido != 5) printf("5 - Densidade Demografica\n");
    if (atributoExcluido != 6) printf("6 - PIB per Capita\n");
    
    printf("========================================\n");
    printf("Opcao: ");
}

// Função para obter o nome do atributo
const char* obterNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

// Função para obter o valor de um atributo de uma carta
double obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (double)carta.populacao;
        case 2: return (double)carta.area;
        case 3: return (double)carta.pib;
        case 4: return (double)carta.pontosTuristicos;
        case 5: return (double)carta.densidade;
        case 6: return (double)carta.pibPerCapita;
        default: return 0.0;
    }
}

// Função para formatar e exibir o valor do atributo
void exibirValorAtributo(int atributo, double valor) {
    switch (atributo) {
        case 1:
            printf("%.0f habitantes", valor);
            break;
        case 2:
            printf("%.2f km²", valor);
            break;
        case 3:
            printf("R$ %.2f bilhoes", valor);
            break;
        case 4:
            printf("%.0f pontos turisticos", valor);
            break;
        case 5:
            printf("%.2f hab/km²", valor);
            break;
        case 6:
            printf("R$ %.2f", valor);
            break;
    }
}

// Função para comparar dois atributos e exibir resultado detalhado
void compararDoisAtributos(Carta carta1, Carta carta2, int atrib1, int atrib2) {
    // Obter valores dos atributos para ambas as cartas
    double valor1_atrib1 = obterValorAtributo(carta1, atrib1);
    double valor1_atrib2 = obterValorAtributo(carta1, atrib2);
    double valor2_atrib1 = obterValorAtributo(carta2, atrib1);
    double valor2_atrib2 = obterValorAtributo(carta2, atrib2);
    
    // Cabeçalho do resultado
    printf("\n========================================\n");
    printf("     RESULTADO DA COMPARACAO AVANCADA\n");
    printf("========================================\n");
    printf("Carta 1: %s (%c%s)\n", carta1.pais, carta1.estado, carta1.codigo);
    printf("Carta 2: %s (%c%s)\n", carta2.pais, carta2.estado, carta2.codigo);
    printf("========================================\n\n");
    
    // Exibir primeiro atributo
    printf("ATRIBUTO 1: %s\n", obterNomeAtributo(atrib1));
    printf("----------------------------------------\n");
    printf("Carta 1 - %s: ", carta1.pais);
    exibirValorAtributo(atrib1, valor1_atrib1);
    printf("\nCarta 2 - %s: ", carta2.pais);
    exibirValorAtributo(atrib1, valor2_atrib1);
    printf("\n");
    
    // Comparação do primeiro atributo (regra especial para densidade)
    int pontosCarta1_atrib1 = 0, pontosCarta2_atrib1 = 0;
    
    if (atrib1 == 5) { // Densidade: menor vence
        pontosCarta1_atrib1 = (valor1_atrib1 < valor2_atrib1) ? 1 : 
                              (valor1_atrib1 > valor2_atrib1) ? 0 : 0;
        pontosCarta2_atrib1 = (valor2_atrib1 < valor1_atrib1) ? 1 : 
                              (valor2_atrib1 > valor1_atrib1) ? 0 : 0;
        printf("Vencedor (menor valor): %s\n", 
               (valor1_atrib1 < valor2_atrib1) ? carta1.pais :
               (valor2_atrib1 < valor1_atrib1) ? carta2.pais : "Empate");
    } else { // Demais atributos: maior vence
        pontosCarta1_atrib1 = (valor1_atrib1 > valor2_atrib1) ? 1 : 
                              (valor1_atrib1 < valor2_atrib1) ? 0 : 0;
        pontosCarta2_atrib1 = (valor2_atrib1 > valor1_atrib1) ? 1 : 
                              (valor2_atrib1 < valor1_atrib1) ? 0 : 0;
        printf("Vencedor (maior valor): %s\n", 
               (valor1_atrib1 > valor2_atrib1) ? carta1.pais :
               (valor2_atrib1 > valor1_atrib1) ? carta2.pais : "Empate");
    }
    
    // Exibir segundo atributo
    printf("\n\nATRIBUTO 2: %s\n", obterNomeAtributo(atrib2));
    printf("----------------------------------------\n");
    printf("Carta 1 - %s: ", carta1.pais);
    exibirValorAtributo(atrib2, valor1_atrib2);
    printf("\nCarta 2 - %s: ", carta2.pais);
    exibirValorAtributo(atrib2, valor2_atrib2);
    printf("\n");
    
    // Comparação do segundo atributo (regra especial para densidade)
    int pontosCarta1_atrib2 = 0, pontosCarta2_atrib2 = 0;
    
    if (atrib2 == 5) { // Densidade: menor vence
        pontosCarta1_atrib2 = (valor1_atrib2 < valor2_atrib2) ? 1 : 
                              (valor1_atrib2 > valor2_atrib2) ? 0 : 0;
        pontosCarta2_atrib2 = (valor2_atrib2 < valor1_atrib2) ? 1 : 
                              (valor2_atrib2 > valor1_atrib2) ? 0 : 0;
        printf("Vencedor (menor valor): %s\n", 
               (valor1_atrib2 < valor2_atrib2) ? carta1.pais :
               (valor2_atrib2 < valor1_atrib2) ? carta2.pais : "Empate");
    } else { // Demais atributos: maior vence
        pontosCarta1_atrib2 = (valor1_atrib2 > valor2_atrib2) ? 1 : 
                              (valor1_atrib2 < valor2_atrib2) ? 0 : 0;
        pontosCarta2_atrib2 = (valor2_atrib2 > valor1_atrib2) ? 1 : 
                              (valor2_atrib2 < valor1_atrib2) ? 0 : 0;
        printf("Vencedor (maior valor): %s\n", 
               (valor1_atrib2 > valor2_atrib2) ? carta1.pais :
               (valor2_atrib2 > valor1_atrib2) ? carta2.pais : "Empate");
    }
    
    // Cálculo da soma dos atributos
    double somaCarta1 = valor1_atrib1 + valor1_atrib2;
    double somaCarta2 = valor2_atrib1 + valor2_atrib2;
    
    // Cálculo de pontos totais
    int pontosTotaisCarta1 = pontosCarta1_atrib1 + pontosCarta1_atrib2;
    int pontosTotaisCarta2 = pontosCarta2_atrib1 + pontosCarta2_atrib2;
    
    // Exibir resultado final
    printf("\n\n========================================\n");
    printf("         RESULTADO FINAL\n");
    printf("========================================\n");
    printf("Soma dos Valores:\n");
    printf("Carta 1 - %s: %.2f\n", carta1.pais, somaCarta1);
    printf("Carta 2 - %s: %.2f\n", carta2.pais, somaCarta2);
    printf("----------------------------------------\n");
    printf("Pontos por Vitoria:\n");
    printf("Carta 1 - %s: %d pontos\n", carta1.pais, pontosTotaisCarta1);
    printf("Carta 2 - %s: %d pontos\n", carta2.pais, pontosTotaisCarta2);
    printf("----------------------------------------\n");
    
    // Determinar vencedor final usando operador ternário
    const char* vencedorFinal = (somaCarta1 > somaCarta2) ? carta1.pais :
                                 (somaCarta2 > somaCarta1) ? carta2.pais : 
                                 "Empate";
    
    // Exibir vencedor
    if (somaCarta1 == somaCarta2) {
        printf("\n*** RESULTADO: EMPATE! ***\n");
        printf("As duas cartas possuem a mesma soma!\n");
    } else {
        printf("\n*** VENCEDOR: %s ***\n", vencedorFinal);
        printf("Diferenca na soma: %.2f\n", 
               (somaCarta1 > somaCarta2) ? (somaCarta1 - somaCarta2) : 
                                            (somaCarta2 - somaCarta1));
    }
    
    printf("========================================\n");
}

int main() {
    Carta carta1, carta2;
    int atributo1, atributo2;
    int continuar;
    
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
    
    // Loop principal do jogo
    do {
        // Escolha do primeiro atributo
        do {
            exibirMenuCompleto();
            scanf("%d", &atributo1);
            
            // Validação usando switch com default
            switch (atributo1) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    printf("\nPrimeiro atributo selecionado: %s\n", 
                           obterNomeAtributo(atributo1));
                    break;
                default:
                    printf("\nERRO: Opcao invalida! Escolha entre 1 e 6.\n");
                    atributo1 = -1; // Marca como inválido para repetir o loop
                    break;
            }
        } while (atributo1 < 1 || atributo1 > 6);
        
        // Escolha do segundo atributo (menu dinâmico)
        do {
            exibirMenuDinamico(atributo1);
            scanf("%d", &atributo2);
            
            // Validação: não pode ser igual ao primeiro
            if (atributo2 == atributo1) {
                printf("\nERRO: Voce ja escolheu este atributo!\n");
                printf("Por favor, escolha um atributo diferente.\n");
                continue;
            }
            
            // Validação usando switch com default
            switch (atributo2) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    printf("\nSegundo atributo selecionado: %s\n", 
                           obterNomeAtributo(atributo2));
                    break;
                default:
                    printf("\nERRO: Opcao invalida! Escolha um atributo valido.\n");
                    atributo2 = -1; // Marca como inválido para repetir o loop
                    break;
            }
        } while (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1);
        
        // Realizar a comparação com os dois atributos escolhidos
        compararDoisAtributos(carta1, carta2, atributo1, atributo2);
        
        // Perguntar se deseja continuar
        printf("\nDeseja fazer outra comparacao?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        printf("Opcao: ");
        scanf("%d", &continuar);
        
    } while (continuar == 1);
    
    printf("\n========================================\n");
    printf("   Obrigado por jogar Super Trunfo!\n");
    printf("========================================\n");
    
    return 0;
}
// Fim do código



