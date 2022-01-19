/**
 * @file cryptocontext-bfvrns.h
 *
 * @brief API to generate BFVRNS crypto context
 *
 * @author TPOC: contact@palisade-crypto.org
 *
 * @contributor Dmitriy Suponitskiy
 *
 * @copyright Copyright (c) 2021, Duality Technologies (https://dualitytech.com/)
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution. THIS SOFTWARE IS
 * PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _CRYPTOCONTEXT_BFVRNS_H_
#define _CRYPTOCONTEXT_BFVRNS_H_

#include "scheme/bfvrns/gen-cryptocontext-bfvrns-internal.h"
#include "scheme/bfvrns/cryptocontextparams-bfvrns.h"
#include "lattice/backend.h"

namespace lbcrypto {
// forward declarations. TODO (dsuponit): I would replace them with the following includes later:
//#include "scheme/bfvrns/bfvrns-scheme.h"
//#include "scheme/bfvrns/bfvrns-cryptoparameters.h"
//#include "cryptocontext.h"
class SchemeBFVRNS;
class CryptoParametersBFVRNS;
template <typename Element> class CryptoContextImpl;
template <typename Element> class CryptoContextFactory;

class CryptoContextBFVRNS {
    using Element = DCRTPoly;

public:
    using ContextType               = CryptoContext<Element>; // required by GenCryptoContext() in gen-cryptocontext.h
    using Factory                   = CryptoContextFactory<Element>;
    using PublicKeyEncryptionScheme = SchemeBFVRNS;
    using CryptoParams              = CryptoParametersBFVRNS;

    static CryptoContext<Element> genCryptoContext(const CCParams<CryptoContextBFVRNS>& parameters) {
        return genCryptoContextBFVRNSInternal<CryptoContextBFVRNS, Element>(parameters);
    }
};

}  // namespace lbcrypto

#endif // _CRYPTOCONTEXT_BFVRNS_H_

