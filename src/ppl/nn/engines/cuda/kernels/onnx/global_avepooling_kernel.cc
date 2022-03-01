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

#include "ppl/nn/engines/cuda/kernels/onnx/global_avepooling_kernel.h"

#include "cudakernel/nn/pooling_ave.h"
#include "cudakernel/nn/global_pooling_ave.h"
#include<iostream>

namespace ppl { namespace nn { namespace cuda {

ppl::common::RetCode GlobalAvePoolingKernel::DoExecute(KernelExecContext* ctx) {
    auto input = ctx->GetInput<TensorImpl>(0);
    auto output = ctx->GetOutput<TensorImpl>(0);
    ppl::common::RetCode status = ppl::common::RC_UNSUPPORTED;
    auto input_id = input->GetEdge()->GetId();
    auto input_quant = GetCommonParam()->cuda_tensor_info->at(input_id);
    auto output_id = output->GetEdge()->GetId();
    auto output_quant = GetCommonParam()->cuda_tensor_info->at(output_id);
    status = PPLCUDAGlobalAvePoolingForwardImp(GetStream(), input->GetShape(), input->GetBufferPtr(),
                                                output->GetShape(), output->GetBufferPtr(), input_quant.scale[0], output_quant.scale[0]);
    return status;
}

}}} // namespace ppl::nn::cuda
