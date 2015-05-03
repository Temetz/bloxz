#include "text.h"
#include <cstring>

/*OLETUS KONSTRUKTORI*/
Text::Text(){
	this->font.loadFromFile("LLPIXEL3.ttf");                      //LADATAAN FONTTI
	for(int i=0; i<((sizeof(textbank))/(sizeof(sf::Text)));i++){  //ASETETAAN KAIKKIEN TEKSTIEN OLETUSFONTTI JA KOKO
		this->textbank[i].setFont(this->font);
		this->textbank[i].setCharacterSize(10);
	}

	//ASETETAAN OLETUSTEKSTI JA ASETUKEST TEKSTIPANKIN PAIKKAAN [0]
	this->textbank[0].setCharacterSize(20);
	this->textbank[0].setColor(sf::Color::Magenta);
	this->textbank[0].setString("                                                                    Bloxz!\n     Keys: ESC = QUIT ;SPACE=START ;MOUSE=MOVE CURSOR\nRED=:( ;GREEN=:) ;YELLOW=RESET ROTATION ;BLUE=SCORE");
	this->textbank[0].setPosition(100,105);
}

/*OLETUS DEKONSTRUKTORI*/
Text::~Text(){
}

/*PALAUTETAAN HALUTTU TEKSTI TEKSTIPANKISTA*/
sf::Text Text::get(int i){
	return this->textbank[i];
}

/*ASETETAAN TEKSTI TEKSTIPANKKISSA*/
void Text::settext(int i, std::string text){
	this->textbank[i].setString(text);
	this->textbank[i].setCharacterSize(20);
}

/*ASETETAAN TEKSTIN SIJAINTI TEKSTIPANKISSA*/
void Text::setposition(int i, float x, float y){
	this->textbank[i].setPosition(x,y);
}

/*ASETETAAN TEKSTIN KOKO JA SIJAINTI*/
void Text::multiset(int id, int size, float x, float y){
	this->textbank[id].setCharacterSize(size);
	this->textbank[id].setPosition(x,y);
}

/*PIIRRETÄÄN KAIKKI TEKSTIPANKISSA OLEVAT TEKSTIT JOTKA EIVÄT OLE TYHJIA*/
void Text::draw(sf::RenderWindow & window){
		for(int i = 0; i < (sizeof this->textbank)/(sizeof sf::Text); i++){
			if(this->textbank[i].getString() != ""){
			window.draw(this->textbank[i]);
		}
	}
}