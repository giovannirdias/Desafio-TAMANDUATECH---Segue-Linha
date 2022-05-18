# 2. Otimização (Geral)

**Desenvolva o método com os argumentos buscando em paralelo o funcionamento básico do
PID.**

Considerou-se no desenvolvimento do método com os argumentos para o cálculo dos ajustes PID, a utilização dos atributos pertencentes a classe valuesPID. <br />
Assim, para o funcionamento básico do controlador PID deve-se determinar a função erro (diferença entre a velocidade ideal dos motores (setPoint) com o valor médio dos sensores (input)) e as componentes de ação P que é proporcional ao erro, integrativa (I) que é proporcional ao erro acumulado, i.e a magnitude (erro) e a duração do erro (output), e derivativa (D) que é proporcional à velocidade de variação do erro. <br />
Logo, neste repositório é apresentado a implementação do [programa em C++](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Geral)%20Q2/PID.cpp), utilizando os ponteiros para os cálculos dos controladores para o ajuste da velocidade dos motores. <br />
