#ifndef SWITCH_H
#define SWITCH_H

class Switch: public FunctionalWall
{
    
    private:
        bool m_isSwitchHit;
        sf::Texture m_switchTexture;
        int m_frameCounter;
    public:
        Switch()
        {
            m_isSwitchHit=false;
            m_switchTexture.loadFromFile("sprites/whiteDot.png");
            (*this).setTexture(m_switchTexture);
            (*this).setColor(sf::Color::Yellow);
            m_frameCounter =0;
        }
        
        void switchTrue()
        { 
            m_isSwitchHit=true;
            (*this).move(0,15); 
            (m_floor).move(0,15);
            (m_ceiling).move(0,15);
               
        }
        void switchFalse()
        {
            m_isSwitchHit=false;
            (*this).move(0,-15); 
            (m_floor).move(0,-15);
            (m_ceiling).move(0,-15);
        }
            
        void invertSwitch()
        {
            m_frameCounter+=1;
            if (m_frameCounter>20)
            {
                if (m_isSwitchHit ==false)
                    { (*this).switchTrue(); }
                else if (m_isSwitchHit ==true)
                    { (*this).switchFalse();}
                m_frameCounter = -50;
            }
            
        }
        
        bool isSwitchHit(){ return m_isSwitchHit;}
        
        
        

};



#endif
