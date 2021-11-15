# Traffic Light Simulation
### Basic traffic light simulation for Arduino.

The aim of this project was to simulate two sets of four-phase traffic lights with a pedestrian crossing. This was created with an Arduino and 8 LEDs to represent the traffic lights.

The code first declares all variables and initializing all ports on the Arduino which are linked to the various bulbs. Functions are used to group the outputs into groups to represent each individual traffic light set. For example, ‘set1’ controls the outputs of what would be the red, amber and green bulbs for the first set of traffic lights.

The system then listens for the ‘X’ button being pressed, which represents the pedestrian crossing button. When pressed, it executes the pedestrian crossing code. That is, it that stops cars from both directions and allows the pedestrians to cross before restarting the main loop.

Setup:
1. Set 1:
   - Port 6 = Red LED
   - Port 7 = Amber LED
   - Port 8 = Green LED

2. Set 2:
   - Port 8 = Red LED
   - Port 9 = Amber LED
   - Port 10 = Green LED

3. Pedestrian Crossing:
   - Port 6 = Red LED
   - Port 7 = Green LED
