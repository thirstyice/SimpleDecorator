#pragma once

template<class T>
class Decorator : public T {
protected:
	T * pointer;
public:
	explicit Decorator(T object):pointer(&object) {};
	explicit Decorator(T* reference):pointer(reference) {};
	T* operator->() {return pointer;}
};