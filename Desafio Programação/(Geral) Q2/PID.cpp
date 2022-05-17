// Metodo adicional para realizar a tarefa de calculo do controlador PID
//Assumiu-se que os parametros utilizados no calculo do PID sao declarados na class valuesPID construida na Q1

void valuesPID::vTaskCalcularPID(float *input, float *output){
    // Calculo do erro atual
    float error = this->setPoint - *input;
    // Componentes do controlador
    float P = error * this->Kp;                      // Proporcional
    this->I += error*(*output)*this->Ki;             // Integrativo
    float D = (error - this->prevError)/(*output);   // Derivativo
    
    // Calculo para o ajuste dos motores
    this->ajuste = P + this->I + D;
    // Atualizacao do erro para proxima iteracao
    this->prevError = error;
}
