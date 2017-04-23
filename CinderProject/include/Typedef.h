#pragma once

#include <string>
typedef std::string String;

#include "cinder/Vector.h"
typedef cinder::ivec2 CoordsInt;
typedef cinder::dvec2 CoordsDouble;
typedef cinder::ivec2 DimensionsInt;

#include "cinder/gl/Texture.h"
typedef cinder::gl::Texture2dRef Image;

#include "cinder/Color.h"
typedef cinder::Color cinderColor;

#include "cinder/Json.h"
typedef cinder::JsonTree CinderJson;

#include "cinder/DataSource.h"
typedef cinder::DataSourceRef CinderDataSource;

using Year = double;

template<typename T>
using owner = T*;


namespace std
{
	template<>
	class hash<CoordsInt>
	{
	public:
		size_t operator()(const CoordsInt& coord) const
		{
			// lazy implementation, this can be improved, a lot!
			return coord.x + coord.y;
		}
	};
}