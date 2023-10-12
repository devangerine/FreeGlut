#include <iostream>
#include <GL\glut.h>

using namespace std;

void displayFunction();
void displayQuadEyes();
void displayQuadFace();
void displayLineMouth();
void wasdESCFunc(unsigned char key, int x, int y);
void mouseClickFunc(int button, int state, int x, int y);

						//Left Eye Coords            //Right Eye Coords
float xCoordEyes[8] = {-0.65f, -0.4f, -0.4f, -0.65f, 0.5f, 0.75f, 0.75f, 0.5f};
float yCoordEyes[8] = {0.25f, 0.25f, 0.5f, 0.5f, 0.25f, 0.25f, 0.5f, 0.5f};

float xCoordFace[4] = {-0.95f, 0.95f, 0.95f, -0.95f};
float yCoordFace[4] = {-1.0f, -1.0f, 1.0f, 1.0f,};

float xCoordMouth[2] = {-0.45, 0.5f};
float yCoordMouth[2] = {-0.5f, -0.5f};

float leftEyeRGB[3] = {1.0f, 0.0f, 0.0f};
int leftEyeCounter = 1; //Counter to keep track of left mouse clicks

float rightEyeRGB[3] = {1.0f, 0.0f, 0.0f};
int rightEyeCounter = 1; //Counter to keep track of right mouse clicks

int main(int argc, char **argv){
	
	glutInit(&argc, argv);
	//glutInitWindowSize(1024,768);
	glutCreateWindow("Lab 5 - glVertex Face");
	glutDisplayFunc(displayFunction);
	glutKeyboardFunc(wasdESCFunc);
	glutMouseFunc(mouseClickFunc);
	glutMainLoop();
	
	
	return 0;
}

//Function to display the eyes of the face using the quads primitive
void displayQuadEyes(){
	
	glBegin(GL_QUADS);
	
	//Left Eye
	glColor3f(leftEyeRGB[0], leftEyeRGB[1], leftEyeRGB[2]);
	glVertex2f(xCoordEyes[0], yCoordEyes[0]); //Lower Left
	glVertex2f(xCoordEyes[1], yCoordEyes[1]); //Lower Right
	glVertex2f(xCoordEyes[2], yCoordEyes[2]); //Upper Right
	glVertex2f(xCoordEyes[3], yCoordEyes[3]); //Upper Left
	
	//Right Eye
	glColor3f(rightEyeRGB[0], rightEyeRGB[1], rightEyeRGB[2]);
	glVertex2f(xCoordEyes[4], yCoordEyes[4]); //Lower Left
	glVertex2f(xCoordEyes[5], yCoordEyes[5]); //Lower Right
	glVertex2f(xCoordEyes[6], yCoordEyes[6]); //Upper Right
	glVertex2f(xCoordEyes[7], yCoordEyes[7]); //Upper Left
	
	
	glEnd();
	
	
}

//function to displau outline of the face using the quads primitive
void displayQuadFace(){
	
	glBegin(GL_QUADS);
	glVertex2f(xCoordFace[0], yCoordFace[0]); //Lower Left
	glVertex2f(xCoordFace[1], yCoordFace[1]); //Lower Right
	glVertex2f(xCoordFace[2], yCoordFace[2]); //Upper Right
	glVertex2f(xCoordFace[3], yCoordFace[3]); //Upper Left	
	glEnd();
	
	
}

//function to display the mouth of the face using the lines primitive
void displayLineMouth(){
	
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glVertex2f(xCoordMouth[0], yCoordMouth[0]); //Lower Left
	glVertex2f(xCoordMouth[1], yCoordMouth[1]); //Lower Right
	
	glEnd();
	
	
}

void wasdESCFunc(unsigned char key, int x, int y){
	
	//Switch case for wasd and ESC key detection
	cout<<key<<" Key Pressed"<<endl;
	switch(key){
		
		case 'w':
			
			//Coordinate Adjustment for Eyes
			for(int i = 0; i<8; i++){
				yCoordEyes[i] += 0.125f;
			}
			
			//Coordinate Adjustment for Face
			for(int i = 0; i<4; i++){
				yCoordFace[i] += 0.125f;
			}
			
			//Coordinate Adjustment for Mouth
			for(int i = 0; i<2; i++){
				yCoordMouth[i] += 0.125f;
			}
			
			break;
		
		case 'a':
			
			//Coordinate Adjustment for Eyes
			for(int i = 0; i<8; i++){
				xCoordEyes[i] -= 0.125f;
			}
			
			//Coordinate Adjustment for Face
			for(int i = 0; i<4; i++){
				xCoordFace[i] -= 0.125f;
			}
			
			//Coordinate Adjustment for Mouth
			for(int i = 0; i<2; i++){
				xCoordMouth[i] -= 0.125f;
			}
			
				
			break;
			
		case 's':
			
			//Coordinate Adjustment for Eyes
			for(int i = 0; i<8; i++){
				yCoordEyes[i] -= 0.125f;
			}
			
			//Coordinate Adjustment for Face
			for(int i = 0; i<4; i++){
				yCoordFace[i] -= 0.125f;
			}
			
			//Coordinate Adjustment for Mouth
			for(int i = 0; i<2; i++){
				yCoordMouth[i] -= 0.125f;
			}
		
			break;
			
		case 'd':
			
			//Coordinate Adjustment for Eyes
			for(int i = 0; i<8; i++){
				xCoordEyes[i] += 0.125f;
			}
			
			//Coordinate Adjustment for Face
			for(int i = 0; i<4; i++){
				xCoordFace[i] += 0.125f;
			}
			
			//Coordinate Adjustment for Mouth
			for(int i = 0; i<2; i++){
				xCoordMouth[i] += 0.125f;
			}
			
			break;
		
		case 27: //ESC Key
			exit(0);
			break;
			
		default:
			
			break;
		
	}
	
	glutPostRedisplay();
}

void mouseClickFunc(int button, int state, int x, int y){
	
		switch(button){
			
			case GLUT_LEFT_BUTTON:
			//	cout<<"Left Mouse Key Clicked"<<endl;
				if(leftEyeCounter == 1){
					leftEyeRGB[2] = 1.0f;
					leftEyeCounter++;
				}
				else if(leftEyeCounter == 2){
					leftEyeRGB[0] = 0.0f;
					leftEyeCounter++;
				}
				else{
					leftEyeRGB[0] = 1.0f;
					leftEyeRGB[2] = 0.0f;
					leftEyeCounter = 1;
				}
				
				break;
				
				
			case GLUT_RIGHT_BUTTON:
			//	cout<<"Right Mouse Key Clicked"<<endl;
				if(rightEyeCounter == 1){
					rightEyeRGB[2] = 1.0f;
					rightEyeCounter++;
				}
				else if(rightEyeCounter == 2){
					rightEyeRGB[0] = 0.0f;
					rightEyeCounter++;
				}
				else{
					rightEyeRGB[0] = 1.0f;
					rightEyeRGB[2] = 0.0f;
					rightEyeCounter = 1;
				}
				
				break;
				
				
				
			default:
			
				break;
			
			
			
		}
	
	
	
}
//main display function
void displayFunction(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0f,1.0f,0.0f);
	displayQuadFace();       //Must be called first otherwise it will cover the other parts of the face
	
	//glColor3f(1.0f,0.0f,0.0f);
	displayQuadEyes();
	
	glColor3f(0.0f,0.0f,1.0f);
	displayLineMouth(); 
	
	glFlush();
	
}


