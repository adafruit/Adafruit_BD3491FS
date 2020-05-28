/*!
 * @file Adafruit_BD3491FS.h
 */

#ifndef _ADAFRUIT_BD3491FS_H
#define _ADAFRUIT_BD3491FS_H

#include "Arduino.h"
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Wire.h>

#define BD3491FS_I2CADDR_DEFAULT 0x41 ///< BD3491FS default I2C address

#define BD3491FS_INPUT_SELECTOR 0x04  ///< Input Selector register
#define BD3491FS_INPUT_GAIN 0x06      ///< Input Gain register
#define BD3491FS_VOLUME_GAIN_CH1 0x21 ///< Channnel 1 Volume Attenuation regiter
#define BD3491FS_VOLUME_GAIN_CH2 0x22 ///< Channnel 2 Volume Attenuation regiter
#define BD3491FS_BASS_GAIN 0x51       ///< Bass Boost/Cut regiter
#define BD3491FS_TREBLE_GAIN 0x57     ///< Treble Boost/Cut regiter
#define BD3491FS_SURROUND 0x78        ///< Sourround Gain regiter
#define BD3491FS_SYSTEM_RESET 0xFE    ///< Reset regiter

/**
 * @brief Input Selector options.
 *
 * Allowed values for `setCurrentInput`.
 */
typedef enum _active_input {
  BD3491FS_INPUT_A,     ///< Inputs A1 and A2
  BD3491FS_INPUT_B,     ///< Inputs B1 and B2
  BD3491FS_INPUT_C,     ///< Inputs C1 and C2
  BD3491FS_INPUT_D,     ///< Inputs D1 and D2
  BD3491FS_INPUT_E,     ///< Inputs E1 and E2
  BD3491FS_INPUT_SHORT, ///< Short inputs
  BD3491FS_INPUT_F,     ///< Inputs F1 and F2
  BD3491FS_INPUT_MUTE,  ///< Mute all
} BD3491FS_Input;

/**
 * @brief Gain, cut, or attenuation options.
 *
 * Allowed values for `setInputGain`, `setVolumeCh1`, `setVolumeCh2`,
 * `setBassGain`, and `setTrebleGain`
 */
typedef enum _level {
  BD3491FS_GAIN_0DB,        ///< 0dB
  BD3491FS_GAIN_2DB,        ///< 2dB
  BD3491FS_GAIN_4DB,        ///< 4dB
  BD3491FS_GAIN_6DB,        ///< 6dB
  BD3491FS_GAIN_8DB,        ///< 8dB
  BD3491FS_GAIN_10DB,       ///< 10dB
  BD3491FS_GAIN_12DB,       ///< 12dB
  BD3491FS_GAIN_14DB,       ///< 14dB
  BD3491FS_GAIN_16DB,       ///< 16dB
  BD3491FS_GAIN_20DB = 0x0A ///< 20dB
} BD3491FS_Level;

/*!
 *    @brief  Class that stores state and functions for interacting with
 *            BD3491FS Current and Power Sensor
 */
class Adafruit_BD3491FS {
public:
  Adafruit_BD3491FS();
  bool begin(uint8_t i2c_addr = BD3491FS_I2CADDR_DEFAULT,
             TwoWire *wire = &Wire);
  void reset(void);
  void setCurrentInput(BD3491FS_Input input);
  void setInputGain(BD3491FS_Level gain);
  void setVolumeCh1(uint8_t attenuation);
  void setVolumeCh2(uint8_t attenuation);
  void setBassGain(BD3491FS_Level level, bool cut);
  void setTrebleGain(BD3491FS_Level level, bool cut);

  Adafruit_I2CRegister *CurrentInput; ///< BusIO Register for INTERRUPT_STATUS

private:
  Adafruit_I2CDevice *i2c_dev;
};

#endif
