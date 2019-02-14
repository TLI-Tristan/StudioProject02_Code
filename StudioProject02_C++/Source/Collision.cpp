#include "Collision.h"


Collision::Collision()
{

}


Collision::~Collision()
{
}

void Collision::collisionImpact(Entity& firstEntity, Entity& secondEntity) {

	if (secondEntity.getName() != "player2") {

		

	}

}

bool Collision::collisionCheck(std::vector <Entity*> &entityPtr)
{
	for (size_t i = 0; i < entityPtr.size(); i++) {
		if (entityPtr.at(i)->getIsItPlayer() == true) {

			for (size_t p = 0; p < entityPtr.size(); p++) {

				if (entityPtr.at(i) != entityPtr.at(p)) {

					/*if ((((entityPtr.at(i)->getPosX() + entityPtr.at(i)->getRangeX() >= entityPtr.at(p)->getPosX() - entityPtr.at(p)->getRangeX()) &&
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
						(entityPtr.at(i)->getPosZ() - entityPtr.at(i)->getRangeZ() <= entityPtr.at(p)->getPosZ() + entityPtr.at(p)->getRangeZ())))) 
					{
							return true;
					}*/

				/*	if ( (( (entityPtr.at(i)->getHeighestX() >= entityPtr.at(p)->getLowestX() ) && (entityPtr.at(i)->getHeighestX() <= entityPtr.at(p)->getHeighestX()) ) ||
						( (entityPtr.at(i)->getLowestX() <= entityPtr.at(p)->getHeighestX()) && (entityPtr.at(i)->getLowestX() >= entityPtr.at(p)->getLowestX()) )) &&

						(( (entityPtr.at(i)->getHeighestY() >= entityPtr.at(p)->getLowestY()) && (entityPtr.at(i)->getHeighestY() <= entityPtr.at(p)->getHeighestY()) ) ||
						( (entityPtr.at(i)->getLowestY() <= entityPtr.at(p)->getHeighestY()) && (entityPtr.at(i)->getLowestY() >= entityPtr.at(p)->getLowestY()) )) &&

						(( (entityPtr.at(i)->getHeighestZ() >= entityPtr.at(p)->getLowestZ()) && (entityPtr.at(i)->getHeighestZ() <= entityPtr.at(p)->getHeighestZ()) ) ||
						( (entityPtr.at(i)->getLowestZ() <= entityPtr.at(p)->getHeighestZ()) && (entityPtr.at(i)->getLowestZ() >= entityPtr.at(p)->getLowestZ()) ))) {

						return true;
					}*/
					
					//if ( ( ( (entityPtr.at(i)->getHeighestX() >= entityPtr.at(p)->getLowestX() ) &&
					//	 (entityPtr.at(i)->getHeighestX() <= entityPtr.at(p)->getHeighestX()) ) ||
					//	((entityPtr.at(i)->getLowestX() >= entityPtr.at(p)->getLowestX()) &&
					//	(entityPtr.at(i)->getLowestX() <= entityPtr.at(p)->getHeighestX())))
					//	&&
					//	(((entityPtr.at(i)->getHeighestY() >= entityPtr.at(p)->getLowestY() ) && // 5 >= -17 true
					//	(entityPtr.at(i)->getHeighestY() <= entityPtr.at(p)->getHeighestY())) || // 5 <= 17 true
					//	((entityPtr.at(i)->getLowestY() >= entityPtr.at(p)->getLowestY()) &&	// -5 >= -17 true
					//	(entityPtr.at(i)->getLowestY() <= entityPtr.at(p)->getHeighestY())))    // -5 <= 17 true
					//	&&
					//	(((entityPtr.at(i)->getHeighestZ() >= entityPtr.at(p)->getLowestZ()) &&
					//	(entityPtr.at(i)->getHeighestZ() <= entityPtr.at(p)->getHeighestZ())) ||
					//	((entityPtr.at(i)->getLowestZ() >= entityPtr.at(p)->getLowestZ()) &&
					//	(entityPtr.at(i)->getLowestZ() <= entityPtr.at(p)->getHeighestZ()))) )
					//{
					//		return true;
					//}

					if (((entityPtr.at(i)->getHeighestX() >= entityPtr.at(p)->getLowestX()) &&
						(entityPtr.at(i)->getLowestX() <= entityPtr.at(p)->getHeighestX()))
						&&
						((entityPtr.at(i)->getHeighestY() >= entityPtr.at(p)->getLowestY()) &&
						(entityPtr.at(i)->getLowestY() <= entityPtr.at(p)->getHeighestY()))
						&&
						((entityPtr.at(i)->getHeighestZ() >= entityPtr.at(p)->getLowestZ()) &&
						(entityPtr.at(i)->getLowestZ() <= entityPtr.at(p)->getHeighestZ())))
					{
						
						collisionImpact(*entityPtr.at(i), *entityPtr.at(p));
						return true;
					}


				}
			}

		}
	}
	

	return false;
}
