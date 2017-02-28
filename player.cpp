#include "player.h"

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite, states);
}

void Player::handleInput(const float & delta, Collisions & col)
{

    switch (curGenre)
    {
    case RPG:
        RPGInput(col, delta);
        break;
    case PLATFORMER:
        platformerInput(col, delta);
        break;
    }

}

void Player::platformerInput(Collisions & col, const float & delta)
{

    sprite.setTexture(&aMoving);

    //vertical axis handle:
    velocity.y += acceleration.y*delta;

    //collider for the player
    sf::FloatRect moveDirection(getPosition(), sprite.getSize());

    //move depending on velocity
    moveDirection.top += velocity.y;

    //check for collision
    if(!col.isWall(moveDirection))
    {
        move(0.0f, velocity.y);
    }
    else
    {
        //if can't go down enable jump
        velocity.y = 0.0f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            moveDirection.top -= jumpPower;
            if(!col.isWall(moveDirection))
            {
                velocity.y -= jumpPower;
            }
        }
    }

    //horizontal axis handle

    moveDirection = sf::FloatRect(getPosition(), sprite.getSize());

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveDirection.left -= velocity.x * delta + acceleration.x * delta * delta;
        anim.setAnimRow(1);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        if(!col.isWall(moveDirection))
        {
            move(-(velocity.x * delta + acceleration.x * delta * delta), 0.0f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveDirection.left += velocity.x * delta + acceleration.x * delta * delta;
        anim.setAnimRow(2);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        if(!col.isWall(moveDirection))
        {
            move(velocity.x * delta + acceleration.x * delta * delta, 0.0f);
        }
    }
    else
    {
        sprite.setTexture(&aIdle);
        anim.hold();
        sprite.setTextureRect(anim.getRect());
    }

}

void Player::RPGInput(Collisions &col, const float &delta)
{

    sprite.setTexture(&aMoving);
    sf::FloatRect moveDirection(getPosition(), sprite.getSize());

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        anim.setAnimRow(1);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        moveDirection.left -= velocity.x * delta + acceleration.x * delta * delta;
        if(!col.isWall(moveDirection))
        {
            move(-(velocity.x * delta + acceleration.x * delta * delta), 0.0f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        anim.setAnimRow(2);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        moveDirection.left += velocity.x * delta + acceleration.x * delta * delta;
        if(!col.isWall(moveDirection))
        {
            move(velocity.x * delta + acceleration.x * delta * delta, 0.0f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        anim.setAnimRow(3);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        moveDirection.top -= velocity.x * delta + acceleration.x * delta * delta;
        if(!col.isWall(moveDirection))
        {
            move(0.0f, -(velocity.x * delta + acceleration.x * delta * delta));
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        anim.setAnimRow(0);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        moveDirection.top += velocity.x * delta + acceleration.x * delta * delta;
        if(!col.isWall(moveDirection))
        {
            move(0.0f, velocity.x * delta + acceleration.x * delta * delta);
        }
    }
    else
    {
        sprite.setTexture(&aIdle);
        anim.hold();
        sprite.setTextureRect(anim.getRect());
    }

}

void Player::init()
{

    velocity = sf::Vector2f(150.0f, 0.0f);
    acceleration = sf::Vector2f(0.0f, 16.0f);

    aIdle.loadFromFile("Levels/basicTextures/PlayerIdle.png");
    aMoving.loadFromFile("Levels/basicTextures/Player.png");
    sprite.setTexture(&aIdle);
    sprite.setSize(sf::Vector2f(aIdle.getSize().x/4, aIdle.getSize().y/4));
    sprite.setTextureRect(sf::IntRect(0,0,aIdle.getSize().x/4, aIdle.getSize().y/4));
    anim.reset(aIdle.getSize(), sf::Vector2f(4,4), 0.2);

}
