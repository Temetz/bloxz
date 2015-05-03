#include "status.h"	

/*OLETUS KONSTRUKTORI*/
Status::Status(){
	this->status = 0;					//OLETUKSENA MENUTILA (STATUS = 0)
										//PELITILA (STATUS = 1)
}

/*OLETUS DESTRUKTORI*/	
Status::~Status(){
}

/*PALAUTETAAN TAMANHETKINEN STATUS*/
int Status::getstatus(){
	return this->status;
}

/*ASETETAAN STATUS*/
void Status::setstatus(int status){
	this->status = status;
}