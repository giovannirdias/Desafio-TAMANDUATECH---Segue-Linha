# 3. Leitura de um encoder  (Específicos da categoria)

Através do acoplamento do encoder em um sistema motor-roda podemos determinar a distância e a velocidade do motor a partir dos pulsos elétricos enviados pelo encoder para um microcontrolador, responsável pela contagem dos pulsos que serão utilizados em fórmulas matemáticas para determinação da distância (x) em metros e a velocidade média  do motor (v) em RPM.

Abaixo apresenta-se as fórmulas para cálculo desse parâmetros:

![](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Especifico)%20Q3/math_formulas.png)

### **Observações** 
PPR (Pulsos por Revolução): equivale a resolução do encoder, ou seja, a quantidade de quadrantes do disco, sendo obtida a partir da relação 360°/(menor incremento de medição).
R: Raio da roda.
N_T: Quantidade de pulsos contados.
N_R: Número de pulsos por revolução.

Para determinar esses parâmetros deve-se obter as informações sobre o enconder. Assim, sabe-se que sua funcionalidade é transformar posição em sinal elétrico digital e para isso ocorrer temos três sinais de saída digital (A, B e O) com valores de alta(1) e baixa(0). Através desse sinais obtém-se o ângulo de rotação, o sentido de rotação e o início e fim de um volta, além de descrever a partir das ondas quadradas A ou B o número de pulsos altos do encoder (PPR).

Em relação ao cálculo de distância percorrido, podemos utilizar as informações obtidas pelo encoder em relação ao comprimento das reta e o raio de curvatura na pista através da contagem de marcações à esquerda da pista, obtendo-se os parâmetos N_T e N_R.

Assim, as figuras abaixo mostram o comportamento dessa ondas relacionando-as com o sentido de rotação do sistema motor-roda. O sinal O indica a origem do encoder, sendo um excelente parâmetro para detecção do números de voltas completas desse sistema, já o sinal A fornece os pulsos no processo de rotação do encoder, enquanto o sinal B é o sinal A defasado por mais ou menos 90°, indicando assim o sentido de rotação.

![](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Especifico)%20Q3/CW_motor.jpg)

**"Pseudo-código":** detectar as bordas de sinal digital A, verificando o estado do sinal B para definir o sentido de rotação.

![](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Especifico)%20Q3/CCW_motor.jpg)

**"Pseudo-código":** detectar as bordas de sinal digital B, verificando o estado do sinal A para definir o sentido de rotação.
