#include "RTE_SWC1.h"

Std_ReturnType SUM(){
	Std_ReturnType status = E_NOT_OK;
	unsigned short x,y;
	unsigned int z;

	status = RTE_Read_SWC1_SUM_SWC1_R_Port_Sum_Val1(&x);
	status = RTE_Read_SWC1_SUM_SWC1_R_Port_Sum_Val2(&y);
	z = x + y;
	status = RTE_Write_SWC1_SUM_SWC1_P_Port_Sum_sumResult(z)

	return Std_ReturnType;
}
