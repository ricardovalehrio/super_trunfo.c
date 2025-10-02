Super Trunfo Países em C
Projeto de Programação em C - Universidade Estácio
Bem-vindo ao repositório do projeto Super Trunfo Países, desenvolvido como parte da disciplina de Algoritmos e Programação Estruturada do curso de Engenharia na Universidade Estácio.

Sobre o Projeto
Este projeto é uma versão console do clássico jogo Super Trunfo, adaptada para comparar cartas de países utilizando diversos atributos demográficos e econômicos. O objetivo é incentivar o aprendizado de estruturas de decisão, manipulação de dados via struct, menus interativos com switch, tratamento de entradas e boas práticas em C.

Funcionalidades
Cadastro de cartas: Cada carta representa um país, com atributos como população, área, PIB, pontos turísticos, densidade demográfica e PIB per capita.

Menu interativo dinâmico: O usuário pode escolher DOIS atributos distintos para comparação das cartas.

Lógica de comparação: Regra geral: o maior valor vence. Exceção: em densidade demográfica, vence o menor valor.

Cálculo da soma dos atributos escolhidos: Ao final, vence a carta com a maior soma dos dois atributos.

Tratamento de empates: Identificação e exibição clara de empates.

Interface amigável e robusta: Menus, mensagens e instruções claras, validação de entradas, uso do operador ternário para decisões elegantes.

Como Executar
Clone o repositório:

bash
git clone https://github.com/ricardovalehrio/super_trunfo.c.git
Compile o código (utilize GCC ou outra ferramenta compatível):

bash
gcc -o super_trunfo super_trunfo.c
Execute o programa:

bash
./super_trunfo
Estrutura do Código
struct Carta: Organiza os atributos das cartas.

Funções para cálculo de indicadores, exibição de menus, comparação de cartas e tratamento de resultados.

Uso extensivo de switch, if-else, laços e operador ternário para garantir clareza e flexibilidade.

Autor
Ricardo Valério
Estudante de Ciências da Computação, Universidade Estácio
Contato: ricardovaleriosilvaoliveira@gmail.com

Aviso
Este projeto é exclusivamente didático, desenvolvido para fins de aprendizagem. Contribuições, sugestões e melhorias são bem-vindas!

Licença
MIT (para fins acadêmicos)

Se divirta testando e aprendendo programação C com o Super Trunfo Países! 👨‍💻🌍