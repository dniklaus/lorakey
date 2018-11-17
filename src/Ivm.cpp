/*
 * ivm.cpp
 *
 *  Created on: 22.01.2014
 *      Author: niklausd
 */

#include "IF_IvmMemory.h"
#include "Ivm.h"

const unsigned int  Ivm::s_devIdAddr      = 0;
const unsigned int  Ivm::s_ivmVersionAddr = 1;

Ivm::Ivm(IF_IvmMemory* ivmMemory)
: m_ivmMemory(ivmMemory)
{ }

Ivm::~Ivm()
{ }

IF_IvmMemory* Ivm::getIvmMemory()
{
  return m_ivmMemory;
}

void Ivm::setIvmMemory(IF_IvmMemory* ivmMemory)
{
  m_ivmMemory = ivmMemory;
}

unsigned char Ivm::getIvmVersion()
{
  unsigned char ivmVersion = 0;
  if (0 != m_ivmMemory)
  {
    ivmVersion = m_ivmMemory->read(s_ivmVersionAddr);
  }
  return ivmVersion;
}

void Ivm::setIvmVersion(unsigned char ivmVersion)
{
  if (0 != m_ivmMemory)
  {
    m_ivmMemory->write(s_ivmVersionAddr, ivmVersion);
  }
}

unsigned char Ivm::getDeviceId()
{
  unsigned char deviceId = 0;
  if (0 != m_ivmMemory)
  {
    deviceId = m_ivmMemory->read(s_devIdAddr);
  }
  return deviceId;
}

void Ivm::setDeviceId(unsigned char deviceId)
{
  if (0 != m_ivmMemory)
  {
    m_ivmMemory->write(s_devIdAddr, deviceId);
  }
}
