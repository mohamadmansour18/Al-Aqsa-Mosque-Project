#pragma once
#include <iostream>
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>
#include "Vector.h"
#include "Building.h"

using namespace std ;


class Camera
{
public:
	Vector player , playerNew , target ;

	float theta , beta  , dis ;

	bool free_room , keyE;

	Camera()
	{
		dis = 0.4f;
		theta = 0;
		free_room = false ;
		staris = false ;
		keyE = false ;
		player.set(0,3,20);
	}

	void keyboard(bool keys[]) {
		if (keys['W']){
			dis = 0.4;
			moveF(dis);
		}
		if (keys['S'])
			moveF(-dis);
		if (keys['A'])
			moveR(-dis);
		if (keys['D'])
			moveR(dis);
		if (keys['E'] && keyE == true)
			moveU(2*dis);
		if (keys['Q'])
			moveU(-2*dis);
		if (keys[VK_LEFT])
			theta += 0.02f;
		if (keys[VK_RIGHT])
			theta -= 0.02f;
		if (keys[VK_UP])
			beta += 0.004f;
		if (keys[VK_DOWN])
			beta -= 0.004f;
		if(keys[VK_SHIFT]){
			dis = 0.8 ;
			moveF(dis);
		}
		if(keys[VK_NUMPAD5]){
			free_room = true ;
			keyE = true ;
		}
		if(keys[VK_NUMPAD6] && free_room == true){
			player.set(0,3,20); 
			free_room = false ;
			keyE = false ;
		}
	}

	bool staris;
	bool checkPos(Vector pos){

		if(free_room == true){
			if(pos.x > 199 || pos.x < -199 || pos.z > 168 || pos.z < -168 || pos.y > 274 || pos.y < -115 )
				return false ;
			return true ;
		}

		if(pos.z < -195)
			return false;
		if(pos.z > 195)
			return false;
		if(pos.x < -95)
			return false;
		if(pos.x > 95)
			return false;
		if(pos.y < 3)
			return false;
		if(pos.y > 7 )
			return false;
		
		//south rock arena
		if(pos.x > -38 && pos.x < -22 && pos.z < -8 && pos.z > -10)
			return false;
		if(pos.x > -12 && pos.x < 12 && pos.z < 10 && pos.z > -10)
			return false;
		if(pos.x > 22 && pos.x < 38 && pos.z < -8 && pos.z > -10)
			return false;

		//north rock arena
		if(pos.x > -40.4 && pos.x < 40.4 && pos.z < -90 && pos.z > -93)
			return false;
		
		//west rock arena
		if(pos.x > -57 && pos.x < -37 && pos.z < -5 && pos.z > -45)
			return false;
		if(pos.x > -57 && pos.x < -37 && pos.z > -90 && pos.z < -55)
			return false;
		
		//east rock arena
		if(pos.x < 57 && pos.x > 37 && pos.z < -5 && pos.z > -45)
			return false;
		if(pos.x < 57 && pos.x > 37 && pos.z > -90 && pos.z < -55)
			return false;

		//all arena
		if(pos.x > -43.5 && pos.x < 43.5 && pos.z > -90 && pos.z < -6.5 && pos.y < 6 )
			return false;
		

		//alqibli by parts 

		//part 8
		if(pos.x < -85 && pos.x > -95 && pos.z > 98 && pos.z < 172)
			return false;

		//part 2
		if(pos.x < -26 && pos.x > -85 && pos.z < 180 && pos.z > 170)
			return false;

		//part 1 west
		if(pos.x > -27 && pos.x < -25 && pos.z < 195 && pos.z > 90)
			return false;

		//part 1 east
		if(pos.x > 9 && pos.x < 11 && pos.z < 195 && pos.z > 90)
			return false;

		//part 1 north
		if(pos.x > -27 && pos.x < -10 && pos.z > 90 && pos.z < 105)
			return false;
		if(pos.x > -5 && pos.x < 11 && pos.z > 90 && pos.z < 105)
			return false;

		//part 6 + 7
		if(pos.x > 11 && pos.x < 18 && pos.z < 190 && pos.z > 160)
			return false;

		//part 5
		if(pos.x > 18 && pos.x < 36 && pos.z < 195 && pos.z > 188)
			return false;

		//garden
		if((pos.x > 25 && pos.x < 53 || pos.x > 57 && pos.x < 86) && pos.z < 108 && pos.z > 101)
			return false;

		if((pos.x > 21 && pos.x < 53 || pos.x > 57 && pos.x < 86) && pos.z < 168 && pos.z > 162)
			return false;

		if(pos.x > 81 && pos.x < 88  && ( pos.z < 133 && pos.z > 105 || pos.z < 162  && pos.z > 136.5) )
			return false;

		if(pos.x > 21 && pos.x < 27  && ( pos.z < 133 && pos.z > 105 || pos.z < 162  && pos.z > 136.5) )
			return false;

			//fortain
			if(pos.x > 46 && pos.x < 63.8 && pos.z < 144 && pos.z > 126)
				return false;

			//abo obeda
			if(pos.x > 30.5 && pos.x < 39.7 && pos.z < 159 && pos.z > 148)
				return false;

			//sitting 1
			if(pos.x > 27 && pos.x < 42 && pos.z < 121 && pos.z > 108)
				return false;

			//sitting 2
			if(pos.x > 68 && pos.x < 80 && pos.z < 161 && pos.z > 147)
				return false;

		//staris

		//1
		if(pos.x > 12 && pos.x < 22 && pos.z < 0.3 && pos.z > -1 && staris == false){
			player.set(17,6.4,-8);
			staris = true ;
			keyE = true ;
			return false ;
		}
		if(pos.x > 12 && pos.x < 22 && pos.z < 2 && pos.z > 0){
			staris = false ;
			keyE = false ;
		}

		//2
		if(pos.x > -21 && pos.x < -13 && pos.z < 0.3 && pos.z > -1 && staris == false){
			player.set(-17 , 6.4 , -8);
			staris = true ;
			keyE = true ;
			return false ;
		}
		if(pos.x > -21 && pos.x < -13 && pos.z < 2 && pos.z > 0){
			staris = false ;
			keyE = false ;
		}

		//3
		if(pos.x > -46 && pos.x < -45 && pos.z < -45 && pos.z > -54 && staris == false){
			player.set(-41 , 6.4 , -50.2);
			staris = true ;
			keyE = true ;
			return false ;
		}
		if(pos.x > -56 && pos.x < -55 && pos.z < -45 && pos.z > -54){
			staris = false ;
			keyE = false ;
		}

		//4
		if(pos.x > 47 && pos.x < 48 && pos.z < -45 && pos.z > -54 && staris == false){
			player.set(39.8 , 6.4 , -50.2);
			staris = true ;
			keyE = true ;
			return false ;
		}
		if(pos.x > 54 && pos.x < 55 && pos.z < -45 && pos.z > -54){
			staris = false ;
			keyE = false ;
		}

		//part1

			//sour
			if(pos.x > 58 && pos.x < 94 && pos.z < -122 && pos.z > -127)
				return false;
			if(pos.x > 38 && pos.x < 50 && pos.z < -122 && pos.z > -127)
				return false;

			//sour 2
			if(pos.x > 37 && pos.x < 42 && pos.z < -127 && pos.z > -141)
				return false;
			if(pos.x > 37 && pos.x < 42 && pos.z < -149 && pos.z > -195)
				return false;

			//house 1
			if(pos.x > 47 && pos.x < 81.5 && pos.z < -171.2 && pos.z > -188.3)
				return false;
			//house 2
			if(pos.x > 80.8 && pos.x < 95 && pos.z < -137 && pos.z > -167)
				return false;

		return true;

	}

	

	void moveU(float d){
		playerNew.x = player.x ;
		playerNew.y = player.y + d;
		playerNew.z = player.z ;

		if(checkPos(playerNew))
			player = playerNew;
	}

	void moveF(float d){
		float a,b,c;
		a= d*cos (theta);
		b= d*sin (theta);

		playerNew.x = player.x + b;
		playerNew.y = player.y ;
		playerNew.z = player.z + a;

		if(checkPos(playerNew))
			player = playerNew;

	}

	void moveR(float d){
		float a,b;
		a= d*cos (theta - 3.14/2);
		b= d*sin (theta - 3.14/2);

		playerNew.x = player.x + b;
		playerNew.y = player.y ;
		playerNew.z = player.z + a ;

		if(checkPos(playerNew))
			player = playerNew;
	}

	void render(){
		float a,b,c;
		a = cos (theta);
		b = sin (theta);
		c = sin (beta);

			target.x = player.x + b;
			target.y = player.y + c ;
			target.z = player.z + a;


		cout <<	"x is :     "<<player.x<<	"     y is :     "<<player.y<<"     z is :     "<<player.z<<endl;


		gluLookAt(
			player.x,player.y,player.z,
			target.x,target.y,target.z,
			0,1,0);
	}
	
};

