#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class GDExample : public Sprite2D {
    GDCLASS(GDExample, Sprite2D);

private:
    double time_passed;   // Tracks elapsed time for the wave motion
    double amplitude;     // Amplitude of the wave motion
    double speed;         // Speed of the wave motion

public:
    // Constructor
    GDExample();

    // Process callback for each frame
    void _process(double delta) override;

    // Amplitude getter and setter
    void set_amplitude(const double p_amplitude);
    double get_amplitude() const;

    // Speed getter and setter
    void set_speed(const double p_speed);
    double get_speed() const;

    // Method to bind properties and functions to Godot
    static void _bind_methods();
};

#endif // GDEXAMPLE_H
