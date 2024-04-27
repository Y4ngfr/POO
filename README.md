# POO
Esse projeto visa realizar o gerenciamento de entregas de uma transportadora, até então, o sistema é responsável por gerenciar os veículos disponíveis e atribuir os pedidos para cada veículo de acordo com sua proximidade.

## Como compilar?
Após adaptar o arquivo `main.cpp` conforme sua necessidade, execute o comando `make` para compilar o código. A saída executável padrão se chama `sistema.out`, mas você pode alterar o caminho usando o seguinte comando:
```bash
make OUTPUT=sistema.out
```

## Estruturação do código
Cada pasta contém o arquivo de cabeçalho e implementação da classe. Por exemplo: na pasta Carros estão os arquivos Carros.h e Carros.cpp que definem a classe Carro.

## Avisos para usuários
- Certifique-se de ver os arquivos de cabeçalho de cada uma das classes para entender o seu propósito e funcionamento.
- Todos os métodos que não são Getters e Setters estão devidamente documentados, assim como atributos que podem não estar facilmente compreensíveis.

## Avisos para colaboradores
- A equipe busca seguir as boas práticas de programação, incluindo declaração de variáveis com nomenclatura autoexplicativa e comentários, facilitando a leitura de códigos de maior complexidade.
- Esse projeto segue a convenção da linguagem C++ e utiliza o padrão camelCase.
- As variáveis e funções estão escritas todas em português, assim como a documentação.
