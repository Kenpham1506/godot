#include "register_types.h"
#include "crypto_key_string.h"

#include "core/object/class_db.h"

void initialize_cryptokey_string_loader_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
		return;

	ClassDB::bind_method(D_METHOD("load_key_from_string", "pem_string"), &CryptoKeyString::load_key_from_string);
}

void uninitialize_cryptokey_string_loader_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
		return;
}
