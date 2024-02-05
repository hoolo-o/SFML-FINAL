#include "menu.h"
#include "Func_aux.h"
#include "Partida.h"
#include "Juego.h"
menu::menu()
{

	fuente.loadFromFile("Recursos/NightmarePills-BV2w.ttf");

	b_Jugar.setScale(1.5f,1.5f);
	b_Jugar.setPosition(500, 350);
	b_Jugar.setFillColor(Color::White);
	b_Jugar.setSize(Vector2f(100,50));

	jugar.setFont(fuente);
	jugar.setFillColor(Color::White);
	jugar.setPosition(518, 234);

	ver_puntos.setScale(1.5f, 1.5f);
	ver_puntos.setPosition(30,30);
	ver_puntos.setFillColor(Color::White);
	ver_puntos.setSize(Vector2f(100, 400));
}

void menu::dibujar(RenderWindow& w)
{
	w.clear(Color::Black);
	w.draw(b_Jugar);
	w.draw(ver_puntos);
	w.draw(jugar);

}

void menu::actualizar(Juego& j)

{
	if (Keyboard::isKeyPressed(Keyboard::Enter)) {
		j.cambiarEscena(new Partida(aux2));
	}
	if (j.getEvent()->type == Event::TextEntered and fj.getElapsedTime().asSeconds()> 0.1) {
		if (j.getEvent()->text.unicode < 128) {
			fj.restart();
			aux2 += static_cast<char>(j.getEvent()->text.unicode);
			jugar.setString(aux2);
		}
	}
}

