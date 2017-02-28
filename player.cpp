#include "player.h"

float playerSpeedX = 100.0f;
float playerSpeedY = 0.0f;
float playerAccelerationY = 9.8f;

Player::Player()
{
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite, states);
}

void Player::handleInput(const float & delta, Collisions & col)
{

    sprite.setTexture(&aMoving);
    int genre = 0;
    if(genre == 0)
    {

        playerSpeedY += playerAccelerationY*delta;
        if(!col.isWall(sf::FloatRect(getPosition().x, getPosition().y+playerSpeedY, sprite.getSize().x, sprite.getSize().y)))
        {
            move(0, playerSpeedY);
        }
        else
        {
            playerSpeedY = 0;
        }

        if(playerSpeedY == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&
                !col.isWall(sf::FloatRect(getPosition().x, getPosition().y-3.6, sprite.getSize().x, sprite.getSize().y)))
        {
            playerSpeedY = -3.6;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            anim.setAnimRow(1);
            anim.update(delta);
            sprite.setTextureRect(anim.getRect());
            if(!col.isWall(sf::FloatRect(getPosition().x-playerSpeedX*delta, getPosition().y,
                                         sprite.getTextureRect().width, sprite.getTextureRect().height)))
            {
                move(sf::Vector2f(- playerSpeedX*delta,0.0));
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            anim.setAnimRow(2);
            anim.update(delta);
            sprite.setTextureRect(anim.getRect());
            if(!col.isWall(sf::FloatRect(getPosition().x+playerSpeedX*delta, getPosition().y,
                                         sprite.getTextureRect().width, sprite.getTextureRect().height)))
            {
                move(sf::Vector2f(playerSpeedX*delta,0.0));
            }
        }
        else
        {
            sprite.setTexture(&aIdle);
            anim.hold();
            sprite.setTextureRect(anim.getRect());
        }

    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            anim.setAnimRow(1);
            anim.update(delta);
            sprite.setTextureRect(anim.getRect());
            if(!col.isWall(sf::FloatRect(getPosition().x-playerSpeedX*delta, getPosition().y,
                                         sprite.getTextureRect().width, sprite.getTextureRect().height)))
            {
                move(sf::Vector2f(-playerSpeedX*delta,0.0));
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            anim.setAnimRow(2);
            anim.update(delta);
            sprite.setTextureRect(anim.getRect());
            if(!col.isWall(sf::FloatRect(getPosition().x+playerSpeedX*delta, getPosition().y,
                                         sprite.getTextureRect().width, sprite.getTextureRect().height)))
            {
                move(sf::Vector2f(playerSpeedX*delta,0.0));
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            anim.setAnimRow(3);
            anim.update(delta);
            sprite.setTextureRect(anim.getRect());
            if(!col.isWall(sf::FloatRect(getPosition().x, getPosition().y-playerSpeedX*delta,
                                         sprite.getTextureRect().width, sprite.getTextureRect().height)))
            {
                move(sf::Vector2f(0.0,-playerSpeedX*delta));
            }

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            anim.setAnimRow(0);
            anim.update(delta);
            sprite.setTextureRect(anim.getRect());
            if(!col.isWall(sf::FloatRect(getPosition().x, getPosition().y+playerSpeedX,
                                         sprite.getTextureRect().width, sprite.getTextureRect().height)))
            {
                move(sf::Vector2f(0.0,playerSpeedX));
            }

        }
        else
        {
            sprite.setTexture(&aIdle);
            anim.hold();
            sprite.setTextureRect(anim.getRect());
        }
    }
}

void Player::init()
{
    aIdle.loadFromFile("Levels/basicTextures/PlayerIdle.png");
    aMoving.loadFromFile("Levels/basicTextures/Player.png");
    sprite.setTexture(&aIdle);
    sprite.setSize(sf::Vector2f(aIdle.getSize().x/4, aIdle.getSize().y/4));
    sprite.setTextureRect(sf::IntRect(0,0,aIdle.getSize().x/4, aIdle.getSize().y/4));
    anim.reset(aIdle.getSize(), sf::Vector2f(4,4), 0.2);
}
