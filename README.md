
# Chicken Invaders Game

This project is an implementation of the classic Chicken Invaders game using C++ Qt. The game features a spaceship controlled by the player, who must shoot invading extraterrestrial chickens to protect the world. The game includes the following mechanics:

- **Spaceship Movement**: The spaceship is controlled using the arrow keys (left, right, up, down) and is represented by an image of a spaceship.
- **Shooting Lasers**: The spaceship can shoot lasers when the space bar is pressed. Lasers are represented by an image of a red laser.
- **Chicken Enemies**: Chickens spawn from the top of the screen at random positions and move towards the bottom. When a laser hits a chicken, the chicken is destroyed.
- **Health and Score**: The player starts with 3 health points. Every time a chicken bypasses the spaceship, the health is decremented. The player’s score increases each time a chicken is destroyed.
- **Game Over**: If the player’s health reaches zero, the game ends, and a "Game Over" message is displayed along with the player's score.
- **Sound Effects**: Sound is played when the bullet is emitted and when a chicken is destroyed to enhance the gaming experience.

