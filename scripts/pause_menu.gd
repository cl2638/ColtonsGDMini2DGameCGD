extends Control

func _ready():
	$PanelContainer.hide()
	$AnimationPlayer.play("RESET")

func resume():
	get_tree().paused = false
	$AnimationPlayer.play_backwards("blur")
	$PanelContainer.hide()

func pause():
	get_tree().paused = true
	$PanelContainer.show()
	$AnimationPlayer.play("blur")
	
func testEsc():
	if Input.is_action_just_pressed("escape") and get_tree().paused == false:
		pause()
	elif Input.is_action_just_pressed("escape") and get_tree().paused == true:
		resume()


func _on_resume_pressed():
	resume()

func _on_restart_pressed():
	resume()
	get_tree().reload_current_scene()

func _on_quit_pressed():
	get_tree().quit()

func _process(delta):
	testEsc()
