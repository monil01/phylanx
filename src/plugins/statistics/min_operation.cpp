// Copyright (c) 2018 Bita Hasheminezhad
// Copyright (c) 2018 Hartmut Kaiser
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <phylanx/config.hpp>
#include <phylanx/plugins/statistics/min_operation.hpp>
#include <phylanx/plugins/statistics/statistics_base_impl.hpp>

#include <string>
#include <type_traits>
#include <utility>
#include <vector>

///////////////////////////////////////////////////////////////////////////////
namespace phylanx { namespace execution_tree { namespace primitives {

    ///////////////////////////////////////////////////////////////////////////
    match_pattern_type const min_operation::match_data =
    {
        match_pattern_type{
            "amin",
            std::vector<std::string>{
                "amin(_1, __arg(_2_axis, nil), __arg(_3_keepdims, nil), "
                    "__arg(_4_initial, nil), __arg(_5_dtype, nil))"
            },
            &create_amin_operation, &create_primitive<min_operation>, R"(
            a, axis, keepdims, initial, dtype
            Args:

                a (vector or matrix): a scalar, a vector or a matrix
                axis (optional, integer): an axis to min along. By default, "
                   flattened input is used.
                keepdims (optional, bool): If this is set to True, the axes which "
                   are reduced are left in the result as dimensions with size "
                   one. False by default
                initial (optional, scalar): The maximum value of an output
                   element.
                dtype (optional, string) : the data-type of the returned array,
                  defaults to dtype of input array.

            Returns:

            Returns the minimum of an array or minimum along an axis.)"
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    min_operation::min_operation(primitive_arguments_type&& operands,
        std::string const& name, std::string const& codename)
      : base_type(std::move(operands), name, codename)
    {
    }
}}}    // namespace phylanx::execution_tree::primitives
