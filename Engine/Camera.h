#pragma once

#include "CoordinateTransformer.h"
#include "RectF.h"
#include "Graphics.h"

class Camera
{
public:
	Camera( CoordinateTransformer& ct )
		:
		ct( ct )
	{}
	Vec2 GetPos() const
	{
		return pos;
	}
	void MoveBy( const Vec2& offset )
	{
		pos += offset;
	}
	void MoveTo( const Vec2& pos_in )
	{
		pos = pos_in;
	}
	void Draw( Drawable& drawable ) const
	{
		drawable.ApplyTranslation(Mat3::Rotate(angle) * Mat3::Scale(scale, scale) * Mat3::Translate(-pos.x, -pos.y));
		ct.Draw( drawable );
	}
	void SetScale( float s )
	{
		scale = s;
	}
	float GetScale() const
	{
		return scale;
	}
	RectF GetViewportRect() const
	{
		const float zoom = 1.0f / scale;
		return RectF::FromCenter( 
			pos,
			float( Graphics::ScreenWidth / 2 ) * zoom,
			float( Graphics::ScreenHeight / 2 ) * zoom
		);
	}
	void SetAngle(const float angle_in) {
		angle = angle_in;
	}

	const float GetAngle() const {
		return angle;
	}
private:
	Vec2 pos = {0.0f,0.0f};
	float scale = 1.0f;
	CoordinateTransformer& ct;
	float angle = 0.0f;
};