#pragma once

#include "cinder/app/Window.h"
#include "Typedef.h"

class IGardenEntityLogic;

class EventListener
{
	friend class InputController;
public:
	virtual ~EventListener() = default;

private:
	virtual void onTimeChanged( Year deltaYear ) = 0;
	virtual void onAddEntity(CoordsInt mousePosition, const IGardenEntityLogic&) = 0;
	virtual void onRemoveEntity(CoordsInt mousePosition) = 0;
};

class InputController
{
public:
	InputController( cinder::app::WindowRef window_ );

	void RegisterEventListener( EventListener* listener );
	void UnregisterEventListener( EventListener* listener );

private:

	template<typename Method, typename... Args>
	void emit( Method method, Args&&... args );

	cinder::app::WindowRef window;
	cinder::signals::ScopedConnection m_onKeyPressedConnection;
	cinder::signals::ScopedConnection m_onMouseClickConnection;

	std::vector<EventListener*> listeners;
};