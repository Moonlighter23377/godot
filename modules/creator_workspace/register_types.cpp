
#include "register_types.h"

#ifdef TOOLS_ENABLED
#include "creator_workspace_plugin.h"

#include "editor/plugins/editor_plugin.h"
#endif

void initialize_creator_workspace_module(
		ModuleInitializationLevel p_level) {
#ifdef TOOLS_ENABLED
	if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
		EditorPlugins::add_by_type<CreatorWorkspacePlugin>();
	}
#endif
}

void uninitialize_creator_workspace_module(
		ModuleInitializationLevel p_level) {
}
