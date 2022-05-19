/* Comentarios sobre o codigo abaixo:
-> Bibliotecas:
   - motor.h: Contem a classe do motor onde ha os atributos 
    de velocidade e metodos de controle do sentido de            rotacao.
   - robot.h: Contem a classe valuesCar com estado do 
    seguidor de linha.
   - interface.h: Contem atributos e metodos associados a 
    ferramentas auxiliares ao percurso da pista, como o 
    botao de inicializacao da volta.
   - sensors.h: Contem as classes valuesMarks e valuesSLat 
    relacionadas aos sensores frontais e laterais         
    responsáveis pela orientacao correta do modelo durante a 
    volta.
*/

#include <iostream>
#include "motor.h"
#include "robot.h"
#include "interface.h"
#include "sensors.h"

int main() {
    while(true)
    {
        // Executa os comandos quando botao eh pressinado
        if (interface::read_button == 1){
            // Inicializa os objetos associados aos sensores
            valuesMarks latMarks(0, 0);
            valuesSLat slat;
            // Leitura das marcas laterais ate a condicao de parada
            while(latMarks.getMarks_right != 2){
                // Metodo integrado a classe permitindo a contagem das marcas
                slat.read_valuesSensor();
            }
            // Instrucao para parada
            valuesCar::setState(0);
            motor::set_Motors(0, 0);
            return 0;
        }
    }
}