#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/floor.h"
#include "headers/wall.h"
#include "headers/ceiling.h"
#include "headers/functionalFloor.h"
#include "headers/functionalWall.h"
#include "headers/movingPlatform.h"

#include "headers/character.h"

#include <iostream>
#include <cmath>


float Character::getXCenter()
{
    sf::FloatRect containingBox = (*this).getGlobalBounds();
    float xCenter = containingBox.width/2 + (*this).getPosition().x;
    return xCenter;
}
float Character::getYCenter()
{
    sf::FloatRect containingBox = (*this).getGlobalBounds();
    float yCenter = containingBox.width/2 + (*this).getPosition().y;
    return yCenter;
}

bool Character::didCollideWith(Character character)
{
    sf::FloatRect box_sprite = (*this).getGlobalBounds();
    sf::FloatRect box_sprite2 = character.getGlobalBounds();
    if (box_sprite.intersects(box_sprite2) )
    {
        m_hitSomething = true;
        return true;
    }
    else 
    {
        //m_hitSomething = false;
        return false;
    }
}

bool Character::didCollideWith(Floor floor)
{
    sf::FloatRect box_sprite = (*this).getGlobalBounds();
    sf::FloatRect box_sprite2 = floor.getGlobalBounds();
    if (box_sprite.intersects(box_sprite2) )
    {
        m_hitSomething = true;
        return true;
    }
    else 
    {
        //m_hitSomething = false;
        return false;
    }
}

bool Character::didCollideWith(Wall wall)
{
    sf::FloatRect box_sprite = (*this).getGlobalBounds();
    sf::FloatRect box_sprite2 = wall.getGlobalBounds();
    if (box_sprite.intersects(box_sprite2) )
    {
        m_hitSomething = true;
        return true;
    }
    else 
    {
        //m_hitSomething = false;
        return false;
    }
}

bool Character::didCollideWith(Ceiling ceiling)
{
    sf::FloatRect box_sprite = (*this).getGlobalBounds();
    sf::FloatRect box_sprite2 = ceiling.getGlobalBounds();
    if (box_sprite.intersects(box_sprite2) )
    {
        m_hitSomething = true;
        return true;
    }
    else 
    {
        //m_hitSomething = false;
        return false;
    }
}

bool Character::didCollideWithOverloaded(FunctionalFloor floor)
{
    bool didCollideFloor;
    bool didCollideLeftWall;
    bool didCollideRightWall;
    bool didCollideCeiling;
    
    if( (*this).didCollideWith( floor.getCeiling() ) )
        {return true;}
    else if ( (*this).didCollideWith( floor.getLeftWall() ) )
        {return true;}
    else if ( (*this).didCollideWith( floor.getLeftWall() ) )
        {return true;}
    else if( (*this).didCollideWith( floor) )
        {return true;}
    else 
        {return false;}
}

bool Character::didCollideWithOverloaded(FunctionalWall wall)
{
   
    
    if( (*this).didCollideWith( wall.getCeiling() ) )
        {return true;}
    else if ( (*this).didCollideWith( wall.getFloor() ) )
        {return true;}
    else if( (*this).didCollideWith( wall) )
        {return true;}
    else 
        {return false;}
}






void Character::getRestrictions(Floor floor) //assume you can only collide with floors below
{
    if( (*this).didCollideWith(floor) )
    {
        m_restricted_down = true; /*
        m_wasRestricted_down = true; //in order to check if you were restricted down 1 frame ago.
        m_unrestrictedFrameCounter =0;*/
        
        for( int iii=0; iii<25; iii+=1)
        {
            (*this).move(0,-1); //move up till no collision. 
            if ( !( (*this).didCollideWith(floor) ))
            {
                break;
            }
        }
        (*this).move(0,2); //move back into 1 pixel collision
    }
    /*else
    {
        m_unrestrictedFrameCounter +=1;
        if( m_unrestrictedFrameCounter >100 )
        {
            m_wasRestricted_down = false;
        }
    }*/
}

void Character::getRestrictions(Wall wall) //assume you can only collide with walls on the right and left
{
    if( (*this).didCollideWith(wall) )
    {
        int rightCounter=0;
        int leftCounter =0;
        
        for( int iii=0; iii<25; iii+=1)
        {
            (*this).move(1,0); //move right till no collision. 
            rightCounter+=1;
            
            if ( !( (*this).didCollideWith(wall) ))
            {
                break;
            }
        }
        (*this).move(-rightCounter,0); //move back to starting point.
        
        for( int iii=0; iii<25; iii+=1)
        {
            (*this).move(-1,0); //move left till no collision. 
            leftCounter+=1;
            
            if ( !( (*this).didCollideWith(wall) ))
            {
                break;
            }

        }
        (*this).move(leftCounter, 0) ;//move back to starting point.
        
        switch (rightCounter >= leftCounter)
        {
            case true: //left is the smaller distance, so move it left out of the wall. leave 1pxl collision
                m_restricted_right = true;
                (*this).move(-leftCounter+1,0);
                break;
            case false:
                m_restricted_left=true;
                (*this).move(rightCounter-1,0);
                break;
        }
    }
}





void Character::getRestrictions(Ceiling ceiling)
{
    if( (*this).didCollideWith(ceiling) )
    {
        m_restricted_up = true;
        
        for( int iii=0; iii<25; iii+=1)
        {
            (*this).move(0,2); //move down till no collision. 
            if ( !( (*this).didCollideWith(ceiling) ))
            {
                break;
            }
        }
        (*this).move(0,-2); //move back into 1 pixel collision
    }
}




void Character::getRestrictionsOverloaded( FunctionalFloor floor)
{
    (*this).getRestrictions(floor.getLeftWall());
    (*this).getRestrictions(floor.getRightWall());
    (*this).getRestrictions(floor.getCeiling());
    (*this).getRestrictions(floor);
    
}

void Character::getRestrictionsOverloaded( FunctionalWall wall)
{
    (*this).getRestrictions(wall.getFloor());
    
    (*this).getRestrictions(wall.getCeiling());
    (*this).getRestrictions(wall);
    
}







void Character::resetRestrictions()
{
    restrictRight(false);
    restrictLeft(false);
    restrictUp(false);
    restrictDown(false);
    m_hitSomething =false;
}



void Character::movement()
{
                 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !m_restricted_left )
    {
        if(m_leftRightVelocity>-4) //set max velocity
            {m_leftRightVelocity -=1;} //set accel
    }  
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !m_restricted_right )
    {
        if(m_leftRightVelocity <4) //set max velocity
            {m_leftRightVelocity+=1;} //set accel
    }
    
    else 
    {
        if (m_leftRightVelocity<0)
            {m_leftRightVelocity+=1;}
        if (m_leftRightVelocity>0)
            {m_leftRightVelocity -=1;}
    }
    (*this).move(m_leftRightVelocity, m_upDownVelocity);
   
}

void Character::movementWASD()
{
                 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !m_restricted_left )
    {
        if(m_leftRightVelocity>-4) //set max velocity
            {m_leftRightVelocity -=1;} //set accel
    }  
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !m_restricted_right )
    {
        if(m_leftRightVelocity <4) //set max velocity
            {m_leftRightVelocity+=1;} //set accel
    }
    
    else 
    {
        if (m_leftRightVelocity<0)
            {m_leftRightVelocity+=1;}
        if (m_leftRightVelocity>0)
            {m_leftRightVelocity -=1;}
    }
    (*this).move(m_leftRightVelocity, m_upDownVelocity);
   
}
 


void Character::gravity()
{
    float accelFromGravity = 1;
    
    if( !m_restricted_down)
    {
        m_upDownVelocity = m_upDownVelocity + accelFromGravity;
        if (m_upDownVelocity >20) {m_upDownVelocity = 20;} //terminal velocity
        
    }
    else if(m_restricted_down)
    {
        m_upDownVelocity=0;
       
    }
    if (m_isJumping)
    {
        m_upDownVelocity+= -4 + m_jumpCounter;
        m_jumpCounter+=.6;
        if (m_upDownVelocity<-10){ m_isJumping = false;m_jumpCounter=0;}
        
        
    }   
    if (m_restricted_up)
    {
        m_upDownVelocity = 0;
        m_jumpCounter+=2;
        if (m_jumpCounter>5)
            {m_upDownVelocity =1;m_jumpCounter=0;}
        m_isJumping = false;
    }
    
 
}

void Character::followTether(Character shadowCharacter)
{
    float yVel = shadowCharacter.getYCenter() -(*this).getYCenter();
    float xVel = shadowCharacter.getXCenter() - (*this).getXCenter();
    
    if (xVel ==0){xVel=1;}
    if (yVel==0){yVel = 1;}
    xVel = xVel/( sqrt( xVel*xVel + yVel*yVel) ); //normalize
    yVel = yVel/( sqrt( xVel*xVel + yVel*yVel) );
    
    xVel = xVel*4; //set how fast you follow tether
    yVel = yVel*4;
    
    if( ! (*this).didCollideWith(shadowCharacter) )
    {
        (*this).move(xVel, yVel);
    }
}

void Character::followPlatform( MovingPlatform platform)
{
    
    if( (*this).didCollideWith( platform ))
    {
        (*this).move( platform.getXVel(), platform.getYVel() );
    }
        // the stuff below is to try to fix the bug where you lose collision at the top of up-down platforms and so cannot jump as soon as the platform starts moving down
   /*
   if( (*this).didCollideWith( platform.getOverBox() ) && !(*this).didCollideWith( platform ) )
   {
        m_isJumping = true;
   }
    */
     
            
}



