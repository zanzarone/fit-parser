#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// #define the macros below to 1/0 to enable/disable the mode of operation.
//
// CBC enables AES128 encryption in CBC-mode of operation and handles 0-padding.
// ECB enables the basic ECB 16-byte block algorithm. Both can be enabled simultaneously.

// The #ifndef-guard allows it to be configured before #include'ing or at compile time.
#ifndef CBC
  #define CBC 1
#endif

#ifndef ECB
  #define ECB 1
#endif



#if defined(ECB) && ECB

void AES128_ECB_encrypt(uint8_t* input, const uint8_t* key, uint8_t *output);
void AES128_ECB_decrypt(uint8_t* input, const uint8_t* key, uint8_t *output);

#endif // #if defined(ECB) && ECB


#if defined(CBC) && CBC

void AES128_CBC_encrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
void AES128_CBC_decrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);

#endif // #if defined(CBC) && CBC

#ifdef __cplusplus
};
#endif

//const uint8_t iv[] = { 0x2B, 0x7E, 0x25, 0x36, 0x28, 0xAE, 0xD3, 0xA6, 0xAB, 0xF7, 0x15, 0x98, 0x19, 0xCF, 0x4F, 0x3C};
#define KEY_LENGTH 16
const uint8_t iv[] = { 0xF0, 0xE1, 0xDA, 0xC3, 0xB4, 0xA5, 0x96, 0x87, 0x78, 0x79, 0x5A, 0x4D, 0x3C, 0x2D, 0x5F, 0xAF };
const uint8_t key[]= { 0x2B, 0x7E, 0x25, 0x36, 0x28, 0xAE, 0xD3, 0xA6, 0xAB, 0xF7, 0x15, 0x98, 0x19, 0xCF, 0x4F, 0x3C };

#endif //_AES_H_
