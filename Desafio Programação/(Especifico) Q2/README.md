# 2. Descrever lógica para parada do robô (Específicos da categoria)

Considerando a abordagem com os sensores laterais do lado direito para a leitura dessas marcações no intuito da parada do robô e assumindo que a pista será similar a figura à baixo retirada da cartilha da categoria segue linha, onde o robô será posicionado inicialmente entre as duas marcas laterais à sua direita, proponho-se um programa com uma instrução única de decisão avaliando a quantidade de marcas à direita detectadas durante o percurso da pista.

![](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F04f57f7c-6ffd-463c-a6a6-eb22113a9503%2FWhatsApp_Image_2022-04-24_at_22.55.02.jpeg?table=block&id=9a058fe5-c64c-478a-9889-05723e5cc837&spaceId=fe56e0f2-d7ef-4de1-87ea-996fd17a4d65&width=1380&userId=cd3f3164-7205-4bb5-b4da-7d490ed618b8&cache=v2)

Abaixo apresento o fluxograma referente à lógica de parada do robô seguidor de linha, onde é utilizado alguns atributos associados as classes desenvolvidas na Q1 geral, como também alguns métodos adicionais como set_Motors que é responsável pela definição da direção de movimento a partir da velocidade do motor utilizando sinais PWM para esse controle.
![Fluxograma](https://github.com/giovannirdias/Desafio-TAMANDUATECH---Segue-Linha/blob/main/Desafio%20Programa%C3%A7%C3%A3o/(Especifico)%20Q2/fluxograma_robo_parado.png)

Além disso, apresento em anexo um [protótipo implementado em C++]() para esse método de parada do robô, cabendo ressaltar que algumas partes relacionadas a esse programa são assumidas como implementadas em outras files, como exemplo o método set_motor associado a uma possível biblioteca "motor.h". Exemplificando, esse método utilizando o arduino é estabelecido através da função digitalWrite() uma comunicação com as portados do drive de ponte H do motor e o sinal PWM.
