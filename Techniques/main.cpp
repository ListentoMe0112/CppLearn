#include "article32.h"

int main(){
    SpaceShip* psship = new SpaceShip();
    SpaceShip* pasship = new SpaceShip();
    SpaceStation* psstation = new SpaceStation();
    Asteroid* pasteroid = new Asteroid();
    psship->collide(*pasship);
    psship->collide(*psstation);
    psship->collide(*pasteroid);
    return 0;
}