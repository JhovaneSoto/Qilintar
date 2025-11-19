# Firmware y Software (Pendiente)

## Firmware (Arduino)
El firmware controla los ciclos Pomodoro:
1. Inicia en estado "trabajo" (LED rojo).  
2. Al completar el tiempo, pasa a "descanso" (LED verde).  
3. Suena el buzzer entre fases.  
4. Permite reinicio manual con pulsador.

## Pseudocódigo
loop:
  si estado == trabajo y tiempo cumplido:
    cambiar a descanso
    sonar buzzer
  si estado == descanso y tiempo cumplido:
    cambiar a trabajo
    sonar buzzer

## Comunicación externa (opcional)
- Enviar estado por puerto serie (ej: `STATE:WORK`).  
- Recibir comandos desde Python (ej: `SET 20 5`).
