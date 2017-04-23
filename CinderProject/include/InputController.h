#pragma once

#include "cinder/app/Window.h"
#include "Typedef.h"
#include "Dispatcher.h"

class IGardenEntityLogic;

class EventListener
{
	friend class InputController;
public:
	virtual ~EventListener() = default;

private:
	virtual void onTimeChanged( Year deltaYear ) = 0;
	virtual void onAddEntity(CoordsInt tile, IGardenEntityLogic* entity) = 0;
	virtual void onRemoveEntity(CoordsInt tile) = 0;
};

class WindowObserver
{
public:
	virtual void onWorldDimensionsChange( unsigned total_pixel_width_, unsigned total_pixel_height_ ) = 0;
	virtual void onLevelGridChanged( unsigned width_, unsigned height_ ) = 0;
	virtual void onWindowSizeChange( unsigned width_, unsigned height_ ) = 0;
};

class InputController : public WindowObserver, public Dispatcher<EventListener>
{
public:
	InputController( cinder::app::WindowRef window_ );

	void onWorldDimensionsChange( unsigned total_pixel_width_, unsigned total_pixel_height_ ) override;
	void onLevelGridChanged( unsigned width_, unsigned height_ ) override;
	void onWindowSizeChange( unsigned width_in_pixels_, unsigned height_in_pixels_ ) override;

private:


	CoordsInt pixelToTile(CoordsInt mousePosition);

	cinder::app::WindowRef window;
	cinder::signals::ScopedConnection m_onKeyPressedConnection;
	cinder::signals::ScopedConnection m_onMouseClickConnection;

	std::vector<EventListener*> listeners;

	DimensionsInt totalInPixels;
	unsigned totalWidthInPixels = 0;
	unsigned totalHeightInPixels = 0;

	DimensionsInt worldInPixels;
	unsigned worldWidthInPixels = 0;
	unsigned worldHeightInPixels = 0;

	DimensionsInt worldInGrid;
	unsigned gardenWidthDimension = 0;
	unsigned gardenHeightDimension = 0;

};
