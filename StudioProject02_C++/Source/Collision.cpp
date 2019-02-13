#include "Collision.h"


Collision::Collision()
{

}


Collision::~Collision()
{
}

bool Collision::CollisionCheck(std::vector <Entity*> &entityPtr)
{
	for (size_t i = 0; i < entityPtr.size(); i++) {
		if (entityPtr.at(i)->getIsItPlayer() == true) {

			for (size_t p = 0; i < entityPtr.size(); i++) {
				if (entityPtr.at(i) != entityPtr.at(p)) {

					if ((((entityPtr.at(i)->getPosX() + entityPtr.at(i)->getRangeX() >= entityPtr.at(p)->getPosX() - entityPtr.at(p)->getRangeX()) &&
						(entityPtr.at(i)->getPosX() + entityPtr.at(i)->getRangeX() <= entityPtr.at(p)->getPosX() + entityPtr.at(p)->getRangeX())) ||
						((entityPtr.at(i)->getPosX() - entityPtr.at(i)->getRangeX() <= entityPtr.at(p)->getPosX() + entityPtr.at(p)->getRangeX()) &&
						(entityPtr.at(i)->getPosX() - entityPtr.at(i)->getRangeX() <= entityPtr.at(p)->getPosX() + entityPtr.at(p)->getRangeX())))
						&&
						(((entityPtr.at(i)->getPosY() + entityPtr.at(i)->getRangeY() >= entityPtr.at(p)->getPosY() - entityPtr.at(p)->getRangeY()) &&
						(entityPtr.at(i)->getPosY() + entityPtr.at(i)->getRangeY() <= entityPtr.at(p)->getPosY() + entityPtr.at(p)->getRangeY())) ||
							((entityPtr.at(i)->getPosY() - entityPtr.at(i)->getRangeY() <= entityPtr.at(p)->getPosY() + entityPtr.at(p)->getRangeY()) &&
							(entityPtr.at(i)->getPosY() - entityPtr.at(i)->getRangeY() <= entityPtr.at(p)->getPosY() + entityPtr.at(p)->getRangeY())))
						&&
						(((entityPtr.at(i)->getPosZ() + entityPtr.at(i)->getRangeZ() >= entityPtr.at(p)->getPosZ() - entityPtr.at(p)->getRangeZ()) &&
						(entityPtr.at(i)->getPosZ() + entityPtr.at(i)->getRangeZ() <= entityPtr.at(p)->getPosZ() + entityPtr.at(p)->getRangeZ())) ||
							((entityPtr.at(i)->getPosZ() - entityPtr.at(i)->getRangeZ() <= entityPtr.at(p)->getPosZ() + entityPtr.at(p)->getRangeZ()) &&
							(entityPtr.at(i)->getPosZ() - entityPtr.at(i)->getRangeZ() <= entityPtr.at(p)->getPosZ() + entityPtr.at(p)->getRangeZ())))
						)


						return true;


				}
			}

		}
	}
	

	return false;
}
