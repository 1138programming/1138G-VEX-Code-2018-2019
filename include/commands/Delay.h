#ifndef _COMMANDS_DELAY_H_
#define _COMMANDS_DELAY_H_

#include "commands/Command.h"

class Delay : public Command {
  private:
    unsigned int startTime;
    unsigned int duration;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    Delay(unsigned int duration);
};

#endif // _COMMANDS_DELAY_H_
