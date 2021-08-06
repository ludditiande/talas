///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: small_primes.hpp
///
/// Author: $author$
///   Date: 5/2/2015
///////////////////////////////////////////////////////////////////////
#ifndef _TALAS_CRYPTO_RANDOM_NUMBER_PRIME_SMALL_PRIMES_HPP
#define _TALAS_CRYPTO_RANDOM_NUMBER_PRIME_SMALL_PRIMES_HPP

#include "talas/crypto/base.hpp"

#define SMALL_PRIMES_SIZE 1028

namespace talas {
namespace crypto {
namespace random {
namespace prime {

extern const unsigned short g_small_primes[SMALL_PRIMES_SIZE];

} // namespace prime
} // namespace random 
} // namespace crypto 
} // namespace talas 

#endif // _TALAS_CRYPTO_RANDOM_NUMBER_PRIME_SMALL_PRIMES_HPP 
