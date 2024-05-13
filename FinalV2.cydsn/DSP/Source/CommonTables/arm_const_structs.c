/* ----------------------------------------------------------------------
 * Project:      CMSIS DSP Library
 * Title:        arm_const_structs.c
 * Description:  Constant structs that are initialized for user convenience.
 *               For example, some can be given as arguments to the arm_cfft_f32() or arm_rfft_f32() functions.
 *
 * $Date:        23 April 2021
 * $Revision:    V1.9.0
 *
 * Target Processor: Cortex-M and Cortex-A cores
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2021 ARM Limited or its affiliates. All rights reserved.
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

#include "arm_math_types.h"
#include "arm_const_structs.h"

/* Floating-point structs */
#if !defined(ARM_MATH_MVEF) || defined(ARM_MATH_AUTOVECTORIZE)


#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_16) && defined(ARM_TABLE_BITREVIDX_FLT_16))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len16 = {
  16, twiddleCoef_16, armBitRevIndexTable16, ARMBITREVINDEXTABLE_16_TABLE_LENGTH
};
#endif


#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_32) && defined(ARM_TABLE_BITREVIDX_FLT_32))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len32 = {
  32, twiddleCoef_32, armBitRevIndexTable32, ARMBITREVINDEXTABLE_32_TABLE_LENGTH
};
#endif

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_64) && defined(ARM_TABLE_BITREVIDX_FLT_64))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len64 = {
  64, twiddleCoef_64, armBitRevIndexTable64, ARMBITREVINDEXTABLE_64_TABLE_LENGTH
};
#endif

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_128) && defined(ARM_TABLE_BITREVIDX_FLT_128))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len128 = {
  128, twiddleCoef_128, armBitRevIndexTable128, ARMBITREVINDEXTABLE_128_TABLE_LENGTH
};
#endif

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_256) && defined(ARM_TABLE_BITREVIDX_FLT_256))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len256 = {
  256, twiddleCoef_256, armBitRevIndexTable256, ARMBITREVINDEXTABLE_256_TABLE_LENGTH
};
#endif

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_512) && defined(ARM_TABLE_BITREVIDX_FLT_512))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len512 = {
  512, twiddleCoef_512, armBitRevIndexTable512, ARMBITREVINDEXTABLE_512_TABLE_LENGTH
};
#endif

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_1024) && defined(ARM_TABLE_BITREVIDX_FLT_1024))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len1024 = {
  1024, twiddleCoef_1024, armBitRevIndexTable1024, ARMBITREVINDEXTABLE_1024_TABLE_LENGTH
};
#endif

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_2048) && defined(ARM_TABLE_BITREVIDX_FLT_2048))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len2048 = {
  2048, twiddleCoef_2048, armBitRevIndexTable2048, ARMBITREVINDEXTABLE_2048_TABLE_LENGTH
};
#endif

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_4096) && defined(ARM_TABLE_BITREVIDX_FLT_4096))
const arm_cfft_instance_f32 arm_cfft_sR_f32_len4096 = {
  4096, twiddleCoef_4096, armBitRevIndexTable4096, ARMBITREVINDEXTABLE_4096_TABLE_LENGTH
};
#endif

#endif /* !defined(ARM_MATH_MVEF) || defined(ARM_MATH_AUTOVECTORIZE) */