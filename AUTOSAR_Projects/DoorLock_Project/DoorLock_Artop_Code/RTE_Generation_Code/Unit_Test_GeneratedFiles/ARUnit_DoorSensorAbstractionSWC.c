/********************************************************************
 * Automatically generated by ARUnit
 * Filename: ARUnit_DoorSensorAbstractionSWC_.c
 * Generated on: Sun Oct 13 23:35:11 AST
 ********************************************************************/

#include "string.h"
#include "ARUnit_DoorSensorAbstractionSWC.h"


extern const Rte_CDS_DoorSensorAbstractionSWC Rte_Instance_DoorSensorAbstractionSWC;
extern const Rte_CDS_DoorSensorAbstractionSWC * const Rte_Inst_DoorSensorAbstractionSWC;




DECLSPEC_EXPORT void ARUnit_IWrite_DoorSensorAbstractionSWC_ReadDoorSensor_PP_SR_DoorState(myunit8 DoorState)
{
		(Rte_Inst_DoorSensorAbstractionSWC)->ReadDoorSensor_PP_SR_DoorState->value = DoorState;
}
DECLSPEC_EXPORT myunit8* ARUnit_IWriteRef_DoorSensorAbstractionSWC_ReadDoorSensor_PP_SR_DoorState(void)
{
	return &(Rte_Inst_DoorSensorAbstractionSWC)->ReadDoorSensor_PP_SR_DoorState->value;
}
DECLSPEC_EXPORT myunit8 ARUnit_IRead_DoorSensorAbstractionSWC_ReadDoorSensor_PP_SR_DoorState(void)
{
	return (Rte_Inst_DoorSensorAbstractionSWC)->ReadDoorSensor_PP_SR_DoorState->value;
}
DECLSPEC_EXPORT Std_ReturnType ARUnit_Trigger_DoorSensorAbstractionSWC_LED_Switch_Runnable(myunit8 LedState)
{
	return LED_Switch_Runnable(LedState);
}


DECLSPEC_EXPORT void ARUnit_Trigger_DoorSensorAbstractionSWC_ReadDoorSensor_Runnable(void)
{
	ReadDoorSensor_Runnable();
}
