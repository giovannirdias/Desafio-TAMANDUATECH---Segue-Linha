# 2. Otimização (Geral)

**Desenvolva o método com os argumentos buscando em paralelo o funcionamento básico do
PID.**

Considerou-se no desenvolvimento do método com os argumentos para o cálculo dos ajustes PID, a utilização dos atributos pertencentes a classe valuesPID.
  
Assim, para o funcionamento básico do controlador PID deve-se determinar a função erro, diferença entre o setPoint, valor relacionado com a metade do alcance do sensores frontais, com o valor médio dos sensores (input), além das componentes de ação P que é proporcional ao erro, integrativa (I) que é proporcional ao erro acumulado, i.e a magnitude (erro) e a duração do erro (output), e a parte derivativa (D) que é proporcional à velocidade de variação do erro.

Logo, neste repositório é apresentado a implementação de um [programa prototipo em C++](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Geral)%20Q2/PID.cpp), utilizando os ponteiros para os cálculos dos controladores para o ajuste da velocidade dos motores.
