extends CanvasLayer

var coinCount = 0

func _ready():
	$coinLabel.text = str(coinCount)

func _on_coin_collected() -> void:
	coinCount += 1
	$coinLabel.text = str(coinCount)

func _on_AnimationPlayer_animation_finished(anim_name):
	if anim_name == "pickupAnimation":
		queue_free()
