#ifndef VECTOR_3D_HPP
#define VECTOR_3D_HPP
#include <assert.h>
#include <cmath>

struct Vector3D {
  float x, y, z;
  int length = 3;

  Vector3D() = default;

  Vector3D(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
  }

  float &operator[](int i) {
    assert(i < this->length);
    return ((&x)[i]);
  }

  const float &operator[](int i) const {
    assert(i < this->length);
    return ((&x)[i]);
  }

  Vector3D &operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return (*this);
  }

  Vector3D &operator/=(float s) {
    s = 1.0f / s;
    x *= s;
    y *= s;
    z *= s;
    return (*this);
  }

  Vector3D &operator+=(float s) {
    x += s;
    y += s;
    z += s;
    return (*this);
  }

  Vector3D &operator-=(float s) {
    x -= s;
    y -= s;
    z -= s;
    return (*this);
  }
};

inline Vector3D operator*(const Vector3D &v, float s) {
  return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator/(const Vector3D &v, float s) {
  s = 1.0f / s;
  return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator+(const Vector3D &v, float s) {
  return (Vector3D(v.x + s, v.y + s, v.z + s));
}

inline Vector3D operator-(const Vector3D &v, float s) {
  return (Vector3D(v.x - s, v.y - s, v.z - s));
}

inline Vector3D operator-(const Vector3D &v) {
  return (Vector3D(-v.x, -v.y, -v.z));
}

inline float magnitude(const Vector3D &v) {
  return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D normalize(const Vector3D &v) { return (v / magnitude(v)); }

inline float dot(const Vector3D &a, const Vector3D &b) {
  return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3D cross(const Vector3D &a, const Vector3D &b) {
  return (Vector3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x));
}

#endif