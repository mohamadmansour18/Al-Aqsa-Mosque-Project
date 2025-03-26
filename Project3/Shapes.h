#pragma once
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

class Shapes
{
public:
	int status ;
	int statusTwo ;

	Shapes(){
		status = 0 ;
		statusTwo = 1 ;
	}

	void QuadTexture (float length , float width , int texture, float repeatsX, float repeatsY){
		glEnable(GL_TEXTURE_2D);

		glPushMatrix();
		glColor3f(1.0f,1.0f,1.0f);
		glRotatef(90, 1, 0, 0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glBegin(GL_QUADS);
		{
			glNormal3f(0, 1, 0);

			glTexCoord2f(0, 0);
			glVertex3f(width, 0, length);

			glTexCoord2f(repeatsX, 0);
			glVertex3f(-width, 0, length);

			glTexCoord2f(repeatsX, repeatsY);
			glVertex3f(-width, 0, -length);

			glTexCoord2f(0, repeatsY);
			glVertex3f(width, 0, -length);
		}
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

	}

	void CubeTexture(float length , float width , int texture, float repeatsX, float repeatsY){

		//front
		glPushMatrix();
		glTranslated(0,length,width);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//back
		glPushMatrix();
		glTranslated(0,length,-width);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//right
		glPushMatrix();
		glTranslated(width,length,0);
		glRotated(90,0,1,0);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//left
		glPushMatrix();
		glTranslated(-width,length,0);
		glRotated(90,0,1,0);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslated(0,2*length,0);	
		glRotated(90,1,0,0);
		QuadTexture(width , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//down
		glPushMatrix();
		glRotated(90,1,0,0);
		QuadTexture(width , width , texture , repeatsX , repeatsY);
		glPopMatrix();
	}

	void Cube2Texture(float length , float width , int texture , int texture2 , float repeatsX, float repeatsY){

		//front
		glPushMatrix();
		glTranslated(0,length,width);
		QuadTexture(length , width , texture2 , repeatsX , repeatsY);
		glPopMatrix();

		//back
		glPushMatrix();
		glTranslated(0,length,-width);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//right
		glPushMatrix();
		glTranslated(width,length,0);
		glRotated(90,0,1,0);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//left
		glPushMatrix();
		glTranslated(-width,length,0);
		glRotated(90,0,1,0);
		glRotated(180 , 0 , 1 , 0);
		QuadTexture(length , width , texture2 , repeatsX , repeatsY);
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslated(0,2*length,0);	
		glRotated(90,1,0,0);
		QuadTexture(width , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//down
		glPushMatrix();
		glRotated(90,1,0,0);
		QuadTexture(width , width , texture , repeatsX , repeatsY);
		glPopMatrix();
	}

	void Cube3TextureWithDoor(float length , float width , int texture , int texture2 , GLubyte R , GLubyte G , GLubyte B , float repeatsX, float repeatsY){

		//front
		glPushMatrix();
		glTranslated(0,length,width);
		glRotated(180 , 0 , 1 , 0);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//back
		glPushMatrix();
		glTranslated(0 , 1.5*length , -width);
		glRotated(180 , 0 , 1 ,0 );
		QuadTexture(length/2 , width , texture2 , repeatsX , repeatsY);
		glPopMatrix();

		glPushMatrix();
		glTranslated(width*0.7 , length*0.5 , -width);
		glRotated(180 , 0 , 1 ,0 );
		QuadTexture(length*0.5 , width*0.3 , texture2 , repeatsX , repeatsY);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-width*0.7 , length*0.5 , -width);
		glRotated(180 , 0 , 1 ,0 );
		QuadTexture(length*0.5 , width*0.3 , texture2 , repeatsX , repeatsY);
		glPopMatrix();

		//right
		glPushMatrix();
		glTranslated(width,length,0);
		glRotated(90,0,1,0);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//left
		glPushMatrix();
		glTranslated(-width,length,0);
		glRotated(90,0,1,0);
		glRotated(180 , 0 , 1 ,0);
		QuadTexture(length , width , texture , repeatsX , repeatsY);
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslated(0,2*length,0);	
		glRotated(90,1,0,0);
		Quad(width , width , R , G , B);
		glPopMatrix();

		//down
		glPushMatrix();
		glRotated(90,1,0,0);
		Quad(width , width , R , G , B);
		glPopMatrix();
	}

	void SphareTextureR(double r , int texture)
	{
		int a ,
			b ,
			stepA = 10 ,
			stepB = 10 ;

		double pi = 3.14159265 ,
			stepI = stepA/10 ,
			stepJ = stepB/10 ,
			i = 0 ,
			j = 0 ;

		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glColor3f(1,1,1);

		glBindTexture(GL_TEXTURE_2D , texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		for(b=0 ; b<180 ; b+=stepB){
			for(a=0 ; a<360 ; a+=stepA){
				glNormal3f(
					cos((a + stepA / 2)*pi/180) * sin((b + stepB / 2)*pi/180), //xn
					sin((a + stepA / 2)*pi/180),								//yn
					cos((a + stepA / 2)*pi/180) * cos((b + stepB / 2)*pi/180)  //zn
					);



				glBegin(GL_QUADS);
				//POINT1
				glTexCoord2d(i,j);
				glVertex3d(
					r * cos(a*pi/180) * sin(b*pi/180), //x P1
					r * sin(a*pi/180),                 //y P2
					r * cos(a*pi/180) * cos(b*pi/180)  //z P3
					);

				//point2
				glTexCoord2d(i + stepI , j);
				glVertex3d(
					r * cos((a + stepA)*pi/180) * sin(b*pi/180), 
					r * sin((a + stepA)*pi/180),
					r * cos((a + stepA)*pi/180) * cos(b*pi/180)
					);

				//point3
				glTexCoord2d(i + stepI , j + stepJ);
				glVertex3d(
					r * cos((a + stepA)*pi/180) * sin((b + stepB)*pi/180), 
					r * sin((a + stepA)*pi/180),
					r * cos((a + stepA)*pi/180) * cos((b + stepB)*pi/180)
					);

				//point4
				glTexCoord2d(i , j + stepJ);
				glVertex3d(
					r * cos(a*pi/180) * sin((b + stepB)*pi/180), 
					r * sin(a*pi/180),
					r * cos(a*pi/180) * cos((b + stepB)*pi/180)
					);
				glEnd();
				i+=stepI;
			}
			i=0;
			j+=stepJ;
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void HalfSphareTextureR(double r , int texture)
	{
		int a ,
			b ,
			stepA = 10 ,
			stepB = 10 ;

		double pi = 3.14159265 ,
			stepI = stepA/10 ,
			stepJ = stepB/10 ,
			i = 0 ,
			j = 0 ;

		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glColor3f(1,1,1);

		glBindTexture(GL_TEXTURE_2D , texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		for(b=0 ; b<180 ; b+=stepB){
			for(a=0 ; a<180 ; a+=stepA){
				glNormal3f(
					cos((a + stepA / 2)*pi/180) * sin((b + stepB / 2)*pi/180), //xn
					sin((a + stepA / 2)*pi/180),                  //yn
					cos((a + stepA / 2)*pi/180) * cos((b + stepB / 2)*pi/180)  //zn
					);



				glBegin(GL_QUADS);
				//POINT1
				glTexCoord2d(i,j);
				glVertex3d(
					r * cos(a*pi/180) * sin(b*pi/180), //x P1
					r * sin(a*pi/180),                 //y P2
					r * cos(a*pi/180) * cos(b*pi/180)  //z P3
					);

				//point2
				glTexCoord2d(i + stepI , j);
				glVertex3d(
					r * cos((a + stepA)*pi/180) * sin(b*pi/180), 
					r * sin((a + stepA)*pi/180),
					r * cos((a + stepA)*pi/180) * cos(b*pi/180)
					);

				//point3
				glTexCoord2d(i + stepI , j + stepJ);
				glVertex3d(
					r * cos((a + stepA)*pi/180) * sin((b + stepB)*pi/180), 
					r * sin((a + stepA)*pi/180),
					r * cos((a + stepA)*pi/180) * cos((b + stepB)*pi/180)
					);

				//point4
				glTexCoord2d(i , j + stepJ);
				glVertex3d(
					r * cos(a*pi/180) * sin((b + stepB)*pi/180), 
					r * sin(a*pi/180),
					r * cos(a*pi/180) * cos((b + stepB)*pi/180)
					);
				glEnd();
				i+=stepI;
			}
			i=0;
			j+=stepJ;
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void SphareTexture(float radius, int texture) {

		int slices = 30 ;
		int stacks = 30 ;
		const float PI = 3.14159f;

		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		for(int i = 0; i < stacks; i++) {
			float theta1 = i * PI / stacks;
			float theta2 = (i + 1) * PI / stacks;

			glBegin(GL_QUAD_STRIP);
			for(int j = 0; j <= slices; j++) {
				float phi = j * 2 * PI / slices;

				float x = cos(phi) * sin(theta2);
				float y = cos(theta2);
				float z = sin(phi) * sin(theta2);

				glTexCoord2f((float)j / slices, (float)(i + 1) / stacks);
				glVertex3f(radius * x, radius * y, radius * z);

				x = cos(phi) * sin(theta1);
				y = cos(theta1);
				z = sin(phi) * sin(theta1);

				glNormal3f(x,y,z);
				glTexCoord2f((float)j / slices, (float)i / stacks);
				glVertex3f(radius * x, radius * y, radius * z);
			}
			glEnd();
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void HalfSphareTexture(float radius, int texture) {

		int slices = 30 ;
		int stacks = 30 ;
		const float PI = 3.14159f;

		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		for(int i = 0; i < stacks/2 ; i++) {
			float theta1 = i * PI / stacks;
			float theta2 = (i + 1) * PI / stacks;

			glBegin(GL_QUAD_STRIP);
			for(int j = 0; j <= slices; j++) {
				float phi = j * 2 * PI / slices;

				float x = cos(phi) * sin(theta2);
				float y = cos(theta2);
				float z = sin(phi) * sin(theta2);

				glTexCoord2f((float)j / slices, (float)(i + 1) / stacks);
				glVertex3f(radius * x, radius * y, radius * z);

				x = cos(phi) * sin(theta1);
				y = cos(theta1);
				z = sin(phi) * sin(theta1);

				glNormal3f(x,y,z);
				glTexCoord2f((float)j / slices, (float)i / stacks);
				glVertex3f(radius * x, radius * y, radius * z);
			}
			glEnd();
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void CylinderTexture(float radius , float height , int texture){

		const double PI = 3.14159f ;
		float tc ;
		double i , resolution = 0.1 ;

		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(radius , radius);
		glVertex3f(0 , height , 0);
		for(i = 2*PI ; i >= 0 ; i-=resolution){
			glTexCoord2f(radius*cos(i) + radius , radius*sin(i) + radius);
			glVertex3f(radius*cos(i) , 0 , radius*sin(i));
		}
		glEnd();

		glBegin(GL_QUAD_STRIP);
		for(i = 0 ; i <= 2*PI ; i+=resolution){
			tc = (i / (float)(2*PI));
			glNormal3f(cos(i) , 0 , sin(i));

			glTexCoord2f(tc , 0.0);
			glVertex3f(radius*cos(i) , 0 , radius*sin(i));
			glTexCoord2f(tc , 1.0);
			glVertex3f(radius*cos(i) , height , radius*sin(i));
		}
		glTexCoord2f(0.0 , 0.0);
		glVertex3f(radius , 0 , 0);
		glTexCoord2f(0.0 , 1.0);
		glVertex3f(radius , height , 0);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void OctagonTexture(float width , float length, int texture , GLubyte R , GLubyte G , GLubyte B){

		//front
		glPushMatrix();
		{
			glTranslated(0 , length , 2.41421356*width);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//right
		glPushMatrix();
		{
			glTranslated(1.70710678*width , length , 1.70710678*width);
			glRotated(45,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//left
		glPushMatrix();
		{
			glTranslated(-1.70710678*width , length , 1.70710678*width);
			glRotated(-45,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//left left
		glPushMatrix();
		{
			glTranslated(-2.41421356*width , length , 0);
			glRotated(-90,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//left left left
		glPushMatrix();
		{
			glTranslated(-1.70710678*width , length , -1.70710678*width);
			glRotated(-135,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//back
		glPushMatrix();
		{
			glTranslated(0, length , -2.41421356*width);
			glRotated(180,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//right right 
		glPushMatrix();
		{
			glTranslated(2.41421356*width , length , 0);
			glRotated(90,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//right right right 
		glPushMatrix();
		{
			glTranslated(1.70710678*width , length , -1.70710678*width);
			glRotated(135,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3ub(R,G,B);
			glBegin(GL_POLYGON);
			glVertex3f(width , 0.01 , -2.41421356*width);
			glVertex3f(2.41421356*width , 0.01 , -width);
			glVertex3f(2.41421356*width , 0.01 , width);
			glVertex3f(width , 0.01 , 2.41421356*width);
			glVertex3f(width , 0.01 , 2.41421356*width);
			glVertex3f(-width , 0.01 , 2.41421356*width);
			glVertex3f(-2.41421356*width , 0.01 , width);
			glVertex3f(-2.41421356*width , 0.01 , -width);
			glVertex3f(-width , 0.01 , -2.41421356*width);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3ub(R,G,B);
			glBegin(GL_POLYGON);
			glVertex3f(width , 2*length , -2.41421356*width);
			glVertex3f(2.41421356*width , 2*length , -width);
			glVertex3f(2.41421356*width , 2*length , width);
			glVertex3f(width , 2*length , 2.41421356*width);
			glVertex3f(width , 2*length , 2.41421356*width);
			glVertex3f(-width , 2*length , 2.41421356*width);
			glVertex3f(-2.41421356*width , 2*length , width);
			glVertex3f(-2.41421356*width , 2*length , -width);
			glVertex3f(-width , 2*length , -2.41421356*width);
			glEnd();
		}
		glPopMatrix();

	}

	void Skybox(float length , float  width , int texture , int texture2){

		if( statusTwo == 1){
			glEnable(GL_TEXTURE_2D);
			glColor3f(1.0f,1.0f,1.0f);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
			//1
			glPushMatrix();
			glBegin(GL_QUADS);
					glNormal3f(0, 0, 1);
				glTexCoord2f(0.25 , 0);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.25 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();

			//2
			glPushMatrix();
			glTranslated(0 , length*0.5 , -width*0.5);
			glRotated(-90 , 1 , 0 , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 0, 1);
				glTexCoord2f(0.25 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.25 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();

			//3
			glPushMatrix();
			glTranslated(0 , length , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 1, 0);
				glTexCoord2f(0.25 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 1);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.25 , 1);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();

			//4
			glPushMatrix();
			glTranslated(-width*0.5 , length*0.5 , 0);
			glRotated(90 , 0 , 0 , 1);
			glRotated(90 , 0 , 1 , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 0 , 1);
				glTexCoord2f(0 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.25 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.25 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();

			//5
			glPushMatrix();
			glTranslated(width*0.5 , length*0.5 , 0);
			glRotated(-90 , 0 , 0 , 1);
			glRotated(-90 , 0 , 1 , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 0 , 1);
				glTexCoord2f(0.50 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.75 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.75 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.50 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();


			//6
			glPushMatrix();
			glTranslated(0 , length*0.5 , width*0.5);
			glRotated(90 , 1 , 0 , 0);
			glRotated(-180 , 0 , 1 , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 0, 1);
				glTexCoord2f(0.75 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(1 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(1 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.75 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
		}

		if( status == 1 ){
			glEnable(GL_TEXTURE_2D);
			glColor3f(1.0f,1.0f,1.0f);
			glBindTexture(GL_TEXTURE_2D, texture2);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
			//1 down
			glPushMatrix();
			glBegin(GL_QUADS);
					glNormal3f(0, 0, 1);
				glTexCoord2f(0.25 , 0);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.25 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();

			//2 
			glPushMatrix();
			glTranslated(0 , length*0.5 , -width*0.5);
			glRotated(-90 , 1 , 0 , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 0, 1);
				glTexCoord2f(0.25 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.25 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();

			//3 top
			glPushMatrix();
			glTranslated(0 , length , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 0, 1);
				glTexCoord2f(0.25 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.50 , 1);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.25 , 1);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();

			//4
			glPushMatrix();
			glTranslated(-width*0.5 , length*0.5 , 0);
			glRotated(90 , 0 , 0 , 1);
			glRotated(90 , 0 , 1 , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 0, 1);
				glTexCoord2f(0 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.25 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.25 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();

			//5
			glPushMatrix();
			glTranslated(width*0.5 , length*0.5 , 0);
			glRotated(-90 , 0 , 0 , 1);
			glRotated(-90 , 0 , 1 , 0);
			glBegin(GL_QUADS);
					glNormal3f(0, 0, 1);
				glTexCoord2f(0.50 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.75 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(0.75 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.50 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();


			//6
			glPushMatrix();
			glTranslated(0 , length*0.5 , width*0.5);
			glRotated(90 , 1 , 0 , 0);
			glRotated(-180 , 0 , 1 , 0);
			glBegin(GL_QUADS);
				glNormal3f(0, 0, 1);
				glTexCoord2f(0.75 , 0.3333);
				glVertex3d(-width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(1 , 0.3333);
				glVertex3d(width*0.5 , -0.035 , -length*0.5);
				glTexCoord2f(1 , 0.6666);
				glVertex3d(width*0.5 , -0.035 , length*0.5);
				glTexCoord2f(0.75 , 0.6666);
				glVertex3d(-width*0.5 , -0.035 , length*0.5);
			glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
		}
	}

	void OctagonT1(float width , float length, int texture){
		glEnable(GL_TEXTURE_2D);

		glPushMatrix();
		glColor3f(1.0f,1.0f,1.0f);
		glBindTexture(GL_TEXTURE_2D, texture);
		{
			glBegin(GL_POLYGON);
			glTexCoord2f(width , -2.41421356*width);
			glVertex3f(width , -0.02 , -2.41421356*width); 

			glTexCoord2f(2.41421356*width , -width);
			glVertex3f(2.41421356*width , -0.02 , -width);

			glTexCoord2f(2.41421356*width , width);
			glVertex3f(2.41421356*width , -0.02 , width);

			glTexCoord2f(width , 2.41421356*width);
			glVertex3f(width , -0.02 , 2.41421356*width);

			glTexCoord2f(width , 2.41421356*width);
			glVertex3f(width , -0.02 , 2.41421356*width);

			glTexCoord2f(-width , 2.41421356*width);
			glVertex3f(-width , -0.02 , 2.41421356*width);

			glTexCoord2f(-2.41421356*width , width);
			glVertex3f(-2.41421356*width , -0.02 , width);

			glTexCoord2f(-2.41421356*width , -width);
			glVertex3f(-2.41421356*width , -0.02 , -width);

			glTexCoord2f(-width , -2.41421356*width);
			glVertex3f(-width , -0.02 , -2.41421356*width);
			glEnd();
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void OctagonTextureWithDoor(int texture , GLubyte R , GLubyte G , GLubyte B){
		float width = 6.0f;
		float length = 5.0f;

		//front
		glPushMatrix();
		{
			glTranslated(0 , 0 , 2.41421356*width);
			door(texture);
		}
		glPopMatrix();

		//right
		glPushMatrix();
		{
			glTranslated(1.70710678*width , length , 1.70710678*width);
			glRotated(45,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//left
		glPushMatrix();
		{
			glTranslated(-1.70710678*width , length , 1.70710678*width);
			glRotated(-45,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//left left
		glPushMatrix();
		{
			glTranslated(-2.41421356*width , 0 , 0);
			glRotated(-90,0,1,0);
			door(texture);
		}
		glPopMatrix();

		//left left left
		glPushMatrix();
		{
			glTranslated(-1.70710678*width , length , -1.70710678*width);
			glRotated(-135,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		//back
		glPushMatrix();
		{
			glTranslated(0, 0 , -2.41421356*width);
			glRotated(180,0,1,0);
			door(texture);
		}
		glPopMatrix();

		//right right 
		glPushMatrix();
		{
			glTranslated(2.41421356*width , 0 , 0);
			glRotated(90,0,1,0);
			door(texture);
		}
		glPopMatrix();

		//right right right 
		glPushMatrix();
		{
			glTranslated(1.70710678*width , length , -1.70710678*width);
			glRotated(135,0,1,0);
			QuadTexture(length , width , texture , 1 ,1);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3ub(R,G,B);
			glBegin(GL_POLYGON);
			glVertex3f(width , -0.01 , -2.41421356*width);
			glVertex3f(2.41421356*width , -0.01 , -width);
			glVertex3f(2.41421356*width , -0.01 , width);
			glVertex3f(width , -0.01 , 2.41421356*width);
			glVertex3f(width , -0.01 , 2.41421356*width);
			glVertex3f(-width , -0.01 , 2.41421356*width);
			glVertex3f(-2.41421356*width , -0.01 , width);
			glVertex3f(-2.41421356*width , -0.01 , -width);
			glVertex3f(-width , -0.01 , -2.41421356*width);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3ub(R,G,B);
			glBegin(GL_POLYGON);
			glVertex3f(width , 2*length , -2.41421356*width);
			glVertex3f(2.41421356*width , 2*length , -width);
			glVertex3f(2.41421356*width , 2*length , width);
			glVertex3f(width , 2*length , 2.41421356*width);
			glVertex3f(width , 2*length , 2.41421356*width);
			glVertex3f(-width , 2*length , 2.41421356*width);
			glVertex3f(-2.41421356*width , 2*length , width);
			glVertex3f(-2.41421356*width , 2*length , -width);
			glVertex3f(-width , 2*length , -2.41421356*width);
			glEnd();
		}
		glPopMatrix();

	}

	void roof(int tex1  , GLubyte R , GLubyte G , GLubyte B ){
		glPushMatrix();

		glNormal3f(0,0,-1);
		glEnable(GL_TEXTURE_2D);
		glColor3f(1.0f,1.0f,1.0f);
		glBindTexture(GL_TEXTURE_2D, tex1);

		glBegin(GL_TRIANGLES);
		glTexCoord2d(0,0);
		glVertex3f(-1,0,1);
		glTexCoord2d(0,1);
		glVertex3f(1,0,1);
		glTexCoord2d(0.5,0.5);
		glVertex3f(0,2,1);
		glEnd();
		glDisable(GL_TEXTURE_2D);


		glEnable(GL_TEXTURE_2D);
		glColor3f(1.0f,1.0f,1.0f);
		glBindTexture(GL_TEXTURE_2D, tex1);

		glBegin(GL_TRIANGLES);
		glTexCoord2d(0,0);
		glVertex3f(-1,0,-1);
		glTexCoord2d(0,1);
		glVertex3f(1,0,-1);
		glTexCoord2d(0.5,0.5);
		glVertex3f(0,2,-1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.5,1,0);
		glRotated(-26,0,0,1);
		glRotated(90,0,1,0);
		Quad(1.1 , 1 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.5,1,0);
		glRotated(26,0,0,1);
		glRotated(90,0,1,0);
		Quad(1.1,1,R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,0,0);
		glRotated(90,1,0,0);
		Quad(1,1,R , G , B);
		glPopMatrix();
		glEnd();
	}
	
	void window (float length , float width,int x){

		glPushMatrix();
		glBlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA); 
		glEnable(GL_BLEND);
		glTranslatef(0,0,28.5);
		switch (x)
		{
		case 1 :
			glColor4f(0.5f,0.5f,0.5f,0.6f);
		break;
		case 2 :
			glColor4f(0.2f,0.2f,0.2f,0.8f);
		

		}
		
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(width, 0, length);
		glVertex3f(width, 0, -length);
		glVertex3f(-width, 0, -length);
		glVertex3f(-width, 0, length);
		glEnd();
		glDisable(GL_BLEND);
		glPopMatrix();
	}



	////////////////////////////////////////////////////////////////////////////////

	void Quad (float length , float width , GLubyte R , GLubyte G , GLubyte B){
		glPushMatrix();
		glRotatef(90, 1, 0, 0);
		glBegin(GL_QUADS);
		{
			glNormal3f(0, 1, 0);
			glColor3ub(R,G,B);
			glVertex3f(width, 0, length);
			glColor3ub(R,G,B);
			glVertex3f(width, 0, -length);
			glColor3ub(R,G,B);
			glVertex3f(-width, 0, -length);
			glColor3ub(R,G,B);
			glVertex3f(-width, 0, length);
		}
		glEnd();
		glPopMatrix();
	}

	void Cube(float length , float width , GLubyte R , GLubyte G , GLubyte B){
		//front
		glPushMatrix();
		glTranslated(0,length,width);
		Quad(length , width , R ,  G , B);
		glPopMatrix();

		//back
		glPushMatrix();
		glTranslated(0,length,-width);
		Quad(length , width , R , G , B);
		glPopMatrix();

		//right
		glPushMatrix();
		glTranslated(width,length,0);
		glRotated(90,0,1,0);
		Quad(length , width , R , G , B);
		glPopMatrix();

		//left
		glPushMatrix();
		glTranslated(-width,length,0);
		glRotated(90,0,1,0);
		Quad(length , width , R , G , B);
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslated(0,2*length,0);	
		glRotated(90,1,0,0);
		Quad(width , width , R , G , B);
		glPopMatrix();

		//down
		glPushMatrix();
		glRotated(90,1,0,0);
		Quad(width , width , R , G , B);
		glPopMatrix();
	}

	void Sphare(double r , GLubyte R , GLubyte G , GLubyte B)
	{
		int a ,
			b ,
			stepA = 10 ,
			stepB = 10 ;

		double pi = 3.14159265 ,
			stepI = stepA/10 ,
			stepJ = stepB/10 ,
			i = 0 ,
			j = 0 ;

		glPushMatrix();
		for(b=0 ; b<180 ; b+=stepB){
			for(a=0 ; a<360 ; a+=stepA){
				glNormal3f(
					cos((a + stepA / 2)*pi/180) * sin((b + stepB / 2)*pi/180), //xn
					sin((a + stepA / 2)*pi/180),                  //yn
					cos((a + stepA / 2)*pi/180) * cos((b + stepB / 2)*pi/180)  //zn
					);

				glBegin(GL_QUADS);
				//POINT1
				glTexCoord2d(i,j);
				glColor3ub(R,G,B);
				glVertex3d(
					r * cos(a*pi/180) * sin(b*pi/180), //x P1
					r * sin(a*pi/180),                 //y P2
					r * cos(a*pi/180) * cos(b*pi/180)  //z P3
					);

				//point2
				glTexCoord2d(i + stepI , j);
				glColor3ub(R,G,B);
				glVertex3d(
					r * cos((a + stepA)*pi/180) * sin(b*pi/180), 
					r * sin((a + stepA)*pi/180),
					r * cos((a + stepA)*pi/180) * cos(b*pi/180)
					);

				//point3
				glTexCoord2d(i + stepI , j + stepJ);
				glColor3ub(R,G,B);
				glVertex3d(
					r * cos((a + stepA)*pi/180) * sin((b + stepB)*pi/180), 
					r * sin((a + stepA)*pi/180),
					r * cos((a + stepA)*pi/180) * cos((b + stepB)*pi/180)
					);

				//point4
				glTexCoord2d(i , j + stepJ);
				glColor3ub(R,G,B);
				glVertex3d(
					r * cos(a*pi/180) * sin((b + stepB)*pi/180), 
					r * sin(a*pi/180),
					r * cos(a*pi/180) * cos((b + stepB)*pi/180)
					);
				glEnd();
				i+=stepI;
			}
			i=0;
			j+=stepJ;
		}
		glPopMatrix();
	}

	void HalfSphare(double r , GLubyte R , GLubyte G , GLubyte B)
	{
		int a ,
			b ,
			stepA = 10 ,
			stepB = 10 ;

		double pi = 3.14159265 ,
			stepI = stepA/10 ,
			stepJ = stepB/10 ,
			i = 0 ,
			j = 0 ;

		glPushMatrix();
		for(b=0 ; b<180 ; b+=stepB){
			for(a=0 ; a<180 ; a+=stepA){
				glNormal3f(
					cos((a + stepA / 2)*pi/180) * sin((b + stepB / 2)*pi/180), //xn
					sin((a + stepA / 2)*pi/180),                  //yn
					cos((a + stepA / 2)*pi/180) * cos((b + stepB / 2)*pi/180)  //zn
					);

				glBegin(GL_QUADS);
				//POINT1
				glTexCoord2d(i,j);
				glColor3ub(R,G,B);
				glVertex3d(
					r * cos(a*pi/180) * sin(b*pi/180), //x P1
					r * sin(a*pi/180),                 //y P2
					r * cos(a*pi/180) * cos(b*pi/180)  //z P3
					);

				//point2
				glTexCoord2d(i + stepI , j);
				glColor3ub(R,G,B);
				glVertex3d(
					r * cos((a + stepA)*pi/180) * sin(b*pi/180), 
					r * sin((a + stepA)*pi/180),
					r * cos((a + stepA)*pi/180) * cos(b*pi/180)
					);

				//point3
				glTexCoord2d(i + stepI , j + stepJ);
				glColor3ub(R,G,B);
				glVertex3d(
					r * cos((a + stepA)*pi/180) * sin((b + stepB)*pi/180), 
					r * sin((a + stepA)*pi/180),
					r * cos((a + stepA)*pi/180) * cos((b + stepB)*pi/180)
					);

				//point4
				glTexCoord2d(i , j + stepJ);
				glColor3ub(R,G,B);
				glVertex3d(
					r * cos(a*pi/180) * sin((b + stepB)*pi/180), 
					r * sin(a*pi/180),
					r * cos(a*pi/180) * cos((b + stepB)*pi/180)
					);
				glEnd();
				i+=stepI;
			}
			i=0;
			j+=stepJ;
		}
		glPopMatrix();
	}

	void Cylinder(float radius , float height ,  GLubyte R , GLubyte G , GLubyte B) {

		const float pi = 3.14159f;
		int sides = 30;

		glPushMatrix();
		glNormal3f(1, 0, 0);
		glBegin(GL_QUADS);

		for (int i = 0; i < sides; i++) {
			float theta1 = 2.0f * pi * float(i) / float(sides);
			float theta2 = 2.0f * pi * float(i + 1) / float(sides);
			glNormal3f(cos(theta1) , -height / 2 , sin(theta1));
			 
			// Bottom face
			glColor3ub(R,G,B);
			glVertex3f(radius * cos(theta1), -height / 2, radius * sin(theta1));
			glVertex3f(radius * cos(theta2), -height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta2), height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta1), height / 2, radius * sin(theta1));

			// Top face
			glColor3ub(R,G,B);
			glVertex3f(radius * cos(theta1), height / 2, radius * sin(theta1));
			glVertex3f(radius * cos(theta2), height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta2), -height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta1), -height / 2, radius * sin(theta1));

			// Side face
			glColor3ub(R,G,B);
			glVertex3f(radius * cos(theta1), height / 2, radius * sin(theta1));
			glVertex3f(radius * cos(theta2), height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta2), -height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta1), -height / 2, radius * sin(theta1));
		}
		glEnd();
		glPopMatrix();
	}

	void HalfCylinder(float radius , float height ,  GLubyte R , GLubyte G , GLubyte B) {

		const float pi = 3.14159f;
		int sides = 30;

		glPushMatrix();
		glNormal3f(1, 0, 0);
		glBegin(GL_QUADS);

		for (int i = 0; i < sides/2 ; i++) {
			float theta1 = 2.0f * pi * float(i) / float(sides);
			float theta2 = 2.0f * pi * float(i + 1) / float(sides);

			// Bottom face
			glColor3ub(R,G,B);
			glVertex3f(radius * cos(theta1), -height / 2, radius * sin(theta1));
			glVertex3f(radius * cos(theta2), -height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta2), height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta1), height / 2, radius * sin(theta1));

			// Top face
			glColor3ub(R,G,B);
			glVertex3f(radius * cos(theta1), height / 2, radius * sin(theta1));
			glVertex3f(radius * cos(theta2), height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta2), -height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta1), -height / 2, radius * sin(theta1));

			// Side face
			glColor3ub(R,G,B);
			glVertex3f(radius * cos(theta1), height / 2, radius * sin(theta1));
			glVertex3f(radius * cos(theta2), height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta2), -height / 2, radius * sin(theta2));
			glVertex3f(radius * cos(theta1), -height / 2, radius * sin(theta1));
		}
		glEnd();
		glPopMatrix();
	}

	void Octagon(float width , float length , GLubyte R , GLubyte G , GLubyte B){

		//front
		glPushMatrix();
		{
			glTranslated(0 , length , 2.41421356*width);
			Quad(length , width , R , G ,B);
		}
		glPopMatrix();

		//right
		glPushMatrix();
		{
			glTranslated(1.70710678*width , length , 1.70710678*width);
			glRotated(45,0,1,0);
			Quad(length , width , R , G ,B);
		}
		glPopMatrix();

		//left
		glPushMatrix();
		{
			glTranslated(-1.70710678*width , length , 1.70710678*width);
			glRotated(-45,0,1,0);
			Quad(length , width , R , G ,B);
		}
		glPopMatrix();

		//left left
		glPushMatrix();
		{
			glTranslated(-2.41421356*width , length , 0);
			glRotated(90,0,1,0);
			Quad(length , width , R , G ,B);
		}
		glPopMatrix();

		//left left left
		glPushMatrix();
		{
			glTranslated(-1.70710678*width , length , -1.70710678*width);
			glRotated(45,0,1,0);
			Quad(length , width , R , G ,B);
		}
		glPopMatrix();

		//back
		glPushMatrix();
		{
			glTranslated(0, length , -2.41421356*width);
			Quad(length , width , R , G ,B);
		}
		glPopMatrix();

		//right right 
		glPushMatrix();
		{
			glTranslated(2.41421356*width , length , 0);
			glRotated(90,0,1,0);
			Quad(length , width , R , G ,B);
		}
		glPopMatrix();

		//right right right 
		glPushMatrix();
		{
			glTranslated(1.70710678*width , length , -1.70710678*width);
			glRotated(-45,0,1,0);
			Quad(length , width , R , G ,B);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3ub(60,60,60);
			glBegin(GL_POLYGON);
			glVertex3f(width , 0 , -2.41421356*width);
			glVertex3f(2.41421356*width , 0 , -width);
			glVertex3f(2.41421356*width , 0 , width);
			glVertex3f(width , 0 , 2.41421356*width);
			glVertex3f(width , 0 , 2.41421356*width);
			glVertex3f(-width , 0 , 2.41421356*width);
			glVertex3f(-2.41421356*width , 0 , width);
			glVertex3f(-2.41421356*width , 0 , -width);
			glVertex3f(-width , 0 , -2.41421356*width);
			glEnd();
		}
		glPopMatrix();

	}

	void door(int texture){
		glEnable(GL_TEXTURE_2D);

		glColor3f(1.0f,1.0f,1.0f);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glPushMatrix();
		{
			//left part
			glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0,0);
			glVertex2d(-6,0);
			glTexCoord2f( 0.3333,0);
			glVertex2d(-2,0);
			glTexCoord2f( 0.3333,0.4);
			glVertex2d(-2,4);
			glTexCoord2f( 0,0.4);
			glVertex2d(-6,4);
			glEnd();
			//right part
			glBegin(GL_QUADS);
			glNormal3f(0,0,1);

			glTexCoord2f(0,0);
			glVertex2d(6,0);
			glTexCoord2f( 0.3333,0);
			glVertex2d(2,0);
			glTexCoord2f( 0.3333,0.4);
			glVertex2d(2,4);
			glTexCoord2f( 0,0.4);
			glVertex2d(6,4);
			glEnd();
			//up part
			glBegin(GL_QUADS);
			glNormal3f(0,0,1);

			glTexCoord2f(1,1);
			glVertex2d(-6,10);

			glTexCoord2f(0,1);
			glVertex2d(6,10);

			glTexCoord2f(0,0.4);
			glVertex2d(6,4);

			glTexCoord2f(1,0.4);
			glVertex2d(-6,4);
			glEnd();
		}
		glPopMatrix();
	}

	void qantara(GLubyte R , GLubyte G , GLubyte B){

		glNormal3f(0, 1, 0);
		glPushMatrix();	
		glColor3ub(R , G , B);

		glBegin(GL_QUADS);
		glVertex3d(-1.5,2,0);
		glVertex3d(-1,2,0);
		glVertex3d(-0.928,2.128,0);
		glVertex3d(-1.5,2.118,0);

		glVertex3d(-1.5,2.118,0);
		glVertex3d(-0.928,2.128,0);
		glVertex3d(-0.808,2.273,0);
		glVertex3d(-1.372,2.358,0);

		glVertex3d(-1.372,2.358,0);
		glVertex3d(-0.808,2.273,0);
		glVertex3d(-0.694,2.376,0);
		glVertex3d(-1.210,2.575,0);

		glVertex3d(-1.210,2.575,0);
		glVertex3d(-0.694,2.376,0);
		glVertex3d(-0.562,2.466,0);
		glVertex3d(-1.043,2.737,0);

		glVertex3d(-1.043,2.737,0);
		glVertex3d(-0.562,2.466,0);
		glVertex3d(-0.422,2.535,0);
		glVertex3d(-0.861,2.870,0);

		glVertex3d(-0.861,2.870,0);
		glVertex3d(-0.422,2.535,0);
		glVertex3d(-0.281,2.582,0);
		glVertex3d(-0.634,2.989,0);

		glVertex3d(-0.634,2.989,0);
		glVertex3d(-0.281,2.582,0);
		glVertex3d(-0.136,2.610,0);
		glVertex3d(-0.425,3.061,0);

		glVertex3d(-0.425,3.061,0);
		glVertex3d(-0.136,2.610,0);
		glVertex3d(0,2.618,0);
		glVertex3d(-0.209,3.104,0);
		glEnd();


		glBegin(GL_TRIANGLES);
		glVertex3d(-0.209,3.104,0);
		glVertex3d(0,2.618,0);
		glVertex3d(0,3.118,0);
		glEnd();




		glBegin(GL_QUADS);
		glVertex3d( 1.5,2,0);
		glVertex3d( 1,2,0);
		glVertex3d( 0.928,2.128,0);
		glVertex3d( 1.5,2.118,0);

		glVertex3d( 1.5,2.118,0);
		glVertex3d( 0.928,2.128,0);
		glVertex3d( 0.808,2.273,0);
		glVertex3d( 1.372,2.358,0);

		glVertex3d( 1.372,2.358,0);
		glVertex3d( 0.808,2.273,0);
		glVertex3d( 0.694,2.376,0);
		glVertex3d( 1.210,2.575,0);

		glVertex3d( 1.210,2.575,0);
		glVertex3d( 0.694,2.376,0);
		glVertex3d( 0.562,2.466,0);
		glVertex3d( 1.043,2.737,0);

		glVertex3d( 1.043,2.737,0);
		glVertex3d( 0.562,2.466,0);
		glVertex3d( 0.422,2.535,0);
		glVertex3d( 0.861,2.870,0);

		glVertex3d( 0.861,2.870,0);
		glVertex3d( 0.422,2.535,0);
		glVertex3d( 0.281,2.582,0);
		glVertex3d( 0.634,2.989,0);

		glVertex3d( 0.634,2.989,0);
		glVertex3d( 0.281,2.582,0);
		glVertex3d( 0.136,2.610,0);
		glVertex3d( 0.425,3.061,0);

		glVertex3d( 0.425,3.061,0);
		glVertex3d( 0.136,2.610,0);
		glVertex3d(0,2.618,0);
		glVertex3d( 0.209,3.104,0);
		glEnd();


		glBegin(GL_TRIANGLES);
		glVertex3d( 0.209,3.104,0);
		glVertex3d(0,2.618,0);
		glVertex3d(0,3.118,0);
		glEnd();


		glBegin(GL_QUADS);
		glVertex3d(-1.5,2,1);
		glVertex3d(-1,2,1);
		glVertex3d(-0.928,2.128,1);
		glVertex3d(-1.5,2.118,1);

		glVertex3d(-1.5,2.118,1);
		glVertex3d(-0.928,2.128,1);
		glVertex3d(-0.808,2.273,1);
		glVertex3d(-1.372,2.358,1);

		glVertex3d(-1.372,2.358,1);
		glVertex3d(-0.808,2.273,1);
		glVertex3d(-0.694,2.376,1);
		glVertex3d(-1.210,2.575,1);

		glVertex3d(-1.210,2.575,1);
		glVertex3d(-0.694,2.376,1);
		glVertex3d(-0.562,2.466,1);
		glVertex3d(-1.043,2.737,1);

		glVertex3d(-1.043,2.737,1);
		glVertex3d(-0.562,2.466,1);
		glVertex3d(-0.422,2.535,1);
		glVertex3d(-0.861,2.870,1);

		glVertex3d(-0.861,2.870,1);
		glVertex3d(-0.422,2.535,1);
		glVertex3d(-0.281,2.582,1);
		glVertex3d(-0.634,2.989,1);

		glVertex3d(-0.634,2.989,1);
		glVertex3d(-0.281,2.582,1);
		glVertex3d(-0.136,2.610,1);
		glVertex3d(-0.425,3.061,1);

		glVertex3d(-0.425,3.061,1);
		glVertex3d(-0.136,2.610,1);
		glVertex3d(0,2.618,1);
		glVertex3d(-0.209,3.104,1);
		glEnd();


		glBegin(GL_TRIANGLES);
		glVertex3d(-0.209,3.104,1);
		glVertex3d(0,2.618,1);
		glVertex3d(0,3.118,1);
		glEnd();




		glBegin(GL_QUADS);
		glVertex3d( 1.5,2,1);
		glVertex3d( 1,2,1);
		glVertex3d( 0.928,2.128,1);
		glVertex3d( 1.5,2.118,1);

		glVertex3d( 1.5,2.118,1);
		glVertex3d( 0.928,2.128,1);
		glVertex3d( 0.808,2.273,1);
		glVertex3d( 1.372,2.358,1);

		glVertex3d( 1.372,2.358,1);
		glVertex3d( 0.808,2.273,1);
		glVertex3d( 0.694,2.376,1);
		glVertex3d( 1.210,2.575,1);

		glVertex3d( 1.210,2.575,1);
		glVertex3d( 0.694,2.376,1);
		glVertex3d( 0.562,2.466,1);
		glVertex3d( 1.043,2.737,1);

		glVertex3d( 1.043,2.737,1);
		glVertex3d( 0.562,2.466,1);
		glVertex3d( 0.422,2.535,1);
		glVertex3d( 0.861,2.870,1);

		glVertex3d( 0.861,2.870,1);
		glVertex3d( 0.422,2.535,1);
		glVertex3d( 0.281,2.582,1);
		glVertex3d( 0.634,2.989,1);

		glVertex3d( 0.634,2.989,1);
		glVertex3d( 0.281,2.582,1);
		glVertex3d( 0.136,2.610,1);
		glVertex3d( 0.425,3.061,1);

		glVertex3d( 0.425,3.061,1);
		glVertex3d( 0.136,2.610,1);
		glVertex3d(0,2.618,1);
		glVertex3d( 0.209,3.104,1);
		glEnd();


		glBegin(GL_TRIANGLES);
		glVertex3d( 0.209,3.104,1);
		glVertex3d(0,2.618,1);
		glVertex3d(0,3.118,1);
		glEnd();


		glBegin(GL_QUAD_STRIP);

		glVertex3d(-1,2,0);
		glVertex3d(-1,2,1);
		glVertex3d(-0.928,2.128,0);
		glVertex3d(-0.928,2.128,1);
		glVertex3d(-0.808,2.273,0);
		glVertex3d(-0.808,2.273,1);
		glVertex3d(-0.694,2.376,0);
		glVertex3d(-0.694,2.376,1);
		glVertex3d(-0.562,2.466,0);
		glVertex3d(-0.562,2.466,1);
		glVertex3d(-0.422,2.535,0);
		glVertex3d(-0.422,2.535,1);
		glVertex3d(-0.281,2.582,0);
		glVertex3d(-0.281,2.582,1);
		glVertex3d(-0.136,2.610,0);
		glVertex3d(-0.136,2.610,1);
		glVertex3d(0,2.618,0);
		glVertex3d(0,2.618,1);
		/**/
		glVertex3d(0.136,2.610,0);
		glVertex3d(0.136,2.610,1);
		glVertex3d(0.281,2.582,0);
		glVertex3d(0.281,2.582,1);
		glVertex3d(0.422,2.535,0);
		glVertex3d(0.422,2.535,1);
		glVertex3d(0.562,2.466,0);
		glVertex3d(0.562,2.466,1);
		glVertex3d(0.694,2.376,0);
		glVertex3d(0.694,2.376,1);
		glVertex3d(0.808,2.273,0);
		glVertex3d(0.808,2.273,1);
		glVertex3d(0.928,2.128,0);
		glVertex3d(0.928,2.128,1);
		glVertex3d(1,2,0);
		glVertex3d(1,2,1);

		glEnd();



		glBegin(GL_QUAD_STRIP);
		glVertex3d(1.5,2,0);
		glVertex3d(1.5,2,1);
		glVertex3d(1.5,2.118,0);
		glVertex3d(1.5,2.118,1);
		glVertex3d(1.372,2.358,0);
		glVertex3d(1.372,2.358,1);
		glVertex3d(1.210,2.575,0);
		glVertex3d(1.210,2.575,1);
		glVertex3d(1.043,2.737,0);
		glVertex3d(1.043,2.737,1);
		glVertex3d(0.861,2.870,0);
		glVertex3d(0.861,2.870,1);
		glVertex3d(0.634,2.989,0);
		glVertex3d(0.634,2.989,1);
		glVertex3d(0.425,3.061,0);
		glVertex3d(0.425,3.061,1);
		glVertex3d(0.209,3.104,0);
		glVertex3d(0.209,3.104,1);
		glVertex3d(0,3.118,0);
		glVertex3d(0,3.118,1);
		/**/
		glVertex3d(-0.209,3.104,0);
		glVertex3d(-0.209,3.104,1);
		glVertex3d(-0.425,3.061,0);
		glVertex3d(-0.425,3.061,1);
		glVertex3d(-0.634,2.989,0);
		glVertex3d(-0.634,2.989,1);
		glVertex3d(-0.861,2.870,0);
		glVertex3d(-0.861,2.870,1);
		glVertex3d(-1.043,2.737,0);
		glVertex3d(-1.043,2.737,1);
		glVertex3d(-1.210,2.575,0);
		glVertex3d(-1.210,2.575,1);
		glVertex3d(-1.372,2.358,0);
		glVertex3d(-1.372,2.358,1);
		glVertex3d(-1.5,2.118,0);
		glVertex3d(-1.5,2.118,1);
		glVertex3d(-1.5,2,0);
		glVertex3d(-1.5,2,1);

		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(-1.5,2,1);
		glVertex3d(-1,2,1);
		glVertex3d(-1,2,0);
		glVertex3d(-1.5,2,0);

		glEnd();
		glPopMatrix();
	}

	void qantara2(GLubyte R , GLubyte G , GLubyte B){
		//front
		glColor3ub( R , G , B);
		glBegin(GL_QUAD_STRIP);

		glVertex3d(-1.5,0,1);
		glVertex3d(-1.5,1.5,1);

		glVertex3d(-1,0,1);
		glVertex3d(-1,1.5,1);

		glVertex3d(-0.937,0.173,1);
		glVertex3d(-0.937,1.5,1);

		glVertex3d(-0.853,0.337,1);
		glVertex3d(-0.853,1.5,1);

		glVertex3d(-0.750,0.490,1);
		glVertex3d(-0.750,1.5,1);

		glVertex3d(-0.625,0.625,1);
		glVertex3d(-0.625,1.5,1);

		glVertex3d(-0.490,0.750,1);
		glVertex3d(-0.490,1.5,1);

		glVertex3d(-0.337,0.853,1);
		glVertex3d(-0.337,1.5,1);

		glVertex3d(-0.173,0.937,1);
		glVertex3d(-0.173,1.5,1);

		glVertex3d(0,1,1);
		glVertex3d(0,1.5,1);

		glVertex3d(0.173,0.937,1);
		glVertex3d(0.173,1.5,1);

		glVertex3d(0.337,0.853,1);
		glVertex3d(0.337,1.5,1);

		glVertex3d(0.490,0.750,1);
		glVertex3d(0.490,1.5,1);

		glVertex3d(0.625,0.625,1);
		glVertex3d(0.625,1.5,1);

		glVertex3d(0.750,0.490,1);
		glVertex3d(0.750,1.5,1);

		glVertex3d(0.853,0.337,1);
		glVertex3d(0.853,1.5,1);

		glVertex3d(0.937,0.173,1);
		glVertex3d(0.937,1.5,1);

		glVertex3d(1,0,1);
		glVertex3d(1,1.5,1);

		glVertex3d(1.5,0,1);
		glVertex3d(1.5,1.5,1);

		glEnd();

		//back
		glBegin(GL_QUAD_STRIP);

		glVertex3d(-1.5,0,-1);
		glVertex3d(-1.5,1.5,-1);

		glVertex3d(-1,0,-1);
		glVertex3d(-1,1.5,-1);

		glVertex3d(-0.937,0.173,-1);
		glVertex3d(-0.937,1.5,-1);

		glVertex3d(-0.853,0.337,-1);
		glVertex3d(-0.853,1.5,-1);

		glVertex3d(-0.750,0.490,-1);
		glVertex3d(-0.750,1.5,-1);

		glVertex3d(-0.625,0.625,-1);
		glVertex3d(-0.625,1.5,-1);

		glVertex3d(-0.490,0.750,-1);
		glVertex3d(-0.490,1.5,-1);

		glVertex3d(-0.337,0.853,-1);
		glVertex3d(-0.337,1.5,-1);

		glVertex3d(-0.173,0.937,-1);
		glVertex3d(-0.173,1.5,-1);

		glVertex3d(0,1,-1);
		glVertex3d(0,1.5,-1);

		glVertex3d(0.173,0.937,-1);
		glVertex3d(0.173,1.5,-1);

		glVertex3d(0.337,0.853,-1);
		glVertex3d(0.337,1.5,-1);

		glVertex3d(0.490,0.750,-1);
		glVertex3d(0.490,1.5,-1);

		glVertex3d(0.625,0.625,-1);
		glVertex3d(0.625,1.5,-1);

		glVertex3d(0.750,0.490,-1);
		glVertex3d(0.750,1.5,-1);

		glVertex3d(0.853,0.337,-1);
		glVertex3d(0.853,1.5,-1);

		glVertex3d(0.937,0.173,-1);
		glVertex3d(0.937,1.5,-1);

		glVertex3d(1,0,-1);
		glVertex3d(1,1.5,-1);

		glVertex3d(1.5,0,-1);
		glVertex3d(1.5,1.5,-1);

		glEnd();

		//bottom
		glBegin(GL_QUAD_STRIP);

		glVertex3d(-1.5,0,1);
		glVertex3d(-1.5,0,-1);

		glVertex3d(-1,0,1);
		glVertex3d(-1,0,-1);

		glVertex3d(-0.937,0.173,1);
		glVertex3d(-0.937,0.173,-1);

		glVertex3d(-0.853,0.337,1);
		glVertex3d(-0.853,0.337,-1);

		glVertex3d(-0.750,0.490,1);
		glVertex3d(-0.750,0.490,-1);

		glVertex3d(-0.625,0.625,1);
		glVertex3d(-0.625,0.625,-1);

		glVertex3d(-0.490,0.750,1);
		glVertex3d(-0.490,0.750,-1);

		glVertex3d(-0.337,0.853,1);
		glVertex3d(-0.337,0.853,-1);

		glVertex3d(-0.173,0.937,1);
		glVertex3d(-0.173,0.937,-1);

		glVertex3d(0,1,1);
		glVertex3d(0,1,-1);

		glVertex3d(0.173,0.937,1);
		glVertex3d(0.173,0.937,-1);

		glVertex3d(0.337,0.853,1);
		glVertex3d(0.337,0.853,-1);

		glVertex3d(0.490,0.750,1);
		glVertex3d(0.490,0.750,-1);

		glVertex3d(0.625,0.625,1);
		glVertex3d(0.625,0.625,-1);

		glVertex3d(0.750,0.490,1);
		glVertex3d(0.750,0.490,-1);

		glVertex3d(0.853,0.337,1);
		glVertex3d(0.853,0.337,-1);

		glVertex3d(0.937,0.173,1);
		glVertex3d(0.937,0.173,-1);

		glVertex3d(1,0,1);
		glVertex3d(1,0,-1);

		glVertex3d(1.5,0,1);
		glVertex3d(1.5,0,-1);

		glEnd();

		//other side
		glBegin(GL_QUAD_STRIP);
		glVertex3d(-1.5,0,1);
		glVertex3d(-1.5,0,-1);

		glVertex3d(-1.5,1.5,1);
		glVertex3d(-1.5,1.5,-1);

		glVertex3d(1.5,1.5,1);
		glVertex3d(1.5,1.5,-1);

		glVertex3d(1.5,0,1);
		glVertex3d(1.5,0,-1);

		glEnd();


	}

	void prymid(GLubyte R , GLubyte G , GLubyte B){
		glColor3ub(R , G , B);
		glBegin(GL_TRIANGLES);
		glNormal3f(0 , 1 , 0);
		glVertex3f(-1,0,1);
		glVertex3f(1,0,1);
		glVertex3f(0,2,0);

		glVertex3f(1,0,1);
		glVertex3f(1,0,-1);
		glVertex3f(0,2,0);

		glVertex3f(-1,0,-1);
		glVertex3f(1,0,-1);
		glVertex3f(0,2,0);

		glVertex3f(-1,0,-1);
		glVertex3f(-1,0,1);
		glVertex3f(0,2,0);
		glEnd();


		glBegin(GL_QUADS);
		glVertex3f(-1,0,-1);
		glVertex3f(-1,0,1);
		glVertex3f(1,0,1);
		glVertex3f(1,0,-1);
		glEnd();
	}

	///////////////////////////////////////////////////////////////////////////////////

	void staries(int texture){
		glPushMatrix();
		CubeTexture(0.5 , 9 , texture , 1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,1,1.1);
		CubeTexture(0.5 , 9 , texture , 1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,2,2.2);
		CubeTexture(0.5 , 9 , texture , 1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,3,3.3);
		CubeTexture(0.5 , 9 , texture , 1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,4,4.4);
		CubeTexture(0.5 , 9 , texture , 1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,5,5.4);
		CubeTexture(0.5 , 9 , texture , 1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,6,6.5);
		CubeTexture(0.5 , 9 , texture , 1,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,7,7.6);
		CubeTexture(0.5 , 9 , texture , 1,1);
		glPopMatrix();
	}

	void roof_tringle(int text){
		//1
		glPushMatrix();
		glTranslated(4,0,0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-4,0,0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 ,text , 1 , 1);
		glPopMatrix();
		//2
		glPushMatrix();
		glTranslated(3.4 , 0.4 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-3.4 , 0.4 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslated(2.8 , 0.8 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 ,text , 1 , 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-2.8 , 0.8 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslated(2.2 , 1.2 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-2.2 , 1.2 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();
		//5
		glPushMatrix();
		glTranslated(1.6 , 1.6 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-1.6 , 1.6 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();
		//6
		glPushMatrix();
		glTranslated(1 , 2 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-1 , 2 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 ,text , 1 , 1);
		glPopMatrix();
		//7
		glPushMatrix();
		glTranslated(0.5 , 2.4 , 0);
		glScaled(0.1,1,1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.5 , 2.4 , 0);
		glScaled(0.1 , 1 , 1);
		CubeTexture(0.2 , 2 , text , 1 , 1);
		glPopMatrix();
		//8
		glPushMatrix();
		glTranslated(0 , 2.8 , 0);
		glScaled(0.2,1,1);
		CubeTexture(0.2 , 2 ,text , 1 , 1);
		glPopMatrix();

	}

	void stariesColor(GLubyte R , GLubyte G , GLubyte B){
		glPushMatrix();
		Cube(0.5 , 9 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,1,1.1);
		Cube(0.5 , 9 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,2,2.2);
		Cube(0.5 , 9 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,3,3.3);
		Cube(0.5 , 9 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,4,4.4);
		Cube(0.5 , 9 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,5,5.4);
		Cube(0.5 , 9 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,6,6.5);
		Cube(0.5 , 9 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,7,7.6);
		Cube(0.5 , 9 , R , G , B);
		glPopMatrix();
	}

	void Castle_cube(GLubyte R , GLubyte G , GLubyte B){
		glPushMatrix();
		Cube(0.1 , 0.4 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.31 , 0.1 , 0.31);
		Cube(0.15 , 0.1 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.31 , 0.1 , 0.31);
		Cube(0.15 , 0.1 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.31 , 0.1 , -0.31);
		Cube(0.15 , 0.1 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.31 , 0.1 , -0.31);
		Cube(0.15 , 0.1 , R , G , B);
		glPopMatrix();
	}

	void Castle_cube2(GLubyte R , GLubyte G , GLubyte B){
		glPushMatrix();
		glScaled(1,1,0.3);
		Cube(0.1 , 0.4 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,0.2,0);
		glScaled(1,1,0.3);
		Cube(0.1 , 0.30 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,0.4,0);
		glScaled(1,1,0.3);
		Cube(0.1 , 0.20 , R , G , B);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,0.6,0);
		glScaled(1,1,0.3);
		Cube(0.1 , 0.10 , R , G , B);
		glPopMatrix();
	}

	////////////////////////////////////////////////////////////////////////////////////

	void CubeTexture4(float length , float width , int texture1 ,int texture2, float repeatsX, float repeatsY){

		//front
		glPushMatrix();
		glTranslated(0,length,width);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//back
		glPushMatrix();
		glTranslated(0,length,-width);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//right
		glPushMatrix();
		glTranslated(width,length,0);
		glRotated(90,0,1,0);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//left
		glPushMatrix();
		glTranslated(-width,length,0);
		glRotated(90,0,1,0);
		glRotated(180 , 0 , 1 , 0);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslated(0,2*length,0);	
		glRotated(90,1,0,0);
		QuadTexture(width , width , texture2 , repeatsX , repeatsY);
		glPopMatrix();

		//down
		glPushMatrix();
		glRotated(90,1,0,0);
		Quad(width , width , 60 , 60 , 60);
		glPopMatrix();
	}

	void CubeTextureforqibli(float length , float width , int texture1 ,int texture2, float repeatsX, float repeatsY){

		//front
		glPushMatrix();
		glTranslated(0,length,width);
		QuadTexture(length , width , texture1 , repeatsX/4 , repeatsY);
		glPopMatrix();

		//back
		glPushMatrix();
		glTranslated(0,length,-width);
		QuadTexture(length , width , texture1 , repeatsX/4 , repeatsY);
		glPopMatrix();

		//right
		glPushMatrix();
		glTranslated(width,length,0);
		glRotated(90,0,1,0);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//left
		glPushMatrix();
		glTranslated(-width,length,0);
		glRotated(90,0,1,0);
		glRotated(180 , 0 , 1 , 0);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslated(0,2*length,0);	
		glRotated(90,1,0,0);
		QuadTexture(width , width , texture2 , repeatsX , repeatsY);
		glPopMatrix();

		//down
		glPushMatrix();
		glRotated(90,1,0,0);
		Quad(width , width , 60 , 60 , 60);
		glPopMatrix();
	}

	void CubeTexturewithdoorO(float length , float width , int texture1 ,int texture2, float repeatsX, float repeatsY){

		//front
		/*	the main face

		glPushMatrix();
		glTranslated(0,length,width);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();*/

		glPushMatrix();
		glTranslated(-width/1.5,length,width);
		QuadTextureo(length , width/3 , texture1 ,0,0, repeatsX/3 , repeatsY);
		glPopMatrix();

		glPushMatrix();
		glTranslated(width/1.5,length,width);
		QuadTextureo(length , width/3 , texture1 ,0,0, repeatsX/3 , repeatsY);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,1.5*length,width);
		QuadTextureo(length/2 , width/3 , texture1 , 0 , repeatsY/2, repeatsX/3 , repeatsY);
		glPopMatrix();/**/




		//back
		glPushMatrix();
		glTranslated(0,length,-width);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//right
		glPushMatrix();
		glTranslated(width,length,0);
		glRotated(90,0,1,0);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//left
		glPushMatrix();
		glTranslated(-width,length,0);
		glRotated(90,0,1,0);
		glRotated(180 , 0 , 1 , 0);
		QuadTexture(length , width , texture1 , repeatsX , repeatsY);
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslated(0,2*length,0);	
		glRotated(90,1,0,0);
		QuadTexture(width , width , texture2 , repeatsX , repeatsY);
		glPopMatrix();

		//down
		glPushMatrix();
		glRotated(90,1,0,0);
		Quad(width , width , 60 , 60 , 60);
		glPopMatrix();
	}

	void QuadTextureo (float length , float width , int texture, float repeatsX1, float repeatsY1, float repeatsX2, float repeatsY2){
		glEnable(GL_TEXTURE_2D);

		glPushMatrix();
		glColor3f(1.0f,1.0f,1.0f);
		glRotatef(90, 1, 0, 0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glBegin(GL_QUADS);
		{
			glNormal3f(0, 1, 0);

			glTexCoord2f(repeatsX1, repeatsY1);
			glVertex3f(width, 0, length);

			glTexCoord2f(repeatsX2, repeatsY1);
			glVertex3f(-width, 0, length);

			glTexCoord2f(repeatsX2, repeatsY2);
			glVertex3f(-width, 0, -length);

			glTexCoord2f(repeatsX1, repeatsY2);
			glVertex3f(width, 0, -length);
		}
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

	}

	void quadTL(float length , float width , int texture, float repeatsX, float repeatsY){
		glEnable(GL_TEXTURE_2D);

		glPushMatrix();
		glColor3f(1.0f,1.0f,1.0f);
		glRotatef(90, 1, 0, 0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glBegin(GL_QUADS);
		{
			glNormal3f(0, -1, 0);

			glTexCoord2f(0, 0);
			glVertex3f(width, 0, length);

			glTexCoord2f(repeatsX, 0);
			glVertex3f(-width, 0, length);

			glTexCoord2f(repeatsX, repeatsY);
			glVertex3f(-width, 0, -length);

			glTexCoord2f(0, repeatsY);
			glVertex3f(width, 0, -length);
		}
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

	}
};


