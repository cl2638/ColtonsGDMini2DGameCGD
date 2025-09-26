# CS420 Assignment 2

**Author:** Colton Leighton  
**Project Type:** 2D Dungeon Crawler  with New GDExtension for wave pattern template. 
**Engine:** Godot Editor  

# WaterGDExtension Node  
**By Colton Leighton**  

## Overview
WaterGDExtension is a custom node that extends 'Sprite2D' using C++ GDExtension in Godot. It provides dynamic water-like motion for 2D game scenes and serves as a flexible template for visual effects or environmental graphics.

## Features
1. **Amplitude Control**  
   The node moves its sprite in a wave pattern using sine and cosine. The amplitude property is editable in the Godot editor, allowing adjustment of how far the sprite oscillates vertically and horizontally.

2. **Speed Control**  
   The speed property controls how fast the wave motion occurs. Changing this value in the editor allows for subtle ripples or faster motion.

Both properties are bound to Godot via 'bing_methods()' and appear in the inspector for easy adjustment.

## Flexibility
- The sprite's length and width can be edited to fit any scene layout.  
- 'process() ' updates the position each frame, creating smooth, continuous motion without using Godot’s built-in animation tools.  
- This makes WaterGDExtension reusable and adaptable for multiple types of scenes.

## Summary
WaterGDExtension is an editor-friendly node that extends 'Sprite2D' with adjustable wave motion. Its amplitude and speed properties allow precise control of motion, while scalable dimensions ensure it works in a variety of scenes. This node provides a strong foundation for creating dynamic water effects in 2D games.
