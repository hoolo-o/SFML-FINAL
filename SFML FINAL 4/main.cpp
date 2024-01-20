
#include "Juego.h"
#include "Partida.h"
#include "Mapa.h"

int main() {
    Juego j(new Partida);
    j.jugar();
    return 0;
}