#ifndef IRRemoteBenq_h
#define IRRemoteBenq_h

#include "IRRemote.h"

class IRRemoteBenq : public IRRemote
{
public:
  IRRemoteBenq(int irPin);
  void SendCommand(String command);
private:
  const unsigned long ON = 0x000CF20D;
  const unsigned long OFF = 0x000C728D;
};

#endif
