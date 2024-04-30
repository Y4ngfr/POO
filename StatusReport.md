# StatusReport

## 22/09/2024 - 29/09/2024 
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

Algumas partes do código estão com tipagens incorretas como o ID que não é uma string e é inserido manualmente na criação do pedido. Além disso, outras variáveis com tipos que **inviabilizam o tratamento de dados**, por exemplo, as coordenadas geográficas, que são tratadas com string e não possuem métodos de conversão. Então, a equipe terá que dedicar certo tempo para adaptar os métodos e atributos necessários para o 
funcionamento correto da aplicação.

Além disso, o CSV fornecido dificultou a percepção do funcionamento do código, pois, além de estar mal formatado, a maioria dos dados eram inválidos. Isso tornou o processo de depuração mais complexo, pois, dado que havia muitos erros e o tempo de requisição pode ficar razoavelmente grande, tornou-se complicado avaliar **se os erros eram referentes a um erro de código ou a uma entrada inválida**.

## Adaptação do Makefile
Além da pequena curva de aprendizado no funcionamento de um arquivo Makefile. A equipe notou que é necessário implementar parametrização do caminho de saída do arquivo binário de execução. E além disso, passar a compilar os headers, que **não estavam sendo compilados**. Dado que esse processo é bem manual e demanda certo tempo, essa atividade ainda não pôde ser realizada completamente.  

- 
</details>