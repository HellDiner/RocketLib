# RocketLib
## Description
***RocketLib*** is a **Windows x64** library designed to easily create mods for RocketLeague.
## Requirements
-You must run under **Windows 64 bits**.  
-You will need to compile **LetsHook.dll** and **LetsHook.lib** from [LetsHook repository](https://github.com/HellDiner/LetsHook).  
-A **DLL injector** called **RocketLibInjector** is provided in the repository. You need to run it in the same directory as **LetsHook.dll**, **RocketLib.dll** and the DLLs you generate for your mods.  
## Coding
-After compiling the repository code into both a **.DLL** and a **.LIB**, start a new DLL project and include the **.LIB** as well as the **header files**.  
-You will want to include **game.h** and **entity.h** in you source files using `#include "game.h"` and `#include "entity.h"` to instantiate a new `Game(Entity* battleCar, Entity* ball)`. For better understanding, please read the example code below.  
-After your code is ready, **compile your DLL** and **inject it after the library DLL** into the target process / this process is automated using **RocketLibInjector** provided in this repository.  
## WARNING
This library was **not designed to provide any help in competitive mode** and distorting it that way is absolutely forbidden !  
## Example
This example will make the ball bounce if it takes too much speed while falling.  

```
#include "game.h"

[...]

Entity ball;
Entity battleCar;
Game game = Game(&battleCar, &ball);
int listenerIndex;

[...]

void listenFunc(float x, float y, float z) {
    if (y <= -20) {
        ball.setTranslationFactorY(20);
    }
    //ball.removeLocationListener(listenerIndex);
}

void init() {
    listenerIndex = ball.addTranslationFactorsListener(Vector3DListener(listenFunc));
}
```
