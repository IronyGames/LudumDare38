#include "GardenLogic.h"
#include "PlantLogic.h"
#include "IGardenEntityLogic.h"
#include "IGardenEntityState.h"
#include "IGardenGoalLogic.h"

#include <cassert>

GardenLogic::GardenLogic( Segment<Year> timeline_, unsigned gardenWidth_, unsigned gardenHeight_, std::vector<IGardenEntityLogic*> entities_, std::vector<IGardenGoalLogic*> objectives_ )
	: timeline( timeline_ )
	, dimensions( gardenWidth_, gardenHeight_ )
	, entities(std::move( entities_ ))
	, objectives( objectives_ )
{
	for (IGardenEntityLogic* entity : entities )
	{
		addEntityToMap(entity);
	}
}

void GardenLogic::addEntityToMap(IGardenEntityLogic* entity_)
{
	for (CoordsInt coord : entity_->getOccupiedPositions())
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

void GardenLogic::updateGardenDelta( Year deltaYear )
{
	timeline += deltaYear;
	for ( IGardenEntityLogic* gardenEntity : getEntities() )
	{
		PlantLogic::CalculateStateResult result = gardenEntity->calculateStateTo( timeline.get(), deltaYear );

		gardenEntity->setCurrentState(result.age, result.occupiedPositions);
	}

	refreshWorld();
}

std::vector<IGardenEntityLogic*> GardenLogic::getEntities() const
{
	return entities;
}

void GardenLogic::addEntity(IGardenEntityLogic* entity_)
{
	for (size_t i = 0; i < entities.size(); i++){
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

void GardenLogic::refreshWorld()
{
	world.clear();
	for (IGardenEntityLogic* entity : entities)
	{
		for (CoordsInt coord : entity->getOccupiedPositions() )
		{
			world.emplace(coord, entity);
		}
	}
}

GardenLogic::EvaluateGoalResult GardenLogic::evaluateGoal() const
{
	for ( IGardenGoalLogic* objective : objectives )
	{
		boost::optional<CoordsInt> seedPos = objective->getSeedPosition();
		if (seedPos)
		{
			auto entityIt = world.find(*seedPos);
			if (entityIt == world.end() )
			{
				return EvaluateGoalResult();
			}

			const IGardenEntityLogic* entity = entityIt->second;
			if (entity->getPosition() != *seedPos)
			{
				return EvaluateGoalResult();
			}
		}

		const std::string desiredPlantType = objective->getEntityType();
		for ( CoordsInt desiredPos : objective->getOccupiedPositions())
		{
			auto entityIt = world.find( desiredPos );
			if (entityIt == world.end())
			{
				return EvaluateGoalResult();
			}

			const IGardenEntityLogic* entity = entityIt->second;
			if (entity->getType() != objective->getEntityType() )
			{
				return EvaluateGoalResult();
			}
		}
	}

	EvaluateGoalResult result;
	result.haveWon = true;
	return result;
}

GardenLogic::Dimensions::Dimensions( unsigned witdh_, unsigned height_ ) : witdh( witdh_ )
, height( height_ )
{

}
