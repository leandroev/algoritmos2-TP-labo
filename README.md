# algoritmos2-TP-labo
Compilar el archivos tests.cpp para correr el programa

## Cartas enlazadas

En el juego de mesa de Cartas Enlazadas los jugadores se sientan en una mesa y van sacando de alguno de
los dos mazos de cartas (Rojo y Azul), una carta a la vez. El juego de mesa Cartas Enlazadas es uno de los
juegos de cartas m´as complicado que existe, comparable con el m´as complicado de todos1, por ende estamos
desarrollando un peque˜no sistema para poder seguir el puntaje y determinar quien gana. Las reglas descriptas
aqu´ı se refieren a la edici´on simplificada para Algoritmos y Estructuras de datos II.
Los jugadores se sientan de a uno por vez en la mesa y el primero que se le otorgan los dos mazos de cartas.
Los jugadores que se agregan luego lo hacen siempre al lado del jugador que tiene el mazo Azul. Las diferentes
cartas de los mazos van indicando las acciones que los jugadores tienen que hacer.
Uno de los jugadores que tiene un mazo debe revelar la carta que est´a en el tope del mismo. La carta revelada
debe resolverse antes de proseguir. Las posibles acciones que se deben realizar son:
Adelantar el mazo n jugadores.
Eliminar el o los jugadores que cumplen cierta condici´on.
Sumar k puntos al jugador que tiene el mazo.
El juego termina cuando se acaba el mazo y el ganador es el jugador que haya acumulado m´as puntos y est´e
sentado en la mesa. Debido a la caracter´ısticas del mazo nunca se puede dar un empate
