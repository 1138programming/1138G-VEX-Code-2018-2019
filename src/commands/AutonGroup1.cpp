#include "commands/AutonGroup1.h"
#include "commands/MoveBaseTo.h"
#include "commands/Delay.h"

AutonGroup1::AutonGroup1() {
  // Add commands to be run sequentially using addSequentialCommand()
  // Add commands to be run in parallel using addParallelCommand();

  addSequentialCommand(new MoveBaseTo(1000, 1000));
  addSequentialCommand(new Delay(1000));
  addSequentialCommand(new MoveBaseTo(-1000, -1000));
}
