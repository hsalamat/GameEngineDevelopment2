
#include "Command.hpp"
#include "SceneNode.hpp"
#include <iostream>

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

void moveLeft(SceneNode& node, sf::Time dt)
{
	node.move(-30.f * dt.asSeconds(), 0.f);
	cout << "Node Moving Left. Position is = " << node.getPosition().x << "," << node.getPosition().y << endl;
}

void moveRight(SceneNode& node, sf::Time dt)
{
	node.move(30.f * dt.asSeconds(), 0.f);
	cout << "Node Moving Right. Position is = " << node.getPosition().x << "," << node.getPosition().y << endl;
}

void moveDown(SceneNode& node, sf::Time dt)
{
	node.move(0.f , 30.f * dt.asSeconds());
	cout << "Node Moving Down. Position is = " << node.getPosition().x << "," << node.getPosition().y << endl;
}

void moveUp(SceneNode& node, sf::Time dt)
{
	node.move(0.f , -30.f * dt.asSeconds());
	cout << "Node Moving Up. Position is = " << node.getPosition().x << "," << node.getPosition().y << endl;
}

void launchMissile(SceneNode& node, sf::Time dt)
{
	cout << "Missile is launched at Position = " << node.getPosition().x << "," << node.getPosition().y << endl;

}


int main() {
	sf::RenderWindow mWindow(sf::VideoMode(640, 480), "Command", sf::Style::Close);


	SceneNode node;
	Command c;

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			sf::Event event;
			while(mWindow.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:		
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
						//c.action = launchMissile;
						c.action = [](SceneNode& node, sf::Time dt)
						{
							cout << "Missile is launched at Position = " << node.getPosition().x << "," << node.getPosition().y << endl;
						};
						c.action(node, TimePerFrame);
					}
					break;

				case sf::Event::KeyReleased:
					break;

				case sf::Event::Closed:
					mWindow.close();
					break;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				c.action = &moveUp;
				c.action(node, TimePerFrame);
			}
				
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				c.action = &moveDown;
				c.action(node, TimePerFrame);
			}
		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				c.action = &moveLeft;
				c.action(node, TimePerFrame);
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				//Do the same thing using lamda expression
				c.action = [](SceneNode& node, sf::Time dt)
				{
					node.move(30.f * dt.asSeconds(), 0.f);
					cout << "Node Moving Right. Position is = " << node.getPosition().x << "," << node.getPosition().y << endl;
				};
				c.action(node, TimePerFrame);
			}
		

		}

	}
	

	string bye = "bye";
	getline(cin, bye);

	return 0;
	
}



