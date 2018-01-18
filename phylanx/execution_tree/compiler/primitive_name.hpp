//  Copyright (c) 2018 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(PHYLANX_EXECUTION_TREE_PRIMITIVE_NAME_HPP)
#define PHYLANX_EXECUTION_TREE_PRIMITIVE_NAME_HPP

#include <phylanx/config.hpp>

#include <hpx/include/util.hpp>

#include <cstdint>
#include <string>

namespace phylanx { namespace execution_tree { namespace compiler
{
    // The full name of every component is patterned after
    //
    //      /phylanx/<primitive>#<sequence-nr>[#<instance>]/<compile_id>#<tag>
    //
    //  where:
    //      <primitive>:   the name of primitive type representing the given
    //                     node in the expression tree
    //      <sequence-nr>: the sequence number of the corresponding instance
    //                     of type <primitive>
    //      <instance>:    (optional), some primitives have additional instance
    //                     names, for instance references to function arguments
    //                     have the name of the argument as their <instance>
    //      <compile_id>:  the sequence number of the invocation of the
    //                     function phylanx::execution_tree::compile
    //      <tag>:         the position inside the compiled code block where the
    //                     referring to the point of usage of the primitive in
    //                     the compiled source code
    struct primitive_name_parts
    {
        primitive_name_parts()
          : sequence_number(-1)
          , compile_id(-1)
          , tag(-1)
        {}

        std::string primitive;
        std::int64_t sequence_number;
        std::string instance;
        std::int64_t compile_id;
        std::int64_t tag;
    };

    // Split the given primitive name into its parts
    PHYLANX_EXPORT primitive_name_parts parse_primitive_name(
        std::string const& name);

    // compose a new primitive name from the given parts
    PHYLANX_EXPORT std::string compose_primitive_name(
        primitive_name_parts const& parts);
}}}

#endif


