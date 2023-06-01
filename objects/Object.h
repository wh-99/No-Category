#pragma once

#include "../math/vec3.h"
#include "./Entity.h"

class Object {
    public:
        Object() = delete;

    protected:
        Object(const Vec3<float>& _pos, const Entity& _entity);
        virtual ~Object() noexcept;

    private:
        float mAngle = { };

        Vec3<float> mPos;
        Vec3<float> mAxis;

        Entity mEntity = { };
};

Object::Object(const Vec3<float>& _pos, const Entity& _entity)
    : mPos{_pos}
    , mEntity{_entity}
{ }
Object::~Object() noexcept { }