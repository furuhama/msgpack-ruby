/*
 * MessagePack for Ruby
 *
 * Copyright (C) 2008-2013 Sadayuki Furuhashi
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
#ifndef MSGPACK_RUBY_COMPAT_H__
#define MSGPACK_RUBY_COMPAT_H__

#include <stdbool.h>
#include "ruby.h"

#include "ruby/st.h"  /* ruby hash on Ruby 1.9 */

/*
 * ZALLOC_N (ruby 2.2 or later)
 */
#ifndef RB_ZALLOC_N
#  define RB_ZALLOC_N(type,n) ((type*)ruby_xcalloc((size_t)(n),sizeof(type)))
#endif
#ifndef ZALLOC_N
#  define ZALLOC_N(type,n) RB_ZALLOC_N(type,n)
#endif

/*
 * COMPAT_HAVE_ENCODING
 */
#ifdef HAVE_RUBY_ENCODING_H
#  include "ruby/encoding.h"
#  define COMPAT_HAVE_ENCODING
#endif

/*
 * define STR_DUP_LIKELY_DOES_COPY
 * check rb_str_dup actually copies the string or not
 */
#define STR_DUP_LIKELY_DOES_COPY(str) FL_ALL(str, FL_USER1|FL_USER3)  /* same as STR_ASSOC_P(str) */


/*
 * SIZET2NUM
 */
#ifndef SIZET2NUM   /* MRI 1.8 */
#  define SIZET2NUM(v) ULL2NUM(v)
#endif


/*
 * rb_errinfo()
 */
#define COMPAT_RERAISE rb_exc_raise(rb_errinfo())


#endif

