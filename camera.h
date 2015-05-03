#ifndef camerah
#define camerah
#include <SFML\Graphics.hpp>

class Camera{
protected:
	sf::View camera;
public:
	Camera();
	~Camera();
	sf::View get();								  //PALAUTA KAMERA SF:VIEW
	void update(sf::RenderWindow &);		      //PAIVITA KAMERAN SIJAINTI (SF:RENDERWINDOW OSOITE) 
	void reset(sf::RenderWindow &);				  //RESETOI KAMERAN SIJAINTI (SF:RENDERWINDOW OSOITE) 
	void menureset(sf::RenderWindow &);           //RESETOI KAMERA MENUA VARTEN (SF::RENDERWINDOW OSOITE)
};
#endif