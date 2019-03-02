#pragma once
#include<SDL.h>
#include<map>
#include<vector>
#include "Vector2.h"
#include "SpriteComponent.h"
#include "Ship.h"
class Game
{
public:
	Game();
	//Initialize the game
	bool Start();
	//Game loop
	void Update();
	//Shutdown game
	void Shutdown();

	//Adding removing actor
	void AddActor(class Actor* actor);
	void RemoveActor(class  Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	SDL_Texture* GetTexture(std::string file);

	SDL_Texture* LoadTexture(std::string filename);

	~Game();

private:
	//Helper functions for game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();



	//Window created by SDL
	SDL_Window* mWindow;
	//Renderer
	SDL_Renderer* mRenderer;
	//game should continue to run
	bool mIsRunning;


	float mTickerCount;

	int mPaddleDir;

	//actor fields
	std::vector < class Actor* > mActors;
	std::vector < class  Actor* > mPendingActors;
	bool mUpdatingActors;

	//Texture fields 
	std::map<std::string, SDL_Texture*> textures;

	//Function to load all data
	void LoadData();
	void UnloadData();

	//Fields and functions for sprites
	std::vector <class SpriteComponent*> mSprites;

	//Ship
	class Ship* mShip;

	
};

