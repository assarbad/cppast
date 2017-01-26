// Copyright (C) 2017 Jonathan Müller <jonathanmueller.dev@gmail.com>
// This file is subject to the license terms in the LICENSE file
// found in the top-level directory of this distribution.

#include <cppast/cpp_type_alias.hpp>

#include <cppast/cpp_entity_kind.hpp>

using namespace cppast;

std::unique_ptr<cpp_type_alias> cpp_type_alias::build(const cpp_entity_index& idx, cpp_entity_id id,
                                                      std::string               name,
                                                      std::unique_ptr<cpp_type> type)
{
    auto result =
        std::unique_ptr<cpp_type_alias>(new cpp_type_alias(std::move(name), std::move(type)));
    idx.register_entity(std::move(id), type_safe::cref(*result));
    return result;
}

cpp_entity_kind cpp_type_alias::do_get_entity_kind() const noexcept
{
    return cpp_entity_kind::type_alias_t;
}