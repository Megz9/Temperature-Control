#include "STD_TYPES.h"
#include <math.h>

#include "voltageTempMapping.h"

u8 getTemp(u8 voltage){
	return round(voltage * m + c);
}
