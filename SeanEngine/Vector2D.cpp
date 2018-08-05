#pragma once
#include "Vector2D.hpp"

Vector2D::Vector2D() {
	x = 0;
	y = 0;
}

Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2D& Vector2D::Add(const Vector2D& vector) {
	this->x += vector.x;
	this->y += vector.y;

	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vector) {
	this->x -= vector.x;
	this->y -= vector.y;

	return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vector) {
	this->x *= vector.x;
	this->y *= vector.y;

	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vector) {
	this->x /= vector.x;
	this->y /= vector.y;

	return *this;
}

Vector2D& operator+(Vector2D& vector1, const Vector2D& vector2) {
	return vector1.Add(vector2);
}

Vector2D& operator-(Vector2D& vector1, const Vector2D& vector2) {
	return vector1.Subtract(vector2);
}

Vector2D& operator*(Vector2D& vector1, const Vector2D& vector2) {
	return vector1.Multiply(vector2);
}

Vector2D& operator/(Vector2D& vector1, const Vector2D& vector2) {
	return vector1.Divide(vector2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vector) {
	return this->Add(vector);
}

Vector2D& Vector2D::operator-=(const Vector2D& vector) {
	return this->Subtract(vector);
}

Vector2D& Vector2D::operator*=(const Vector2D& vector) {
	return this->Multiply(vector);
}

Vector2D& Vector2D::operator/=(const Vector2D& vector) {
	return this->Divide(vector);
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vector) {
	stream << "Vector2D ( " << vector.x << ":" << vector.y << " )";
	return stream;
}