/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*!
 * \file tl/op/builtin.h
 * \brief Builtin intrinsics.
 *
 */

#ifndef TVM_TL_OP_BUILTIN_H_
#define TVM_TL_OP_BUILTIN_H_

#include "op.h"

namespace tvm {
namespace tl {

/*!
 * \brief tvm intrinsics for TMADescriptor creation
 *
 * CreateTMADescriptorOp(data_type, rank, global_addr, global_shape..., global_stride...,
 * smem_box..., smem_stride..., interleave, swizzle, l2_promotion, oob_fill)
 *
 */
const Op& CreateTMADescriptorOp();

/*!
 * \brief tvm intrinsics for loading data from global tensor descriptor to shared memory
 *
 * TMALoadOp(descriptor, barrier_id, smem_data, coord_0, coord_1, ...)
 *
 */
const Op& TMALoadOp();

/*!
 * \brief tvm intrinsics for storing data from shared memory to global tensor descriptor
 *
 * TMAStoreOp(descriptor, smem_data, coord_0, coord_1, ...)
 *
 */
const Op& TMAStoreOp();

/*!
 * \brief tvm intrinsics for mbarrier wait with parity bit
 *
 * MBarrierWaitParity(barrier_id, parity)
 *
 */
const Op& MBarrierWaitParity();

/*!
 * \brief tvm intrinsics for mbarrier expect tx
 *
 * MBarrierExpectTX(barrier_id, transaction_bytes)
 *
 */
const Op& MBarrierExpectTX();

/*!
 * \brief tvm intrinsics for ldmatrix
 *
 * LDMatrixOp(transposed, num, shared_addr, local_addr)
 *
 */
const Op& LDMatrixOp();

/*!
 * \brief tvm intrinsics for stmatrix
 *
 * LDMatrixOp(transposed, num, shared_addr, int32_values...)
 *
 */
const Op& STMatrixOp();

/*!
 * \brief Pack two b16 value into a b32 value
 *
 * int32 PackB16Op(b16_value, b16_value)
 *
 */
const Op& PackB16Op();

/*!
 * \brief Similar to __syncthreads(), but can be used to sync partial threads
 *
 * SyncThreadsPartialOp(barrier_id)
 *
 */
const Op& SyncThreadsPartialOp();

}  // namespace tl
}  // namespace tvm

#endif  //  TVM_TL_OP_BUILTIN_H_