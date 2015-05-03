#ifndef cursorh
#define cursorh
#include "text.h"
#include "SFML\Graphics.hpp"
class Cursor{
protected:
	sf::CircleShape cursor;
public:
	Cursor();
	~Cursor();
	void generate();                 //LUO KURSORI
	sf::CircleShape get();			 //PALAUTA SF::RECTANGLESHAPE
	void update(sf::RenderWindow &); //PAIVITA KURSORIN SIJANTI (IKKUNA)
};

#endif