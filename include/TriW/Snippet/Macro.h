//
// Created by ll06 on 24-12-18.
//

#ifndef TRIW_SNIPPET_MACRO_H
#define TRIW_SNIPPET_MACRO_H

#include <boost/preprocessor.hpp>

#define TRIW_SEQ_AND_AND_REDUCE(seq)                                         \
  BOOST_PP_IF(                                                               \
      BOOST_PP_EQUAL(1, BOOST_PP_SEQ_SIZE(seq)), seq,                        \
      BOOST_PP_SEQ_FOLD_LEFT(TRIW_AND_AND_REDUCE_OP, BOOST_PP_SEQ_HEAD(seq), \
                             BOOST_PP_SEQ_TAIL(seq)))

#define TRIW_AND_AND_REDUCE_OP(d, state, elem) TRIW_AND_AND_REDUCE(state, elem)

#define TRIW_AND_AND_REDUCE(left, right) left&& right

#endif  // TRIW_SNIPPET_MACRO_H
