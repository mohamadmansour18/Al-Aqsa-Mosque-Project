#pragma once
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include "Shapes.h"
#include "Camera.h"
#include "Model_3DS.h"
#include "3DTexture.h"

class Building
{
public:

	Shapes s1 ;
	Model_3DS *bird , *tree ;

	float doorX1 , doorX2 , doorX1a , doorX2a; 
	float xr ;
	int  doorOpenState , doorOpenState1 ;


	Building()
	{
		doorX1 = 0.0f ;
		doorX2 = 0.0f ;
		doorOpenState = 0.0f ;

		doorX1a = 0.0f ;
		doorX2a = 0.0f ;
		doorOpenState1 = 0 ;

		xr = 0.0f ; 
	}

	int  img0 , img1 , img2 , img3 , img4 , img5 , img6 , img7 , img8 , img9 , img10 , img11 , img12 , img13 , img14 , img15 , img16 , img17 , img18 , img19 , img20 , img21 ,img22;
	int	 im0 , im1 , im2 , im3 , im4 , im5 , im6 , im7 , im8 , im9 , im10 , im11 , im12 , im13 , im14 , im15 , im16 , im17 , im18 , im19 , im20 ;
	int sign1,sign2,sign3,sign4,sign5,sign6,sign7,sign8,sign9,sign10,sign11,sign12;

	void LoadT(){

		img0=LoadTexture("texture//2.bmp",255); 
		img1=LoadTexture("texture//wall1.bmp",255);
		img2=LoadTexture("texture//cil.bmp",255);
		img3=LoadTexture("texture//dump.bmp",255);
		img4=LoadTexture("texture//mans.bmp",255);
		img5=LoadTexture("texture//cilynd3.bmp",255);  
		img6=LoadTexture("texture//gold.bmp",255);
		img7=LoadTexture("texture//ground3.bmp",255);
		img8=LoadTexture("texture//ccc.bmp",255);
		img9=LoadTexture("texture//ground4.bmp",255);
		img10=LoadTexture("texture//sign.bmp",255);
		img11=LoadTexture("texture//cccd.bmp",255);
		img12=LoadTexture("texture//ground.bmp",255);
		img13=LoadTexture("texture//obeda.bmp",255);
		img14=LoadTexture("texture//wall.bmp",255);
		img15=LoadTexture("texture//chair.bmp",255);
		img16=LoadTexture("texture//cilynd6.bmp",255);
		img17=LoadTexture("texture//cilynd5.bmp",255); 
		img18=LoadTexture("texture//door.bmp",255); 
		img19=LoadTexture("texture//water.bmp",255); 
		img20=LoadTexture("texture//garden2.bmp",255); 
		img21=LoadTexture("texture//garden.bmp",255); 
		img22=LoadTexture("texture//wanted.bmp",255);

		////
		im0=LoadTexture("texture//main2.bmp",255);
		im1=LoadTexture("texture//main.bmp",255);
		im2=LoadTexture("texture//tex2.bmp",255);
		im3=LoadTexture("texture//tex3.bmp",255);
		im4=LoadTexture("texture//tex4.bmp",255);
		im5=LoadTexture("texture//entry.bmp",255);
		im6=LoadTexture("texture//tex6.bmp",255);
		im7=LoadTexture("texture//tex7.bmp",255);
		im8=LoadTexture("texture//tex8.bmp",255);
		im9=LoadTexture("texture//tex9.bmp",255);
		im10=LoadTexture("texture//green.bmp",255);
		//im11=LoadTexture("texture//tex11.bmp",255);
		im12=LoadTexture("texture//tex12.bmp",255);
		im13=LoadTexture("texture//tex13.bmp",255);
		im14=LoadTexture("texture//tex14.bmp",255);
		im15=LoadTexture("texture//tex15.bmp",255);
		im16=LoadTexture("texture//tex16.bmp",255);
		im17=LoadTexture("texture//tex17.bmp",255);
		//im18=LoadTexture("texture//tex18.bmp",255);
		//im19=LoadTexture("texture//tex19.bmp",255);
		//im20=LoadTexture("texture//tex20.bmp",255);

		/////
		sign1 =	LoadTexture("texture//sign1.bmp",255);
		sign2 =	LoadTexture("texture//sign2.bmp",255);
		sign3 =	LoadTexture("texture//sign3.bmp",255);
		sign4 =	LoadTexture("texture//sign4.bmp",255);
		sign5 =	LoadTexture("texture//sign5.bmp",255);
		sign6 =	LoadTexture("texture//sign6.bmp",255);
		sign7 =	LoadTexture("texture//sign7.bmp",255);
		sign8 =	LoadTexture("texture//sign8.bmp",255);
		sign9 =	LoadTexture("texture//sign9.bmp",255);
		sign10=	LoadTexture("texture//sign10.bmp",255);
		sign11=	LoadTexture("texture//sign11.bmp",255);
		sign12=	LoadTexture("texture//sign12.bmp",255);

	//load bird 3D model
	bird = new Model_3DS();
    bird->Load("models//GULL.3DS");

	GLTexture texBird;
	texBird.LoadBMP("texture//bird.bmp");
	bird->Materials[0].tex = texBird;
	bird->Materials[1].tex = texBird;
	bird->Materials[2].tex = texBird;

	bird->pos.x = 0;
	bird->pos.y = 0;
	bird->pos.z = 20;
	bird->scale = 10;

	//load tree 3D model
	tree = new Model_3DS();
    tree->Load("models//tree.3DS");

	GLTexture textree;
	textree.LoadBMP("texture//trunk.bmp");
	tree->Materials[0].tex = textree;
	textree.LoadBMP("texture//leaf3.bmp");
	tree->Materials[1].tex = textree;
	tree->scale = 0.25 ;
	}

	////////////////////////////////////....< all >....///////////////////////////////////
	void all(bool keys[]){

		//mosuq
		glPushMatrix();
			glTranslated(0,4,-50);
			glRotated(180 , 0 , 1 ,0);
			Rock_dome_with_arena(keys);
		glPopMatrix();
		 
		//alqibli
		glPushMatrix();
			glTranslated(-8 , 0 , 150);
			glRotated(180 , 0 , 1 , 0);
			glScaled(1.5 , 1.5 , 2);
			alqibli(keys);
		glPopMatrix();

		//birds
		glPushMatrix();
			glTranslated(0 , -25 , -55);
			draw_birds();
		glPopMatrix();
	}

	void all_with_list(){

		//wall
		glPushMatrix();
			aqsa_wall();
		glPopMatrix();

		//garden
		glPushMatrix();
			glTranslated(55 , 0 , 135);
			garden();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0 , 0 , -145);
			garden();
		glPopMatrix(); 

		//house

		//1
		glPushMatrix();
			part1();
		glPopMatrix();

		//2
		glPushMatrix();
			part2();
		glPopMatrix();

		//model
		glPushMatrix();
			draw_tree_in_arena();
		glPopMatrix();
	}

	////////////////////////////////////....< on the patch >....///////////////////////////////////
	void Rock_dome_with_arena(bool keys[]){		

		glPushMatrix();
			glScaled(0.8 , 0.8 , 0.8);
			Rock_dome(keys);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.5 , 0.5 , 0.5);
			arena_aqsa();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-4.03,-50);
			glRotated(90 , 1 , 0 , 0);
			s1.QuadTexture(200 , 100 , im1 , 5 ,10);
		glPopMatrix();
	}

	void main_house(){

		glPushMatrix();
			glScaled(1.3 , 1 , 1.8);
			s1.Cube3TextureWithDoor(5 , 5 , img14 , img4 , 63 , 59 , 50 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-10.8,9.85,0);
			glScaled(2.7,1,1.2);
			s1.Cube(0.1 , 8 , 80 , 0 , 0 );
		glPopMatrix();

		//1
		glPushMatrix();
			glTranslated(8.2 , 0 , 9);
			s1.CylinderTexture(0.5 , 10 , img9);
		glPopMatrix();

			glPushMatrix();
				glTranslated(8.2 , 0 , 9);
				glScaled(1.7 , 1.7 , 1.6);
				s1.Castle_cube(1 , 1 , 1);
			glPopMatrix();


		//2
		glPushMatrix();
			glTranslated(8.2 , 0 , -9);
			s1.CylinderTexture(0.5 , 10 , img9);
		glPopMatrix();

			glPushMatrix();
				glTranslated(8.2 , 0 , -9);
				glScaled(1.7 , 1.7 , 1.6);
				s1.Castle_cube(1 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(8.2 , 9.8 , -9);
				glRotated(180,0,0,1);
				glScaled(1.7 , 1.7 , 1.6);
				s1.Castle_cube(1 , 1 , 1);
			glPopMatrix();



		//3
		glPushMatrix();
			glTranslated(-8 , 0 , 7);
			s1.CylinderTexture(0.5 , 10 , img9);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-8 , 0 , 7);
				glScaled(1.7 , 1.7 , 1.6);
				s1.Castle_cube(1 , 1 , 1);
			glPopMatrix();


		//4 
		glPushMatrix();
			glTranslated(-8 , 0 , -7);
			s1.CylinderTexture(0.5 , 10 , img9);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-8 , 0 , -7);
				glScaled(1.7 , 1.7 , 1.6);
				s1.Castle_cube(1 , 1 , 1);
			glPopMatrix();

		//5
		glPushMatrix();
			glTranslated(-31.2 , 0 , -9);
			s1.CylinderTexture(0.5 , 10 , img9);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-31.2 , 0 , -9);
				glScaled(1.7 , 1.7 , 1.6);
				s1.Castle_cube(1 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-31.2 , 9.8 , -9);
				glRotated(180,0,0,1);
				glScaled(1.7 , 1.7 , 1.6);
				s1.Castle_cube(1 , 1 , 1);
			glPopMatrix();

		//6
		glPushMatrix();
			glTranslated(-31.2 , 0 , 9);
			s1.CylinderTexture(0.5 , 10 , img9);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-31.2 , 0 , 9);
				glScaled(1.7 , 1.7 , 1.6);
				s1.Castle_cube(1 , 1 , 1);
			glPopMatrix();

		///////

		glPushMatrix();
			glScaled(1 , 1 , 1.2);
			main_roof(img3 , img2 );
		glPopMatrix();
		
		///////...<chimney>.../////////
		glPushMatrix();
			glTranslated(4.25,11.9,-2.2);
			s1.Cube(2.5 , 1.5 , 134 , 24 , 24);
		glPopMatrix();

		glPushMatrix();
			glTranslated(4.25 , 16.5 ,-2.2);
			s1.Cube(0.15 , 1.65 , 20 , 20 , 20);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -18.55 , 0 , 0);
			glRotated(180 , 0 , 1 , 0);
			glScaled(2,1,1);
			s1.CubeTexture( 5 , 6 , img14 , 1 , 1 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(-16.5 , 0 , 0);
			glRotated(90 , 0 , 1 ,0 );
			glScaled(0.5 , 1 , 2);
			main_roof(img3 , img2 );
		glPopMatrix();

		for(int i=2 ; i<=42 ; i+=2){
			glPushMatrix();
			glTranslated( i - 32.8 , 9.8 , -8.7);
			glRotated(180 , 0 , 0 , 1);
			glScaled(3,2,1);
				s1.Castle_cube2( 63 , 59 , 50 );
			glPopMatrix();
		}

		for(int i=2 ; i<=42 ; i+=2){
			glPushMatrix();
			glTranslated( i - 32.8 , 9.8 , 8.7);
			glRotated(180 , 0 , 0 , 1);
			glScaled(3,2,1);
				s1.Castle_cube2( 63 , 59 , 50 );
			glPopMatrix();
		}

		for(int i=0 ; i<=16 ; i+=3){
			 glPushMatrix();
			 glTranslated(10.5 , 9.8 , i-7.5);
				glRotated(90,0,1,0);
				glRotated(180 , 0 , 0 , 1);
				glScaled(3,2,1);
				s1.Castle_cube2(63 , 59 , 50);
			glPopMatrix();
		}

		for(int i=0 ; i<=16 ; i+=3){
			 glPushMatrix();
			 glTranslated(-32 , 9.8 , i-7.5);
				glRotated(90,0,1,0);
				glRotated(180 , 0 , 0 , 1);
				glScaled(3,2,1);
				s1.Castle_cube2(63 , 59 , 50);
			glPopMatrix();
		}

			glPushMatrix();
			glTranslated(-1.28,0,-9);
				glScaled(12.9 , 1 , 1);
				glRotated(180 , 0 , 1 , 0);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(1.28,0,-9);
				glRotated(180 , 0 , 1 , 0);
				glScaled(12.9 , 1 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			//door edges
			glPushMatrix();
				glTranslated(0,5,-9.2);
				glScaled(1.38,1,0.1);
				s1.Cube(0.1 , 3 , 63 , 59 , 50);
			glPopMatrix();

	}

	void sub_house(){

		glPushMatrix();
			glTranslated(0,5,0);
			s1.CubeTexture(0.2 , 16 , img2 , 1 , 1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(0 , 5.5 , 0);
			s1.Cube3TextureWithDoor(5.1 , 10 , img16 , img4 , 60 , 60 ,60 , 1 , 1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,15.8,0);
			glScaled(1.2 , 1 ,1);
			s1.CubeTexture(0.2 , 14 , img2 , 1 , 1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(8.8 , 9.8 , 0);
			glScaled(0.6 , 0.6 , 2);
			main_roof(img17 , img2);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(2 , 4 , 0);
			glScaled(1.1 , 1.3 , 1.5);
			main_roof(img17 , img2);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-2 , 4 , 0);
			glRotated(90 , 0 , 1 , 0);
			glScaled(1 , 1.3 , 1.5);
			main_roof(img17 , img2);			
		glPopMatrix();

		for(float i = 0 ; i<=16 ; i+=4){
			glPushMatrix();
			glTranslated(8-i,0,-15);
			s1.CylinderTexture(0.5 , 8 , img9);	
			glPopMatrix();
		}

			//red
			for(float i = 0 ; i<=16 ; i+=4){
				glPushMatrix();
				glTranslated(8-i,15,-10);
				glRotated(180 , 0 , 0 , 1);
				glScaled(3,3,1);
				s1.Castle_cube(92,48,39);	
				glPopMatrix();
			}
			//red
			for(float i = 0 ; i<=16 ; i+=4){
				glPushMatrix();
				glTranslated(8-i,12.6,-10);
				glScaled(3,3,1);
				s1.Castle_cube(92,48,39);	
				glPopMatrix();
			}

		for(float i = 0 ; i<=30 ; i+=4){
			glPushMatrix();
			glTranslated(14-i,0,15);
			s1.CylinderTexture(0.5 , 8 , img9);	
			glPopMatrix();
		}

		for(float i = 0 ; i<=30 ; i+=4){
			glPushMatrix();
			glTranslated(15 , 0 , 13-i);
			s1.CylinderTexture(0.5 , 8 , img9);	
			glPopMatrix();
		}

		for(float i = 0 ; i<=30 ; i+=4){
			glPushMatrix();
			glTranslated(-15 , 0 , 13-i);
			s1.CylinderTexture(0.5 , 8 , img9);	
			glPopMatrix();
		}

		glPushMatrix();
			glTranslated(0 , 8 ,-15);
			glScaled(18,1,1);
			s1.CubeTexture(0.2 , 0.5 , img2 , 1 , 1 );	
		glPopMatrix();

		glPushMatrix();
			glTranslated(0 , 8 ,15);
			glScaled(32,1,1);
			s1.CubeTexture(0.2 , 0.5 , img2 , 1 , 1 );	
		glPopMatrix();

		glPushMatrix();
			glTranslated(15 , 8 ,0);
			glRotated(90 , 0 , 1 , 0);
			glScaled(32,1,1);
			s1.CubeTexture(0.2 , 0.5 , img2 , 1 , 1 );	
		glPopMatrix();

		glPushMatrix();
			glTranslated(-15 , 8 ,0);
			glRotated(90 , 0 , 1 , 0);
			glScaled(32,1,1);
			s1.CubeTexture(0.2 , 0.5 , img2 , 1 , 1 );	
		glPopMatrix();

		//staris
		glPushMatrix();
		glTranslated(-11.6 , 0 , -15);
		glScaled(0.33 , 0.65 , 0.7);
			s1.staries(img2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(11.6 , 0 , -15);
		glScaled(0.33 , 0.65 , 0.7);
			s1.staries(img2);
		glPopMatrix();

		//shemany
		glPushMatrix();
			glTranslated(4.25,22.9,-2.2);
			s1.Cube(2.5 , 1.5 , 134 , 24 , 24);
		glPopMatrix();

		glPushMatrix();
			glTranslated(4.25 , 27.5 ,-2.4);
			s1.Cube(0.15 , 1.65 , 20 , 20 , 20);
		glPopMatrix();

		//door

			glPushMatrix();
			glTranslated(-2 , 5.5 , -10);
				glScaled(20 , 1.05 , 1.5);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(2 , 5.5 , -10);
				glScaled(20 , 1.05 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();
	}

	void third_house(){
		glPushMatrix();
		glTranslated(41 , 0 , 0);
			main_house();
		glPopMatrix();

		glPushMatrix();
			sub_house();
		glPopMatrix();
	}

	void garden(){
		glPushMatrix();
			glRotated(90,1,0,0);
			s1.QuadTexture(30,30,img20,4,4);		
		glPopMatrix();

		glPushMatrix();
			glScaled(1.5 , 1.5 , 1.5);
			fountain();			
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,0.01,0);
		glRotated(90 , 1 , 0 , 0);
			s1.QuadTexture(3 , 30 , img21 , 10 , 1);			
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,0.01,0);
		glRotated(90 , 1 , 0 , 0);
		glRotated(90 , 0 , 0 ,1);
			s1.QuadTexture(3 , 30 , img21 , 10 ,1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(0 , 0.015 , 0);
			glRotated(90 , 1 , 0 , 0);
			s1.QuadTexture(6 , 6 , img0 , 1 , 1);			
		glPopMatrix();



		//windows
		glPushMatrix();
			glTranslated(0 , 29.5 , 6);
			glRotated(90 , 1 , 0 , 0);
			s1.window(1,6,1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(0 , 29.5 , -6);
			glRotated(90 , 1 , 0 , 0);
			s1.window(1,6,1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(6 , 29.5 , 0);
			glRotated(90 , 1 , 0 , 0);
			glRotated(90 , 0 , 0 , 1);
			s1.window(1,6,1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-6 , 29.5 , 0);
			glRotated(90 , 1 , 0 , 0);
			glRotated(90 , 0 , 0 , 1);
			s1.window(1,6,1);			
		glPopMatrix();


		//wall
		//1
		glPushMatrix();
			glTranslated(10,0,30);
			garden_wall();			
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(22,0,30);
			garden_wall();			
		glPopMatrix();
		//2
		glPushMatrix();
			glTranslated(-10,0,30);
			garden_wall();			
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(-22,0,30);
			garden_wall();			
		glPopMatrix();
		//3
		glPushMatrix();
			glTranslated(10,0,-30);
			garden_wall();			
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(22,0,-30);
			garden_wall();			
		glPopMatrix();
		//4
		glPushMatrix();
			glTranslated(-10,0,-30);
			garden_wall();			
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(-22,0,-30);
			garden_wall();			
		glPopMatrix();
		//5
		glPushMatrix();
			glTranslated(-30,0,-10);
			glRotated(90 , 0 , 1 , 0);
			garden_wall();			
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(-30,0,-22);
			glRotated(90 , 0 , 1 , 0);
			garden_wall();			
		glPopMatrix();
		//6
		glPushMatrix();
			glTranslated(30,0,10);
			glRotated(90 , 0 , 1 , 0);
			garden_wall();			
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(30,0,22);
			glRotated(90 , 0 , 1 , 0);
			garden_wall();			
		glPopMatrix();
		//7
		glPushMatrix();
			glTranslated(-30,0,10);
			glRotated(90 , 0 , 1 , 0);
			garden_wall();			
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(-30,0,22);
			glRotated(90 , 0 , 1 , 0);
			garden_wall();			
		glPopMatrix();
		//8
		glPushMatrix();
			glTranslated(30,0,-10);
			glRotated(90 , 0 , 1 , 0);
			garden_wall();			
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(30,0,-22);
			glRotated(90 , 0 , 1 , 0);
			garden_wall();			
		glPopMatrix();

		//charis

		//first entry
		glPushMatrix();
			glTranslated(3,0,13);
			glRotated(90 , 0 , 1 , 0);
			glScaled(1.5,1.5,1.5);
			chair();			
		glPopMatrix();

			glPushMatrix();
				glTranslated(2.3,0,30);
				glRotated(90 , 0 , 1 , 0);
				garden_lights();			
			glPopMatrix();

			glPushMatrix();
				glTranslated(-2.3,0,30);
				glRotated(90 , 0 , 1 , 0);
				garden_lights();			
			glPopMatrix();

		glPushMatrix();
			glTranslated(-3,0,23);
			glRotated(-90 , 0 , 1 , 0);
			glScaled(1.5,1.5,1.5);
			chair();			
		glPopMatrix();

		//second entry
		glPushMatrix();
			glTranslated(3,0,-13);
			glRotated(90 , 0 , 1 , 0);
			glScaled(1.5,1.5,1.5);
			chair();			
		glPopMatrix();

			glPushMatrix();
				glTranslated(2.3,0,-30);
				glRotated(-90 , 0 , 1 , 0);
				garden_lights();			
			glPopMatrix();

			glPushMatrix();
				glTranslated(-2.3,0,-30);
				glRotated(-90 , 0 , 1 , 0);
				garden_lights();			
			glPopMatrix();

		glPushMatrix();
			glTranslated(-3,0,-23);
			glRotated(-90 , 0 , 1 , 0);
			glScaled(1.5,1.5,1.5);
			chair();			
		glPopMatrix();

		//thired entry
		glPushMatrix();
			glTranslated(-13,0,3);
			glScaled(1.5,1.5,1.5);
			chair();			
		glPopMatrix();

			glPushMatrix();
				glTranslated(-30,0,2.3);
				garden_lights();			
			glPopMatrix();

			glPushMatrix();
				glTranslated(-30,0,-2.3);
				garden_lights();			
			glPopMatrix();

		glPushMatrix();
			glTranslated(-23,0,-3);
			glScaled(1.5,1.5,1.5);
			glRotated(180 , 0 , 1 , 0);
			chair();			
		glPopMatrix();	

		//forth entry
		glPushMatrix();
			glTranslated(13,0,3);
			glScaled(1.5,1.5,1.5);
			chair();			
		glPopMatrix();

			glPushMatrix();
				glTranslated(30,0,2.3);
				glRotated(180 , 0 , 1 , 0);
				garden_lights();			
			glPopMatrix();

			glPushMatrix();
				glTranslated(30,0,-2.3);
				glRotated(180 , 0 , 1 , 0);
				garden_lights();			
			glPopMatrix();

		glPushMatrix();
			glTranslated(23,0,-3);
			glScaled(1.5,1.5,1.5);
			glRotated(180 , 0 , 1 , 0);
			chair();			
		glPopMatrix();	

		//angle

		//1
		glPushMatrix();
			glTranslated(20 , 1.4 , 20);
			s1.CubeTexture(0.2 , 5 , img16 , 1, 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(15 , -1 , 20);
			glScaled(0.8 , 0.8 , 0.8);
			s1.roof_tringle(img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(20 , -1 , 15);
			glRotated(90,0,1,0);
			glScaled(0.8 , 0.8 , 0.8);
			s1.roof_tringle(img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(19 , 1.7 , 24);
			glScaled(1.5,1.5,1.5);
			chair();			
		glPopMatrix();

		glPushMatrix();
			glTranslated(24 , 1.7 , 19);
			glScaled(1.5,1.5,1.5);
			glRotated(90 , 0 , 1 , 0);
			chair();			
		glPopMatrix();	

		glPushMatrix();
			glTranslated(23 , 1.8 , 23);
			glRotated(-45 , 0 , 1 , 0);
			garden_lights();			
		glPopMatrix();

		//2
		glPushMatrix();
			glTranslated(-20 , 1.4 , -20);
			s1.CubeTexture(0.2 , 5 , img16 , 1, 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-15 , -1 , -20);
			glScaled(0.8 , 0.8 , 0.8);
			s1.roof_tringle(img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-20 , -1 , -15);
			glRotated(-90,0,1,0);
			glScaled(0.8 , 0.8 , 0.8);
			s1.roof_tringle(img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-19 , 1.7 , -24);
			glRotated(180 , 0 , 1 , 0);
			glScaled(1.5,1.5,1.5);
			chair();			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-24 , 1.7 , -19);
			glScaled(1.5,1.5,1.5);
			glRotated(-90 , 0 , 1 , 0);
			chair();			
		glPopMatrix();	

		glPushMatrix();
			glTranslated(-23 , 1.8 , -23);
			glRotated(125 , 0 , 1 , 0);
			garden_lights();			
		glPopMatrix();

		//3
		glPushMatrix();
			glTranslated(-20 , 1 , 20);
			glRotated(-45 , 0 , 1 , 0);
			glRotated(180,1,0,0);
			glScaled(5,1,1);
			s1.prymid(50,50,50);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-18 , 1 , 23);
			glRotated(225 , 0 , 1 , 0);
			garden_lights();			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-23 , 1 , 18);
			glRotated(225 , 0 , 1 , 0);
			garden_lights();			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-20 , 3 , 20);
			glRotated(-45,0,1,0);
			s1.QuadTexture(2 , 4 , img22 , 1 , 1);			
		glPopMatrix();

	}

	void part1(){
		glPushMatrix();
			glTranslated(55,0,-180);
			glRotated(180 , 0 , 1 , 0);
			glScaled(0.8 , 0.8 , 0.8);
			main_house();
		glPopMatrix();

		glPushMatrix();
			glTranslated(90,0,-160);
			glRotated(90 , 0 , 1 , 0);
			glScaled(0.7 , 0.7 , 0.7);
			main_house();
		glPopMatrix();

		glPushMatrix();
			glTranslated(60,0,-145);
			glScaled(1.2 , 1.2 , 1.2);
			small_dump(img9 , img2 , img3 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(70,-0.01,-165);
			glRotated(90,1,0,0);
			s1.QuadTexture(40,30,im5,5,5);
		glPopMatrix();

		glPushMatrix();
			glTranslated(40,2,-178);
			glRotated(180,0,1,0);
			glScaled(0.05 , 1 , 2);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(40,0,-178);
			glRotated(180,0,1,0);
			glScaled(0.05 , 1 , 2);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

			glPushMatrix();
				glTranslated(40,0,-150.2);
				s1.CylinderTexture(0.8 , 6 ,img17 );
			glPopMatrix();

			glPushMatrix();
				glTranslated(40,0,-140);
				s1.CylinderTexture(0.8 , 6 ,img17 );
			glPopMatrix();

		glPushMatrix();
			glTranslated(40,2,-132.6);
			glRotated(180,0,1,0);
			glScaled(0.05 , 1 , 0.55);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(40,0,-132.6);
			glRotated(180,0,1,0);
			glScaled(0.05 , 1 , 0.55);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(45,2,-125.5);
			glRotated(90,0,1,0);
			glScaled(0.05 , 1 , 0.40);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(45,0,-125.5);
			glRotated(90,0,1,0);
			glScaled(0.05 , 1 , 0.40);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

			glPushMatrix();
				glTranslated(50,0,-125.6);
				s1.CylinderTexture(0.8 , 6 ,img17 );
			glPopMatrix();

			glPushMatrix();
				glTranslated(60,0,-125.6);
				s1.CylinderTexture(0.8 , 6 ,img17 );
			glPopMatrix();

		glPushMatrix();
			glTranslated(80.4,2,-125.5);
			glRotated(90,0,1,0);
			glScaled(0.05 , 1 , 1.5);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(80.4,0,-125.5);
			glRotated(90,0,1,0);
			glScaled(0.05 , 1 , 1.5);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();
	}

	void part2(){
		glPushMatrix();
			glTranslated(-60,0,-125);
			glScaled(0.8 , 0.8 , 0.8);
			main_house();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-90,0,-155);
			glRotated(-90 , 0 , 1 , 0);
			glScaled(0.7 , 0.7 , 0.7);
			main_house();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-55,0,-185);
			glRotated(180 , 0 , 1 , 0);
			glScaled(0.7 , 0.7 , 0.7);
			sub_house();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-70,-0.01,-155);
			glRotated(90,1,0,0);
			s1.QuadTexture(45,30,im5,2,6);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-40,2,-178);
			glRotated(180,0,1,0);
			glScaled(0.05 , 1 , 2);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-40,0,-178);
			glRotated(180,0,1,0);
			glScaled(0.05 , 1 , 2);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-40,0,-150.2);
				s1.CylinderTexture(0.8 , 6 ,img17 );
			glPopMatrix();

			glPushMatrix();
				glTranslated(-40,0,-140);
				s1.CylinderTexture(0.8 , 6 ,img17 );
			glPopMatrix();

		glPushMatrix();
			glTranslated(-40,2,-125);
			glRotated(180,0,1,0);
			glScaled(0.05 , 1 , 1.1);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-40,0,-125);
			glRotated(180,0,1,0);
			glScaled(0.05 , 1 , 1.1);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-70.2,2,-110);
			glRotated(90,0,1,0);
			glScaled(0.05 , 1 , 2.2);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-70.2,0,-110);
			glRotated(90,0,1,0);
			glScaled(0.05 , 1 , 2.2);
			s1.Cube(0.1 , 14 , 63 , 59 , 50);
		glPopMatrix();
	}


	////////////////////////////////////....< all parts of rock dome >....///////////////////////////////////
	void Rock_dome(bool keys[]){

		/////////////////////////...< External structure for the mosuq >.../////////////////////////
		glPushMatrix();
			s1.OctagonTextureWithDoor(img8 , 80 , 80 , 80);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,10,0);
			glRotated(90,0,1,0);
			s1.CylinderTexture(9,5,img11);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,15,0);
			s1.OctagonTexture(3.8,0.5,img2 ,60 ,60 ,60);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,10.1,0);
			s1.OctagonTexture(6.5,0.5,img2 , 60 , 60 , 60);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,0.009,0);
			s1.OctagonT1(9,9,img5);
		glPopMatrix();
		/////////////////////////...< end structure for the mosuq >.../////////////////////////


		/////////////////////////...< External structure for the dome >.../////////////////////////
		glPushMatrix();
			glTranslated(0,15.5,0);
			s1.HalfSphareTexture(8.5,img6);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0 , 25 , 0);
			s1.SphareTexture(1 , img6);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0 , 26.5 , 0);
			s1.SphareTexture(0.5 , img6);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.3 , 29.8 , -0.5);
			glRotated(-135 , 0 , 0 , 1);
			s1.qantara(253 , 201 , 56);
		glPopMatrix();
	
		/////////////////////////...< end structure for the dome >.../////////////////////////


		/////////////////////////...< External structure for the cylinder >.../////////////////////////
		glPushMatrix();
			glTranslated(6 , 0 , 6*2.41421356);
			s1.CylinderTexture(1 , 10 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-6 , 0 , 6*2.41421356);
			s1.CylinderTexture(1 , 10 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 6*2.41421356 , 0 , -6);
			s1.CylinderTexture(1 , 10 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 6*2.41421356 , 0 , 6);
			s1.CylinderTexture(1 , 10 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -6*2.41421356 , 0 , 6);
			s1.CylinderTexture(1 , 10 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -6*2.41421356 , 0 , -6);
			s1.CylinderTexture(1 , 10 , img2);
		glPopMatrix();

		/////////////////////////...< end structure for the cylinder >.../////////////////////////



		/////////////////////////...< External structure cylinder first entry >.../////////////////////////
		glPushMatrix();
			glTranslated( 3.8 , 4 , -6.7*2.51421356);
			glRotated(90 , 0 , 1 , 0);
			s1.CubeTexture(0.1 , 2.5 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -3.8 , 4 , -6.7*2.51421356);
			glRotated(90 , 0 , 1 , 0);
			s1.CubeTexture(0.1 , 2.5 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -5.5 , 0 , -7.3*2.51421356);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 5.5 , 0 , -7.3*2.51421356);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 5.5 , 0 , -7.3*2.51421356);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -5.5 , 0 , -7.3*2.51421356);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -2 , 0 , -7.3*2.51421356);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 2 , 0 , -7.3*2.51421356);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 2 , 0 , -7.3*2.51421356);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -2 , 0 , -7.3*2.51421356);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		/////////////////////////...< end structure cylinder first entry >.../////////////////////////


		/////////////////////////...< External structure cylinder seconed entry >.../////////////////////////
		glPushMatrix();
			glTranslated( 3.8 , 4 , 6.7*2.51421356);
			glRotated(90 , 0 , 1 , 0);
			s1.CubeTexture(0.1 , 2.5 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -3.8 , 4 , 6.7*2.51421356);
			glRotated(90 , 0 , 1 , 0);
			s1.CubeTexture(0.1 , 2.5 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -5 , 0 , 7.3*2.51421356);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 5 , 0 , 7.3*2.51421356);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 5 , 0 , 7.3*2.51421356);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -5 , 0 , 7.3*2.51421356);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -2 , 0 , 7.3*2.51421356);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 2 , 0 , 7.3*2.51421356);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 2 , 0 , 7.3*2.51421356);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -2 , 0 , 7.3*2.51421356);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		/////////////////////////...< end structure cylinder first entry >.../////////////////////////



		/////////////////////////...< External structure cylinder thired entry >.../////////////////////////
		glPushMatrix();
			glTranslated( 6.7*2.51421356 , 4 , 3.8);
			glRotated(90 , 0 , 1 , 0);
			s1.CubeTexture(0.1 , 2.5 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 6.7*2.51421356 , 4 , -3.8);
			glRotated(90 , 0 , 1 , 0);
			s1.CubeTexture(0.1 , 2.5 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 7.3*2.51421356 , 0 , -5);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 7.3*2.51421356 , 0 , 5);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 7.3*2.51421356 , 0 , 5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 7.3*2.51421356 , 0 , -5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 7.3*2.51421356 , 0 , -2);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 7.3*2.51421356 , 0 , 2);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 7.3*2.51421356 , 0 , 2);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( 7.3*2.51421356 , 0 , -2);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();
		/////////////////////////...< end structure cylinder thired entry >.../////////////////////////



		/////////////////////////...< External structure cylinder forth entry >.../////////////////////////
		glPushMatrix();
			glTranslated( -6.7*2.51421356 , 4 , 3.8);
			glRotated(90 , 0 , 1 , 0);
			s1.CubeTexture(0.1 , 2.5 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -6.7*2.51421356 , 4 , -3.8);
			glRotated(90 , 0 , 1 , 0);
			s1.CubeTexture(0.1 , 2.5 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -7.3*2.51421356 , 0 , -5);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -7.3*2.51421356 , 0 , 5);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -7.3*2.51421356 , 0 , 5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -7.3*2.51421356 , 0 , -5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -7.3*2.51421356 , 0 , -2);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -7.3*2.51421356 , 0 , 2);
			s1.CylinderTexture(0.5 , 4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -7.3*2.51421356 , 0 , 2);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated( -7.3*2.51421356 , 0 , -2);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
		glPopMatrix();

		/////////////////////////...< end structure cylinder forth entry >.../////////////////////////


		/////////////////////////...< internal structure  for mosuq >.../////////////////////////

		//1
		glPushMatrix();
		glTranslated( 5 , 0 , 5 );
		s1.CylinderTexture( 0.5 , 10 , img7);
		glPopMatrix();

			glPushMatrix();
			glTranslated( 5 , 0 , 5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
			glTranslated( 5 , 5 , 5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
			glTranslated( 5 , 9.7 , 5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

		//2
		glPushMatrix();
		glTranslated(-5,0,5);
		s1.CylinderTexture(0.5,10,img7);
		glPopMatrix();

			glPushMatrix();
			glTranslated( -5 , 0 , 5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
			glTranslated( -5 , 5 , 5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
			glTranslated( -5 , 9.7 , 5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

		//3
		glPushMatrix();
		glTranslated(-5,0,-5);
		s1.CylinderTexture(0.5,10,img7);
		glPopMatrix();

			glPushMatrix();
			glTranslated( -5 , 0 , -5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
			glTranslated( -5 , 5 , -5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
			glTranslated( -5 , 9.7 , -5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

		//4
		glPushMatrix();
		glTranslated(5,0,-5);
		s1.CylinderTexture(0.5,10,img7);
		glPopMatrix();
			
			glPushMatrix();
			glTranslated( 5 , 0 , -5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
			glTranslated( 5 , 5 , -5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

			glPushMatrix();
			glTranslated( 5 , 9.7 , -5);
			s1.CubeTexture(0.2 , 0.6 , img2 , 1 , 1);
			glPopMatrix();

		glPushMatrix();
			glTranslated(-9.4 , 1.5 , -5);
			glScaled(1,1,0.1);
			s1.Cube(0.2 , 5 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-5 , 1.5 , -9.4);
			glRotated(90 , 0 , 1 , 0);
			glScaled(1,1,0.1);
			s1.Cube(0.2 , 5 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(9.4 , 1.5 , -5);
			glScaled(1,1,0.1);
			s1.Cube(0.2 , 5 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(5 , 1.5 , -9.4);
			glRotated(90 , 0 , 1 , 0);
			glScaled(1,1,0.1);
			s1.Cube(0.2 , 5 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-9.4 , 1.5 , 5);
			glScaled(1,1,0.1);
			s1.Cube(0.2 , 5 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-5 , 1.5 , 9.4);
			glRotated(90 , 0 , 1 , 0);
			glScaled(1,1,0.1);
			s1.Cube(0.2 , 5 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(9.4 , 1.5 , 5);
			glScaled(1,1,0.1);
			s1.Cube(0.2 , 5 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(5 , 1.5 , 9.4);
			glRotated(90 , 0 , 1 , 0);
			glScaled(1,1,0.1);
			s1.Cube(0.2 , 5 , 63 , 59 , 50);
		glPopMatrix();

		for (int i = 0; i <=16 ; i+=8)
		{
			glPushMatrix();
				glTranslated(0 , 0 , -8+i);
				glRotated(90 , 1 , 0 , 0);
				s1.QuadTexture(4,4,im9 , 2 , 2);
			glPopMatrix();
		}

		for (int i = 0; i <=16 ; i+=8)
		{
			glPushMatrix();
				glTranslated(-8+i , 0 , 0);
				glRotated(90 , 1 , 0 , 0);
				s1.QuadTexture(4,4,im9 , 2 , 2);
			glPopMatrix();
		}
		//...<end>...//


		/////////////////////////...< end internal structure  for mosuq >.../////////////////////////


		/////////////////////////...< External structure  of quantara >.../////////////////////////
			glPushMatrix();
				glTranslated( 0 , 2.2 , -14.3);
				glScaled( 1.5 , 1 , -5);
				s1.qantara(63,59,50);
			glPopMatrix();

			glPushMatrix();
				glTranslated( 0 , 2.2 , 14.3);
				glScaled( 1.5 , 1 , 5);
				s1.qantara(63,59,50);
			glPopMatrix();

			glPushMatrix();
				glTranslated( 14.3 , 2.2 , 0);
				glRotated(90,0,1,0);
				glScaled( 1.5 , 1 , 5 );
				s1.qantara(63,59,50);
			glPopMatrix();

			glPushMatrix();
				glTranslated( -14.3 , 2.2 , 0);
				glRotated(90 , 0 , 1 , 0);
				glScaled(-1.5 , 1 , -5);
				s1.qantara(63,59,50);
			glPopMatrix();

		/////////////////////////...< End External structure  of quantara >.../////////////////////////


		////.....<sign>...../////
		glPushMatrix();
			glTranslated(0  , 10.5 , -15.8);
			s1.quadTL(1 , 2 , img10 , 1 , 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-34  , 0.01 , 0);
			s1.OctagonTexture(2.2 , 0.1 ,img2 , 60 , 60 , 60);
		glPopMatrix();

		/////// 1
		glPushMatrix();
			glTranslated(-38.7 , 0 , 2.11421356);
			s1.CylinderTexture(0.3 , 3.5 , img4);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-39 , 0.7 , 0);
				glRotated(90,0,1,0);
				glScaled(1.4,1.5,1);
				s1.qantara(63 , 59 , 50 );
			glPopMatrix();

		/////// 2
		glPushMatrix();
			glTranslated(-38.7 , 0 , -2.11421356);
			s1.CylinderTexture(0.3 , 3.5 , img4);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-37.5 , 0.7 , -1.7*2.11421356);
				glRotated(45,0,1,0);
				glScaled(1.4,1.5,1);
				s1.qantara(63 , 59 , 50 );
			glPopMatrix();

		/////// 3
		glPushMatrix();
			glTranslated(-36 , 0 , 2.25*2.11421356);
			s1.CylinderTexture(0.3 , 3.5 , img4);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-36.8 , 0.7 , 1.4*2.11421356);
				glRotated(-45,0,1,0);
				glScaled(1.4,1.5,1);
				s1.qantara(63 , 59 , 50 );
			glPopMatrix();

		/////// 4
		glPushMatrix();
			glTranslated(-36 , 0 , -2.25*2.11421356);
			s1.CylinderTexture(0.3 , 3.5 , img4);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-30 , 0.7 , 0);
				glRotated(90,0,1,0);
				glScaled(1.4,1.5,1);
				s1.qantara(63 , 59 , 50 );
			glPopMatrix();

		/////// 5
		glPushMatrix();
			glTranslated(-32 , 0 , 2.25*2.11421356);
			s1.CylinderTexture(0.3 , 3.5 , img4);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-30.5 , 0.7 , -1.7*2.11421356);
				glRotated(-45,0,1,0);
				glScaled(1.4,1.5,1);
				s1.qantara(63 , 59 , 50 );
			glPopMatrix();

		//////// 6
		glPushMatrix();
			glTranslated(-32 , 0 , -2.25*2.11421356);
			s1.CylinderTexture(0.3 , 3.5 , img4);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-31.2 , 0.7 , 1.4*2.11421356);
				glRotated(45,0,1,0);
				glScaled(1.4,1.5,1);
				s1.qantara(63 , 59 , 50 );
			glPopMatrix();

		//////// 7
		glPushMatrix();
			glTranslated(-29.4 , 0 , 2.11421356);
			s1.CylinderTexture(0.3 , 3.5 , img4);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-34 , 0.7 , -2.4*2.11421356);
				glScaled(1.4,1.5,1);
				s1.qantara(63 , 59 , 50 );
			glPopMatrix();

		///////// 8
		glPushMatrix();
			glTranslated(-29.4 , 0 , -2.11421356);
			s1.CylinderTexture(0.3,3.5,img4);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-34 , 0.7 , 1.95*2.11421356);
				glScaled(1.4,1.5,1);
				s1.qantara(63 , 59 , 50 );
			glPopMatrix();

		
		glPushMatrix();
			glTranslated(-34  , 3.5 , 0);
			s1.OctagonTexture(2.2 , 0.1 , img2 , 60 , 60 , 60);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-34  , 3.6 , 0);
			s1.OctagonTexture(1.8 , 1 , img3 , 60 , 60 , 60);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-34  , 5.4 , 0);
			s1.OctagonTexture(2.4 , 0.15 , img2 , 60 , 60 , 60);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-34  , 5.7 , 0);
			s1.OctagonTexture(1.5 , 1 , img11 , 60 , 60 , 60);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-34  , 7.4 , 0);
			s1.OctagonTexture(1.8 , 0.15 , img2 , 60 , 60 , 60);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-34  , 7.7 , 0);
			s1.HalfSphareTexture(3.7 ,img3);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-34  , 11.4 , 0);
			s1.SphareTexture(0.6 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-34  , 12 , 0);
			s1.SphareTexture(0.3 , img2);
		glPopMatrix();

		//door
		float maxX = 1.5 , minX = -1.5 , incr = 0.02 ;

		if(doorX2a <= maxX-1.5  && doorOpenState1 == 1 ){
			doorX2a+=incr;
			doorX1a-=incr;
		}
		if(doorX2a > minX   && doorOpenState1 == 2 ){
			doorX1a+=incr;
			doorX2a-=incr;
		}
		if(keys[VK_NUMPAD3]){
			doorOpenState1 = 1 ;

		}
		if(keys[VK_NUMPAD1]){
			doorOpenState1 = 2 ;
			PlaySound("wav//aqsa.wav", NULL, SND_FILENAME | SND_ASYNC);
		}

			glPushMatrix();
				glTranslated(-1.18-doorX1a,0,-14.5);
				glRotated(180 , 0 , 1 , 0);
				glScaled(11.9 , 0.8 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(1.18-doorX2a,0,-14.5);
				glRotated(180 , 0 , 1 , 0);
				glScaled(11.9 , 0.8 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-1.18-doorX1a,0,14.5);
				glScaled(11.9 , 0.8 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(1.18-doorX2a,0,14.5);
				glScaled(11.9 , 0.8 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(14.5 , 0 , -1.18-doorX1a);
				glRotated(90 , 0 , 1 , 0);
				glScaled(11.9 , 0.8 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(14.5 , 0 , 1.18-doorX2a);
				glRotated(90 , 0 , 1 , 0);
				glScaled(11.9 , 0.8 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-14.5 , 0 , -1.18-doorX1a);
				glRotated(90 , 0 , 1 , 0);
				glRotated(180 , 0 , 1 , 0);
				glScaled(11.9 , 0.8 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-14.5 , 0 , 1.18-doorX2a);
				glRotated(90 , 0 , 1 , 0);
				glRotated(180 , 0 , 1 , 0);
				glScaled(11.9 , 0.8 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

	}

	void arena_aqsa(){
	/////////////////////////...< External structure  of arena >.../////////////////////////

		glPushMatrix();
			glTranslated(0,-0.023,0);
			glRotated(90,1,0,0);
			glRotated(90,1,0,0);
			glScaled(1,0.5,1);
			s1.CubeTexture(8,80,img12,5,3);
		glPopMatrix(); 

		// 1 hunsh
		glPushMatrix();
			glTranslated(81,0.5,80);
			glRotated(90,0,0,1);
			s1.Cube(81,0.5,63 , 59 , 50);
		glPopMatrix(); 

		glPushMatrix();
			glTranslated(81,-7.5,80.2);
			glRotated(90,0,0,1);
			s1.Cube(81,0.5,63 , 59 , 50);
		glPopMatrix(); 

		// 2 hunsh
		glPushMatrix();
			glTranslated(80,0.5,8);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.Cube(36,0.5,63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(80,-7.5,8);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.Cube(36,0.5,63 , 59 , 50);
		glPopMatrix();

		// 3 hunsh
		glPushMatrix();
			glTranslated(-80,0.5,8);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.Cube(36,0.5,63 , 59 , 50);
		glPopMatrix(); 

		glPushMatrix();
			glTranslated(-80,-7.5,8);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.Cube(36,0.5,63 , 59 , 50);
		glPopMatrix(); 

		// 4 hunsh 
		glPushMatrix();
			glTranslated(80,0.5,-80);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.Cube(36,0.5,63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(80,-7.5,-80);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.Cube(36,0.5,63 , 59 , 50);
		glPopMatrix();


		// 5 hunsh
		glPushMatrix();
			glTranslated(-80,0.5,-80);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.Cube(36,0.5,63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-80,-7.5,-80);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.Cube(36,0.5,63 , 59 , 50);
		glPopMatrix();


		// 6 hunsh
		glPushMatrix();
			glTranslated(26,0.5,-80);
			glRotated(90,0,0,1);
			s1.Cube(26,0.5,63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(26,-7.5,-80);
			glRotated(90,0,0,1);
			s1.Cube(26,0.5,63 , 59 , 50);
		glPopMatrix();

		// 7 hunsh 
		glPushMatrix();
			glTranslated(-44.3,0.5,-80);
			glRotated(90,0,0,1);
			s1.Cube(18.1,0.5,63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-44.3,-7.5,-80);
			glRotated(90,0,0,1);
			s1.Cube(18.1,0.5,63 , 59 , 50);
		glPopMatrix();

		// 8 hunsh 
		glPushMatrix();
			glTranslated(80.5,0.5,-80);
			glRotated(90,0,0,1);
			s1.Cube(18.1,0.5,63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(80.5,-7.5,-80);
			glRotated(90,0,0,1);
			s1.Cube(18.1,0.5,63 , 59 , 50);
		glPopMatrix();
		////////...< Entrance external arena >...//////// 
		
		//1
		glPushMatrix();
			glScaled(1,0.8,1);
			Entrance_arena();
		glPopMatrix();

		//2
		glPushMatrix();
			glTranslated(160,0,0);
			glScaled(1,0.8,1);
			Entrance_arena();
		glPopMatrix();

		//3
		glPushMatrix();
			glTranslated(35,0,-160);
			glRotated(90,0,1,0);
			glScaled(1,0.8,1);
			Entrance_arena();
		glPopMatrix();

		//4
		glPushMatrix();
			glTranslated(-35,0,-160);
			glRotated(90,0,1,0);
			glScaled(1,0.8,1);
			Entrance_arena();
		glPopMatrix();

		////////...< Entrance staris arena >...////////
		glPushMatrix();
			glTranslated(-35,-8.09,-82.5);
			s1.staries(img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(35,-8.09,-82.5);
			s1.staries(img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-82.5,-8.09,0);
			glRotated(90,0,1,0);
			s1.staries(img2);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-132,-8,0);
				glRotated(90,1,0,0);
				s1.QuadTexture(9 , 80 , img16 , 12 , 1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(132,-8,0);
				glRotated(90,1,0,0);
				s1.QuadTexture(9 , 80 , img16 , 12 , 1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-35,-8,-285);
				glRotated(90,1,0,0);
				glRotated(90,0,0,1);
				s1.QuadTexture(9 , 200 , img16 , 26 , 1);
			glPopMatrix();

		glPushMatrix();
			glTranslated(82.5,-8.09,0);
			glRotated(-90,0,1,0);
			s1.staries(img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(82.5,-8.09,0);
			glRotated(-90,0,1,0);
			s1.staries(img2);
		glPopMatrix();

		//green area

		//front
		glPushMatrix();
			glTranslated(0,-8.02,-95);
			glRotated(90,1,0,0);
			s1.QuadTexture(24,24,im10 , 1 ,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-8.02,-120);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(25,-8.02,-97);
			glRotated(90,0,1,0);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(-25,-8.02,-97);
			glRotated(90,0,1,0);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		//right
		glPushMatrix();
			glTranslated(-85,-8.02,40);
			glRotated(90,1,0,0);
			s1.QuadTexture(30,30,im10 , 1 ,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-115,-8.02,40);
			glRotated(90,0,1,0);
			glScaled(1.5 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(-92,-8.02,70);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(-92,-8.02,10);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

				glPushMatrix();
					glTranslated(-190,-8.02,40);
					glRotated(90,1,0,0);
					s1.QuadTexture(30,30,im10 , 1 ,1);
				glPopMatrix();

				glPushMatrix();
					glTranslated(-160,-8.02,40);
					glRotated(90,0,1,0);
					glScaled(1.5 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

				glPushMatrix();
					glTranslated(-183,-8.02,70);
					glScaled(1.2 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

				glPushMatrix();
					glTranslated(-183,-8.02,10);
					glScaled(1.2 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();
		//2
		glPushMatrix();
			glTranslated(-85,-8.02,-40);
			glRotated(90,1,0,0);
			s1.QuadTexture(30,30,im10 , 1 ,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-115,-8.02,-40);
			glRotated(90,0,1,0);
			glScaled(1.5 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(-92,-8.02,-70);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(-92,-8.02,-10);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

				glPushMatrix();
					glTranslated(-190,-8.02,-40);
					glRotated(90,1,0,0);
					s1.QuadTexture(30,30,im10 , 1 ,1);
				glPopMatrix();

				glPushMatrix();
					glTranslated(-160,-8.02,-40);
					glRotated(90,0,1,0);
					glScaled(1.5 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

				glPushMatrix();
					glTranslated(-183,-8.02,-70);
					glScaled(1.2 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

				glPushMatrix();
					glTranslated(-183,-8.02,-10);
					glScaled(1.2 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();	

		//right
		glPushMatrix();
			glTranslated(85,-8.02,40);
			glRotated(90,1,0,0);
			s1.QuadTexture(30,30,im10 , 1 ,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(115,-8.02,40);
			glRotated(90,0,1,0);
			glScaled(1.5 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(92,-8.02,70);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(92,-8.02,10);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();


				glPushMatrix();
					glTranslated(190,-8.02,40);
					glRotated(90,1,0,0);
					s1.QuadTexture(30,30,im10 , 1 ,1);
				glPopMatrix();

				glPushMatrix();
					glTranslated(160,-8.02,40);
					glRotated(90,0,1,0);
					glScaled(1.5 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

				glPushMatrix();
					glTranslated(183,-8.02,70);
					glScaled(1.2 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

				glPushMatrix();
					glTranslated(183,-8.02,10);
					glScaled(1.2 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

		//2
		glPushMatrix();
			glTranslated(85,-8.02,-40);
			glRotated(90,1,0,0);
			s1.QuadTexture(30,30,im10 , 1 ,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(115,-8.02,-40);
			glRotated(90,0,1,0);
			glScaled(1.5 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(92,-8.02,-70);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

		glPushMatrix();
			glTranslated(92,-8.02,-10);
			glScaled(1.2 , 1 , 0.05);
			s1.Cube(0.2 , 20 , 63 , 59 , 50 );
		glPopMatrix();

				glPushMatrix();
					glTranslated(190,-8.02,-40);
					glRotated(90,1,0,0);
					s1.QuadTexture(30,30,im10 , 1 ,1);
				glPopMatrix();

				glPushMatrix();
					glTranslated(160,-8.02,-40);
					glRotated(90,0,1,0);
					glScaled(1.5 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

				glPushMatrix();
					glTranslated(183,-8.02,-70);
					glScaled(1.2 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();

				glPushMatrix();
					glTranslated(183,-8.02,-10);
					glScaled(1.2 , 1 , 0.05);
					s1.Cube(0.2 , 20 , 63 , 59 , 50 );
				glPopMatrix();	

		////////...<  small build in right >...////////
		glPushMatrix();
			glTranslated(0,-2.5,4.1);
			glScaled(1,0.7,1);
			Small_house();
		glPopMatrix();	

		////////...<  small dump in right  >...////////
		glPushMatrix();
			glTranslated(50 , 0 , 25);
			small_dump(img9 , img2 , img3 , 63 , 59 , 50);
		glPopMatrix();
	}
	
	void Small_house(){
		glPushMatrix();
			glTranslated(76,-8,-70);
			glScaled(1,1,2);
			s1.Cube2Texture(16,10,img1,img13,1,1);
		glPopMatrix();
	

		for(int i=4 ; i<=20 ; i+=4){
			 glPushMatrix();
				glTranslated(-i+88 , 24.1 ,-89.7);
				glScaled(5,5,2);
				s1.Castle_cube2(63 , 59 , 50);
			glPopMatrix();
		}

		for(int i=4 ; i<=20 ; i+=4){
			 glPushMatrix();
				glTranslated(-i+88 , 24.1 ,-50.2);
				glScaled(5,5,2);
				s1.Castle_cube2(63 , 59 , 50);
			glPopMatrix();
		}

		for(int i=4 ; i<=40 ; i+=4){
			 glPushMatrix();
			 glTranslated(85.8 , 24.1 , i-92);
				glRotated(90,0,1,0);
				glScaled(5,5,2);
				s1.Castle_cube2(63 , 59 , 50);
			glPopMatrix();
		}

		for(int i=4 ; i<=40 ; i+=4){
			 glPushMatrix();
			 glTranslated(66.2 , 24.1 , i-92);
				glRotated(90,0,1,0);
				glRotated(180 , 0 , 1 , 0);
				glScaled(5,5,2);
				s1.Castle_cube2(63 , 59 , 50);
			glPopMatrix();
		}

		glPushMatrix();
			glTranslated(76 , 26 , -79);
			glScaled(1,1.9,1);
			s1.HalfSphareTexture(8,img3);
		glPopMatrix();

	}

	void small_dump(int textureC , int textureO , int textureD , GLubyte R , GLubyte G , GLubyte B){

		//1
		glPushMatrix();
			glTranslated(2 , 0 , 2*2.41421356);
			s1.CylinderTexture(0.5 , 6 , textureC);
		glPopMatrix();

			glPushMatrix();
				glTranslated(4.3 , 3 , 0);
				glRotated(90 , 0 , 1 , 0);
				glScaled(1.5 , 1.5 , 1);
				s1.qantara(R , G , B);
			glPopMatrix();			

		//2
		glPushMatrix();
			glTranslated(-2 , 0 , 2*2.41421356);
			s1.CylinderTexture(0.5 , 6 , textureC);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-5.3 , 3 , 0);
				glRotated(90 , 0 , 1 , 0);
				glScaled(1.5 , 1.5 , 1);
				s1.qantara(R , G , B);
			glPopMatrix();	

		//3
		glPushMatrix();
			glTranslated( 2*2.41421356 , 0 , -2);
			s1.CylinderTexture(0.5 , 6 , textureC);
		glPopMatrix();

			glPushMatrix();
				glTranslated(0 , 3 , 4.3);
				glScaled(1.5 , 1.5 , 1);
				s1.qantara(R , G , B);
			glPopMatrix();	

		//4
		glPushMatrix();
			glTranslated( 2*2.41421356 , 0 , 2);
			s1.CylinderTexture(0.5 , 6 , textureC);
		glPopMatrix();

			glPushMatrix();
				glTranslated(0 , 3 , -5.3);
				glScaled(1.5 , 1.5 , 1);
				s1.qantara(R , G , B);
			glPopMatrix();	

		//5
		glPushMatrix();
			glTranslated( -2*2.41421356 , 0 , 2);
			s1.CylinderTexture(0.5 , 6 , textureC);
		glPopMatrix();

			glPushMatrix();
				glTranslated(3.1 , 3 , 1.5*2.11421356);
				glRotated(45,0,1,0);
				glScaled(1.5 , 1.5 , 1);
				s1.qantara(R , G , B);
			glPopMatrix();

		//6
		glPushMatrix();
			glTranslated( -2*2.41421356 , 0 , -2);
			s1.CylinderTexture(0.5 , 6 , textureC);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-3.1 , 3 , 1.5*2.11421356);
				glRotated(-45,0,1,0);
				glScaled(1.5 , 1.5 , 1);
				s1.qantara(R , G , B);
			glPopMatrix();

		//7
		glPushMatrix();
			glTranslated(2 , 0 , -2*2.41421356);
			s1.CylinderTexture(0.5 , 6 , textureC);
		glPopMatrix();

			glPushMatrix();
				glTranslated(-3.8 , 3 , -1.8*2.11421356);
				glRotated(45,0,1,0);
				glScaled(1.5 , 1.5 , 1);
				s1.qantara(R , G , B);
			glPopMatrix();

		//8
		glPushMatrix();
			glTranslated(-2 , 0 , -2*2.41421356);
			s1.CylinderTexture(0.5 , 6 , textureC);
		glPopMatrix();

			glPushMatrix();
				glTranslated(3.8 , 3 , -1.8*2.11421356);
				glRotated(-45,0,1,0);
				glScaled(1.5 , 1.5 , 1);
				s1.qantara(R , G , B);
			glPopMatrix();

		//octagon
			glPushMatrix();
			glTranslated(0,5.9,0);
			s1.OctagonTexture(2.3 , 0.2 , textureO , 60 , 60 , 60);
			glPopMatrix();

		//dump
			glPushMatrix();
			glTranslated(0,6.2,0);
			s1.HalfSphareTexture(4,textureD);
			glPopMatrix();

			glPushMatrix();
				glTranslated(0 , 12.4 , 0);
				glRotated(180 , 0 , 0 , 1);
				glScaled(0.7 , 0.7 , 0.7);
				s1.qantara(60 , 60 , 60);
			glPopMatrix();	

		//disghn
		//1
		glPushMatrix();
		glTranslated(2 , 0 , 2*2.41421356);
		glScaled(1.4 , 1.4 , 1.4);
			s1.Castle_cube(63 , 59 , 50);
		glPopMatrix();	

		//2
		glPushMatrix();
		glTranslated(2 , 0 , -2*2.41421356);
		glScaled(1.4 , 1.4 , 1.4);
			s1.Castle_cube(63 , 59 , 50);
		glPopMatrix();

		//3
		glPushMatrix();
		glTranslated(-2 , 0 , -2*2.41421356);
		glScaled(1.4 , 1.4 , 1.4);
			s1.Castle_cube(63 , 59 , 50);
		glPopMatrix();

		//4
		glPushMatrix();
		glTranslated(-2 , 0 , 2*2.41421356);
		glScaled(1.4 , 1.4 , 1.4);
			s1.Castle_cube(63 , 59 , 50);
		glPopMatrix();

		//5
		glPushMatrix();
		glTranslated(2*2.41421356 , 0 , 2);
		glScaled(1.4 , 1.4 , 1.4);
			s1.Castle_cube(63 , 59 , 50);
		glPopMatrix();

		//6
		glPushMatrix();
		glTranslated(2*2.41421356 , 0 , -2);
		glScaled(1.4 , 1.4 , 1.4);
			s1.Castle_cube(63 , 59 , 50);
		glPopMatrix();

		//7
		glPushMatrix();
		glTranslated(-2*2.41421356 , 0 , -2);
		glScaled(1.4 , 1.4 , 1.4);
			s1.Castle_cube(63 , 59 , 50);
		glPopMatrix();

		//8
		glPushMatrix();
		glTranslated(-2*2.41421356 , 0 , 2);
		glScaled(1.4 , 1.4 , 1.4);
			s1.Castle_cube(63 , 59 , 50);
		glPopMatrix();

	}


	////////////////////////////////////....< shapes of quantara entry >....///////////////////////////////////
	void Entrance_arena (){
		glPushMatrix();
			glTranslated(-80,10.4,-8);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			s1.CubeTexture(8,0.7,img2,1,5);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-80,14.5,-10);
			glRotated(90,0,0,1);
			glRotated(90,1,0,0);
			glScaled(1,1,8);
			s1.CubeTexture(10,0.2,img2,1,5);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-80.5, 5.1 , 4);
			glScaled(1,3,3);
			glRotated(90,0,1,0);
			s1.qantara(63,59,50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-80.5 , 5.1 , -4);
			glScaled(1,3,3);
			glRotated(90,0,1,0);
			s1.qantara(63,59,50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-80,0,-8.2);
			s1.CylinderTexture(1.2,14.2,img7);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-80,0,8.2);
			s1.CylinderTexture(1.2,14.2,img7);
		glPopMatrix(); 

		glPushMatrix();
			glTranslated(-80,15.2,-3.7);
			s1.SphareTexture(1,img7);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-80,15.2,3.7);
			s1.SphareTexture(1,img7);
		glPopMatrix(); 

		glPushMatrix();
			glTranslated(-81.5 , 2.7 , 0);
			glScaled(3,6,6.5);
			glRotated(90,0,1,0);
			s1.qantara(63,59,50);
		glPopMatrix(); 
	}


	////////////////////////////////////....< shapes of houses >....///////////////////////////////////
	void main_roof(int texture , int texture2 ){
		glPushMatrix();
			glTranslated(0,10.01,0);
			glScaled(7.8 , 3 , 6.5);
			s1.roof(texture , 80 , 80 , 80);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,10,0);
			glScaled( 2 , 2 , 4);
			s1.roof_tringle(texture2);
		glPopMatrix();
	}


	////////////////////////////////////....<Garden parts>....////////////////////////////////////
	void chair(){
		glPushMatrix();
			glTranslated(0,0.4,0);
			glScaled(1,1,0.3);
			s1.CubeTexture(0.1 , 1.5 , img2 , 1 , 1);
		glPopMatrix();

		for(float i = 0.0f ; i<= 0.9f ; i+=0.3f){
		glPushMatrix();
			glTranslated(0 , i+0.7 , 0.35);
			glScaled(1 , 0.05 , 0.4);
			glRotated(90 , 1 , 0 , 0);
			s1.CubeTexture(0.1 , 1.5 , img15 , 10 , 1);
		glPopMatrix();
		}

		glPushMatrix();
			glTranslated(1.3 , 0.2 , 0.3);
			s1.Cylinder(0.1 , 0.4 , 155 , 140 , 109);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.3 , 0.2 , 0.3);
			s1.Cylinder(0.1 , 0.4 , 155 , 140 , 109);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.3 , 0.2 , -0.3);
			s1.Cylinder(0.1 , 0.4 , 155 , 140 , 109);
		glPopMatrix();

		glPushMatrix();
			glTranslated(1.3 , 0.2 , -0.3);
			s1.Cylinder(0.1 , 0.4 , 155 , 140 , 109);
		glPopMatrix();

		glPushMatrix();
			glTranslated(1.3 , 0.9 , 0.39);
			s1.Cylinder(0.03 , 0.8 , 63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.3 , 0.9 , 0.39);
			s1.Cylinder(0.03 , 0.8 , 63 , 59 , 50);
		glPopMatrix();
	}

	void fountain(){
		glPushMatrix();
			glTranslated(0,0.5,0);
			glRotated(180,0,0,1);
			s1.CylinderTexture(3 , 0.5 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,0.4,0);
			glRotated(180,0,0,1);
			s1.CylinderTexture(2.7 , 0.2 , img19);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,3,0);
			s1.CylinderTexture(1.6 , 0.4 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-2.56 , 0.44 , 0.1);
			glRotated(90 , 1 , 0 ,0);
			glRotated(-10 , 0 , 1 , 0);
			s1.QuadTexture(0.4 , 0.4 , img2 , 1 , 1);
		glPopMatrix();

		//first waterfall
		glPushMatrix();
			glTranslated(0, 0.4 , 1.7);
			s1.CubeTexture(1.5 , 0.3 , img19 , 1, 1);
		glPopMatrix();

			glPushMatrix();
				glTranslated(0, 3.2 , 1.8);
				glRotated(-45 , 1 , 0 , 0);
				s1.CubeTexture(0.5 , 0.3 , img19 , 1, 1);
			glPopMatrix();

		//seconed waterfall
		glPushMatrix();
			glTranslated(0, 0.4 , -1.7);
			s1.CubeTexture(1.5 , 0.3 , img19 , 1, 1);
		glPopMatrix();

			glPushMatrix();
				glTranslated(0, 3.2 , -1.8);
				glRotated(45 , 1 , 0 , 0);
				s1.CubeTexture(0.5 , 0.3 , img19 , 1, 1);
			glPopMatrix();
		//thired waterfall
		glPushMatrix();
			glTranslated(1.7, 0.4 , 0);
			s1.CubeTexture(1.5 , 0.3 , img19 , 1, 1);
		glPopMatrix();

			glPushMatrix();
				glTranslated(1.8, 3.2 , 0);
				glRotated(45 , 0 , 0 , 1);
				s1.CubeTexture(0.5 , 0.3 , img19 , 1, 1);
			glPopMatrix();
		//forth waterfall
		glPushMatrix();
			glTranslated(-1.7, 0.4 , 0);
			s1.CubeTexture(1.5 , 0.3 , img19 , 1, 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.8, 3.2 , 0);
			glRotated(-45 , 0 , 0 , 1);
			s1.CubeTexture(0.5 , 0.3 , img19 , 1, 1);
		glPopMatrix();

		//ball
		glPushMatrix();
		glTranslated(0 , 4.4 , 0);
		glScaled(1.5 , 1 , 1.5);
			s1.SphareTexture(1 , img4);
		glPopMatrix();

		glPushMatrix();
			s1.CylinderTexture(0.3, 3 , img9);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,5,0);
			s1.CylinderTexture(0.3, 0.8 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,6,0);
			glScaled(1.5 , 1 , 1.5);
			s1.SphareTexture(0.4 , img4);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,6,0);
			s1.CylinderTexture(0.2, 0.6 , img2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,6.8,0);
			glScaled(1.5 , 1 , 1.5);
			s1.SphareTexture(0.2 , img4);
		glPopMatrix();
	}

	void garden_wall(){
		for(float i = 0 ; i<=12 ; i+=2){
			glPushMatrix();
				glTranslated(-6 + i,0,0);
				s1.CubeTexture(1 , 0.3 , img15 , 1 , 1 );			
			glPopMatrix();
		}

		for(float i = 0 ; i<=12 ; i+=2){
			glPushMatrix();
				glTranslated(-6+i ,1.91,0);
				glScaled(0.4 , 0.3 , 0.4);
				s1.prymid(97 , 89 , 78);
			glPopMatrix();
		}

		glPushMatrix();
			glTranslated(0,1.4,0);
			glRotated(90 , 0 , 0 , 1);
			s1.Cylinder(0.1 , 16 , 63 , 59 , 50);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,1,0);
			glRotated(90 , 0 , 0 , 1);
			s1.Cylinder(0.1 , 16 , 63 , 59 , 50);			
		glPopMatrix();
	}

	void garden_lights(){
		glPushMatrix();
			s1.CylinderTexture(0.3 , 5.5 , img7);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-0.95 , 3.7 , -0.4);
			glScaled(0.8 , 0.9 , 0.8);
			s1.qantara(63 , 59 , 50);			
		glPopMatrix();

		glPushMatrix();
			s1.Cube(0.08 , 0.46 , 1 , 1 , 1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,5.5,0);
			s1.Cube(0.08 , 0.46 , 1 , 1 , 1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.9 , 5.48 , 0);
			s1.Cube(0.08 , 0.46 , 1 , 1 , 1);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.9 , 5 , 0);
			s1.CylinderTexture(0.1 , 0.5 , img7);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.9 , 5 , 0);
			s1.Cylinder(0.26 , 0.12 , 50 , 50 , 50);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.9 , 4.33 , 0);
			s1.CylinderTexture(0.25 , 0.6 , img6);			
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1.9 , 4.33 , 0);
			s1.Cylinder(0.26 , 0.12 , 50 , 50 , 50);			
		glPopMatrix();
	}

	////////////////////////////////////....<Qibli parts>....////////////////////////////////////

	void Minaret2(){
		glPushMatrix();
		glTranslated(46,6,-16);
		glScaled(3,10,3);
			s1.CubeTexture4(1,1,im8,im2,1,5);
		glPopMatrix();

		glPushMatrix();
		glTranslated(46,20,-16);
		glScaled(4,0.5,4);
			s1.CubeTexture4(1,1,im2,im2,10,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(46,26,-16);
		glScaled(4,0.5,4);
			s1.CubeTexture4(1,1,im2,im2,10,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(43,20.5,-13);
			s1.CylinderTexture(0.5,6,img2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(49,20.5,-13);
			s1.CylinderTexture(0.5,6,img2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(49,20.5,-19);
			s1.CylinderTexture(0.5,6,img2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(43,20.5,-19);
			s1.CylinderTexture(0.5,6,img2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(46,27,-16);
		glScaled(4,4,4);
			s1.prymid(56 ,46 , 46);
		glPopMatrix();

		glPushMatrix();
		glTranslated(46,35,-16);
		glScaled(1,1,1);
			s1.SphareTexture(1,im2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(46,36,-16);
		glScaled(1,1,1);
			s1.SphareTexture(0.5,im2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(48,39,-16.5);
		glScaled(1,1,1);
		glRotated(135,0,0,1);
			s1.qantara(255 , 255 ,255);
		glPopMatrix();

	}

	void Minaret1(){
		
		glPushMatrix();
		glTranslated(0,10,-18);
			s1.CylinderTexture(5,6,im8);
		glPopMatrix();


		glPushMatrix();
		glTranslated(0,14,-18);
			s1.CylinderTexture(6,2,im2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,16,-18);
			s1.HalfSphareTexture(5,img4);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,21,-18);
		glScaled(1,1,1);
			s1.SphareTexture(1,im2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,22,-18);
		glScaled(1,1,1);
			s1.SphareTexture(0.5,im2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(2,25,-18.5);
		glScaled(1,1,1);
		glRotated(135,0,0,1);
			s1.qantara(255 , 255 ,255);
		glPopMatrix();
	}

	void extintion(){
		glPushMatrix();
		glTranslated(0,0.01,0);
		glRotated(90,1,0,0);
		glRotated(180,0,0,1);
			s1.QuadTexture(24,12,im9,8,10);
		glPopMatrix();

		glPushMatrix();
		glTranslated(56,3,24.01);
			s1.QuadTexture(3,4,im14,1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-16.03,5,-16);
		glRotated(90,0,1,0);
		glRotated(180 , 0 , 1 , 0);
			s1.QuadTexture(5,4,im13,1,1);
		glPopMatrix();
	}

	void part2_qantara(){

		glPushMatrix();
		glTranslated(11.5,0,26.51);
		glScaled(0.5,3,2.5);
			s1.CubeTexture(1,1,img2,1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(8.5,0,28.5);
		glScaled(0.5,3,0.5);
			s1.CubeTexture(1,1,img2,1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(5.5,0,28.5);
		glScaled(0.5,3,0.5);
			s1.CubeTexture(1,1,img2,1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(2.5,0,28.5);
		glScaled(0.5,3,0.5);
			s1.CubeTexture(1,1,img2,1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-11.5,0,26.51);
		glScaled(0.5,3,2.5);
			s1.CubeTexture(1,1,img2,1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-8.5,0,28.5);
		glScaled(0.5,3,0.5);
			s1.CubeTexture(1,1,img2,1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-5.5,0,28.5);
		glScaled(0.5,3,0.5);
			s1.CubeTexture(1,1,img2,1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-2.5,0,28.5);
		glScaled(0.5,3,0.5);
			s1.CubeTexture(1,1,img2,1,1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.6,0.6,0.6);

		glTranslated(0,2,24.01);
		glScaled(2,2,5);
			s1.qantara(63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslated(4,4,24.01);
		glScaled(1.2,1,5);
			s1.qantara(63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslated(7,4,24.01);
		glScaled(1.2,1,5);
			s1.qantara(63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslated(10,4,24.01);
		glScaled(1.2,1,5);
			s1.qantara(63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslated(-4,4,24.01);
		glScaled(1.2,1,5);
			s1.qantara(63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslated(-7,4,24.01);
		glScaled(1.2,1,5);
			s1.qantara(63 , 59 , 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslated(-10,4,24.01);
		glScaled(1.2,1,5);
			s1.qantara(63 , 59 , 50);
		glPopMatrix();


	}

	void alqibli(bool keys[]){
		//1
		glPushMatrix();
			glTranslated(36.01,0,-18);
			glScaled(24,3,6);
			s1.CubeTexture4(1,1,im6,im2,5,1);
		glPopMatrix();

		//2
		glPushMatrix();
			glTranslated(0,0,0);
			glScaled(12,5,24);
			s1.CubeTexturewithdoorO(1,1,im7,im2,5,1);
		glPopMatrix();

		//3
		glPushMatrix();
		glTranslated(-4,10.01,4);
		glScaled(8,2,16);
			s1.CubeTextureforqibli(1,1,im7,im2,8,1);
		glPopMatrix();

		//4
		glPushMatrix();
		glTranslated(0,14.02,4);
		glScaled(2,1,16);
			s1.CubeTextureforqibli(1,1,im6,im2,8,1);
		glPopMatrix();

		//5
		glPushMatrix();
		glTranslated(-20.01,0,-22);
		glScaled(8,3,2);
			s1.CubeTexture4(1,1,im15,im2,1,1);
		glPopMatrix();

		//6
		glPushMatrix();
		glTranslated(-14.01,0,-16);
		glScaled(2,5,4);
			s1.CubeTexture4(1,1,im15,im2,1,1);
		glPopMatrix();

		//7
		glPushMatrix();
		glTranslated(-13.51,0,-10);
		glScaled(1.5,7,2);
			s1.CubeTexture4(1,1,im15,im2,1,1);
		glPopMatrix();

		//8
		glPushMatrix();
		glTranslated(56,0,5.99);
		glScaled(4,3,18);
			s1.CubeTextureforqibli(1,1,im6,im2,5,1);
		glPopMatrix();

		glPushMatrix();
			Minaret1();
		glPopMatrix();

		glPushMatrix();
			Minaret2();
		glPopMatrix();

		glPushMatrix();
			part2_qantara();
		glPopMatrix();

		glPushMatrix();
			extintion();
		glPopMatrix();

		glPushMatrix();
			inner_qibli(keys);
		glPopMatrix();		
		
	}

	void inner_colums(float x){

		glPushMatrix();
			glTranslated(x,0,-7.75);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,-7.75);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(186, 167, 125);
			glTranslated(x,4.99,-7.75);
			glScaled(0.25,0.25,0.8);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,-3.25);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,-3.25);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,4.99,-3.25);
			glScaled(0.25,0.25,0.8);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(186, 167, 125);
			glTranslated(x,0,1.25);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,1.25);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,4.99,1.25);
			glScaled(0.25,0.25,0.8);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,5.75);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(186, 167, 125);
			glTranslated(x,0,5.75);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,4.99,5.75);
			glScaled(0.25,0.25,0.8);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,10.25);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,10.25);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,4.99,10.25);
			glScaled(0.25,0.25,0.8);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,14.75);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,14.75);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,4.99,14.75);
			glScaled(0.25,0.25,0.8);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,19.25);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,19.25);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,4.99,19.25);
			glScaled(0.25,0.25,0.8);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,23.4);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,0,23.4);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,4.99,23.4);
			glScaled(0.25,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();


		/////////////////////////


		glPushMatrix();
			glTranslated(x,5,-5.5);
			glRotated(90,0,1,0);
			glScaled(1.5,2,0.2);
			s1.qantara2(144 , 125 , 104);
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(x,5,-1);
			glRotated(90,0,1,0);
			glScaled(1.5,2,0.2);
			s1.qantara2(144, 125, 104);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,5,3.5);
			glRotated(90,0,1,0);
			glScaled(1.5,2,0.2);
			s1.qantara2(144, 125, 104);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,5,8);
			glRotated(90,0,1,0);
			glScaled(1.5,2,0.2);
			s1.qantara2(144, 125, 104);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,5,12.5);
			glRotated(90,0,1,0);
			glScaled(1.5,2,0.2);
			s1.qantara2(144, 125, 104);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,5,17);
			glRotated(90,0,1,0);
			glScaled(1.5,2,0.2);
			s1.qantara2(144, 125, 104);
		glPopMatrix();

		glPushMatrix();
			glTranslated(x,5,21.5);
			glRotated(90,0,1,0);
			glScaled(1.5,2,0.2);
			s1.qantara2(144, 125, 104);
		glPopMatrix();




	}

	void inner_qibli(bool keys[]){
		
		inner_colums(8);
		inner_colums(4);
		inner_colums(-8);
		inner_colums(-4);
		

		//under doom qantara
		glPushMatrix();
			glTranslated(0,5,-8);
			glScaled(2.8,2.5,0.5);
			s1.qantara2(79, 64, 64);
		glPopMatrix();

		glPushMatrix();
			glTranslated(4.5,5,-12);
			glRotated(90,0,1,0);
			glScaled(2.8,2.5,0.5);
			s1.qantara2(79, 64, 64);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,5,-16);
			glScaled(2.8,2.5,0.5);
			s1.qantara2(79, 64, 64);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-4.5,5,-12);
			glRotated(90,0,1,0);
			glScaled(2.8,2.5,0.5);
			s1.qantara2(79, 64, 64);
		glPopMatrix();


		//other qantara
		glPushMatrix();
			glTranslated(6,5,-8);
			glScaled(1.5,2.5,0.2);
			s1.qantara2(79, 64, 64);
		glPopMatrix();

		glPushMatrix();
			glTranslated(9.8,5,-8);
			glScaled(1.4,2.5,0.2);
			s1.qantara2(79, 64, 64);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-6,5,-8);
			glScaled(1.5,2.5,0.2);
			s1.qantara2(79, 64, 64);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-9.8,5,-8);
			glScaled(1.4,2.5,0.2);
			s1.qantara2(79, 64, 64);
		glPopMatrix();


		//under doom colums
		glPushMatrix();
			glTranslated(-4,0,-16);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-4,0,-16);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-4,4.99,-16);
			glScaled(1,0.25,0.6);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(4,0,-16);
			s1.CylinderTexture(0.25,5,im1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(4,0,-16);
			glScaled(0.5,0.25,0.5);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(4,4.99,-16);
			glScaled(1,0.25,0.6);
			s1.CubeTexture(1,1,im2,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,9.99,-12);
			glRotated(90,1,0,0);
			s1.QuadTexture(5,5,im16,1,1);
		glPopMatrix();

		//doors
		float maxX = 1.5 , minX = -1.5 , incr = 0.02 ;

		if(doorX2 <= maxX-1.5  && doorOpenState == 1 ){
			doorX2+=incr;
			doorX1-=incr;
		}
		if(doorX2 > minX   && doorOpenState == 2 ){
			doorX1+=incr;
			doorX2-=incr;
		}
		if(keys[VK_NUMPAD9]){
			doorOpenState = 1 ;

		}
		if(keys[VK_NUMPAD7]){
			doorOpenState = 2 ;
		}

			glPushMatrix();
				glTranslated(2+doorX1 , 0 ,24);
				glRotated(180 , 0 , 1 , 0);
				glScaled(20 , 1 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-2+doorX2 , 0 , 24);
				glRotated(180 , 0 , 1 , 0);
				glScaled(20 , 1 , 1);
				s1.CubeTexture(2.5,0.1,img18,1,1);
			glPopMatrix();


		//sign
		glPushMatrix();
			glTranslated( 4 , 3 , 29.1);
			glRotated(180 , 0 , 1 , 0);
			s1.QuadTexture(0.5,1,sign12,1,1);
		glPopMatrix();

		//windows
		glPushMatrix();
		glRotated(90,1,0,0);
		glTranslated(-7,28.5,-31.5);
		s1.window(3 , 4,2 );
		glPopMatrix();

		glPushMatrix();
		glRotated(90,1,0,0);
		glTranslated(7,28.5,-31.5);
		s1.window(3 , 4 ,2);
		glPopMatrix();
	}

	////////////////////////////////////....<wall parts>....////////////////////////////////////
	void aqsa_wall (){
		//left

		{
		glPushMatrix();
			glTranslated(-100,0,0);
			glScaled(1,4,200);
			s1.CubeTexture(1,1,im0,30,1);
		glPopMatrix();

		glPushMatrix();
		for (int i=-200;i<=200;i+=5){
		glPushMatrix();
			glTranslated(-100,8,i);
			s1.CubeTexture(1,1,im0,1,1);
		glPopMatrix();
		}
		glPopMatrix();
		}
		//right
				{
		glPushMatrix();
			glTranslated(100,0,0);
			glRotated(180 , 0 , 1 , 0 );
			glScaled(1,4,200);
			s1.CubeTexture(1,1,im0,30,1);
		glPopMatrix();

		glPushMatrix();
		for (int i=-200;i<=200;i+=5){
		glPushMatrix();
			glTranslated(100,8,i);
			glRotated(180 , 0 , 1 , 0);
			s1.CubeTexture(1,1,im0,1,1);
		glPopMatrix();
		}
		glPopMatrix();
		}

		//back
		{
		glPushMatrix();
			glTranslated(0,0,-200);
			glScaled(100,4,1);
			s1.CubeTexture(1,1,im0,20,1);
		glPopMatrix();

		glPushMatrix();
		for (int i=-100;i<=100;i+=5){
		glPushMatrix();
			glTranslated(i,8,-200);
			s1.CubeTexture(1,1,im0,1,1);
		glPopMatrix();
		}
		glPopMatrix();
		}

		//front
		{
		glPushMatrix();
			glTranslated(0,0,200);
			glScaled(100,4,1);
			s1.CubeTexture(1,1,im0,20,1);
		glPopMatrix();

		glPushMatrix();
		for (int i=-100;i<=100;i+=5){
		glPushMatrix();
			glTranslated(i,8,200);
			s1.CubeTexture(1,1,im0,1,1);
		glPopMatrix();
		}
		glPopMatrix();
		}



		//gates

		//glPushMatrix();
		//	glTranslated(-100,0,125);
		//	glRotated(90,0,1,0);
		//	gate(sign1);
		//glPopMatrix();
		
		glPushMatrix();
			glTranslated(-100,0,75);
			glRotated(90,0,1,0);
			gate(sign1);
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(-100,0,25);
			glRotated(90,0,1,0);
			gate(sign3);
		glPopMatrix();
		
		/*glPushMatrix();
			glTranslated(-100,0,0);
			glRotated(90,0,1,0);
			gate(sign4);
		glPopMatrix();*/
		
		glPushMatrix();
			glTranslated(-100,0,-50);
			glRotated(90,0,1,0);
			gate(sign5);
		glPopMatrix();
		
		//glPushMatrix();
		//	glTranslated(-100,0,-125);
		//	glRotated(90,0,1,0);
		//	gate(sign6);
		//glPopMatrix();
		//
		//glPushMatrix();
		//	glTranslated(-100,0,-180);
		//	glRotated(90,0,1,0);
		//	gate(sign7);
		//glPopMatrix();
		
		glPushMatrix();
			glTranslated(-25,0,-200);	
			gate(sign8);
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(25,0,-200);
			gate(sign9);
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(90,0,-200);
			gate(sign10);
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(100,0,-50);
			glRotated(-90,0,1,0);
			gate(sign11);
		glPopMatrix();
	}

	void gate (int tex){

		glPushMatrix();
			glScaled(6.1,8,2);
			s1.CubeTexture(1,1,im17,1,1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-10,6,1.1);
			glRotated(180 , 0 , 1 , 0);
			s1.quadTL(1,2,tex,1,1);
		glPopMatrix();

	}

	///////////////////////////////////....<draw 3D Models>..../////////////////////////////////

	void draw_birds(){

		glPushMatrix();
			glRotated(xr,0,1,0);
			glTranslated(-25,80,0);
			glRotated(-45,0,0,1);
			bird->Draw();
		glPopMatrix();

		glPushMatrix();
			glRotated(xr,0,1,0);
			glTranslated(-30,80,5);
			glRotated(-45,0,0,1);
			bird->Draw();
		glPopMatrix();

		glPushMatrix();
			glRotated(xr,0,1,0);
			glTranslated(-35,80,5);
			glRotated(-45,0,0,1);
			bird->Draw();
		glPopMatrix();

		glPushMatrix();
			glRotated(xr,0,1,0);
			glTranslated(-40,80,0);
			glRotated(-45,0,0,1);
			bird->Draw();
		glPopMatrix();

		glPushMatrix();
			glRotated(xr,0,1,0);
			glTranslated(-32.5,80,10);
			glRotated(-45,0,0,1);
			bird->Draw();
		glPopMatrix();

		xr+=0.8;
	}

	void draw_tree(){
		glPushMatrix();
		glColor3f(1.0f , 1.0f , 1.0f);
			tree->Draw();
		glPopMatrix();
	}

	void draw_tree_in_arena(){
		//front
		glPushMatrix();
			glTranslated(7,0,-1);
			glRotated(180,0,1,0);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-7,0,-1);
			glRotated(360,0,1,0);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

		//left
		glPushMatrix();
			glTranslated(-50 , 0 , -40);
			glRotated(180 , 0 , 1 , 0);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-50 , 0 , -20);
			glRotated(180 , 0 , 1 , 0);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-50 , 0 , -60);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-50 , 0 , -80);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();
	
				glPushMatrix();
					glTranslated(-90 , 0 , -35);
					glRotated(180 , 0 , 1 , 0);
					glScaled(2,1,2);
					draw_tree();
				glPopMatrix();
			
				glPushMatrix();
					glTranslated(-90 , 0 , -20);
					glRotated(180 , 0 , 1 , 0);
					glScaled(2,1,2);
					draw_tree();
				glPopMatrix();
			
				glPushMatrix();
					glTranslated(-90 , 0 , -65);
					glScaled(2,1,2);
					draw_tree();
				glPopMatrix();
			
				glPushMatrix();
					glTranslated(-90 , 0 , -80);
					glScaled(2,1,2);
					draw_tree();
				glPopMatrix();

		//right
		glPushMatrix();
			glTranslated(50 , 0 , -40);
			glRotated(180 , 0 , 1 , 0);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

		glPushMatrix();
			glTranslated(50 , 0 , -20);
			glRotated(180 , 0 , 1 , 0);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

		glPushMatrix();
			glTranslated(50 , 0 , -60);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

		glPushMatrix();
			glTranslated(50 , 0 , -80);
			glScaled(2,1,2);
			draw_tree();
		glPopMatrix();

				glPushMatrix();
					glTranslated(90 , 0 , -35);
					glRotated(180 , 0 , 1 , 0);
					glScaled(2,1,2);
					draw_tree();
				glPopMatrix();
			
				glPushMatrix();
					glTranslated(90 , 0 , -20);
					glRotated(180 , 0 , 1 , 0);
					glScaled(2,1,2);
					draw_tree();
				glPopMatrix();
			
				glPushMatrix();
					glTranslated(90 , 0 , -65);
					glScaled(2,1,2);
					draw_tree();
				glPopMatrix();
			
				glPushMatrix();
					glTranslated(90 , 0 , -80);
					glScaled(2,1,2);
					draw_tree();
				glPopMatrix();
	}


};

// 63 , 59 , 50 //b

//155 , 140 , 109 //w

//140 , 129 , 109