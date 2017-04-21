#pragma once

template <class T>
class Segment{
private:
	T min, max, current;
	void evaluateLimits();

public:
	Segment();
	Segment(T minimum, T maximum);
	Segment(T minimum, T maximum, T currentValue);
	void operator+= (const T& obj);
	void operator-= (const T& obj);
	void operator*= (const T& obj);
	void operator/= (const T& obj);
	T& get();
	int getMax();
	int getMin();
	void setToMax();
	void setToMin();
    
	bool isMax();
	bool isMin();

};

#include "Segment.inl" 
