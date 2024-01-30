#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Poder {
private:
public:
	virtual void actualizar(Vector2f pos) = 0;
	virtual void dibujar(RenderWindow& w) = 0;
	virtual ~Poder() {};
};