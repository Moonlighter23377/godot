
#pragma once

#include "scene/3d/node_3d.h"

class CreatorMover3D : public Node3D {
    GDCLASS(CreatorMover3D, Node3D);

private:
    Vector3 target_position;
    float movement_speed = 2.0f;
    bool moving = false;

protected:
    static void _bind_methods();
    void _notification(int p_what);

public:
    CreatorMover3D();

    void move_to(
        const Vector3 &p_position,
        float p_speed
    );

    void stop_moving();

    bool is_moving() const;
};
