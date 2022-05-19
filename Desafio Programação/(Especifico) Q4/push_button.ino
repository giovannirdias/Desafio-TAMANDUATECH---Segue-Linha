#include <LiquidCrystal.h>

// Inicializacao das variaveis auxiliares
int push_button = 8;  //PIN 8
int count = 0;
int stop = 1;
bool state = LOW;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Funcao para configuracao dos pinos
void setup(){
	lcd.begin(16, 2);
  	pinMode(push_button, INPUT);
  	lcd.print(count);
}

// Funcao para permitr a mudanca e resposta com a ativadade no Arduino
void loop(){
	state = digitalRead(push_button);  // Leitura do estado do botao
  	// Conta quando o botao eh pressionado
  	if (state == HIGH && stop == 1){
    	count += 1;
      	stop = 0; // Variavel para controle de mudancas reais
      	lcd.setCursor(0, 0);
      	lcd.print(count);
      	delay(75);  // Metodo para debouncing
    }
    // A contagem ocorre apenas quando o botao for solto e pressionado novamente
  	if (state == LOW && stop == 0){
    	stop = 1;
    }
}
