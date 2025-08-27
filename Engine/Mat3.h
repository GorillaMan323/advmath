#pragma once
#include "Vec3.h"
template<typename T> class _Mat3 {
public:
	_Vec3<T> operator*(const _Vec3<T>& other) const {
		const float x = cell[0][0] * other.x + cell[0][1] * other.y + cell[0][2] * other.w;
		const float y = cell[1][0] * other.x + cell[1][1] * other.y + cell[1][2] * other.w;
		return _Vec3<T>(x, y);
	}
	_Vec2<T> operator*(const _Vec3<T>& other) {
		return _Vec2<T>(*this * other);
	}
	_Mat3<T> operator*(const _Mat3<T>& other) {
		_Mat3<T> out;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				out.cell[i][j] = (T)0;
				for (int k = 0; k < 3; k++) {
					out.cell[i][j] += cell[i][k] * other.cell[k][j];
				}
			}
		}
		return out;
	}
	static _Mat3<T> Rotate(float angle) {
		const T sintheta = sin(angle);
		const T costheta = cos(angle);
		return {
			costheta,	-sintheta,	(T)0,
			sintheta,	costheta,	(T)0,
			(T)0,			(T)0,	(T)1
		};
	}
	static _Mat3<T> Translate(const T x, const T y) {
		return {(T)1,	(T)0,	x,
				(T)0,	(T)1,	y,
				(T)0,	(T)0,	(T)1
		}
	}
	static _Mat3<T> Identity() {
		return {(T)1,	(T)0,	(T)0,
				(T)0,	(T)1,	(T)0,
				(T)0,	(T)0,	(T)1 
		};
	}
public:
	T cell[3][3];
};