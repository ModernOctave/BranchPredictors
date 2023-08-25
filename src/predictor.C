// A very stupid predictor.  It will always predict not taken.
#include <stdio.h>
#include <math.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

const int NumEntries = 16*1024;
const int NumBits = 2;

int predTable[NumEntries];

void init_predictor ()
{
  for (int i = 0; i < NumEntries; i++)
    predTable[i] =  0;
}

bool make_prediction (unsigned int pc)
{
  int index = pc % NumEntries;
  return predTable[index] > pow(2, NumBits-1);
}

void train_predictor (unsigned int pc, bool outcome)
{
  int index = pc % NumEntries;
  if (outcome)
    predTable[index] = MIN(predTable[index] + 1, (int)pow(2, NumBits));
  else
    predTable[index] = MAX(predTable[index] - 1, 0);
}
