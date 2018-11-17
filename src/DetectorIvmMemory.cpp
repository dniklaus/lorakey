/*
 * DetectorIvmMemory.cpp
 *
 *  Created on: 27.08.2018
 *      Author: niklaudi
 */

//#include <Arduino.h>

#include <DetectorIvmMemory.h>

const unsigned int DetectorIvmMemory::s_numDevices  =  6;
const unsigned int DetectorIvmMemory::s_numMaxChars = 32;

//-----------------------------------------------------------------------------
DetectorIvmMemory::DetectorIvmMemory()
: m_hwDeviceId(0)
{ }

DetectorIvmMemory::~DetectorIvmMemory()
{ }

void DetectorIvmMemory::write(unsigned int address, unsigned char data)
{
  // Dummy write - no action
}

char DetectorIvmMemory::read(unsigned int address)
{
  const char deviceSpecificKeys[s_numDevices][KT_NumKeys][s_numMaxChars+1] =
  {
    {
      { "trööt-0" },     // deviceId
      { "" },                          // devAddr
      { "" },  // nwkSKey
      { "" }   // appSKey
    },
    {
      { "trööt-1" },        // deviceId
      { "" },                          // devAddr
      { "" },  // nwkSKey
      { "" }   // appSKey
    },
    {
      { "trööt-2" },
      { "" },
      { "" },
      { "" }
    },
    {
      { "trööt-3" },
      { "" },
      { "" },
      { "" }
    },
    {
      { "trööt-4" },
      { "" },
      { "" },
      { "" }
    },
    {
      { "trööt-5" },
      { "" },
      { "" },
      { "" }
    }
  };
  unsigned int key = address / s_numMaxChars;
  unsigned int ch  = address % s_numMaxChars;
  return deviceSpecificKeys[m_hwDeviceId][key][ch];
}

void DetectorIvmMemory::setDeviceSerialNr(unsigned long int deviceSerialNr)
{
  m_hwDeviceId = deviceSerialNr;
}

unsigned int DetectorIvmMemory::sizeOfDeviceKeyStorage()
{
  return s_numDevices * KT_NumKeys * s_numMaxChars;
}
