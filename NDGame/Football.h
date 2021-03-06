// Football derived from Sprite Class - this is what player throws at football player
#ifndef FOOTBALL_H
#define FOOTBALL_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <typeinfo>
#include "LTexture.h"
#include "SDLClass.h"
#include "Sprite.h"
using namespace std;

class Football : public Sprite {

	public:
		Football(SDLClass &myC, int, int); //takes in x and y positions as arguments as well
		void setTextureClips(string path1, string path2);

		void draw(int); // int is to indicate if screen is scrolling

		//collision detection
		int collisionCheck(Sprite* enemy);
		int collisionLoopRect(vector<Sprite*>& enemyVector);

	private:
		int isInCollision; //indicates if football is in collision with football player

};

#endif
