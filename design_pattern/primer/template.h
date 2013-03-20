#pragma once

template <class T, size_t N> void arrary_init(T (&parm)[N])
{
	for (size_t i = 0; i != N; ++i)
	{
		parm[i] = 0;
	}
}

template<typename T> int compare(const T& t1, const T&t2)
{
	if (t1 < t2)
		return -1;
	else if(t1 > t2)
		return 1;
	return 0;
}

template<> int compare<const char*>(const char*  const&s1, const char*  const&s2)
{
	return strcmp(s1, s2);
}