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
