#include "executeMachine.h"

ExecuteMachine::ExecuteMachine(std::map<char*, std::vector<char*>> plan)
    : plan(plan)
{
   exec_status = EXEC_STATUS_NIL;
};

void ExecuteMachine::execute()
{
   
};
