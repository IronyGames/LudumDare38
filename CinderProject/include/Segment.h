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

	Segment& operator=( const T& other);

	void operator+= (const T& obj);
	void operator-= (const T& obj);
	void operator*= (const T& obj);
	void operator/= (const T& obj);
	const T& get() const;
	int getMax() const;
	int getMin() const;
	void setToMax();
	void setToMin();
    
	bool isMax() const;
	bool isMin() const;

};

#include "Segment.inl" 
