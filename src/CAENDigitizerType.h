/******************************************************************************
* 
* CAEN SpA - Computing Division
* Via Vetraia, 11 - 55049 - Viareggio ITALY
* +390594388398 - www.caen.it
*
***************************************************************************//**
* \note TERMS OF USE:
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License as published by the Free Software
* Foundation. This program is distributed in the hope that it will be useful, 
* but WITHOUT ANY WARRANTY; without even the implied warranty of 
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. The user relies on the 
* software, documentation and results solely at his own risk.
*
* \file     CAENDigitizerType.h
* \brief    CAEN - Digitizer Library types definition
* \author   Alberto Lucchesi, Giovanni Bianchi (support.computing@caen.it)
*
* This library provide functions, structures and definitions for the CAEN
* digitizer family
******************************************************************************/

#ifndef __CAENDIGITIZERTYPE_H
#define __CAENDIGITIZERTYPE_H

#ifdef WIN32
	#include <windows.h>
	#define CAENDGTZ_API __stdcall
#else 
	#include <sys/time.h>
	#include <sys/types.h>
	#include <unistd.h>
	#include <stdint.h> 
	#define CAENDGTZ_API
#endif

#ifdef WIN32
	#ifndef int8_t
        #define int8_t  INT8
    #endif
    #ifndef int16_t
        #define int16_t INT16
    #endif
    #ifndef int32_t
        #define int32_t INT32
    #endif
    #ifndef int64_t
        #define int64_t INT64
    #endif
    #ifndef uint8_t
        #define uint8_t  UINT8
    #endif
    #ifndef uint16_t
        #define uint16_t UINT16
    #endif
    #ifndef uint32_t
        #define uint32_t UINT32
    #endif
    #ifndef uint64_t
        #define uint64_t UINT64
    #endif
#endif


#define MAX_UINT16_CHANNEL_SIZE				64
#define MAX_UINT8_CHANNEL_SIZE				8
#define MAX_V1724DPP_CHANNEL_SIZE			8
#define MAX_V1720DPP_CHANNEL_SIZE			8
#define MAX_X742_CHANNEL_SIZE				9
#define MAX_X742_GROUP_SIZE					4

/******************************************************************************
* Digitizer Registers Address Map 
******************************************************************************/

#define CAEN_DGTZ_MULTI_EVENT_BUFFER						0x0000

#define CAEN_DGTZ_CHANNEL_ZS_THRESHOLD_BASE_ADDRESS			0x1024
#define CAEN_DGTZ_CHANNEL_ZS_NSAMPLE_BASE_ADDRESS			0x1028
#define CAEN_DGTZ_CHANNEL_THRESHOLD_BASE_ADDRESS			0x1080
#define CAEN_DGTZ_CHANNEL_OV_UND_TRSH_BASE_ADDRESS			0x1084
#define CAEN_DGTZ_CHANNEL_STATUS_BASE_ADDRESS				0x1088
#define CAEN_DGTZ_CHANNEL_AMC_FPGA_FW_BASE_ADDRESS			0x108C
#define CAEN_DGTZ_CHANNEL_BUFFER_OCC_BASE_ADDRESS			0x1094
#define CAEN_DGTZ_CHANNEL_DAC_BASE_ADDRESS					0x1098
#define CAEN_DGTZ_CHANNEL_GROUP_V1740_BASE_ADDRESS			0x10A8
#define CAEN_DGTZ_GROUP_FASTTRG_THR_V1742_BASE_ADDRESS		0x10D4
#define CAEN_DGTZ_GROUP_FASTTRG_DCOFFSET_V1742_BASE_ADDRESS	0x10DC
#define CAEN_DGTZ_DRS4_FREQUENCY_REG						0x10D8

#define CAEN_DGTZ_BROAD_CH_CTRL_ADD						0x8000
#define CAEN_DGTZ_BROAD_CH_CONFIGBIT_SET_ADD			0x8004
#define CAEN_DGTZ_BROAD_CH_CLEAR_CTRL_ADD				0x8008
#define CAEN_DGTZ_BROAD_NUM_BLOCK_ADD					0x800C
#define CAEN_DGTZ_CUSTOM_SIZE_REG						0x8020
#define CAEN_DGTZ_DPP_NUM_EVENTS_PER_AGGREGATE			0x8034
#define CAEN_DGTZ_DRS4_FREQUENCY_REG_WRITE				0x80D8
#define CAEN_DGTZ_ACQ_CONTROL_ADD						0x8100
#define CAEN_DGTZ_ACQ_STATUS_ADD						0x8104
#define CAEN_DGTZ_SW_TRIGGER_ADD						0x8108
#define CAEN_DGTZ_TRIGGER_SRC_ENABLE_ADD				0x810C
#define CAEN_DGTZ_FP_TRIGGER_OUT_ENABLE_ADD				0x8110
#define CAEN_DGTZ_POST_TRIG_ADD							0x8114				
#define CAEN_DGTZ_FRONT_PANEL_IO_ADD					0x8118			
#define CAEN_DGTZ_FRONT_PANEL_IO_CTRL_ADD				0x811C		
#define CAEN_DGTZ_CH_ENABLE_ADD							0x8120			
#define CAEN_DGTZ_FW_REV_ADD							0x8124			
#define CAEN_DGTZ_DOWNSAMPLE_FACT_ADD					0x8128				
#define CAEN_DGTZ_EVENT_STORED_ADD						0x812C		
#define CAEN_DGTZ_MON_SET_ADD							0x8138				
#define CAEN_DGTZ_BOARD_INFO_ADD						0x8140
#define CAEN_DTGZ_EVENT_SIZE_ADD						0x814C
#define CAEN_DGTZ_MON_MODE_ADD							0x8144			
#define CAEN_DGTZ_ANALOG_MON_ADD						0x8150

#define CAEN_DGTZ_VME_CONTROL_ADD						0xEF00				
#define CAEN_DGTZ_VME_STATUS_ADD						0xEF04				
#define CAEN_DGTZ_BOARD_ID_ADD							0xEF08				
#define CAEN_DGTZ_MCST_CBLT_ADD_CTRL_ADD				0xEF0C				
#define CAEN_DGTZ_RELOCATION_ADDRESS_ADD				0xEF10				
#define CAEN_DGTZ_INT_STATUS_ID_ADD						0xEF14				
#define CAEN_DGTZ_INT_EVENT_NUM_ADD						0xEF18				
#define CAEN_DGTZ_BLT_EVENT_NUM_ADD						0xEF1C				
#define CAEN_DGTZ_SCRATCH_ADD							0xEF20				
#define CAEN_DGTZ_SW_RESET_ADD							0xEF24				
#define CAEN_DGTZ_SW_CLEAR_ADD							0xEF28				
#define CAEN_DGTZ_FLASH_EN_ADD							0xEF2C				
#define CAEN_DGTZ_FLASH_DATA_ADD						0xEF30				
#define CAEN_DGTZ_RELOAD_CONFIG_ADD						0xEF34

#define CAEN_DGTZ_ROM_CHKSUM_ADD						0xF000				
#define CAEN_DGTZ_ROM_CHKSUM_LEN_2_ADD					0xF004				
#define CAEN_DGTZ_ROM_CHKSUM_LEN_1_ADD					0xF008				
#define CAEN_DGTZ_ROM_CHKSUM_LEN_0_ADD					0xF00C				
#define CAEN_DGTZ_ROM_CONST_2_ADD						0xF010				
#define CAEN_DGTZ_ROM_CONST_1_ADD						0xF014			
#define CAEN_DGTZ_ROM_CONST_0_ADD						0xF018			
#define CAEN_DGTZ_ROM_C_CODE_ADD						0xF01C			
#define CAEN_DGTZ_ROM_R_CODE_ADD						0xF020			
#define CAEN_DGTZ_ROM_OUI_2_ADD							0xF024				
#define CAEN_DGTZ_ROM_OUI_1_ADD							0xF028			
#define CAEN_DGTZ_ROM_OUI_0_ADD							0xF02C			
#define CAEN_DGTZ_ROM_VERSION_ADD						0xF030				
#define CAEN_DGTZ_ROM_BOARD_ID_2_ADD					0xF034				
#define CAEN_DGTZ_ROM_BOARD_ID_1_ADD					0xF038			
#define CAEN_DGTZ_ROM_BOARD_ID_0_ADD					0xF03C			
#define CAEN_DGTZ_ROM_REVISION_3_ADD					0xF040			
#define CAEN_DGTZ_ROM_REVISION_2_ADD					0xF044				
#define CAEN_DGTZ_ROM_REVISION_1_ADD					0xF048				
#define CAEN_DGTZ_ROM_REVISION_0_ADD					0xF04C				
#define CAEN_DGTZ_ROM_SERIAL_1_ADD						0xF080				
#define CAEN_DGTZ_ROM_SERIAL_0_ADD						0xF084				
#define CAEN_DGTZ_ROM_VCXO_TYPE_ADD						0xF088				


// INDIVIDUAL CHANNEL ADDRESSING
#define CAEN_DGTZ_InputDCOffsetReg_Ch(x)      (0x1098 | ((x)<<8)) ///< Input DC offset adjust Register Indiv. Address 
#define CAEN_DGTZ_ChannelFWRevisionReg_Ch(x)  (0x108C | ((x)<<8)) ///< Channel FW Revision Register Indiv. Address 
#define CAEN_DGTZ_DPP1Reg_Ch(x)               (0x1024 | ((x)<<8)) ///< DPP1 Param Register Indiv. Address
#define CAEN_DGTZ_DPP2Reg_Ch(x)               (0x1028 | ((x)<<8)) ///< DPP2 Param Register Indiv. Address
#define CAEN_DGTZ_DPP3Reg_Ch(x)               (0x102C | ((x)<<8)) ///< DPP3 Param Register Indiv. Address


/*###########################################################################*/
/*
** ErrorCode
*/
/*###########################################################################*/
typedef enum CAEN_DGTZ_ErrorCode {
CAEN_DGTZ_Success						=	 0L,    /* Operation completed successfully             */
CAEN_DGTZ_CommError						=	-1L,    /* Communication error                          */
CAEN_DGTZ_GenericError					=	-2L,    /* Unspecified error                            */
CAEN_DGTZ_InvalidParam					=	-3L,    /* Invalid parameter                            */
CAEN_DGTZ_InvalidLinkType				=	-4L,    /* Invalid Link Type                            */
CAEN_DGTZ_InvalidHandle					=	-5L,    /* Invalid device handle                        */
CAEN_DGTZ_MaxDevicesError				=	-6L,    /* Maximum number of devices exceeded           */
CAEN_DGTZ_BadBoardType					=	-7L,    /* The operation is not allowed on this type of board           */
CAEN_DGTZ_BadInterruptLev				=	-8L,    /* The interrupt level is not allowed			*/
CAEN_DGTZ_BadEventNumber				=	-9L,    /* The event number is bad          				*/
CAEN_DGTZ_ReadDeviceRegisterFail		=   -10L,   /* Unable to read the registry     				*/
CAEN_DGTZ_WriteDeviceRegisterFail		=   -11L,   /* Unable to write into the registry    			*/
CAEN_DGTZ_InvalidChannelNumber			=   -13L,   /* The channel number is invalid     			*/
CAEN_DGTZ_ChannelBusy					=	-14L,   /* The Channel is busy				   			*/
CAEN_DGTZ_FPIOModeInvalid				=	-15L,   /* Invalid FPIO Mode				    			*/
CAEN_DGTZ_WrongAcqMode					=	-16L,   /* Wrong acquisition mode		    			*/
CAEN_DGTZ_FunctionNotAllowed			=	-17L,   /* This function is not allowed for this module	*/
CAEN_DGTZ_Timeout						=	-18L,   /* Communication Timeout			    			*/
CAEN_DGTZ_InvalidBuffer					=	-19L,   /* The buffer is invalid 		    			*/
CAEN_DGTZ_EventNotFound					=	-20L,   /* The event is not found		    			*/
CAEN_DGTZ_InvalidEvent					=	-21L,   /* The vent is invalid			    			*/
CAEN_DGTZ_OutOfMemory					=	-22L,   /* Out of memory					    			*/
CAEN_DGTZ_CalibrationError				=	-23L,   /* Unable to calibrate the board	    			*/
CAEN_DGTZ_DigitizerNotFound				=	-24L,   /* Unable to open the digitizer	    			*/
CAEN_DGTZ_DigitizerAlreadyOpen			=	-25L,   /* The Digitizer is already open					*/	
CAEN_DGTZ_DigitizerNotReady				=	-26L,   /* The Digitizer is not ready to operate			*/	
CAEN_DGTZ_InterruptNotConfigured		=	-27L,   /* The Digitizer has not the IRQ configured			*/
CAEN_DGTZ_DigitizerMemoryCorrupted		=	-28L,   /* The digitizer flash memory is corrupted		*/
CAEN_DGTZ_DPPFirmwareNotSupported		=	-29L,   /* The digitizer dpp firmware is not supported in this lib version */

CAEN_DGTZ_NotYetImplemented				=	-99L,   /* The function is not yet implemented			*/

}CAEN_DGTZ_ErrorCode; 

#define CAEN_DGTZ_MAX_CHANNEL			8			/*!< \brief The number of channels */


/*###########################################################################*/
/*
** ConnectionType
*/
/*###########################################################################*/

typedef enum CAEN_DGTZ_ConnectionType {
CAEN_DGTZ_USB	    				= 0L,
CAEN_DGTZ_PCI_OpticalLink			= 1L,
CAEN_DGTZ_PCIE_OpticalLink			= 2L,
CAEN_DGTZ_PCIE_EmbeddedDigitizer	= 3L,
} CAEN_DGTZ_ConnectionType;


/* Digitizers Model */
typedef enum
{
	CAEN_DGTZ_V1724			=0L,						/*!< \brief The board is V1724  */
	CAEN_DGTZ_V1721			=1L,						/*!< \brief The board is V1721  */
	CAEN_DGTZ_V1731			=2L,						/*!< \brief The board is V1731  */
	CAEN_DGTZ_V1720			=3L,						/*!< \brief The board is V1720  */
	CAEN_DGTZ_V1740			=4L,						/*!< \brief The board is V1740  */
	CAEN_DGTZ_V1751			=5L,						/*!< \brief The board is V1751  */
	CAEN_DGTZ_DT5724		=6L,					    /*!< \brief The board is DT5724 */
	CAEN_DGTZ_DT5721		=7L,					    /*!< \brief The board is DT5721 */
	CAEN_DGTZ_DT5731		=8L,					    /*!< \brief The board is DT5731 */
	CAEN_DGTZ_DT5720		=9L,					    /*!< \brief The board is DT5720 */
	CAEN_DGTZ_DT5740		=10L,					/*!< \brief The board is DT5740 */
	CAEN_DGTZ_DT5751		=11L,					/*!< \brief The board is DT5751 */
	CAEN_DGTZ_N6724		    =12L,					/*!< \brief The board is N6724  */
	CAEN_DGTZ_N6721		    =13L,					/*!< \brief The board is N6721  */
	CAEN_DGTZ_N6731		    =14L,					/*!< \brief The board is N6731  */
	CAEN_DGTZ_N6720		    =15L,					/*!< \brief The board is N6720  */
	CAEN_DGTZ_N6740		    =16L,					/*!< \brief The board is N6740  */
	CAEN_DGTZ_N6751		    =17L,					/*!< \brief The board is N6751  */
	CAEN_DGTZ_DT5742		=18L,
	CAEN_DGTZ_N6742			=19L,
	CAEN_DGTZ_V1742			=20L,
    CAEN_DGTZ_DT5780		=21L,
	CAEN_DGTZ_N6780			=22L,
	CAEN_DGTZ_V1780			=23L,
    CAEN_DGTZ_DT5761		=24L,
	CAEN_DGTZ_N6761			=25L,
	CAEN_DGTZ_V1761			=26L,
} CAEN_DGTZ_BoardModel_t;

typedef enum {
    CAEN_DGTZ_VME64_FORM_FACTOR   = 0L,
    CAEN_DGTZ_VME64X_FORM_FACTOR  = 1L,
    CAEN_DGTZ_DESKTOP_FORM_FACTOR = 2L,
    CAEN_DGTZ_NIM_FORM_FACTOR     = 3L,
} CAEN_DGTZ_BoardFormFactor_t;

typedef enum {
    CAEN_DGTZ_XX724_FAMILY_CODE  = 0L,
    CAEN_DGTZ_XX721_FAMILY_CODE  = 1L,
    CAEN_DGTZ_XX731_FAMILY_CODE  = 2L,
    CAEN_DGTZ_XX720_FAMILY_CODE  = 3L,
    CAEN_DGTZ_XX740_FAMILY_CODE  = 4L,
    CAEN_DGTZ_XX751_FAMILY_CODE  = 5L,
    CAEN_DGTZ_XX742_FAMILY_CODE  = 6L, 
    CAEN_DGTZ_XX780_FAMILY_CODE  = 7L,
    CAEN_DGTZ_XX761_FAMILY_CODE  = 8L,
} CAEN_DGTZ_BoardFamilyCode_t;

typedef enum CAEN_DGTZ_DPP_PARAMETER
{
	CAEN_DGTZ_DPP_Param_m				= 0L,
	CAEN_DGTZ_DPP_Param_M				= 1L,
	CAEN_DGTZ_DPP_Param_Delta1			= 2L,
	CAEN_DGTZ_DPP_Param_a				= 3L,
	CAEN_DGTZ_DPP_Param_b				= 4L,
	CAEN_DGTZ_DPP_Param_NSBaseline		= 5L,
	CAEN_DGTZ_DPP_Param_shf				= 6L,
	CAEN_DGTZ_DPP_Param_k				= 7L,
	CAEN_DGTZ_DPP_Param_NSPeakMean		= 8L,
	CAEN_DGTZ_DPP_Param_FlatTopDelay	= 9L,
	CAEN_DGTZ_DPP_Param_Decimation		= 10L,
	CAEN_DGTZ_DPP_Param_TrgThreshold	= 11L,
	CAEN_DGTZ_DPP_Param_TrgWinOffset	= 12L,
	CAEN_DGTZ_DPP_Param_TrgWinWidth		= 13L,
	CAEN_DGTZ_DPP_Param_DigitalGain		= 14L,
	CAEN_DGTZ_DPP_Param_GateWidth		= 15L,
	CAEN_DGTZ_DPP_Param_PreGate			= 16L,
	CAEN_DGTZ_DPP_Param_HoldOffTime		= 17L,
	CAEN_DGTZ_DPP_Param_BslThreshold	= 18L,
	CAEN_DGTZ_DPP_Param_NoFlatTime		= 19L,
	CAEN_DGTZ_DPP_Param_GateMode		= 20L,
	CAEN_DGTZ_DPP_Param_InvertInput		= 21L,
} CAEN_DGTZ_DPP_PARAMETER_t;

typedef enum
{
	CAEN_DGTZ_FPIO_MODES_GPIO			= 0L,			/*!< General purpose IO */
	CAEN_DGTZ_FPIO_MODES_PROGIO			= 1L,			/*!< Programmed IO */
	CAEN_DGTZ_FPIO_MODES_PATTERN		= 2L,			/*!< Pattern mode */
} CAEN_DGTZ_FrontPanelIOModes;

typedef enum
{
	CAEN_DGTZ_TRGMODE_DISABLED				= 0L,
	CAEN_DGTZ_TRGMODE_EXTOUT_ONLY			= 2L,
	CAEN_DGTZ_TRGMODE_ACQ_ONLY				= 1L,
	CAEN_DGTZ_TRGMODE_ACQ_AND_EXTOUT		= 3L,
}CAEN_DGTZ_TriggerMode_t;

typedef enum {
	CAEN_DGTZ_TRIGGER					 = 0L,
	CAEN_DGTZ_FASTTRG_ALL				 = 1L,
	CAEN_DGTZ_FASTTRG_ACCEPTED	 		 = 2L,
	CAEN_DGTZ_BUSY					     = 3L,
	CAEN_DGTZ_CLK_OUT					 = 4L,
	CAEN_DGTZ_RUN					     = 5L,
	CAEN_DGTZ_TRGPULSE					 = 6L,	
	CAEN_DGTZ_OVERTHRESHOLD		         = 7L,					
} CAEN_DGTZ_OutputSignalMode_t;

typedef enum
{
	CAEN_DGTZ_ZS_NO						= 0L,
	CAEN_DGTZ_ZS_INT					= 1L,
	CAEN_DGTZ_ZS_ZLE					= 2L,
	CAEN_DGTZ_ZS_AMP					= 3L,
} CAEN_DGTZ_ZS_Mode_t;

typedef enum
{
	CAEN_DGTZ_ENABLE					= 1L,
	CAEN_DGTZ_DISABLE					= 0L,
} CAEN_DGTZ_EnaDis_t;

typedef enum 
{
	CAEN_DGTZ_ZS_FINE					= 0L,
	CAEN_DGTZ_ZS_COARSE					= 1L,
}CAEN_DGTZ_ThresholdWeight_t;			


typedef enum
{
	CAEN_DGTZ_SW_CONTROLLED				= 0L,
	CAEN_DGTZ_S_IN_CONTROLLED			= 1L,
}CAEN_DGTZ_AcqMode_t;

typedef enum
{
	CAEN_DGTZ_AM_TRIGGER_MAJORITY		= 0L,
	CAEN_DGTZ_AM_TEST					= 1L,
	CAEN_DGTZ_AM_ANALOG_INSPECTION		= 2L,
	CAEN_DGTZ_AM_BUFFER_OCCUPANCY		= 3L,
	CAEN_DGTZ_AM_VOLTAGE_LEVEL			= 4L,
}CAEN_DGTZ_AnalogMonitorOutputMode_t;

typedef enum 
{
	CAEN_DGTZ_AM_MAGNIFY_1X				= 0L,
	CAEN_DGTZ_AM_MAGNIFY_2X				= 1L,
	CAEN_DGTZ_AM_MAGNIFY_4X				= 2L,
	CAEN_DGTZ_AM_MAGNIFY_8X				= 3L,
}CAEN_DGTZ_AnalogMonitorMagnify_t;			


typedef enum 
{
	CAEN_DGTZ_AM_INSPECTORINVERTER_P_1X	 = 0L,
	CAEN_DGTZ_AM_INSPECTORINVERTER_N_1X  = 1L,
}CAEN_DGTZ_AnalogMonitorInspectorInverter_t;

typedef enum 
{
	CAEN_DGTZ_IRQ_MODE_RORA				 = 0L,
	CAEN_DGTZ_IRQ_MODE_ROAK				 = 1L,
}CAEN_DGTZ_IRQMode_t;

typedef enum
{
	CAEN_DGTZ_IRQ_DISABLED				= 0L,
	CAEN_DGTZ_IRQ_ENABLED_OPTICAL		= 1L,
	CAEN_DGTZ_IRQ_ENABLED_VME_RORA		= 1L,
	CAEN_DGTZ_IRQ_ENABLED_VME_ROAK		= 2L,
} CAEN_DGTZ_IRQState_t;

typedef enum 
{
	CAEN_DGTZ_SLAVE_TERMINATED_READOUT_MBLT		= 0L,
	CAEN_DGTZ_SLAVE_TERMINATED_READOUT_2eVME 	= 1L,
	CAEN_DGTZ_SLAVE_TERMINATED_READOUT_2eSST 	= 2L,
	CAEN_DGTZ_POLLING_MBLT					 	= 3L,
	CAEN_DGTZ_POLLING_2eVME						= 4L,
	CAEN_DGTZ_POLLING_2eSST						= 5L,
} CAEN_DGTZ_ReadMode_t;

typedef enum
{
	CAEN_DGTZ_DPP_ACQ_MODE_Oscilloscope			= 0L,
	CAEN_DGTZ_DPP_ACQ_MODE_List					= 1L,
	CAEN_DGTZ_DPP_ACQ_MODE_Mixed				= 2L,
} CAEN_DGTZ_DPP_AcqMode_t;

typedef enum
{
	CAEN_DGTZ_DPP_CI_GPO_Gate				= 0L,
	CAEN_DGTZ_DPP_CI_GPO_Discri				= 1L,
	CAEN_DGTZ_DPP_CI_GPO_Coincidence		= 2L,
} CAEN_DGTZ_DPP_CI_GPO_SEL_t;

typedef enum {
	CAEN_DGTZ_DPP_Channel_0					= 0L,
	CAEN_DGTZ_DPP_Channel_1					= 1L,
	CAEN_DGTZ_DPP_Channel_2					= 2L,
	CAEN_DGTZ_DPP_Channel_3					= 3L,
	CAEN_DGTZ_DPP_Channel_4					= 4L,
	CAEN_DGTZ_DPP_Channel_5					= 5L,
	CAEN_DGTZ_DPP_Channel_6					= 6L,
	CAEN_DGTZ_DPP_Channel_7					= 7L,
	CAEN_DGTZ_DPP_Channel_ALL				= 255L,
} CAEN_DGTZ_DPP_Channel_t;

/*! 
 * \brief Defines whether to include an additional virtual analog probe in the readout data
 *        at the cost of halving the resolution of the first
 */
typedef enum
{
	CAEN_DGTZ_DPP_VIRTUALPROBE_SINGLE		= 0L,
	CAEN_DGTZ_DPP_VIRTUALPROBE_DUAL			= 1L,
} CAEN_DGTZ_DPP_VirtualProbe_t;

/*! 
 * \brief Defines the digital signals that can be carried by the digital probe
 *        in the readout data of the DPP-PHA
 */
typedef enum
{
	CAEN_DGTZ_DPP_PHA_DIGITAL_PROBE_trgKln		= 0L,
	CAEN_DGTZ_DPP_PHA_DIGITAL_PROBE_Armed		= 1L,
	CAEN_DGTZ_DPP_PHA_DIGITAL_PROBE_PkRun		= 2L,
	CAEN_DGTZ_DPP_PHA_DIGITAL_PROBE_PkAbort		= 3L,
	CAEN_DGTZ_DPP_PHA_DIGITAL_PROBE_Peaking		= 4L,
	CAEN_DGTZ_DPP_PHA_DIGITAL_PROBE_PkHoldOff	= 5L,
	CAEN_DGTZ_DPP_PHA_DIGITAL_PROBE_Flat		= 6L,
	CAEN_DGTZ_DPP_PHA_DIGITAL_PROBE_trgHoldOff	= 7L,
} CAEN_DGTZ_DPP_PHA_DigitalProbe_t;

/*! 
 * \brief Defines the signals that can be carried by the virtual analog probe 1
 *        in the readout data of the DPP-PHA
 */
typedef enum
{
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE1_Input		= 0L,
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE1_Delta		= 1L,
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE1_Delta2		= 2L,
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE1_trapezoid	= 3L,
} CAEN_DGTZ_DPP_PHA_VirtualProbe1_t;
  
/*! 
 * \brief Defines the signals that can be carried by the virtual analog probe 2
 *        in the readout data of the DPP-PHA
 */
typedef enum
{
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE2_Input		= 0L,
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE2_S3			= 1L,
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE2_DigitalCombo	= 2L,
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE2_trapBaseline	= 3L,
	CAEN_DGTZ_DPP_PHA_VIRTUALPROBE2_None			= 4L,
} CAEN_DGTZ_DPP_PHA_VirtualProbe2_t;


/*! 
 * \brief Defines the signals that can be carried by the virtual analog probe
 *        in the readout data of the DPP-CI version 2
 */
typedef enum
{
	CAEN_DGTZ_DPP_CI_VIRTUALPROBE_Baseline = 0L,
} CAEN_DGTZ_DPP_CI_VirtualProbe_t;

/*! 
 * \brief Defines the signals that can be carried by the digital probe 1
 *        in the readout data of the DPP-CI version 2
 */
typedef enum
{
	CAEN_DGTZ_DPP_CI_DIGITALPROBE1_BlOutSafeBand	= 0L,
	CAEN_DGTZ_DPP_CI_DIGITALPROBE1_BlTimeout		= 1L,
	CAEN_DGTZ_DPP_CI_DIGITALPROBE1_CoincidenceMet	= 2L,
	CAEN_DGTZ_DPP_CI_DIGITALPROBE1_Tvaw			= 3L,
} CAEN_DGTZ_DPP_CI_DigitalProbe1_t;

/*! 
 * \brief Defines the signals that can be carried by the digital probe 2
 *        in the readout data of the DPP-CI version 2
 */
typedef enum
{
	CAEN_DGTZ_DPP_CI_DIGITALPROBE2_BlOutSafeBand	= 0L,
	CAEN_DGTZ_DPP_CI_DIGITALPROBE2_BlTimeout		= 1L,
	CAEN_DGTZ_DPP_CI_DIGITALPROBE2_CoincidenceMet	= 2L,
	CAEN_DGTZ_DPP_CI_DIGITALPROBE2_Tvaw			= 3L,
} CAEN_DGTZ_DPP_CI_DigitalProbe2_t;

/*! 
 * \brief Defines the signals that can be carried by the virtual analog probe
 *        in the readout data of the DPP-PSD
 */
typedef enum
{
	CAEN_DGTZ_DPP_PSD_VIRTUALPROBE_Baseline		= 0L,
	CAEN_DGTZ_DPP_PSD_VIRTUALPROBE_Threshold	= 1L,
} CAEN_DGTZ_DPP_PSD_VirtualProbe_t;

/*! 
 * \brief Defines the signals that can be carried by the digital probe 1
 *        in the readout data of the DPP-PSD
 */
typedef enum
{
    /* x720 Digital Probes Types */
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_Armed			= 0L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_Trigger			= 1L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_ChargeReady		= 2L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_PileUp			= 3L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_BlOutSafeBand	= 4L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_BlTimeout		= 5L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_CoincidenceMet	= 6L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_Tvaw			= 7L,

    /* x751 Digital Probes Types */
    CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_OverThr		    = 8L,
    CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_GateShort		= 9L,
    CAEN_DGTZ_DPP_PSD_DIGITALPROBE1_None            = 10L
} CAEN_DGTZ_DPP_PSD_DigitalProbe1_t;

/*! 
 * \brief Defines the signals that can be carried by the digital probe 2
 *        in the readout data of the DPP-PSD
 */
typedef enum
{
    /* x720 Digital Probes Types */
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_Armed			= 0L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_Trigger			= 1L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_ChargeReady		= 2L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_PileUp			= 3L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_BlOutSafeBand	= 4L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_BlTimeout		= 5L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_CoincidenceMet	= 6L,
	CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_Tvaw			= 7L,

    /* x751 Digital Probes Types */
    CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_GateShort		= 8L,
    CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_GateLong		= 9L,
    CAEN_DGTZ_DPP_PSD_DIGITALPROBE2_None            = 10L
} CAEN_DGTZ_DPP_PSD_DigitalProbe2_t;

/*! 
 * \brief Defines the kind of histogram data returned in readout data
 */
typedef enum
{
	CAEN_DGTZ_DPP_SAVE_PARAM_EnergyOnly		= 0L, /*!< Only energy (DPP-PHA) or charge (DPP-PSD/DPP-CI v2) is returned */
	CAEN_DGTZ_DPP_SAVE_PARAM_TimeOnly		= 1L, /*!< Only time is returned */
	CAEN_DGTZ_DPP_SAVE_PARAM_EnergyAndTime	= 2L, /*!< Both energy/charge and time are returned */
	CAEN_DGTZ_DPP_SAVE_PARAM_ChargeAndTime  = 4L, /*!< \deprecated On DPP-PSD and DPP-CI use CAEN_DGTZ_DPP_SAVE_PARAM_EnergyAndTime */
	CAEN_DGTZ_DPP_SAVE_PARAM_None			= 3L, /*!< No histogram data is returned */
} CAEN_DGTZ_DPP_SaveParam_t;

typedef enum {
	CAEN_DGTZ_IOLevel_NIM		= 0L,
	CAEN_DGTZ_IOLevel_TTL		= 1L,
} CAEN_DGTZ_IOLevel_t;

typedef enum {
	CAEN_DGTZ_DRS4_5GHz		= 0L,
	CAEN_DGTZ_DRS4_2_5GHz	= 1L,
	CAEN_DGTZ_DRS4_1GHz		= 2L,
	_CAEN_DGTZ_DRS4_COUNT_  = 3L,
} CAEN_DGTZ_DRS4Frequency_t;

/*! 
 * \brief Defines the available synchronization modes to be set with CAEN_DGTZ_SetDPPRunSynchronizationMode
 */
typedef enum {
	CAEN_DGTZ_RUN_SYNC_Disabled,
	CAEN_DGTZ_RUN_SYNC_TrgOutTrgInDaisyChain,
	CAEN_DGTZ_RUN_SYNC_TrgOutSinDaisyChain,
	CAEN_DGTZ_RUN_SYNC_SinFanout,
	CAEN_DGTZ_RUN_SYNC_GpioGpioDaisyChain
} CAEN_DGTZ_RunSyncMode_t;


typedef enum {
	CAEN_DGTZ_TriggerOnRisingEdge		= 0L,
	CAEN_DGTZ_TriggerOnFallingEdge		= 1L,
} CAEN_DGTZ_TriggerPolarity_t;

typedef enum {
	CAEN_DGTZ_PulsePolarityPositive		= 0,
	CAEN_DGTZ_PulsePolarityNegative		= 1,
} CAEN_DGTZ_PulsePolarity_t;

typedef struct {
	char						ModelName[12];
	uint32_t					Model;
	uint32_t					Channels;
	uint32_t					FormFactor;
	uint32_t					FamilyCode;
	char						ROC_FirmwareRel[20];
	char						AMC_FirmwareRel[40];
	uint32_t					SerialNumber;
	uint32_t					PCB_Revision;
	uint32_t					ADC_NBits;
} CAEN_DGTZ_BoardInfo_t;

typedef struct 
{
	uint32_t			 EventSize;
	uint32_t			 BoardId;
	uint32_t			 Pattern;
	uint32_t			 ChannelMask;
	uint32_t			 EventCounter;
	uint32_t			 TriggerTimeTag;
} CAEN_DGTZ_EventInfo_t;

typedef struct 
{
	uint32_t				 ChSize[MAX_X742_CHANNEL_SIZE]; 		  // the number of samples stored in DataChannel array  
	float					 *DataChannel[MAX_X742_CHANNEL_SIZE];  // the array of ChSize samples
	uint32_t				 TriggerTimeTag;
	uint16_t				 StartIndexCell;
} CAEN_DGTZ_X742_GROUP_t;

typedef struct 
{
	uint32_t			ChSize[MAX_UINT16_CHANNEL_SIZE]; // the number of samples stored in DataChannel array  
	uint16_t			*DataChannel[MAX_UINT16_CHANNEL_SIZE]; // the array of ChSize samples
} CAEN_DGTZ_UINT16_EVENT_t;

typedef struct 
{
	uint32_t			ChSize[MAX_UINT8_CHANNEL_SIZE]; // the number of samples stored in DataChannel array  
	uint8_t				*DataChannel[MAX_UINT8_CHANNEL_SIZE];  // the array of ChSize samples
} CAEN_DGTZ_UINT8_EVENT_t;

typedef struct 
{
	uint8_t					GrPresent[MAX_X742_GROUP_SIZE]; // If the group has data the value is 1 otherwise is 0  
	CAEN_DGTZ_X742_GROUP_t	DataGroup[MAX_X742_GROUP_SIZE]; // the array of ChSize samples
} CAEN_DGTZ_X742_EVENT_t;


/*! 
 * \brief Event type for DPP-PHA to be used within the <b>new readout API</b>
 */
typedef struct 
{
    uint32_t Format;
    uint64_t TimeTag;
    uint16_t Energy;
    int16_t Extras;
    uint32_t *Waveforms; /*!< pointer to coded data inside the readout buffer. only meant to be supplied to CAEN_DGTZ_DecodeDPPWaveforms */ 

} CAEN_DGTZ_DPP_PHA_Event_t;

/*! 
 * \brief Event type for DPP-PSD to be used within the <b>new readout API</b>
 */
typedef struct 
{
    uint32_t Format;
    uint32_t TimeTag;
	int16_t ChargeShort;
	int16_t ChargeLong;
    int16_t Baseline;
	int16_t Pur;
    uint32_t *Waveforms; /*!< pointer to coded data inside the readout buffer. only meant to be supplied to CAEN_DGTZ_DecodeDPPWaveforms */ 
} CAEN_DGTZ_DPP_PSD_Event_t;

/*! 
 * \brief Event type for DPP-CI v2 to be used within the <b>new readout API</b>
 */
typedef struct 
{
    uint32_t Format;
    uint32_t TimeTag;
    int16_t Charge;
    int16_t Baseline;
    uint32_t *Waveforms; /*!< pointer to coded data inside the readout buffer. only meant to be supplied to CAEN_DGTZ_DecodeDPPWaveforms */ 
} CAEN_DGTZ_DPP_CI_Event_t;

/*! 
 * \brief Waveform type for DPP-PHA to be used within the <b>new readout API</b>
 */
typedef struct 
{
    uint32_t Ns;
    uint8_t  DualTrace;
    uint8_t  VProbe1;
    uint8_t  VProbe2;
    uint8_t  VDProbe;
    int16_t *Trace1;
    int16_t *Trace2;
    uint8_t  *DTrace1;
    uint8_t  *DTrace2;
} CAEN_DGTZ_DPP_PHA_Waveforms_t;

/*! 
 * \brief Waveform type for DPP-PSD to be used within the <b>new readout API</b>
 */
typedef struct
{
    uint32_t Ns;
    uint8_t  dualTrace;
    uint8_t  anlgProbe;
    uint8_t  dgtProbe1;
	uint8_t  dgtProbe2;
    uint16_t *Trace1;
    uint16_t *Trace2;
    uint8_t  *DTrace1;
    uint8_t  *DTrace2;
	uint8_t  *DTrace3;
    uint8_t  *DTrace4;
} CAEN_DGTZ_DPP_PSD_Waveforms_t;

#define CAEN_DGTZ_DPP_CI_Waveforms_t CAEN_DGTZ_DPP_PSD_Waveforms_t /*!< \brief Waveform types for DPP-CI and DPP-PSD are the same, hence this define */

#define CAEN_DGTZ_AutoAggregation 0

/*! 
 * \brief Defines the Pile Up Rejection method
 * \note Only for DPP-PSD and DPP-CI version 2
 */
typedef enum
{
	CAEN_DGTZ_DPP_PSD_PUR_DetectOnly, /*!< Only detect pile-up events by setting the Pur field in the readout data (CAEN_DGTZ_DPP_PSD_Event_t) */
	CAEN_DGTZ_DPP_PSD_PUR_Enabled /*!< Reject pile-up events. They won't be read out */
} CAEN_DGTZ_DPP_PUR_t;
#define CAEN_DGTZ_DPP_CI_PUR_DetectOnly CAEN_DGTZ_DPP_PSD_PUR_DetectOnly /*!< \brief PileUp Rejection types for DPP-CI and DPP-PSD are the same, hence this define */
#define CAEN_DGTZ_DPP_CI_PUR_Enabled CAEN_DGTZ_DPP_PSD_PUR_Enabled /*!< \brief PileUp Rejection types for DPP-CI and DPP-PSD are the same, hence this define */

/*! 
 * \brief Defines the trigger mode to be set with CAEN_DGTZ_SetDPPTriggerMode
 * \note Only for DPP-PSD and DPP-CI version 2
 */
typedef enum
{
	CAEN_DGTZ_DPP_TriggerMode_Normal,
	CAEN_DGTZ_DPP_TriggerMode_Coincidence
} CAEN_DGTZ_DPP_TriggerMode_t;

/*! 
 * \brief Defines the trigger configuration to be set with CAEN_DGTZ_SetDPPTriggerConfig
 * \note Only for DPP-PSD and DPP-CI version 2
 */
typedef enum
{
	CAEN_DGTZ_DPP_TriggerConfig_Peak,
	CAEN_DGTZ_DPP_TriggerConfig_Threshold
} CAEN_DGTZ_DPP_TriggerConfig_t;


typedef enum 
{
	CAEN_DGTZ_DPPFirmware_PHA,
	CAEN_DGTZ_DPPFirmware_PSD,
	CAEN_DGTZ_DPPFirmware_CI,
	CAEN_DGTZ_NotDPPFirmware = -1
} CAEN_DGTZ_DPPFirmware_t;

/*! 
 * \brief DPP parameter structure to be initialized and passed to CAEN_DGTZ_SetDPPParameters
 * \note1 Only for DPP-PHA
 */
typedef struct
{
	int M		  [MAX_V1724DPP_CHANNEL_SIZE]; // Signal Decay Time Constant
	int m		  [MAX_V1724DPP_CHANNEL_SIZE]; // Trapezoid Flat Top
	int k		  [MAX_V1724DPP_CHANNEL_SIZE]; // Trapezoid Rise Time
	int ftd		  [MAX_V1724DPP_CHANNEL_SIZE]; //
	int a		  [MAX_V1724DPP_CHANNEL_SIZE]; // Trigger Filter smoothing factor
	int b		  [MAX_V1724DPP_CHANNEL_SIZE]; // Input Signal Rise time
	int thr		  [MAX_V1724DPP_CHANNEL_SIZE]; // Trigger Threshold
	int nsbl	  [MAX_V1724DPP_CHANNEL_SIZE]; // Number of Samples for Baseline Mean
	int nspk	  [MAX_V1724DPP_CHANNEL_SIZE]; // Number of Samples for Peak Mean Calculation
	int pkho	  [MAX_V1724DPP_CHANNEL_SIZE]; // Peak Hold Off
	int blho	  [MAX_V1724DPP_CHANNEL_SIZE]; // Base Line Hold Off
    int otrej	  [MAX_V1724DPP_CHANNEL_SIZE]; // 
    int trgho	  [MAX_V1724DPP_CHANNEL_SIZE]; // Trigger Hold Off
    int twwdt	  [MAX_V1724DPP_CHANNEL_SIZE]; // 
    int trgwin	  [MAX_V1724DPP_CHANNEL_SIZE]; //
	int dgain	  [MAX_V1724DPP_CHANNEL_SIZE]; // Digital Probe Gain
	float enf	  [MAX_V1724DPP_CHANNEL_SIZE]; // Energy Nomralization Factor
	int decimation[MAX_V1724DPP_CHANNEL_SIZE]; // Decimation of Input Signal
} CAEN_DGTZ_DPP_PHA_Params_t;

/*! 
 * \brief DPP parameter structure to be initialized and passed to CAEN_DGTZ_SetDPPParameters
 * \note Only for DPP-PSD
 */
typedef struct {
	int blthr;
	int bltmo;
	int thr		[MAX_V1720DPP_CHANNEL_SIZE];
	int selft	[MAX_V1720DPP_CHANNEL_SIZE];
	int csens	[MAX_V1720DPP_CHANNEL_SIZE];
	int sgate	[MAX_V1720DPP_CHANNEL_SIZE];
	int lgate	[MAX_V1720DPP_CHANNEL_SIZE];
	int pgate	[MAX_V1720DPP_CHANNEL_SIZE];
	int tvaw	[MAX_V1720DPP_CHANNEL_SIZE];
	int nsbl	[MAX_V1720DPP_CHANNEL_SIZE];
	CAEN_DGTZ_DPP_TriggerConfig_t trgc // Ignored for x751
				[MAX_V1720DPP_CHANNEL_SIZE];
	CAEN_DGTZ_DPP_PUR_t purh; // Ignored for x751
	int purgap; // Ignored for x751
} CAEN_DGTZ_DPP_PSD_Params_t;


/*! 
 * \brief DPP parameter structure to be initialized and passed to CAEN_DGTZ_SetDPPParameters
 * \note Only for DPP-CI version 2
 */
typedef struct {
	int blthr;
	int bltmo;
	int thr		[MAX_V1720DPP_CHANNEL_SIZE];
	int selft	[MAX_V1720DPP_CHANNEL_SIZE];
    int csens	[MAX_V1720DPP_CHANNEL_SIZE];
	int gate	[MAX_V1720DPP_CHANNEL_SIZE];
	int pgate	[MAX_V1720DPP_CHANNEL_SIZE];
	int tvaw	[MAX_V1720DPP_CHANNEL_SIZE];
	int nsbl	[MAX_V1720DPP_CHANNEL_SIZE];
	CAEN_DGTZ_DPP_TriggerConfig_t trgc
				[MAX_V1720DPP_CHANNEL_SIZE];
} CAEN_DGTZ_DPP_CI_Params_t;


#endif

