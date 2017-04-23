#include "InputController.h"

#include <algorithm>
#include "PlantLogic.h"
#include "GardenEntityPattern.h"

template<typename Method, typename... Args>
void InputController::emit( Method method, Args&&... args )
{
	for (EventListener* listener : listeners )
	{
		(listener->*method)( std::forward<Args>(args)... );
	}
}


InputController::InputController( cinder::app::WindowRef window_ )
	: window(window_)
{
	m_onKeyPressedConnection = window->getSignalKeyDown().connect( 
		[this]( const cinder::app::KeyEvent& keyEvent )
		{
			if ( keyEvent.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
			{
				emit( &EventListener::onTimeChanged, Year(5) );
			}

			if(keyEvent.getCode() == cinder::app::KeyEvent::KEY_LEFT)
			{
				emit( &EventListener::onTimeChanged, Year( -5 ) );
			}
		} );

	m_onMouseClickConnection = window->getSignalMouseDown().connect(
		[this](const cinder::app::MouseEvent& mouseEvent)
		{
			CoordsInt tile = pixelToTile(mouseEvent.getPos());
			if (mouseEvent.isLeft()){
				PlantLogic *nextSeed = new PlantLogic(GardenEntityPattern(), Year(300), Year(200), tile, "test_plant");
				emit(&EventListener::onAddEntity, tile, nextSeed);
			}
			else if (mouseEvent.isRight()){
				emit(&EventListener::onRemoveEntity, tile);
			}
		});

	onWindowSizeChange( window->getSize().x, window->getSize().y );
}

void InputController::RegisterEventListener( EventListener* listener )
{
	listeners.emplace_back(listener);
}

void InputController::UnregisterEventListener( EventListener* listener )
{
	auto it = std::find(listeners.begin(), listeners.end(), listener );
	if (it != listeners.end())
	{
		listeners.erase(it);
	}
}

void InputController::onWorldDimensionsChange( unsigned total_pixel_width_, unsigned total_pixel_height_ )
{
	worldInPixels = DimensionsInt(total_pixel_width_, total_pixel_height_);
}

void InputController::onLevelGridChanged( unsigned width_, unsigned height_ )
{
	worldInGrid = DimensionsInt(width_, height_);
}

void InputController::onWindowSizeChange( unsigned width_, unsigned height_ )
{
	totalInPixels = DimensionsInt(width_, height_);
}

CoordsInt InputController::pixelToTile(CoordsInt mousePosition)
{
	int translation = worldInPixels.x / worldInPixels.x;
	CoordsInt renderingOffset((totalInPixels - worldInPixels).x / 2, (totalInPixels - worldInPixels).y / 3);
	
	CoordsInt mouseTile = (mousePosition - renderingOffset) / translation;
	if (mouseTile.x < 0 || mouseTile.x > worldInGrid.x || mouseTile.y < 0 || mouseTile.y > worldInGrid.y){
		mouseTile = CoordsInt(-1, -1);
	}

	return mouseTile;
}
