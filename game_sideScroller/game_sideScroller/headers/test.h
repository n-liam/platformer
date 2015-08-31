#ifndef TEST_H
#define TEST_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "floor.h"
#include "wall.h" 
#include "character.h"
#include "functionalFloor.h"
#include "functionalWall.h"
#include "movingPlatform.h"
#include "door.h"
#include "switch.h"
#include "laser.h"
#include "checkpoints.h"


namespace Test
{
    
    sf::Texture blackDotTexture;
    sf::Texture greenDotTexture;
    sf::Texture whiteDotTexture;
    sf::Texture castleTexture;
    sf::Texture floorTexture;
    
    Floor resetFloor1;
    Floor resetFloor2_1;
    Floor resetFloor2_2;
    Floor resetFloor3_1;
    Floor resetFloor3_2;
    
    FunctionalFloor goodFloorSprite;
    FunctionalFloor goodFloorSprite2;
    FunctionalFloor floor3;
    FunctionalFloor floor4ShadowOnly;
    FunctionalFloor floor5;
    FunctionalFloor floor2_1;
    FunctionalFloor floor2_2shadowOnly;
    FunctionalFloor floor2_3;
    FunctionalFloor floor2_4mainOnly;
    FunctionalFloor floor2_5;
    FunctionalFloor floor2_6;
    FunctionalFloor floor2_7shadowOnly;
    FunctionalFloor floor2_8mainOnly;
    FunctionalFloor floor2_9shadowOnly;
    FunctionalFloor floor2_10mainOnly;
    FunctionalFloor floor2_11shadowOnly;
    FunctionalFloor floor2_12mainOnly;
    FunctionalFloor floor2_13shadowOnly;
    FunctionalFloor floor2_14shadowOnly;
    FunctionalFloor floor3_1;
    MovingPlatform  floor3_2moving; 
    MovingPlatform  floor3_3moving;
    MovingPlatform  floor3_4movingShadowOnly;   
    FunctionalFloor floor3_5mainOnly;   
    MovingPlatform  floor3_6movingShadowOnly;
    FunctionalFloor floor3_7shadowOnly;
    MovingPlatform  floor3_8moving;
    MovingPlatform  floor3_9moving;
    FunctionalFloor floor3_10;
    FunctionalFloor floor3_11shadowOnly;
    FunctionalFloor floor3_12mainOnly;
    FunctionalFloor floor3_13shadowOnly;
    FunctionalFloor floor3_14mainOnly;
    FunctionalFloor floor3_15shadowOnly;
    FunctionalFloor floor3_16mainOnly;
    MovingPlatform  floor3_17moving;
    MovingPlatform  floor3_18moving;
    MovingPlatform  floor3_19moving;
    MovingPlatform  floor3_20moving;
    FunctionalFloor floor3_21shadowOnly;
    FunctionalFloor floor3_22mainOnly;
   
    
    
   
   
    Floor deathFloor3_1;
    
    FunctionalWall goodWallSprite;
    FunctionalWall wall1;
    FunctionalWall wall2_1;
    FunctionalWall wall2_2;
    FunctionalWall wall3_1;
    FunctionalWall wall3_2;
    
    FunctionalWall castle1;
    FunctionalWall castle2;
    FunctionalWall castle3;
    
    Door door1;
    Door door2_1;
    Door door3_1;
    
    Switch switch1;
    Switch switch2_1;
    Switch switch3_1;
    
    Laser laserSprite;
    sf::Sprite energyBar;
    sf::Sprite spamPreventionBar;
    
    
    
    
    
    
    //remember to set textures first
    
    void setFloor()    
    {
        floorTexture.loadFromFile("sprites/badWall.png");
        blackDotTexture.loadFromFile("sprites/blackDot.png");
        greenDotTexture.loadFromFile("sprites/greenDot.png");
        whiteDotTexture.loadFromFile("sprites/whiteDot.png");
        castleTexture.loadFromFile("sprites/Castle.png");
       
        
        goodWallSprite.setTexture(floorTexture);
        goodWallSprite.setScaleOverloaded(1,34);
        goodWallSprite.setPositionFull(850,932-340);
        
        wall1.setTexture(floorTexture);
        wall1.setScaleOverloaded(1,5);
        wall1.setPositionFull(500, 950);
        
        wall2_1.setTexture(floorTexture);
        wall2_1.setScaleOverloaded(1,20);
        wall2_1.setPositionFull(4200,500);
        
        wall2_2.setTexture(floorTexture);
        wall2_2.setScaleOverloaded(1,20);
        wall2_2.setPositionFull(6100,535);
        
        wall3_1.setTexture(floorTexture);
        wall3_1.setScaleOverloaded(1,15);
        wall3_1.setPositionFull(12500,-250);
        
        wall3_2.setTexture(floorTexture);
        wall3_2.setScaleOverloaded(1,20);
        wall3_2.setPositionFull(12500,0);
        
        
        
        
        resetFloor1.setTexture(blackDotTexture);
        resetFloor1.setScale(4000,50);
        resetFloor1.setPosition(-1000,1400);
        
        resetFloor2_1.setTexture(blackDotTexture);
        resetFloor2_1.setScale(1760,50);
        resetFloor2_1.setPosition(3000,1400);
        
        resetFloor2_2.setTexture(blackDotTexture);
        resetFloor2_2.setScale(2740,50);
        resetFloor2_2.setPosition(4760,1400);
        
        resetFloor3_1.setTexture(blackDotTexture);
        resetFloor3_1.setScale(2650,50);
        resetFloor3_1.setPosition(7500,1400);
        
        resetFloor3_2.setTexture(blackDotTexture);
        resetFloor3_2.setScale(10000,50);
        resetFloor3_2.setPosition(10150,1400);
     
        
        goodFloorSprite.setTexture(floorTexture);
        goodFloorSprite.setScaleOverloaded(35,2);
        goodFloorSprite.setPositionFull(0,1000);
        
        goodFloorSprite2.setTexture(floorTexture);
        goodFloorSprite2.setScaleOverloaded(35,2);
        goodFloorSprite2.setPositionFull(850,1300);
        
        floor3.setTexture(floorTexture);
        floor3.setScaleOverloaded(8,2);
        floor3.setPositionFull(1200,1100);
        
        floor4ShadowOnly.setTexture(floorTexture);
        floor4ShadowOnly.setScaleOverloaded(8,2);
        floor4ShadowOnly.setPositionFull(1700,1200);
        floor4ShadowOnly.setColor(sf::Color::Green);
        
        floor5.setTexture(floorTexture);
        floor5.setScaleOverloaded(35,2);
        floor5.setPositionFull(1900, 1150);
        
        floor2_1.setTexture(floorTexture);
        floor2_1.setScaleOverloaded(10,2);
        floor2_1.setPositionFull(3500, 500);
        
        floor2_2shadowOnly.setTexture(floorTexture);
        floor2_2shadowOnly.setScaleOverloaded(2,2);
        floor2_2shadowOnly.setPositionFull(4000,700);
        floor2_2shadowOnly.setColor(sf::Color::Green);
        
        floor2_3.setTexture(floorTexture);
        floor2_3.setScaleOverloaded(10,2);
        floor2_3.setPositionFull(4064, 700);
        
        floor2_4mainOnly.setTexture(floorTexture);
        floor2_4mainOnly.setScaleOverloaded(10,2);
        floor2_4mainOnly.setPositionFull(4300,800);
        floor2_4mainOnly.setColor(sf::Color::Yellow);
        
        floor2_5.setTexture(floorTexture);
        floor2_5.setScaleOverloaded(5,2);
        floor2_5.setPositionFull(4600, 700);
        
        floor2_6.setTexture(floorTexture);
        floor2_6.setScaleOverloaded(5,2);
        floor2_6.setPositionFull(4760, 600);
        
        floor2_7shadowOnly.setTexture(floorTexture);
        floor2_7shadowOnly.setScaleOverloaded(5,2);
        floor2_7shadowOnly.setPositionFull(5000, 600);
        floor2_7shadowOnly.setColor(sf::Color::Green);
        
        floor2_8mainOnly.setTexture(floorTexture);
        floor2_8mainOnly.setScaleOverloaded(5,2);
        floor2_8mainOnly.setPositionFull(5200,700);
        floor2_8mainOnly.setColor(sf::Color::Yellow);
        
        floor2_9shadowOnly.setTexture(floorTexture);
        floor2_9shadowOnly.setScaleOverloaded(5,2);
        floor2_9shadowOnly.setPositionFull(5250, 570);
        floor2_9shadowOnly.setColor(sf::Color::Green);
        
        floor2_10mainOnly.setTexture(floorTexture);
        floor2_10mainOnly.setScaleOverloaded(5,2);
        floor2_10mainOnly.setPositionFull(5800,800);
        floor2_10mainOnly.setColor(sf::Color::Yellow);
        
        floor2_11shadowOnly.setTexture(floorTexture);
        floor2_11shadowOnly.setScaleOverloaded(5,2);
        floor2_11shadowOnly.setPositionFull(5500, 570);
        floor2_11shadowOnly.setColor(sf::Color::Green);
        
        floor2_12mainOnly.setTexture(floorTexture);
        floor2_12mainOnly.setScaleOverloaded(20,2);
        floor2_12mainOnly.setPositionFull(6000,800);
        floor2_12mainOnly.setColor(sf::Color::Yellow);
        
        floor2_13shadowOnly.setTexture(floorTexture);
        floor2_13shadowOnly.setScaleOverloaded(5,2);
        floor2_13shadowOnly.setPositionFull(5750, 570);
        floor2_13shadowOnly.setColor(sf::Color::Green);
        
        floor2_14shadowOnly.setTexture(floorTexture);
        floor2_14shadowOnly.setScaleOverloaded(10,2);
        floor2_14shadowOnly.setPositionFull(6000, 570);
        floor2_14shadowOnly.setColor(sf::Color::Green);
        
        floor3_1.setTexture(floorTexture);
        floor3_1.setScaleOverloaded(5,2);
        floor3_1.setPositionFull( 8000, 60);
        
        floor3_2moving.setScaleOverloaded(100,20);
        floor3_2moving.setXStart( 8200);
        floor3_2moving.setYStart( 60 );
        floor3_2moving.setXEnd(8200);
        floor3_2moving.setYEnd(150);
        floor3_2moving.setXVel(0);
        floor3_2moving.setYVel(2);
        floor3_2moving.setColor(sf::Color::Black);
        
        floor3_3moving.setScaleOverloaded(100,20);
        floor3_3moving.setXStart( 8800);
        floor3_3moving.setYStart( 170 );
        floor3_3moving.setXEnd(8400);
        floor3_3moving.setYEnd(170);
        floor3_3moving.setXVel(3);
        floor3_3moving.setYVel(0);
        floor3_3moving.setColor(sf::Color::Black);
        
        //floor3_4movingShadowOnly.setTexture(floorTexture);
        //floor3_4movingShadowOnly.setColor(sf::Color::Green);
        floor3_4movingShadowOnly.setScaleOverloaded(100,20);
        floor3_4movingShadowOnly.setXStart( 8900);
        floor3_4movingShadowOnly.setYStart( 170 );
        floor3_4movingShadowOnly.setXEnd(8900);
        floor3_4movingShadowOnly.setYEnd(0);
        floor3_4movingShadowOnly.setXVel(0);
        floor3_4movingShadowOnly.setYVel(2);
        
        
        floor3_5mainOnly.setTexture(floorTexture);
        floor3_5mainOnly.setScaleOverloaded(10,2);
        floor3_5mainOnly.setPositionFull(9050,20);
        floor3_5mainOnly.setColor(sf::Color::Yellow);
        
        //floor3_6movingShadowOnly.setTexture(floorTexture);
        //floor3_6movingShadowOnly.setColor(sf::Color::Green);
        floor3_6movingShadowOnly.setScaleOverloaded(100,20);
        floor3_6movingShadowOnly.setXStart( 8850);
        floor3_6movingShadowOnly.setYStart( 200 );
        floor3_6movingShadowOnly.setXEnd(9300);
        floor3_6movingShadowOnly.setYEnd(200);
        floor3_6movingShadowOnly.setXVel(1);
        floor3_6movingShadowOnly.setYVel(0);
        
        
        floor3_7shadowOnly.setTexture(floorTexture);
        floor3_7shadowOnly.setScaleOverloaded(10,2);
        floor3_7shadowOnly.setPositionFull(9500,20);
        floor3_7shadowOnly.setColor(sf::Color::Green);
        
        floor3_8moving.setTexture(floorTexture);
        floor3_8moving.setScaleOverloaded(150,20);
        floor3_8moving.setXStart( 9820);
        floor3_8moving.setYStart( 20 );
        floor3_8moving.setXEnd(10000);
        floor3_8moving.setYEnd(20);
        floor3_8moving.setXVel(1);
        floor3_8moving.setYVel(0);
        floor3_8moving.setColor(sf::Color::Black);
        
        
        floor3_9moving.setTexture(floorTexture);
        floor3_9moving.setScaleOverloaded(150,20);
        floor3_9moving.setXStart( 9400);
        floor3_9moving.setYStart( 200 );
        floor3_9moving.setXEnd(9580);
        floor3_9moving.setYEnd(200);
        floor3_9moving.setXVel(1);
        floor3_9moving.setYVel(0);
        floor3_9moving.setColor(sf::Color::Black);
        
        floor3_10.setTexture(floorTexture);
        floor3_10.setScaleOverloaded(5,2);
        floor3_10.setPositionFull( 10150, 20);
        
        floor3_11shadowOnly.setTexture(floorTexture);
        floor3_11shadowOnly.setColor(sf::Color::Green);
        floor3_11shadowOnly.setScaleOverloaded(2,2);
        floor3_11shadowOnly.setPositionFull( 10310, -80);
        
        floor3_12mainOnly.setTexture(floorTexture);
        floor3_12mainOnly.setColor(sf::Color::Yellow);
        floor3_12mainOnly.setScaleOverloaded(1,2);
        floor3_12mainOnly.setPositionFull( 10374, -80);
        
        floor3_13shadowOnly.setTexture(floorTexture);
        floor3_13shadowOnly.setColor(sf::Color::Green);
        floor3_13shadowOnly.setScaleOverloaded(2,2);
        floor3_13shadowOnly.setPositionFull( 10440, -170);
        
        floor3_14mainOnly.setTexture(floorTexture);
        floor3_14mainOnly.setColor(sf::Color::Yellow);
        floor3_14mainOnly.setScaleOverloaded(1,2);
        floor3_14mainOnly.setPositionFull( 10504, -170);
        
        floor3_15shadowOnly.setTexture(floorTexture);
        floor3_15shadowOnly.setColor(sf::Color::Green);
        floor3_15shadowOnly.setScaleOverloaded(10,2);
        floor3_15shadowOnly.setPositionFull( 10540, -250);
        
        floor3_16mainOnly.setTexture(floorTexture);
        floor3_16mainOnly.setColor(sf::Color::Yellow);
        floor3_16mainOnly.setScaleOverloaded(5,2);
        floor3_16mainOnly.setPositionFull( 10800, 0);
        
        floor3_17moving.setScaleOverloaded(100,20);
        floor3_17moving.setXStart( 10900);
        floor3_17moving.setYStart( -250 );
        floor3_17moving.setXEnd(11200);
        floor3_17moving.setYEnd(-250);
        floor3_17moving.setXVel(1);
        floor3_17moving.setYVel(0);
        floor3_17moving.setColor(sf::Color::Black);
        
        floor3_18moving.setScaleOverloaded(100,20);
        floor3_18moving.setXStart( 11150);
        floor3_18moving.setYStart( 0 );
        floor3_18moving.setXEnd(11400);
        floor3_18moving.setYEnd(0);
        floor3_18moving.setXVel(2);
        floor3_18moving.setYVel(0);
        floor3_18moving.setColor(sf::Color::Black);
        
        floor3_19moving.setScaleOverloaded(100,20);
        floor3_19moving.setXStart(11650);
        floor3_19moving.setYStart( -250 );
        floor3_19moving.setXEnd(11350);
        floor3_19moving.setYEnd(-250);
        floor3_19moving.setXVel(1);
        floor3_19moving.setYVel(0);
        floor3_19moving.setColor(sf::Color::Black);
        
        floor3_20moving.setScaleOverloaded(100,20);
        floor3_20moving.setXStart( 12000);
        floor3_20moving.setYStart( 0 );
        floor3_20moving.setXEnd(11600);
        floor3_20moving.setYEnd(0);
        floor3_20moving.setXVel(2);
        floor3_20moving.setYVel(0);
        floor3_20moving.setColor(sf::Color::Black);
        
        floor3_21shadowOnly.setTexture(floorTexture);
        floor3_21shadowOnly.setColor(sf::Color::Green);
        floor3_21shadowOnly.setScaleOverloaded(15,2);
        floor3_21shadowOnly.setPositionFull( 11800, -250);
        
        floor3_22mainOnly.setTexture(floorTexture);
        floor3_22mainOnly.setColor(sf::Color::Yellow);
        floor3_22mainOnly.setScaleOverloaded(5,2);
        floor3_22mainOnly.setPositionFull( 12300, 0);
        
        
        
        
        
        
        
        
        
        
        
        
        castle1.setTexture(castleTexture);
        castle1.setScale(5,5);
        castle1.setPositionFull(2400, 1000);
        
        castle2.setTexture(castleTexture);
        castle2.setScale(5,5);
        castle2.setPosition( 6300,650);
        
        castle3.setTexture(castleTexture);
        castle3.setScale(5,5);
        castle3.setPosition( 12600,0);
        
        
        
        
        door1.setScale(20,68);
        door1.setPosition(856, 932);
        door2_1.setScale(20,68);
        door2_1.setPosition(6110, 735);
        door3_1.setScale(20,100);
        door3_1.setPosition(12506, -100);
        
        switch1.setScaleOverloaded(15,20);
        switch1.setPositionFull(1000,980);
        switch2_1.setScaleOverloaded(15,20);
        switch2_1.setPositionFull(6200,550);
        switch3_1.setScaleOverloaded(15,20);
        switch3_1.setPositionFull(12000,-270);
        
        
        deathFloor3_1.setTexture(whiteDotTexture);
        deathFloor3_1.setScale(2000,20);
        deathFloor3_1.setPosition(10900,-220);
        deathFloor3_1.setColor(sf::Color::Red);
        
        
        
        
        
        
    }
    
    
    Character mainCharacter;
    sf::Texture mainCharacterTexture;
    
    Character shadowCharacter;
    sf::Texture shadowCharacterTexture;
    
    
    
    void setMainCharacter()
    {
        mainCharacterTexture.loadFromFile( "sprites/badWall.png");
        mainCharacter.setTexture(mainCharacterTexture);
        mainCharacter.setScale(.3,5);
        //mainCharacter.setPosition(12350,-50); //set starting point
        //mainCharacter.setPosition(Checkpoint::checkpoint3_2_x, Checkpoint::checkpoint3_2_y);
        mainCharacter.setPosition(Checkpoint::checkpoint1_x, Checkpoint::checkpoint1_y);
        mainCharacter.setColor(sf::Color::Red);

    }
    
    void setShadowCharacter()
    {
        shadowCharacterTexture.loadFromFile("sprites/badWall.png");
        shadowCharacter.setTexture(shadowCharacterTexture);
        shadowCharacter.setScale(0.3,5);
        shadowCharacter.setColor(sf::Color::Black);
        shadowCharacter.setPosition(mainCharacter.getPosition().x, mainCharacter.getPosition().y );
    }
    
    void setLaser()
    {
        laserSprite.setPositionFull(mainCharacter,shadowCharacter);
        energyBar.setTexture(whiteDotTexture);
        spamPreventionBar.setTexture(whiteDotTexture);
        spamPreventionBar.setColor(sf::Color::Blue);
        if(! laserSprite.isInRefractoryPeriod() )
            {energyBar.setColor(sf::Color::Green);}
        if( laserSprite.isInRefractoryPeriod() )
            {energyBar.setColor(sf::Color::Red) ;}
        
        energyBar.setPosition( mainCharacter.getPosition().x -350 , mainCharacter.getPosition().y-350);
        energyBar.setScale( laserSprite.getTimer()*2 , 10);
        spamPreventionBar.setScale(laserSprite.getSpamCounter()*10 ,2);
        spamPreventionBar.setPosition( energyBar.getPosition().x, energyBar.getPosition().y+11);
    }
    
    bool isShadowOnScreen()
    {
        if( shadowCharacter.getPosition().x > (mainCharacter.getPosition().x +400) )
            { return false;}
        else if( shadowCharacter.getPosition().x < (mainCharacter.getPosition().x -400) )
            { return false;}
        else if( shadowCharacter.getPosition().y > (mainCharacter.getPosition().y +400) )
            { return false;}
        else if( shadowCharacter.getPosition().y < (mainCharacter.getPosition().y -400) )
            { return false;}
        else
            {return true;}
    }


    
    

}
#endif

