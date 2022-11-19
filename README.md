# README DEL PROYECTO
## _Descripción del Programa_


El programa se encarga de simular el juego egipsio **Senet**. Esto cumple con el proyecto del curso "Diseño de Software".


# _Manual de usuario_
## Modo de uso
El juego se puede jugar de dos formas, por terminal o por medio de una _GUI_ construida con el programa _QT_. A continuación se dan instrucciones de cómo construir y correr el juego en consola. Para correrlo con la _GUI_ deberá instalar el programa y construir el programa.

## ¿Cómo construir el proyecto?
Ingrese el comando: 

    make

## ¿Cómo correr el programa?
Ingrese el comando: 

    make run

## ¿Cómo limpiar los archivos generados por el programa?
Ingrese el comando: 

    make clean

# _Reglas del Juego_

1. Se ubican las fichas en el tablero sobre la primera fila intercalando blancas y negras alternativamente, comenzando por la ficha blanca en el casillero1.

2. Empieza el jugador 1.

3. El turno acaba cuando el jugador saca un 2 ó un 3, (pasa el turno después de mover una ficha la cantidad de espacios correspondientes a esta última lanzada). Mientras tanto el jugador sigue lanzando y jugando hasta sacar este 2 ó 3.

4. Si una ficha cae en un lugar ocupado por el adversario las fichas intercambian lugares.

5. Dos fichas juntas del mismo jugador bloquean la posibilidad del adversario de intercambiar las fichas.

6. Tres fichas juntas del mismo jugador no pueden ser sobrepasadas por una del adversario a pesar de que el valor de la lanzada lo permita.

7. Si una ficha no puede adelantar, debe entonces retroceder.

8. Si ninguna de las fichas del jugador pueden ser movidas, pasa entonces el turno al adversario.

9. Si una ficha se encuentra en las casillas de seguridad número 26, 28 o 29 no puede ser intercambiada por una del adversario.

10. Si una ficha cae en el río Nilo, casillero número 27, debe retroceder al casillero número 15. Si este casillero está ya ocupado por una ficha, propia o del adversario, debe entonces seguir retrocediendo hasta el casillero número 1.

11. Las fichas continúan su camino hasta salir del tablero. No es necesario sacar las fichas con el valor exacto.

12. No se pueden sacar fichas del tablero mientras haya alguna ficha propia en el primer fila del tablero.

# _Créditos_

Josué Retana Rodríguez C06440

Hansell Solís Ramírez, C07677

Judith Vargas Esquivel, C08168

Henry Ledezma Vindas, C04185
