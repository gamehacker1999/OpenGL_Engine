#pragma once
#include<SDL.h>
class Component
{

public:
		// Constructor
		// (the lower the update order, the earlier the component updates)
		Component(class Actor* owner, int updateOrder = 100);
		// Destructor
		virtual ~Component();
		// Update this component by delta time
		virtual void Update(float deltaTime);
		virtual void ProcessInput(const Uint8* state);
		int GetUpdateOrder() const { return mUpdateOrder; }

		//update the world transform
		virtual void OnUpdateWorldTransform();
protected:
	// Owning actor
	class Actor* mOwner;
	// Update order of component
	int mUpdateOrder;
};

