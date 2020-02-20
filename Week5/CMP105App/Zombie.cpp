#include "Zombie.h"
int moveSpeed = 0;
bool moving = false;

Zombie::Zombie(){
	walk.addFrame(sf::IntRect(0, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(55, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(110, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(165, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(220, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(275, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(330, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);
}

Zombie::~Zombie() {}

void Zombie::handleInput(float dt) {
	moveSpeed = 0;
	moving = false;

	if (input->isKeyDown(sf::Keyboard::Left)) {
		moveSpeed = -500;
		walk.setFlipped(true);
		moving = true;
	}

	if (input->isKeyDown(sf::Keyboard::Right)) {
		moveSpeed = 500;
		walk.setFlipped(false);
		moving = true;
	}
}

void Zombie::update(float dt) {
	if (moving) {
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
		move(moveSpeed * dt, 0);
	}
}

