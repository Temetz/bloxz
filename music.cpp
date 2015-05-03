#include "music.h"
#include "SFML\Audio.hpp"
#include <iostream>

/*OLETUSKONSTRUKTORI*/
Music::Music(){
	this->music[1].openFromFile("audio/music.ogg");		//TAUSTAMUSIIKKA
	this->music[1].setVolume(40);
	this->music[1].setLoop(true);						//TAUSTAMUSIIKKI ON LOOPPAAVA
	
    this->music[2].openFromFile("audio/negscore.wav");	//MIINUSAANI
	this->music[2].setVolume(80);

	this->music[3].openFromFile("audio/score.wav");		//PISTEAANI
	this->music[3].setVolume(10);

	this->music[4].openFromFile("audio/reset.wav");		//RES OTOINTIAANI
	this->music[4].setVolume(10);
}

/*OLETUS DESTUKTORI*/
Music::~Music(){
}

/*TOISTETAAN AANI ID NUMERON PERUSTEELLA*/
void Music::play(int id){
	this->music[id].play();
}

/*PAUSETETAAN AANI ID NUMERON PERUSTEELLA*/
void Music::pause(int id){
	this->music[id].pause();
}