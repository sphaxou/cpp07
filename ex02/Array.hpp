#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>

template <class T>
class Array
{
	private:
		int	_size;
		T *array;
	public:
		Array<T>(): _size(0), array(NULL){}
		Array<T>(unsigned int n): _size(n){
			if (_size < 0)
				throw std::overflow_error("wrong _size in the constructor");
			array = new T[_size];
		}
		Array<T>(const Array<T> &src){*this = src;}
		~Array<T>(){
			if (_size > 0)
				delete [] array;
		}

		Array<T> &operator=(const Array<T> &src)
		{
			if (this == &src)
				return (*this);
			if (this->_size > 0)
				delete [] array;
			_size = src._size;
			array = new T[this->_size];
			for (int i = 0; i < _size; i++)
				array[i] = src.array[i];
			return (*this);
		}

		T &operator[] (const int i)const
		{
			if (i < 0 || i >= _size)
				throw std::overflow_error("Index out of bounds");
			return (array[i]);
		}

		int size() const{return (_size);}
};

#endif