/*
 * ivm.h
 *
 *  Created on: 22.01.2014
 *      Author: niklausd
 */

#ifndef IVM_H_
#define IVM_H_

class IF_IvmMemory;

class Ivm
{
public:
  Ivm(IF_IvmMemory* ivmMemory = 0);
  virtual ~Ivm();

  /**
   * Get current Inventory Management Memory.
   * @return IVM Memory
   */
  IF_IvmMemory* getIvmMemory();

  /**
   * Get the current version of the Inventory Management Data.
   * @return IVM Version (Byte)
   */
  unsigned char getIvmVersion();

  /**
   * Get the device ID.
   * @return Device ID (Byte)
   */
  unsigned char getDeviceId();

  /**
   * Set the device ID.
   * @parameter deviceId (Byte)
   */
  void setDeviceId(unsigned char deviceId);

protected:
  /**
   * Set Inventory Management Memory.
   * @parameter IVM Memory.
   */
  void setIvmMemory(IF_IvmMemory* ivmMemory);

  /**
   * Initialize memory for new features.
   */
  virtual void maintainVersionChange() = 0;

  /**
   * Set the Inventory Management Version.
   * @parameter ivmVersion (Byte)
   */
  virtual void setIvmVersion(unsigned char ivmVersion);

private:
  IF_IvmMemory* m_ivmMemory;

  /**
   * Device ID storage Address.
   */
  const static unsigned int  s_devIdAddr;

  /**
   *
   */
  const static unsigned int s_ivmVersionAddr;

private: // forbidden default functions
  Ivm& operator = (const Ivm& );  // assignment operator
  Ivm(const Ivm& src);            // copy constructor
};

#endif /* IVM_H_ */
