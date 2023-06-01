#pragma once

#include "../math/vec3.h"
#include "./Entity.h"

class Object {
    public:
        Object() = delete;

    protected:
        Object(const Entity& _entity, const Vec3<float>& _pos);
        virtual ~Object() noexcept;

    private:
        float mAngle = { };

        Vec3<float> mPos;
        Vec3<float> mAxis;

        Entity mEntity = { };
};

Object::Object(const Entity& _entity, const Vec3<float>& _pos)
    : mEntity{_entity}
    , mPos{_pos}
{ }
Object::~Object() noexcept { }