#pragma once

#include "cinder/app/Window.h"
#include "Typedef.h"

class EventListener
{
	friend class InputController;
public:
	virtual ~EventListener() = default;

private:
	virtual void onTimeChanged( Year deltaYear ) = 0;
// 	virtual void onRewindTime() = 0;
// 	virtual void onForwardTime() = 0;
	virtual void onLeftMouse(CoordsInt mousePosition) = 0;
	virtual void onRightMouse(CoordsInt mousePosition) = 0;
};

class WindowObserver
{
public:
	virtual void onWorldDimensionsChange( unsigned total_pixel_width_, unsigned total_pixel_height_ ) = 0;
	virtual void onLevelGridChanged( unsigned width_, unsigned height_ ) = 0;
	virtual void onWindowSizeChange( unsigned width_, unsigned height_ ) = 0;
};

class InputController : public WindowObserver
{
public:
	InputController( cinder::app::WindowRef window_ );

	void RegisterEventListener( EventListener* listener );
	void UnregisterEventListener( EventListener* listener );

	void onWorldDimensionsChange( unsigned total_pixel_width_, unsigned total_pixel_height_ ) override;
	void onLevelGridChanged( unsigned width_, unsigned height_ ) override;
	void onWindowSizeChange( unsigned width_in_pixels_, unsigned height_in_pixels_ ) override;

private:

	template<typename Method, typename... Args>
	void emit( Method method, Args&&... args );

	cinder::app::WindowRef window;
	cinder::signals::ScopedConnection m_onKeyPressedConnection;
	cinder::signals::ScopedConnection m_onMouseClickConnection;

	std::vector<EventListener*> listeners;

	unsigned totalWidthInPixels = 0;
	unsigned totalHeightInPixels = 0;

	unsigned worldWidthInPixels = 0;
	unsigned worldHeightInPixels = 0;

	unsigned gardenWidthDimension = 0;
	unsigned gardenHeightDimension = 0;

};
