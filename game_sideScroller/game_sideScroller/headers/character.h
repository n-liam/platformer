#ifndef CHARACTER_H
#define CHARACTER_H

class Character: public sf::Sprite
{
    
    private:
        bool m_restricted_left;
        bool m_restricted_right;
        bool m_restricted_up;
        bool m_restricted_down;
        bool m_hitSomething;
        
        //bool m_wasRestricted_down;
        //int  m_unrestrictedFrameCounter;
        
        bool m_isJumping;
        bool m_isFollowingTether;
        
        int m_gravityTimer;
        
        int m_upDownVelocity;
        int m_leftRightVelocity;
        int m_jumpCounter;
        
        
        
    
    public:
        Character()
        {
            m_restricted_left = false;
            m_restricted_right = false;
            m_restricted_up = false;
            m_restricted_down = false;
            m_hitSomething = false;
            
            m_isFollowingTether = false;
            m_isJumping = false;
            m_upDownVelocity=0;
            m_gravityTimer=0;
            m_jumpCounter =0;
            
            m_leftRightVelocity=0;
            m_upDownVelocity=0;
            
           
            
            
            
        }
    
        bool isJumping() {return m_isJumping;}
        void setJump(bool yesNo) {m_isJumping = yesNo;}
        void jump();
        
        
        
        
        bool didCollideWith(Floor floor);
        bool didCollideWith(Wall wall);
        bool didCollideWith(Ceiling ceiling);
        bool didCollideWith(Character character);
        bool didCollideWithOverloaded(FunctionalFloor floor);
        bool didCollideWithOverloaded(FunctionalWall wall);
        bool didHitSomething() {return m_hitSomething;}
        bool setHitSomethingValue( bool yesNo) {m_hitSomething=yesNo;}
        
        void getRestrictions(Floor floor);
        void getRestrictions(Wall wall);
        void getRestrictions(Ceiling ceiling);
        void getRestrictionsOverloaded(FunctionalFloor floor);
        void getRestrictionsOverloaded(FunctionalWall wall);
        
        float getXCenter();
        float getYCenter();
      
        void resetRestrictions();
        void movement();
        void movementWASD();
        void gravity();
        void setFollowingTether(bool yesNo) {m_isFollowingTether=yesNo;}
        void followTether(Character shadowCharacter);
        bool isFollowingTether(){ return m_isFollowingTether;}
        void followPlatform(MovingPlatform platform);
        void resetUpDownVelocity(){ m_upDownVelocity =0;}
        
        bool isRestrictedDown(){ return m_restricted_down;}
        //bool wasRestrictedDown(){ return m_wasRestricted_down;}
     
        void restrictLeft(bool yesNo) { m_restricted_left = yesNo; }
        void restrictRight(bool yesNo) { m_restricted_right = yesNo; }
        void restrictUp(bool yesNo) { m_restricted_up = yesNo; }
        void restrictDown(bool yesNo) { m_restricted_down = yesNo; }
        
        
        
};

#endif
