#include "pch.h"
#include "hook.h"
#include "entity.h"
#include "game.h"

#ifdef DBG
#include <iostream>
#endif

Entity* Game::ball;
Entity* Game::battleCar;

Game::Game(Entity* battleCar, Entity* ball) {
    this->battleCar = battleCar;
    this->ball = ball;
    injectEntities();
}

void Game::hookEntities(SIZE_T* stack) {
    SIZE_T rcx = stack[0];
    //x is at [[rcx+770]+40]
    SIZE_T entityBase = *reinterpret_cast<SIZE_T*>(rcx + 0x770);
    if (entityBase) {
        float* x = reinterpret_cast<float*>(entityBase + 0x40);
        float* y = reinterpret_cast<float*>(entityBase + 0x48);
        float* z = reinterpret_cast<float*>(entityBase + 0x44);
        float* tfx = reinterpret_cast<float*>(entityBase + 0x160);
        float* tfy = reinterpret_cast<float*>(entityBase + 0x168);
        float* tfz = reinterpret_cast<float*>(entityBase + 0x164);
        float* rfx = reinterpret_cast<float*>(entityBase + 0x170);
        float* rfy = reinterpret_cast<float*>(entityBase + 0x178);
        float* rfz = reinterpret_cast<float*>(entityBase + 0x174);
        SIZE_T id_addr(entityBase + 0xfc);
        SIZE_T id = *reinterpret_cast<SIZE_T*>(id_addr);
        if (id == Entity::BALL_ID) {
            //ball
            int updateLocation = ball->updateLocation();
            if (updateLocation == UPDATE_X || updateLocation == UPDATE_XYZ) *x = ball->getX();
            if (updateLocation == UPDATE_Y || updateLocation == UPDATE_XYZ) *y = ball->getY();
            if (updateLocation == UPDATE_Z || updateLocation == UPDATE_XYZ) *z = ball->getZ();
            ball->onUpdateLocation(*x, *y, *z);
            int updateTranslationFactors = ball->updateTranslationFactors();
            if (updateTranslationFactors == UPDATE_X || updateTranslationFactors == UPDATE_XYZ) *tfx = ball->getTranslationFactorX();
            if (updateTranslationFactors == UPDATE_Y || updateTranslationFactors == UPDATE_XYZ) *tfy = ball->getTranslationFactorY();
            if (updateTranslationFactors == UPDATE_Z || updateTranslationFactors == UPDATE_XYZ) *tfz = ball->getTranslationFactorZ();
            ball->onUpdateTranslationFactors(*tfx, *tfy, *tfz);
            int updateRotationFactors = ball->updateRotationFactors();
            if (updateRotationFactors == UPDATE_X || updateRotationFactors == UPDATE_XYZ) *rfx = ball->getRotationFactorX();
            if (updateRotationFactors == UPDATE_Y || updateRotationFactors == UPDATE_XYZ) *rfy = ball->getRotationFactorY();
            if (updateRotationFactors == UPDATE_Z || updateRotationFactors == UPDATE_XYZ) *rfz = ball->getRotationFactorZ();
            ball->onUpdateRotationFactors(*rfx, *rfy, *rfz);
        }
        else {
            //battlecar
            int updateLocation = battleCar->updateLocation();
            if (updateLocation == UPDATE_X || updateLocation == UPDATE_XYZ) *x = battleCar->getX();
            if (updateLocation == UPDATE_Y || updateLocation == UPDATE_XYZ) *y = battleCar->getY();
            if (updateLocation == UPDATE_Z || updateLocation == UPDATE_XYZ) *z = battleCar->getZ();
            battleCar->onUpdateLocation(*x, *y, *z);
            int updateTranslationFactors = battleCar->updateTranslationFactors();
            if (updateTranslationFactors == UPDATE_X || updateTranslationFactors == UPDATE_XYZ) *tfx = battleCar->getTranslationFactorX();
            if (updateTranslationFactors == UPDATE_Y || updateTranslationFactors == UPDATE_XYZ) *tfy = battleCar->getTranslationFactorY();
            if (updateTranslationFactors == UPDATE_Z || updateTranslationFactors == UPDATE_XYZ) *tfz = battleCar->getTranslationFactorZ();
            battleCar->onUpdateTranslationFactors(*tfx, *tfy, *tfz);
            int updateRotationFactors = battleCar->updateRotationFactors();
            if (updateRotationFactors == UPDATE_X || updateRotationFactors == UPDATE_XYZ) *rfx = battleCar->getRotationFactorX();
            if (updateRotationFactors == UPDATE_Y || updateRotationFactors == UPDATE_XYZ) *rfy = battleCar->getRotationFactorY();
            if (updateRotationFactors == UPDATE_Z || updateRotationFactors == UPDATE_XYZ) *rfz = battleCar->getRotationFactorZ();
            battleCar->onUpdateRotationFactors(*rfx, *rfy, *rfz);
        }
    }
}

void Game::injectEntities() {
    SIZE_T off = 0xebd720;
    SIZE_T addr = (SIZE_T)GetModuleHandleA("RocketLeague.exe") + off;
    HookInjector injector(addr, 19, &hookEntities);
    injector.inject();
    #ifdef DBG
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "----- Backdoor injected -----" << std::endl;
    std::cout << "Name : Entities" << std::endl;
    std::cout << "Address : RocketLeague.exe + " << std::hex << off << std::endl;
    std::cout << "-----------------------------" << std::endl << std::endl;
    SetConsoleTextAttribute(hConsole, 8);
    #endif
}