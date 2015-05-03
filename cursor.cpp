#include "cursor.h"
#include "text.h"
#include "SFML\Graphics.hpp"
#include <iostream>

/*OLETUSKONSTRUKTORI*/
Cursor::Cursor(){
}

/*OLETUSDEKONSTRUKTORI*/
Cursor::~Cursor(){
}

/*KURSORIN LUONTI*/
void Cursor::generate(){
this->cursor.setRadius(5.0f);						//SATEEKSI 5
this->cursor.setOrigin(5.0f,5.0f);					//KESKUSTA PALLON KESKELLE
this->cursor.setOutlineColor(sf::Color::Magenta);	//ULKOREUNAN VÄRI MAGENTA
this->cursor.setFillColor(sf::Color::Transparent);  //SISUSTA LÄPINÄKYVÄ
this->cursor.setOutlineThickness(2);				//REUNUKSEN PAKUUS 2

}

/*NOUDETAAN KOKO SF::CIRCLESHAPE JA PALAUTETAAN SE*/
sf::CircleShape Cursor::get(){
	return this->cursor;
}

/*PÄIVITETÄÄN KURSORIN SIJAINTI HIIREN KANSSA SAMAAN KOHTAAN JA PIIRRETAAN SE*/
void Cursor::update(sf::RenderWindow & window){
	/*MUTTA VAIN JOS HIIRI ON IKKUNASSA*/
	if((sf::Mouse::getPosition(window).x <= window.getSize().x) && (sf::Mouse::getPosition(window).y <= window.getSize().y)){
		this->cursor.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	}
window.draw(this->cursor); //PIIRRA KURSORI
}