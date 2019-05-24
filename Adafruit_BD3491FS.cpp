/*!
 *  @file Adafruit_BD3491FS.cpp
 *
 *  @mainpage Adafruit BD3491FS I2C water resistant barometric pressure sensor
 *
 *  @section intro_sec Introduction
 *
 * 	I2C Driver for the BD3491FS I2C water resistant barometric pressure sensor
 *
 * 	This is a library for the Adafruit BD3491FS breakout:
 * 	http://www.adafruit.com/products
 *
 * 	Adafruit invests time and resources providing this open source code,
 *  please support Adafruit and open-source hardware by purchasing products from
 * 	Adafruit!
 *
 *  @section dependencies Dependencies
 *
 *  This library depends on the Adafruit BusIO library
 *
 *  @section author Author
 *
 *  Bryan Siepert for Adafruit Industries
 *
 * 	@section license License
 *
 * 	BSD (see license.txt)
 *
 * 	@section  HISTORY
 *
 *     v1.0 - First release
 */

#include "Arduino.h"
#include <Wire.h>

#include "Adafruit_BD3491FS.h"

/*!
 *    @brief  Instantiates a new BD3491FS class
 */
Adafruit_BD3491FS::Adafruit_BD3491FS(void) {}

/*!
 *    @brief  Sets up the hardware and initializes I2C
 *    @param  i2c_address
 *            The I2C address to be used.
 *    @param  wire
 *            The Wire object to be used for I2C connections.
 *    @return True if initialization was successful, otherwise false.
 */
boolean Adafruit_BD3491FS::begin(uint8_t i2c_address, TwoWire *wire) {
  i2c_dev = new Adafruit_I2CDevice(i2c_address, wire);

  if (!i2c_dev->begin()) {
    return false;
  }

  return true;
}

/**************************************************************************/
/*!
    @brief Selects an input channel.
    @param  input
            The new input to be selected. Must be a `BD3491FS_Input`
*/
/**************************************************************************/
void Adafruit_BD3491FS::setCurrentInput(BD3491FS_Input input){
    Adafruit_I2CRegister current_input =  
      Adafruit_I2CRegister(i2c_dev, BD3491FS_INPUT_SELECTOR, 1);
    current_input.write(input);
}

/**************************************************************************/
/*!
    @brief Sets the gain applied to the active inputs.
    @param  gain
            The new input to be selected. Must be a `BD3491FS_Input`
*/
/**************************************************************************/
void Adafruit_BD3491FS::setInputGain(BD3491FS_Level gain){
    Adafruit_I2CRegister input_gain =  
      Adafruit_I2CRegister(i2c_dev, BD3491FS_INPUT_GAIN, 1);
    input_gain.write(gain << 1);
}

/**************************************************************************/
/*!
    @brief Sets the attenuation for output channel 1.
    @param  attenuation
            The attenuation to applied to output channnel 1. 
            Must be a `BD3491FS_Level`
*/
/**************************************************************************/
void Adafruit_BD3491FS::setVolumeCh1(BD3491FS_Level attenuation){
    Adafruit_I2CRegister volume =  
      Adafruit_I2CRegister(i2c_dev, BD3491FS_VOLUME_GAIN_CH1, 1);
    volume.write(attenuation << 1);
}

/**************************************************************************/
/*!
    @brief Sets the attenuation for output channel 2
    @param  attenuation
            The attenuation to applied to output channnel 2. 
            Must be a `BD3491FS_Level`
*/
/**************************************************************************/
void Adafruit_BD3491FS::setVolumeCh2(BD3491FS_Level attenuation){
    Adafruit_I2CRegister volume =  
      Adafruit_I2CRegister(i2c_dev, BD3491FS_VOLUME_GAIN_CH2, 1);
    volume.write(attenuation << 1);
}

/**************************************************************************/
/*!
    @brief Applys gain to or cuts the Bass range.
    @param  level
            The amount of gain or cut. Must be a `BD3491FS_Level`
    @param  cut
            Cut or Boost. Set true to cut, or false to boost

*/
/**************************************************************************/
void Adafruit_BD3491FS::setBassGain(BD3491FS_Level level, bool cut){
    Adafruit_I2CRegister bass_gain =  
      Adafruit_I2CRegister(i2c_dev, BD3491FS_BASS_GAIN, 1);
    bass_gain.write((cut <<7) & (level << 1));
}

/**************************************************************************/
/*!
    @brief Applys gain to or cuts the Treble range.
    @param  level
            The amount of gain or cut. Must be a `BD3491FS_Level`
    @param  cut
            Cut or Boost. Set true to cut, or false to boost
*/
/**************************************************************************/
void Adafruit_BD3491FS::setTrebleGain(BD3491FS_Level level, bool cut){
    Adafruit_I2CRegister treble_gain =  
      Adafruit_I2CRegister(i2c_dev, BD3491FS_TREBLE_GAIN, 1);
    treble_gain.write((cut <<7) & (level << 1));
}