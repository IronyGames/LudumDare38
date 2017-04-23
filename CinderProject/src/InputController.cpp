#include "InputController.h"

#include <algorithm>
#include "PlantLogic.h"
#include "GardenEntityPattern.h"

InputController::InputController( cinder::app::WindowRef window_ )
	: window(window_)
{
	m_onKeyPressedConnection = window->getSignalKeyDown().connect( 
		[this]( const cinder::app::KeyEvent& keyEvent )
		{
			
			if ( keyEvent.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
			{
				Dispatcher<GardenEventListener>::emit( &GardenEventListener::onTimeChanged, Year(5) );
			}

			if(keyEvent.getCode() == cinder::app::KeyEvent::KEY_LEFT)
			{
				Dispatcher<GardenEventListener>::emit(&GardenEventListener::onTimeChanged, Year(-5));
			}
		} );

	m_onMouseClickConnection = window->getSignalMouseDown().connect(
		[this](const cinder::app::MouseEvent& mouseEvent)
		{
			Dispatcher<InputEventListener>::emit(&InputEventListener::onAnyKey);
			boost::optional<CoordsInt> tile = pixelToTile(mouseEvent.getPos());
			if (tile)
			{
				if(mouseEvent.isLeft())
				{
					Dispatcher<GardenEventListener>::emit(&GardenEventListener::onAddEntity, *tile);
				}
				else if(mouseEvent.isRight())
				{
					Dispatcher<GardenEventListener>::emit(&GardenEventListener::onRemoveEntity, *tile);
				}
			}
			
		});

	m_onResizeConection = window->getSignalResize().connect(
		[this]()
		{
			onWindowSizeChange( window->getSize().x, window->getSize().y );
		}
	);
	onWindowSizeChange( window->getSize().x, window->getSize().y );
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

boost::optional<CoordsInt> InputController::pixelToTile(CoordsInt mousePosition)
{
	if (worldInGrid.x == 0){
		return boost::none;
	}
	int translation = worldInPixels.x / worldInGrid.x;
	CoordsInt renderingOffset((totalInPixels - worldInPixels).x / 2, (totalInPixels - worldInPixels).y / 3);
	
	boost::optional<CoordsInt> mouseTile = (mousePosition - renderingOffset) / translation;
	if (mouseTile->x < 0 || mouseTile->x > worldInGrid.x || mouseTile->y < 0 || mouseTile->y > worldInGrid.y){
		mouseTile = boost::none;
	}

	return mouseTile;
}
