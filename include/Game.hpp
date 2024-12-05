#ifndef Game_H
#define Game_H

class Game{
    public: 
        Game();
        void run();

    private: 
        void processEvents();
        void update();
        void render();
};

#endif