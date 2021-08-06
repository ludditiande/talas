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
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: 6/28/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_TALAS_HASH_MAIN_OPT_CPP
#define TALAS_APP_CONSOLE_TALAS_HASH_MAIN_OPT_CPP

#ifndef TALAS_APP_CONSOLE_TALAS_HASH_MAIN_HPP
#include "talas/app/console/talas/hash/main_opt.hpp"
namespace talas {
namespace app {
namespace console {
namespace talas {
namespace hash {
class _EXPORT_CLASS main {
protected:
#endif /// ndef TALAS_APP_CONSOLE_TALAS_HASH_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_hash_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((!(optarg[1]) && (TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_MD5_C[0] == (optarg[0])))
                || !(chars_t::compare(optarg, TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_MD5_S))) {
                set_hash_algorithm(hash_algorithm_md5);
            } else {
                if ((!(optarg[1]) && (TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA1_C[0] == (optarg[0])))
                    || !(chars_t::compare(optarg, TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA1_S))) {
                    set_hash_algorithm(hash_algorithm_sha1);
                } else {
                    if ((!(optarg[1]) && (TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA256_C[0] == (optarg[0])))
                        || !(chars_t::compare(optarg, TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA256_S))) {
                        set_hash_algorithm(hash_algorithm_sha256);
                    } else {
                        if ((!(optarg[1]) && (TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA512_C[0] == (optarg[0])))
                            || !(chars_t::compare(optarg, TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG_SHA512_S))) {
                            set_hash_algorithm(hash_algorithm_sha512);
                        } else {
                            err = on_invalid_option_arg
                            (optval, optarg, optname, optind, argc, argv, env);
                        }
                    }
                }
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_key_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_hash_key(optarg);
        } else {
            get_hash_key();
        }
        return err;
    }
    virtual const char_t* key_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTUSE;
        optarg = TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTARG;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_plain_text_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_plain_text(optarg);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        switch(optval) {
        case TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTVAL_C:
            err = on_hash_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTVAL_C:
            err = on_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTVAL_C:
            err = on_plain_text_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTVAL_C:
            optarg = TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTARG;
            chars = TALAS_APP_CONSOLE_TALAS_MAIN_HASH_OPTUSE;
            break;
        case TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTVAL_C:
            optarg = TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTARG;
            chars = TALAS_APP_CONSOLE_TALAS_MAIN_RANDOM_PLAIN_OPTUSE;
            break;
        case TALAS_APP_CONSOLE_TALAS_MAIN_KEY_OPTVAL_C:
            chars = key_option_usage(optarg, longopt);
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = TALAS_APP_CONSOLE_TALAS_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            TALAS_APP_CONSOLE_TALAS_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* arguments(const char**& args) {
        static const char* _args = TALAS_APP_CONSOLE_TALAS_MAIN_ARGS;
        static const char* _argv[3] = {
            TALAS_APP_CONSOLE_TALAS_MAIN_ARGV
            0};
        args = _argv;
        return _args;
    }

#ifndef TALAS_APP_CONSOLE_TALAS_HASH_MAIN_HPP
}; /// class _EXPORT_CLASS main
} /// namespace hash
} /// namespace talas
} /// namespace console
} /// namespace app
} /// namespace talas
#endif /// ndef TALAS_APP_CONSOLE_TALAS_HASH_MAIN_HPP

#endif /// ndef TALAS_APP_CONSOLE_TALAS_HASH_MAIN_OPT_CPP
