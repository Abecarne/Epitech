/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Vector3Utils.hpp
*/

#pragma once

#include "raylib.h"

namespace bomberman
{
    namespace utils
    {
        static Vector3 Vector3AddVector4(const Vector3 &a, const Vector4 &b)
        {
            return {a.x + b.x, a.y + b.y, a.z + b.z};
        }

        static Vector3 Vector3SubVector4(const Vector3 &a, const Vector4 &b)
        {
            return {a.x - b.x, a.y - b.y, a.z - b.z};
        }

        static Vector3 Vector3ModifyY(Vector3 a, const float coef)
        {
            a.y += coef;
            return a;
        }

        static Vector3 Vector3MultiplyByValue(Vector3 a, const float coef)
        {
            return {a.x * coef, a.y * coef, a.z * coef};
        }

        static Vector3 Vector3FromValue(const float coef)
        {
            return {coef, coef, coef};
        }

        static Vector3 Vector3Floor(Vector3 a)
        {
            a.x = floor(a.x);
            a.y = floor(a.y);
            a.z = floor(a.z);
            return a;
        }

        static bool Vector3isEqual(const Vector3 a, const Vector3 b)
        {
            return (a.x == b.x && a.y == b.y && a.z == b.z);
        }

        static bool Vector3isEqual2D(const Vector3 a, const Vector3 b)
        {
            return (a.x == b.x && a.z == b.z);
        }


        static float Vector3Distance(const Vector3 a, const Vector3 b)
        {
            return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2) + pow((b.z - a.z), 2));
        }

        static float Vector32DDistance(const Vector3 a, const Vector3 b)
        {
            return sqrt(pow((b.x - a.x), 2) + pow((b.z - a.z), 2));
        }
    };
};