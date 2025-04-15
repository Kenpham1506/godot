#include "crypto_key_string.h"
#include "core/io/marshalls.h"
#include "core/os/os.h"
#include "core/os/memory.h"
#include "core/io/file_access.h"

#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

void CryptoKeyString::_bind_methods() {
	ClassDB::bind_method(D_METHOD("load_key_from_string", "pem_string"), &CryptoKeyString::load_key_from_string);
}

Error CryptoKeyString::load_from_string(const String &pem_string) {
	BIO *bio = BIO_new_mem_buf(pem_string.utf8().get_data(), -1);
	if (!bio) {
		ERR_print_errors_fp(stderr);
		return ERR_CANT_OPEN;
	}

	RSA *rsa = PEM_read_bio_RSAPrivateKey(bio, nullptr, nullptr, nullptr);
	if (!rsa) {
		BIO_free(bio);
		ERR_print_errors_fp(stderr);
		return ERR_PARSE_ERROR;
	}

	Ref<CryptoKeyOpenSSL> key;
	key.instantiate();
	key->set_rsa(rsa);

	// Replace the current default Crypto singleton (or return this key as needed)
	Crypto::get_singleton()->set_private_key(key);

	BIO_free(bio);
	return OK;
}
