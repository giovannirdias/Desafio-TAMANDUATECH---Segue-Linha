#include <iostream>
#include "PID.h"

int base_speed = 204;
int min_speed = -255;
int max_speed = 255;

void new_motor_speed(){
    int left_motor_speed = base_speed - PID::getAjuste();
    int right_motor_speed = base_speed + PID::getAjuste();

    // Verificar se o motor esta dentro dos valores limites
    if (left_motor_speed > max_speed){
        left_motor_speed = max_speed;
    }
    if (left_motor_speed < min_speed){
        left_motor_speed = min_speed;
    }
    if (right_motor_speed > max_speed){
        left_motor_speed = max_speed;
    }
    if (right_motor_speed < min_speed){
        left_motor_speed = min_speed;
    }

    // Funcao para alterar a velocidade do motor atraves dos sinais PWM
    set_motor_speed(right_motor_speed, left_motor_speed);
}
