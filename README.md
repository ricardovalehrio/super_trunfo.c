# super_trunfo.c
Repositório da aula do Tema - Super Trunfo em c.

Implemetação da Lógica do jogo:
Para implementar a lógica de comparação entre duas cartas com base em um único atributo numérico, podemos aproveitar o código de cadastro das cartas que já foi desenvolvido e adicionar a funcionalidade de comparação. O código a seguir utiliza estruturas if e if-else para comparar um dos atributos entre as duas cartas e determinar a vencedora.

Explicação do Código:

Entrada de Dados:
O código começa recebendo os dados das duas cartas, incluindo estado, código, nome da cidade, população, área, PIB e pontos turísticos.

Cálculos:
Calcula a densidade populacional dividindo a população pela área da cidade.

Calcula o PIB per capita dividindo o PIB pela população, considerando que o PIB está em bilhões de reais.

Escolha do Atributo para Comparação:
O código compara um atributo específico entre as duas cartas. O atributo é selecionado no código usando a variável atributo. No exemplo, foi escolhido comparar a População (atributo = 1).

Dependendo do valor de atributo, o código faz a comparação entre os valores correspondentes (População, Área, PIB, PIB per capita ou Densidade Populacional).

Exibição do Resultado:
O programa exibe o resultado da comparação de acordo com o atributo selecionado, mostrando qual carta venceu ou se houve empate.

Possíveis Modificações:
Alterar o valor da variável atributo para comparar diferentes atributos, como PIB, Área, etc.
Modificar o código para permitir a escolha do atributo de comparação por parte do usuário (caso queira expandir o programa).
