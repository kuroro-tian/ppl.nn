// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "ppl/kernel/riscv/common/internal_include.h"
#include "ppl/kernel/riscv/common/topk/topk_common.h"

namespace ppl { namespace kernel { namespace riscv {

uint64_t topk_ndarray_get_buffer_bytes_fp32(
    const ppl::nn::TensorShape *src_shape,
    const int32_t axis)
{
    return topk_ndarray_get_buffer_bytes<float>(src_shape, axis);
}

ppl::common::RetCode topk_ndarray_fp32(
    const ppl::nn::TensorShape *src_shape,
    const ppl::nn::TensorShape *value_shape,
    const ppl::nn::TensorShape *indices_shape,
    const float *src,
    const int64_t k,
    const int32_t axis,
    const int32_t largest,
    const int32_t sorted,
    void *temp_buffer,
    float *values,
    int64_t *indices)
{
    return topk_ndarray_common<float>(
        src_shape,
        value_shape,
        indices_shape,
        src,
        k,
        axis,
        largest,
        sorted,
        temp_buffer,
        values,
        indices);
}

}}} // namespace ppl::kernel::riscv