# Qilintar (Pomodoro Timer)

![Qilintar Logo](/assets/logo/logo.jpg)

Temporizador Pomodoro basado en un **ESP32 DEVKIT V1** con un **LED RGB** y un **buzzer** para indicar las fases de trabajo y descanso del método Pomodoro.  
Su nombre se basa en los **Qilin**, criatura mitológica de origen oriental, relacionada con la virtud, el conocimiento y la sabiduría moral.

![Qilin](https://upload.wikimedia.org/wikipedia/commons/9/9b/%E9%BA%92%E9%BA%9F_Qilin_%D0%A6%D0%B8%D0%BB%D0%B8%D0%BD%D1%8C_%287944149254%29.jpg)

---

## 🧭 Estado del proyecto

🟡 Prototipo funcional en hardware real (**ESP32 DEVKIT V1**).

---

## 🎯 Objetivos

- Implementar ciclos automáticos de trabajo y descanso usando un microcontrolador.
- Mostrar el estado mediante un LED RGB.
- Emitir sonidos cuando cambia de fase.
- Permitir detener, continuar y saltar cada fase utilizando botones físicos.

---

## ▶️ Uso básico

1. Al encender el dispositivo, el ciclo Pomodoro inicia automáticamente.
2. **Botón 1**: continúa el ciclo actual.
3. **Botón 2**: pausa el ciclo.
4. **Botón 3**: salta a la siguiente fase del ciclo.
5. El LED RGB y el buzzer indican el estado y los cambios de fase.

---

## Diagrama

![Diagrama](/pcb_design/final_schematic.SVG)

## Prototipo

![Prototipo_a](/assets/images/prototype_1.jpg)
![Prototipo_b](/assets/images/prototype_2.jpg)

## Demostración

[Ver demostración](./assets/demostracion.mp4)

## 📚 Documentación

- [Visión general](/docs/01_vision_general.md)
- [Requerimientos funcionales](/docs/02_requerimientos.md)
- [Diseño del circuito](/docs/03_diseno_circuito.md)
- [Firmware y código](/docs/04_firmware_y_software.md)
- [Flujo de trabajo](/docs/05_flujo_de_operacion.md)
- [Plan de desarrollo](/docs/06_plan_desarrollo.md)
- [Notas y versiones](/docs/07_notas_y_versiones.md)

