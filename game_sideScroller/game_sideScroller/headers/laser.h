#ifndef LASER_H
#define LASER_H

class Laser: public sf::Sprite
{
    private:
        sf::Texture m_texture;
        bool m_isOn;
        float m_timer;
       
        bool m_refractoryPeriod;
        bool m_spamPreventionOn;
        int m_spamPreventionCounter;
        
    public:
        Laser()
        {
            m_timer = 0;
            m_texture.loadFromFile( "sprites/whiteDot.png");
            (*this).setColor(sf::Color::Cyan);
            
            (*this).setTexture(m_texture);
            m_isOn = false;
            
            m_refractoryPeriod = false;
            m_spamPreventionOn = false;
            m_spamPreventionCounter = 0;
        }
        
        void setPositionFull( Character mainCharacter, Character shadowCharacter )
        {
            int mainX = mainCharacter.getXCenter();
            int mainY = mainCharacter.getYCenter(); 
            int shadowX = shadowCharacter.getXCenter(); 
            int shadowY = shadowCharacter.getYCenter();
            
            int xDist = shadowX-mainX;
            int yDist = shadowY-mainY;
            
            float laserDist = sqrt(xDist*xDist + yDist*yDist);
           
            float laserAngle = atan2( yDist, xDist);//in rad
            laserAngle =  laserAngle*180/3.14; //convert to deg;
            
            (*this).setScale( laserDist, 10);
            (*this).setRotation( laserAngle);
            (*this).setPosition( mainX, mainY+20);
            
        }
        
        void turnOn()
        { 
            if( !m_refractoryPeriod && !m_spamPreventionOn ) //cannot turn on in refractory period
                {m_isOn = true;m_spamPreventionCounter = 0;}
            
        }
        
        
        void turnOff()
        { 
            m_isOn = false;
            
            
            
        }
        bool isOn(){return m_isOn;}
        
        void advanceTimer() //exit refractory period at more than 40 pts
        { 
            m_spamPreventionOn = true;
            m_timer+=1;
            m_spamPreventionCounter+=1;
             //set spam cool down
            if (m_spamPreventionCounter>=20 ) //you mess up spambar length if you change cool down
                {m_spamPreventionOn = false; m_spamPreventionCounter=20;}
            if (m_timer >40){ m_refractoryPeriod=false;}
            if (m_timer>100){m_timer =100;}
        }
        void decreaseTimer() //enter refractory period if timer hits zero
        { 
            m_timer -=1;
            if (m_timer <=0){m_isOn = false; m_refractoryPeriod = true;}
        }
        void resetTimer(){m_timer =0;}
        float getTimer(){return m_timer;}
        
        void turnOnRefractoryPeriod(){m_refractoryPeriod = true;}
        void turfOffRefractoryPeriod(){m_refractoryPeriod = false;}
        bool isInRefractoryPeriod(){return m_refractoryPeriod;}
        
        int getSpamCounter(){return m_spamPreventionCounter;}

};



#endif
