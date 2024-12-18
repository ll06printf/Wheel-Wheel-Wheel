//
// Created by ll06 on 24-12-17.

/// \file
/// 这个头文件提供了 C++20 <concept> 头文件的一种
/// fallback。这个头文件出现的一个原因是本库 可能在支持 concept
/// 核心语言特性，但不支持 <concept> 库的环境中使用 (clang12,但是使用的libc++)

#ifndef TRIW_SNIPPET_CONSTRAINT_H
#define TRIW_SNIPPET_CONSTRAINT_H

#include "TriW/Snippet/Config.h"

#if __cpp_concepts >= 201907L
#  define TRIW_DEFINE_CONSTRAINT(name, body) concept name = body;
#else
#  define TRIW_DEFINE_CONSTRAINT(name, body) \
    static inline constexpr bool name = body;
#endif

#if TRIW_HAS_CONCEPT_LIB
#  include <concepts>
#else
#endif

#include <type_traits>

namespace TriW::Constraint {
#if TRIW_HAS_CONCEPT_LIB
using std::convertible_to;
using std::integral;
using std::invocable;
using std::predicate;
using std::regular_invocable;
using std::same_as;
using std::relation;
#else

// 没有概念库时的 fallback

/**
 * \brief 相同类型
 */
template <typename T, typename U>
TRIW_DEFINE_CONSTRAINT(same_as, (std::is_same_v<T, U>))

/**
 * \brief 整数
 */
template <typename T>
TRIW_DEFINE_CONSTRAINT(integral, (std::is_integral_v<T>))

/**
 * \brief 调用
 */
template <typename Fn, typename... ArgTypes>
TRIW_DEFINE_CONSTRAINT(invocable, (std::is_invocable_v<Fn, ArgTypes...>))

/**
 * \brief 相等性调用
 */
template <typename Fn, typename... ArgTypes>
TRIW_DEFINE_CONSTRAINT(regular_invocable, (invocable<Fn, ArgTypes...>))

/**
 * \brief 转让
 */
template <typename From, typename To>
TRIW_DEFINE_CONSTRAINT(convertible_with,
                       (std::is_convertible_v<From, To> and
                        requires { static_cast<To>(std::declval<From>()); }))

// 实现 boolean_testable 的细节
namespace Details {
  template <typename T>
  TRIW_DEFINE_CONSTRAINT(convertible_to_bool, (convertible_with<T, bool>))
}

/**
 * \brief 布尔测试
 */
template <typename T>
TRIW_DEFINE_CONSTRAINT(boolean_testable,
                       (Details::convertible_to_bool<T> and requires(T&& t) {{!std::forward<T>(t)} -> Details::convertible_to_bool;}))

/**
 * \brief 谓词
 */
template<typename F, typename... Args>
TRIW_DEFINE_CONSTRAINT(predicate, (
  regular_invocable<F, Args...>
  && boolean_testable<std::invoke_result_t<F, Args...>>
))


/**
 * \brief 二元关系
 */
template<typename R, typename T, typename U>
TRIW_DEFINE_CONSTRAINT(relation, (
  predicate<R, T, U> and predicate<R, U, U> and
  predicate<R, T, T> and predicate<R, U, T>
))



#endif
}  // namespace TriW::Constraint

#endif  // TRIW_SNIPPET_CONSTRAINT_H
