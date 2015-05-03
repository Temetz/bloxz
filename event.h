#ifndef eventh
#define eventh
#include "score.h"
#include "status.h"
#include "boxes.h"
#include "SFML\Graphics.hpp"
class Event{
public:
	Event();
	~Event();
	void handle(sf::RenderWindow &);                    //TAPAHTUMAKASITTELIJA (RENDERWINDOW OSOITE)
	void handle(sf::RenderWindow &, Status &, Boxes &); //YLIKUORMITETTU TAPAHTUMAKASITTELEIJA (RENDERWINDOW OSOITE)
};
#endif