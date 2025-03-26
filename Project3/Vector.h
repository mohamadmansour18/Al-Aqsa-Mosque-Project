#pragma once
class Vector
{
public:

	float x , y , z ;

	Vector(float x=0 ,float y=0 ,float z=0)
	{
		this->x = x ;
		this->y = y ;
		this->z = z ;
	}

	void set(float x=0 ,float y=0 ,float z=0)
	{
		this->x = x ;
		this->y = y ;
		this->z = z ;
	}

};

