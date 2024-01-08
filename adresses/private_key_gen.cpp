#include <iostream>
#include <openssl/ec.h>
#include <openssl/bn.h>
#include <openssl/obj_mac.h>
#include <openssl/evp.h>
#include "private_key_gen.h"

class PrivateKeyGenerator {
public:
    std::string generate() {
        EVP_PKEY *pkey = NULL;
        EVP_PKEY_CTX *pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
        if (!pctx || EVP_PKEY_keygen_init(pctx) <= 0 || EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, NID_secp256k1) <= 0 || EVP_PKEY_keygen(pctx, &pkey) <= 0) {
            std::cerr << "Error generating EC_KEY.\n";
            EVP_PKEY_CTX_free(pctx);
            EVP_PKEY_free(pkey);
            return "";
        }

        EC_KEY *key = EVP_PKEY_get1_EC_KEY(pkey);
        const BIGNUM *bn = EC_KEY_get0_private_key(key);
        char *hex_bn = BN_bn2hex(bn);

        std::string privateKey(hex_bn);
        OPENSSL_free(hex_bn);
        EC_KEY_free(key);
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(pctx);

        return privateKey;
    }

    std::string generateSignature(const std::string& privateKey, const std::string& transactionHash) {
        BIGNUM *bn = BN_new();
        BN_hex2bn(&bn, privateKey.c_str());

        EC_KEY *key = EC_KEY_new_by_curve_name(NID_secp256k1);
        EC_KEY_set_private_key(key, bn);

        unsigned int sig_len = ECDSA_size(key);
        unsigned char *signature = (unsigned char*)malloc(sig_len);
        if (!ECDSA_sign(0, (const unsigned char*)transactionHash.c_str(), transactionHash.length(), signature, &sig_len, key)) {
            std::cerr << "Error generating signature.\n";
            EC_KEY_free(key);
            BN_free(bn);
            free(signature);
            return "";
        }

        char *hex_sig = BN_bn2hex(BN_bin2bn(signature, sig_len, NULL));
        std::string signatureStr(hex_sig);
        OPENSSL_free(hex_sig);
        EC_KEY_free(key);
        BN_free(bn);

        return signatureStr;
    }
};