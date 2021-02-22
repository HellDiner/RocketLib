#include "entity.h"
class Game {
public:
	__declspec(dllexport) Game(Entity* battleCar, Entity* ball);
private:
	static void hookEntities(SIZE_T*);
	void injectEntities();
	static Entity* ball;
	static Entity* battleCar;
};