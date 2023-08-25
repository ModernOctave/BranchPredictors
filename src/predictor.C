// A very stupid predictor.  It will always predict not taken.
#include <stdio.h>
#include <math.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

const int NumCounterBits = 2;
const int NumBits = 14;
const int NumEntries = 32*512;

bool GHR[NumBits];
int PHT[NumEntries];

int regToInt (bool reg[])
{
  int result = 0;
  for (int i = 0; i < NumBits; i++)
  {
    result += reg[i] * pow(2, NumBits - 1 - i);
  }
  return result;
}

void addBitToReg (bool reg[], bool bit)
{
  for (int i = 0; i < NumBits - 1; i++)
  {
    reg[i] = reg[i + 1];
  }
  reg[NumBits - 1] = bit;
}

void init_predictor ()
{
  for (int i = 0; i < NumEntries; i++)
  {
    PHT[i] = 0;
  }
}

bool make_prediction (unsigned int pc)
{
  return PHT[regToInt(GHR)] > 1;
}

void train_predictor (unsigned int pc, bool outcome)
{
  if (outcome) {
    PHT[regToInt(GHR)] = MIN(PHT[regToInt(GHR)] + 1, 3);
  } else {
    PHT[regToInt(GHR)] = MAX(PHT[regToInt(GHR)] - 1, 0);
  }
  addBitToReg(GHR, outcome);
}
