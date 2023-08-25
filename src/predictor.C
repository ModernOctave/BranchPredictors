// A very stupid predictor.  It will always predict not taken.
#include <stdio.h>
#include <math.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

const int NumCounterBits = 2;
const int NumGHRBits = 4;
const int NumPCBits = 5;
const int NumEntries = 512;

bool GHR[NumGHRBits];
int PHT[NumEntries];

int regToInt (bool GHR[], int pc)
{
  int result = pc % (int) pow(2, NumPCBits);
  for (int i = 0; i < NumGHRBits; i++)
  {
    result += GHR[i] * pow(2, NumPCBits + i);
  }
  return result;
}

void addBitToReg (bool reg[], bool bit)
{
  for (int i = 0; i < NumGHRBits - 1; i++)
  {
    reg[i] = reg[i + 1];
  }
  reg[NumGHRBits - 1] = bit;
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
  return PHT[regToInt(GHR, pc)] > 1;
}

void train_predictor (unsigned int pc, bool outcome)
{
  if (outcome) {
    PHT[regToInt(GHR, pc)] = MIN(PHT[regToInt(GHR, pc)] + 1, 3);
  } else {
    PHT[regToInt(GHR, pc)] = MAX(PHT[regToInt(GHR, pc)] - 1, 0);
  }
  addBitToReg(GHR, outcome);
}
