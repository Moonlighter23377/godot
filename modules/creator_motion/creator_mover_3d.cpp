
#include "creator_mover_3d.h"

#include "core/object/class_db.h"

CreatorMover3D::CreatorMover3D() {
	set_process(false);
}

void CreatorMover3D::_notification(int p_what) {
	if (p_what != NOTIFICATION_PROCESS) {
		return;
	}

	if (!moving) {
		return;
	}

	const float delta = get_process_delta_time();

	const Vector3 current = get_position();

	const Vector3 next_position = current.move_toward(
			target_position,
			movement_speed * delta);

	set_position(next_position);

	if (next_position.distance_to(target_position) <= 0.001f) {
		set_position(target_position);
		moving = false;
		set_process(false);
	}
}

void CreatorMover3D::move_to(
		const Vector3 &p_position,
		float p_speed) {
	if (p_speed <= 0.0f) {
		return;
	}

	target_position = p_position;
	movement_speed = p_speed;

	moving = true;
	set_process(true);
}

void CreatorMover3D::stop_moving() {
	moving = false;
	set_process(false);
}

bool CreatorMover3D::is_moving() const {
	return moving;
}

void CreatorMover3D::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("move_to", "position", "speed"),
			&CreatorMover3D::move_to);

	ClassDB::bind_method(
			D_METHOD("stop_moving"),
			&CreatorMover3D::stop_moving);

	ClassDB::bind_method(
			D_METHOD("is_moving"),
			&CreatorMover3D::is_moving);
}
