#include "event.h"
#include "boxes.h"
#include "SFML\Graphics.hpp"

/*OLETUS KONSTRUKTORI*/
Event::Event(){
}

/*OLETUS DESTRUKTORI*/
Event::~Event(){
}

/*TAPAHTUMAKÄSITTELIJÄ PELIN AIKANA*/
void Event::handle(sf::RenderWindow & window){
	sf::Event eventti;
	while (window.pollEvent(eventti))
        {
			if (eventti.type == sf::Event::Closed){ //JOS PAINETAAN IKKUNAN X
                window.close();						//SULJE IKKUNA
			}

			/*JOS PAINETAAN ESC*/
			if ((eventti.type == sf::Event::KeyPressed) && (eventti.key.code == sf::Keyboard::Escape)){ 
				 window.close();   //SULJE IKKUNA
			}                
		}
}

/*TAPAHTUMAKÄSITTEÖIJÄ MENUSSA*/
void Event::handle(sf::RenderWindow & window, Status & status, Boxes & box){
	sf::Event eventti;
	while (window.pollEvent(eventti))
        {
			if (eventti.type == sf::Event::Closed){  //JOS PAINETAAN IKKUNAN X
                window.close();						 //SULJE IKKUNA
			}

			/*JOS PAINETAAN ESC*/
			if ((eventti.type == sf::Event::KeyPressed) && (eventti.key.code == sf::Keyboard::Escape)){
				 window.close();					//SULJE IKKUNA
			}  

			/*JOS PAINETAAN VALILYONTIA*/
			if ((eventti.type == sf::Event::KeyPressed) && (eventti.key.code == sf::Keyboard::Space)){
				box.clearall();						//ASETA KAIKKI LAATIKOT VALKOISEKSI
				status.setstatus(1);				//ASETA PELITILA (1 = PELI KAYNTIIN)
			}  
		}
}