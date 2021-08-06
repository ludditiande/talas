########################################################################
# Copyright (c) 1988-2021 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: libtalas.pri
#
# Author: $author$
#   Date: 6/28/2021
#
# QtCreator .pri file for talas library libtalas
########################################################################

########################################################################
# libtalas

# libtalas TARGET
#
libtalas_TARGET = talas
libtalas_TEMPLATE = lib
libtalas_CONFIG += staticlib

# libtalas INCLUDEPATH
#
libtalas_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# libtalas DEFINES
#
libtalas_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libtalas OBJECTIVE_HEADERS
#
#libtalas_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/talas/main.hh \

# libtalas OBJECTIVE_SOURCES
#
#libtalas_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/talas/main.mm \

########################################################################
# random
libtalas_random_HEADERS += \
$${TALAS_SRC}/talas/crypto/random/pseudo.hpp \
$${TALAS_SRC}/talas/crypto/random/generator.hpp \
$${TALAS_SRC}/talas/crypto/random/reader.hpp \

libtalas_random_SOURCES += \
$${TALAS_SRC}/talas/crypto/random/pseudo.cpp \
$${TALAS_SRC}/talas/crypto/random/generator.cpp \

########################################################################
# hash
libtalas_hash_HEADERS += \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha512.hpp \
$${TALAS_SRC}/talas/crypto/hash/sha512.hpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha256.hpp \
$${TALAS_SRC}/talas/crypto/hash/sha256.hpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha1.hpp \
$${TALAS_SRC}/talas/crypto/hash/sha1.hpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/md5.hpp \
$${TALAS_SRC}/talas/crypto/hash/md5.hpp \
$${TALAS_SRC}/talas/crypto/hash/mac.hpp \
$${TALAS_SRC}/talas/crypto/hash/base.hpp \

libtalas_hash_SOURCES += \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha512.cpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha256.cpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/sha1.cpp \
$${TALAS_SRC}/talas/crypto/hash/openssl/md5.cpp \
$${TALAS_SRC}/talas/crypto/hash/mac.cpp \
$${TALAS_SRC}/talas/crypto/hash/base.cpp \

########################################################################
# cipher
libtalas_cipher_HEADERS += \
$${TALAS_SRC}/talas/crypto/cipher/devine/aes.hpp \
$${TALAS_SRC}/talas/crypto/cipher/aes.hpp \
$${TALAS_SRC}/talas/crypto/cipher/openssl/des.hpp \
$${TALAS_SRC}/talas/crypto/cipher/des3.hpp \
$${TALAS_SRC}/talas/crypto/cipher/des.hpp \
$${TALAS_SRC}/talas/crypto/cipher/base.hpp \

libtalas_cipher_SOURCES += \
$${TALAS_SRC}/talas/crypto/cipher/devine/aes.cpp \
$${TALAS_SRC}/talas/crypto/cipher/openssl/des.cpp \

########################################################################
# libtalas HEADERS
#
libtalas_HEADERS += \
$${TALAS_SRC}/talas/base/base.hpp \
$${TALAS_SRC}/talas/crypto/base.hpp \
$${libtalas_random_HEADERS} \
$${libtalas_hash_HEADERS} \
$${libtalas_cipher_HEADERS} \

# libtalas SOURCES
#
libtalas_SOURCES += \
$${libtalas_random_SOURCES} \
$${libtalas_hash_SOURCES} \
$${libtalas_cipher_SOURCES} \

########################################################################



