#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>
#include <cmath>  // for sin() and cos()

using namespace godot;

// Bind properties and methods so they show up in the Godot editor
void GDExample::_bind_methods() {
    // Amplitude
    ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
    ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &GDExample::set_amplitude);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

    // Speed
    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &GDExample::set_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "set_speed", "get_speed");
}

// Constructor
GDExample::GDExample() {
    time_passed = 0.0;
    amplitude = 10.0; // default amplitude
    speed = 1.0;      // default speed
}

// Main process loop
void GDExample::_process(double delta) {
    // Advance time scaled by speed
    time_passed += speed * delta;

    // Compute new position in a wave-like pattern
    Vector2 new_position = Vector2(
        amplitude + (amplitude * sin(time_passed * 2.0)),
        amplitude + (amplitude * cos(time_passed * 1.5))
    );

    set_position(new_position);
}

// Amplitude setter/getter
void GDExample::set_amplitude(const double p_amplitude) {
    amplitude = p_amplitude;
}

double GDExample::get_amplitude() const {
    return amplitude;
}

// Speed setter/getter
void GDExample::set_speed(const double p_speed) {
    speed = p_speed;
}

double GDExample::get_speed() const {
    return speed;
}
