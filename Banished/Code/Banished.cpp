#include "Game\Game.h"

int main(int argc, char** argv)
{
	Game banishedGame;

	if (banishedGame.init())
		banishedGame.run();

	banishedGame.release();

	return 0;
}