/* Sprite class for the sprite that the user controls */

#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "LTexture.h"
#include "SDLClass.h"

enum SpriteStates {
	isResting, //use first two for state variable
	isWalking,
	isNotJumping, //use the next three for jumpingState member variable
	isJumpingUp,
	isJumpingDown
};

class Sprite {
	
	public:
		Sprite(SDLClass &myC);
		virtual ~Sprite(); 		// virtual destructor in order to delete derived pointers
		virtual void setTextureClips(string path1, string path2)=0;     //sets sheets of derived classes
		void loadSheetFromFile(string path); //load sprite sheet
		void loadFlippedSheetFromFile(string path); //load flipped sprite sheet
		void destroySprite();
		void addClip(int, int, int, int);       // add sprite clips to vector
		void addFlippedClip(int, int, int, int);        // add flipped sprite clips to vector

		void basicDraw(); //basic drawing functionality that all sprites must use -- not directly used by user but be used in draw function below
		void checkCurrentClip(); //check if currentClip needs to be set to 0. Also not used directly by user but must be used in draw function
		virtual void draw(int); //uses basicDraw in base class and can be changed for derived classes
		void update(); //not all sprite classes may use this

		//change sprite's position
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

		void incrementCurrentClip();    // increment to next clip to be used for animation

		//get and set functions
		int getX();
		int getY();
		void setPos(int x, int y);
		int getH();
		int getW();
		void setSize(int w, int h);
		void setNumClips(int);
		void setCurrentClip(int);
		void setState(int);
		int getState();
		void setFacingRight(int);
		int getHalfOfScreen(); //return halfway point of screen in x direction
		int getFacingRight();
		int getXPos();
		int getYPos();
		int getSpeedX();
		int getSpeedY();
		void setSpeed(int,int);
		int getCurrentClip();
		void incrementSpeed(); //increase speed
		void setMaxSpeed(int);
		void setW(int); //set width
		void setH(int); //set height

		//collision detection box	
		SDL_Rect spriteBox;


	private:
		LTexture spriteSheet;	
		LTexture flippedSheet; //for when character walks the other way
		vector<SDL_Rect> spriteClips;
		vector<SDL_Rect> flippedClips; //for when character walks the other way

		SDLClass *mySDL; //pointer to SDL

		int height;
		int width;

		string texturePath;	
		int numOfClips; //number of clips
		int currentClip; //number indicating index of current clip
		int xPos; //x position
		int yPos; //y position
		int speedX;
		int speedY;
		int maxSpeed; //max speed - use for player since he goes faster when he eats hotdog
		int state; // isResting, isWalking, or isJumping
		bool facingRight; //1 if walking right, 0 if walking left
		
};

#endif
