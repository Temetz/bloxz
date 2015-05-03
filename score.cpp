#include "score.h"
#include <iostream>
#include <fstream>

/*OLETUS KONSTRUKTORI*/
Score::Score(){
	this->score = 10000;   //ALKUPISTEET 100000
}

/*OLETUS KONSTRUKTORI*/
Score::~Score(){
}

/*SAATIIN PISTEITÄ, LISÄTÄÄN TULOSTA*/
void Score::add(){
	this->score = this->score+500;

}

/*TEHTIIN VIRHE, VÄHENNETÄÄN TULOSTA*/
void Score::remove(){
	this->score = this->score-1000;
}

/*RESEOTOIDAAN TULOS UUTTA PELIÄ VARTEN*/
void Score::reset(){
	this->score = 10000;
}

/*PÄIVITETÄÄN TULOS JA ASETETAAN TULOSTEKSTIN SIJAINTI*/
void Score::update(sf::RenderWindow & window, Text & text, Status & status){
	if(status.getstatus()){
		if((sf::Mouse::getPosition(window).x <= window.getSize().x) && (sf::Mouse::getPosition(window).y <= window.getSize().y)){
			text.setposition(0, sf::Mouse::getPosition(window).x-60,sf::Mouse::getPosition(window).y-50);
		}
	
		text.settext(0,"Score: " + std::to_string(this->score));
	}
}

/*VÄHENNETÄÄN TULOSTA PELIN EDETESSÄ (JOKA LOOPILLA)*/
void Score::timer(){
	this->score--;
}

/*NOUDETAAN JA PALAUTETAAN TULOS*/
long double Score::get(){
	return this->score;
}

/*TULOSTEN TANNENNUS TIEDOSTOON*/
void Score::save(Text & text){

  std::ofstream scorefile ("scores.bloxz", std::ios::app); //AVATAAN TIEDOSTO, KIRJOITUS TIEDOSTON LOPPUUN
  if (!scorefile.is_open()) {
      std::cout << "Tiedoston avausvirhe";
  }else{
	/*TAMANHETKISEN AJAN NOUTO JA MUOTOILU*/
	std::time_t rawtime;  
	std::tm* timeinfo;
	char buffer [80];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);

	std::strftime(buffer,80,"%d.%m.%Y-%H:%M:%S",timeinfo);   //MUOTOILLAAN KELLONAIKA
	/*AIKA END*/

	scorefile << buffer << "|" << std::to_string(this->score) << "\n";
	scorefile.close();

	text.settext(0,"You scored: " + std::to_string(this->score) + " points ;)\n  Press Space to restart!");
	text.multiset(0,40,150,100);
	this->reset(); //RESETOIDAAN TULOS TALLENNYUKSEN JÄLKEEN
  }
}