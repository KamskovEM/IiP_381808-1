#pragma once
#include "SongElement.h"

class Songs
{
private:
	int length; //Длина массива
	int rlength; //реальная длина массива
	int buf; //Буфер для добадвения новых элементов 
	SongElement* base;


public:
	Songs();
	~Songs();
};



