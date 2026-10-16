#include "neon_core_bridge.h"

#include <godot_cpp/core/class_db.hpp>

extern "C" {
#include "neon_core.h"
}

namespace godot {

void NeonCoreBridge::_bind_methods()
{
    ClassDB::bind_method(
        D_METHOD("random_from_seed", "seed"),
        &NeonCoreBridge::random_from_seed
    );

    ClassDB::bind_method(
        D_METHOD(
            "manhattan_distance",
            "a",
            "b"
        ),
        &NeonCoreBridge::manhattan_distance
    );
}

int64_t NeonCoreBridge::random_from_seed(
    int64_t seed
) const
{
    uint32_t state =
        static_cast<uint32_t>(seed);

    return static_cast<int64_t>(
        nc_xorshift32(&state)
    );
}

int32_t NeonCoreBridge::manhattan_distance(
    Vector2i a,
    Vector2i b
) const
{
    NC_Point point_a = {
        a.x,
        a.y
    };

    NC_Point point_b = {
        b.x,
        b.y
    };

    return nc_manhattan_distance(
        point_a,
        point_b
    );
}

}