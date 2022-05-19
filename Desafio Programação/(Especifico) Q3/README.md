# 3. Leitura de um encoder  (Específicos da categoria)

Através do acoplamento do encoder em um sistema motor-roda podemos determinar a distância e a velocidade do motor a partir dos pulsos elétricos enviados pelo encoder para um microcontrolador, responsável pela contagem dos pulsos que serão utilizados em fórmulas matemáticas para determinação da distância (x) em metros e a velocidade média  do motor (v) em RPM.

Abaixo apresenta-se as fórmulas para cálculo desse parâmetros:
$v = \frac{2 pi R}{PPR} \cdot f \cdot 60 [RPM]$
