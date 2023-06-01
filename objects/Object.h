#pragma once

#include "../math/vec3.h"
#include "./Entity.h"

class Object {
    public:
        Object();
        virtual ~Object() noexcept;

    private:
        float mAngle = { };

        Vec3<float> mPos;
        Vec3<float> mAxis;

        Entity mEntity = { };
};

Object::Object() { }
Object::~Object() noexcept { }