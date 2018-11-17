/*
 * IF_IvmMemory.h
 *
 *  Created on: 23.01.2014
 *      Author: niklausd
 */

#ifndef IF_IVMMEMORY_H_
#define IF_IVMMEMORY_H_

class IF_IvmMemory
{
protected:
  /**
   * Constructor, protected since this is an Interface.
   */
  IF_IvmMemory() { };
public:
  virtual ~IF_IvmMemory() { };
  virtual void write(unsigned int address, unsigned char data) = 0;
  virtual char read(unsigned int address) = 0;
  virtual void setDeviceSerialNr(unsigned long int deviceSerialNr) { }

private: // forbidden default functions
  IF_IvmMemory& operator = (const IF_IvmMemory& );  // assignment operator
  IF_IvmMemory(const IF_IvmMemory& src);            // copy constructor
};

#endif /* IF_IVMMEMORY_H_ */
