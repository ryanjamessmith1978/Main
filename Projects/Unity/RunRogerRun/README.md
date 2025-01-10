

Run Roger Run

Background Story
Roger was a middle-aged man looking for some adventure in his life.  He stumbled across an ad online about prototyping a new type of game reality.  This sounded exciting to Roger, so he decided to reach out to this company called Dynamic Realities.  There was no response.  The ad appeared to be a scam.  Oh well said Roger.

Fifteen minutes later, the familiar chime of the Zelda theme song plays on Roger's phone.  

"Hello?" says Roger.

"Is this Roger Ramstein?" the voice replied.  

"Yes, it is, who is this?" says Roger.

All Roger heard next were a couple of weird beep sounds followed by a text message to an address.

Despite Roger's suspicions, he was feeling adventurous combined with a bit of hopelessness.  You see, Roger was out of a job and had no motivation to find a similar position.  Roger was striving for something new in his life, so he begrundingly showed up at the address.  It looked like an abandoned warehouse from the outside.  As soon as Roger knocked on the door it opened.  There were a group of high tech security agents to greet Roger.  After frisking him and checking his id, he entered into the next room, where an HR representative introduced herself.  After the initial freak-out, Roger understood the high tech nature and neccessary security protocols of the situation.  Excitement and Fear crept in simultaneously as an Engineer approached Roger with some type of head mounted apparatus.  As the procedure was being explained to Roger, Roger felt cool sensations at multiple points on his head with a gel-like sensation.  

Next thing Roger knew, he was running, and falling off ledges.  The sensation of falling was so visceral.  It scared the heck out of Roger.  As Roger yelled out to the engineer to come out, nothing happened!  Roger was trapped.  All he could do now to try to escape was to run!  Run Roger Run!


Game type
Endless Runner.  Endless Runners were made popular on mobile platforms.

Excerpt from Wikipedia about Endless Runners:

'Endless runner or infinite runner is a subgenre of platform game in which the player character runs for an infinite amount of time while avoiding obstacles. The player's objective is to reach a high score by surviving for as long as possible.[1] The method by which the game level or environment appears to continuously spawn before the player is an example of procedural generation. The genre exploded on mobile platforms following the success of Canabalt, Jetpack Joyride and Temple Run[2] being other popular examples.[3] Its popularity is attributed to its simple gameplay that works well on touchscreen devices.[4]'  


Gameplay Mechanics
The Gameplay is centered around dodging, sprinting, crouching, and jumping your way around various obstacles and chasms.  If any obstacle makes contact with Roger or he falls of a platform, it's game over.  Each time you die, you have to start at level 1.  The action occurs from the first person camera perspective.  The FP Camera gives the game an intimate level of realism and challenge.  

The purpose of the game is collect coins and gems to achieve a high score.  Coins are worth 100 points while gems are worth 500 points.  Once you achieve a certain number of points a new endless level is instantiated.  Level 1 is the start with 0 points.  Level 2 is reached once the player scores 2000 points.  Level 3 is reached with 5000 points.  Level 4 is reached with a score of 10000 points.  Level 5 can be reached with 16000 points.  Finally, you win the game when you score a total of 25000 points on level 5.  At which point, a YOU WIN win screen appears at the top of the screen.  At which point you can press enter to start again, or press esc to quit.

In addition to scoring points by collecting gems and coins at various heights and horizontal locations, moving itself nets Roger points.  You can sprint by holding down the sprint button, which will always be 2x fast as your walk speed.  The faster Roger goes the more bonus points Roger will receive.  This adds additional strategy and intensity when attempting to get that high score.

Another advance mechanic occurs on a level by level basis.  Each level gets progressively more challenging while still maintianing the randomization of obstacles and collectibles through procedural generation.  Roger's base speed increases as Roger progresses the level.  In addition to that Roger's acceleration increases at a faster rate, but his scoring speed multiplier increases as well.  The number of spawned obstacles, spawn gap, jump speed, gravity, and various other gameplay mechanics change as Roger progresses through the levels.  


Level Design

As mentioned above, the difficulty of the levels increase as Roger progresses.

Level 1 is slow with basic obstacles and low spawn rates.  There aren't any gems premade and a low chance of gems spawning.  Level 2 ups the challenge some with a more cluttered initial area and faster speeds.  The green mossy ground material and calming music track give Level 2 a distinct feel.  Level 3 ups the difficulty rather steeply.  There are lots of bouncy ball hazards, floot gaps, more spawns per section, and a few more gems to balance out the difficulty.  Level 4 offers additional variety with side platforms, a much higher acceleration rate, and more obstacles.  Level 5, also known as the yellow brick road is the final stage.  The initial speed and acceleration are insane in level 5, but if you could hold on, victory will be yours.


Game States
Title Screen state brings you to the title screen and waits for an enter input to start the play state.  The play state is where the action and control occurs.  The play state start immediately upon pressing enter from the title screen.  There are brief pauses between levels once the high score goal is achieved for that particular level.  The game over state occurs when you die.  You have the option to press enter to start again or press esc to quit the application.


Controls
Enter - Starts the game and exits the Game Over screen to head back to the title screen.  You can also use enter to start at level 1 once you have achieved the You Win screen at the end of Level 5.

Esc - The escape key stops the game's play state from within Unity's editor as well as quits the application of a build version of the game running as a standalone.

Shift - Enables sprint.  Sprinting doubles Roger's normal walk speed.

S and F keys - Move Roger horizontally on the Platform.  Mouse look is disabled to keep Roger on a straight forward path.

Spacebar - Jumps.  Jump Speed and Gravity change from level to level.

C - Crouches or Ducks.  You need to slide under some road blocks.


What, Why, and How
What I did was create an Endless Runner game using the Unity Engine.  I downloaded assets from the Unity store to fill in some of the basic graphics environment in order to render a comprehensive game prototype.  I created various obstacles, UI, Game Manager and procedural generation scripts to enable a simple but elegant gameplay system.  

Why I chose to make an endless runner eludes me at this time.  The game idea just popped in my head.  I'm assuming these ideas came from the previous two projects of DreadHalls and the Portal Pro builder exercises from GD50.  Using procedural generation while applying a semi unique gameplay experience of first person running seemed like it could work.  After I had the base idea in my heads, other ideas just came pouring out as I was designing and coding up the game.


Bibliography

https://en.wikipedia.org/wiki/Endless_runner

 Polansky, Lana (2013-07-01). "The Leaderboard: The Loneliness of the Endless Runner". Paste Magazine. Retrieved 2021-12-31.
 Fahey, Mike (2013-02-27). "Wouldn't Sonic Be the Perfect Endless Runner Hero? Sega Might Agree. [Update]". Kotaku. Retrieved 2021-12-31.
 Whitwam, Ryan (2014-03-11). "Not So Fast for Android Turns the Endless Runner on its Head". PC Magazine. Retrieved 2021-12-31.
 Parkin, Simon (2013-06-07). "Don't Stop: The Game That Conquered Smartphones". The New Yorker. Retrieved 2022-01-01.
 
 UI images:
 
 https://www.rawpixel.com/image/3815889/boom-png-web-icon-outline-style
 
 Graphics, Models, Textures, and Sound:
 
 https://assetstore.unity.com/packages/2d/textures-materials/sky/cartoon-stylized-skybox-130609 - skybox
 
 https://assetstore.unity.com/packages/audio/sound-fx/cartoon-game-sound-5438 - sound fx/cartoon-game-sound-5438
 
 https://assetstore.unity.com/packages/templates/tutorials/endless-runner-sample-game-87901 - models
 
 https://assetstore.unity.com/packages/audio/music/toon-adventure-soundtrack-60684 - music track
 
 Google creative common pics used including the Roger Rabbit on the title screen.  Updating completion date.
 
 

