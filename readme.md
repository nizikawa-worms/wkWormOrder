# wkWormOrder v.1.2.0
_Worms Armageddon WormKit module that appends worm order numbers to their names and allows randomizing the worm order within the team in multiplayer games._

**Usage of this module should be discussed with other players beforehand.**

## Features
- To enable displaying order of your worms, use **/order my** command in game chat.
- To enable displaying order of all worms, use **/order all** command in game chat.
- During replay playback all worms have their numbers displayed. 
- The displayed worm name format is customizable in .ini with **{name}** and **{number}** tags.
- In multiplayer games the worm order within your team can be scrambled. The order is scrambled every time you add the team to the round roster. To enable this feature set: **ScrambleWormOrder = 1**
- Team name bars can have their owner name displayed. The displayed format is customizable with **{name}** (team name), **{owner}** (owner nickname), **{hp}** (sum of HP of all worms within the team) and **{wins}** (number of team wins in match) tags. To enable this feature set: **TeamNameShowOwner = 1** or use **/owner** command in game chat.
