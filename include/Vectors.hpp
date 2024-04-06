#pragma once

class Vec2
{
public:
	float x, y;

	Vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2 operator+(Vec2 b)
	{
		return Vec2(this->x + b.x, this->y + b.y);
	}
	Vec2 operator-(Vec2 b)
	{
		return Vec2(this->x - b.x, this->y - b.y);
	}
	Vec2 operator*(Vec2 b)
	{
		return Vec2(this->x * b.x, this->y * b.y);
	}
	Vec2 operator/(Vec2 b)
	{
		return Vec2(this->x / b.x, this->y / b.y);
	}

	Vec2() = default;
};
class Vec3
{
public:
	float x, y, z;

	Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3 operator+(Vec3 b)
	{
		return Vec3(this->x + b.x, this->y + b.y, this->z + b.z);
	}
	Vec3 operator-(Vec3 b)
	{
		return Vec3(this->x - b.x, this->y - b.y, this->z - b.z);
	}
	Vec3 operator*(Vec3 b)
	{
		return Vec3(this->x * b.x, this->y * b.y, this->z * b.z);
	}
	Vec3 operator/(Vec3 b)
	{
		return Vec3(this->x / b.x, this->y / b.y, this->z / b.z);
	}

	Vec3() = default;
};
class Vec4
{
public:
	float x, y, z, w;

	Vec4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vec4 operator+(Vec4 b)
	{
		return Vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);
	}
	Vec4 operator-(Vec4 b)
	{
		return Vec4(this->x - b.x, this->y - b.y, this->z - b.z, this->w - b.w);
	}
	Vec4 operator*(Vec4 b)
	{
		return Vec4(this->x * b.x, this->y * b.y, this->z * b.z, this->w * b.w);
	}
	Vec4 operator/(Vec4 b)
	{
		return Vec4(this->x / b.x, this->y / b.y, this->z / b.z, this->w / b.w);
	}

	Vec4() = default;
};
using Color = Vec4;