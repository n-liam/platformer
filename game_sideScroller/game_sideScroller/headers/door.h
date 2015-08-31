#ifndef DOOR_H
#define DOOR_H

class Door: public Wall
{

    private:
        
        bool m_isOpen;
        
        sf::Texture m_doorTexture;
        
        
    public:
        
        Door()
        {
            m_isOpen = false;
            m_doorTexture.loadFromFile("sprites/blackDot.png");
            (*this).setTexture(m_doorTexture);
        }
        
        bool isOpen(){ return m_isOpen;}
        bool isClosed(){ return !m_isOpen;}
        
        void open(){ m_isOpen = true;}
        void close(){m_isOpen = false;}

};



#endif
