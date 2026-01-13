# Snake en C++ (Proyecto Experimental)

## Descripción

Este es un **juego clásico de Snake** desarrollado en C++ usando la consola de Windows.  
El objetivo del juego es mover la serpiente para comer la fruta (`F`) y crecer sin chocar con su propio cuerpo.

Es un proyecto desarrollado con fines **educativos**, ideal para practicar:
- Manejo de arrays
- Lógica de colisiones
- Entrada de teclado en tiempo real
- Control de pantalla en consola (gotoxy y COORD)

---

## Cómo jugar

- Usa las teclas del teclado para mover la serpiente:
  - `w` → Arriba
  - `s` → Abajo
  - `a` → Izquierda
  - `d` → Derecha
- Presiona `x` para salir del juego.
- Cada fruta que comas suma **10 puntos**.
- La serpiente crece cada vez que come una fruta.
- Cuando la serpiente choca con su propio cuerpo, el juego termina.

---

## Funcionamiento general

- **C++** como lenguaje principal.
- Uso de **conio.h** para entrada de teclado en tiempo real.
- Uso de **windows.h** para mover el cursor en la consola (`gotoxy`) y controlar la velocidad (`Sleep`).
- Lógica de colisiones y crecimiento de la serpiente mediante arrays (`colaX`, `colaY`).

---

## Estructura del código

1. `Inicializar()` → Inicializa variables del juego (posición de la serpiente, fruta y puntuación).
2. `Dibujar()` → Dibuja la pantalla del juego, la serpiente y la fruta.
3. `Entrada()` → Detecta la tecla presionada para mover la serpiente.
4. `Logica()` → Actualiza la posición de la serpiente, verifica colisiones y controla el crecimiento al comer fruta.
5. `main()` → Bucle principal que ejecuta el juego hasta que se pierde.

---

## Captura de pantalla (opcional)

