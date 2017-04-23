template <class T>
inline void Segment<T>::evaluateLimits(){
	if (current > max){
		current = max;
	}
	else if (current < min){
		current = min;
	}
}

template <class T>
inline Segment<T>::Segment(){}

template <class T>
inline Segment<T>::Segment(T minimum, T maximum)
: min(minimum), max(maximum), current(minimum){
}


template <class T>
inline Segment<T>& Segment<T>::operator=( const T& currentValue )
{
	current = currentValue;
	evaluateLimits();

	return *this;
}


template <class T>
inline Segment<T>::Segment(T minimum, T maximum, T currentValue)
: min(minimum), max(maximum), current(currentValue){
	evaluateLimits();
}

template <class T>
inline void Segment<T>::operator+= (const T& obj){
	current += obj;
	evaluateLimits();
}

template <class T>
inline void Segment<T>::operator-= (const T& obj){
	current -= obj;
	evaluateLimits();
}

template <class T>
inline void Segment<T>::operator*= (const T& obj){
	current *= obj;
	evaluateLimits();
}

template <class T>
inline void Segment<T>::operator/= (const T& obj){
	current /= obj;
	evaluateLimits();
}

template <class T>
inline const T& Segment<T>::get() const {
	return current;
}

template <class T>
int Segment<T>::getMin() const
{
	return min;
}

template <class T>
int Segment<T>::getMax() const
{
	return max;
}

template <class T>
inline void Segment<T>::setToMax(){
	current = max;
}

template <class T>
inline void Segment<T>::setToMin(){
	current = min;
}

template <class T>
bool Segment<T>::isMax() const
{
	return current == max;
}

template <class T>
bool Segment<T>::isMin() const
{
	return current == min;
}
