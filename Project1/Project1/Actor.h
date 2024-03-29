#pragma once
#include <SDL.h>
#include "Component.h"
#include "Vector2.h"
#include"Math.h"
#include<math.h>
#include <algorithm>
#include <vector>
//#include"MeshComponent.h"
//#include"Mesh.h"

class MeshComponent;

class Actor
{
public:

	enum class State
	{
		EActive,
		EPaused,
		EDead
		
	};
	Actor(class Game* game);


	virtual  ~Actor();

	//update function called from game non overridable
	void Update(float deltaTime);
	//Update components non ovveridable
	void UpdateComponents(float deltaTime);
	//Overridable actor specific code
	virtual void UpdateActor(float deltaTime);

	//Getters and setters
	State GetState();
	float GetScale() const { return mScale; }
	Vector3 GetPosition() const { return position; }
	Quaternion GetRotation() const { return mRotation; }
	Game* GetGame() const { return mGame; }
	Vector3 GetForward() const { return Vector3::Transform(Vector3::UnitX, mRotation); }
	Vector3 GetRight() const { return Vector3::Transform(Vector3::UnitY,mRotation); }
	Vector3 GetUp() const { return Vector3::Transform(Vector3::UnitZ, mRotation); }
	Matrix4& GetWorldTransform() { return worldTransform; }

	void SetPosition(Vector3 pos) { position = pos; }
	void SetScale(float scale) { mScale = scale; }
	void SetRotation(Quaternion rot) { mRotation = rot; }
	void SetMesh(class Mesh* mesh);

	//Add remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	//Process input called from game
	void ProcessInput(const Uint8* state);
	//Actor input called by child actors
	virtual void ActorInput(const Uint8* state);

	//Transform actor
	void CreateWorldTransform();


private:
	//Actor state
	State mState;

	//Transform
	Vector3 position;
	float mScale;
	Quaternion mRotation;

	//Members to compute transform
	Matrix4 worldTransform; //Assume we have a z component with a w component
	bool recomputeWorldTransform; //Recompute transform if any of the properties change

	//List of components
	std::vector<class Component* > mComponents;

	class Game* mGame;

	MeshComponent* meshComp;

};

