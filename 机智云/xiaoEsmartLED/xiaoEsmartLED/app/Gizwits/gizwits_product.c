/**
************************************************************
* @file         gizwits_product.c
* @brief        Gizwits 控制协议处理,及平台相关的硬件初始化 
* @author       Gizwits
* @date         2016-09-05
* @version      V03010201
* @copyright    Gizwits
* 
* @note         机智云.只为智能硬件而生
*               Gizwits Smart Cloud  for Smart Products
*               链接|增值ֵ|开放|中立|安全|自有|自由|生态
*               www.gizwits.com
*
***********************************************************/
#include <stdio.h>
#include <string.h>
#include "gizwits_product.h"
#include "driver/hal_key.h"

#include "driver/RGB_light.h"

/** 用户区当前设备状态结构体*/
extern dataPoint_t currentDataPoint;

/**@name Gizwits 用户API接口
* @{
*/

/**
* @brief 事件处理接口

* 说明：

* 1.用户可以对WiFi模组状态的变化进行自定义的处理

* 2.用户可以在该函数内添加数据点事件处理逻辑，如调用相关硬件外设的操作接口

* @param[in] info : 事件队列
* @param[in] data : 协议数据
* @param[in] len : 协议数据长度
* @return NULL
* @ref gizwits_protocol.h
*/
int8_t ICACHE_FLASH_ATTR gizwitsEventProcess(eventInfo_t *info, uint8_t *data, uint32_t len)
{
  uint8_t i = 0;
  dataPoint_t *dataPointPtr = (dataPoint_t *)data;
  moduleStatusInfo_t *wifiData = (moduleStatusInfo_t *)data;

  if((NULL == info) || (NULL == data))
  {
    return -1;
  }

  for(i=0; i<info->num; i++)
  {
    switch(info->event[i])
    {

      case EVENT_LED_COLOR:
        currentDataPoint.valueLED_Color = dataPointPtr->valueLED_Color;
        os_printf("Evt: EVENT_LED_COLOR %d\n", currentDataPoint.valueLED_Color);
        switch(currentDataPoint.valueLED_Color)
        {
          case LED_COLOR_VALUE0:
            //user handle
          {
             RGB_light_set_color(currentDataPoint.valueLED_R,currentDataPoint.valueLED_G,currentDataPoint.valueLED_B);
             RGB_light_start();
          }
            break;
          case LED_COLOR_VALUE1:
            //user handle
        {
         RGB_light_set_color(254, 254,0);
         RGB_light_start();
        }
            break;
          case LED_COLOR_VALUE2:
            //user handle
          {
         RGB_light_set_color(254, 0, 70);
         RGB_light_start();
        }
            break;
          case LED_COLOR_VALUE3:
            //user handle
                 {
         RGB_light_set_color(238, 30, 30);
         RGB_light_start();
        }
            break;
          default:
            break;
        }
        break;

      case EVENT_LED_R:
        currentDataPoint.valueLED_R = dataPointPtr->valueLED_R;
        os_printf("Evt:EVENT_LED_R %d\n",currentDataPoint.valueLED_R);
        //user handle
        {
        RGB_light_set_color(currentDataPoint.valueLED_R, 0, 0);
         RGB_light_start();
        }
        break;
      case EVENT_LED_G:
        currentDataPoint.valueLED_G = dataPointPtr->valueLED_G;
        os_printf("Evt:EVENT_LED_G %d\n",currentDataPoint.valueLED_G);
        //user handle
        {
         RGB_light_set_color(0, currentDataPoint.valueLED_G, 0);
         RGB_light_start();
        }
        break;
      case EVENT_LED_B:
        currentDataPoint.valueLED_B = dataPointPtr->valueLED_B;
        os_printf("Evt:EVENT_LED_B %d\n",currentDataPoint.valueLED_B);
        //user handle
       {
         RGB_light_set_color(0, 0, currentDataPoint.valueLED_B);
         RGB_light_start();
        }

        break;


      case WIFI_SOFTAP:
        break;
      case WIFI_AIRLINK:
        break;
      case WIFI_STATION:
        break;
      case WIFI_CON_ROUTER:
      {
         RGB_light_set_color(0, 0, 0);
         RGB_light_start();
      }
        break;
      case WIFI_DISCON_ROUTER:
        break;
      case WIFI_CON_M2M:
        break;
      case WIFI_DISCON_M2M:
        break;
      case WIFI_RSSI:
        os_printf("RSSI %d\n", wifiData->rssi);
        break;
      case TRANSPARENT_DATA:
        os_printf("TRANSPARENT_DATA \n");
        //user handle , Fetch data from [data] , size is [len]
        break;
      default:
        break;
    }
  }
  system_os_post(USER_TASK_PRIO_0, SIG_UPGRADE_DATA, 0);
  return 0;
}
/**@} */