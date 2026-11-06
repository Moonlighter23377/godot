
#ifndef CREATOR_WORKSPACE_PLUGIN_H
#define CREATOR_WORKSPACE_PLUGIN_H

#ifdef TOOLS_ENABLED

#include "editor/plugins/editor_plugin.h"

#include "core/templates/vector.h"
#include "scene/gui/box_container.h"
#include "scene/gui/button.h"
#include "scene/gui/item_list.h"
#include "scene/gui/label.h"
#include "scene/gui/line_edit.h"
#include "scene/gui/option_button.h"

class CreatorWorkspacePlugin : public EditorPlugin {
    GDCLASS(CreatorWorkspacePlugin, EditorPlugin);

private:
    VBoxContainer *workspace = nullptr;
    LineEdit *search = nullptr;
    OptionButton *category_picker = nullptr;
    OptionButton *mode_picker = nullptr;
    ItemList *studio_list = nullptr;
    Label *details = nullptr;
    Label *count_label = nullptr;

    Vector<int> visible_studio_ids;

    void _build_ui();
    void _refresh_catalog();
    void _show_studio(int p_index);
    void _clear_filters();

    void _on_search_changed(const String &p_text);
    void _on_category_changed(int p_index);
    void _on_mode_changed(int p_index);

protected:
    static void _bind_methods() {}

public:
    CreatorWorkspacePlugin();
    ~CreatorWorkspacePlugin();
};

#endif // TOOLS_ENABLED

#endif // CREATOR_WORKSPACE_PLUGIN_H
