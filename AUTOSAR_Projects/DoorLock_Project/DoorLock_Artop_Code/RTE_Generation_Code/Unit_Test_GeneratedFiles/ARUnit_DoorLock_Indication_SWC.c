/********************************************************************
 * Automatically generated by ARUnit
 * Filename: ARUnit_DoorLock_Indication_SWC_.c
 * Generated on: Sun Oct 13 23:35:11 AST
 ********************************************************************/

#include "string.h"
#include "ARUnit_DoorLock_Indication_SWC.h"


extern const Rte_CDS_DoorLock_Indication_SWC Rte_Instance_DoorLock_Indication_SWC;
extern const Rte_CDS_DoorLock_Indication_SWC * const Rte_Inst_DoorLock_Indication_SWC;


extern Std_ReturnType DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch_Buffer_retcode;

extern FunctionPtr_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch Rte_Call_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch_Delegate;

DECLSPEC_EXPORT void ARUnit_IWrite_DoorLock_Indication_SWC_DoorLock_Indication_RP_SR_DoorState_DoorState(myunit8 DoorState)
{
	(Rte_Inst_DoorLock_Indication_SWC)->DoorLock_Indication_RP_SR_DoorState_DoorState->value = DoorState;
}
DECLSPEC_EXPORT myunit8* ARUnit_IWriteRef_DoorLock_Indication_SWC_DoorLock_Indication_RP_SR_DoorState_DoorState(void)
{
	return &(Rte_Inst_DoorLock_Indication_SWC)->DoorLock_Indication_RP_SR_DoorState_DoorState->value;
}
DECLSPEC_EXPORT myunit8 ARUnit_IRead_DoorLock_Indication_SWC_DoorLock_Indication_RP_SR_DoorState_DoorState(void)
{
	return (Rte_Inst_DoorLock_Indication_SWC)->DoorLock_Indication_RP_SR_DoorState_DoorState->value;
}
DECLSPEC_EXPORT void ARUnit_Call_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch_ReturnCode(Std_ReturnType returnCode)
{
	DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch_Buffer_retcode = returnCode;
}

DECLSPEC_EXPORT void ARUnit_Set_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch_Delegate(FunctionPtr_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch  delegate)
{
	Rte_Call_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch_Delegate = delegate;
}

DECLSPEC_EXPORT void ARUnit_Trigger_DoorLock_Indication_SWC_DoorLock_Indication_Runnable(void)
{
	DoorLock_Indication_Runnable();
}
