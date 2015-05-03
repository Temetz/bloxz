#ifndef scoreh
#define scoreh
#include "text.h"
#include "status.h"

class Score{
protected:
	long double score;
public:
	Score();
	~Score();
	void add();											//LISAA TULOSTA
	void remove();										//VAHENTAA TULOSTA
	void reset();										//RESETOI TULOKSEN
	void update(sf::RenderWindow &, Text &, Status &);  //PÄIVITTÄÄ TULOKSEN TEKSTIN (SF:RENDERWINDOW osoite, Text luokan osoite, Status luokan osoite)
	void timer();										//VAHENTAA TULOSTA YHDELLA JOKA LOOPISSA
	long double get();									//PALAUTTAA TULOKSEN
	void save(Text &);									//TALLENTAA TULOKSEN JA ASETTAA LOPETUSTEKSTIN (Text luokan osoite)
};
#endif