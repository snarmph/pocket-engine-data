@vec2i {
	x: i32
	y: i32
}

@frametype {
	length: i32
	duration: f32
}

@animationtype {
    name: str
    frames: vec<frametype>
    repeat: bool
}

@data {
	size: vec2i 
	texture: str
	animations: vec<animationtype>
	initial_state: str
}