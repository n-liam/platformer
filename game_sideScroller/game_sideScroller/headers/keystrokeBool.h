#ifndef KEYSTROKEBOOL_H
#define KEYSTROKEBOOL_H


namespace KeystrokeBool
{
    bool down; //for the laser
    bool space; // for shadow creation
    bool up;  //main jump
    bool w;     //shadow jump
    bool s; //main character follow tether
    bool facingRight = true;
    bool shadowDrawnFrameCounter =0;
    
    
    int frameBufferCounter= 0;
    
    bool frameBuffer()
    {
        
        if (frameBufferCounter =500)
        {
            frameBufferCounter =0;
            
        }
        frameBufferCounter+=1;
        if(frameBufferCounter ==1)
            {return true; }
        else
            {return false;}
            
       
        
    }
    
    
    
   

    void setDown( bool yesNo){  down =yesNo;}
    void setUp( bool yesNo){up = yesNo;}
    void setW( bool yesNo){ w = yesNo;}
    void setFacingRight(bool yesNo) {facingRight =yesNo;}
   
    
    void invertSpaceValue() 
    {
        
        shadowDrawnFrameCounter=0;
        space = !space;
    }
    
    
    
    bool isFacingRight()
    {
        return facingRight;
    }


    void resetAll()
    {
        s=false;
        up = false;
        w= false;
    }

}



#endif
