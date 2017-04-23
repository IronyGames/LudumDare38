#include "GardenLogic.h"
#include "PlantLogic.h"
#include "IGardenEntityLogic.h"
#include "IGardenEntityState.h"

#include <cassert>

GardenLogic::GardenLogic( Segment<Year> timeline_, unsigned gardenWidth_, unsigned gardenHeight_, std::vector<IGardenEntityLogic*> entities_ )
	: timeline( timeline_ )
	, dimensions( gardenWidth_, gardenHeight_ )
	, entities(std::move( entities_ ))
{
	for (IGardenEntityLogic* entity : entities )
	{
		addEntityToMap(entity);
	}
}

void GardenLogic::addEntityToMap(IGardenEntityLogic* entity_)
{
	for (CoordsInt coord : entity_->getCurrentState()->getOccupiedPositions())
	{
		assert(world.find(coord) == world.end());
		world[coord] = entity_;
	}
}

GardenLogic::Dimensions GardenLogic::getDimensions() const
{
	return dimensions;
}

Segment<Year> GardenLogic::getCurrentTimeState() const
{
	return timeline;
}

void GardenLogic::updateGardenDelta( Year year )
{
	timeline += year;
	for ( IGardenEntityLogic* gardenEntity : getEntities() )
	{
		PlantLogic::CalculateStateResult result = gardenEntity->calculateStateTo(year);

		// TODO: Do stuff later
	}
}

std::vector<IGardenEntityLogic*> GardenLogic::getEntities() const
{
	return entities;
}

void GardenLogic::addEntity(IGardenEntityLogic* entity_)
{
	for (int i = 0; i < entities.size(); i++){
		if (entity_->getPosition() == getEntities().at(i)->getPosition()){
			return;
		}
	}
	entities.emplace_back(entity_);
	addEntityToMap(entity_);
}

void GardenLogic::unPlant(CoordsInt tile)
{
	IGardenEntityLogic* plant = getEntity(tile);
	if (plant == nullptr){ 
		return; 
		
	}
	entities.erase(std::remove(entities.begin(), entities.end(), plant), entities.end());
	delete plant;
}

IGardenEntityLogic* GardenLogic::getEntity(CoordsInt origin)
{
	for (IGardenEntityLogic* entity : entities){
		if (entity->getPosition() == origin){
			return entity;
		}
	}
	return nullptr;
}

GardenLogic::Dimensions::Dimensions( unsigned witdh_, unsigned height_ ) : witdh( witdh_ )
, height( height_ )
{

}
