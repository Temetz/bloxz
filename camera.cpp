#include "camera.h"
#include "SFML\Graphics.hpp"
#include <iostream>

/*OLETUSKONSTRUKTORI*/
Camera::Camera(){
	this->camera.setSize(400,300);  //KAMERA-ALUEEN KOKO 400x300 px
};

/*OLETUSDEKONSTRUKTORI*/
Camera::~Camera(){
};

/*PALAUTETAAN KOKO SF:VIEW*/
sf::View Camera::get(){
	return this->camera;
}

/*RESETOIDAAN KAMERAN KIERTYMINEN (KUN NAPATAAN KELTAINEN LAATIKKO)*/
void Camera::reset(sf::RenderWindow & window){
	this->camera.setRotation(0);
}

/*RESETOIDAAN KAMERAN KOKO JA ASENTO KUN OLLAAN MENUSSA*/
void Camera::menureset(sf::RenderWindow & window){
	this->camera.setSize(800,600);										//KOKO
	this->camera.setRotation(0);										//KIERTYMA
	this->camera.setCenter(window.getSize().x/2,window.getSize().y/2);	//KAMERA KESKELLE IKKUNAA
	window.setView(this->camera);										//ASETETAAN KAMERA
}

/*KAMERAN PÄIVITYS LIIKKUMISEN MUKAAN*/
void Camera::update(sf::RenderWindow & window){
	this->camera.setSize(400,300);	//ASETETAAN KAMERAN KOKO 400x300px
	/*ASETETAAN KAMERAN KESKIKOHTA VAIN JOS HIIRI ON IKKUNASSA*/
	if((sf::Mouse::getPosition(window).x <= window.getSize().x) && (sf::Mouse::getPosition(window).y <= window.getSize().y)){
		this->camera.setCenter(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
	}
	this->camera.rotate(-0.05f);    //KAANNETAAN KAMERAA 0.05 ASTETTA JOKA PAIVITYKSELLA
window.setView(this->camera);		//ASETETAAN KAMERA ASETUKSIEN MUKAISESTI
}                                                   