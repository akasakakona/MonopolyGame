
# MONOPLOY
 
 > Authors: Kaiting Zheng   https://github.com/kaitingzheng
            Ryan Le         https://github.com/ryanle432
            Tangyuan Liang  https://github.com/akasakakona
 

PROJECT DESCRIPTION

We chose this project because we like board games, and monopoly seemed like a fun and interesting entry project. 
The language we are going to use is C++ and maybe a GUI extension to create our program. We chose C++ because it’s the most well known language for us and a GUI extension for displaying the monopoly board and player interaction. The GUI will handle pretty much all interactions since monopoly is a visual game.
The input for the game would just be the mouse. Players can use the mouse to interact with the board. The output would be visual feedback such as seeing the piece move on the board. 
The two design patterns we are using are abstract factory and strategy.


Abstract factory

We are choosing the abstract factory design pattern because, for example, Monopoly has multiple board pieces. We can create a base class, possibly named Piece, Building or Cards. These base classes will have simple features like moving, property tax or cost of building. There will also be several pieces on the board at the same time, including the player or very simple AI. Since both the players and AI will have the same possible actions, it makes sense to have both the player and AI inherit from a base class. This pattern will make it easier to implement to pieces as well as the different houses on the board since everything might differ by a little. 

Strategy 

We are choosing the strategy design pattern because throughout the game, we need to have the player object interacting with different locations like Stores, Cities, and Jails. When the player object visits each location, it needs to interact differently with each location object. 
A strategy class is needed in order to achieve the goal mentioned above. If we do not use this design pattern, we will have to define in the player object how to interact with each location object, which will make our code a mess. This design pattern will make our code cleaner. 


 The AbstractBoardFactory class reads in from the configuration files. Then determines whether it will return a PropertyFactory or ChessPieceFactory. The ChessPieceFactory will be responsible for making ChanceCard, ChestCard, and Player objects. The PropertiesFactory will be responsible for making Jail, Utility, Land, and Railroad classes.

The VisitDecider class is an abstract base class. Classes like VisitJailDecider, VisitRailroadDecider, VisitPropertyDecider, VisitUtilityDecider, VisitChanceDecider, and VisitChestDecider all inherit from the VisitDecider base class. Every class will implement a virtual function called interact() that will take a Player object as an argument and decide how this player object will interact with each different property object.

Board class will take care of all the interactions between Properties object and ChessPiece object. It hewill also call t

<img src="https://github.com/cs100/final-project-rle026-kzhen027-tlian020/blob/board_for_game/kzhen027/Project1/images/Project%20(1).jpg?raw=true">
<img src="https://github.com/cs100/final-project-rle026-kzhen027-tlian020/blob/board_for_game/kzhen027/Project1/images/Project.jpg?raw=true">
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
