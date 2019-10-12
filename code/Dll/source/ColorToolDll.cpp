
#include "ApiDefine.hpp"
#include "ColorTool.hpp"

namespace unity_dll {
	extern "C" {
		///DLL INTERFACE FUNCYIONS: inverse color
		AMAPI int CalculateInverseColor(int color) {return InverseColor(color); }
		///DLL INTERFACE FUNCYIONS: Analogous color
		AMAPI int CalculateAnalogousColor(int color,int percentage) { return AnalogousColor(color, percentage); }
		///DLL INTERFACE FUNCYIONS: Tool initializer 
		AMAPI int Initialize() { return InitializeTool(); }


	}
}