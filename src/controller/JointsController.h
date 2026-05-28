#pragma once

#include "../model/Joint.h"

class JointsController{
    private:
        Joint joint1;
        Joint joint2;
        Joint joint3;

    public:
        void begin();
        void initialize();
        void getFood();
        void eat();
        
};