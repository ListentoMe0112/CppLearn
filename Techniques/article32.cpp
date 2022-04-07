#include "article32.h"
#include <iostream>
#include <cxxabi.h>

using namespace std;
void SpaceShip::collide(GameObject& otherObject){
    HitFunctionPtr hfp = lookup(otherObject);
    if (hfp){
        (this->*hfp)(otherObject);
    }else{
        cout << "Sorry, none function was found" << endl;
    }
}

SpaceShip::HitFunctionPtr SpaceShip::lookup(const GameObject& whatWeHit){
    // static HitMap collisionMap;
    static shared_ptr<HitMap> collisionMap(initializeCollisionMap());
    cout << typeid(whatWeHit).name() << endl;
    int status  = 0;
    char * const readable_name = abi::__cxa_demangle(typeid(whatWeHit).name(), 0, 0, &status);
    cout << readable_name << endl;
    HitMap::iterator mapEntry = collisionMap->find(readable_name);
    if (mapEntry != collisionMap->end()){
        return (*mapEntry).second;
    }else{
        return 0;
    }
}

SpaceShip::HitMap* SpaceShip::initializeCollisionMap(){
    HitMap *phm = new HitMap;
    (*phm)["SpaceShip"] = &SpaceShip::hitSpaceShip;
    (*phm)["SpaceStation"] = &SpaceShip::hitSpaceStation;
    (*phm)["Asteroid"] = &SpaceShip::hitAsteroid;
    return phm;
}

void SpaceShip::hitSpaceShip(GameObject& spaceShip){
    SpaceShip& otherShip = dynamic_cast<SpaceShip&>(spaceShip);
    cout << "Hit SpaceShip"  << endl;
}

void SpaceShip::hitSpaceStation(GameObject& spaceStation){
    SpaceStation& otherShip = dynamic_cast<SpaceStation&>(spaceStation);
    cout << "Hit SpaceStation"  << endl;
}

void SpaceShip::hitAsteroid(GameObject& asteroid){
    Asteroid& otherShip = dynamic_cast<Asteroid&>(asteroid);
    cout << "Hit Asteroid"  << endl;
}