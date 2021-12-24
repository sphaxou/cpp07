#ifndef ITER_HPP
#define ITER_HPP

template<class T>
void iter(T *tab, size_t len, void (*f)(const T &))
{
	for (size_t i = 0; i < len; i++)
		f(tab[i]);
}

#endif
