extends Area2D

signal coin_collected

@onready var animation_player: AnimationPlayer = $AnimationPlayer

func _on_body_entered(body):
	if body.is_in_group("player"):
		emit_signal("coin_collected")
		animation_player.play("pickupAnimation")
