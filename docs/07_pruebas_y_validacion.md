# Pruebas y Validación (Pendiente)

## Pruebas de hardware
- Verificar que cada LED cambia correctamente según el pin.  
- Confirmar buzzer activo en cambios de fase.  
- Pulsador responde en menos de 200ms.

## Pruebas de software
- Temporizador cambia tras 25 minutos.  
- Reset manual reinicia ciclo.  
- Comunicación serie muestra estados esperados.

## Registro de pruebas
| Fecha | Prueba | Resultado | Observaciones |
|--------|--------|------------|----------------|
| 10/11/2025 | LED rojo encendido | ✅ | Funciona |
| 10/11/2025 | Buzzer no suena | ❌ | Revisar pin D3 |
