# MONOPLOY
 
  **Authors** 

  Kaiting Zheng   https://github.com/kaitingzheng

  Ryan Le         https://github.com/ryanle432

  Tangyuan Liang  https://github.com/akasakakona

**PROJECT DESCRIPTION**

We chose this project because we like board games, and monopoly seemed like a fun and interesting entry project. 
The language we are going to use is C++. We chose C++ because it’s the most well known language for us and a GUI extension for displaying the monopoly board and player interaction. The GUI will handle pretty much all interactions since monopoly is a visual game.
The input for the game would just be the input from command line interface. The output would be the text feedback from the game itself. 
The two design patterns we are using are factory and strategy.


**Factory**

We are choosing the factory design pattern because, for example, Monopoly has many properties with different names and different prices. We can create a base class, possibly named Piece, Building or Cards. These base classes will have attributes that are shared across properties: name, price, interact(Player*).  This pattern will make it easier for players to customize their own map by simply changing the name and price inside of the configuration file. 

**Strategy**

We are choosing the strategy design pattern because throughout the game, we need to give players the freedom to choose their own winning rules and give us developers the ability to easily add more winning rules to expand our game in the future. 
A strategy class is needed in order to achieve the goal mentioned above. If we do not use this design pattern, we will have lose the ability for players to choose their winning rule and it will be harder to add more winning rules in the future, which will make our code a mess. This design pattern will make our code cleaner. 

<img src="https://raw.githubusercontent.com/cs100/final-project-rle026-kzhen027-tlian020/master/Project1/Images/Final%20OMT%20Diagram.jpg?token=AKPWCG3CQHKXK6GBRG4YQU3AKGTVS">

The WinnerDecider class is an abstract base class. Classes like DecideByMostMoney, DecideByMostProperty, DecideByTenThousand, DecideByLastBroke all inherit from the WinnerDecider base class. Every class will implement a virtual function called evaluateWinner() that will take a Game object as an argument and decide who is the winner of the game.
 
The PropertyFactory class reads in from the configuration files. Then determines what Property object to create, what name the object should be called and how much should the object be. The PropertiesFactory will be responsible for making Jail, Utility, Land, Railroad, Tax, and Corner classes.

The WinnerDecider class is an abstract base class. Classes like VisitJailDecider, VisitRailroadDecider, VisitPropertyDecider, VisitUtilityDecider, VisitChanceDecider, and VisitChestDecider all inherit from the VisitDecider base class. Every class will implement a virtual function called interact() that will take a Player object as an argument and decide how this player object will interact with each different property object.

Game class will take care of all the interactions between Player object and Properties object. It will also call the PropertyFactory to initialize the board. On top of that, Game class will decide who is the winner of the game.

 ## Screenshots
 > Screenshots of the input/output after running your application

**Starting Screen**

<img src="https://github.com/cs100/final-project-rle026-kzhen027-tlian020/blob/master/Project1/Images/Screenshot.png">

**Ending Screen**

<img src="https://github.com/cs100/final-project-rle026-kzhen027-tlian020/blob/master/Project1/Images/Screenshot1.png">

 ## Installation/Usage
 Instructions on installing and running your application
 Step 1: Install all files on Github
 Step 2: Using a C++ compiler, compile using `g++ main.cpp Player.cpp WinnerDecider.cpp Game.cpp -o monopoly`
 Step 3: Now run the program. `./monopoly.exe price_rent_mortgage cards` or `./monopoly price_rent_mortgage cards` depending on your pc. 
 Step 4: The game is text based. Follow the prompts on the screen to play.
 **NOTE:** This game is customizable, just edit the `price_rent_mortgage` and `cards` file and you will be able to change the name/price of properties and message of cards!
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.

Our project was tested/validated using Google Tests and unit testing. We unit tested each class, which can be seen in the "unit_tests" folder. Our unit tests were aimed at making sure the code would behave as expected. For example, a chance card. The unit tests for chance and chest cards made sure that a chance/chest card object could be made and would work as intended in game. In other words, the unit test made sure that a player could land, draw, and the card would perform the action as intended. These kind of unit tests were done for all classes, including factories. We used cmake to also run these tests. Furthermore, we created a debug branch on GitHub. Using this branch we ran the game ourselves on our individual machines and looked for bugs. We all played the games ourselves to find any bugs, and we were able to elimnate many bugs by doing so. Since the game has many random possibilites, this was the best way to test/validate our game. 
## Recent Changes
2/26/21 -3/1/21 Implemented property factory to create the different property present on the board.

3/1/21 - 3/4/21 Implemented the chance piece, chest piece, tax piece and updated the property factory accordingly also created the player class.

 3/5/21 - 3/7/21 Implement chance cards, community chest cards, and interact functions. Property functions also received interact functions. Game logic added.

 3/8/21 - 3/9/21 Most recent changes before our project due date was debugging once our final.  
