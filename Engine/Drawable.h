#pragma once

#include "Graphics.h"
#include <vector>
#include "Vec2.h"
#include "Mat3.h"
class Drawable
{
public:
	Drawable( const std::vector<Vec2>& model,Color c )
		:
		c( c ),
		model( &model )
	{}
	
	void Render( Graphics& gfx ) const
	{
		gfx.DrawClosedPolyline( *model,TranslationComplete,angle,c );
	}


	void ApplyTranslation(const Mat3 NewTranslation) {
		TranslationComplete = NewTranslation * TranslationComplete;
	}


private:
	Color c;
	Mat3 TranslationComplete = Mat3::Identity();
	const std::vector<Vec2>* model;
	Vec2 translation = {0.0f,0.0f};
	float scale_x = 1.0f;
	float scale_y = 1.0f;
	float angle = 0.0f;
};