

#ifndef FLOOR_H
#define FLOOR_H



class Floor: public sf::Sprite
{
    
        
    
    public:
        static int numberOfFloorSprites;
        //static Floor floor_spriteList[10];
        Floor()
        {
            //floor_spriteList[ numberOfFloorSprites ] = (*this);
            numberOfFloorSprites +=1 ;
            
        }
        
        
};

#endif