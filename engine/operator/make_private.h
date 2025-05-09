// Copyright 2023 Ant Group Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "engine/framework/operator.h"

namespace scql::engine::op {

// Reveal the secret data
class MakePrivate : public Operator {
 public:
  static const std::string kOpType;

  static constexpr char kIn[] = "In";
  static constexpr char kOut[] = "Out";
  // attrs
  static constexpr char kRevealToAttr[] = "reveal_to";

  const std::string& Type() const override;

 protected:
  void Validate(ExecContext* ctx) override;
  void Execute(ExecContext* ctx) override;

 private:
  static TensorPtr RevealPublicString(ExecContext* ctx, const TensorPtr& t,
                                      bool reveal_to_me, size_t reveal_to_rank);
};

}  // namespace scql::engine::op