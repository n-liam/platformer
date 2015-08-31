#ifndef FUNCTIONALWALL_H
#define FUNCTIONALWALL_H

//NEED TO BE AT LEAST 8 PIXELS THICK
class FunctionalWall: public Wall
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
        Floor m_floor;
       
        FunctionalWall()
        {
            m_xScale=1;
            m_yScale=1;
            
            m_blackTexture.loadFromFile("sprites/blackDot.png");
            m_ceiling.setTexture(m_blackTexture);
            m_floor.setTexture(m_blackTexture);
            
            
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
            

            
            m_ceiling.setScale(m_length-8, 2);
            m_floor.setScale(m_length-8,2);
            
            
            
            m_ceiling.setPosition(m_xPosition+4, m_yPosition+m_height+1);
            m_floor.setPosition(m_xPosition+4,m_yPosition-2);
            
        }
        
        Floor getFloor(){return m_floor;}
        Ceiling getCeiling() { return m_ceiling;}
        
        Floor& getFloorReference()
        {
            return m_floor ;
        }
        
        int getFloorWidth()
        {
            return m_floor.getGlobalBounds().width;
        }
        
        int getLength(){ return m_length;}
        int getHeight(){ return m_height;}
        
        void moveFloor(int x, int y)
        {
            (  m_floor ).move(x,y);
        }
    

};






#endif
