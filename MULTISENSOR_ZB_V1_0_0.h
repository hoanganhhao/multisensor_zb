// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// Enclosing macro to prevent multiple inclusion
#ifndef SILABS_ZNET_CONFIG
#define SILABS_ZNET_CONFIG


/**** Included Header Section ****/



// Networks
#define EM_AF_GENERATED_NETWORK_TYPES { \
  EM_AF_NETWORK_TYPE_ZIGBEE_PRO, /* Primary */ \
}
#define EM_AF_GENERATED_ZIGBEE_PRO_NETWORKS { \
  { \
    /* Primary */ \
    ZA_ROUTER, \
    EMBER_AF_SECURITY_PROFILE_Z3, \
  }, \
}
#define EM_AF_GENERATED_NETWORK_STRINGS  \
  "Primary (pro)", \
/**** ZCL Section ****/
#define ZA_PROMPT "MULTISENSOR_ZB_V1_0_0"
#define ZCL_USING_BASIC_CLUSTER_SERVER
#define ZCL_USING_IDENTIFY_CLUSTER_SERVER
#define ZCL_USING_GROUPS_CLUSTER_SERVER
#define ZCL_USING_SCENES_CLUSTER_SERVER
#define ZCL_USING_ON_OFF_CLUSTER_SERVER
#define ZCL_USING_LEVEL_CONTROL_CLUSTER_SERVER
/**** Optional Attributes ****/
#define ZCL_USING_BASIC_CLUSTER_APPLICATION_VERSION_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_STACK_VERSION_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_HW_VERSION_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_MANUFACTURER_NAME_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_MODEL_IDENTIFIER_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_DATE_CODE_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_GENERIC_DEVICE_CLASS_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_GENERIC_DEVICE_TYPE_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_PRODUCT_CODE_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_PRODUCT_URL_ATTRIBUTE 
#define ZCL_USING_BASIC_CLUSTER_SW_BUILD_ID_ATTRIBUTE 
#define ZCL_USING_ON_OFF_CLUSTER_GLOBAL_SCENE_CONTROL_ATTRIBUTE 
#define ZCL_USING_ON_OFF_CLUSTER_ON_TIME_ATTRIBUTE 
#define ZCL_USING_ON_OFF_CLUSTER_OFF_WAIT_TIME_ATTRIBUTE 
#define ZCL_USING_ON_OFF_CLUSTER_START_UP_ON_OFF_ATTRIBUTE 
#define ZCL_USING_LEVEL_CONTROL_CLUSTER_LEVEL_CONTROL_REMAINING_TIME_ATTRIBUTE 
#define ZCL_USING_LEVEL_CONTROL_CLUSTER_OPTIONS_ATTRIBUTE 
#define ZCL_USING_LEVEL_CONTROL_CLUSTER_START_UP_CURRENT_LEVEL_ATTRIBUTE 
#define EMBER_AF_MANUFACTURER_CODE 0x1002
#define EMBER_AF_DEFAULT_RESPONSE_POLICY_ALWAYS

/**** Cluster endpoint counts ****/
#define EMBER_AF_BASIC_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_IDENTIFY_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_GROUPS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_SCENES_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_ON_OFF_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_LEVEL_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT (1)

/**** Cluster Endpoint Summaries ****/
#define EMBER_AF_MAX_SERVER_CLUSTER_COUNT (6)
#define EMBER_AF_MAX_CLIENT_CLUSTER_COUNT (0)
#define EMBER_AF_MAX_TOTAL_CLUSTER_COUNT (6)

/**** CLI Section ****/
#define EMBER_AF_GENERATE_CLI

/**** Security Section ****/
#define EMBER_AF_HAS_SECURITY_PROFILE_Z3

/**** Network Section ****/
#define EMBER_SUPPORTED_NETWORKS (1)
#define EMBER_AF_NETWORK_INDEX_PRIMARY (0)
#define EMBER_AF_DEFAULT_NETWORK_INDEX EMBER_AF_NETWORK_INDEX_PRIMARY
#define EMBER_AF_HAS_ROUTER_NETWORK
#define EMBER_AF_HAS_RX_ON_WHEN_IDLE_NETWORK
#define EMBER_AF_TX_POWER_MODE EMBER_TX_POWER_MODE_USE_TOKEN

/**** Callback Section ****/
#define EMBER_CALLBACK_MAIN_INIT
#define EMBER_CALLBACK_STACK_STATUS
#define EMBER_CALLBACK_ON_OFF_CLUSTER_ON_OFF_CLUSTER_SERVER_ATTRIBUTE_CHANGED
#define EMBER_CALLBACK_HAL_BUTTON_ISR
#define EMBER_CALLBACK_ENERGY_SCAN_RESULT
#define EMBER_CALLBACK_SCAN_COMPLETE
#define EMBER_CALLBACK_NETWORK_FOUND
#define EMBER_CALLBACK_SCENES_CLUSTER_SCENES_CLUSTER_SERVER_INIT
#define EMBER_CALLBACK_SCENES_CLUSTER_ADD_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_VIEW_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_REMOVE_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_REMOVE_ALL_SCENES
#define EMBER_CALLBACK_SCENES_CLUSTER_STORE_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_RECALL_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_GET_SCENE_MEMBERSHIP
#define EMBER_CALLBACK_SCENES_CLUSTER_STORE_CURRENT_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_RECALL_SAVED_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_CLEAR_SCENE_TABLE
#define EMBER_CALLBACK_SCENES_CLUSTER_SCENES_CLUSTER_MAKE_INVALID
#define EMBER_CALLBACK_SCENES_CLUSTER_REMOVE_SCENES_IN_GROUP
#define EMBER_CALLBACK_GROUPS_CLUSTER_GROUPS_CLUSTER_SERVER_INIT
#define EMBER_CALLBACK_GROUPS_CLUSTER_ADD_GROUP
#define EMBER_CALLBACK_GROUPS_CLUSTER_VIEW_GROUP
#define EMBER_CALLBACK_GROUPS_CLUSTER_GET_GROUP_MEMBERSHIP
#define EMBER_CALLBACK_GROUPS_CLUSTER_REMOVE_GROUP
#define EMBER_CALLBACK_GROUPS_CLUSTER_REMOVE_ALL_GROUPS
#define EMBER_CALLBACK_GROUPS_CLUSTER_ADD_GROUP_IF_IDENTIFYING
#define EMBER_CALLBACK_GROUPS_CLUSTER_ENDPOINT_IN_GROUP
#define EMBER_CALLBACK_GROUPS_CLUSTER_CLEAR_GROUP_TABLE
#define EMBER_CALLBACK_CONFIGURE_REPORTING_COMMAND
#define EMBER_CALLBACK_READ_REPORTING_CONFIGURATION_COMMAND
#define EMBER_CALLBACK_CLEAR_REPORT_TABLE
#define EMBER_CALLBACK_REPORTING_ATTRIBUTE_CHANGE
#define EMBER_CALLBACK_IDENTIFY_CLUSTER_IDENTIFY_CLUSTER_SERVER_INIT
#define EMBER_CALLBACK_IDENTIFY_CLUSTER_IDENTIFY_CLUSTER_SERVER_TICK
#define EMBER_CALLBACK_IDENTIFY_CLUSTER_IDENTIFY_CLUSTER_SERVER_ATTRIBUTE_CHANGED
#define EMBER_CALLBACK_IDENTIFY_CLUSTER_IDENTIFY
#define EMBER_CALLBACK_IDENTIFY_CLUSTER_IDENTIFY_QUERY
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_LEVEL_CONTROL_CLUSTER_SERVER_INIT
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_LEVEL_CONTROL_CLUSTER_SERVER_TICK
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL_WITH_ON_OFF
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_MOVE
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_MOVE_WITH_ON_OFF
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_STEP
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_STEP_WITH_ON_OFF
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_STOP
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_STOP_WITH_ON_OFF
#define EMBER_CALLBACK_ON_OFF_CLUSTER_ON_OFF_CLUSTER_LEVEL_CONTROL_EFFECT
#define EMBER_CALLBACK_ON_OFF_CLUSTER_ON_OFF_CLUSTER_SERVER_INIT
#define EMBER_CALLBACK_ON_OFF_CLUSTER_OFF
#define EMBER_CALLBACK_ON_OFF_CLUSTER_ON
#define EMBER_CALLBACK_ON_OFF_CLUSTER_TOGGLE
#define EMBER_CALLBACK_ON_OFF_CLUSTER_ON_OFF_CLUSTER_SET_VALUE
#define EMBER_CALLBACK_MAC_FILTER_MATCH_MESSAGE
#define EMBER_APPLICATION_HAS_MAC_FILTER_MATCH_MESSAGE_HANDLER
#define EMBER_CALLBACK_EZSP_MAC_FILTER_MATCH_MESSAGE
#define EZSP_APPLICATION_HAS_MAC_FILTER_MATCH_HANDLER
#define EMBER_CALLBACK_INTERPAN_SEND_MESSAGE
#define EMBER_CALLBACK_COUNTER_HANDLER
#define EMBER_APPLICATION_HAS_COUNTER_HANDLER
#define EMBER_CALLBACK_EZSP_COUNTER_ROLLOVER_HANDLER
#define EZSP_APPLICATION_HAS_COUNTER_ROLLOVER_HANDLER
#define EMBER_CALLBACK_BASIC_CLUSTER_RESET_TO_FACTORY_DEFAULTS
/**** Debug printing section ****/

// Global switch
#define EMBER_AF_PRINT_ENABLE
// Individual areas
#define EMBER_AF_PRINT_CORE 0x0001
#define EMBER_AF_PRINT_APP 0x0002
#define EMBER_AF_PRINT_ZDO 0x0004
#define EMBER_AF_PRINT_BITS { 0x07 }
#define EMBER_AF_PRINT_NAMES { \
  "Core",\
  "Application",\
  "ZDO (ZigBee Device Object)",\
  NULL\
}
#define EMBER_AF_PRINT_NAME_NUMBER 3


#define EMBER_AF_SUPPORT_COMMAND_DISCOVERY


// Generated plugin macros

// Use this macro to check if ADC plugin is included
#define EMBER_AF_PLUGIN_ADC

// Use this macro to check if AES-CMAC plugin is included
#define EMBER_AF_PLUGIN_AES_CMAC

// Use this macro to check if Antenna Stub plugin is included
#define EMBER_AF_PLUGIN_ANTENNA_STUB

// Use this macro to check if Basic Server Cluster plugin is included
#define EMBER_AF_PLUGIN_BASIC

// Use this macro to check if Binding Table Library plugin is included
#define EMBER_AF_PLUGIN_BINDING_TABLE_LIBRARY
// User options for plugin Binding Table Library
#define EMBER_BINDING_TABLE_SIZE 3

// Use this macro to check if CCM* Encryption plugin is included
#define EMBER_AF_PLUGIN_CCM_ENCRYPTION
// User options for plugin CCM* Encryption
#define EMBER_AF_PLUGIN_CCM_ENCRYPTION_SOFTWARE_CCM
#define USE_SOFTWARE_CCM

// Use this macro to check if Radio Coexistence Stub plugin is included
#define EMBER_AF_PLUGIN_COEXISTENCE_STUB

// Use this macro to check if Counters plugin is included
#define EMBER_AF_PLUGIN_COUNTERS
// User options for plugin Counters

// Use this macro to check if Debug Basic Library plugin is included
#define EMBER_AF_PLUGIN_DEBUG_BASIC_LIBRARY

// Use this macro to check if Debug JTAG plugin is included
#define EMBER_AF_PLUGIN_DEBUG_JTAG

// Use this macro to check if Ember Minimal Printf plugin is included
#define EMBER_AF_PLUGIN_EMBER_MINIMAL_PRINTF

// Use this macro to check if Find and Bind Target plugin is included
#define EMBER_AF_PLUGIN_FIND_AND_BIND_TARGET
// User options for plugin Find and Bind Target
#define EMBER_AF_PLUGIN_FIND_AND_BIND_TARGET_COMMISSIONING_TIME 180

// Use this macro to check if Groups Server Cluster plugin is included
#define EMBER_AF_PLUGIN_GROUPS_SERVER

// Use this macro to check if HAL Library plugin is included
#define EMBER_AF_PLUGIN_HAL_LIBRARY

// Use this macro to check if Heartbeat plugin is included
#define EMBER_AF_PLUGIN_HEARTBEAT
// User options for plugin Heartbeat
#define EMBER_AF_PLUGIN_HEARTBEAT_PERIOD_QS 1

// Use this macro to check if Identify Cluster plugin is included
#define EMBER_AF_PLUGIN_IDENTIFY

// Use this macro to check if Install Code Library plugin is included
#define EMBER_AF_PLUGIN_INSTALL_CODE_LIBRARY

// Use this macro to check if Interpan plugin is included
#define EMBER_AF_PLUGIN_INTERPAN
// User options for plugin Interpan
#define EMBER_AF_PLUGIN_INTERPAN_DELIVER_TO PRIMARY_ENDPOINT
#define EMBER_AF_PLUGIN_INTERPAN_DELIVER_TO_SPECIFIED_ENDPOINT_VALUE 1

// Use this macro to check if Level Control Server Cluster plugin is included
#define EMBER_AF_PLUGIN_LEVEL_CONTROL
// User options for plugin Level Control Server Cluster
#define EMBER_AF_PLUGIN_LEVEL_CONTROL_MAXIMUM_LEVEL 255
#define EMBER_AF_PLUGIN_LEVEL_CONTROL_MINIMUM_LEVEL 0
#define EMBER_AF_PLUGIN_LEVEL_CONTROL_RATE 0

// Use this macro to check if mbed TLS plugin is included
#define EMBER_AF_PLUGIN_MBEDTLS
// User options for plugin mbed TLS
#define EMBER_AF_PLUGIN_MBEDTLS_CONF_DEVICE_ACCELERATION
#define EMBER_AF_PLUGIN_MBEDTLS_CONF_DEVICE_ACCELERATION_APP

// Use this macro to check if Network Steering plugin is included
#define EMBER_AF_PLUGIN_NETWORK_STEERING
// User options for plugin Network Steering
#define EMBER_AF_PLUGIN_NETWORK_STEERING_CHANNEL_MASK 0x0318C800
#define EMBER_AF_PLUGIN_NETWORK_STEERING_RADIO_TX_POWER 3
#define EMBER_AF_PLUGIN_NETWORK_STEERING_SCAN_DURATION 4
#define EMBER_AF_PLUGIN_NETWORK_STEERING_COMMISSIONING_TIME_S 180
#define EMBER_AF_PLUGIN_NETWORK_STEERING_OPTIMIZE_SCANS

// Use this macro to check if NVM3 Library plugin is included
#define EMBER_AF_PLUGIN_NVM3
// User options for plugin NVM3 Library
#define EMBER_AF_PLUGIN_NVM3_FLASH_PAGES 4
#define EMBER_AF_PLUGIN_NVM3_CACHE_SIZE 200
#define EMBER_AF_PLUGIN_NVM3_MAX_OBJECT_SIZE 254
#define EMBER_AF_PLUGIN_NVM3_USER_REPACK_HEADROOM 0

// Use this macro to check if On/Off Server Cluster plugin is included
#define EMBER_AF_PLUGIN_ON_OFF

// Use this macro to check if RAIL Library plugin is included
#define EMBER_AF_PLUGIN_RAIL_LIBRARY
// User options for plugin RAIL Library
#define EMBER_AF_PLUGIN_RAIL_LIBRARY_RAILPHYDEF 1

// Use this macro to check if Reporting plugin is included
#define EMBER_AF_PLUGIN_REPORTING
// User options for plugin Reporting
#define EMBER_AF_PLUGIN_REPORTING_TABLE_SIZE 5
#define EMBER_AF_PLUGIN_REPORTING_ENABLE_GROUP_BOUND_REPORTS

// Use this macro to check if Scan Dispatch plugin is included
#define EMBER_AF_PLUGIN_SCAN_DISPATCH
// User options for plugin Scan Dispatch
#define EMBER_AF_PLUGIN_SCAN_DISPATCH_SCAN_QUEUE_SIZE 10

// Use this macro to check if Scenes Server Cluster plugin is included
#define EMBER_AF_PLUGIN_SCENES
// User options for plugin Scenes Server Cluster
#define EMBER_AF_PLUGIN_SCENES_TABLE_SIZE 3
#define EMBER_AF_PLUGIN_SCENES_USE_TOKENS

// Use this macro to check if Serial plugin is included
#define EMBER_AF_PLUGIN_SERIAL

// Use this macro to check if Simulated EEPROM version 2 to NVM3 Upgrade Stub plugin is included
#define EMBER_AF_PLUGIN_SIM_EEPROM2_TO_NVM3_UPGRADE_STUB

// Use this macro to check if Simple Main plugin is included
#define EMBER_AF_PLUGIN_SIMPLE_MAIN

// Use this macro to check if Source Route Library plugin is included
#define EMBER_AF_PLUGIN_SOURCE_ROUTE_LIBRARY
// User options for plugin Source Route Library
#define EMBER_SOURCE_ROUTE_TABLE_SIZE 7

// Use this macro to check if Strong Random plugin is included
#define EMBER_AF_PLUGIN_STRONG_RANDOM
// User options for plugin Strong Random
#define EMBER_AF_PLUGIN_STRONG_RANDOM_RADIO_PRNG
#define USE_RADIO_API_FOR_TRNG

// Use this macro to check if Update TC Link Key plugin is included
#define EMBER_AF_PLUGIN_UPDATE_TC_LINK_KEY
// User options for plugin Update TC Link Key
#define EMBER_AF_PLUGIN_UPDATE_TC_LINK_KEY_MAX_ATTEMPTS 3

// Use this macro to check if ZCL Framework Core plugin is included
#define EMBER_AF_PLUGIN_ZCL_FRAMEWORK_CORE
// User options for plugin ZCL Framework Core
#define EMBER_AF_PLUGIN_ZCL_FRAMEWORK_CORE_CLI_ENABLED
#define ZA_CLI_FULL

// Use this macro to check if ZigBee PRO Stack Library plugin is included
#define EMBER_AF_PLUGIN_ZIGBEE_PRO_LIBRARY
// User options for plugin ZigBee PRO Stack Library
#define EMBER_MAX_END_DEVICE_CHILDREN 6
#define EMBER_PACKET_BUFFER_COUNT 75
#define EMBER_END_DEVICE_KEEP_ALIVE_SUPPORT_MODE EMBER_KEEP_ALIVE_SUPPORT_ALL
#define EMBER_END_DEVICE_POLL_TIMEOUT MINUTES_256
#define EMBER_END_DEVICE_POLL_TIMEOUT_SHIFT 6
#define EMBER_LINK_POWER_DELTA_INTERVAL 300
#define EMBER_APS_UNICAST_MESSAGE_COUNT 10
#define EMBER_BROADCAST_TABLE_SIZE 15
#define EMBER_NEIGHBOR_TABLE_SIZE 16


// Generated API headers

// API adc-cortexm3 from ADC plugin
#define EMBER_AF_API_ADC_CORTEXM3 "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/platform/base/hal/plugin/adc/adc-cortexm3.h"

// API adc from ADC plugin
#define EMBER_AF_API_ADC "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/platform/base/hal/plugin/adc/adc.h"

// API aes-cmac from AES-CMAC plugin
#define EMBER_AF_API_AES_CMAC "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/protocol/zigbee/app/framework/plugin/aes-cmac/aes-cmac.h"

// API antenna from Antenna Stub plugin
#define EMBER_AF_API_ANTENNA "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/platform/base/hal/plugin/antenna/antenna.h"

// API coexistence from Radio Coexistence Stub plugin
#define EMBER_AF_API_COEXISTENCE "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154/coexistence-802154.h"

// API find-and-bind-target from Find and Bind Target plugin
#define EMBER_AF_API_FIND_AND_BIND_TARGET "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/protocol/zigbee/app/framework/plugin/find-and-bind-target/find-and-bind-target.h"

// API network-steering from Network Steering plugin
#define EMBER_AF_API_NETWORK_STEERING "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/protocol/zigbee/app/framework/plugin/network-steering/network-steering.h"

// API nvm3 from NVM3 Library plugin
#define EMBER_AF_API_NVM3 "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/platform/base/hal/plugin/nvm3/nvm3-token.h"

// API rail-library from RAIL Library plugin
#define EMBER_AF_API_RAIL_LIBRARY "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/platform/radio/rail_lib/common/rail.h"

// API scan-dispatch from Scan Dispatch plugin
#define EMBER_AF_API_SCAN_DISPATCH "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/protocol/zigbee/app/framework/plugin/scan-dispatch/scan-dispatch.h"

// API serial from Serial plugin
#define EMBER_AF_API_SERIAL "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/platform/base/hal/plugin/serial/serial.h"

// API update-tc-link-key from Update TC Link Key plugin
#define EMBER_AF_API_UPDATE_TC_LINK_KEY "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/protocol/zigbee/app/framework/plugin/update-tc-link-key/update-tc-link-key.h"

// API command-interpreter2 from ZCL Framework Core plugin
#define EMBER_AF_API_COMMAND_INTERPRETER2 "../../../../../SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7/protocol/zigbee/app/util/serial/command-interpreter2.h"


// Custom macros
#ifdef COMMISSIONING_STATUS_LED
#undef COMMISSIONING_STATUS_LED
#endif
#define COMMISSIONING_STATUS_LED BOARDLED2

#ifdef ON_OFF_LIGHT_LED
#undef ON_OFF_LIGHT_LED
#endif
#define ON_OFF_LIGHT_LED BOARDLED2

#ifdef LED_BLINK_PERIOD_MS
#undef LED_BLINK_PERIOD_MS
#endif
#define LED_BLINK_PERIOD_MS 2000



#endif // SILABS_ZNET_CONFIG
