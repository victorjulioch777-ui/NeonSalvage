extends Node


func _ready() -> void:
    print("================================")
    print("Neon Salvage - Native Lab")
    print("================================")

    var bridge := NeonCoreBridge.new()

    var seed := 12345

    var random_value = bridge.random_from_seed(seed)

    print("Seed: ", seed)
    print("Random generado desde C: ", random_value)

    var point_a := Vector2i(0, 0)
    var point_b := Vector2i(4, 3)

    var distance = bridge.manhattan_distance(
        point_a,
        point_b
    )

    print(
        "Distancia Manhattan: ",
        distance
    )

    print("================================")

    get_tree().quit()