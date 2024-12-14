#include "Point2d.h"

#include <iostream>

int main( )
{
	Point2D p( 1, 2 );

	auto[x, y] = p.AsTuple( );

	std::cout << x << ", " << y << std::endl;

	return 0;
}