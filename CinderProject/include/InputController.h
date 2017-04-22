#pragma once

#include "cinder/app/Window.h"
#include "Typedef.h"

class EventListener
{
public:
	virtual ~EventListener() = default;

	virtual void onTimeChanged( Year deltaYear ) = 0;
};

class InputController
{
public:
	InputController( cinder::app::WindowRef window_ );

	cinder::signals::Connection RegisterEventListener( EventListener* listener );

private:

	cinder::app::WindowRef window;
	cinder::signals::ScopedConnection m_onKeyPressedConnection;


	cinder::signals::Signal<void(Year)> m_onTimeChanged;
};