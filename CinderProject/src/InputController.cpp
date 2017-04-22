#include "InputController.h"

InputController::InputController( cinder::app::WindowRef window_ )
	: window(window_)
{
	m_onKeyPressedConnection = window->getSignalKeyDown().connect( 
		[this]( const cinder::app::KeyEvent& keyEvent )
		{
			auto slots = m_onTimeChanged.getNumSlots();
			if ( keyEvent.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
			{
				m_onTimeChanged.emit( Year(5) );
			}

			if(keyEvent.getCode() == cinder::app::KeyEvent::KEY_LEFT)
			{
				m_onTimeChanged.emit( Year( -5 ) );
			}
		} );
}

cinder::signals::Connection InputController::RegisterEventListener( EventListener* listener )
{
	return m_onTimeChanged.connect(
		[listener]( Year year )
	{
		listener->onTimeChanged(year);
	});
}