#pragma once

#include "string"
#include "math.h"
#include "sstream"
#include "stdio.h"
#include "DirectXMath.h"
#include "../ManagedDxlGame/program/library/tnl_vector3.h"

namespace sgl {
	// 三次元ベクトルを提供する
	struct Vector3
	{
	public:
		float x, y, z;

		Vector3() { x = y = z = 0; }
		Vector3(float val) { x = y = z = val; }
		Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
		// x,y,z成分がすべて１のベクトル
		static const sgl::Vector3 one() noexcept { return { 1 }; }
		// y成分が１のベクトル
		static const sgl::Vector3 up() noexcept { return { 0,1,0 }; }
		// x成分が１のベクトル
		static const sgl::Vector3 right() noexcept { return { 1,0,0 }; }
		// DxLib::VECTOR → sgl::Vector3の関数
		static sgl::Vector3 ToSglVector(const DxLib::VECTOR vec) noexcept {
			return sgl::Vector3(vec.x, vec.y, vec.z);
		}
		// DirectX::XMVECTOR  → sgl::Vector3
		static sgl::Vector3 ToSglVector(const DirectX::XMVECTOR vec) noexcept {
			return sgl::Vector3(vec.m128_f32[0], vec.m128_f32[1], vec.m128_f32[2]);
		}
		// DirectXのベクトルに変換
		static DirectX::XMVECTOR ToDXVector(const sgl::Vector3& v) noexcept {
			return DirectX::XMVectorSet(v.x, v.y, v.z, 1.0f);
		}

		sgl::Vector3 operator+(const sgl::Vector3& other) noexcept {
			return Vector3(x + other.x, y + other.y, z + other.z);
		}
		sgl::Vector3 operator+(const tnl::Vector3& other) noexcept {
			return Vector3(x + other.x, y + other.y, z + other.z);
		}
		sgl::Vector3 operator-(const sgl::Vector3& other) noexcept {
			return Vector3(x - other.x, y - other.y, z - other.z);
		}
		sgl::Vector3 operator-(const tnl::Vector3& other) noexcept {
			return Vector3(x - other.x, y - other.y, z - other.z);
		}
		sgl::Vector3 operator*(const sgl::Vector3& other) noexcept {
			return Vector3(x * other.x, y * other.y, z * other.z);
		}
		sgl::Vector3 operator*(const tnl::Vector3& other) noexcept {
			return Vector3(x * other.x, y * other.y, z * other.z);
		}
		sgl::Vector3 operator/(const sgl::Vector3& other) noexcept {
			return Vector3(x / other.x, y / other.y, z / other.z);
		}
		sgl::Vector3 operator/(const tnl::Vector3& other) noexcept {
			return Vector3(x / other.x, y / other.y, z / other.z);
		}
		sgl::Vector3& operator+=(const sgl::Vector3& other) noexcept {
			x = x + other.x;
			y = y + other.y;
			z = z + other.z;
			return *this;
		}
		sgl::Vector3& operator+=(const tnl::Vector3& other) noexcept {
			x = x + other.x;
			y = y + other.y;
			z = z + other.z;
			return *this;
		}
		sgl::Vector3& operator-=(const sgl::Vector3& other) noexcept {
			x = x - other.x;
			y = y - other.y;
			z = z - other.z;
			return *this;
		}
		sgl::Vector3& operator-=(const tnl::Vector3& other) noexcept {
			x = x - other.x;
			y = y - other.y;
			z = z - other.z;
			return *this;
		}
		sgl::Vector3& operator*=(const sgl::Vector3& other) noexcept {
			x = x * other.x;
			y = y * other.y;
			z = z * other.z;
			return *this;
		}
		sgl::Vector3& operator*=(const tnl::Vector3& other) noexcept {
			x = x * other.x;
			y = y * other.y;
			z = z * other.z;
			return *this;
		}
		sgl::Vector3& operator/=(const sgl::Vector3& other) noexcept {
			x = x / other.x;
			y = y / other.y;
			z = z / other.z;
			return *this;
		}
		sgl::Vector3& operator/=(const tnl::Vector3& other) noexcept {
			x = x / other.x;
			y = y / other.y;
			z = z / other.z;
			return *this;
		}
		// 各成分の値がすべて一致していたら 真
		bool operator==(const sgl::Vector3& other) const noexcept {
			return this->x == other.x && this->y == other.y && this->z == other.z;
		}
		bool operator==(const tnl::Vector3& other) const noexcept {
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
		sgl::Vector3 normalized() noexcept {
			float magnitude = sqrtf(x * x + y * y + z * z);
			float calc_x = this->x / magnitude;
			float calc_y = this->y / magnitude;
			float calc_z = this->z / magnitude;
			return sgl::Vector3(calc_x, calc_y, calc_z);
		}
		// 大きさを返す
		float magnitude() noexcept {
			float magnitude = sqrtf(x * x + y * y + z * z);
			return magnitude;
		}
		// DirectXのベクトルに変換
		DirectX::XMVECTOR ToDXVector() noexcept {
			DirectX::XMVECTOR vec{ x,y,z };
			return vec;
		}
		// tnl::Vectorに変換
		tnl::Vector3 ToTnlVector() {
			return tnl::Vector3{ x,y,z };
		}
		// float配列で返す
		const float* ToFloatArray() {
			float arr[3]{ x,y,z };
			return arr;
		}
	};
}
