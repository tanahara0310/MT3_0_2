#pragma once

struct Vector3 {
    float x, y, z;

    //Vector3 operator+(const Vector3& other) { return { x + other.x, y + other.y , z + other.z}; }
    //Vector3 operator-(const Vector3& other) { return { x - other.x, y - other.y, z - other.z }; }
    //Vector3 operator*(const Vector3& other) { return { x * other.x, y * other.y, z * other.z }; }
    //Vector3 operator/(const Vector3& other) { return { x / other.x, y / other.y , z / other.z}; }
    //Vector3 operator=(const Vector3& other) { return { x = other.x, y = other.y , z = other.z}; }
    //Vector3 operator+=(const Vector3& other) { return { x += other.x, y += other.y, z += other.z }; }
    //Vector3 operator-=(const Vector3& other) { return { x -= other.x, y -= other.y, z -= other.z }; }
    //Vector3 operator*=(const Vector3& other) { return { x *= other.x, y *= other.y, z *= other.z}; }
    //Vector3 operator/=(const Vector3& other) { return { x /= other.x, y /= other.y, z /= other.z }; }
};

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);

// 内積
float Dot(const Vector3& v1, const Vector3& v2);

//長さ
float Length(const Vector3& v);

// 正規化
Vector3 Normalize(const Vector3& v);
