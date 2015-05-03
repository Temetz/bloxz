#ifndef musich
#define musich
#include "SFML\Audio.hpp"

class Music{
	sf::Music music[5];
public:
	Music();
	~Music();
	void play(int);    //SOITA AANI (AANIPANKIN ID)
	void pause(int);   //PYSAYTA AANI (AANIPANKIN ID)
};

#endif
