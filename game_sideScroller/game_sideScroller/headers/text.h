#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

namespace Text
{
    sf::Font font;
    sf::Text tutText0;
    sf::Text tutText1;
    sf::Text tutText2;
    sf::Text tutText3;
    sf::Text tutText4; 
    sf::Text tutText5; 
    sf::Text tutText6; 
    sf::Text tutText7;
    sf::Text tutText8;
    sf::Text tutText9;
    sf::Text titleText;
    
    sf::Text text2_1;
    sf::Text text3_1;
    
    void setText()
    {
        font.loadFromFile("fonts/OpenSans-Regular.ttf");
        tutText0.setFont(font);
        tutText1.setFont(font);
        tutText2.setFont(font);
        tutText3.setFont(font);
        tutText4.setFont(font);
        
        titleText.setFont(font);
        titleText.setString("Achim's Quest II:\nThe Questening...\nOF DOOM!");
        titleText.setColor(sf::Color::Red);
        titleText.scale(1,1);
        titleText.setPosition(-300,650);
        
        tutText0.setString("Level One");
        tutText0.setCharacterSize(24);
        tutText0.setColor(sf::Color::Black);
        tutText0.setPosition(50,650);
        
        tutText1.setString("<-- A    D -->");
        tutText1.setCharacterSize(24);
        tutText1.setColor(sf::Color::Black);
        tutText1.setPosition(50, 700);
        
        tutText2.setString("W");
        tutText2.setCharacterSize(24);
        tutText2.setColor(sf::Color::Black);
        tutText2.setPosition(500, 700);
        
        tutText3.setString("-->");
        tutText3.setCharacterSize(24);
        tutText3.setColor(sf::Color::Black);
        tutText3.setPosition(490, 690);
        tutText3.setRotation(270);
        
        tutText4.setFont(font);
        tutText4.setCharacterSize(24);
        tutText4.setString("Space");
        tutText4.setColor(sf::Color::Black);
        tutText4.setPosition(740, 700);
        
        tutText5.setFont(font);
        tutText5.setString("<-- Left    Right --> \n (hint: that's a switch)");
        tutText5.setCharacterSize(24);
        tutText5.setColor(sf::Color::Black);
        tutText5.setPosition(920, 700);
        
        tutText6.setFont(font);
        tutText6.setString("Up");
        tutText6.setCharacterSize(24);
        tutText6.setColor(sf::Color::Black);
        tutText6.setPosition(995, 660);
        
        tutText7.setFont(font);
        tutText7.setString("-->");
        tutText7.setCharacterSize(24);
        tutText7.setColor(sf::Color::Black);
        tutText7.setPosition(985, 650);
        tutText7.setRotation(270);
        
        tutText8.setFont(font);
        tutText8.setString("You can't stand on this platform, but...");
        tutText8.setCharacterSize(12);
        tutText8.setColor(sf::Color::Black);
        tutText8.setPosition(1650, 1150);
        
        tutText9.setFont(font);
        tutText9.setString("S (Hold)");
        tutText9.setCharacterSize(24);
        tutText9.setColor(sf::Color::Black);
        tutText9.setPosition(1900, 1000);
        
        
        
        text2_1.setFont(font);
        text2_1.setString("Level Two");
        text2_1.setCharacterSize(24);
        text2_1.setColor(sf::Color::Black);
        text2_1.setPosition(3500, 200);
        
        text3_1.setFont(font);
        text3_1.setString("Level Three");
        text3_1.setCharacterSize(24);
        text3_1.setColor(sf::Color::Black);
        text3_1.setPosition(8000, -100);
    
    }


}


#endif
