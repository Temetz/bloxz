#ifndef statush
#define statush

class Status{
private:
	int status;
public:
	Status();
	~Status();
	int getstatus();		//PALAUTTAA STATUKSEN
	void setstatus(int);	//ASETTAA STATUKSEN (int status [0,1])
};

#endif