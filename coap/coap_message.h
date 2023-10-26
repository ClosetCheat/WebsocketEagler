

#ifndef _COAP_MESSAGE_H
#define _COAP_MESSAGE_H

//Dependencies
#include "core/net.h"
#include "coap/coap_common.h"

//Maximum size of CoAP messages
#ifndef COAP_MAX_MSG_SIZE
   #define COAP_MAX_MSG_SIZE 1152
#elif (COAP_MAX_MSG_SIZE < 16)
   #error COAP_MAX_MSG_SIZE parameter is not valid
#endif

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief CoAP message
 **/

typedef struct
{
   uint8_t buffer[COAP_MAX_MSG_SIZE];
   size_t length;
   size_t pos;
} CoapMessage;


//CoAP related functions
error_t coapParseMessage(const CoapMessage *message);

error_t coapParseMessageHeader(const uint8_t *p, size_t length,
   size_t *consumed);

error_t coapSetType(CoapMessage *message, CoapMessageType type);
error_t coapGetType(const CoapMessage *message, CoapMessageType *type);

error_t coapSetCode(CoapMessage *message, CoapCode code);
error_t coapGetCode(const CoapMessage *message, CoapCode *code);

error_t coapSetPayload(CoapMessage *message, const void *payload,
   size_t payloadLen);

error_t coapGetPayload(const CoapMessage *message, const uint8_t **payload,
   size_t *payloadLen);

error_t coapWritePayload(CoapMessage *message, const void *data,
   size_t length);

error_t coapReadPayload(CoapMessage *message, void *data, size_t size,
   size_t *length);

bool_t coapCompareToken(const CoapMessageHeader *header1,
   const CoapMessageHeader *header2);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
