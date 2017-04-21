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
inline T& Segment<T>::get(){
	return current;
}

template <class T>
int Segment<T>::getMin()
{
	return min;
}

template <class T>
int Segment<T>::getMax()
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
bool Segment<T>::isMax()
{
	return current == max;
}

template <class T>
bool Segment<T>::isMin()
{
	return current == min;
}
