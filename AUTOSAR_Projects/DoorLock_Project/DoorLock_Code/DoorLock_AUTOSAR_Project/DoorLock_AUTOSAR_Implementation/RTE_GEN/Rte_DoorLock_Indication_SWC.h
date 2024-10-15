/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_DoorLock_Indication_SWC.h
 * Generated on: Sun Oct 13 23:35:11 AST
 ********************************************************************/

#ifndef RTE_DOORLOCK_INDICATION_SWC_H
#define RTE_DOORLOCK_INDICATION_SWC_H

#include "Rte_DoorLock_Indication_SWC_Type.h"

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

/**************** component data structure definition ****************/

#ifndef IN_RTE_C
typedef const Rte_CDS_DoorLock_Indication_SWC * const Rte_Instance;
#endif

/************************* instance handle ***************************/

extern const Rte_CDS_DoorLock_Indication_SWC * const Rte_Inst_DoorLock_Indication_SWC;

/************************ application errors *************************/

#define RTE_E_IF_CS_LED_E_OK ((Std_ReturnType)0)
#define RTE_E_IF_CS_LED_E_NOT_OK ((Std_ReturnType)1)

/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port: 		RP_SR_DoorState
 * Interface:	IF_SR_DoorLock
 * DataElement:	DoorState
 * Runnable:	DoorLock_Indication
 *****************************************************/
extern myunit8 Rte_IRead_DoorLock_Indication_SWC_DoorLock_Indication_RP_SR_DoorState_DoorState (void);
#ifndef IN_RTE_C
#define Rte_IRead_DoorLock_Indication_RP_SR_DoorState_DoorState() \
	Rte_IRead_DoorLock_Indication_SWC_DoorLock_Indication_RP_SR_DoorState_DoorState()
#endif

/*****************************************************
 * Port: 		RP_CS_LED_Switch
 * Interface:	IF_CS_LED
 * Operation:	LED_Switch
 * Sync/Async:	Synchronous
 *****************************************************/
extern Std_ReturnType Rte_Call_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch (myunit8 LedState);
#ifndef IN_RTE_C
#define Rte_Call_RP_CS_LED_Switch_LED_Switch(LedState) \
	Rte_Call_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch(LedState)
#endif


/**************** event triggered runnable entities *******************/

/*****************************************************
 * Runnable: 	DoorLock_Indication
 * Period:		0.012
 *****************************************************/
extern void DoorLock_Indication_Runnable(void);


/******** ARUnit-specific function pointers for server call delegates *********/
typedef Std_ReturnType (*FunctionPtr_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch)(myunit8 LedState);


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_DOORLOCK_INDICATION_SWC_H */
