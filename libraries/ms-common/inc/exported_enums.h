#pragma once

// This file stores enums which are exported between projects to allow both
// sides to use the same enums when sending and receiving CAN Messages over the
// primary network. To make things easier all enums in this file must follow a
// slightly modified naming convention.
//
// Example:
// typedef enum {
//   EE_<MY_CAN_MESSAGE_NAME>_<FIELD_NAME>_<VALUE> = 0,
//   // ...
//   NUM_EE_<MY_CAN_MESSAGE_NAME>_<FIELD_NAME>_<PLURAL>,
// } EE<MyCanMessageName><FieldName>


// STEERING SIGNALS 
// Signals for analog inputs received at the steering board
typedef enum SteeringInfoAnalog {
	EE_STEERING_INFO_LIGHTS_OFF = 0, // Turn lights off
	EE_STEERING_LIGHTS_RIGHT, // Right Turn Signal
	EE_STEERING_LIGHTS_LEFT, // Left Turn Signal
	NUM_EE_STEERING_LIGHTS,
} SteeringInfoAnalog;

// Signals for digital inputs received at the steering board
typedef enum SteeringInfoDigitalMask {
	EE_STEERING_CC_DECREASE_MASK = 0, // Signal to decrease cruise control speed
	EE_STEERING_CC_INCREASE_MASK,     // Signal to increase cruise control speed
	EE_STEERING_DIGITAL_SIGNAL_CC_TOGGLE_MASK, // Toggle cruise control on/off
  EE_STEERING_HORN_MASK,   // Horn Pressed Event
} SteeringInfoDigitalMask;

// CENTRE CONSOLE SIGNALS
// Drive Output
typedef enum {
  EE_DRIVE_OUTPUT_CC_STATE_OFF = 0, // Cruise control enabled,
  EE_DRIVE_OUTPUT_CC_STATE_ON, // Cruise control disabled
  NUM_EE_DRIVE_OUTPUT_CC_STATES,
} CentreConsoleCCState; 

typedef enum {
  EE_DRIVE_OUTPUT_REGEN_STATE_OFF = 0, // Regen Braking enabled,
  EE_DRIVE_OUTPUT_REGEN_STATE_ON, // Regen Braking disabled
  NUM_EE_DRIVE_OUTPUT_REGEN_STATES,
} CentreConsoleRegenState; 

typedef enum {
  EE_DRIVE_OUTPUT_STATE_NEUTRAL = 0,
  EE_DRIVE_OUTPUT_STATE_DRIVE,
  EE_DRIVE_OUTPUT_STATE_REVERSE,
  NUM_EE_DRIVE_OUTPUT_STATES,
} CentreConsoleDriveState;

typedef enum {
  EE_DRIVE_FSM_BEGIN_PRECHARGE_OFF = 0, // Begin precharge signal off
  EE_DRIVE_FSM_BEGIN_PRECHARGE_ON, // Begin precharge signal on
  NUM_DRIVE_FSM_BEGIN_PRECHARGE_STATES,
} CentreConsoleBeginPrechargeState; 


// Signal used by drive fsm
typedef enum {
  EE_DRIVE_FSM_BEGIN_PRECHARGE_OFF = 0, // Begin precharge signal off
  EE_DRIVE_FSM_BEGIN_PRECHARGE_ON, // Begin precharge signal on
  NUM_DRIVE_FSM_BEGIN_PRECHARGE_STATES,
} CentreConsoleBeginPrechargeState; 

// POWER SELECT SIGNALS
typedef enum {
  EE_PWR_SEL_STATUS_PWR_SUPPLY_MASK = 0, // Mask for bit indicating power supply status
  EE_PWR_SEL_STATUS_DCDC_MASK, // Mask for bit indicating dcdc status
  EE_PWR_SEL_STATUS_AUX_MASK, // Mask for bit indicating aux status
  NUM_EE_PWR_SEL_STATUS_MASKS, 
} PowerSelectStatusMasks;

typedef enum {
  EE_PWR_SEL_FAULT_PWR_SUPPLY_OVERCURRENT_MASK = 0, 
  EE_PWR_SEL_FAULT_PWR_SUPPY_OVERVOLTAGE_MASK,
  EE_PWR_SEL_FAULT_DCDC_OVERTEMP_MASK,
  EE_PWR_SEL_FAULT_DCDC_OVERCURRENT_MASK,
  EE_PWR_SEL_FAULT_DCDC_OVERVOLTAGE_MASK,
  EE_PWR_SEL_FAULT_AUX_OVERTEMP_MASK,
  EE_PWR_SEL_FAULT_AUX_OVERCURRENT_MASK,
  EE_PWR_SEL_FAULT_AUX_OVERVOLTAGE_MASK,
} PowerSelectFaultMasks;

// BMS SIGNALS

// SOLAR SENSE SIGNALS

