// Copyright (C) 2017 Jonathan Müller <jonathanmueller.dev@gmail.com>
// This file is subject to the license terms in the LICENSE file
// found in the top-level directory of this distribution.

#include <cppast/cpp_namespace.hpp>

#include <cppast/cpp_entity_kind.hpp>

using namespace cppast;

cpp_entity_kind cpp_namespace::do_get_entity_kind() const noexcept
{
    return cpp_entity_kind::namespace_t;
}

bool detail::cpp_namespace_ref_predicate::operator()(const cpp_entity& e)
{
    return e.kind() == cpp_entity_kind::namespace_t;
}

std::unique_ptr<cpp_namespace_alias> cpp_namespace_alias::build(const cpp_entity_index& idx,
                                                                cpp_entity_id id, std::string name,
                                                                cpp_namespace_ref target)
{
    auto ptr = std::unique_ptr<cpp_namespace_alias>(
        new cpp_namespace_alias(std::move(name), std::move(target)));
    idx.register_entity(std::move(id), type_safe::ref(*ptr));
    return ptr;
}

cpp_entity_kind cpp_namespace_alias::do_get_entity_kind() const noexcept
{
    return cpp_entity_kind::namespace_alias_t;
}

cpp_entity_kind cpp_using_directive::do_get_entity_kind() const noexcept
{
    return cpp_entity_kind::using_directive_t;
}

cpp_entity_kind cpp_using_declaration::do_get_entity_kind() const noexcept
{
    return cpp_entity_kind::using_declaration_t;
}
