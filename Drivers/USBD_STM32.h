/******************************************************************************
 * @file     USBD_STM32.h
 * @brief    USB Device Driver header for STMicroelectronics STM32 devices
 * @version  V3.0
 * @date     28. February 2024
 ******************************************************************************/
/*
 * Copyright (c) 2024 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef  USBD_STM32_H__
#define  USBD_STM32_H__

#include "Driver_USBD.h"
#include "MX_Device.h"

#ifdef  __cplusplus
extern "C"
{
#endif

// Configuration **************************************************************

#if     defined(MX_USB)
#define MX_USBD0                        1
#define MX_USBD_EP_PMAConfig            1
#endif

#if   ((defined(MX_USB_OTG_FS) && defined(MX_USB_OTG_FS_DEVICE))         || \
       (defined(MX_USB_OTG_FS) && defined(MX_USB_OTG_FS_Device_Only)))
#define MX_USBD0                        1
#endif

#if   ((defined(MX_USB_OTG_HS) && defined(MX_USB_OTG_HS_DEVICE))         || \
       (defined(MX_USB_OTG_HS) && defined(MX_USB_OTG_HS_Device_Only_FS)) || \
       (defined(MX_USB_OTG_HS) && defined(MX_USB_OTG_HS_Device_HS)))
#define MX_USBD1                        1
#endif

// If MX_USBD_EP_PMAConfig == 1 then for Endpoint FIFO
// the function HAL_PCDEx_PMAConfig is used,
// if MX_USBD_EP_PMAConfig == 0 then for Endpoint FIFO
// the functions HAL_PCDEx_SetTxFiFo and HAL_PCDEx_SetRxFiFo are used
// HAL_PCDEx_PMAConfig are available on older devices that have older
// USB controller (not OTG)
#ifndef MX_USBD_EP_PMAConfig
#define MX_USBD_EP_PMAConfig            0
#endif

// Global driver structures ***************************************************

#ifdef  MX_USBD0
extern  ARM_DRIVER_USBD Driver_USBD0;
#endif

#ifdef  MX_USBD1
extern  ARM_DRIVER_USBD Driver_USBD1;
#endif

#ifdef  __cplusplus
}
#endif

#endif /* USBD_STM32_H__ */