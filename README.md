# 42so_long

Prior to starting with this project, it’s better to learn about the miniLibX,
the simple graphic library that we use at 42. Luckily I have a sample project where I a talk about how it works and what it offers here: https://github.com/S-LucasSerrano/miniLibX_sample The aim of this project is to create a small 2D game where players have to pick up all collectables and go to the exit making as few moves as possible. In my case, the game is about a muscular gardener cleaning up her garden from weeds. While ¿alien? creatures stand in her way. Because they are on mars. Or something.


# Maps
The game is able to play any map you want as long as it follow some specific rules:

Prior to starting with this project, it’s better to learn about the miniLibX,
the simple graphic library that we use at 42. Luckily I have a sample project where I a talk about how it works and what it offers here: https://github.com/S-LucasSerrano/miniLibX_sample The aim of this project is to create a small 2D game where players have to pick up all collectables and go to the exit making as few moves as possible. In my case, the game is about a muscular gardener cleaning up her garden from weeds. While ¿alien? creatures stand in her way. Because they are on mars. Or something.

The map has to be a .ber file.
It can only contain some of the following characters:
Character	Object
1	Wall.
0	Empty space.
C	Collectable.
E	Exit.
P	Player starting position.
H	Horizontal enemy. It moves to left and right, changing direction when its path is blocked.
V	Vertical enemy. Moving up and down.
F	Following enemy. Each move tries to get closer to the player
The map must be a rectangle surrounded by walls ‘1’.
It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.
See some examples in the map_files folder of this project.

# Controls
Use WASD or ARROWS to move . Enemies move in randomic way, also one tile at a time, and will kill you when you move into their tile or they move into yours. After picking up all shoes, the exits open and you may leave to see how many moves you’ve used to solve the map.

You can close it with esc.
