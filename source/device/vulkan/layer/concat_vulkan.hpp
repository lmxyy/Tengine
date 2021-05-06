/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Parts of the following code in this file refs to
 * https://github.com/Tencent/ncnn/tree/master/src/layer/vulkan/
 * Tencent is pleased to support the open source community by making ncnn
 * available.
 *
 * Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 */

/*
 * Copyright (c) 2020, Open AI Lab
 * Author: ddzhao@openailab.com
 */

#ifndef LAYER_CONCAT_HPP
#define LAYER_CONCAT_HPP

#include "../vulkan_layer.hpp"
#include "../vulkan_command.hpp"

#include "concat_param.h"

namespace TEngine{

class Concat_vulkan : public Layer
{
public:
    Concat_vulkan();
    Concat_vulkan(ir_graph_t* graph, ir_node_t* ir_node);

    virtual int create_pipeline(const Option& opt);
    virtual int destroy_pipeline(const Option& opt);
    
    virtual int record_pipeline(const std::vector<VkTensor>& bottom_blobs, std::vector<VkTensor>& top_blobs, VkCompute& cmd, const Option& opt) const;

public:
    Pipeline* pipeline_concat[2];
    Pipeline* pipeline_concat_pack4[2];
    Pipeline* pipeline_concat_pack4to1[2];
    Pipeline* pipeline_concat_pack8[2];
    Pipeline* pipeline_concat_pack8to4[2];
    Pipeline* pipeline_concat_pack8to1[2];

public:
    int input_c;
    int input_h;
    int input_w;
    int output_c;
    int output_h;
    int output_w;
    int axis;
};

}   // namespace TEngine

#endif