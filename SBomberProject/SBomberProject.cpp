
#include <conio.h>
#include <thread>
#include <chrono>


#include "SBomber.h"
#include "MyTools.h"


using namespace std;

//========================================================================================================================

int main(void)
{
   // MyTools::FileLoggerSingletone::getInstance();
    MyTools::FileLoggerSingletone& logger = MyTools::FileLoggerSingletone::getInstance();
    logger.OpenLogFile("log.txt");

    SBomber game; 

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }
        std::this_thread::sleep_for(100ms);
        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    logger.CloseLogFile();

    return 0;
}
