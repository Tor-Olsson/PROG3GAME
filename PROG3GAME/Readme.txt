Author Tor Olsson / tool2256
======================The Game======================
Music should be in /Sound/Music/
Background image in /Images/Backgrounds/

Paths can be changed in Game.cpp

Music downloaded from https://patrickdearteaga.com/chiptune-8-bit-retro/ published under Creative Commons license. Extended playtime in case someone plays the game longer than 29 seconds.
Background downloaded https://opengameart.org/content/mountain-at-dusk-background published under Creative Commons license. Author ansimuz

=====================GameEngine=====================

Functions that should be called to make use of GameEngine:
GameEngine.setTitle("The title of your game");
GameEngine.setBackground("Path to your image");

Not obligatory:
GameEngine.setBackgroundMusic("Path to your soundfile"); 
GameEngine.setFont("Path to your font"); (necessary for other OS than Windows)