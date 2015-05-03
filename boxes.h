#ifndef boxes
#define boxes
#include "cursor.h"
#include "music.h"
#include "camera.h"
#include "score.h"
#include "status.h"
#include "text.h"
#include "SFML\Graphics.hpp"


class Boxes{
protected:
	struct BOX{              //LAATIKKOLISTAN ELEMENTIN RAKENNE
	int id;					 //UNIQUE ID
	int x;					 //X koordinaatti (40x30 ruudukossa)
	int y;					 //Y koordinaatti (40x30 ruudukossa)
	int state;               //TILA [0-5]
	sf::RectangleShape box;  //SF::RECTANGESHAPE
	};

	BOX tiedot[1201];	     //LAATIKKOLISTA
public:
	Boxes();
	~Boxes();
	void randomize();                 //SATUNNOI LAATIKOT
	void menurandomize();             //SATUNNOI LAATIKOT MENUSA
	void setcolor(int, int);          //ASETA LAATIKON VARI (LAATIKKO ID; VARI [0-5])
	void setcolor(int, sf::Color);    //ASETA LAATIKON VARI (LAATIKKO ID; SF::COLOR)
	void draw(sf::RenderWindow &);    //PIIRRA LAATIKOT (SF::RENDERWINDOW OSOITE [KOHDEIKKUNA])
	void collisions(sf::RenderWindow &, Music &, Camera &, Score &, Status &, Text &); 
									  //TARKISTA TORMAYKSET (SF::RENCERWINDOW OSOITE; Music luokan osoite; 
									  //Camera luokan osoite; Score luokan osoite; Status luokan osoite; Text luokan osoite)
	void clearall();				  //TYHJENNA KAIKKI LAATIKOT
};


#endif