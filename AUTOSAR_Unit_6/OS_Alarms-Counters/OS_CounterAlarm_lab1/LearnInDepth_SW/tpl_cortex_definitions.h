/**
 * @file tpl_cortex_definitions.h
 *
 * @section descr File description
 *
 * Defines related to the cortex target platform
 *
 * Generated from application CortexM4
 * Automatically generated by goil on Www Mmm dd hh:mm:ss yyyy
 * from root OIL file LearnInDepth_SW.oil
 *
 * @section infos File informations
 *
 * $$Date$$
 * $$Rev$$
 * $$Author$$
 * $$URL$$
 */

#ifndef TPL_CORTEX_DEFINITIONS_H
#define TPL_CORTEX_DEFINITIONS_H
  
/*-----------------------------------------------------------------------------
 * File generated for target cortex-m/armv7em/stm32f407/stm32f4discovery
 * Number of priority bits :      4
 */
#define PRIO_BITS_IN_NVIC              4

/*
 * Priorities are unshifted and intended to be used in NVIC_SetPriority
 */
#define KERNEL_PRIO_UNSHIFTED        15
#define OS_ISR_PRIO_UNSHIFTED        15
#define ISR1_IT_PRIO_UNSHIFTED        1

/*
 * Priorities are shifted and intended to be stored in BASEPRI
 */
#define KERNEL_PRIO       240          /* Unshifted priority: 15     */
#define OS_ISR_PRIO       240          /* Unshifted priority: 15     */
#define ISR1_IT_PRIO       16          /* Unshifted priority: 1      */

/*
 * Priority of KERNEL_PRIO shifted to fit in SHPR2
 */
#define KERNEL_PRIO_SHPR2    0xF0000000

/*
 * Interrupt numbers for interrupt sources used by ISR
 */

/* TPL_CORTEX_DEFINITIONS_H */
#endif

/* End of file tpl_cortex_definitions.h */
