///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 6/28/2021, 8/6/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_TALAS_HASH_MAIN_OPT_HPP
#define TALAS_APP_CONSOLE_TALAS_HASH_MAIN_OPT_HPP

#include "talas/console/main.hpp"
#include "talas/console/main_opt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPT "hash"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_MD5_C "m"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_MD5_S "md5"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA1_C "1"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA1_S "sha1"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA256_C "2"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA256_S "sha256"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA512_C "5"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA512_S "sha512"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG "{ " \
    "(" TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_MD5_C ")" \
        TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_MD5_S \
    " | (" TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA1_C ")" \
           TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA1_S \
    " | (" TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA256_C ")" \
           TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA256_S \
    " | (" TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA512_C ")" \
           TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA512_S \
    " }"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTUSE ""
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTVAL_S "h:"
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTVAL_C 'h'
#define TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTION \
   {TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPT, \
    TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTVAL_C}, \

#define TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPT "key"
#define TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTARG "[ { 0..9 | a..f | A..F }... ]"
#define TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTUSE "Hmac key"
#define TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTVAL_S "k::"
#define TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTVAL_C 'k'
#define TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTION \
   {TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPT, \
    TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTVAL_C}, \

#define TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPT "plain-text"
#define TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTARG "string"
#define TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTUSE "Plain text"
#define TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTVAL_S "p:"
#define TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTVAL_C 'p'
#define TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTION \
   {TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPT, \
    TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_TALAS_MAIN_OPTIONS_CHARS \
   TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTVAL_S \
   TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTVAL_S \
   TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTVAL_S \
   TALAS_CONSOLE_MAIN_OPTIONS_CHARS

#define TALAS_APP_CONSOLE_TALAS_MAIN_OPTIONS_OPTIONS \
   TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTION \
   TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTION \
   TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTION \
   TALAS_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_TALAS_MAIN_SOURCE_ARG "[source]"
#define TALAS_APP_CONSOLE_TALAS_MAIN_SOURCE_ARG_USE "source file"

#define TALAS_APP_CONSOLE_TALAS_MAIN_TARGET_ARG "[target]"
#define TALAS_APP_CONSOLE_TALAS_MAIN_TARGET_ARG_USE "target file"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_TALAS_MAIN_ARGS \
    TALAS_APP_CONSOLE_TALAS_MAIN_SOURCE_ARG " " /*\
    TALAS_APP_CONSOLE_TALAS_MAIN_TARGET_ARG " " \*/

#define TALAS_APP_CONSOLE_TALAS_MAIN_ARGV \
    TALAS_APP_CONSOLE_TALAS_MAIN_SOURCE_ARG " - " TALAS_APP_CONSOLE_TALAS_MAIN_SOURCE_ARG_USE, /*\
    TALAS_APP_CONSOLE_TALAS_MAIN_TARGET_ARG " - " TALAS_APP_CONSOLE_TALAS_MAIN_TARGET_ARG_USE, \*/

namespace talas {
namespace app {
namespace console {
namespace talas {
namespace hash {

} /// namespace hash
} /// namespace talas
} /// namespace console
} /// namespace app
} /// namespace talas

#endif /// TALAS_APP_CONSOLE_TALAS_HASH_MAIN_OPT_HPP
