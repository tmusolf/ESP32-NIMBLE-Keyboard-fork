#ifndef NIMBLE_ERR_CODE_H
#define NIMBLE_ERR_CODE_H

#include <Arduino.h>
typedef uint16_t tNimBleErrCode;
typedef struct {
  tNimBleErrCode nimBle;
  tNimBleErrCode formal;
  const char* errName;
  const char* errDesc;
} tNimBleErrRec;

tNimBleErrRec* getNimBleErrRec(tNimBleErrCode errCode);

#endif
