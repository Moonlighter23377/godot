
#include "creator_workspace_plugin.h"

#ifdef TOOLS_ENABLED

#include "core/object/callable_mp.h"

// Creator Engine — Native Studio Catalog
// Godot 4.7.x compatible version.

struct CreatorStudioEntry {
	const char *name;
	const char *category;
	const char *description;
	const char *status;
	bool advanced;
};

static const CreatorStudioEntry STUDIO_CATALOG[] = {
	{ "Creator Workspace",
			"Production",
			"The unified native Creator Engine workspace.",
			"Working foundation", false },

	// Visuals and rendering.
	{
			"Lighting Studio",
			"Visuals",
			"Lights, shadows, global illumination, "
			"time of day and lighting presets.",
			"Planned integration", false },
	{ "PostFX Studio",
			"Visuals",
			"Bloom, grading, fog, film effects and "
			"cinematic post-processing.",
			"Planned integration", false },
	{ "Shader Studio",
			"Visuals",
			"Shaders, reusable visual effects and "
			"beginner-friendly shader creation.",
			"Planned", false },
	{ "Material Studio",
			"Visuals",
			"PBR materials, fabric, glass, metals "
			"and material presets.",
			"Planned", false },
	{ "Camera Studio",
			"Visuals",
			"Camera rigs, movement, tracking and "
			"cinematic camera controls.",
			"Planned", false },
	{ "VFX Studio",
			"Visuals",
			"Particles, trails, decals, impacts "
			"and other visual effects.",
			"Planned", false },
	{ "HD-2D Studio",
			"Visuals",
			"2D characters inside 3D environments "
			"with stylized lighting and cameras.",
			"Planned", false },
	{ "Renderer Studio",
			"Visuals",
			"Advanced rendering, image quality "
			"and renderer diagnostics.",
			"Future engine research", true },

	// Worlds and environment.
	{
			"Scene Builder",
			"Worlds",
			"Build environments using modular assets, "
			"placement tools and scene templates.",
			"Planned", false },
	{ "Environment Studio",
			"Worlds",
			"Terrain, water, weather, vegetation "
			"and environmental systems.",
			"Planned", false },
	{ "Terrain Builder",
			"Worlds",
			"Sculpt, paint and optimize terrain.",
			"Planned", false },
	{ "Rivers & Oceans",
			"Worlds",
			"Rivers, lakes, shorelines, oceans "
			"and underwater environments.",
			"Planned", false },
	{ "Foliage Studio",
			"Worlds",
			"Vegetation painting, trees, grass "
			"and procedural foliage.",
			"Planned", false },
	{ "Modular Construction",
			"Worlds",
			"Build roads, bridges, houses, fences "
			"and reusable structures.",
			"Planned", false },
	{ "Weather & Seasons",
			"Worlds",
			"Rain, snow, wind, seasons and "
			"environmental transitions.",
			"Planned", false },
	{ "World Streaming",
			"Worlds",
			"Scene streaming, chunk loading "
			"and large-world optimization.",
			"Future engine research", true },

	// Characters and presentation.
	{
			"Character Studio",
			"Characters",
			"Character setup, controllers, "
			"customization and movement.",
			"Planned", false },
	{ "Animation Studio",
			"Characters",
			"Animation editing, blending, "
			"state machines and IK.",
			"Planned", false },
	{ "UI Studio",
			"Characters",
			"HUDs, menus, responsive layouts "
			"and reusable UI components.",
			"Planned", false },
	{ "Audio Studio",
			"Characters",
			"Music, spatial audio, ambience "
			"and sound mixing.",
			"Planned", false },
	{ "Cinematic Studio",
			"Characters",
			"Cutscenes, camera timelines "
			"and story presentation.",
			"Planned", false },

	// Gameplay.
	{
			"Creator Logic",
			"Gameplay",
			"Visual programming blocks "
			"and simplified game logic.",
			"Planned", false },
	{ "Interaction Studio",
			"Gameplay",
			"Doors, switches, pickups, "
			"triggers and interactions.",
			"Planned", false },
	{ "Save & Load Studio",
			"Gameplay",
			"Save slots, autosave, persistence "
			"and data serialization.",
			"Planned", false },
	{ "Dialogue Studio",
			"Gameplay",
			"Dialogue trees, choices, conditions "
			"and branching conversations.",
			"Planned", false },
	{ "AI Behavior Studio",
			"Gameplay",
			"Behavior trees, navigation, "
			"perception and AI decisions.",
			"Planned", false },
	{ "Inventory Studio",
			"Gameplay",
			"Items, equipment, crafting "
			"and inventory systems.",
			"Planned", false },
	{ "Quest Studio",
			"Gameplay",
			"Quests, objectives, conditions "
			"and player journals.",
			"Planned", false },
	{ "Combat Studio",
			"Gameplay",
			"Combat, abilities, damage "
			"and status effects.",
			"Planned", false },

	// Genre frameworks.
	{
			"Management Studio",
			"Genres",
			"Economies, shops, production, "
			"customers and staffing.",
			"Planned", false },
	{ "Roguelite Studio",
			"Genres",
			"Procedural runs, rewards, upgrades "
			"and meta-progression.",
			"Planned", false },
	{ "RPG Studio",
			"Genres",
			"Stats, leveling, classes "
			"and RPG progression.",
			"Planned", false },
	{ "Platformer Studio",
			"Genres",
			"Reusable platforming mechanics "
			"and character movement.",
			"Planned", false },
	{ "Simulation Studio",
			"Genres",
			"Simulation rules, schedules, "
			"needs and time systems.",
			"Planned", false },
	{ "Strategy Studio",
			"Genres",
			"Tactical grids, units "
			"and strategy frameworks.",
			"Planned", false },
	{ "Rhythm Studio",
			"Genres",
			"Beat synchronization, timing "
			"and rhythm-game tools.",
			"Planned", false },
	{ "Creature & Gacha Studio",
			"Genres",
			"Creature collections, teams "
			"and configurable gacha systems.",
			"Planned", false },

	// Production and publishing.
	{
			"Steam Studio",
			"Production",
			"Steam achievements, lobbies "
			"and publishing workflows.",
			"Planned", false },
	{ "Multiplayer Studio",
			"Production",
			"Networking, replication, "
			"lobbies and online testing.",
			"Planned", false },
	{ "Input Studio",
			"Production",
			"Input mapping, remapping "
			"and controller support.",
			"Planned", false },
	{ "Localization Studio",
			"Production",
			"Translation, language switching "
			"and localization tools.",
			"Planned", false },
	{ "Accessibility Studio",
			"Production",
			"Accessibility controls, subtitles "
			"and UI scaling.",
			"Planned", false },
	{ "Testing Studio",
			"Production",
			"Automated tests, validation "
			"and playtest workflows.",
			"Planned", false },
	{ "Asset Pipeline",
			"Production",
			"Asset importing, processing "
			"and optimization.",
			"Planned", true },
	{ "Performance Studio",
			"Production",
			"CPU, GPU, memory and "
			"rendering performance tools.",
			"Planned", true }
};

static constexpr int STUDIO_COUNT =
		sizeof(STUDIO_CATALOG) /
		sizeof(STUDIO_CATALOG[0]);

CreatorWorkspacePlugin::CreatorWorkspacePlugin() {
	_build_ui();

	add_control_to_dock(
			DOCK_SLOT_RIGHT_UL,
			workspace);

	_refresh_catalog();
}

CreatorWorkspacePlugin::~CreatorWorkspacePlugin() {
	if (workspace != nullptr) {
		remove_control_from_docks(workspace);
		workspace->queue_free();
		workspace = nullptr;
	}
}

void CreatorWorkspacePlugin::_build_ui() {
	workspace = memnew(VBoxContainer);

	workspace->set_name("Creator Workspace");
	workspace->set_custom_minimum_size(
			Size2(260, 0));

	Label *heading = memnew(Label);
	heading->set_text("CREATOR ENGINE");
	workspace->add_child(heading);

	Label *subtitle = memnew(Label);
	subtitle->set_text("Unified Studio Workspace");
	workspace->add_child(subtitle);

	search = memnew(LineEdit);
	search->set_placeholder(
			"Search studios and features...");
	workspace->add_child(search);

	search->connect(
			"text_changed",
			callable_mp(
					this,
					&CreatorWorkspacePlugin::_on_search_changed));

	category_picker = memnew(OptionButton);
	category_picker->add_item("All Categories");
	category_picker->add_item("Visuals");
	category_picker->add_item("Worlds");
	category_picker->add_item("Characters");
	category_picker->add_item("Gameplay");
	category_picker->add_item("Genres");
	category_picker->add_item("Production");

	workspace->add_child(category_picker);

	category_picker->connect(
			"item_selected",
			callable_mp(
					this,
					&CreatorWorkspacePlugin::_on_category_changed));

	mode_picker = memnew(OptionButton);
	mode_picker->add_item("Easy Mode");
	mode_picker->add_item("Advanced Mode");
	workspace->add_child(mode_picker);

	mode_picker->connect(
			"item_selected",
			callable_mp(
					this,
					&CreatorWorkspacePlugin::_on_mode_changed));

	count_label = memnew(Label);
	workspace->add_child(count_label);

	studio_list = memnew(ItemList);
	studio_list->set_v_size_flags(
			Control::SIZE_EXPAND_FILL);
	studio_list->set_custom_minimum_size(
			Size2(0, 180));
	workspace->add_child(studio_list);

	studio_list->connect(
			"item_selected",
			callable_mp(
					this,
					&CreatorWorkspacePlugin::_show_studio));

	details = memnew(Label);
	details->set_autowrap_mode(
			TextServer::AUTOWRAP_WORD_SMART);
	details->set_custom_minimum_size(
			Size2(0, 145));
	workspace->add_child(details);

	Button *clear_button = memnew(Button);
	clear_button->set_text(
			"Clear Search & Filters");
	workspace->add_child(clear_button);

	clear_button->connect(
			"pressed",
			callable_mp(
					this,
					&CreatorWorkspacePlugin::_clear_filters));

	Label *footer = memnew(Label);
	footer->set_text(
			"Native Creator Engine module");
	workspace->add_child(footer);
}

void CreatorWorkspacePlugin::_refresh_catalog() {
	if (studio_list == nullptr) {
		return;
	}

	studio_list->clear();
	visible_studio_ids.clear();

	const String search_text =
			search->get_text().strip_edges();

	const String category =
			category_picker->get_item_text(
					category_picker->get_selected());

	const bool advanced =
			mode_picker->get_selected() == 1;

	for (int i = 0; i < STUDIO_COUNT; i++) {
		const CreatorStudioEntry &studio =
				STUDIO_CATALOG[i];

		if (!advanced && studio.advanced) {
			continue;
		}

		const String studio_category =
				String(studio.category);

		if (category != "All Categories" &&
				studio_category != category) {
			continue;
		}

		const String title = String(studio.name);
		const String description =
				String(studio.description);

		if (!search_text.is_empty()) {
			const bool matches =
					title.findn(search_text) >= 0 ||
					description.findn(search_text) >= 0 ||
					studio_category.findn(search_text) >= 0;

			if (!matches) {
				continue;
			}
		}

		studio_list->add_item(title);
		visible_studio_ids.push_back(i);
	}

	count_label->set_text(
			String::num_int64(
					visible_studio_ids.size()) +
			" studios");

	if (!visible_studio_ids.is_empty()) {
		studio_list->select(0);
		_show_studio(0);
	} else {
		details->set_text(
				"No matching studios.\n"
				"Try another search or category.");
	}
}

void CreatorWorkspacePlugin::_show_studio(int p_index) {
	if (p_index < 0 ||
			p_index >= visible_studio_ids.size()) {
		return;
	}

	const int catalog_index =
			visible_studio_ids[p_index];

	const CreatorStudioEntry &studio =
			STUDIO_CATALOG[catalog_index];

	const String text =
			String(studio.name) + "\n\n" +
			"Category: " +
			String(studio.category) + "\n" +
			"Status: " +
			String(studio.status) + "\n\n" +
			String(studio.description);

	details->set_text(text);
}

void CreatorWorkspacePlugin::_clear_filters() {
	search->set_text("");
	category_picker->select(0);
	mode_picker->select(0);
	_refresh_catalog();
}

void CreatorWorkspacePlugin::_on_search_changed(
		const String &p_text) {
	_refresh_catalog();
}

void CreatorWorkspacePlugin::_on_category_changed(
		int p_index) {
	_refresh_catalog();
}

void CreatorWorkspacePlugin::_on_mode_changed(
		int p_index) {
	_refresh_catalog();
}

#endif // TOOLS_ENABLED
