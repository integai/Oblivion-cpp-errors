#include <iostream>
#include <openssl/ec.h>
#include <openssl/bn.h>
#include <openssl/obj_mac.h>

class PrivateKeyGenerator {
public:
    std::string generate() {
        EC_KEY *key = EC_KEY_new_by_curve_name(NID_secp256k1);

        if (key == NULL) {
            std::cerr << "Error creating EC_KEY structure. This should never happen.\n";
            return "";
        }

        if (!EC_KEY_generate_key(key)) {
            std::cerr << "Error generating EC_KEY.\n";
            return "";
        }

        const BIGNUM *bn = EC_KEY_get0_private_key(key);
        char *hex_bn = BN_bn2hex(bn);

        std::string privateKey(hex_bn);
        OPENSSL_free(hex_bn);
        EC_KEY_free(key);

        return privateKey;
    }

    std::string generateSignature(const std::string& privateKey, const std::string& transactionHash) {
        BIGNUM *bn = BN_new();
        BN_hex2bn(&bn, privateKey.c_str());

        EC_KEY *key = EC_KEY_new_by_curve_name(NID_secp256k1);
        EC_KEY_set_private_key(key, bn);

        unsigned char *signature = NULL;
        unsigned int sig_len;
        if (!ECDSA_sign(0, (const unsigned char*)transactionHash.c_str(), transactionHash.length(), signature, &sig_len, key)) {
            std::cerr << "Error generating signature.\n";
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