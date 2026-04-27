#pragma once
#define VEC3_H

#include <cmath>
#include <iostream>
#include <ostream>
#include <istream>

class vec3 {
    public:
        double e[3];

        vec3() : e{0, 0, 0} {} //default const
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} //const for specific vals

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        double operator[](int i) const { return e[i]; }

        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator *=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator /=(double t) {
            return *this *= 1/t;
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        double length() const {
            return std::sqrt(length_squared());
        }

};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& x, const vec3& y) {
    return vec3(x.e[0] + y.e[0], x.e[1] + y.e[1], x.e[2] + y.e[2]);
}

inline vec3 operator-(const vec3& x, const vec3& y) {
    return vec3(x.e[0] - y.e[0], x.e[1] - y.e[1], x.e[2] - y.e[2]);

}

inline vec3 operator*(const vec3& x, const vec3& y) {
    return vec3(x.e[0] * y.e[0], x.e[1] * y.e[1], x.e[2] * y.e[2]);
}

inline vec3 operator*(const vec3& x, double y) {
    return vec3(x.e[0] * y, x.e[1] * y, x.e[2] * y);
}

inline vec3 operator*(double y, const vec3& x) {
    return vec3(x * y);
}

inline vec3 operator/(const vec3& x, double y) {
    return vec3(x * (1/y));
}

inline double dot(const vec3& a, const vec3& b) {
    return a.e[0] * b.e[0]
        + a.e[1] * b.e[1]
        + a.e[2] * b.e[2];
}

inline vec3 cross(const vec3& a, const vec3& b) {
    return vec3((a.e[1] * b.e[2] - b.e[1] * a.e[2]), 
            -(a.e[0] * b.e[2] - a.e[2] * b.e[0]),
            (a.e[0] * b.e[1] - b.e[0] * a.e[1]));
}

inline vec3 unit_vector(const vec3& a) {
    return a / a.length();
}

