# 1340GP  
 
# Team members (In alphabetical order): 

 Name | UID 
 ---- | ----
Cao Rui | 3035974303 
Deng Zihong | 3035962465 
Duan Xihan | 3035974042 
Fu Yeqiao | 3035974664 
He Minggao | 3035973373 

 

# Description of game and game rules 

## Instructions 

Please adjust the terminal size to at least 106*28 to ensure a normal game 	experience. 

## Game Introduction 

This is an underground adventure game where you play as a miner with the goal of digging as deep as possible before your oxygen runs out. There are two scenes in the game: underground exploration and base camp. In the underground scene, press 'a' and 'd' to dig left or right, and press 's' to dig down. 
The hardness of the soil will increase with depth, making it more difficult to dig. In the base camp scene, you can move around with 'w', 'a', 's', and 'd', and communicate with the merchant to purchase items.

## Operation Guide 

Operation | Description  
---- | ---- 
a、d | Dig left and right 
s | Dig Downwards 
r | Return to base camp 
w、a、s、d | Move around in base camp 
q | save and quit the game 

## Blocks 

Blocks | features 
---- | ---- 
'#' | you can break this block but the Hardness level may increase as you get deeper 
'X' | This rock is impregnable but you can still blast through it by bombs 
'$' | You can get more coins if you collect this kind of block 

## Merchants Description 

Name | Items |Purpose  
---- | ---- | ---- 
L | Digging equipments| Increase Digging Efficiency and Damage 
O | Oxygen Pack |Extend the maximum exploration time underground. 
M |Bomb | Blast through hard rocks 
A | skins | Change your appearance 

## Item Prices 

Items | prices  
---- | ---- 
Digging equipments| 500 coins for the first time (price*3 for every extra unit) 
Oxygen Pack | 200 coins for the first time  (price*2 for every extra unit) 
Bomb | 50 coins 
skins | 1000 coins 

## Game Over 

The game ends when your oxygen value reaches zero. 

Enjoy your adventure! 



# Features: 

Code Requirement:  

• Generation of random game sets or events  

• Data structures for storing game status  

• Dynamic memory management  

• File input/output (e.g., for loading/saving game status)  

• Program codes in multiple files  

 

## Block  

To better manage the game flow, we define the class “Block”. A 		block has member properties of health, appearance, id, and value. 		When digging down, the player can attack a block, decreasing its 		health, 	and when a block is broken, the player can 	collect coins equal 	 to the block’s value. A block’s id and appearance will determine 		its color and image shown on the game map. 

 

## Map  

The 2D map consists of single Blocks. 

We use a deque （deque <vector<Block> >） to store the game map. 	 When the player move down one tile, the deque will pop out the 		first line and a new line will be pushed in. When creating a new line, 	we use <random> to randomly generate the component Blocks of the 	line. 

 

## Player 

To better manage the game flow, we define the class “Player”. A player has member properties of appearance, bombNumber, damage, wealth, oxygen, x, y. The player records its current position on the map, its depth, and the number of items it owns. 

 

## UI  

The UI program can draw our game’s interfaces on the screen, the 	  	drawborder function equiped our game interfaces with a butiful blue 	border. The printStr function prints a string at a specified position on 	the screen with a specified color. The draw function takes in a 2D 		vector representing a map and a player object, and displays them on 	the screen. It loops through the elements of the map and prints their 	characters at appropriate positions with appropriate colors. 

 

## Shop 

In order to make the purchase experience between games more vivid 	and interactive, we implement a map in shop where the program 		captures the player's location and movements through several 			functions. At the same time, we applied the skin system, where a 		vector is used to store the skins that can be purchased. When the 		player selects the appropriate skins, the skins are called through 		dynamic memory management. 

	 

## Timer

We use timer function to compute a timer to get exact time in game to 	judge whether the oxygen is used or not. 

	 

## Save & Load system 

We wrote an io program that includes some functions for file I/O and 	working with objects. The saveToFile function saves the player's 		information to a file named gameData.dat, and loadFromFile function 	reads the player's information from that file. This program enables 		players to save game data when quit the game and load the store 		data when restart the game 

 

## Program code management 

Our codes are separated into multiple files: ‘block.h’, ‘block.cpp’, 		’gamemap.h’, ’gamemap.cpp’, ’player.h’, ’player.cpp’, ’shop.h’, 			’shop.cpp’, ’io.cpp’, ’io.h’, ’timer.h’, ’timer.cpp’, ’ui.h’, ’ui.cpp’, 			’main.cpp’, which makes the code structure more clear and concise. 

 
 
# Libraries: 

curses.h 

ctime 

cmath 

Unistd.h 

ncurses.h 

 

# Compilation and execution Instructions: 

execute make main use  
./main to start the game  
