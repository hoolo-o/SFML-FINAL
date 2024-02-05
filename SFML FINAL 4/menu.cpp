#include "menu.h"
#include "Partida.h"
#include "Juego.h"
menu::menu()
{

	v = cargarDatosDesdeArchivo();

	sort(v.begin(), v.end(), compararPorKills);

	for (int x = 0;x < v.size();x++) {
		cout << v[x].usuario << endl;
	}
	fuente.loadFromFile("Recursos/Winter Storm2.ttf");
	fondo.loadFromFile("Imagenes/Menuu.png");

	s_fondo.setTexture(fondo);

	b_Jugar.setScale(1.5f,1.5f);
	b_Jugar.setPosition(500, 350);
	b_Jugar.setFillColor(Color::White);
	b_Jugar.setSize(Vector2f(100, 50));

	puntos.setFont(fuente);
	puntos.setCharacterSize(25);
	puntos.setPosition(50,240);
	puntos.setFillColor(Color::Black);
	for (int x = 0;x < v.size();x++) {
		aux += v[x].usuario + " / " + std::to_string(v[x].kills) + " / " + std::to_string(v[x].puntos) + '\n';
		if (x >= 9) {
			break;
		}
	}
	puntos.setString(aux);


	jugar.setFont(fuente);
	jugar.setFillColor(Color::Black);
	jugar.setPosition(518, 280);
	
	ver_puntos.setScale(1.5f, 1.5f);
	ver_puntos.setPosition(30,30);
	ver_puntos.setFillColor(Color::White);
	ver_puntos.setSize(Vector2f(100, 50));
}

void menu::dibujar(RenderWindow& w)
{
	w.clear(Color::Black);
	w.draw(s_fondo);
	//w.draw(ver_puntos);
	w.draw(jugar);
	w.draw(puntos);
	
}

void menu::actualizar(Juego& j) {
	if (Keyboard::isKeyPressed(Keyboard::Enter)) {
		j.cambiarEscena(new Partida(aux2));
	}

	if (j.getEvent()->type == Event::TextEntered && fj.getElapsedTime().asSeconds() > 0.1 && !Keyboard::isKeyPressed(Keyboard::BackSpace)) {
		if (j.getEvent()->text.unicode < 128 && aux2.getSize() < 10) {
			fj.restart();
			aux2 += static_cast<char>(j.getEvent()->text.unicode);
			jugar.setString(aux2);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::BackSpace) && fj.getElapsedTime().asSeconds() > 0.1 && !aux2.isEmpty()) {
		fj.restart();
		aux2.erase(aux2.getSize() - 1);
		jugar.setString(aux2);
	}
}


