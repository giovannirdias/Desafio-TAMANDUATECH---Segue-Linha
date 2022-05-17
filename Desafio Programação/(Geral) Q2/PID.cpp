#include <iostream>
#include <vector>

using namespace std;

class valuesPID
{
    public:
        float setPoint, prevError, I, Kp, Ki, Kd;
        void setPID(float, float, float, vector<float>);
        void vTaskCalcularPID(float *, float *);
};

void valuesPID::setPID(float point, float prev, float I, vector<float> params){
    this->setPoint = point;
    this->prevError = prev;
    this->I = I;
    this->Kp = params[0];
    this->Ki = params[1];
    this->Kd = params[2];
}

void valuesPID::vTaskCalcularPID(float *input, float *output){
    float error = this->setPoint - *input;
    printf("Error: %.3f\n", error);
    float P = error * this->Kp;
    printf("Proporcional: %.3f\n", P);
    this->I += error*(*output)*this->Ki;
    printf("Integrativo: %.3f\n", this->I);
    float D = (error - this->prevError)/(*output);
    printf("Derivativo: %.3f\n", D);
    float controller = P + this->I + D;
    printf("PID controller: %.3f\n", controller);
    printf("Erro anterior: %.3f\n", this->prevError);
    this->prevError = error;
    printf("Erro anterior: %.3f\n", this->prevError);
}

class valuesCar
{
    // Atributos
    int8_t state;    // 0: parado, 1: linha e 2: curva
    uint32_t lastUpdate;
    public:
        void setCar(int8_t, uint32_t);
        int8_t getState();
        valuesPID PID;
};

void valuesCar::setCar(int8_t sta, uint32_t update){
    this->state = sta;
    this->lastUpdate = update;
}

int8_t valuesCar::getState(){
    return this->state;
}

int main(){
    valuesCar robot;
    robot.setCar(1, 0);

    vector<float> vect;
  
    vect.push_back(0.2);
    vect.push_back(0.5);
    vect.push_back(1.2);
    
    robot.PID.setPID(10, 0, 0, vect);

    float entrada = 1.5;
    float saida = 2;

    robot.PID.vTaskCalcularPID(&entrada, &saida);
    printf("\n");
    entrada = 0.8;
    saida = 1.5;
    robot.PID.vTaskCalcularPID(&entrada, &saida);
    
    return 0;
}

