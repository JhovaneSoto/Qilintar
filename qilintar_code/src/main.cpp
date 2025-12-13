#include <Arduino.h>

// ciclo de actualizacion de estado de salidas y entradas
int CYCLE = 1000/5;

//Definicion de ciclos Pomodoro
int MAIN_CYCLE [] = {0,1,0,1,0,1,0,1,0,2};
int TIME_PER_CYCLE [] = {20,5,30};
int COLORS_PER_CYCLE [][3] = {{HIGH,LOW,LOW},{LOW,HIGH,LOW},{LOW,LOW,HIGH}};

//VALORES ACTUALES
int CURRENT_CYCLE = 0;
float CURRENT_TIME = TIME_PER_CYCLE[MAIN_CYCLE[CURRENT_CYCLE]];
int CURRENT_COLOR[3] = {0,0,0};

int CURR_BUTTON = 1;
int TEMP_BUTTON = 1;
int LAST_BUTTON = 0;

//tiempo de parpadeo de led

float ON_OFF_TIME = 0.8;

float TIME_LEFT_LED = ON_OFF_TIME;

int STATE_LED = HIGH;

//Pines de entrada
int button_stop = 34;
int button_pause = 35;
int button_play = 32;

//Pines de salida
int r_color = 33;
int g_color = 25;
int b_color = 26;

int interruptor_led = 12;

void setup() {

  pinMode(r_color,OUTPUT);
  pinMode(g_color,OUTPUT);
  pinMode(b_color,OUTPUT);
  pinMode(interruptor_led,OUTPUT);

  pinMode(button_stop, INPUT);
  pinMode(button_pause, INPUT);
  pinMode(button_play, INPUT);

  digitalWrite(r_color,COLORS_PER_CYCLE[MAIN_CYCLE[CURRENT_CYCLE]][0]);
  digitalWrite(g_color,COLORS_PER_CYCLE[MAIN_CYCLE[CURRENT_CYCLE]][1]);
  digitalWrite(b_color,COLORS_PER_CYCLE[MAIN_CYCLE[CURRENT_CYCLE]][2]);

  digitalWrite(interruptor_led,HIGH);

  Serial.begin(115200);
}

int current_button();

void actualizarCiclo();

void loop() {
  actualizarCiclo();
  //TRABAJAR CON BOTONES
  TEMP_BUTTON = current_button();
  if(TEMP_BUTTON != 0 && TEMP_BUTTON != LAST_BUTTON){
    if(TEMP_BUTTON != CURR_BUTTON){
      //SE DETECTO UN CAMBIO DE BOTON/MODO
      CURR_BUTTON = TEMP_BUTTON;
    }
  }

  LAST_BUTTON = TEMP_BUTTON;
  //Serial.println(CURR_BUTTON);

  //ESPERAR QUE SE CONSUMA EL CICLO
  delay(CYCLE);

  
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


//actualiza el ciclo de trabajo

void actualizarCiclo(){

  switch (CURR_BUTTON)
  {
  case 1:
    CURRENT_TIME -= (float)CYCLE/1000.0;
    TIME_LEFT_LED = ON_OFF_TIME;
    STATE_LED = HIGH;
    break;
  case 2:
    TIME_LEFT_LED -= (float)CYCLE/1000.0;
    break;
  case 3:
    CURRENT_TIME = 0;
    CURR_BUTTON = 1;
    break;
  }
  
  if (TIME_LEFT_LED <= 0){
    STATE_LED = !STATE_LED;
    TIME_LEFT_LED = ON_OFF_TIME;
  }

  digitalWrite(interruptor_led, STATE_LED);
  

  if (CURRENT_TIME <= 0){
    int size = sizeof(MAIN_CYCLE) / sizeof(MAIN_CYCLE[0]);

    CURRENT_CYCLE =  (CURRENT_CYCLE + 1) % size;
    CURRENT_TIME = TIME_PER_CYCLE[MAIN_CYCLE[CURRENT_CYCLE]];

    digitalWrite(r_color,COLORS_PER_CYCLE[MAIN_CYCLE[CURRENT_CYCLE]][0]);
    digitalWrite(g_color,COLORS_PER_CYCLE[MAIN_CYCLE[CURRENT_CYCLE]][1]);
    digitalWrite(b_color,COLORS_PER_CYCLE[MAIN_CYCLE[CURRENT_CYCLE]][2]);

  }

  Serial.println(CURRENT_TIME);
}