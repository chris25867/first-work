/*
 * @Author: chris25867 c79325936@gmail.com
 * @Date: 2026-09-29 17:14:45
 * @LastEditors: chris25867 c79325936@gmail.com
 * @LastEditTime: 2026-09-30 14:13:35
 * @FilePath: \firstwork\Tasks\src\task.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "tasks.h"
#include "main.h"
#include "tim.h"
#include "iwdg.h"

volatile uint32_t tick = 0;


void Tasks_Init(void){
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

      HAL_TIM_Base_Start_IT(&htim2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
      if (htim->Instance ==TIM2)
      {
            tick++;
            //HAL_IWDG_Refresh(&hiwdg);//第二题使用，第三题注释掉
      }
}