extends CharacterBody2D

@export var SPEED: float = 100.0
@export var GRAVITY: float = 1000.0
@export var JUMP_VELOCITY: float = -350.0

@onready var animated_sprite: AnimatedSprite2D = $AnimatedSprite2D

func _physics_process(delta):
	# Adding gravity
	if not is_on_floor():
		velocity.y += GRAVITY * delta
	elif Input.is_action_just_pressed("jump") and is_on_floor():
		velocity.y = JUMP_VELOCITY
		
	# Get input direction(1, 0, -1)
	var direction = Input.get_axis("move_left", "move_right")
	
	if is_on_floor():
		if direction == 0:
			animated_sprite.play("idle")
		else:
			animated_sprite.play("run")
	else:
		animated_sprite.play("jump")
		

	if direction > 0:
		animated_sprite.flip_h = false
	elif direction < 0:
		animated_sprite.flip_h = true
	
	# Apply movement
	if direction:
		velocity.x = direction * SPEED
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)

	move_and_slide()
