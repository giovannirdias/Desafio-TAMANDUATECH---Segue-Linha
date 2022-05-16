# (Geral) 1. Organização de dados

**Como você organizaria esses dados, pensando em formas de programação estruturada ou orientada a objetos?**

Para a organização desses dados fornecidos na árvore de dados do robô seguidor de linha optou-se por utilizar o paradigma de programação orientada a objetos, pois teremos uma passagem por referência implicando em maior rapidez devido a não duplicação dos dados da memória, como também uma abordagem baseada em classes e heranças para agrupar os métodos e atributos de cada nó não-folha da árvore.

Assim, teríamos 7 classes onde a classe pai será a classe *valuesCar*, que estabelece relações específicas com outras classes já que algumas delas possuem conexões de herança, associação e implementação. Especificamente as classes *valuesSpeed* e *valuesPID*  que possuem relação de herança, já que seus atributos depende do valor associado ao atributo *state* pertencente a classe pai.

Em relação a parte da árvore referente ao valores deve-se ressaltar que os valores do nós folha do motor esquerdo e direto serão declarados como instâncias da classe *valuesSpeed* (objetos) e os nós folha entrada e saída do PID serão utilizados em métodos adicionais, especificamente no cálculo do parâmetros PID para estado específico do robô.

Em anexo é apresentado um [diagrama UML](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Geral)%20Q1/UML.pdf) para demonstrar a estrutura das classes, como também um protótipo para declaração desse [programa implementado em C++](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Geral)%20Q1/prototipo.cpp), onde podemos utilizar os arquivos de cabeçalho (*files .h*) para fornecer informações em arquivos gerais de execução, facilitando a organização do projeto.
