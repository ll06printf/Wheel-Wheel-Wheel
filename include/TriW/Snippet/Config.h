//
// Created by ll06 on 24-12-18.
//

#ifndef TRIW_SNIPPET_CONFIG_H
#define TRIW_SNIPPET_CONFIG_H

#include <version>

// 配置 concept 特性

#if __cpp_concepts < 201907L
#error "C++20 concept core language feature is required"
#endif

#define TRIW_HAS_CONCEPT_LIB\
  __cpp_lib_concepts >= 202002L \
  and not defined(TRIW_WITHOUT_CONCEPT)



#endif //TRIW_SNIPPET_CONFIG_H
