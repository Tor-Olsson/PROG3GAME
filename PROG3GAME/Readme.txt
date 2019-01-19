Author Tor Olsson / tool2256
======================The Game======================
Music should be in /Sound/Music/
Background image in /Images/Backgrounds/
Sprites in /Sprites/
Fonts in /Fonts/

Paths can be changed in setUpGame() in Game.cpp

Controls:
Left and right arrow to move the tank.
Up arrow to shoot (for some reason SDLK_SPACE did not work on my computer, so we will have to make do with the up-key).

Game specific files:
Game.cpp
EarthDefense.*
EarthDefenseMissile.*
AlienScout.*
Life.*

=====================GameEngine=====================

Functions that should be called to make use of GameEngine:
GameEngine.setTitle("The title of your game");
GameEngine.setBackground("Path to your background image");
GameEngine.setBackgroundMusic("Path to your soundfile"); 
GameEngine.setFont("Path to your font");

======================Credits======================

Music downloaded from https://patrickdearteaga.com/chiptune-8-bit-retro/ published under Creative Commons license. Author Patrick de Arteaga.
Background downloaded https://opengameart.org/content/mountain-at-dusk-background published under Creative Commons license. Author ansimuz.
Alien ships and muzzle flashes downloaded from https://opengameart.org/content/space-ship-construction-kit published under Creative Commons license. Author Skorpio.
Ground defense downloaded from https://opengameart.org/content/saucy-trucks published under Creative Commons license. Author madmarcel.
Hearts downloaded from https://opengameart.org/content/heart-pixel-art published under Creative Commons license. Author DontMind8.
Font downloaded from https://fontlibrary.org/en/font/unique published under SIL Open Font License. Author Anna Pocius. 


