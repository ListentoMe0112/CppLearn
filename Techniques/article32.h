#include <map>
#include <string>
#include <memory>
#include <boost/smart_ptr.hpp>
#include <iostream>
using namespace std;
class GameObject{
    virtual void collide(GameObject& otherObject) = 0;
};

class SpaceShip : public GameObject {
public:
    virtual void collide(GameObject& otherObject);
    virtual void hitSpaceShip(GameObject& spaceShip);
    virtual void hitSpaceStation(GameObject& spaceStatio);
    virtual void hitAsteroid(GameObject& asteroi);

    typedef void (SpaceShip::*HitFunctionPtr)(GameObject&);
    typedef map<string, HitFunctionPtr> HitMap;
    static HitFunctionPtr lookup(const GameObject& wahtWeHit);
    static HitMap* initializeCollisionMap();
};

class SpaceStation : public GameObject{
    virtual void collide(GameObject& otherObject){
        cout << "Just for test" << endl;
    }
};

class Asteroid : public GameObject {
    virtual void collide(GameObject& otherObject){cout << "Just for test" << endl;}
};

class CollisionWithUnknownObject{
public:
    CollisionWithUnknownObject(GameObject& whatWeHit){
        cout << typeid(whatWeHit).name() << endl;
    }
};