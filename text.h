#ifndef texth
#define texth
#include "SFML\Graphics.hpp"
#include <cstring>

class Text{
protected:
	sf::Text textbank[5];                //TESKTIPANKKI
	sf::Font font;						 //KAYTETTAVA FONTTI
public:
	
	Text();
	~Text();
	sf::Text get(int);					 //PALAUTA SF::TEXT (TEKSTIPANKKI ID)
	void settext(int, std::string);      //ASETA TEKSTI (TEKSTIPANKKI ID ; TEKSTI)
	void setposition(int, float, float); //ASETA TEKSTIN PAIKKA (TEKSTIPANKKI ID ; X koodinaatti ; Y koordinaatti)
	void multiset(int,int,float,float);  //ASETA TEKSTIN FONTTI JA PAIKKA (TEKSTIPANKKI ID ; FONTTIKOKO ; X koodinaatti ; Y koordinaatti)
	void draw(sf::RenderWindow &);       //PIIRRA LAATIKOT SF::RENDERWINDOW (PELIIKKUNA)
};

#endif