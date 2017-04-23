#pragma once

template<typename Listener>
class Dispatcher
{
public:
	void RegisterListener( Listener* listener )
	{
		listeners.push_back(listener);
	}

	void UnregisterListener( Listener* listener )
	{
		auto it = std::find( listeners.begin(), listeners.end(), listener );
		if (it != listeners.end())
		{
			listeners.erase(it);
		}
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
	std::vector<Listener*> listeners;
};
