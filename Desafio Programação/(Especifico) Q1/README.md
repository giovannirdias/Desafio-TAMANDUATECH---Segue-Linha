# 1. Descrever lógica para robô seguir a linha (Específicos da categoria)

Um robô seguidor de linha tem como tarefa seguir um trajeto delimitado no menor tempo possível. Para isso ocorrer, utiliza-se como variável controlada o estado lógico do array de sensores para dimensionar o erro de trajetória, com intuito de realizar de maneira autônoma as curvas e a parada do robô. Desta forma, para atingir esse grau de autonomia opta-se por utilizar a técnica PID para o ajuste das linhas no processo.

O controlador PID está relacionado a um sistema de controle em malha fechada que será responsável pela conversão do sinal de erro em uma taxa de giro que possibilita o robô permanecer sob a linha. Esse erro flutua em valores positivos e negativos de acordo com a posição do robô em relação à linha, assim para poder percorrer uma curva deve-se ajustar a velocidade do conjunto de motores dependendo do sentido do movimento, por exemplo, para acelerar para à direta temos que diminuir a taxa de giro do motor associado a roda direita e aumentar a velocidade do motor associado a roda esquerda, assim com o objetivo de ajustar a posição relativa para termos um sistema com erro nulo.

Abaixo é apresentado o diagrama de blocos para esse sistema, demonstrando a lógica para o robô seguir a linha a partir do bloco do controlador corrigindo o processo de velocidade e utilizando as informações dos sensores na retroalimentação desse sistema de malha fechada. 

![image](https://user-images.githubusercontent.com/99917909/169548162-84cc6089-447b-4d0a-bef4-12530ee12058.png)

Em relação ao algoritmo do segue-linha, será utilizado a leitura dos sensores (bits representando o status de cada sensor frontal) e o sinal de erro na função vTaskCalcularPID para determinar o ajuste necessário da velocidade para anulamento do erro. Assim, aplica-se esse ajuste sob uma velocidade de referência, que no caso para facilitar a sintonização do controlador PID foi definido como k = 80% da velocidade máxima e para efetiva aplicação sob o motores é utilizado a função adicional set_motor(int, int) para alterar o nível de tensão com PWM do motor para provocar esse alteração de valor ou até sentido de rotação, cabendo ressaltar que o intervalo de valores de PWM do motor é [-255, 255], não podendo desviar desses valores.

vel_Motor_esq = k - ajuste;

vel_Motor_dir = k + ajuste;

Abaixo é apresentado o fluxograma da utilização da leitura dos sensores para ajuste das velocidade dos motores, onde utiliza-se atributos e métodos associados a classes como PID.h e motor.h:

![image](https://user-images.githubusercontent.com/99917909/169548467-2b137ac5-01c1-4b97-90d2-ea73e96fe028.png)

Alguns casos de pista deve-se estabelecer regras de conduta do robô como:
1. Cruzamentoo: se existe um caminho para a frente, o robô deve tomar esse caminho.
2. Retas: o robô deve utilizar a velocidade máxima possível em ambos os motores.
3. Curvas: o raio dessa curvas percorridas depende da diferença da velocidade dos motores, assim em curvas atenuadas deve-se ter uma diferença grande entre os motores.

Além disso, apresenta-se um [prototipo implementado em C++](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Especifico)%20Q1/motor_speed.cpp) para a lógica do robô seguidor de linha, onde a função para mandar os comandos PWM para motor pode utilizar algo como analogWrite() do Arduino para o envio desse sinal.
