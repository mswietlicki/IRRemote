#ifndef IRRemoteMicrolab_h
#define IRRemoteMicrolab_h

#include "IRRemote.h"

class IRRemoteMicrolab : public IRRemote
{
public:
  IRRemoteMicrolab(int irPin);
  void SendCommand(String command);
private:
  const unsigned long INPUT = 0x807F20DF;
  const unsigned long VOLUP = 0x807F8877;
  const unsigned long VOLDOWN = 0x807F08F7;
  const unsigned long RESET = 0x807F10EF;
  const unsigned long MUTE = 0x807F40BF;
  const unsigned long TREBLEUP = 0x807F906F;
  const unsigned long TREBLEDOWN = 0x807FB04F;
  const unsigned long BASSUP = 0x807F50AF;
  const unsigned long BASSDOWN = 0x807F708F;
};

#endif
