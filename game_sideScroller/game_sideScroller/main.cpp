#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

#include "headers/floor.h"
#include "headers/wall.h"
#include "headers/ceiling.h"
#include "headers/functionalFloor.h"
#include "headers/functionalWall.h"
#include "headers/door.h"
#include "headers/switch.h"
#include "headers/movingPlatform.h"

#include "headers/character.h"
#include "headers/test.h"
#include "headers/text.h"
#include "headers/keystrokeBool.h"
#include "headers/checkpoints.h"
#include "headers/laser.h"



// make two types of wall, right wall and left wall to avoid not being able to fall off edges or tether off edges. apply the new wall types to FunctionalWall
// make killer red panels to stop from crossing routes. swtich on top side, and castle on bottom so you cant get from top to bottom.




int main()
{
   
    
    sf::RenderWindow window( sf::VideoMode(800,800), "main");
    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

      
    sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));   
    
    // begin SET stuff -----------------------------------------------
    
    Test::setFloor();
    Test::setMainCharacter();
    Test::setShadowCharacter();
    
    Text::setText();
    
    
    
    /*Floor floorList[10];
    floorList[0] = Test::floorSprite;
    floorList[1] =Test::floorSprite2;
    
    Wall wallList[10];
    wallList[0] = Test::wallSprite;*/ //FOR LOOPS NOT WORKING SEE BELOW IN MOVEMENT SECTION
    
    // end SET stuff ===========================
        
    
    
    
    
    
    while( window.isOpen())
    { 
    
    
    
        //reset keystrokes----------
        
        KeystrokeBool::resetAll();
        
            //reset gravity if shadow is off screen

        //=========
        
        sf::Event event;
        while (window.pollEvent(event) ) //EVENT LOOP begin*******jumps and such**************
        {
            
            
            if (event.type== sf::Event::Closed)
                {window.close();}
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    KeystrokeBool::invertSpaceValue();
                }
            
                if (event.key.code == sf::Keyboard::W)
                {
                    KeystrokeBool::setW(true);
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                    KeystrokeBool::setUp(true);
                }
                if ( (event.key.code ==sf::Keyboard::Down) && KeystrokeBool::down==false )
                //check for down press, shadow on screen, and downpresssoff
                {
                    KeystrokeBool::down = true;
                }
                else if ( (event.key.code ==sf::Keyboard::Down)&&KeystrokeBool::down==true )
                //turn down keystroke off if already on
                {
                    KeystrokeBool::down = false;
                }
                
                
            }
            
                
            
        } // EVENT LOOP CLOSE *********************************************************
        
        
        
        window.clear(sf::Color::White);
        
        
        
        //begin CHECK FOR KEY ENTRY--type 2--------------------
        
       
        
            //direction facing
		int levelValue = 0;
		int checkpointValue = 0;
		bool devCheat = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) )
		{
			devCheat = true;
			std::cout << "What level?\t";
			std::cin >> levelValue;
			
			
			std::cout <<"\n What Checkpoint\t";
			std::cin >> checkpointValue;
		}
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
        {
            KeystrokeBool::setFacingRight(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
        {
            KeystrokeBool::setFacingRight(false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Test::isShadowOnScreen() )
        {
            KeystrokeBool::s = true;
            
            
            if(Test::laserSprite.isOn() )
            {
                Test::mainCharacter.resetUpDownVelocity();
                Test::mainCharacter.followTether(Test::shadowCharacter);
                Test::mainCharacter.setFollowingTether(true);
            }
            else
                {Test::mainCharacter.setFollowingTether(false);}
        }
        else {Test::mainCharacter.setFollowingTether(false); }
        
        //end CHECK FOR KEY ENTRY===================
        
        
        
        // begin USE KEYSTROKES---------------------
        
		if (devCheat)
		{
			if( levelValue ==1 && checkpointValue ==1)
				{Test::mainCharacter.setPosition( Checkpoint::checkpoint1_x, Checkpoint::checkpoint1_y);}
			else if (levelValue ==2 && checkpointValue ==1)
				{Test::mainCharacter.setPosition( Checkpoint::checkpoint2_1_x, Checkpoint::checkpoint2_1_y); }	
			else if (levelValue ==2 && checkpointValue ==2)
				{Test::mainCharacter.setPosition( Checkpoint::checkpoint2_2_x, Checkpoint::checkpoint2_2_y); }
			else if (levelValue ==3 && checkpointValue ==1)
				{Test::mainCharacter.setPosition( Checkpoint::checkpoint3_1_x, Checkpoint::checkpoint3_1_y); }
			else if (levelValue ==3 && checkpointValue ==2)
				{Test::mainCharacter.setPosition( Checkpoint::checkpoint3_2_x, Checkpoint::checkpoint3_2_y); }
			else
				{std::cout <<"ERROR";}
			devCheat = false;
		}
		
        if ( KeystrokeBool::w && Test::mainCharacter.isRestrictedDown()  )
        {
            
            Test::mainCharacter.setJump(true);
        }
        if (KeystrokeBool::up && Test::shadowCharacter.isRestrictedDown() )
        {
            Test::shadowCharacter.setJump(true);
        }
        if (KeystrokeBool::s && Test::isShadowOnScreen() )
        {
            Test::laserSprite.turnOn();
        }
        else
        {
            KeystrokeBool::s = false;
            Test::laserSprite.turnOff();
            Test::mainCharacter.setFollowingTether(false);
            Test::mainCharacter.resetRestrictions();
            Test::shadowCharacter.resetRestrictions();
        }
        
        //end USE KEYSTROKES ========================
        
        //begin Check SWITCHES AND DOORS ------------------------
        
        if (Test::switch1.isSwitchHit() ){ Test::door1.open(); }
        else if (!Test::switch1.isSwitchHit()){Test::door1.close();}
        
        if (Test::switch2_1.isSwitchHit() ){ Test::door2_1.open(); }
        else if (!Test::switch2_1.isSwitchHit()){Test::door2_1.close();}
        
        if (Test::switch3_1.isSwitchHit() ){ Test::door3_1.open(); }
        else if (!Test::switch3_1.isSwitchHit()){Test::door3_1.close();}
        
        //end SWITCHES AND DOORS
        
        // begin DRAW stuff ------- also set view----------draw switches and door sfirst----------
        
        if (Test::door1.isClosed() )
            {window.draw(Test::door1);}
        window.draw(Test::switch1);
        
        
        if (Test::door2_1.isClosed() )
            {window.draw(Test::door2_1);}
        window.draw(Test::switch2_1);
        
        if (Test::door3_1.isClosed() )
            {window.draw(Test::door3_1);}
        window.draw(Test::switch3_1);
        
        window.draw(Text::titleText);
        window.draw(Text::tutText0);
        window.draw(Text::tutText1);
        window.draw(Text::tutText2);
        window.draw(Text::tutText3);
        window.draw(Text::tutText4);
        window.draw(Text::tutText5);
        window.draw(Text::tutText6);
        window.draw(Text::tutText7);
        window.draw(Text::tutText8);
        window.draw(Text::tutText9);
        window.draw(Text::text2_1);
        window.draw(Text::text3_1);
       
       
        window.draw(Test::mainCharacter);
        
        window.draw(Test::goodFloorSprite);
        window.draw(Test::goodFloorSprite2);
        window.draw(Test::floor3);
        window.draw(Test::floor4ShadowOnly);
        window.draw(Test::floor5);
        window.draw(Test::floor2_1);
        window.draw(Test::floor2_2shadowOnly);
        window.draw(Test::floor2_3);
        window.draw(Test::floor2_4mainOnly);
        window.draw(Test::floor2_5);
        window.draw(Test::floor2_6);
        window.draw(Test::floor2_7shadowOnly);
        window.draw(Test::floor2_8mainOnly);
        window.draw(Test::floor2_9shadowOnly);
        window.draw(Test::floor2_10mainOnly);
        window.draw(Test::floor2_11shadowOnly);
        window.draw(Test::floor2_12mainOnly);
        window.draw(Test::floor2_13shadowOnly);
        window.draw(Test::floor2_14shadowOnly);
        window.draw(Test::floor3_1);
        window.draw(Test::floor3_2moving);
        window.draw(Test::floor3_3moving);
        window.draw(Test::floor3_4movingShadowOnly);
        window.draw(Test::floor3_5mainOnly);
        window.draw(Test::floor3_6movingShadowOnly);
        window.draw(Test::floor3_7shadowOnly);
        window.draw(Test::floor3_8moving);
        window.draw(Test::floor3_9moving);
        window.draw(Test::floor3_10);
        window.draw(Test::floor3_11shadowOnly);
        window.draw(Test::floor3_12mainOnly);
        window.draw(Test::floor3_13shadowOnly);
        window.draw(Test::floor3_14mainOnly);
        window.draw(Test::floor3_15shadowOnly);
        window.draw(Test::floor3_16mainOnly);
        window.draw(Test::floor3_17moving);
        window.draw(Test::floor3_18moving);
        window.draw(Test::floor3_19moving);
        window.draw(Test::floor3_20moving);
        window.draw(Test::floor3_21shadowOnly);
        window.draw(Test::floor3_22mainOnly);
        
        //window.draw(Test::resetFloor1);
        //window.draw(Test::resetFloor2_1);
        //window.draw(Test::resetFloor2_2);
        //window.draw(Test::resetFloor3_1);
        //window.draw(Test::resetFloor3_2);
        
        
        
        window.draw(Test::goodWallSprite);
        window.draw(Test::wall1);
        window.draw(Test::wall2_1);
        window.draw(Test::wall2_2);
        window.draw(Test::wall3_1);
        window.draw(Test::wall3_2);
        
        window.draw(Test::castle1);
        window.draw(Test::castle2);
        window.draw(Test::castle3);
        
        window.draw(Test::deathFloor3_1);
        
       
        
       
        
        if(Test::laserSprite.isOn() )
        {
            
            window.draw(Test::laserSprite);
            
            if(Test::laserSprite.getTimer() <= 0)
                {KeystrokeBool::s = false;} //turn off laser
            Test::laserSprite.decreaseTimer(); //decrease laser energy
        }
        else { Test::laserSprite.advanceTimer();} //get energy back while not on
        
        if(KeystrokeBool::space)
        {
            if (!KeystrokeBool::shadowDrawnFrameCounter)
            {
                Test::setShadowCharacter();
                
                if (KeystrokeBool::isFacingRight() )
                    {Test::shadowCharacter.move(50,0);}
                else
                    {Test::shadowCharacter.move(-50,0);}
                KeystrokeBool::shadowDrawnFrameCounter+=1;
                
            }
  
            window.draw(Test::shadowCharacter);
            
            
            //erase shadow if it falls off the screen
            if (!Test::isShadowOnScreen() )
            {
                KeystrokeBool::space = false;
                Test::mainCharacter.setFollowingTether(false);
            }
  
        }
        else 
        {
            Test::shadowCharacter.setPosition(-1000,-1000); 
            Test::laserSprite.turnOff();
            Test::shadowCharacter.resetUpDownVelocity();
        }
            
        
        window.draw(Test::energyBar);
        window.draw(Test::spamPreventionBar);
        
        
        view.setCenter(Test::mainCharacter.getPosition());
        window.setView(view);
        
        // end DRAW stuff =================================
        
        // begin MOVEMENT -----------------------------------
        
            //start with platforms
        Test::floor3_2moving.movement(); 
        Test::floor3_3moving.movement();
        Test::floor3_4movingShadowOnly.movement();
        Test::floor3_6movingShadowOnly.movement();
        Test::floor3_8moving.movement();
        Test::floor3_9moving.movement();
        Test::floor3_17moving.movement();
        Test::floor3_18moving.movement();
        Test::floor3_19moving.movement();
        Test::floor3_20moving.movement();
       
        Test::setLaser();
        Test::mainCharacter.resetRestrictions();
        Test::shadowCharacter.resetRestrictions();
        
      
        
        
        Test::mainCharacter.getRestrictionsOverloaded( Test::goodFloorSprite);
        Test::mainCharacter.getRestrictionsOverloaded(Test::goodFloorSprite2);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor5);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor2_1);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor2_3);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor2_4mainOnly);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor2_5);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor2_6);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor2_8mainOnly);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor2_10mainOnly);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor2_12mainOnly);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_1);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_2moving);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_3moving);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_5mainOnly);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_8moving);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_9moving);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_10);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_12mainOnly);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_14mainOnly);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_16mainOnly);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_17moving);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_18moving);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_19moving);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_20moving);
        Test::mainCharacter.getRestrictionsOverloaded(Test::floor3_22mainOnly);
        
        Test::mainCharacter.getRestrictionsOverloaded(Test::goodWallSprite);
        Test::mainCharacter.getRestrictionsOverloaded(Test::wall1);
        Test::mainCharacter.getRestrictionsOverloaded(Test::wall2_1);
        Test::mainCharacter.getRestrictionsOverloaded(Test::wall2_2);
        Test::mainCharacter.getRestrictionsOverloaded(Test::wall3_1);
        Test::mainCharacter.getRestrictionsOverloaded(Test::wall3_2);
        Test::mainCharacter.getRestrictionsOverloaded(Test::switch1);
        Test::mainCharacter.getRestrictionsOverloaded(Test::switch2_1);
        Test::mainCharacter.getRestrictionsOverloaded(Test::switch3_1);
        
        
        if(Test::mainCharacter.didCollideWith( Test::resetFloor1) )
            {Test::mainCharacter.setPosition(Checkpoint::checkpoint1_x, Checkpoint::checkpoint1_y);}//reset when fall 
        if(Test::mainCharacter.didCollideWith( Test::resetFloor2_1) )
            {Test::mainCharacter.setPosition(Checkpoint::checkpoint2_1_x, Checkpoint::checkpoint2_1_y);}
        if (Test::mainCharacter.didCollideWith( Test::resetFloor2_2) )
            {Test::mainCharacter.setPosition(Checkpoint::checkpoint2_2_x, Checkpoint::checkpoint2_2_y);}
        if (Test::mainCharacter.didCollideWith( Test::resetFloor3_1) )
            {Test::mainCharacter.setPosition(Checkpoint::checkpoint3_1_x, Checkpoint::checkpoint3_1_y);}
        if (Test::mainCharacter.didCollideWith( Test::resetFloor3_2) )
            {Test::mainCharacter.setPosition(Checkpoint::checkpoint3_2_x, Checkpoint::checkpoint3_2_y);}
            
            //reset when hit deathfloor
            
        if(Test::mainCharacter.didCollideWith( Test::deathFloor3_1) )
            {Test::mainCharacter.setPosition(Checkpoint::checkpoint3_2_x, Checkpoint::checkpoint3_2_y);}
            
            
            
            //move to next level
        if(Test::mainCharacter.didCollideWith(Test::castle1) )
            {Test::mainCharacter.setPosition (Checkpoint::checkpoint2_1_x, Checkpoint::checkpoint2_1_y);} //move to next level
        if(Test::mainCharacter.didCollideWith(Test::castle2) )
            {Test::mainCharacter.setPosition (Checkpoint::checkpoint3_1_x, Checkpoint::checkpoint3_1_y);}
        if(Test::mainCharacter.didCollideWith(Test::castle3) )
            {Test::mainCharacter.setPosition (Checkpoint::checkpoint3_1_x, Checkpoint::checkpoint3_1_y);}
        
        
        Test::shadowCharacter.getRestrictionsOverloaded(Test::goodFloorSprite);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::goodFloorSprite2);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor4ShadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor5);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_1);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_2shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_3);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_5);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_6);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_7shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_9shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_11shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_13shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor2_14shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_1);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_2moving);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_3moving);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_4movingShadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_6movingShadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_7shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_8moving);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_9moving);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_10);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_11shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_13shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_15shadowOnly);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_17moving);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_18moving);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_19moving);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_20moving);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::floor3_21shadowOnly);
        
        
        Test::shadowCharacter.getRestrictionsOverloaded(Test::goodWallSprite);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::wall1);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::wall2_1);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::wall2_2);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::wall3_1);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::wall3_2);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::switch1);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::switch2_1);
        Test::shadowCharacter.getRestrictionsOverloaded(Test::switch3_1);
        
        
        //door and switch collision
        if(Test::door1.isClosed() )
        {
            Test::shadowCharacter.getRestrictions(Test::door1);
            Test::mainCharacter.getRestrictions(Test::door1);
        }
        if( Test::shadowCharacter.didCollideWith( Test::switch1.getFloor()) || Test::mainCharacter.didCollideWith(Test::switch1.getFloor()) ) 
            {Test::switch1.invertSwitch();}
            
        
         if(Test::door2_1.isClosed() )
        {
            Test::shadowCharacter.getRestrictions(Test::door2_1);
            Test::mainCharacter.getRestrictions(Test::door2_1);
        }
        if( Test::shadowCharacter.didCollideWith( Test::switch2_1.getFloor()) || Test::mainCharacter.didCollideWith(Test::switch2_1.getFloor()) ) 
            {Test::switch2_1.invertSwitch();}
            
        if(Test::door3_1.isClosed() )
        {
            Test::shadowCharacter.getRestrictions(Test::door3_1);
            Test::mainCharacter.getRestrictions(Test::door3_1);
        }
        if( Test::shadowCharacter.didCollideWith( Test::switch3_1.getFloor()) || Test::mainCharacter.didCollideWith(Test::switch3_1.getFloor()) ) 
            {Test::switch3_1.invertSwitch();}
       
        
        //moving platform movement/collision
        
        Test::mainCharacter.followPlatform( Test::floor3_2moving);
        Test::shadowCharacter.followPlatform(Test::floor3_2moving);
        /*if(Test::mainCharacter.didCollideWith( Test::floor3_2moving)  )
            {Test::mainCharacter.move( Test::floor3_2moving.getXVel(), Test::floor3_2moving.getYVel() );}
        if(Test::shadowCharacter.didCollideWith( Test::floor3_2moving) )
            {Test::shadowCharacter.move( Test::floor3_2moving.getXVel(), Test::floor3_2moving.getYVel() );} */
        
        if(Test::mainCharacter.didCollideWith( Test::floor3_3moving) )
            {Test::mainCharacter.move( Test::floor3_3moving.getXVel(), Test::floor3_3moving.getYVel() );}
        if(Test::shadowCharacter.didCollideWith( Test::floor3_3moving) )
            {Test::shadowCharacter.move( Test::floor3_3moving.getXVel(), Test::floor3_3moving.getYVel() );}
            
       
        if(Test::shadowCharacter.didCollideWith( Test::floor3_4movingShadowOnly) )
            {Test::shadowCharacter.move( Test::floor3_4movingShadowOnly.getXVel(), Test::floor3_4movingShadowOnly.getYVel() );}
            
        if(Test::shadowCharacter.didCollideWith( Test::floor3_6movingShadowOnly) )
            {Test::shadowCharacter.move( Test::floor3_6movingShadowOnly.getXVel(), Test::floor3_6movingShadowOnly.getYVel() );}
            
            if(Test::mainCharacter.didCollideWith( Test::floor3_8moving) )
            {Test::mainCharacter.move( Test::floor3_8moving.getXVel(), Test::floor3_8moving.getYVel() );}
        if(Test::shadowCharacter.didCollideWith( Test::floor3_8moving) )
            {Test::shadowCharacter.move( Test::floor3_8moving.getXVel(), Test::floor3_8moving.getYVel() );}
            
        if(Test::mainCharacter.didCollideWith( Test::floor3_9moving) )
            {Test::mainCharacter.move( Test::floor3_9moving.getXVel(), Test::floor3_9moving.getYVel() );}
        if(Test::shadowCharacter.didCollideWith( Test::floor3_9moving) )
            {Test::shadowCharacter.move( Test::floor3_9moving.getXVel(), Test::floor3_9moving.getYVel() );}
            
            if(Test::mainCharacter.didCollideWith( Test::floor3_17moving) )
            {Test::mainCharacter.move( Test::floor3_17moving.getXVel(), Test::floor3_17moving.getYVel() );}
        if(Test::shadowCharacter.didCollideWith( Test::floor3_17moving) )
            {Test::shadowCharacter.move( Test::floor3_17moving.getXVel(), Test::floor3_17moving.getYVel() );}
            
            if(Test::mainCharacter.didCollideWith( Test::floor3_18moving) )
            {Test::mainCharacter.move( Test::floor3_18moving.getXVel(), Test::floor3_18moving.getYVel() );}
        if(Test::shadowCharacter.didCollideWith( Test::floor3_18moving) )
            {Test::shadowCharacter.move( Test::floor3_18moving.getXVel(), Test::floor3_18moving.getYVel() );}
            
            if(Test::mainCharacter.didCollideWith( Test::floor3_19moving) )
            {Test::mainCharacter.move( Test::floor3_19moving.getXVel(), Test::floor3_19moving.getYVel() );}
        if(Test::shadowCharacter.didCollideWith( Test::floor3_19moving) )
            {Test::shadowCharacter.move( Test::floor3_19moving.getXVel(), Test::floor3_19moving.getYVel() );}
            
            if(Test::mainCharacter.didCollideWith( Test::floor3_20moving) )
            {Test::mainCharacter.move( Test::floor3_20moving.getXVel(), Test::floor3_20moving.getYVel() );}
        if(Test::shadowCharacter.didCollideWith( Test::floor3_20moving) )
            {Test::shadowCharacter.move( Test::floor3_20moving.getXVel(), Test::floor3_20moving.getYVel() );}
        
        
       //tether mechanics 
        if( !Test::mainCharacter.isFollowingTether() )
        {
            Test::mainCharacter.gravity(); //also includes jumping
            
        }    
        Test::shadowCharacter.gravity();
        
        
        Test::mainCharacter.movementWASD();
        Test::shadowCharacter.movement();
        
       
        
       
 
        // end MOVMENT ===================================
        
        
        
        
        
        window.display();
        
    }
    
   
    
    return 0;

}            
        
