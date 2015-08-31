
#ifndef FUNCTIONALFLOOR_H
#define FUNCTIONALFLOOR_H

#include <iostream>


class FunctionalFloor: public Floor
{
    private:
        int m_length;
        int m_height;
        
        int m_xScale;
        int m_yScale;
        
        int m_xPosition;
        int m_yPosition;
        
        
        
        
        
        
        sf::Texture m_blackTexture;
    
    public:
        Ceiling m_ceiling;
        Wall m_leftWall;
        Wall m_rightWall;
        Floor m_overBox; //for moving platforms, a box above the platform to stop you from losing your jump when the platform goes down (it isnt really a floor)
       
        FunctionalFloor()
        {
            m_xScale=1;
            m_yScale=1;
            
            m_blackTexture.loadFromFile("sprites/blackDot.png");
            m_ceiling.setTexture(m_blackTexture);
            
            m_leftWall.setTexture(m_blackTexture);
            m_rightWall.setTexture(m_blackTexture);
            m_overBox.setTexture(m_blackTexture);
            
            
        }
        
        void setScaleOverloaded(int xScale, int yScale)
        {
            m_xScale = xScale;
            m_yScale= yScale;
            (*this).setScale(xScale,yScale);
        }
        
        
        void setPositionFull( int xPosition, int yPosition)
        {
            (*this).setPosition(xPosition, yPosition);
            
            m_xPosition= xPosition;
            m_yPosition= yPosition;
            
            m_length = ((*this).getLocalBounds().width)*m_xScale;
            m_height = ((*this).getLocalBounds().height) * m_yScale;
            
            
            m_overBox.setScale(m_length, 5);
            m_ceiling.setScale(m_length, 4);
            m_leftWall.setScale(4, m_height);
            m_rightWall.setScale(4,m_height);
            
            m_overBox.setPosition(m_xPosition, m_yPosition - 5);
            m_ceiling.setPosition(m_xPosition, m_yPosition+m_height);
            m_leftWall.setPosition( m_xPosition-2, m_yPosition+2);
            m_rightWall.setPosition( m_xPosition + m_length-1, m_yPosition+2);
            
        }
        
        Wall getLeftWall() {return m_leftWall;}
        Wall getRightWall() { return m_rightWall;}
        Ceiling getCeiling() { return m_ceiling;}
        Floor getOverBox() {return m_overBox;}
    
  

};





#endif
