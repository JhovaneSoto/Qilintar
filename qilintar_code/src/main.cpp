#include <Arduino.h>

// ciclo de actualizacion de estado de salidas y entradas
int CYCLE = 1000/5;

//Definicion de ciclos Pomodoro
int MAIN_CYCLE [] = {0,1,0,1,0,1,0,1,0,2};
int TIME_PER_CYCLE [] = {20,5,30};
int COLORS_PER_CYCLE [][3] = {{HIGH,LOW,LOW},{LOW,HIGH,LOW},{LOW,LOW,HIGH}};

//VALORES ACTUALES
int CURRENT_CYCLE = MAIN_CYCLE[0];
int CURRENT_TIME = TIME_PER_CYCLE[CURRENT_CYCLE];
int CURRENT_COLOR[3];
CURRENT_COLOR[0] = COLORS_PER_CYCLE[CURRENT_CYCLE][0];
CURRENT_COLOR[1] = COLORS_PER_CYCLE[CURRENT_CYCLE][1];
CURRENT_COLOR[2] = COLORS_PER_CYCLE[CURRENT_CYCLE][2];

//Pines de entrada
int button_stop = 34;
int button_pause = 35;
int button_play = 32;

void setup() {
  pinMode(button_stop, INPUT);
  pinMode(button_pause, INPUT);
  pinMode(button_play, INPUT);

  Serial.begin(115200);
}

int current_button();

void loop() {
  delay(CYCLE);
  Serial.println(current_button());
}




//Filtra y retorna el boton que esta actualmente presionado
int current_button(){
  int buttons[3] = {digitalRead(button_play),digitalRead(button_pause),digitalRead(button_stop)};
  
  //si hay mas de un boton presionado se considera que no hay ningun boton realmente presionado
  if ((buttons[0] + buttons[1] + buttons[2]) != 1){
    return 0;
  }

  if (digitalRead(button_play) == HIGH)  return 1;
  if (digitalRead(button_pause) == HIGH) return 2;
  if (digitalRead(button_stop) == HIGH)  return 3;
  return 0;
}