#ifndef _COMMANDS_MOVEBASETO_H_
#define _COMMANDS_MOVEBASETO_H_

#include "commands/Command.h"

class MoveBaseTo : public Command {
  private:
    int leftSetpoint = 0;
    int rightSetpoint = 0;
    bool absolute = false;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveBaseTo(int leftSetpoint, int rightSetpoint, bool absolute = false);
};

#endif // _COMMANDS_MOVEBASETO_H_
