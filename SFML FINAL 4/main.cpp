
#include "Juego.h"
#include "Partida.h"
#include "Mapa.h"
#include "menu.h"

int main() {
    Juego j(new menu);
    j.jugar();
    return 0;
}