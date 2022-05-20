# 1. Descrever lógica para robô seguir a linha (Específicos da categoria)

Um robô seguidor de linha tem como tarefa seguir um trajeto delimitado no menor tempo possível, para isso utiliza-se como variável controlada o estado lógico do array de sensores para dimensionar o erro de trajetória, com intuito de realizar de maneira autônoma as curvas e a parada do robô. Desta forma para atingir esse grau de autonomia opta-se por utilizar a técnica PID para o ajuste das linhas no processo.

O controlador PID está relacionado a um sistema de controle em malha fechada, que será responsável pela conversão do sinal de erro em uma taxa de giro que possibilita que o robô permaneça sob a linha. Esse erro flutua em valores positivos e negativos de acordo com a posição do robô em relação à linha, assim para poder percorrer uma curva, deve-se ajustar a velocidade do conjunto de motores dependendo do sentido do movimento, por exemplo, para acelerar para à direta temos que diminuir a taxa de giro do motor associado a roda direita e aumentar a velocidade do motor associado a roda direita, assim ajustando a posição relativa para termos um sistema com erro nulo.

Abaixo é apresentado o diagrama de blocos para esse sistema, demonstrando a lógica para o robô seguir a linha a partir do bloco do controlador corrigindo o processo de velocidade e utilizando as informações dos sensores na retroalimentação desse sistema de malha fechada. 

![image](https://user-images.githubusercontent.com/99917909/169548162-84cc6089-447b-4d0a-bef4-12530ee12058.png)

Em relação ao algoritmo do segue-linha, será utilizado a leitura dos sensores (bits representando o status de cada sensor frontal) e o sinal de erro na função vTaskCalcularPID para determinar o ajuste necessário da velocidade para anulamento do erro. Assim, aplica-se esse ajuste sob uma velocidade de referência, que no caso para facilitar a sintonização do controlador PID foi definido como k = 80% da velocidade máxima


- em qualquer cruzamento, se existe um caminho para a frente, então o robô deve tomar esse caminho e se ele não existe, então o robô é livre para escolher qualquer caminho.


Vale a pena notar que quanto maior a velocidade de uma roda em relação a outra, menor é o raio da curva realizada. Em outras palavras, se é desejado realizar uma curva fechada, a velocidade de uma roda deve ser bem maior em relação a outra. 

A constante deve-se sintotiar o PID utilizando uma velociade meno que a velocidade máxima, pois está dificulta o processo.

vel_Motor_esq = k(203) - ajuste;
vel_Motor_dir = k(203) + ajuste;

Par o ajuste efetivo da velocidade dos motores é utilizado uma função adicional, o set_motor(int, int), para alterar o nível de tensão com PWM do motor para provocar esse alteração de valor ou até sentido de rotação. Cabe ressaltar que o intervalor de valores de PWM do motor é [-255, 255], não podendo desviar desses valores.
Valores negativos indicam a mudança de direção de rotação.

![image](https://user-images.githubusercontent.com/99917909/169548467-2b137ac5-01c1-4b97-90d2-ea73e96fe028.png)

[prototipo implementado em C++](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Especifico)%20Q1/motor_speed.cpp)
