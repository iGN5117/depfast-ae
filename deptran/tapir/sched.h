#pragma once

#include "../scheduler.h"

namespace rococo {

class SimpleCommand;
class TapirSched : public Scheduler {
 public:
  using Scheduler::Scheduler;

  int OnDispatch(const SimpleCommand &cmd,
                 int *res,
                 map<int32_t, Value> *output,
                 const function<void()> &callback);

  int OnFastAccept(cmdid_t cmd_id,
                   int* res,
                   const function<void()>& callback);

  int OnDecide(cmdid_t cmd_id, int decision, const function<void()>& callback);
};

} // namespace rococo