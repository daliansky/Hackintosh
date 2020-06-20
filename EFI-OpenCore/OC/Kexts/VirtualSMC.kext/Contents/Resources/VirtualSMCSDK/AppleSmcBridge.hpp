//
//  AppleSmcBridge.hpp
//  AppleSmcBridge
//
//  Copyright © 2017 vit9696. All rights reserved.
//

#ifndef AppleSmcBridge_hpp
#define AppleSmcBridge_hpp

#include <stdint.h>

using CHAR8  = char;
using UINT8  = uint8_t;
using UINT16 = uint16_t;
using UINT32 = uint32_t;

static constexpr uint8_t BIT0 = 0b00000001;
static constexpr uint8_t BIT1 = 0b00000010;
static constexpr uint8_t BIT2 = 0b00000100;
static constexpr uint8_t BIT3 = 0b00001000;
static constexpr uint8_t BIT4 = 0b00010000;
static constexpr uint8_t BIT5 = 0b00100000;
static constexpr uint8_t BIT6 = 0b01000000;
static constexpr uint8_t BIT7 = 0b10000000;

extern "C" {
	#include "AppleSmc.h"
}
	
#endif /* AppleSmcBridge_hpp */
