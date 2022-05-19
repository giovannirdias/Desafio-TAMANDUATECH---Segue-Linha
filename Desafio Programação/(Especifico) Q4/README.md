# [Opcional] 4. Descrever algoritmo para leitura de um botão (Específicos da categoria) 

**Considerar a leitura de um sinal enviado por um botão para o desenvolvimento de um algoritmo que conte a quantidade de vezes que ele foi pressionado**

A figura abaixo é um fluxograma apresentando um possível algoritmo para leitura do sinal enviado pelo botão, seguindo as condições estabelecidas na questão. Além disso, é apresentado um [código utilizando o Arduino](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Especifico)%20Q4/push_button.ino) para verificar a validade desse algoritmo proposto considerando a necessidade de aplicação do efeito debouncing, que é explicado também nessa file.

![](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Especifico)%20Q4/fluxograma_push_button.png)

O efeito bocuncing em botões é um fenômeno de trepidação relacionado ao tempo necessário para estabilização da posição de repouso dos condutores associados ao botão no estado de contato fechado e aberto. Assim, o micropocessador utilizado para ler o sinal gerado por esse dispositivo na mudança de estado também considera essas oscilações na leitura, podendo causar problemas de execução em ambientes críticos.
Para contornar esse problema pode-se utilizar uma abordagem voltada ao hardware, utilizando algum elemento de armazenamento, como capacitor, para armazenar a energia de oscilação e implicar em um atraso no sinal gerado pelo botão, ou através de alguma função de atraso no programa de leitura e contagem do botão, como a função delay() no Arduino que pausa a ativadade de processamento.

![Efeito Bouncing](https://user-images.githubusercontent.com/99917909/169338256-de1e7d07-d682-4c57-b211-7ff2c3b174ac.png)

### Anexos
1. Circuito simulado no TinkerCAD.
https://www.tinkercad.com/things/eN5wyxXS6Yh?sharecode=1C7ajNLiOkRoonQ9IOmvWdGgCIzXX1T3PhLH-ZyddD8
