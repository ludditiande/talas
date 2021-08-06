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
///   File: main.hpp
///
/// Author: $author$
///   Date: 6/28/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_TALAS_HASH_MAIN_HPP
#define TALAS_APP_CONSOLE_TALAS_HASH_MAIN_HPP

#include "talas/app/console/talas/hash/main_opt.hpp"
#include "talas/crypto/console/main.hpp"
#include "talas/crypto/hash/implementation/implementation.hpp"
#include "talas/crypto/random/pseudo.hpp"
#include "talas/crypto/byte_array.hpp"
#include "thirdparty/gnu/glibc/stdlib/rand_r.h"
#include "xos/base/array.hpp"

#define TALAS_APP_CONSOLE_TALAS_MAIN_KB_BLOCKSIZE 64
#define TALAS_APP_CONSOLE_TALAS_MAIN_BLOCKSIZE (TALAS_APP_CONSOLE_TALAS_MAIN_KB_BLOCKSIZE*1024)

namespace talas {
typedef xos::base::byte_array byte_array;
namespace app {
namespace console {
namespace talas {
namespace hash {

typedef crypto::console::main_implements main_implements;
typedef crypto::console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    typedef main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : run_(0), 
      hash_algorithm_(hash_algorithm_none), 
      block_size_(TALAS_APP_CONSOLE_TALAS_MAIN_BLOCKSIZE) {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef io::read::file source_file_t;

    typedef crypto::byte_array byte_array_t;
    typedef crypto::hash::base hash_t;
    typedef crypto::hash::implementation::md5 md5_t;
    typedef crypto::hash::implementation::sha1 sha1_t;
    typedef crypto::hash::implementation::sha256 sha256_t;
    typedef crypto::hash::implementation::sha512 sha512_t;
    enum hash_algorithm_t {
        hash_algorithm_none,
        hash_algorithm_sha512,
        hash_algorithm_sha256,
        hash_algorithm_sha1,
        hash_algorithm_md5,
        next_hash_algorithm,
        first_hash_algorithm = (hash_algorithm_none + 1),
        last_hash_algorithm = (next_hash_algorithm - 1)
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef int (Derives::*run_t)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = this->usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_md5(int argc, char_t** argv, char_t** env) {
        int err = run_hash(md5_, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int run_sha1(int argc, char_t** argv, char_t** env) {
        int err = run_hash(sha1_, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int run_sha256(int argc, char_t** argv, char_t** env) {
        int err = run_hash(sha256_, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int run_sha512(int argc, char_t** argv, char_t** env) {
        int err = run_hash(sha512_, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int run_hash(hash_t& hash, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((argc > optind) && (argv[optind]) && (argv[optind][0])) {
            const string_t source(argv[optind]);
            err = hash_file(source, hash);
        } else {
            const char_t* chars = 0;
            size_t length = 0;
            if ((chars = plain_text(length))) {
                err = this->hash(hash, chars, length);
            } else {
                err = this->hash(hash, 0,0);
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int run_hash_key(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = hash_key_chars(length))) {
            this->outln(chars, length);
        } else {
            this->outln();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int hash_file(const string_t& source, hash_t& hash) {
        const char_t* chars = 0;
        size_t length = 0;
        int err = 1;
        if ((chars = source.chars(length)) && (0 < length)) {
            source_file_t source_file;

            TALAS_LOG_MESSAGE_INFO("open source file \"" << chars << "\"...");
            if ((source_file.open(chars, source_file.mode_read_binary()))) {
                TALAS_LOG_MESSAGE_INFO("...opened source file \"" << chars << "\"");

                err = hash_file(source_file, hash);

                TALAS_LOG_MESSAGE_INFO("close source file \"" << chars << "\"...");
                if ((source_file.close())) {
                    TALAS_LOG_MESSAGE_INFO("...closed source file \"" << chars << "\"");
                } else {
                    TALAS_LOG_MESSAGE_INFO("...failed to close source file \"" << chars << "\"");
                }
            } else {
                TALAS_LOG_MESSAGE_ERROR("...failed to open source file \"" << chars << "\"");
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int hash_file(source_file_t& source, hash_t& hash) {
        int err = 1;
        ssize_t initialized = 0;
        size_t keylen = 0, keymax = 0;
        const byte_t* key = 0;
        
        if ((key = hash_key(keylen))) {
            if ((keylen > (keymax = hash.key_max()))) {
                keylen = keymax;
            }
            initialized = hash.initialize(key, keylen);
        } else {
            initialized = hash.initialize();
        }
        if (0 <= (initialized)) {
            err = 0;
            for (ssize_t count = 0, amount = 0; 0 <= amount; count += amount) {
                if (0 < (amount = source.read(block_, block_size_))) {
                    if (amount != (hash.hash(block_, amount))) {
                        err = 1;
                    } else {
                        continue;
                    }
                } else {
                    if (0 > (amount)) {
                        err = 1;
                    }
                }
                if (!(err)) {
                    if (0 < (count = hash.finalize(block_, block_size_))) {
                        outxln(block_, count);
                    } else {
                        err = 1;
                    }
                }
                break;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int hash(hash_t& hash, const void* source, size_t length) {
        int err = 1;
        ssize_t initialized = 0;
        size_t keylen = 0, keymax = 0;
        const byte_t* key = 0;
        
        if ((key = hash_key(keylen))) {
            if ((keylen > (keymax = hash.key_max()))) {
                keylen = keymax;
            }
            initialized = hash.initialize(key, keylen);
        } else {
            initialized = hash.initialize();
        }
        if (0 <= (initialized)) {
            err = 0;
            ssize_t count = 0;
            if ((source) && (length)) {
                if (length != (hash.hash(source, length))) {
                    return err = 1;
                }
            }
            if (0 < (count = hash.finalize(block_, block_size_))) {
                outxln(block_, count);
            } else {
                err = 1;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual hash_algorithm_t set_hash_algorithm(hash_algorithm_t to) {
        switch (hash_algorithm_ = to) {
        case hash_algorithm_md5:
            run_ = &Derives::run_md5;
            break;
        case hash_algorithm_sha1:
            run_ = &Derives::run_sha1;
            break;
        case hash_algorithm_sha256:
            run_ = &Derives::run_sha256;
            break;
        case hash_algorithm_sha512:
            run_ = &Derives::run_sha512;
            break;
        default:
            run_ = 0;
            break;
        }
        return hash_algorithm_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* get_hash_key() {
        size_t length = 0;
        const char_t* chars = 0;

        run_ = &Derives::run_hash_key;
        chars = hash_key_text_.has_chars(length);
        return chars;
    }
    virtual const char_t* set_hash_key(const char_t* chars) {
        size_t length = 0;

        if ((chars) && (chars[0])) {
            hash_key_text_.assign(chars);
            if ((chars = hash_key_text_.has_chars(length))) {
                const byte_t* bytes = 0;

                hash_key_.assignx(chars, length);
                if ((bytes = hash_key_.elements()) 
                    && (0 < (length = hash_key_.length()))) {
                    hash_key_text_.assignx(bytes, length);
                } else {
                }
            } else {
            }
        } else {
        }
        chars = hash_key_text_.has_chars(length);
        return chars;
    }
    virtual const char_t* hash_key_chars(size_t& length) const {
        const char_t* chars = hash_key_text_.has_chars(length);
        return chars;
    }
    virtual const byte_t* hash_key(size_t& length) const {
        const byte_t* bytes = hash_key_.elements();
        length = hash_key_.length();
        return bytes;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_plain_text(const char_t* chars) {
        plain_text_.assign(chars);
        chars = plain_text_.has_chars();
        return chars;
    }
    virtual const char_t* plain_text(size_t& length) const {
        const char_t* chars = plain_text_.has_chars(length);
        return chars;
    }

#include "talas/app/console/talas/hash/main_opt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    run_t run_;
    hash_algorithm_t hash_algorithm_;
    md5_t md5_;
    sha1_t sha1_;
    sha256_t sha256_;
    sha512_t sha512_;
    size_t block_size_;
    char block_[TALAS_APP_CONSOLE_TALAS_MAIN_BLOCKSIZE];
    string_t plain_text_, hash_key_text_;
    byte_array_t hash_key_;
}; /// class _EXPORT_CLASS main

} /// namespace hash
} /// namespace talas
} /// namespace console
} /// namespace app
} /// namespace talas

#endif /// TALAS_APP_CONSOLE_TALAS_HASH_MAIN_HPP
