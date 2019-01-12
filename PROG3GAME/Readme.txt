Author Tor Olsson / tool2256
======================The Game======================
Music should be in /Sound/Music/
Background image in /Images/Backgrounds/
Sprites in /Sprites/Fixed/ and /Sprites/Animated/
Fonts in /Fonts/

Paths can be changed in setUpGame() in Game.cpp

Music downloaded from https://patrickdearteaga.com/chiptune-8-bit-retro/ published under Creative Commons license. Author Patrick de Arteaga.
Background downloaded https://opengameart.org/content/mountain-at-dusk-background published under Creative Commons license. Author ansimuz.
Alien ships and muzzle flashes downloaded from https://opengameart.org/content/space-ship-construction-kit published under Creative Commons license. Author Skorpio.
Ground defense downloaded from https://opengameart.org/content/saucy-trucks published under Creative Commons license. Author madmarcel.
Hearts (lifes) downloaded from https://opengameart.org/content/heart-pixel-art published under Creative Commons license. Author DontMind8.
Font downloaded from https://fontlibrary.org/en/font/unique published under SIL Open Font License. Author Anna Pocius. 

Game specific files:
Game.cpp
EarthDefense.cpp/h


=====================GameEngine=====================

Functions that should be called to make use of GameEngine:
GameEngine.setTitle("The title of your game");
GameEngine.setBackground("Path to your image");
GameEngine.setBackgroundMusic("Path to your soundfile"); 
GameEngine.setFont("Path to your font");