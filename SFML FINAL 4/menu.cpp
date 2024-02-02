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
	jugar.setFillColor(Color::Black);
	jugar.setPosition(518, 234);
	jugar.setString("Jugar : M");

	b_ver_puntos.setScale(1.5f, 1.5f);
	b_ver_puntos.setPosition(500,220);
	b_ver_puntos.setFillColor(Color::White);
	b_ver_puntos.setSize(Vector2f(100, 50));

}

void menu::dibujar(RenderWindow& w)
{
	w.clear(Color::Black);
	w.draw(b_Jugar);
	w.draw(b_ver_puntos);
	w.draw(jugar);

}

void menu::actualizar(Juego& j)
{
	if (Keyboard::isKeyPressed(Keyboard::M)) {
			j.cambiarEscena(new Partida);
	}
	j.Eventos(e);
	if (Keyboard::isKeyPressed(Keyboard::Enter)) {
		s_nombre = j.getNombre();
		jugar.setString(s_nombre);
	}
}

