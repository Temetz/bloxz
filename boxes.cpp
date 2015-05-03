#include "boxes.h"
#include "text.h"
#include "SFML\Graphics.hpp"
#include <iostream>

/*OLETUSKONSTRUKTORI*/
/*LUODAAN PELIN LAATIKOT*/
Boxes::Boxes(){
	int a = 0;
	/*TAYTETAAN KOKO 30x40 RUUDUKKKO*/
	for(int korkeus = 1; korkeus <= 30; korkeus++){
		for(int leveys = 1; leveys <= 40; leveys++){
			sf::RectangleShape box(sf::Vector2f(20,20));
			box.setOutlineColor(sf::Color::Color(0,0,0));
			box.setOutlineThickness(2);
			box.setPosition((leveys-1)*20,(korkeus-1)*20);
		    
			//tiedot[] = LISTA LAATIKOISTA JA SEN TIEDOISTA
			this->tiedot[a].id = a;       //YKSILOLLINEN ID
			this->tiedot[a].x = leveys;   //SIJAINTI RUUDUKOSSA x
			this->tiedot[a].y = korkeus;  //SIJAINTI RUUDUKOSSA y
			this->tiedot[a].state = 1;    //VAPAA / TYHJA = VALKOINEN
			this->tiedot[a].box = box;    //SF:RECTANGESHAPE
			a++;
		}
	}
}

/*OLETUSDEKONSTRUKTORI*/
Boxes::~Boxes(){
}

/*PELIKENTAN MUUTTUMINEN*/
void Boxes::randomize(){
	/*STAUS KOODIT this->setcolorin toiseksi intiksi*/	
		//0=unset
		//1=white
		//2=vihree
		//3=punanen
		//4=kelt
		//5=sin

	/*20% MAHDOLLISUUS ETTA PELIKENTTA MUUTTUU*/
	if(rand()%100<20){
	
		if((rand()%100)<10){					//10% MAHDOLLISUUS ETTA RANDOM LAATIKKO MUUTTUU KELTAISEKSI
			this->setcolor(rand()%1201, 4);	
		}

		if((rand()%100)<5){						//5% MAHDOLLISUUS ETTA RANDOM LAATIKKO MUUTTUU SINISEKSI
			this->setcolor(rand()%1201, 5);
		}


		this->setcolor(rand()%1201, 2);			//MUUTETAAN RANDOM LAATIKKO VIHREAKSI
		this->setcolor(rand()%1201, 3);			//MUUTETAAN RANDOM LAATIKKO PUNAISEKSI
		this->setcolor(rand()%1201, 3);			//MUUTETAAN RANDOM LAATIKKO PUNAISEKSI

		for(int c=0; c<7; c++){					//MUUTETAAN 7 RANDOM LAATIKKO VALKOISEKSI
			this->setcolor(rand()%1201, 1);
		}
	}
}

/*MENULAATIKOIDEN "ANIMOINTI"*/
void Boxes::menurandomize(){
     for(int i=0;i<1201;i++){			//KAYDAAN LAPI KAIKKI LAATIKOT
		 if(!((i>5*40-1)&&(i<10*40))){	//JOS EI OLLA "SAFE ZONELLA" (VARATTU TEKSTILLE)
			 if(rand()%400<1){			//0.25% MAHDOLLISUUS ETTA RUUTU VAIHTAA VARIA
				this->setcolor(i, sf::Color(rand()%255,rand()%255,rand()%255,rand()%255));
			 }
		 }else{											//OLTIIN "SAFE ZONELLA"
				 this->setcolor(i, sf::Color::White);	//RUUDUT VALKOISEKSI
		 }
	 }
}

/*ASETETAAN LAATIKKO HALUTUN VARISEKSI*/
void Boxes::setcolor(int id, int vari){
	if(vari == 1){
		this->tiedot[id].state = vari;
		this->tiedot[id].box.setFillColor(sf::Color::White);
	}

	if(vari == 2){
		this->tiedot[id].state = vari;
		this->tiedot[id].box.setFillColor(sf::Color::Green);
	}

	if(vari == 3){
		this->tiedot[id].state = vari;
		this->tiedot[id].box.setFillColor(sf::Color::Red);
	}

	if(vari == 4){
		this->tiedot[id].state = vari;
		this->tiedot[id].box.setFillColor(sf::Color::Yellow);
	}

	if(vari == 5){
		this->tiedot[id].state = vari;
		this->tiedot[id].box.setFillColor(sf::Color::Blue);
	}
}

/*KUORIMITETTY VARIENVAIHTO, MAHDOLLISUUS ASETTAA VARI SF::COLORILLA*/
/*KAYTTO MENUVALIKOSSA*/
void Boxes::setcolor(int id, sf::Color vari){
	this->tiedot[id].box.setFillColor(vari);
}

/*TYHJENTAA KAIKKI LAATIKOT JA ASETTAA STATUKSEN 1 = TYHJA*/
void Boxes::clearall(){
		for(int i=0; i< 1201; i++){
			this->tiedot[i].state = 1;
			this->tiedot[i].box.setFillColor(sf::Color::White);
		  }
}

/*PIIRTAA KAIKKI LAATIKOT IKKUNAN*/
void Boxes::draw(sf::RenderWindow & window){
		for(int i=0; i< 1201; i++){
			window.draw(this->tiedot[i].box);
		  }
}

/*TARKISTAA TORMAAKO HIIRI LAATIKKOON*/
void Boxes::collisions(sf::RenderWindow &window, Music &sound, Camera &camera, Score &score, Status &status, Text & text){
	/*LAATIKOIDEN STATUS ID:T*/
		//0=unset
		//1=white
		//2=vihree
		//3=punanen
		//4=kelt
		//5=sin

	for(int i=0; i< 1201; i++){  //KAYDAAN LAPI KAIKKI LAATIKOT
		/*JOS OLLAAN VIHREASSA*/
		if((this->tiedot[i].state == 2) && this->tiedot[i].box.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
			this->setcolor(i,1);	//ASETETAAN LAATIKKO VALKOISEKSI
			score.add();			//LISATAAN SCOREA
			sound.play(3);			//SOITEAAN PISTEAANI
		}

		/*JOS OLLAAN PUNAISESSA*/
		if((this->tiedot[i].state == 3) && this->tiedot[i].box.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
			this->setcolor(i,1);    //ASETETAAN LAATIKKO VALKOISEKSI
			score.remove();			//VAHENNETAAN SCOREA
			sound.play(2);			//SOITETAAN VIRHEAANI
		}

		/*JOS OLLAAN KELTAISESSA*/
		if((this->tiedot[i].state == 4) && this->tiedot[i].box.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
			this->clearall();		//TYHJENNETAAN KAIKKI LAATIKOT
			sound.play(4);			//SOITETAAN RESET AANI
			camera.reset(window);   //RESETOIDAAN KAMERA
		}

		/*JOS OLLAAN SINISESSA*/
		if((this->tiedot[i].state == 5) && this->tiedot[i].box.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
			this->setcolor(i,1);    //ASETATAAN VARI VALKOISEKSI
			score.save(text);		//TALLENNETAAN TULOS
			status.setstatus(0);    //ASETETAAN PELITILA 0 = MENU
		}
	}
	score.timer();                  //VAHENNETAAN SCOREA JOKA LOOPILLA
}