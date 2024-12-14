#ifndef POINT2D_H
#define POINT2D_H

#include <tuple>

template <typename T>
class Point2D
{
public:
	Point2D( T x, T y ) : m_x( x ), m_y( y ) {}
	std::tuple<T, T> AsTuple( )
	{
		return std::make_tuple( m_x, m_y );
	}

private:
	T m_x;
	T m_y;
};

template <typename T>
Point2D( T x, T y )->Point2D<T>;

#endif
