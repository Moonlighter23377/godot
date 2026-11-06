
#include "register_types.h"

#include "creator_mover_3d.h"

#include "core/object/class_db.h"

void initialize_creator_motion_module(
		ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<CreatorMover3D>();
}

void uninitialize_creator_motion_module(
		ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
