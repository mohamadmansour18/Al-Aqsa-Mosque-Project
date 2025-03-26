#pragma once

#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Vector.h"

class Camera3D
{
public:
	Vector player , playerNew , camp;
	float theta , beta , dis;


	Camera3D()
	{
		dis = 0.4f;
		theta = 0;
		player.set(0,4,20);
	}

	void keyboard(bool keys[]) {
		if (keys['W']){
			moveF(dis);
		}
		if (keys['S'])
			moveF(-dis);
		if (keys['A'])
			moveR(-dis);
		if (keys['D'])
			moveR(dis);
		if (keys['E'])
			moveU(2*dis);
		if (keys['Q'])
			moveU(-2*dis);
		if (keys[VK_LEFT])
			theta += 0.02f;
		if (keys[VK_RIGHT])
			theta -= 0.02f;
		if (keys[VK_UP])
			beta += 0.003f;
		if (keys[VK_DOWN])
			beta -= 0.003f;
	}

	bool checkPos(Vector pos){
		if(pos.z < -195)
			return false;
		if(pos.z > 195)
			return false;
		if(pos.x < -95)
			return false;
		if(pos.x > 95)
			return false;
		if(pos.y < 4)
			return false;
		if(pos.y > 7)
			return false;
		
		//south rock arena
		if(pos.x > -38 && pos.x < -22 && pos.z < -8 && pos.z > -10)
			return false;
		if(pos.x > -12 && pos.x < 12 && pos.z < 10 && pos.z > -10)
			return false;
		if(pos.x > 22 && pos.x < 38 && pos.z < -8 && pos.z > -10)
			return false;

		//north rock arena
		if(pos.x > -38 && pos.x < 38 && pos.z < -90 && pos.z > -92)
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
		if(pos.x > -40 && pos.x < 40 && pos.z > -90 && pos.z < -10 && pos.y < 6 )
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
		float a,b;
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
		a= -cos (theta);
		b= -sin (theta);
		c = sin (beta);

		camp.x = player.x+b;
		camp.y = player.y+c;
		camp.z = player.z+a;

		gluLookAt(			
			camp.x,camp.y,camp.z,
			player.x,player.y,player.z,
			0,1,0);
	}
};

