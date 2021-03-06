#include "Sprite.h"
#include "Football.h"
#include "Footballer.h"
#include "Car1.h"
#include "Car2.h"

Football::Football(SDLClass &myC, int x, int y) : Sprite(myC)
{
	setTextureClips("resources/football.png", "resources/football.png");
	setSpeed(5,0);
	setPos(x, y); //set position
	isInCollision=0;
}

void Football::setTextureClips(string path1, string path2)
{
	//load image
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips=1; //n of sprites on sheet
	setNumClips(totalClips);

	addClip(0, 0, 67, 41);

	spriteBox.w=67;
	spriteBox.h=41;

}

//if s==0, use actualSpeed. 
//if s==1, the screen is scrolling. use actualSpeed+extraSpeed. extra accounts for the extra speed
//so that the football doesn't slow down when the player moves
void Football::draw(int s)
{
	moveRight();
	Sprite::draw(s);
}

int Football::collisionLoopRect(vector<Sprite*>& enemyVector)
{
	int check=0;

	Sprite* ptr; //use to determine what kind of sprite

	for (int i=0; i<enemyVector.size(); i++)
	{
		check=0;

		//add is loaded if statement
		check=collisionCheck(enemyVector[i]);

		ptr=enemyVector[i];

		if (check==1)
		{
			if (isInCollision==1)
			{
				isInCollision=0;
			}
		}

		//check to see what kind of sprite player has collided with
		if (check)
		{
			//if footballer hit, destroy the footballer and remove from enemy vector
			if (typeid(*ptr)==typeid(Footballer))
			{
				ptr->destroySprite();
				enemyVector.erase(enemyVector.begin()+i);
				i--;
				return 1; //if footballer hit, return 1
			}
                        if (typeid(*ptr)==typeid(Car1) || typeid(*ptr)==typeid(Car2)) 
                        {
                                return 1;
                        }
		}
	}
	return 0; //if no footballer hit, return 0
}

//check if football has collided with enemy
int Football::collisionCheck(Sprite* enemy)
{
	SDL_bool value;
	SDL_Rect enemyRect;

	enemyRect.x = enemy->spriteBox.x;
	enemyRect.y = enemy->spriteBox.y;
	enemyRect.h = enemy->spriteBox.h;
	enemyRect.w = enemy->spriteBox.w;

	value = SDL_HasIntersection(&spriteBox, &enemyRect);

	if (value==SDL_TRUE)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}
