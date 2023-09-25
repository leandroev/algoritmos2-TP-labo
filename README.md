# algoritmos y estructuras de datos II - TP-labo
Compilar el archivos tests.cpp para correr el programa

## Cartas enlazadas

En el juego de mesa de Cartas Enlazadas los jugadores se sientan en una mesa y van sacando de alguno de
los dos mazos de cartas (Rojo y Azul), una carta a la vez. El juego de mesa Cartas Enlazadas es uno de los
juegos de cartas más complicado que existe, comparable con el más complicado de todos, por ende estamos
desarrollando un pequeño sistema para poder seguir el puntaje y determinar quien gana. Las reglas descriptas
aquí se refieren a la edición simplificada para Algoritmos y Estructuras de datos II.
Los jugadores se sientan de a uno por vez en la mesa y el primero que se le otorgan los dos mazos de cartas.
Los jugadores que se agregan luego lo hacen siempre al lado del jugador que tiene el mazo Azul. Las diferentes
cartas de los mazos van indicando las acciones que los jugadores tienen que hacer.
Uno de los jugadores que tiene un mazo debe revelar la carta que está en el tope del mismo. La carta revelada
debe resolverse antes de proseguir. Las posibles acciones que se deben realizar son:
Adelantar el mazo n jugadores.
Eliminar el o los jugadores que cumplen cierta condición.
Sumar k puntos al jugador que tiene el mazo.
El juego termina cuando se acaba el mazo y el ganador es el jugador que haya acumulado más puntos y esté
sentado en la mesa. Debido a la características del mazo nunca se puede dar un empate.
