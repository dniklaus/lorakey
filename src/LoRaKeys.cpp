//============================================================================
// Name        : LoRaKeys.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <DetectorIvm.h>
#include <DetectorIvmMemory.h>

int main()
{
  DetectorIvm* ivm = new DetectorIvm();

  for (unsigned long int i = 0; i < 6; i++)
  {
    ivm->getIvmMemory()->setDeviceSerialNr(i);

    printf("---------------------------------------------------------------------------\n");
    printf("Device Serial Nr: %lu\n", i);
    printf("---------------------------------------------------------------------------\n");

    char deviceId[DetectorIvmMemory::s_numMaxChars+1];
    ivm->getDeviceId(deviceId, sizeof(deviceId));
    printf("deviceId: %s\n", deviceId);

    char devAddr[DetectorIvmMemory::s_numMaxChars+1];
    ivm->getDevAddr(devAddr, sizeof(devAddr));
    printf("devAddr:  %s\n", devAddr);

    char nwkSKey[DetectorIvmMemory::s_numMaxChars+1];
    ivm->getNwkSKey(nwkSKey, sizeof(nwkSKey));
    printf("nwkSKey:  %s\n", nwkSKey);

    char appSKey[DetectorIvmMemory::s_numMaxChars+1];
    ivm->getAppSKey(appSKey, sizeof(appSKey));
    printf("appSKey:  %s\n", appSKey);

    printf("\n");
  }
  return 0;
}
