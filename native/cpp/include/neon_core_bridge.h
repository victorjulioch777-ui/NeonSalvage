#ifndef NEON_CORE_BRIDGE_H
#define NEON_CORE_BRIDGE_H

#include <cstdint>

#include "godot_cpp/classes/ref_counted.hpp"
#include <godot_cpp/variant/vector2i.hpp>

namespace godot {

class NeonCoreBridge : public RefCounted {
    GDCLASS(NeonCoreBridge, RefCounted)

protected:
    static void _bind_methods();

public:
    int64_t random_from_seed(int64_t seed) const;

    int32_t manhattan_distance(
        Vector2i a,
        Vector2i b
    ) const;
};

}

#endif