#pragma once

#include "cinder/app/Window.h"
#include "Typedef.h"
#include "Dispatcher.h"
#include "boost/optional/optional.hpp"

class IGardenEntityLogic;

class GardenEventListener
{
	friend class InputController;
public:
	virtual ~GardenEventListener() = default;

private:
	virtual void onTimeChanged( Year deltaYear ) = 0;
	virtual void onAddEntity(CoordsInt tile ) = 0;
	virtual void onRemoveEntity(CoordsInt tile ) = 0;
};

class InputEventListener{
	friend class InputController;
private:
	virtual void onAnyKey() = 0;
};

class WindowObserver
{
public:
	virtual void onWorldDimensionsChange( unsigned total_pixel_width_, unsigned total_pixel_height_ ) = 0;
	virtual void onLevelGridChanged( unsigned width_, unsigned height_ ) = 0;
	virtual void onWindowSizeChange( unsigned width_, unsigned height_ ) = 0;
};

class InputController : public WindowObserver, public Dispatcher<GardenEventListener>, public Dispatcher<InputEventListener>
{
public:
	InputController( cinder::app::WindowRef window_ );

	void onWorldDimensionsChange( unsigned total_pixel_width_, unsigned total_pixel_height_ ) override;
	void onLevelGridChanged( unsigned width_, unsigned height_ ) override;
	void onWindowSizeChange( unsigned width_in_pixels_, unsigned height_in_pixels_ ) override;

private:

	boost::optional<CoordsInt> pixelToTile(CoordsInt mousePosition);

	cinder::app::WindowRef window;
	cinder::signals::ScopedConnection m_onKeyPressedConnection;
	cinder::signals::ScopedConnection m_onMouseClickConnection;
	cinder::signals::ScopedConnection m_onResizeConection;

	std::vector<GardenEventListener*> listeners;

	DimensionsInt totalInPixels;
	DimensionsInt worldInPixels;
	DimensionsInt worldInGrid;
};
