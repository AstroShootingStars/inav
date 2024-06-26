/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>

#include <platform.h>

#include "common/axis.h"

#include "drivers/sensor.h"
#include "drivers/pwm_esc_detect.h"
#include "drivers/pwm_mapping.h"
#include "drivers/pwm_output.h"
#include "drivers/serial.h"

#include "fc/rc_controls.h"

#include "flight/failsafe.h"
#include "flight/mixer.h"
#include "flight/pid.h"

#include "rx/rx.h"

#include "io/serial.h"

#include "telemetry/telemetry.h"

#include "sensors/battery.h"
#include "sensors/sensors.h"

#include "config/config_master.h"
#include "config/feature.h"

#include "sensors/battery.h"
#include "sensors/compass.h"

void targetConfiguration(void)
{
    compassConfigMutable()->mag_align = CW90_DEG;

#if defined(CLRACINGF4AIRV2) || defined(CLRACINGF4AIRV3)
    // To improve backwards compatibility with INAV versions 6.x and older
    timerOverridesMutable(timer2id(TIM8))->outputMode = OUTPUT_MODE_MOTORS;
#endif
}
