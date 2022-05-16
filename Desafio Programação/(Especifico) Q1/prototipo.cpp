#include <iostream>
#include <vector>

using namespace std;

// Classe: pid.h
class valuesPID
{
    float setPoint, Kp, Ki, Kd;
    public:
        valuesPID(float);           // Construtor
        ~valuesPID();               // Destrutor
        /* Declaracao de metodos */
        // Metodos modificadores, acesso e adicionais
};

// Classe: speed.h
class valuesSpeed
{
    float max_vel, min_vel, base_vel;
    public:
        valuesSpeed(float, float, float);    // Construtor
        ~valuesSpeed();                      // Destrutor
        /* Declaracao de metodos */
        // Metodos modificadores, acesso e adicionais
};

// Classe: lat_marks.h
class valuesMarks
{
    int8_t marks_left, marks_right;
    public:
        valuesMarks(int8_t, int8_t);   // Construtor
        ~valuesMarks();                // Destrutor
        /* Declaracao de metodos */
        // Metodos modificadores, acesso e adicionais
};

// Classe: encoders.h
class valuesEnc
{
    int8_t marks_left, marks_right;
    public:
        valuesEnc(int8_t, int8_t);   // Construtor
        ~valuesEnc();                // Destrutor
        //* Declaracao de metodos *//
        // Metodos modificadores, acesso e adicionais
};

// Classe: lat_sensors.h
class valuesSLat
{
    vector<float> Lat_sensors;
    float max_value, min_value, w_avg;
    public:
        valuesSLat(vector<float>, float);      // Construtor
        ~valuesSLat();                         // Destrutor
        //* Declaracao de metodos *//
        // Metodos modificadores, acesso e adicionais
};

// Classe: array_sensors.h 
class valuesSArray
{
    vector<float> Array_sensors;
    float max_value, min_value, w_avg;
    public:
        valuesSArray(vector<float>, float);
        ~valuesSArray();
        //* Declaracao de metodos *//
        // Metodos modificadores, acesso e adicionais
};

// Classe: car.h
class valuesCar
{
    // Atributos
    int8_t state;    // 0: parado, 1: linha e 2: curva
    uint32_t lastUpdate;
    public:
        valuesCar(int8_t, uint32_t);
        ~valuesCar();
        void setParams(int8_t, uint32_t); 
        int8_t getState();
        uint32_t getUpdate();
        valuesSpeed speed;
        valuesPID PID;
        valuesMarks latMarks;
        valuesEnc motEncs;
        valuesSLat sLat;
        valuesSArray sArray;
};
