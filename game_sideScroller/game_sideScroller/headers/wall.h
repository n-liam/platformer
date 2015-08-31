#ifndef WALL_H
#define WALL_H


class Wall: public sf::Sprite
{


    public:
        static int numberOfWallSprites;
        
        Wall()
        {
            
            numberOfWallSprites +=1 ;
            
        }       

};




#endif
