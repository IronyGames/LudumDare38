#pragma once

#include <set>

template<typename Listener>
class Dispatcher
{
public:
	void RegisterListener( Listener* listener )
	{
		listeners.emplace(listener);
	}

	void UnregisterListener( Listener* listener )
	{
		listeners.erase( listener );
	}

protected:
	template<typename Method, typename... Args>
	void emit( Method method, Args&&... args )
	{
		for(Listener* listener : listeners)
		{
			(listener->*method)(std::forward<Args>( args )...);
		}
	}

private:
	std::set<Listener*> listeners;
};
