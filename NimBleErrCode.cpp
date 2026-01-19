#include <cstdint> // For uint16_t
#include <string>  // For std::string
#include <Arduino.h> //For Serial.print

struct errRec {
  uint16_t NimBLE;
  uint16_t Formal;
  const char* errName;
  const char* errDesc;
};

const errRec errTable[] = {
  {0x00,0x00,"N/A","Success"},
  {0x01,0x00,"BLE_HS_EAGAIN","Temporary failure; try again."},
  {0x02,0x00,"BLE_HS_EALREADY","Operation already in progress or completed."},
  {0x03,0x00,"BLE_HS_EINVAL","One or more arguments are invalid."},
  {0x04,0x00,"BLE_HS_EMSGSIZE","The provided buffer is too small."},
  {0x05,0x00,"BLE_HS_ENOENT","No entry matching the specified criteria."},
  {0x06,0x00,"BLE_HS_ENOMEM","Operation failed due to resource exhaustion."},
  {0x07,0x00,"BLE_HS_ENOTCONN","No open connection with the specified handle."},
  {0x08,0x00,"BLE_HS_ENOTSUP","Operation disabled at compile time."},
  {0x09,0x00,"BLE_HS_EAPP","Application callback behaved unexpectedly."},
  {0x0a,0x00,"BLE_HS_EBADDATA","Command from peer is invalid."},
  {0x0b,0x00,"BLE_HS_EOS","Mynewt OS error."},
  {0x0c,0x00,"BLE_HS_ECONTROLLER","Event from controller is invalid."},
  {0x0d,0x00,"BLE_HS_ETIMEOUT","Operation timed out."},
  {0x0e,0x00,"BLE_HS_EDONE","Operation completed successfully."},
  {0x0f,0x00,"BLE_HS_EBUSY","Operation cannot be performed until procedure completes."},
  {0x10,0x00,"BLE_HS_EREJECT","Peer rejected a connection parameter update request."},
  {0x11,0x00,"BLE_HS_EUNKNOWN","Unexpected failure; catch all."},
  {0x12,0x00,"BLE_HS_EROLE","Operation requires different role (e.g., central vs. peripheral)."},
  {0x13,0x00,"BLE_HS_ETIMEOUT_HCI","HCI request timed out; controller unresponsive."},
  {0x14,0x00,"BLE_HS_ENOMEM_EVT","Controller failed to send event due to memory exhaustion (combined host-controller only)."},
  {0x15,0x00,"BLE_HS_ENOADDR","Operation requires an identity address but none configured."},
  {0x16,0x00,"BLE_HS_ENOTSYNCED","Attempt to use the host before it is synced with controller."},
  {0x17,0x00,"BLE_HS_EAUTHEN","Insufficient authentication."},
  {0x18,0x00,"BLE_HS_EAUTHOR","Insufficient authorization."},
  {0x19,0x00,"BLE_HS_EENCRYPT","Insufficient encryption level."},
  {0x1a,0x00,"BLE_HS_EENCRYPT_KEY_SZ","Insufficient key size."},
  {0x1b,0x00,"BLE_HS_ESTORE_CAP","Storage at capacity."},
  {0x1c,0x00,"BLE_HS_ESTORE_FAIL","Storage IO error."},
  {0x0101,0x01,"BLE_ATT_ERR_INVALID_HANDLE","The attribute handle given was not valid on this server."},
  {0x0102,0x02,"BLE_ATT_ERR_READ_NOT_PERMITTED","The attribute cannot be read."},
  {0x0103,0x03,"BLE_ATT_ERR_WRITE_NOT_PERMITTED","The attribute cannot be written."},
  {0x0104,0x04,"BLE_ATT_ERR_INVALID_PDU","The attribute PDU was invalid."},
  {0x0105,0x05,"BLE_ATT_ERR_INSUFFICIENT_AUTHEN","The attribute requires authentication before it can be read or written."},
  {0x0106,0x06,"BLE_ATT_ERR_REQ_NOT_SUPPORTED","Attribute server does not support the request received from the client."},
  {0x0107,0x07,"BLE_ATT_ERR_INVALID_OFFSET","Offset specified was past the end of the attribute."},
  {0x0108,0x08,"BLE_ATT_ERR_INSUFFICIENT_AUTHOR","The attribute requires authorization before it can be read or written."},
  {0x0109,0x09,"BLE_ATT_ERR_PREPARE_QUEUE_FULL","Too many prepare writes have been queued."},
  {0x010a,0x0a,"BLE_ATT_ERR_ATTR_NOT_FOUND","No attribute found within the given attribute handle range."},
  {0x010b,0x0b,"BLE_ATT_ERR_ATTR_NOT_LONG","The attribute cannot be read or written using the Read Blob Request."},
  {0x010c,0x0c,"BLE_ATT_ERR_INSUFFICIENT_KEY_SZ","The Encryption Key Size used for encrypting this link is insufficient."},
  {0x010d,0x0d,"BLE_ATT_ERR_INVALID_ATTR_VALUE_LEN","The attribute value length is invalid for the operation."},
  {0x010e,0x0e,"BLE_ATT_ERR_UNLIKELY","The attribute request that was requested has encountered an error that was unlikely, and therefore could not be completed as requested."},
  {0x010f,0x0f,"BLE_ATT_ERR_INSUFFICIENT_ENC","The attribute requires encryption before it can be read or written."},
  {0x0110,0x10,"BLE_ATT_ERR_UNSUPPORTED_GROUP","The attribute type is not a supported grouping attribute as defined by a higher layer specification."},
  {0x0111,0x11,"BLE_ATT_ERR_INSUFFICIENT_RES","Insufficient Resources to complete the request."},
  {0x0201,0x01,"BLE_ERR_UNKNOWN_HCI_CMD","Unknown HCI Command"},
  {0x0202,0x02,"BLE_ERR_UNK_CONN_ID","Unknown Connection Identifier"},
  {0x0203,0x03,"BLE_ERR_HW_FAIL","Hardware Failure"},
  {0x0204,0x04,"BLE_ERR_PAGE_TMO","Page Timeout"},
  {0x0205,0x05,"BLE_ERR_AUTH_FAIL","Authentication Failure"},
  {0x0206,0x06,"BLE_ERR_PINKEY_MISSING","PIN or Key Missing"},
  {0x0207,0x07,"BLE_ERR_MEM_CAPACITY","Memory Capacity Exceeded"},
  {0x0208,0x08,"BLE_ERR_CONN_SPVN_TMO","Connection Timeout"},
  {0x0209,0x09,"BLE_ERR_CONN_LIMIT","Connection Limit Exceeded"},
  {0x020a,0x0a,"BLE_ERR_SYNCH_CONN_LIMIT","Synchronous Connection Limit To A Device Exceeded"},
  {0x020b,0x0b,"BLE_ERR_ACL_CONN_EXISTS","ACL Connection Already Exists"},
  {0x020c,0x0c,"BLE_ERR_CMD_DISALLOWED","Command Disallowed"},
  {0x020d,0x0d,"BLE_ERR_CONN_REJ_RESOURCES","Connection Rejected due to Limited Resources"},
  {0x020e,0x0e,"BLE_ERR_CONN_REJ_SECURITY","Connection Rejected Due To Security Reasons"},
  {0x020f,0x0f,"BLE_ERR_CONN_REJ_BD_ADDR","Connection Rejected due to Unacceptable BD_ADDR"},
  {0x0210,0x10,"BLE_ERR_CONN_ACCEPT_TMO","Connection Accept Timeout Exceeded"},
  {0x0211,0x11,"BLE_ERR_UNSUPPORTED","Unsupported Feature or Parameter Value"},
  {0x0212,0x12,"BLE_ERR_INV_HCI_CMD_PARMS","Invalid HCI Command Parameters"},
  {0x0213,0x13,"BLE_ERR_REM_USER_CONN_TERM","Remote User Terminated Connection"},
  {0x0214,0x14,"BLE_ERR_RD_CONN_TERM_RESRCS","Remote Device Terminated Connection due to Low Resources"},
  {0x0215,0x15,"BLE_ERR_RD_CONN_TERM_PWROFF","Remote Device Terminated Connection due to Power Off"},
  {0x0216,0x16,"BLE_ERR_CONN_TERM_LOCAL","Connection Terminated By Local Host"},
  {0x0217,0x17,"BLE_ERR_REPEATED_ATTEMPTS","Repeated Attempts"},
  {0x0218,0x18,"BLE_ERR_NO_PAIRING","Pairing Not Allowed"},
  {0x0219,0x19,"BLE_ERR_UNK_LMP","Unknown LMP PDU"},
  {0x021a,0x1a,"BLE_ERR_UNSUPP_REM_FEATURE","Unsupported Remote Feature / Unsupported LMP Feature"},
  {0x021b,0x1b,"BLE_ERR_SCO_OFFSET","SCO Offset Rejected"},
  {0x021c,0x1c,"BLE_ERR_SCO_ITVL","SCO Interval Rejected"},
  {0x021d,0x1d,"BLE_ERR_SCO_AIR_MODE","SCO Air Mode Rejected"},
  {0x021e,0x1e,"BLE_ERR_INV_LMP_LL_PARM","Invalid LMP Parameters / Invalid LL Parameters"},
  {0x021f,0x1f,"BLE_ERR_UNSPECIFIED","Unspecified Error"},
  {0x0220,0x20,"BLE_ERR_UNSUPP_LMP_LL_PARM","Unsupported LMP Parameter Value / Unsupported LL Parameter Value"},
  {0x0221,0x21,"BLE_ERR_NO_ROLE_CHANGE","Role Change Not Allowed"},
  {0x0222,0x22,"BLE_ERR_LMP_LL_RSP_TMO","LMP Response Timeout / LL Response Timeout"},
  {0x0223,0x23,"BLE_ERR_LMP_COLLISION","LMP Error Transaction Collision"},
  {0x0224,0x24,"BLE_ERR_LMP_PDU","LMP PDU Not Allowed"},
  {0x0225,0x25,"BLE_ERR_ENCRYPTION_MODE","Encryption Mode Not Acceptable"},
  {0x0226,0x26,"BLE_ERR_LINK_KEY_CHANGE","Link Key cannot be Changed"},
  {0x0227,0x27,"BLE_ERR_UNSUPP_QOS","Requested QoS Not Supported"},
  {0x0228,0x28,"BLE_ERR_INSTANT_PASSED","Instant Passed"},
  {0x0229,0x29,"BLE_ERR_UNIT_KEY_PAIRING","Pairing With Unit Key Not Supported"},
  {0x022a,0x2a,"BLE_ERR_DIFF_TRANS_COLL","Different Transaction Collision"},
  {0x022c,0x2c,"BLE_ERR_QOS_PARM","QoS Unacceptable Parameter"},
  {0x022d,0x2d,"BLE_ERR_QOS_REJECTED","QoS Rejected"},
  {0x022e,0x2e,"BLE_ERR_CHAN_CLASS","Channel Classification Not Supported"},
  {0x022f,0x2f,"BLE_ERR_INSUFFICIENT_SEC","Insufficient Security"},
  {0x0230,0x30,"BLE_ERR_PARM_OUT_OF_RANGE","Parameter Out Of Mandatory Range"},
  {0x0232,0x32,"BLE_ERR_PENDING_ROLE_SW","Role Switch Pending"},
  {0x0234,0x34,"BLE_ERR_RESERVED_SLOT","Reserved Slot Violation"},
  {0x0235,0x35,"BLE_ERR_ROLE_SW_FAIL","Role Switch Failed"},
  {0x0236,0x36,"BLE_ERR_INQ_RSP_TOO_BIG","Extended Inquiry Response Too Large"},
  {0x0237,0x37,"BLE_ERR_SEC_SIMPLE_PAIR","Secure Simple Pairing Not Supported By Host"},
  {0x0238,0x38,"BLE_ERR_HOST_BUSY_PAIR","Host Busy - Pairing"},
  {0x0239,0x39,"BLE_ERR_CONN_REJ_CHANNEL","Connection Rejected due to No Suitable Channel Found"},
  {0x023a,0x3a,"BLE_ERR_CTLR_BUSY","Controller Busy"},
  {0x023b,0x3b,"BLE_ERR_CONN_PARMS","Unacceptable Connection Parameters"},
  {0x023c,0x3c,"BLE_ERR_DIR_ADV_TMO","Directed Advertising Timeout"},
  {0x023d,0x3d,"BLE_ERR_CONN_TERM_MIC","Connection Terminated due to MIC Failure"},
  {0x023e,0x3e,"BLE_ERR_CONN_ESTABLISHMENT","Connection Failed to be Established"},
  {0x023f,0x3f,"BLE_ERR_MAC_CONN_FAIL","MAC Connection Failed"},
  {0x0240,0x40,"BLE_ERR_COARSE_CLK_ADJ","Coarse Clock Adjustment Rejected but Will Try to Adjust Using Clock Dragging."},
  {0x0300,0x00,"BLE_L2CAP_SIG_ERR_CMD_NOT_UNDERSTOOD","Invalid or unsupported incoming L2CAP sig command."},
  {0x0301,0x01,"BLE_L2CAP_SIG_ERR_MTU_EXCEEDED","Incoming packet too large."},
  {0x0302,0x02,"BLE_L2CAP_SIG_ERR_INVALID_CID","No channel with specified ID."},
  {0x0401,0x01,"BLE_SM_ERR_PASSKEY","The user input of passkey failed, for example, the user cancelled the operation."},
  {0x0402,0x02,"BLE_SM_ERR_OOB","The OOB data is not available."},
  {0x0403,0x03,"BLE_SM_ERR_AUTHREQ","The pairing procedure cannot be performed as authentication requirements cannot be met due to IO capabilities of one or both devices."},
  {0x0404,0x04,"BLE_SM_ERR_CONFIRM_MISMATCH","The confirm value does not match the calculated compare value."},
  {0x0405,0x05,"BLE_SM_ERR_PAIR_NOT_SUPP","Pairing is not supported by the device."},
  {0x0406,0x06,"BLE_SM_ERR_ENC_KEY_SZ","The resultant encryption key size is insufficient for the security requirements of this device."},
  {0x0407,0x07,"BLE_SM_ERR_CMD_NOT_SUPP","The SMP command received is not supported on this device."},
  {0x0408,0x08,"BLE_SM_ERR_UNSPECIFIED","Pairing failed due to an unspecified reason."},
  {0x0409,0x09,"BLE_SM_ERR_REPEATED","Pairing or authentication procedure is disallowed because too little time has elapsed since last pairing request or security request."},
  {0x040a,0x0a,"BLE_SM_ERR_INVAL","The Invalid Parameters error code indicates that the command length is invalid or that a parameter is outside of the specified range."},
  {0x040b,0x0b,"BLE_SM_ERR_DHKEY","Indicates to the remote device that the DHKey Check value received doesn’t match the one calculated by the local device."},
  {0x040c,0x0c,"BLE_SM_ERR_NUMCMP","Indicates that the confirm values in the numeric comparison protocol do not match."},
  {0x040d,0x0d,"BLE_SM_ERR_ALREADY","Indicates that the pairing over the LE transport failed due to a Pairing Request sent over the BR/EDR transport in process."},
  {0x040e,0x0e,"BLE_SM_ERR_CROSS_TRANS","Indicates that the BR/EDR Link Key generated on the BR/EDR transport cannot be used to derive and distribute keys for the LE transport."},
  {0x0501,0x01,"BLE_SM_ERR_PASSKEY","The user input of passkey failed, for example, the user cancelled the operation."},
  {0x0502,0x02,"BLE_SM_ERR_OOB","The OOB data is not available."},
  {0x0503,0x03,"BLE_SM_ERR_AUTHREQ","The pairing procedure cannot be performed as authentication requirements cannot be met due to IO capabilities of one or both devices."},
  {0x0504,0x04,"BLE_SM_ERR_CONFIRM_MISMATCH","The confirm value does not match the calculated compare value."},
  {0x0505,0x05,"BLE_SM_ERR_PAIR_NOT_SUPP","Pairing is not supported by the device."},
  {0x0506,0x06,"BLE_SM_ERR_ENC_KEY_SZ","The resultant encryption key size is insufficient for the security requirements of this device."},
  {0x0507,0x07,"BLE_SM_ERR_CMD_NOT_SUPP","The SMP command received is not supported on this device."},
  {0x0508,0x08,"BLE_SM_ERR_UNSPECIFIED","Pairing failed due to an unspecified reason."},
  {0x0509,0x09,"BLE_SM_ERR_REPEATED","Pairing or authentication procedure is disallowed because too little time has elapsed since last pairing request or security request."},
  {0x050a,0x0a,"BLE_SM_ERR_INVAL","The Invalid Parameters error code indicates that the command length is invalid or that a parameter is outside of the specified range."},
  {0x050b,0x0b,"BLE_SM_ERR_DHKEY","Indicates to the remote device that the DHKey Check value received doesn’t match the one calculated by the local device."},
  {0x050c,0x0c,"BLE_SM_ERR_NUMCMP","Indicates that the confirm values in the numeric comparison protocol do not match."},
  {0x050d,0x0d,"BLE_SM_ERR_ALREADY","Indicates that the pairing over the LE transport failed due to a Pairing Request sent over the BR/EDR transport in process."},
  {0x050e,0x0e,"BLE_SM_ERR_CROSS_TRANS","Indicates that the BR/EDR Link Key generated on the BR/EDR transport cannot be used to derive and distribute keys for the LE transport."}
};
constexpr size_t ERR_TABLE_SIZE = sizeof(errTable)/sizeof(errTable[0]);

uint16_t getErrIndex(uint16_t errCode) {
  for (int i = 0; i < ERR_TABLE_SIZE; ++i) {  // Clean loop bound
    if (errTable[i].NimBLE == errCode) {
      return i;
    }
  }
  return -1;
}
/*=================================================================================
  Print return codes for BLE 
  
  List is from here: https://mynewt.apache.org/latest/network/ble_hs/ble_hs_return_codes.html#return-code-reference
=================================================================================*/
void printNimBLEErrCode(int errCode) {
  uint16_t errIndex;
  Serial.printf("NimBLE Reason code: 0x%04x: ",errCode);
  errIndex = getErrIndex(errCode);
  if (errIndex >=0) {
    Serial.printf("%s: %s\n",errTable[errIndex].errName,errTable[errIndex].errDesc);
  } 
  else {
    Serial.printf("Unknown error code\n");
  }
}
