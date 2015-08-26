/*
 * IRRemote
 * Version 0.1
 * Copyright 2015 Mateusz Świetlicki
 * Based on IRremote by Ken Shirriff and NECIRrcv by Joe Knapp
 */

#ifndef IRRemote_h
#define IRRemote_h
#include "application.h"

class IRRemote
{
  const int irPin;
  int burstWait;
  int burstLength;

public:
  IRRemote(int irPin);
  void setup(int freq, int nbits, int hdr_mark, int hdr_space, int bit_mark, int one_space, int zero_space);
  void send(unsigned long data);
private:
  void enableIROut(int khz);
  void mark(int usec);
  void space(int usec);
  int _freq, _nbits, _hdr_mark, _hdr_space, _bit_mark, _one_space, _zero_space;

};

#define TOPBIT 0x80000000

#endif
