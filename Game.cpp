#include "Game.h"

Game::Game(){
    //color for platforms
    grey = new sf::Color(105,105,105);
    //starting score
    score = 0;
    //a small gun, required parameters in global, also need to make 
    //a large bullet slow gun and perhaps make this faster
    SmallGun = new Gun(1,250, 5, 20);
    //player with player parameter
    Player1 = new Player(Global.PLAYER_SIZE,Global.PLAYER_X,Global.PLAYER_Y,Global.PLAYER_HEALTH, Global.PLAYER_SPEED, sf::Color::Magenta,Global. PLAYER_JUMP_HEIGHT,SmallGun);
    //declaring enemies, currently discconect between global and private enemy array size
    enemy = new Enemy*[Global.NUMBER_OF_ENEMIES];
    for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++)
    {
        enemy[i] = new Enemy(Global.ENEMY_SIZE,Global.PLAYER_X,Global.ENEMY_X,Global.ENEMY_Y, Global.ENEMY_SPEED, sf::Color::Red, Global.ENEMY_HEALTH);
    }
    //loading font from file and formattings its size
    font.loadFromFile("arial.ttf");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    beginGameButtonText.setCharacterSize(30);
    beginGameButtonText.setFillColor(sf::Color::Green);
    beginGameButtonText.setFont(font);
    exitGameButtonText.setCharacterSize(30);
    exitGameButtonText.setFillColor(sf::Color::Green);
    exitGameButtonText.setFont(font);
    //declaring all platform objects needed
    ground = new Platform(*grey,sf::Vector2f((int)1000,(int)100),sf::Vector2f(500,563));
    platform1 = new Platform(*grey,sf::Vector2f((int)200,(int)4),sf::Vector2f(500,200));
    platform2 = new Platform(*grey,sf::Vector2f((int)200,(int)4),sf::Vector2f(750,350));
    platform3 = new Platform(*grey,sf::Vector2f((int)200,(int)4),sf::Vector2f(250,350));
    leftWall = new Platform(*grey,sf::Vector2f((int)4,(int)1000),sf::Vector2f(1000,100));
    rightWall = new Platform(*grey,sf::Vector2f((int)4,(int)1000),sf::Vector2f(0,100));
    ceiling = new Platform(*grey,sf::Vector2f((int)1000,(int)75),sf::Vector2f(500,0));
    //declaring direction vectors needed to provide information about which direction the
    //collision occured at
    direction = new sf::Vector2f(0,0);
    direction2 = new sf::Vector2f(0,0);
    //game window
    window = new sf::RenderWindow(sf::VideoMode(Global.GW_X,Global.GW_Y), Global.GW_NAME);
    window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width/2 - window->getSize().x/2, sf::VideoMode::getDesktopMode().height/2 - window->getSize().y/2));
    //theta is a change in time and time is cumulative theta;
    theta = 0.0f;
    time = 0.0f;
    // Integer that controls what screen should be should such as main menu, main game or game over screen
    // Defaults to game state 
    gameScreen = "menu";
}

void Game::run(){
    while (window->isOpen()){
    //Clear window
    window->clear();
    //game time to be used as reference for all movements??
    time = time + theta;
    theta = clock.restart().asSeconds();
    //update mouse position
    mousePosition = sf::Mouse::getPosition(*window);
    //close event
    sf::Event clsevent;
    while (window->pollEvent(clsevent))
    {
        if (clsevent.type == clsevent.Closed)
        {
            window->close();
        }
    }

    // Controls what screen is shown
    if (gameScreen == "menu"){
        this->runMainMenu();
    }else if (gameScreen == "game"){
        this->runMainGame();
    }else if (gameScreen == "gameover"){
        this->runGameOver();
    }

    //display
    window->display();
    }
}

void Game::runMainMenu(){
    //format text to always be in the centre of the screen and draw
    //Perhaps group this in a function
    text.setString("Welcome to the \"" + Global.GW_NAME + "\" game!");
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2.0f,0));
    text.setPosition(sf::Vector2f(Global.GW_X/2,Global.GW_Y/2 - 100));

    beginGameButtonText.setString("Begin Game");
    beginGameButtonText.setOrigin(sf::Vector2f(beginGameButtonText.getLocalBounds().width/2.0f,0));
    beginGameButtonText.setPosition(sf::Vector2f(Global.GW_X/2,Global.GW_Y/2));

    exitGameButtonText.setString("Exit Game");
    exitGameButtonText.setOrigin(sf::Vector2f(exitGameButtonText.getLocalBounds().width/2.0f,0));
    exitGameButtonText.setPosition(sf::Vector2f(Global.GW_X/2,Global.GW_Y/2 + 50));

    window->draw(text);
    window->draw(beginGameButtonText);
    window->draw(exitGameButtonText);
    
    // Interaction with the 'Start Game' or 'Exit Game' text
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && beginGameButtonText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
        gameScreen = "game";
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && exitGameButtonText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
        window->close();
    }
}

// Starts the game when the main menu is interacted with
void Game::runMainGame(){
    //Update using the character class function, same inputs but different behaviour
    //example of polymorphism;
    Player1->update(theta, time, errormargin);
    for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++){
        enemy[i]->update(theta, time, errormargin);
    }
    //bullet and enemy collision
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < Global.NUMBER_OF_ENEMIES; j++)
        {
            if( SmallGun->getammo()[i].getcollision()->checkcollision( enemy[j]->getcollision(),direction2,1.0f)){
                enemy[j]->SetAlive(false);
                score += 1;
            }
        }
    }
    //player and enemy collision, kills enemy but damages player
    for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++){
            if( Player1->getcollision()->checkcollision( enemy[i]->getcollision(),direction2,1.0f)){
                enemy[i]->SetAlive(false);
                Player1->sethealth(Player1->gethealth()-1);//should be minus enemy damage in future
            }
    }
    //if players health drops below window, show the game over screen
    if (Player1->gethealth() <= 0){
        gameScreen = "gameover";
    }
    //calculates error margin for the ground between player, used to turn gravity off and on to stop continious bouncing
    //implement for platforms, perhaps return abs intersection from collider class
    errormargin = abs(abs(Player1->getcollision()->getposition().y - ground->getcollider()->getposition().y) - abs(Player1->getcollision()->gethalfsize().y + ground->getcollider()->gethalfsize().y));
    //reset direction
    direction->x = 0;
    direction->y = 0;
    //check ground and platform collision, if collided pass change direction to reflect direction of collisoin
    //PUT PLATFORM OBJECTS IN ARRAY AND PUT THIS IN LOOP
    if( ground->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
        Player1->onCollision(direction);
    }
    if (platform1->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
        Player1->onCollision(direction);
    }
    if (platform2->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
        Player1->onCollision(direction);
    }
    if (platform3->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
        Player1->onCollision(direction);
    }
    if (leftWall->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
        Player1->onCollision(direction);
    }
    if (rightWall->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
        Player1->onCollision(direction);
    }
    if (ceiling->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
        Player1->onCollision(direction);
    }
    //draw enemies
    for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++){
        enemy[i]->draw(window);
    }
    //draw player and platforms
    Player1->draw(window);//pass window address so it can be altered
    ground->drawplatform(window);
    platform1->drawplatform(window);
    platform2->drawplatform(window);
    platform3->drawplatform(window);
    leftWall->drawplatform(window);
    rightWall->drawplatform(window);
    ceiling->drawplatform(window);
    //format text to always be in the centre of the screen and draw
    //Perhaps group this in a function
    text.setString("Score: " + std::to_string(score) + "    " + "Health: " + std::to_string(Player1->gethealth()));
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2.0f,0));
    text.setPosition(sf::Vector2f(Global.GW_X/2,0));
    window->draw(text);
}

void Game::runGameOver(){
    //format text to always be in the centre of the screen and draw
    //Perhaps group this in a function
    text.setString("Game Over!");
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2.0f,0));
    text.setPosition(sf::Vector2f(Global.GW_X/2,Global.GW_Y/2 - 100));

    beginGameButtonText.setString("Try Again");
    beginGameButtonText.setOrigin(sf::Vector2f(beginGameButtonText.getLocalBounds().width/2.0f,0));
    beginGameButtonText.setPosition(sf::Vector2f(Global.GW_X/2,Global.GW_Y/2));

    exitGameButtonText.setString("Exit Game");
    exitGameButtonText.setOrigin(sf::Vector2f(exitGameButtonText.getLocalBounds().width/2.0f,0));
    exitGameButtonText.setPosition(sf::Vector2f(Global.GW_X/2,Global.GW_Y/2 + 50));

    window->draw(text);
    window->draw(beginGameButtonText);
    window->draw(exitGameButtonText);
    
    // Resetting the game when 'Try again' is pressed
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && beginGameButtonText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
        Player1->sethealth(Global.PLAYER_HEALTH);
        Player1->setbodyposition(sf::Vector2f(Global.PLAYER_X, Global.PLAYER_Y));

        //Removing all existing enemies, currently disconnect between global and private enemy array size
        for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++)
        {
            enemy[i]->SetAlive(false);
        }

        gameScreen = "game";
    }

    // Closing the window when 'Exit Game' is pressed
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && exitGameButtonText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
        window->close();
    }
}

//destructor
Game::~Game(){
    for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++)
    {
        delete enemy[i]; 
    }
    delete[] enemy; 
    delete grey;
    delete Player1;
    delete ground;
    delete platform1;
    delete platform2;
    delete platform3;
    delete leftWall;
    delete rightWall;
    delete ceiling;
    delete direction;
    delete direction2;
    delete window;

}
