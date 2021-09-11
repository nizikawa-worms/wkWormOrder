# wkWormOrder v.1.1.0
_Worms Armageddon WormKit module that appends worm order numbers to their names and allows randomizing the worm order within the team in multiplayer games._

## Features
- Worms belonging to you have their numbers displayed. During replay playback all worms have their numbers displayed. The displayed format is customizable in .ini with **{name}** and **{number}** tags.
- To enable displaying order of all worms, use **/order** command in game chat. Usage of this feature should be discussed with other players beforehand.
- In multiplayer games the worm order within your team can be scrambled. The order is scrambled every time you add the team to the round roster. To enable this feature set: **ScrambleWormOrder = 1**
- Team name bars can have their owner name displayed. The displayed format is customizable with **{name}**, **{owner}** and **{hp}** (sum of HP of all worms within the team) tags. To enable this feature set: **TeamNameShowOwner = 1** or use **/owner** command in game chat.
