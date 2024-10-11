#pragma once

#include "string"
#include "math.h"
#include "sstream"
#include "stdio.h"

namespace sgl {
	// 三次元ベクトルを提供する
	struct vector3
	{
	public:
		float x, y, z;

		vector3() { x = y = z = 0; }
		vector3(float val) { x = y = z = val; }
		vector3(float x, float y, float z) : x(x), y(y), z(z) {}

		vector3 operator+(const vector3& other) noexcept {
			return vector3(x + other.x, y + other.y, z + other.z);
		}
		vector3 operator-(const vector3& other) noexcept {
			return vector3(x - other.x, y - other.y, z - other.z);
		}
		vector3 operator*(const vector3& other) noexcept {
			return vector3(x * other.x, y * other.y, z * other.z);
		}
		vector3 operator/(const vector3& other) noexcept {
			return vector3(x / other.x, y / other.y, z / other.z);
		}
		vector3& operator+=(const vector3& other) noexcept {
			x = x + other.x;
			y = y + other.y;
			z = z + other.z;
			return *this;
		}
		vector3& operator-=(const vector3& other) noexcept {
			x = x - other.x;
			y = y - other.y;
			z = z - other.z;
			return *this;
		}
		vector3& operator*=(const vector3& other) noexcept {
			x = x * other.x;
			y = y * other.y;
			z = z * other.z;
			return *this;
		}
		vector3& operator/=(const vector3& other) noexcept {
			x = x / other.x;
			y = y / other.y;
			z = z / other.z;
			return *this;
		}
		// 各成分の値がすべて一致していたら 真
		bool operator==(const vector3& other) const noexcept {
			return this->x == other.x && this->y == other.y && this->z == other.z;
		}
		// C言語の文字列へ変換した値を返す
		const char* const ToString() const {
			char buff[64];
			snprintf(buff, sizeof(buff), "x:%.3f,y:%.3f,z:%.3f", x, y, z);
			buff[63] = '\0'; // 文字列の末尾には必ず'\0'が番兵として配置されている。これがないと文字列として認識されない。
			return &buff[0];
		}
		// ベクトルの正規化をしたのち、正規化されたベクトルを返す
		vector3 normalized() noexcept {
			float magnitude = sqrtf(x * x + y * y + z * z);
			float calc_x = this->x / magnitude;
			float calc_y = this->y / magnitude;
			float calc_z = this->z / magnitude;

			return vector3(calc_x, calc_y, calc_z);
		}
		// 大きさを返す
		float magnitude() noexcept {
			float magnitude = sqrtf(x * x + y * y + z * z);
			return magnitude;
		}
	};
}
