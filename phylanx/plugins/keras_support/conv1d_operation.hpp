// Copyright (c) 2019 Bita Hasheminezhad
// Copyright (c) 2019 Hartmut Kaiser
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(PHYLANX_KERAS_SUPPORT_CONV1D_OPERATION)
#define PHYLANX_KERAS_SUPPORT_CONV1D_OPERATION

#include <phylanx/config.hpp>
#include <phylanx/execution_tree/primitives/base_primitive.hpp>
#include <phylanx/execution_tree/primitives/primitive_component_base.hpp>
#include <phylanx/plugins/common/conv1d_all_paddings.hpp>

#include <hpx/futures/future.hpp>

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace phylanx { namespace execution_tree { namespace primitives {
/// \brief returns 1D convoltion
/// \param x              a tensor
/// \param kernel         a tensor, the filter
/// \param padding        Padding mode, either `valid`, `same` or `causal`
/// \param strides        The step to apply convolution
/// \param dilation_rate  The rate to sample x in each step

    class conv1d_operation
      : public primitive_component_base
      , public std::enable_shared_from_this<conv1d_operation>
    {
    protected:
        hpx::future<primitive_argument_type> eval(
            primitive_arguments_type const& operands,
            primitive_arguments_type const& args,
            eval_context ctx) const override;

    public:
        static match_pattern_type const match_data;

        conv1d_operation() = default;

        conv1d_operation(primitive_arguments_type&& operands,
            std::string const& name, std::string const& codename);
    };

    inline primitive create_conv1d_operation(hpx::id_type const& locality,
        primitive_arguments_type&& operands, std::string const& name = "",
        std::string const& codename = "")
    {
        return create_primitive_component(
            locality, "conv1d", std::move(operands), name, codename);
    }
}}}

#endif
