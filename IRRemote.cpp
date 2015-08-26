/*
 * IRRemote
 * Version 0.1
 * Copyright 2015 Mateusz Świetlicki
 * Based on IRremote by Ken Shirriff and NECIRrcv by Joe Knapp
 */

#include "IRRemote.h"

IRRemote::IRRemote(int irPin) : irPin(irPin) {}

void IRRemote::setup(int freq, int nbits, int hdr_mark, int hdr_space, int bit_mark, int one_space, int zero_space) {
  _freq = freq;
  _nbits = nbits;
  _hdr_mark = hdr_mark;
  _hdr_space = hdr_space;
  _bit_mark = bit_mark;
  _one_space = one_space;
  _zero_space = zero_space;
}

void IRRemote::send(unsigned long data) {
  enableIROut(_freq);
  mark(_hdr_mark);
  space(_hdr_space);
  for (int i = 0; i < _nbits; i++) {
    if (data & TOPBIT) {
      mark(_bit_mark);
      space(_one_space);
    }
    else {
      mark(_bit_mark);
      space(_zero_space);
    }
    data <<= 1;
  }
  mark(_bit_mark);
  space(0);
}

void IRRemote::mark(int time) {
  // Sends an IR mark (frequency burst output) for the specified number of microseconds.
  noInterrupts();

  while (time > 0) {
    digitalWrite(irPin, HIGH); // this takes about 3 microseconds to happen
    delayMicroseconds(_burstWait);
    digitalWrite(irPin, LOW); // this also takes about 3 microseconds
    delayMicroseconds(_burstWait);

    time -= _burstLength;
  }

  interrupts();
}

void IRRemote::space(int time) { // Sends an IR space (no output) for the specified number of microseconds.
  digitalWrite(irPin, LOW); // Takes about 3 microsecondes
  if (time > 3) {
    delayMicroseconds(time - 3);
  }
}

void IRRemote::enableIROut(int khz) {
  // Enables IR output.  The khz value controls the modulation frequency in kilohertz.
  // MAX frequency is 166khz.
  pinMode(irPin, OUTPUT);
  digitalWrite(irPin, LOW);

  // This is the time to wait with the IR LED on and off to make the frequency, in microseconds.
  // The - 3.0 at the end is because digitalWrite() takes about 3 microseconds. Info from:
  // https://github.com/eflynch/sparkcoreiremitter/blob/master/ir_emitter/ir_emitter.ino
  _burstWait = round(1.0 / khz * 1000.0 / 2.0 - 3.0);
  // This is the total time of a period, in microseconds.
  _burstLength = round(1.0 / khz * 1000.0);
}