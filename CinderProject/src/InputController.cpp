#include "InputController.h"

#include <algorithm>



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
			if (mouseEvent.isLeft()){
				emit(&EventListener::onLeftMouse, mouseEvent.getPos());
			}
			else if (mouseEvent.isRight()){
				emit(&EventListener::onRightMouse, mouseEvent.getPos());
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
	worldWidthInPixels = total_pixel_width_;
	worldHeightInPixels = total_pixel_height_;
}

void InputController::onLevelGridChanged( unsigned width_, unsigned height_ )
{
	gardenWidthDimension = width_;
	gardenHeightDimension = height_;
}

void InputController::onWindowSizeChange( unsigned width_, unsigned height_ )
{
	totalWidthInPixels = width_;
	totalHeightInPixels = height_;
}
