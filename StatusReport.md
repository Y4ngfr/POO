# StatusReport

# 22/04/2024 - 29/04/2024 
<details>

Durante essa sprint a equipe se concentrou em duas atividades principais:
- Adaptação do código para realizar as tarefas solicitadas
- Adicionar uma nova classe para orquestrar entrada e saida de dados

## O que foi feito?
As atividades dessa sprint ainda não foram completamente realizadas dado que essa sprint necessita de um tempo maior de dedicação e de tempo por conta da curva de aprendizado para a **compreensão do código** e **adaptações necessárias**. Entretanto, durante essa semana, algumas alterações foram realizadas no código e que valem serem destacadas:

O projeto possui alguns padrões de projeto que foram levados em conta e preservados, visando manter a identidade do projeto e que, consequentemente, foram mantidos:
- Variáveis e mensagens de saída em português;
- Modelo de declaração de variáveis no formato camelCase, padrão da linguagem;

## CSVWriter
CSVWriter é uma ferramenta criada pra leitura de CSVs bem formatados com o proposito de alimentar os objetos que armazenam os dados da empresa fictícia. Seu funcionamento é bem simples e pode ser executado através dos comandos:

```cpp
CSVWriter::alimentarComCSV(string path, Logistica* logistica, uint64_t UINT64_MAX)
```

Essa classe funciona de acordo com o que a mesma propõem, ela pode ler os valores do CSV e exibi-los na tela ou inseri-los diretamente na base da dados do sistema.

## Adaptação do sistema para o funcionamento com coordenadas
Foi-se utilizado o código aberto de autoria de [@diogo2m](https://github.com/diogo2m) para conversão de endereços para coordenadas geográficas. Apesar dessa ter sido uma etapa simples no sentido que a equipe utilizou de um sistema já criado, a etapa de **adaptar as classes** já existentes para que pudesse alocar veículos de acordo com a mesma, foi desafiadora.

O sistema anterior realizava a atribuição de carga levando em conta **apenas o peso do pedido**, e permitindo apenas **um pedido por veículo**. Dessa forma a equipe teve que alterar o código original para que o mesmo começasse a levar em conta **fatores de capacidade** (carregar mais de um pedido) e levar em conta as **coordenadas geográficas** para a atribuição de tarefas.

Algumas partes do código estão com tipagens incorretas como o ID que não é uma string e é inserido manualmente na criação do pedido. Além disso, outras variáveis com tipos que **inviabilizam o tratamento de dados**, por exemplo, as coordenadas geográficas, que são tratadas com string e não possuem métodos de conversão. Então, a equipe terá que dedicar certo tempo para adaptar os métodos e atributos necessários para o funcionamento correto da aplicação.

Além disso, o CSV fornecido dificultou a percepção do funcionamento do código, pois, além de estar mal formatado, a maioria dos dados eram inválidos. Isso tornou o processo de depuração mais complexo, pois, dado que havia muitos erros e o tempo de requisição pode ficar razoavelmente grande, tornou-se complicado avaliar **se os erros eram referentes a um erro de código ou a uma entrada inválida**.

## Adaptação do Makefile
Além da pequena curva de aprendizado no funcionamento de um arquivo Makefile. A equipe notou que é necessário implementar parametrização do caminho de saída do arquivo binário de execução. E além disso, passar a compilar os headers, que **não estavam sendo compilados**. Dado que esse processo é bem manual e demanda certo tempo, essa atividade ainda não pôde ser realizada completamente.  

Próximos passos:
- Refatorar os headers.
- Refatorar o código, adaptando para fazer o que foi solicitado.

</details>



# 29/04/2024 - 04/06/2024
<details>

Durante essa sprint a equipe se concentrou em duas atividades principais:
- Finalização das tarefas solicitadas.
- Aprimorar elementos do código.
- Aprimorar a experiência do usuário leigo.

## Primeira versão estável
Como comentado na sprint anterior, a equipe, por restrição de tempo, não pôde adaptar completamente o código para cumprir com as demandas propostas. Então, durante essas semanas a equipe teve o foco principal em criar uma primeira versão estável da aplicação. 

Dessa forma, a aplicação passou a ser alterada, agora, contando com: **compilação dos cabeçalhos** das classes; criação do atributo `coordenadas` e seus respectivos métodos get e set; **atualização das coordenadas** do pedido de acordo com a localização; **lidando com limitações de capacidade** durante a atribuição de carga. 

## Aprimorando AlimentadorBancoDados
A equipe buscou realizar refatoração no código da classe AlimentadorBancoDados (antigo CSVWriter). Foram realizados alguns **tratamentos de erros** quando o CSV não está bem formatado ou possui valores inválidos. Além disso, considerando que o sistema AlimentadorBancoDados está frequentemente associado a um grande volume de requisições e inserções nas classes de armazenamento do sistema (por exemplo, ListaVeiculos, Logistica), a equipe optou por implementar **processamento paralelo** para a criação e adição de pedidos. Assim, reduzindo o tempo de espera e aumentando a eficiência na utilização dos recursos computacionais disponíveis. 

## Mensagens semânticas e experiência do usuário
Com propósito de melhorar a experiência do usuário no sistema, a equipe criou a classe Sistema. Essa classe, em linhas gerais, gera interfaces para utilização das funcionaliades do sistema. A mesma aceita tanto entradas do próprio sistema (e.g. ponteiro para objetos ou ID) como entradas via console em tempo real e com atualizações contantes do progresso da execução.  

Além disso, a equipe refatorou o código adicionando **mensagens de saída semânticas**, com a biblioteca stdout e stderr. Essa alteração é interessante pois além de aumentar a legibilidade e semântica do código, também permite que o usuário possa redirecionar as mensagens de log para um arquivo a parte, possibilitando a filtragem de mensagens baseada nos interesses do usuário. 

Próximos passos:
- Adaptação dos nomes das classe seguindo o pad~rao convencional (nome da classe é o nome do arquivo)
- Regularizar padrão de projeto, const e comentarios

</details>