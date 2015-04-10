/* Man derived from Sprite Class */
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "LTexture.h"
#include "SDLClass.h"
#include "Sprite.h"
using namespace std;

class Player : public Sprite {

	public: 
		Player(SDLClass &myC);
		void setTextureClips(string path1, string path2);
		void draw(); //draw sprite
		void update(); //use to update if screen should be scrolling

		//get and set methods
		void setMaxHeight(int);
		void setMinHeight(int);
		int getJumpingState();
		void setJumpingState(int);
		int getStopScreen();

	private:
		int maxHeight; //max jumping height
		int minHeight; //min jumping height
		int jumpingState; //3 states- not, up, down
		int stopScreen; //when character is walking, indicates if screen should be scrolling

		
};

#endif
