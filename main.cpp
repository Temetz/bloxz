#include "cursor.h"
#include "camera.h"
#include "event.h"
#include "score.h"
#include "music.h"
#include "text.h"
#include "boxes.h"
#include "status.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <cstring>
#include <stdlib.h>
#include <iostream>

/*MAININ ALIOHJELMIEN ESITTELYT*/
int videomode();
int aamode();

int main()
{  
	/*ALKUVALMISTELUT*/
	/*LUODAAN LUOKAT*/
	Cursor cursor;
	Camera camera;
	Event events;
	Score score;
	Music sound;
	Text text;
	Boxes boxit;
	Status status;
	/**/

	sf::RenderWindow window; //SFML IKKUNAN LUONTI

	/*KYSYTAAN ALKUASETUKSET PELIIN*/
	int mode = videomode();
	if(mode == 1){
		window.create(sf::VideoMode(800, 600), "Bloxz",sf::Style::Close,sf::ContextSettings(32,32,aamode()));
	}
    if(mode == 2){
		window.create(sf::VideoMode(800, 600), "Bloxz",sf::Style::Fullscreen,sf::ContextSettings(32,32,aamode()));
	}
	/**/

	/*IKKUNAN MUUT ASETUKESET*/
	window.setMouseCursorVisible(false); //POISTETAAN WINDOWSSIN KURSORI KÄYTYÖSTÄ
	window.setFramerateLimit(40);        //PÄIVITYSNOPEUS MAX 40 FPS

	cursor.generate();					 //LUODAAN UUSI PALLOKURSORI
	sound.play(1);						 //ALOITETAAN TAUSTAMUSIIKIN SOITTO
	
	
while (window.isOpen())					//IKKUNOINNIN PÄÄLOOPPI
    {   
		if(status.getstatus()){         //JOS PELI KÄYNNISSÄ
			events.handle(window);		//KÄSITELLÄÄN INPUTIT
			boxit.collisions(window, sound, camera, score, status, text); //TARKISTETAAN ONKO KURSORI LAATIKOSSA
			boxit.randomize();			//VÄRITETÄÄN SATUNNAISET LAATIKOT
			window.clear();				//TYHJENNETAAN SFML IKKUNA
			boxit.draw(window);			//PIIRRETAAN LAATIKOT
			camera.update(window);		//PAIVITETAAN KAMERAN SIJAINTI
			cursor.update(window);		//PAIVITETAAN KURSORIN SIJAINTI
			score.update(window,text,status); //PAIVITETAAN SCORETEKSTI JA SEN SIJAINTI
			text.draw(window);			//PIIRRETAAN SCORETEKSTI
			window.display();			//PIIRRETÄÄN IKKUNA NÄKYVIIN
		}else{							//JOS PELI PAATTYNYT
			boxit.menurandomize();      //VÄRITETÄÄN MENUIKKUNAN LAATIKOITA SATUNAISESTI
			events.handle(window,status,boxit); //KÄSITELLÄÄN INPUTIT
			window.clear();				//TYHJENNETAAN SFML IKKUNA
			camera.menureset(window);	//ASETETAAN KAMERAN SIJAINTI MENUIKKUNASETUKSIIN
			boxit.draw(window);			//PIIRRETAAN LAATIKOT
			text.draw(window);			//PIIRRETAAN TEKSTIT
			window.display();			//PIIRRETAAN IKKUNA
		}
    }	
    return 0;                           //SFML IKKUNA ON SULJETTU; PALAUTETAAN MAINILLE 0;
}

/*VIDEOTILAN KYSELY*/
int videomode(){
	int videomode = 0;
	while(videomode != 1 && videomode !=  2){
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << std::endl << "Valitse videotila. [1]windowed, [2]fullscreen: ";
		std::cin >> videomode;
	}
	return videomode;
}
/**/

/*ANTI-ALLASING TILAN KYSELY*/
int aamode(){
	int aamode = -1;
	while(aamode < 0 || aamode > 32){
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << std::endl << "Reunapehmennys? [0-32]: ";
		std::cin >> aamode;
	}
	return aamode;
}
/**/