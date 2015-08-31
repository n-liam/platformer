#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H

class MovingPlatform: public FunctionalFloor
{
    // ONE OF THE VELOCITIES SHOULD PROBABLY BE ZERO
    //MAKE SURE YOU SET THINGS IN THE RIGHT ORDER
    // dont have up down velocities higher than 2.
    // there is an issue with sliding when you use pause frames on left right platforms
    private:
        int m_xStart;
        int m_yStart;
        int m_xEnd;
        int m_yEnd;
        int m_yVel;
        int m_xVel;
        
        
        //bool m_isPausing;
        //int m_pauseCounter;
        //int m_numberPauseFrames;
        bool m_isSet;
        bool m_isMovingTowardEnd;
        
        
        
        sf::Texture m_texture;
    public:
        
        MovingPlatform()
        {
            m_texture.loadFromFile("sprites/greenDot.png");
            (*this).setTexture(m_texture);
            
           
            
            //(*this).setColor(sf::Color::Black);
            m_isSet= false;
            m_isMovingTowardEnd = true;
            m_xVel = 0;
            m_yVel = 0;
            //m_isPausing = false;
            //m_pauseCounter = 0;
            //m_numberPauseFrames =1;
           
        }
        
        //bool isPaused(){return m_isPausing;}
        
        
        
        void setXVel(int xVel)
        { 
            m_xVel = abs( xVel ); 
            if(m_xStart >= m_xEnd){ m_xVel = -m_xVel;}
        }
        void setYVel(int yVel)
        { 
            m_yVel = abs( yVel ); 
            if(m_yStart >= m_yEnd){ m_yVel = -m_yVel;}
        }
        void setXStart(int xStart){m_xStart = xStart;}
        void setYStart(int yStart){m_yStart = yStart;}
        void setXEnd(int xEnd){m_xEnd= xEnd;}
        void setYEnd(int yEnd){m_yEnd = yEnd;}
        
        int getXVel()
        {
            if(m_isMovingTowardEnd) {return m_xVel;}
            else                    {return -m_xVel;}
        }
        int getYVel()
        {
            if(m_isMovingTowardEnd) {return m_yVel;}
            else                    {return -m_yVel;}
        }
        int getXStart(){return m_xStart;}
        int getXEnd(){return m_xEnd;}
        int getYStart(){return m_yStart;}
        int getYEnd(){return m_yEnd;}
        
        bool needsToSwitchDirection()
        {
            if ( m_xVel >0 && ((*this).getPosition().x > m_xEnd || (*this).getPosition().x<m_xStart)) 
                {return true;}
            if ( m_xVel <0 && ((*this).getPosition().x < m_xEnd || (*this).getPosition().x>m_xStart)) 
                {return true;}
            if ( m_yVel >0 && ((*this).getPosition().y > m_yEnd || (*this).getPosition().y<m_yStart)) 
                {return true;}
            if ( m_yVel <0 && ((*this).getPosition().y < m_yEnd || (*this).getPosition().y>m_yStart)) 
                {return true;}
            else {return false;}
            
        }
        
        
        void movement()
        {
            if (!m_isSet)
            {
                (*this).setPositionFull( m_xStart, m_yStart);
                m_isSet = true;
            }
            else
            {
                if( (*this).needsToSwitchDirection() ==true )
                {
                    
                    m_isMovingTowardEnd = !m_isMovingTowardEnd;
                    //m_isPausing = true;
                }
                
                /*if (m_isPausing)
                {
                    m_pauseCounter+=1;
                    if (m_pauseCounter == m_numberPauseFrames)
                    {
                        m_isMovingTowardEnd = !m_isMovingTowardEnd;
                        m_pauseCounter = 0;
                        m_isPausing = false;
                    }
                }
   
                if (!m_isPausing)
                { */
                if (m_isMovingTowardEnd)
                {
                    (*this).move(m_xVel,0);
                    m_ceiling.move(m_xVel,0);
                    m_leftWall.move(m_xVel,0);
                    m_rightWall.move(m_xVel,0);
                  
                    (*this).move(0, m_yVel);
                    m_leftWall.move(0,m_yVel);
                    m_rightWall.move(0,m_yVel);
                    m_ceiling.move(0,m_yVel);
                    
                    m_overBox.move(m_xVel, m_yVel);
                }
                else
                {
                    (*this).move(-m_xVel,0);
                    m_leftWall.move(-m_xVel,0);
                    m_rightWall.move(-m_xVel,0);
                    m_ceiling.move(-m_xVel,0);
                    
                    (*this).move(0, -m_yVel);
                    m_leftWall.move(0,-m_yVel);
                    m_rightWall.move(0,-m_yVel);
                    m_ceiling.move(0,-m_yVel);
                    
                    m_overBox.move(-m_xVel, -m_yVel); 
                }
                //}
                
                
            }
            
        }
       

};



#endif
