#ifndef CRYPTO_KEY_STRING_H
#define CRYPTO_KEY_STRING_H

#include "core/object/ref_counted.h"
#include "core/io/stream_peer.h"
#include "modules/openssl/crypto_key_openssl.h"

class CryptoKeyString : public RefCounted {
	GDCLASS(CryptoKeyString, RefCounted);

protected:
	static void _bind_methods();

public:
	CryptoKeyString() {}
	Error load_from_string(const String &pem_string);
};

#endif
