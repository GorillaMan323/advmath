#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"
#include "Drawable.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer( Graphics& gfx )
		:
		gfx( gfx )
	{}
	void Draw( Drawable& drawable ) const
	{
		const Vec2 offset = { float( Graphics::ScreenWidth / 2 ),float( Graphics::ScreenHeight / 2 ) };
		drawable.ApplyTranslation(Mat3::Translate(offset.x, offset.y) * Mat3::InvertY());
		drawable.Render( gfx );
	}
private:
	Graphics& gfx;
};