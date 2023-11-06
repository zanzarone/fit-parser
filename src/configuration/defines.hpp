#if !defined(DEFINES_H)
#define DEFINES_H 1
/*
    DEFINES
*/
// #define VERSION "1.0.0.20230222"
#define VERSION "1.0.1.20231025"
#define SYSTEM_TIME_OFFSET_SEC 631065600    // Needed for conversion from UNIX time to FIT time (is in fit_date_time ma é privata)
#define LEFT_RIGHT_BALANCE_100 100.0        // L/R Balance scale
/*
    ENUMS
*/
enum StatusCode {
    COULD_NOT_OPEN                  = 0x0001,
    NOT_FIT_FILE                    = 0x0002,
    CHECK_INTEGRITY_FAILS           = 0x0003,
    DECODE_EXCEPTION                = 0x0004,
    JSON_PARSE_EXCEPTION            = 0x0005,
    ENCODE_CLOSE_EXCEPTION          = 0x0006,
};
enum EncoderWarningCodes {
    JSON_UNKNOW_KEY                 = 0x0010,
    JSON_MESG_WITHOUT_LOCAL_NUM     = 0x0011,
    JSON_FIELD_WITHOUT_TYPE         = 0x0012,
    JSON_FIELD_WITHOUT_LOCAL_NUM    = 0x0013,
    JSON_FIELD_WITHOUT_COUNT        = 0x0014
};
#endif
