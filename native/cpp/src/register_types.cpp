#include "register_types.h"

#include "neon_core_bridge.h"

#include "gdextension_interface.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_neon_native(
    ModuleInitializationLevel p_level
)
{
    if (
        p_level !=
        MODULE_INITIALIZATION_LEVEL_SCENE
    ) {
        return;
    }

    GDREGISTER_CLASS(NeonCoreBridge);
}


void uninitialize_neon_native(
    ModuleInitializationLevel p_level
)
{
    if (
        p_level !=
        MODULE_INITIALIZATION_LEVEL_SCENE
    ) {
        return;
    }
}

extern "C" {

GDExtensionBool GDE_EXPORT
neon_native_library_init(
    GDExtensionInterfaceGetProcAddress
        p_get_proc_address,

    GDExtensionClassLibraryPtr
        p_library,

    GDExtensionInitialization
        *r_initialization
)
{
    GDExtensionBinding::InitObject init_obj(
        p_get_proc_address,
        p_library,
        r_initialization
    );

    init_obj.register_initializer(
        initialize_neon_native
    );

    init_obj.register_terminator(
        uninitialize_neon_native
    );

    init_obj.set_minimum_library_initialization_level(
        MODULE_INITIALIZATION_LEVEL_SCENE
    );

    return init_obj.init();
}

}